[@react.component]
let make = () => {
  <div
    className="fixed bottom-0 inset-x-0 px-4 pb-4 sm:inset-0 sm:flex sm:items-center sm:justify-center">
    <div className="fixed inset-0">
      <div className="absolute inset-0 bg-gray-500 opacity-75" />
    </div>
    <div
      className="bg-white rounded-lg overflow-hidden shadow-xl transform transition-all sm:max-w-lg sm:w-full">
      <div className="bg-white px-4 pt-5 pb-4 sm:p-6 sm:pb-4">
        <div className="sm:flex sm:items-start">
          <div className="mt-3 text-center sm:mt-0 sm:ml-4 sm:text-left">
            <h3 className="text-lg leading-6 font-medium text-gray-900">
              "Add transaction"->React.string
            </h3>
            <div className="mt-2 flex flex-col">
              <div className="flex flex-col sm:flex-row -mx-2">
                <div className="flex flex-col px-2">
                  <div>
                    <label
                      htmlFor="account"
                      className="block text-sm leading-5 font-medium text-left text-gray-700">
                      "Account"->React.string
                    </label>
                    <div className="mt-1 relative rounded-md shadow-sm">
                      <input
                        id="account"
                        className="form-input block w-full sm:text-sm sm:leading-5"
                        placeholder="Nubank Credit Card"
                      />
                    </div>
                  </div>
                  <div>
                    <label
                      htmlFor="payee"
                      className="block text-sm leading-5 font-medium text-left text-gray-700">
                      "Payee"->React.string
                    </label>
                    <div className="mt-1 relative rounded-md shadow-sm">
                      <input
                        id="payee"
                        className="form-input block w-full sm:text-sm sm:leading-5"
                        placeholder="7Eleven"
                      />
                    </div>
                  </div>
                </div>
                <div className="flex flex-col px-2">
                  <div>
                    <label
                      htmlFor="value"
                      className="block text-sm leading-5 font-medium text-left text-gray-700">
                      "Value"->React.string
                    </label>
                    <div className="mt-1 relative rounded-md shadow-sm">
                      <div
                        className="absolute inset-y-0 left-0 pl-3 flex items-center pointer-events-none">
                        <span
                          className="text-gray-500 sm:text-sm sm:leading-5">
                          "$"->React.string
                        </span>
                      </div>
                      <input
                        id="value"
                        className="form-input block w-full pl-7 sm:text-sm sm:leading-5"
                        placeholder="1.99"
                      />
                    </div>
                  </div>
                  <div>
                    <label
                      htmlFor="category"
                      className="block text-sm leading-5 font-medium text-left text-gray-700">
                      "Category"->React.string
                    </label>
                    <div className="mt-1 relative rounded-md shadow-sm">
                      <input
                        id="category"
                        className="form-input block w-full sm:text-sm sm:leading-5"
                        placeholder="Groceries"
                      />
                    </div>
                  </div>
                </div>
              </div>
              <div>
                <label
                  htmlFor="comment"
                  className="block text-sm leading-5 font-medium text-left text-gray-700">
                  "Note"->React.string
                </label>
                <div className="mt-1 relative rounded-md shadow-sm">
                  <input
                    id="comment"
                    className="form-input block w-full sm:text-sm sm:leading-5"
                    placeholder="Dinner ingredients"
                  />
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
            className="inline-flex justify-center w-full rounded-md border border-transparent px-4 py-2 bg-green-600 text-base leading-6 font-medium text-white shadow-sm hover:bg-green-500 focus:outline-none focus:border-green-700 focus:shadow-outline-green transition ease-in-out duration-150 sm:text-sm sm:leading-5">
            "Confirm"->React.string
          </button>
        </span>
        <span
          className="mt-3 flex w-full rounded-md shadow-sm sm:mt-0 sm:w-auto">
          <button
            type_="button"
            className="inline-flex justify-center w-full rounded-md border border-gray-300 px-4 py-2 bg-white text-base leading-6 font-medium text-gray-700 shadow-sm hover:text-gray-500 focus:outline-none focus:border-blue-300 focus:shadow-outline transition ease-in-out duration-150 sm:text-sm sm:leading-5">
            "Cancel"->React.string
          </button>
        </span>
      </div>
    </div>
  </div>;
};
