[@react.component]
let make = () => {
  <div className="relative">
    <div className="pt-4 z-50 relative">
      <div className="absolute inset-0 mt-32">
        <div className="container mt-4">
          <form
            className="ml-8 p-8 relative bg-white rounded"
            style={ReactDOMRe.Style.make(~maxWidth="max-content", ())}
            onSubmit={e => ReactEvent.Form.preventDefault(e)}>
            <button
              type_="button"
              className="absolute top-0 right-0 p-1 rounded-full bg-gray-700 hover:bg-gray-800 transform translate-x-1/2 -translate-y-1/2">
              <CrossIcon className="w-4 h-4 fill-current text-white" />
            </button>
            <div className="flex flex-col -mx-6">
              <div className="flex flex-wrap">
                <label htmlFor="account" className="flex flex-col px-3">
                  <span className="text-xs font-light text-gray-600 uppercase"> "Conta"->React.string </span>
                  <input
                    type_="text"
                    name="account"
                    id="account"
                    className="py-2 pl-8 pr-4 w-48 h-10 rounded border"
                  />
                </label>
                <label htmlFor="account" className="flex flex-col px-3">
                  <span className="text-xs font-light text-gray-600 uppercase"> "Emitente"->React.string </span>
                  <input type_="text" name="account" id="account" className="py-2 px-3 w-48 h-10 rounded border" />
                </label>
                <label htmlFor="category" className="flex flex-col px-3">
                  <span className="text-xs font-light text-gray-600 uppercase"> "Categoria"->React.string </span>
                  <input type_="text" name="category" id="category" className="py-2 px-3 w-48 h-10 rounded border" />
                </label>
                <label htmlFor="value" className="flex flex-col px-3">
                  <span className="text-xs font-light text-gray-600 uppercase"> "Valor"->React.string </span>
                  <input type_="number" name="value" id="value" className="py-2 px-3 w-48 h-10 rounded border" />
                </label>
              </div>
              <div className="flex flex-wrap">
                <label htmlFor="date" className="flex flex-col px-3">
                  <span className="text-xs font-light text-gray-600 uppercase"> "Data"->React.string </span>
                  <input type_="text" name="date" id="date" className="py-2 px-3 w-48 h-10 h-10 rounded border" />
                </label>
                <label htmlFor="comment" className="flex flex-col px-3">
                  <span className="text-xs font-light text-gray-600 uppercase"> {j|Comentário|j}->React.string </span>
                  <input type_="text" name="comment" id="comment" className="py-2 px-3 w-64 h-10 rounded border" />
                </label>
                <button className="rounded w-48 h-10 ml-auto mr-3 self-end font-medium bg-green-600 shadow-lg text-white">
                  {j|Salvar Transação|j}->React.string
                </button>
              </div>
            </div>
          </form>
        </div>
      </div>
    </div>
    <div className="fixed opacity-25 transition-opacity duration-300 inset-0 bg-black z-40 w-screen" />
  </div>;
};
