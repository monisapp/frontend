type t =
  | SetTransactionModal(bool)
  | SetAccountModal(bool);

type performAction = t => unit
