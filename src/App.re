[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  switch (Dom.Storage.getItem("monis-app-token", Dom.Storage.localStorage)) {
  | None => <Login />
  | _ =>
    switch (url.path) {
    | ["signup"] => <Signup />
    | ["login"] => <Login />
    | _ =>
      <ReactExperimental.Suspense
        fallback={
          <div className="bg-indigo-100 h-screen w-screen flex">
            <span className="m-auto"> "Loading..."->React.string </span>
          </div>
        }>
        <Home />
      </ReactExperimental.Suspense>
    }
  };
};
