[@react.component]
let make = (~type_, ~id, ~label, ~value, ~onChange, ~className=?, ~fullWidth=false, ~error="") => {
  let (focused, setFocused) = React.useState(() => false);
  <div ?className>
    <div className="group relative mt-6">
      <label
        className={
          "transform transition-all duration-200 absolute top-0 p-1 text-gray-700 pointer-events-none  "
          ++ (error != "" ? "text-red-700" : "")
          ++ " "
          ++ (focused || value != "" ? " -translate-x-1 -translate-y-5 text-blue-700 text-xs" : "")
        }
        htmlFor=id>
        label->React.string
      </label>
      <input
        className={
          "p-1 transition-colors duration-200 border-b-2 "
          ++ (error != "" ? "border-red-700" : "")
          ++ " "
          ++ (focused || value != "" ? "border-blue-700" : "")
          ++ " "
          ++ (fullWidth ? "w-full" : "")
        }
        type_
        id
        value
        onChange
        onFocus={_ => setFocused(_ => true)}
        onBlur={_ => setFocused(_ => false)}
      />
      <p className={"text-xs text-red-700 " ++ (focused || value != "" || error == "" ? "hidden" : "")}>
        error->React.string
      </p>
    </div>
  </div>;
};
