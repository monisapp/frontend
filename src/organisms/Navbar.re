module Query = [%relay.query {|
  query NavbarQuery {
    user {
      ...UserDropdown_user
    }
  }
|}];

[@react.component]
let make = () => {
  let homeData = Query.use(~variables=(), ());
  <div className="flex p-8">
    <button className="flex">
      <DollarIcon className="fill-current text-green-600 w-6 h-6" />
      <span className="mx-1"> "Budget Name"->React.string </span>
      <ChevronIcon className="w-6 h-6" />
    </button>
    <UserDropdown user={homeData.user.getFragmentRefs()} className="ml-auto" />
  </div>;
};
