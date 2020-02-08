[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  switch (url.path) {
  | [] => <div> "Hello, world"->React.string </div>
  | _ => <div> "Hello, world"->React.string </div>
  };
};
