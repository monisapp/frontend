[@react.component]
let make = () => {
  let (modalState, setModal) = React.useState(() => Modals.None);

  let performAction: Actions.performAction = action => switch(action) {
    | Actions.SetTransactionModal(true) => setModal(_ => Modals.AddTransaction)
    | Actions.SetTransactionModal(false) => setModal(_ => Modals.None)
    | Actions.SetAccountModal(true) => setModal(_ => Modals.AddAccount)
    | Actions.SetAccountModal(false) => setModal(_ => Modals.None)
  };

  <div className="bg-indigo-100 min-h-screen">
    <div className="container">
      <Navbar />
      <main className="flex flex-row">
        <SideMenu performAction=performAction />
        <FirstAccount/>
      </main>
      {
        switch (modalState) {
        | Modals.AddTransaction =>
          <AddTransactionModal
            performAction=performAction
          />
        | Modals.AddAccount =>
          <AddAccountModal
            performAction=performAction
          />
        | Modals.None => React.null
        }
      }
    </div>
  </div>
}
