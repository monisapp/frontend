let convertError =
  [@bs.open]
  (
    fun
    | ReasonRelay.Mutation_failed(errors) => errors
  );
