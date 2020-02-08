'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonRelay = require("reason-relay/src/ReasonRelay.bs.js");
var ReactExperimental = require("reason-relay/src/ReactExperimental.bs.js");
var App$ReasonReactExamples = require("./App.bs.js");
var RelayEnv$ReasonReactExamples = require("./RelayEnv.bs.js");

ReactExperimental.renderConcurrentRootAtElementWithId(React.createElement(ReasonRelay.Context.Provider.make, Curry._4(ReasonRelay.Context.Provider.makeProps, RelayEnv$ReasonReactExamples.environment, React.createElement(App$ReasonReactExamples.make, { }), undefined, /* () */0)), "app");

/*  Not a pure module */
