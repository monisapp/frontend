'use strict';

var ReasonRelay = require("reason-relay/src/ReasonRelay.bs.js");

var Unions = { };

var Types = { };

var wrapResponseConverter = ({"__root":{"register":{"n":""},"register_user_name":{"n":""}}});

function convertWrapResponse(v) {
  return ReasonRelay._convertObj(v, wrapResponseConverter, /* () */0, null);
}

var responseConverter = ({"__root":{"register":{"n":""},"register_user_name":{"n":""}}});

function convertResponse(v) {
  return ReasonRelay._convertObj(v, responseConverter, /* () */0, undefined);
}

var variablesConverter = ({});

function convertVariables(v) {
  return ReasonRelay._convertObj(v, variablesConverter, /* () */0, undefined);
}

var Internal = {
  wrapResponseConverter: wrapResponseConverter,
  wrapResponseConverterMap: /* () */0,
  convertWrapResponse: convertWrapResponse,
  responseConverter: responseConverter,
  responseConverterMap: /* () */0,
  convertResponse: convertResponse,
  variablesConverter: variablesConverter,
  variablesConverterMap: /* () */0,
  convertVariables: convertVariables
};

var Utils = { };

var node = ((function(){
var v0 = [
  {
    "kind": "LocalArgument",
    "name": "email",
    "type": "String!",
    "defaultValue": null
  },
  {
    "kind": "LocalArgument",
    "name": "name",
    "type": "String!",
    "defaultValue": null
  },
  {
    "kind": "LocalArgument",
    "name": "password",
    "type": "String!",
    "defaultValue": null
  },
  {
    "kind": "LocalArgument",
    "name": "passwordConfirm",
    "type": "String!",
    "defaultValue": null
  }
],
v1 = [
  {
    "kind": "LinkedField",
    "alias": null,
    "name": "register",
    "storageKey": null,
    "args": [
      {
        "kind": "Variable",
        "name": "email",
        "variableName": "email"
      },
      {
        "kind": "Variable",
        "name": "name",
        "variableName": "name"
      },
      {
        "kind": "Variable",
        "name": "password",
        "variableName": "password"
      },
      {
        "kind": "Variable",
        "name": "passwordConfirm",
        "variableName": "passwordConfirm"
      }
    ],
    "concreteType": "LoginResult",
    "plural": false,
    "selections": [
      {
        "kind": "ScalarField",
        "alias": null,
        "name": "token",
        "args": null,
        "storageKey": null
      },
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "user",
        "storageKey": null,
        "args": null,
        "concreteType": "User",
        "plural": false,
        "selections": [
          {
            "kind": "ScalarField",
            "alias": null,
            "name": "name",
            "args": null,
            "storageKey": null
          }
        ]
      }
    ]
  }
];
return {
  "kind": "Request",
  "fragment": {
    "kind": "Fragment",
    "name": "SignupMutation",
    "type": "RootMutationType",
    "metadata": null,
    "argumentDefinitions": (v0/*: any*/),
    "selections": (v1/*: any*/)
  },
  "operation": {
    "kind": "Operation",
    "name": "SignupMutation",
    "argumentDefinitions": (v0/*: any*/),
    "selections": (v1/*: any*/)
  },
  "params": {
    "operationKind": "mutation",
    "name": "SignupMutation",
    "id": null,
    "text": "mutation SignupMutation(\n  $email: String!\n  $name: String!\n  $password: String!\n  $passwordConfirm: String!\n) {\n  register(name: $name, email: $email, password: $password, passwordConfirm: $passwordConfirm) {\n    token\n    user {\n      name\n    }\n  }\n}\n",
    "metadata": {}
  }
};
})());

exports.Unions = Unions;
exports.Types = Types;
exports.Internal = Internal;
exports.Utils = Utils;
exports.node = node;
/* wrapResponseConverter Not a pure module */
