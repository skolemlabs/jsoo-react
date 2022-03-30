(lang dune 3.0)

(name jsoo-react)

(license MIT)

(maintainers "Javier Chávarri <javier.chavarri@gmail.com>")

(authors "Javier Chávarri <javier.chavarri@gmail.com>")

(source
 (github ml-in-barcelona/jsoo-react))

(generate_opam_files true)

(implicit_transitive_deps false)

(package
 (name jsoo-react)
 (synopsis "Bindings to ReactJS for js_of_ocaml, including JSX ppx")
 (depends
  ;; General system dependencies
  (dune (and (>= 2) (< 4)))
  (ocaml (and (>= 4.10.0) (< 5.0.0)))

  js_of_ocaml
  gen_js_api
  (ppxlib (>= 0.23.0))

  ;; Test dependencies
  (webtest :with-test)
  (webtest-js :with-test)
  (js_of_ocaml-ppx :with-test)
  (conf-npm :with-test)

  ;; Dev dependencies, using with-test so that consumers don't install them (until package is released in opam)
  (ocamlformat (and (= 0.20.1) :with-test))
  (reason :with-test)

  ;; Example dependencies, using with-test so that consumers don't install them (until package is released in opam)
  (ppx_blob :with-test)
  (js_of_ocaml-lwt :with-test)
))
