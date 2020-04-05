[@react.component]
let make = (~accounts) => {
  Js.log(accounts);
  <select className="form-select block w-full sm:text-sm sm:leading-5">
    <option disabled=true selected=true className="text-gray-500">
      "Choose an account"->React.string
    </option>
    {Array.map(
       account =>
         <option key=[%bs.raw {|account.id|}]>
           [%bs.raw {|account.name|}]->React.string
         </option>,
       accounts,
     )
     ->React.array}
  </select>;
};
