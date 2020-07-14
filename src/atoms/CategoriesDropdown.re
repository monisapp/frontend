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

  let elements =
    switch(categoriesData.categories) {
      | Some(categories) => categories |> Array.map(
        (category : Query.Types.categories) =>
          category.name->String.capitalize_ascii
        )
      | None => [||]
    };

  Array.sort(String.compare, elements);

  <Dropdown elements=elements color="gray" />;
};
