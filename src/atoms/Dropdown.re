let empty=<li className="appearance-none p-1 text-gray-500">
  "Empty"->React.string
</li>;

[@react.component]
let make = (
  ~placeholder="Select one",
  ~render={e => e->React.string},
  ~elements=[||],
  ~emptyElement=empty,
  ~color : string ="indigo",
  ~border : bool = true
) => {
  let (isOpen, onOpen) = React.useState(() => false);
  let (selected, onSelected) = React.useState(() => -1);
  let toggle = _event => onOpen(current => !current);

  let handleClickOutside = _ => {
    onOpen(_ => false)
  }
  let dropdownRef = ClickOutside.useClickOutside(handleClickOutside);

  let borderClass = border ? "border shadow" : "";

  <div className="w-full" ref={ReactDOMRe.Ref.domRef(dropdownRef)}> // Container
    <div className=(borderClass ++ "border-" ++ color ++ "-400 hover:border-" ++ color ++ "-500 rounded leading-tight focus:outline-none focus:shadow-outline cursor-pointer p-2 w-full") onClick=toggle> // Header
      <div className="flex justify-between select-none">
        (selected == -1 ? placeholder : elements[selected])->React.string
        <ChevronIcon className=("w-5 text-" ++ color ++ "-500 transition-transform duration-200 transform" ++ (isOpen ? " rotate-180" : "")) />
      </div>
    </div> // Header
    { isOpen ?
      <div className="absolute z-40 bg-white inset-x-0"> // Choices
        <ul className=(borderClass ++ "appearance-none border-" ++ color ++ "-300 rounded")> // Choices
          <li className=("appearance-none p-1 text-gray-600 text-sm")>
            placeholder->React.string
          </li>
          <hr />
        {
          if (elements |> Array.length == 0) {
            emptyElement
          } else {
            Array.mapi(
              (i, element) =>
              <li
                onClick={
                  _e => {
                    onSelected(_ => i);
                    onOpen(_ => false);
                  }
                }
                className=("appearance-none p-1 bg-white hover:bg-" ++ color ++ "-200 cursor-pointer")>
                element->render
              </li>
            , elements)
            |> React.array
          }
        }
        </ul>
      </div>
    : React.null}
  </div> // Container
};
