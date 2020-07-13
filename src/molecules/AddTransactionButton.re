[@react.component]
let make = (~onClick=?) =>
  <>
    <button
      className="hidden sm:flex items-center px-4 py-1 rounded-full shadow-lg bg-blue-700 text-white"
      ?onClick>
      <PlusIcon
        className="-ml-2 mr-2 fill-current text-blue-700 bg-white rounded-full w-4 h-4"
      />
      <span> {j|Add Transaction|j}->React.string </span>
    </button>
    <button
      className="fixed sm:hidden bottom-0 right-0 mr-8 mb-8 rounded-full bg-blue-700 p-4"
      ?onClick>
      <PlusIcon className="fill-current text-white w-6 h-6" />
    </button>
  </>;
