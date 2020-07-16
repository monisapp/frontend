type buttonType =
  | None
  | Plus
  | Minus;

[@react.component]
let make = (~onClick=?, ~children, ~color="blue", ~textColor="white", ~buttonType=None) => {
  let icon = iconClasses => switch(buttonType) {
    | Plus => <PlusIcon className=iconClasses />
    | Minus => <MinusIcon className=iconClasses />
    | None => React.null
  };
  <>
    <button
      className=("cursor-pointer hidden sm:flex items-center px-4 py-1 rounded-full shadow-lg bg-" ++ color ++ "-700 text-" ++ textColor)
      ?onClick>
      {
        icon("-ml-2 mr-2 fill-current text-" ++ color ++ "-700 bg-" ++ textColor ++ " rounded-full w-4 h-4")
      }
      <span> children </span>
    </button>
    <button
      className=("cursor-pointer fixed sm:hidden bottom-0 right-0 mr-8 mb-8 rounded-full bg-" ++ color ++ "-700 p-4")
      ?onClick>
      {
        icon("fill-current text-" ++ textColor ++ " w-6 h-6")
      }
    </button>
  </>;
}
