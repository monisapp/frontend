module Mutation = [%relay.mutation
  {|
mutation SignupMutation($input: RegisterInput!) {
  register(input: $input) {
    token
    user {
      name
    }
  }
}
|}
];

let execute = (~name, ~email, ~password, ~passwordConfirm) =>
  Mutation.commitMutation(
    ~environment=RelayEnv.environment,
    ~variables={
      input: {
        name,
        email,
        password,
        passwordConfirm,
      },
    },
    (),
  );
