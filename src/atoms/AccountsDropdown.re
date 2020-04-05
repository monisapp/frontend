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

  <select className="form-select block w-full sm:text-sm sm:leading-5" defaultValue="default">
    <option disabled=true value="default" className="text-gray-500">
      "Choose an account"->React.string
    </option>
    {Array.map(
       (account: Fragment.Types.accounts) =>
         <option key={account.id}> {account.name}->React.string </option>,
       accountsData.accounts,
     )
     ->React.array}
  </select>;
};
