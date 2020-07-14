module Fragment = [%relay.fragment
  {|
  fragment AccountsDropdown_accounts on RootQueryType {
    accounts {
      id
      name
    }
  }
|}
];

[@react.component]
let make = (~accounts as accountsRef) => {
  let accountsData = Fragment.use(accountsRef);
  let elements=accountsData.accounts;

  <Dropdown elements={ elements |> Array.map( (element : Fragment.Operation.Types.accounts) => element.name ) } color="gray" />;
};
