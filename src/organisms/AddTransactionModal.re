[@react.component]
let make = () => {
  <div className="relative">
    <div className="pt-4 z-50 relative">
      <div className="absolute inset-x-0 container">
        <form
          className="flex flex-wrap w-full p-4 relative bg-white rounded"
          onSubmit={e => ReactEvent.Form.preventDefault(e)}>
          <button
            type_="button"
            className="absolute top-0 right-0 p-1 rounded-full bg-gray-700 hover:bg-gray-800 transform translate-x-1/2 -translate-y-1/2">
            <CrossIcon className="w-4 h-4 fill-current text-white" />
          </button>
          <label htmlFor="account" className="flex flex-col">
            <span className="text-xs font-light text-gray-600 uppercase"> "Conta"->React.string </span>
            <input type_="text" name="account" id="account" className="py-2 pl-8 pr-4 w-48 rounded border" />
          </label>
          <label htmlFor="account" className="flex flex-col">
            <span className="text-xs font-light text-gray-600 uppercase"> "Emitente"->React.string </span>
            <input type_="text" name="account" id="account" className="p-2 w-48 rounded border" />
          </label>
        </form>
      </div>
    </div>
    <div className="fixed opacity-25 transition-opacity duration-300 inset-0 bg-black z-40 w-screen" />
  </div>;
};
