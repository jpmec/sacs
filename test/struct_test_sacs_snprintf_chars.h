
#ifndef TESTSACSSTRUCTSNPRINTFCHARS_H


#include <stdio.h>

#include "../src/sacs.h"




#undef SACS_STRUCT
#define SACS_STRUCT struct_test_sacs_snprintf_chars

#include "../src/sacs_struct.h"
#include "struct_test_sacs_snprintf_chars.sac"

#include "../src/sacs_parsable.h"
#include "struct_test_sacs_snprintf_chars.sac"

#include "../src/sacs_snprintfable.h"
#include "struct_test_sacs_snprintf_chars.sac"

#include "../src/sacs_jsonable.h"
#include "struct_test_sacs_snprintf_chars.sac"

#include "../src/sacs_xmlable.h"
#include "struct_test_sacs_snprintf_chars.sac"

#include "../src/sacs_yamlable.h"
#include "struct_test_sacs_snprintf_chars.sac"




#endif
