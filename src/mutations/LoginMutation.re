module Mutation = [%relay.mutation
  {|
mutation LoginMutation($email: String!, $password: String!) {
  login(email: $email, password: $password) {
    token
  }
}
|}
];

let execute = (~email, ~password) =>
  Mutation.commitMutation(
    ~environment=RelayEnv.environment,
    ~variables={email, password},
    (),
  );
