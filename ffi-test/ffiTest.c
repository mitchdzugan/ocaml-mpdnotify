#include <stdio.h>

#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/custom.h>

value
caml_ffi_test( value i )
{
    CAMLparam1( i );
    printf( "%i\n", Int_val(i) );
    CAMLreturn( Val_unit );
}
