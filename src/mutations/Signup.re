module Mutation = [%relay.mutation
  {|
mutation SignupMutation($email: String!, $name: String!, $password: String!, $passwordConfirm: String!) {
  register(name: $name, email: $email, password: $password, passwordConfirm: $passwordConfirm) {
    token
    user {
      name
    }
  }
}
|}
];

let execute = (~name, ~email, ~password, ~passwordConfirm) => {
  Mutation.commitMutation(~environment=RelayEnv.environment, ~variables={name, email, password, passwordConfirm});
};
