#include <stdio.h>

#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/custom.h>

value
caml_ffi_test( value unit )
{
    CAMLparam1( unit );
    printf( "%s\n", __FILE__ );
    CAMLreturn( Val_unit );
}
