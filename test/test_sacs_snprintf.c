

#include <stdio.h>
#include "test_sacs.h"



#include "struct_test_sacs_snprintf_char.h"




/** Test helper function, will parse then print a test string and compared to the expected string.
 */
static void test_cycle_sacs_snprintf_char(const char* expect_string, const char* test_string)
{
  struct struct_test_sacs_snprintf_char test_struct = {0};
  
  const size_t snprintf_result = SACS_PARSE_TYPE(struct_test_sacs_snprintf_char, &test_struct, test_string);
  assert(snprintf_result == strlen(test_string));
  
  char result_string[256] = {0};
  struct SacsStructSnprintfFormat format = SACS_SNPRINTF_FORMAT_DEFAULT;
  
  const size_t result_string_size = SACS_SNPRINTF_TYPE(struct_test_sacs_snprintf_char, &test_struct, result_string, sizeof(result_string), &format);  
  assert(result_string_size == strlen(expect_string));
  
  assert(0 == strcmp(expect_string, result_string));  
}




static void test_sacs_snprintf_char(void)
{
  printf("%s\n", __FUNCTION__);
  
  // Test 'a'
  {
    const char test_string[] = "{.value='a',}"; 
    
    test_cycle_sacs_snprintf_char(test_string, test_string);
  }
  
  
  // Test '\0'
  {
    const char test_string[] = "{.value='\\0',}"; 

    test_cycle_sacs_snprintf_char(test_string, test_string);    
  }
  
  
  // Test '\012'
  {
    const char test_string[] = "{.value='\\012',}"; 
    
    test_cycle_sacs_snprintf_char(test_string, test_string);     
  }
  
  
  // Test '\321'
  {
    const char test_string[] = "{.value='\\321',}"; 
    
    test_cycle_sacs_snprintf_char(test_string, test_string);     
  }
  
  
  // Test 1
  {
    const char test_string[] = "{.value=1,}"; 
    const char expect_string[] = "{.value='\\001',}";
    
    test_cycle_sacs_snprintf_char(expect_string, test_string);     
  }
}




void test_sacs_snprintf(void)
{
  printf("%s\n", __FUNCTION__);
  
  test_sacs_snprintf_char();
  
//  struct TestSacsStruct test_struct = {0};
//
//  {
//
//    
//    char result_string[4096] = {0};
//
//  const size_t test_string0_length = strlen(test_string0);
////  const size_t test_string1_length = strlen(test_string1);
//
//  struct TestSacsStruct test_struct = {0};
  
//  const size_t parse_result0 = SACS_PARSE_TYPE(TestSacsStruct, &test_struct, test_string0);
//  assert(0 < parse_result0);
//  assert(test_string0_length == parse_result0);
//  
////  struct SacsStructSnprintfFormat format = SACS_SNPRINTF_FORMAT_DEFAULT;   
////  struct SacsStructSnprintfFormat format = SACS_SNPRINTF_FORMAT_C89; 
//  struct SacsStructSnprintfFormat format = SACS_SNPRINTF_FORMAT_PRETTY; 
//  
//  size_t result_string_size = SACS_SNPRINTF_TYPE(TestSacsStruct, &test_struct, result_string, sizeof(result_string), &format);
//  puts(result_string);
//  
////  size_t pretty_string_size = sacs_snprettyf(pretty_string, sizeof(pretty_string), result_string, result_string_size);  
////  assert(0 < pretty_string_size);  
////  puts(pretty_string);
//  
//  
//  const size_t parse_result1 = SACS_PARSE_TYPE(TestSacsStruct, &test_struct, test_string1);
//  assert(0 < parse_result1);
//  assert(test_string1_length == parse_result1);
//  
//  result_string_size = SACS_SNPRINTF_TYPE(TestSacsStruct, &test_struct, result_string, sizeof(result_string), &format);
//  puts(result_string);
//  
////  pretty_string_size = sacs_snprettyf(pretty_string, sizeof(pretty_string), result_string, result_string_size);  
////  assert(0 < pretty_string_size);
////  puts(pretty_string);
}







