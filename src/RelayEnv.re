/* RelayEnv.re */
/* This is just a custom exception to indicate that something went wrong. */
exception Graphql_error(string);
/**
 * A standard fetch that sends our operation and variables to the
 * GraphQL server, and then decodes and returns the response.
 */
let fetchQuery: ReasonRelay.Network.fetchFunctionPromise =
  (operation, variables, _cacheConfig) => {
    let token = Dom.Storage.getItem("monis-app-token", Dom.Storage.localStorage);
    Fetch.(
      fetchWithInit(
        "http://localhost:4000/graphql",
        RequestInit.make(
          ~method_=Post,
          ~body=
            Js.Dict.fromList([("query", Js.Json.string(operation.text)), ("variables", variables)])
            |> Js.Json.object_
            |> Js.Json.stringify
            |> BodyInit.make,
          ~headers=HeadersInit.make({"content-type": "application/json", "accept": "application/json", "authorization": {j|Bearer $token|j}}),
          (),
        ),
      )
      |> Js.Promise.then_(resp =>
           if (Response.ok(resp)) {
             Response.json(resp);
           } else {
             Js.log(("error", resp))
             Js.Promise.reject(Graphql_error("Request failed: " ++ Response.statusText(resp)));
           }
         )
    );
  }
let network = ReasonRelay.Network.makePromiseBased(~fetchFunction=fetchQuery, ());
let environment =
  ReasonRelay.Environment.make(
    ~network,
    ~store=ReasonRelay.Store.make(~source=ReasonRelay.RecordSource.make(), ()),
    (),
  );
