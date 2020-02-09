[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  switch (Dom.Storage.getItem("monis-app-token", Dom.Storage.localStorage)) {
  | None => <Login />
  | _ =>
    switch (url.path) {
    | ["signup"] => <Signup />
    | ["login"] => <Login />
    | _ => <div> "Hello, world"->React.string </div>
    }
  };
};
