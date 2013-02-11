
#ifndef TESTSACSSTRUCTPARSECHARINT_H


#include <stdio.h>

#include "../src/sacs.h"




#undef SACS_STRUCT
#define SACS_STRUCT struct_test_sacs_parse_char_int

#include "../src/sacs_struct.h"
#include "struct_test_sacs_parse_char_int.sac"

#include "../src/sacs_parsable.h"
#include "struct_test_sacs_parse_char_int.sac"

#include "../src/sacs_snprintfable.h"
#include "struct_test_sacs_parse_char_int.sac"




#endif
