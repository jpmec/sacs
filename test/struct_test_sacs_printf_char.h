
#ifndef TESTSACSSTRUCTPRINTFCHAR_H


#include <stdio.h>

#include "../src/sacs.h"




#undef SACS_STRUCT
#define SACS_STRUCT struct_test_sacs_printf_char

#include "../src/sacs_struct.h"
#include "struct_test_sacs_printf_char.sac"

#include "../src/sacs_parsable.h"
#include "struct_test_sacs_printf_char.sac"

#include "../src/sacs_printfable.h"
#include "struct_test_sacs_printf_char.sac"




#endif
