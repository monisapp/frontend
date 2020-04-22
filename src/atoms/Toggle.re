[@react.component]
let make = (~id, ~className="", ~checked, ~onChange) =>
  <label
    htmlFor=id className={"flex items-center cursor-pointer " ++ className}>
    <div className="relative">
      <input type_="checkbox" id checked onChange className="hidden" />
      <div
        className="toggle__line w-14 h-8 sm:w-10 sm:h-6 rounded shadow-inner"
      />
      <div
        className="toggle__dot transform transition-transform ease-in duration-200 absolute w-6 h-6 sm:w-4 sm:h-4 bg-white rounded shadow inset-y-0 left-0 m-1 flex">
        {
          checked ?
            <PlusIcon className="w-full h-full" /> :
            <MinusIcon className="w-full h-full" />
        }
      </div>
    </div>
  </label>;
