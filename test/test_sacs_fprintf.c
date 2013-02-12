

#include "test_sacs_fprintf.h"



#include "struct_test_sacs_fprintf_char.h"

#include "../src/sacs_util.h"


#include <assert.h>




static void test_sacs_fprintf_char(void)
{
  printf("%s\n", __FUNCTION__);
}




void test_sacs_fprintf(void)
{
  printf("%s\n", __FUNCTION__);
  
  test_sacs_fprintf_char();
  
}







