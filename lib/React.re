module Js = Js_of_ocaml.Js;

type element;
let null: element = Js.Unsafe.js_expr("null");

external string: Js.t(Js.js_string) => element = "%identity";
let string = s => string(Js.string(s));

external array: array(element) => element = "%identity";

type componentLike('props, 'return) = 'props => 'return;

type component('props) = componentLike('props, element);

class type react = {
  pub createElement: (component('props), 'props) => Js.meth(element);
  pub _Fragment: Js.readonly_prop(Js.js_string);
};

class type reactRef ('value) = {
  pub current: Js.readonly_prop('value);
  pub current_value: 'value => Js.meth(unit);
};
/*type domRef = t(Js.nullable(Dom.element));
type refForRecordAPI = Js.nullable(Dom.element) => unit;*/
/* These are both hacky interop things because React has n different ways of dealing with refs */
/*external refForRecordAPI: domRef => refForRecordAPI = "%identity";
external refForHooks: refForRecordAPI => domRef = "%identity";*/

let react: Js.t(react) = Js.Unsafe.global##.React;
let createElement = (c, p) => react##createElement(c, p);

type context('a);

[@bs.module "react"] external createContext: 'a => context('a) = "";

/*
module Context = {
  module Provider = (C: {
                       type t;
                       let context: context(t);
                     }) => {
    type props = {
      .
      "value": C.t,
      "children": element,
    };

    [@bs.get]
    external provider: context(C.t) => component(props) = "Provider";

    [@bs.obj]
    external makeProps: (~value: C.t, ~children: element, unit) => props = "";

    let make: props => element = C.context->provider;
  };
};
*/

[@bs.module "react"]
external memo: component('props) => component('props) = "";

/* HOOKS */

/*
 * Yeah, we know this api isn't great. tl;dr: useReducer instead.
 * It's because useState can take functions or non-function values and treats
 * them differently. Lazy initializer + callback which returns state is the
 * only way to safely have any type of state and be able to update it correctly.
 */
[@bs.module "react"]
external useState: (unit => 'state) => ('state, ('state => 'state) => unit) =
  "";

[@bs.module "react"]
external useReducer:
  (('state, 'action) => 'state, 'state) => ('state, 'action => unit) =
  "";

[@bs.module "react"]
external useReducerWithMapState:
  (('state, 'action) => 'state, 'initialState, 'initialState => 'state) =>
  ('state, 'action => unit) =
  "useReducer";

[@bs.module "react"]
external useEffect: (unit => option(unit => unit)) => unit = "useEffect";
[@bs.module "react"]
external useEffect0:
  (unit => option(unit => unit), [@bs.as {json|[]|json}] _) => unit =
  "useEffect";
[@bs.module "react"]
external useEffect1: (unit => option(unit => unit), array('a)) => unit =
  "useEffect";
[@bs.module "react"]
external useEffect2: (unit => option(unit => unit), ('a, 'b)) => unit =
  "useEffect";

[@bs.module "react"]
external useLayoutEffect: (unit => option(unit => unit)) => unit =
  "useLayoutEffect";
[@bs.module "react"]
external useLayoutEffect0:
  (unit => option(unit => unit), [@bs.as {json|[]|json}] _) => unit =
  "useLayoutEffect";
[@bs.module "react"]
external useLayoutEffect1: (unit => option(unit => unit), array('a)) => unit =
  "useLayoutEffect";
[@bs.module "react"]
external useLayoutEffect2: (unit => option(unit => unit), ('a, 'b)) => unit =
  "useLayoutEffect";

[@bs.module "react"] external useMemo: (unit => 'any) => 'any = "useMemo";
[@bs.module "react"]
external useMemo0: (unit => 'any, [@bs.as {json|[]|json}] _) => 'any =
  "useMemo";
[@bs.module "react"]
external useMemo1: (unit => 'any, array('a)) => 'any = "useMemo";
[@bs.module "react"]
external useMemo2: (unit => 'any, ('a, 'b)) => 'any = "useMemo";

type callback('input, 'output) = 'input => 'output;

[@bs.module "react"]
external useCallback:
  callback('intput, 'output) => callback('intput, 'output) =
  "useCallback";
[@bs.module "react"]
external useCallback0:
  (callback('intput, 'output), [@bs.as {json|[]|json}] _) =>
  callback('intput, 'output) =
  "useCallback";
[@bs.module "react"]
external useCallback1:
  (callback('intput, 'output), array('a)) => callback('intput, 'output) =
  "useCallback";
[@bs.module "react"]
external useCallback2:
  (callback('intput, 'output), ('a, 'b)) => callback('intput, 'output) =
  "useCallback";
[@bs.module "react"]
external useCallback3:
  (callback('intput, 'output), ('a, 'b, 'c)) => callback('intput, 'output) =
  "useCallback";

[@bs.module "react"] external useContext: context('any) => 'any = "";

[@bs.module "react"] external useRef: 'value => reactRef('value) = "";

[@bs.set]
external setDisplayName: (component('props), string) => unit = "displayName";