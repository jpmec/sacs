/** Test sacs library.
 */




#include "test_sacs.h"

#include "../src/sacs.c"

#include "test_sacs_parse.h"
#include "test_sacs_parse.c"

#include "test_sacs_snprintf.h"
#include "test_sacs_snprintf.c"

#include "test_sacs_fprintf.h"
#include "test_sacs_fprintf.c"

//#include "test_sacs_printf.h"
//#include "test_sacs_printf.c"

#include "test_sacs_json.h"
#include "test_sacs_json.c"


#include <stdio.h>




int test_sacs(void)
{
  test_sacs_parse();
  test_sacs_snprintf();
  test_sacs_fprintf();
//  test_sacs_printf();

  test_sacs_json();

  return 0;
}
