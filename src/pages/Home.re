[@react.component]
let make = () => {
  <div className="bg-indigo-100 min-h-screen">
    <div className="container">
      <Navbar />
      <div>
        <SideMenu />
        <div className="fixed" style={ReactDOMRe.Style.make(~paddingLeft="22rem", ~height="calc(100vh - 88px)", ())} />
      </div>
    </div>
  </div>;
};
