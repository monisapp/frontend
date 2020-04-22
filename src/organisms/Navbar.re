module Query = [%relay.query
  {|
  query NavbarQuery {
    user {
      ...UserDropdown_user
    }
  }
|}
];

[@react.component]
let make = () => {
  let homeData = Query.use(~variables=(), ());
  <div className="h-22">
    <div className="flex fixed top-0 bg-indigo-100 container p-8">
      <button className="flex">
        <DollarIcon className="fill-current text-green-600 w-6 h-6" />
        <span className="mx-1"> "Budget Name"->React.string </span>
        <ChevronIcon className="w-6 h-6" />
      </button>
      <UserDropdown
        user={homeData.user.getFragmentRefs()}
        className="ml-auto"
      />
    </div>
  </div>;
};
