all:
	ocamlc -c ffiTest.c
	ocamlmklib ffiTest.o ffiTestModule.mli -o ffiTestModule
	ocamlfind install ffiTestModule META ffiTestModule.cm* *.mli *.a *.so
	ocamlfind ocamlopt -linkpkg -package ffiTestModule ffiTest.ml -o ffiTest 

clean:
	ocamlfind remove ffiTestModule
	rm *.o *.a *.so *.cm* ffiTest
