// Snippet adapted from https://github.com/MargaretKrutikova/use-click-outside-re
// MIT License

let handleClickOutside = (domElement: Dom.element, e: Dom.mouseEvent, fn) => {
  let targetElement = Webapi.Dom.MouseEvent.target(e) |> Webapi.Dom.EventTarget.unsafeAsElement;

  !(domElement |> Webapi.Dom.Element.contains(targetElement)) ? fn(e) : ();
};

let useClickOutside = (onClickOutside: Dom.mouseEvent => unit) => {
  let elementRef = React.useRef(Js.Nullable.null);

  let handleMouseDown = (e: Dom.mouseEvent) => {
    elementRef.current
    ->Js.Nullable.toOption
    ->Belt.Option.map(refValue =>
        handleClickOutside(refValue, e, onClickOutside)
      )
    ->ignore;
  };

  React.useEffect0(() => {
    Webapi.Dom.Document.addMouseDownEventListener(handleMouseDown, Webapi.Dom.document);
    Some(
      () => Webapi.Dom.Document.removeMouseDownEventListener(handleMouseDown, Webapi.Dom.document),
    );
  });

  elementRef;
};
