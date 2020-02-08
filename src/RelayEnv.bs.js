'use strict';

var Fetch = require("bs-fetch/src/Fetch.js");
var Js_dict = require("bs-platform/lib/js/js_dict.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var ReasonRelay = require("reason-relay/src/ReasonRelay.bs.js");
var Caml_exceptions = require("bs-platform/lib/js/caml_exceptions.js");

var Graphql_error = Caml_exceptions.create("RelayEnv-ReasonReactExamples.Graphql_error");

function fetchQuery(operation, variables, _cacheConfig) {
  return fetch("http://localhost:4000/graphql", Fetch.RequestInit.make(/* Post */2, {
                      "content-type": "application/json",
                      accept: "application/json"
                    }, Caml_option.some(JSON.stringify(Js_dict.fromList(/* :: */[
                                  /* tuple */[
                                    "query",
                                    operation.text
                                  ],
                                  /* :: */[
                                    /* tuple */[
                                      "variables",
                                      variables
                                    ],
                                    /* [] */0
                                  ]
                                ]))), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* () */0)).then((function (resp) {
                if (resp.ok) {
                  return resp.json();
                } else {
                  return Promise.reject([
                              Graphql_error,
                              "Request failed: " + resp.statusText
                            ]);
                }
              }));
}

var network = ReasonRelay.Network.makePromiseBased(fetchQuery, undefined, /* () */0);

var environment = ReasonRelay.Environment.make(network, ReasonRelay.Store.make(ReasonRelay.RecordSource.make(undefined, /* () */0), undefined, /* () */0), undefined, /* () */0);

exports.Graphql_error = Graphql_error;
exports.fetchQuery = fetchQuery;
exports.network = network;
exports.environment = environment;
/* network Not a pure module */
