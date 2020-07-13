/*
module Fragment = [%relay.fragment
  {|
  fragment CategoriesDropdown_category on RootQueryType {
    categories {
      name,
      icon,
      cat_type: type
    }
  }
|}
];
*/

module Query = [%relay.query {|
  query CategoriesDropdownQuery($categoryType: String!) {
    categories(type: $categoryType) {
      name,
      icon,
      cat_type: type,
    }
  }
|}];

[@react.component]
let make = (~categoryType) => {
  let categoriesData = Query.use(~variables={
    categoryType: categoryType
  }, ());

  <select
    className="form-select block w-full sm:text-sm sm:leading-5"
    defaultValue="default">
    <option disabled=true value="default" className="text-gray-500">
      "Choose a category"->React.string
    </option>
    {
      switch(categoriesData.categories) {
        | Some(categories) => Array.map(
          (categories: Query.Types.categories) =>
          <option key={categories.name}> categories.name->String.capitalize_ascii->React.string </option>,
          categories,
        )->React.array
        | None => React.null
      }
    }
  </select>;
};
