[@react.component]
let make = () => {
  let (isAddingTransaction, showAddTransaction) = React.useState(() => false);
  <div className="bg-indigo-100 min-h-screen">
    <div className="container">
      <Navbar />
      <SideMenu onClick={ _ => showAddTransaction(_ => true) } />
      {
        switch (isAddingTransaction) {
        | true =>
            <AddTransactionModal
              cancelAction={
                _ => showAddTransaction(_ => false)
              }
              confirmAction={
                _ => showAddTransaction(_ => false)
              }
            />
        | false => React.null
        }
      }
    </div>
  </div>
}
