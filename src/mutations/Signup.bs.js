'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var ReasonRelay = require("reason-relay/src/ReasonRelay.bs.js");
var RelayEnv$ReasonReactExamples = require("../RelayEnv.bs.js");
var SignupMutation_graphql$ReasonReactExamples = require("../__generated__/SignupMutation_graphql.bs.js");

var convertResponse = SignupMutation_graphql$ReasonReactExamples.Internal.convertResponse;

var wrapResponse = SignupMutation_graphql$ReasonReactExamples.Internal.convertWrapResponse;

var convertVariables = SignupMutation_graphql$ReasonReactExamples.Internal.convertVariables;

var Mutation = ReasonRelay.MakeCommitMutation({
      node: SignupMutation_graphql$ReasonReactExamples.node,
      convertResponse: convertResponse,
      wrapResponse: wrapResponse,
      convertVariables: convertVariables
    });

var convertResponse$1 = SignupMutation_graphql$ReasonReactExamples.Internal.convertResponse;

var wrapResponse$1 = SignupMutation_graphql$ReasonReactExamples.Internal.convertWrapResponse;

var convertVariables$1 = SignupMutation_graphql$ReasonReactExamples.Internal.convertVariables;

var UseMutation = ReasonRelay.MakeUseMutation({
      node: SignupMutation_graphql$ReasonReactExamples.node,
      convertResponse: convertResponse$1,
      wrapResponse: wrapResponse$1,
      convertVariables: convertVariables$1
    });

var commitMutation = Mutation.commitMutation;

var Mutation$1 = {
  Operation: /* alias */0,
  Types: /* alias */0,
  Mutation: Mutation,
  UseMutation: UseMutation,
  commitMutation: commitMutation
};

function execute(name, email, password, passwordConfirm) {
  return Curry._2(commitMutation, RelayEnv$ReasonReactExamples.environment, {
              email: email,
              name: name,
              password: password,
              passwordConfirm: passwordConfirm
            });
}

exports.Mutation = Mutation$1;
exports.execute = execute;
/* Mutation Not a pure module */
