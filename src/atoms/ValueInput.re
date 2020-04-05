[@react.component]
let make = () => {
  let (toggled, setToggled) = React.useState(() => false);
  <div>
    <label
      htmlFor="value"
      className="block text-sm leading-5 font-medium text-left text-gray-700">
      "Value"->React.string
    </label>
    <div className="mt-1 relative rounded-md shadow-sm flex">
      <div
        className="absolute inset-y-0 left-0 pl-3 flex items-center pointer-events-none">
        <span className="text-gray-500 sm:text-sm sm:leading-5">
          "$"->React.string
        </span>
      </div>
      <input
        id="value"
        className="form-input block w-full pl-7 sm:text-sm sm:leading-5"
        placeholder="1.99"
      />
      <Toggle
        id="value_toggle"
        className="absolute right-0 inset-y-0 justify-center mr-2 sm:text-sm"
        checked=toggled
        onChange={_ => setToggled(toggle => !toggle)}
      />
    </div>
  </div>;
};
