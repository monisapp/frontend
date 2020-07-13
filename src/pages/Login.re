type state = {
          </div>
  email: string,
  password: string,
  error: string,
};

type action =
  | ChangeError(string)
  | ChangeEmail(string)
  | ChangePassword(string);

let reducer = (state, action) =>
  switch (action) {
  | ChangeEmail(email) => {...state, email}
  | ChangePassword(password) => {...state, password}
  | ChangeError(error) => {...state, error}
  };

[@react.component]
let make = () => {
  let ({email, password, error}, dispatch) =
    React.useReducer(reducer, {email: "", password: "", error: ""});
  <div className="bg-indigo-100 min-h-screen flex">
    <form className="m-auto shadow bg-white p-16">
      <h1 className="text-center text-xl px-12 font-semibold mb-4">
        {j|Faça login na sua conta|j}->React.string
      </h1>
      {
        error != "" ?
          <p
            className="bg-red-100 border border-red-700 text-red-700 py-2 px-4 rounded">
            error->React.string
          </p> :
          React.null
      }
      <Input
        fullWidth=true
        id="email"
        label={j|Endereço de e-mail|j}
        type_="email"
        className="mt-8"
        value=email
        onChange={
          e => {
            let value = ReactEvent.Form.currentTarget(e)##value;
            dispatch(ChangeEmail(value));
          }
        }
      />
      <Input
        fullWidth=true
        id="password"
        label={j|Sua senha|j}
        type_="password"
        value=password
        onChange={
          e => {
            let value = ReactEvent.Form.currentTarget(e)##value;
            dispatch(ChangePassword(value));
          }
        }
      />
      <button
        className="rounded w-full bg-blue-700 uppercase font-medium text-white py-3 mt-10"
        type_="submit"
        onClick={
          e => {
            ReactEvent.Mouse.preventDefault(e);
            LoginMutation.execute(~email, ~password)
            |> Js.Promise.then_(v => {
                 let resp: LoginMutation.Mutation.Operation.response =
                   Obj.magic(v);
                 switch (resp.login) {
                 | Some({token}) =>
                   Dom.Storage.(
                     setItem("monis-app-token", token, localStorage)
                   );
                   ReasonReactRouter.push("/");
                 | None => ()
                 };
                 Js.Promise.resolve();
               })
            |> Js.Promise.catch(err =>
                 (
                   switch (Utils.convertError(err)) {
                   | Some([|err|]) => dispatch(ChangeError(err.message))
                   | _ => Js.log("Error not known")
                   }
                 )
                 |> Js.Promise.resolve
               )
            |> ignore;
          }
        }>
        "ENTRAR"->React.string
      </button>
      <span
        className="sm:text-sm text-sm cursor-pointer"
        onClick={
          _ => {
            ReasonReactRouter.push("/signup")
          }
        }
      > "Need an account?"->React.string </span>
    </form>
  </div>;
};
