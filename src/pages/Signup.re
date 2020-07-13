type state = {
  email: string,
  name: string,
  password: string,
  passwordConfirm: string,
  error: string,
};

type action =
  | ChangeError(string)
  | ChangeEmail(string)
  | ChangeName(string)
  | ChangePassword(string)
  | ChangePasswordConfirm(string);

let reducer = (state, action) =>
  switch (action) {
  | ChangeName(name) => {...state, name}
  | ChangeEmail(email) => {...state, email}
  | ChangePassword(password) => {...state, password}
  | ChangePasswordConfirm(passwordConfirm) => {...state, passwordConfirm}
  | ChangeError(error) => {...state, error}
  };

[@react.component]
let make = () => {
  let ({name, email, password, passwordConfirm, error}, dispatch) =
    React.useReducer(
      reducer,
      {email: "", name: "", password: "", passwordConfirm: "", error: ""},
    );
  <div className="bg-indigo-100 min-h-screen flex">
    <form
      className="m-auto shadow bg-white p-16"
      onSubmit={
        e => {
          ReactEvent.Form.preventDefault(e);
          Js.log("onSubmit Ok!");
        }
      }>
      <h1 className="text-center text-xl px-24 font-semibold uppercase mb-4">
        "CADASTRO"->React.string
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
        id="name"
        label="Nome"
        type_="text"
        className="mt-8"
        value=name
        onChange={
          e => {
            let value = ReactEvent.Form.currentTarget(e)##value;
            dispatch(ChangeName(value));
          }
        }
      />
      <Input
        fullWidth=true
        id="email"
        label={j|Endereço de e-mail|j}
        type_="email"
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
        label="Sua senha"
        type_="password"
        value=password
        onChange={
          e => {
            let value = ReactEvent.Form.currentTarget(e)##value;
            dispatch(ChangePassword(value));
          }
        }
      />
      <Input
        fullWidth=true
        id="password_confirm"
        label="Confirme sua senha"
        type_="password"
        value=passwordConfirm
        onChange={
          e => {
            let value = ReactEvent.Form.currentTarget(e)##value;
            dispatch(ChangePasswordConfirm(value));
          }
        }
      />
      <button
        className="rounded w-full bg-blue-700 uppercase font-medium text-white py-3 mt-10"
        type_="submit"
        onClick={
          e => {
            ReactEvent.Mouse.preventDefault(e);
            SignupMutation.execute(~name, ~email, ~password, ~passwordConfirm)
            |> Js.Promise.then_(v => {
                 let resp: SignupMutation.Mutation.Operation.response =
                   Obj.magic(v);
                 switch (resp.register) {
                 | Some(register) =>
                   Dom.Storage.setItem(
                     "monis-app-token",
                     register.token,
                     Dom.Storage.localStorage,
                   );
                   ReasonReactRouter.push("/");
                 | None => ()
                 };
                 Js.log((v, resp));
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
        "CADASTRE-SE"->React.string
      </button>
      <span
        className="sm:text-sm text-sm cursor-pointer"
        onClick={
          _ => {
            ReasonReactRouter.push("/login")
          }
        }
      > "Already have an account?"->React.string </span>
    </form>
  </div>;
};
