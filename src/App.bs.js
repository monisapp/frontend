'use strict';

var React = require("react");
var ReasonReactRouter = require("reason-react/src/ReasonReactRouter.js");

function App(Props) {
  var url = ReasonReactRouter.useUrl(undefined, /* () */0);
  url.path;
  return React.createElement("div", undefined, "Hello, world");
}

var make = App;

exports.make = make;
/* react Not a pure module */
