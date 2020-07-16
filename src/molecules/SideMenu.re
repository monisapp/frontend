module Query = [%relay.query
  {|
  query SideMenuQuery {
    accounts {
      id
      name
    }
  }
|}
];

[@react.component]
let make = (~performAction: Actions.performAction) => {
  let accounts = Query.use(~variables=(), ());

  <aside className="pl-8 w-64 bg-indigo-100">
    {
      if (accounts.accounts->Array.length > 0) {
        <Button
          onClick={_ => performAction(Actions.SetTransactionModal(true))}
          buttonType=Button.Plus>
            "Add Transaction"->React.string
        </Button>
      } else {
        <Button
          onClick={_ => performAction(Actions.SetAccountModal(true))}
          color="green"
          buttonType=Button.Plus>
            "Add Account"->React.string
        </Button>;
      }
    }
    <button className="flex items-center mt-8 ml-2 text-blue-700">
      <HomeIcon className="w-4 h-4 mr-2 fill-current" />
      <span className="font-medium"> "Home"->React.string </span>
    </button>
  </aside>;
}
