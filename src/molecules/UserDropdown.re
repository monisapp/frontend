module UserFragment = [%relay.fragment
  {|
  fragment UserDropdown_user on User {
    name
  }
|}
];

module Pure = {
  [@react.component]
  let make = (~name, ~className="") =>
    <button className={"flex " ++ className}>
      <UserIcon className="w-6 h-6" />
      <span className="mx-1"> name->React.string </span>
      <ChevronIcon className="w-6 h-6" />
    </button>;
};

[@react.component]
let make = (~user as userRef, ~className=?) => {
  let user = UserFragment.use(userRef);
  <Pure name={user.name} ?className />;
};
