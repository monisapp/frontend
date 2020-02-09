[@react.component]
let make = () => {
  <aside className="fixed pl-8" style={ReactDOMRe.Style.make(~width="20rem", ())}>
    <button className="flex items-center px-4 py-1 rounded-full shadow-lg bg-blue-700 text-white">
      <PlusIcon className="-ml-2 mr-2 fill-current text-blue-700 bg-white rounded-full w-4 h-4" />
      <span> {j|Adicionar Trasação|j}->React.string </span>
    </button>
    <button className="flex items-center mt-8 ml-2 text-blue-700">
      <HomeIcon className="w-4 h-4 mr-2 fill-current" />
      <span className="font-medium"> "Home"->React.string </span>
    </button>
  </aside>;
};
