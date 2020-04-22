[@react.component]
let make = () =>
  <aside className="pl-8 fixed w-64 bg-indigo-100">
    <AddTransactionButton />
    <button className="flex items-center mt-8 ml-2 text-blue-700">
      <HomeIcon className="w-4 h-4 mr-2 fill-current" />
      <span className="font-medium"> "Home"->React.string </span>
    </button>
  </aside>;
