[@react.component]
let make = (~performAction: Actions.performAction) => {
  let modalRef = ClickOutside.useClickOutside(_ => performAction(Actions.SetTransactionModal(false)));
  let currencies = [|"BRL", "USD", "CAD"|];
  let accountTypes = [|"debit", "credit"|];

  <div
    className="fixed bottom-0 inset-x-0 px-4 pb-4 sm:inset-0 sm:flex sm:items-center sm:justify-center">
    <div className="fixed inset-0">
      <div className="absolute inset-0 bg-gray-500 opacity-75" />
    </div>
    <div
      ref={ReactDOMRe.Ref.domRef(modalRef)}
      className="bg-white rounded-lg overflow-y-visible shadow-xl transform transition-all">
      <div className="bg-white px-4 pt-5 pb-4 sm:p-6 sm:pb-4">
        <div className="sm:flex sm:items-start">
          <div className="mt-3 text-center sm:mt-0 sm:ml-4 sm:text-left">
            <h3 className="text-lg leading-6 font-medium text-gray-900">
              "Add Account"->React.string
            </h3>
            <div className="mt-2 flex flex-col">
              <div className="flex flex-col sm:flex-row -mx-2">
                <div className="flex flex-col px-2">
                  <div>
                    <label
                      htmlFor="account"
                      className="block text-sm leading-5 font-medium text-left text-gray-700">
                      "Account Name"->React.string
                    </label>
                    <div className="mt-1 relative rounded-md shadow-sm">
                      <input
                        id="account"
                        className="form-input block w-full sm:text-sm sm:leading-5"
                        placeholder="Bank Account"
                      />
                    </div>
                  </div>
                  <div>
                    <label
                      htmlFor="initial-balance"
                      className="block text-sm leading-5 font-medium text-left text-gray-700">
                      "Initial Balance"->React.string
                    </label>
                    <div className="mt-1 flex flex-row relative rounded-md shadow-sm">
                      <Dropdown
                        placeholder="Select currency"
                        defaultSelection=0
                        elements=currencies
                      />
                      <input
                        id="initial-balance"
                        className="form-input block w-full sm:text-sm sm:leading-5"
                        type_="number"
                        defaultValue="0.00"
                      />
                    </div>
                  </div>
                  <div>
                    <label
                      htmlFor="type"
                      className="block text-sm leading-5 font-medium text-left text-gray-700">
                      "Account type"->React.string
                    </label>
                    <div className="mt-1 flex flex-row relative rounded-md shadow-sm">
                      <Dropdown
                        placeholder="Select one"
                        defaultSelection=0
                        elements=(accountTypes|>Array.map(String.capitalize_ascii))
                      />
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
      <div
        className="bg-gray-50 px-4 py-3 sm:px-6 sm:flex sm:flex-row-reverse">
        <span className="flex w-full rounded-md shadow-sm sm:ml-3 sm:w-auto">
          <button
            type_="button"
            onClick={ _ => performAction(Actions.SetTransactionModal(false))}
            className="inline-flex justify-center w-full rounded-md border border-transparent px-4 py-2 bg-green-600 text-base leading-6 font-medium text-white shadow-sm hover:bg-green-500 focus:outline-none focus:border-green-700 focus:shadow-outline-green transition ease-in-out duration-150 sm:text-sm sm:leading-5">
            "Confirm"->React.string
          </button>
        </span>
        <span
          className="mt-3 flex w-full rounded-md shadow-sm sm:mt-0 sm:w-auto">
          <button
            type_="button"
            onClick={ _ => performAction(Actions.SetTransactionModal(false))}
            className="inline-flex justify-center w-full rounded-md border border-gray-300 px-4 py-2 bg-white text-base leading-6 font-medium text-gray-700 shadow-sm hover:text-gray-500 focus:outline-none focus:border-blue-300 focus:shadow-outline transition ease-in-out duration-150 sm:text-sm sm:leading-5">
            "Cancel"->React.string
          </button>
        </span>
      </div>
    </div>
  </div>;
};
