

#include "test_sacs_snprintf.h"




#include "struct_test_sacs_snprintf_char.h"
#include "struct_test_sacs_snprintf_chars.h"
#include "struct_test_sacs_snprintf_double.h"
#include "struct_test_sacs_snprintf_float.h"
#include "struct_test_sacs_snprintf_int.h"
#include "struct_test_sacs_snprintf_int_array.h"




#include "../src/sacs_util.h"
#include "../src/sacs_format.h"

#include <assert.h>




/** Test helper function, will parse then print a test string and compared to the expected string.
 */
static void test_cycle_sacs_snprintf_char(const char* expect_string, const char* test_string)
{
  struct struct_test_sacs_snprintf_char test_struct = {0};
  char result_string[256] = {0};
  struct SacsStructFormat format = SACS_FORMAT_DEFAULT;  

  
  const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_snprintf_char, &test_struct, test_string);
  assert(parse_result == strlen(test_string));    
  
  memset(result_string, 0, sizeof(result_string));
  const size_t parsesnprintf_string_size = SACS_PARSESNPRINTF_TYPE( struct_test_sacs_snprintf_char, &test_struct, result_string, sizeof(result_string), &format, test_string);
  
  assert(parsesnprintf_string_size == strlen(expect_string));  
  assert(0 == strcmp(expect_string, result_string));  
  
  

  const size_t result_string_size = SACS_SNPRINTF_TYPE(struct_test_sacs_snprintf_char, &test_struct, result_string, sizeof(result_string), &format);  
  assert(result_string_size == strlen(expect_string));  
  assert(0 == strcmp(expect_string, result_string));  
  puts(result_string);

  
  const struct SacsStructFormat pretty_format = SACS_FORMAT_PRETTY;    
  memset(result_string, 0, sizeof(result_string));
  const size_t pretty_string_size = SACS_SNPRINTF_TYPE(struct_test_sacs_snprintf_char, &test_struct, result_string, sizeof(result_string), &pretty_format);  
  
  assert(pretty_string_size == strlen(result_string)); 
  puts(result_string);
  
  
  memset(result_string, 0, sizeof(result_string));
  const size_t json_string_size = SACS_SNPRINTF_TYPE_AS_JSON(struct_test_sacs_snprintf_char, &test_struct, result_string, sizeof(result_string));
  
  assert(json_string_size == strlen(result_string));  
  puts(result_string);  
  
  
  memset(result_string, 0, sizeof(result_string));
  const size_t xml_string_size = SACS_SNPRINTF_TYPE_AS_XML(struct_test_sacs_snprintf_char, &test_struct, result_string, sizeof(result_string));
  
  assert(xml_string_size == strlen(result_string));  
  puts(result_string);
  
  
  memset(result_string, 0, sizeof(result_string));
  const size_t yaml_string_size = SACS_SNPRINTF_TYPE_AS_YAML(struct_test_sacs_snprintf_char, &test_struct, result_string, sizeof(result_string));
  
  assert(yaml_string_size == strlen(result_string));  
  puts(result_string);  
  
}




static void test_cycle_sacs_snprintf_chars(const char* expect_string, const char* test_string)
{  
  struct struct_test_sacs_snprintf_chars test_struct = {0};
 
  puts(test_string);
  
  const size_t snprintf_result = SACS_PARSE_TYPE(struct_test_sacs_snprintf_chars, &test_struct, test_string);
  assert(snprintf_result == strlen(test_string));
  
  char result_string[256] = {0};
  struct SacsStructFormat format = SACS_FORMAT_DEFAULT;
  
  const size_t result_string_size = SACS_SNPRINTF_TYPE(struct_test_sacs_snprintf_chars, &test_struct, result_string, sizeof(result_string), &format);  
  assert(result_string_size == strlen(expect_string));
  
  assert(0 == strcmp(expect_string, result_string));  
  
  
  memset(result_string, 0, sizeof(result_string));
  const size_t json_string_size = SACS_SNPRINTF_TYPE_AS_JSON(struct_test_sacs_snprintf_chars, &test_struct, result_string, sizeof(result_string));
  
  assert(json_string_size == strlen(result_string));  
  puts(result_string);  
  
  
  memset(result_string, 0, sizeof(result_string));
  const size_t xml_string_size = SACS_SNPRINTF_TYPE_AS_XML(struct_test_sacs_snprintf_chars, &test_struct, result_string, sizeof(result_string));
  
  assert(xml_string_size == strlen(result_string));  
  puts(result_string);  
  
  
  memset(result_string, 0, sizeof(result_string));
  const size_t yaml_string_size = SACS_SNPRINTF_TYPE_AS_YAML(struct_test_sacs_snprintf_chars, &test_struct, result_string, sizeof(result_string));
  
  assert(yaml_string_size == strlen(result_string));  
  puts(result_string);    
}




static void test_cycle_sacs_snprintf_int(const char* expect_string, const char* test_string)
{
  struct struct_test_sacs_snprintf_int test_struct = {0};
  
  puts(test_string);
  
  const size_t snprintf_result = SACS_PARSE_TYPE(struct_test_sacs_snprintf_int, &test_struct, test_string);
  assert(snprintf_result == strlen(test_string));
  
  char result_string[256] = {0};
  struct SacsStructFormat format = SACS_FORMAT_DEFAULT;
  
  const size_t result_string_size = SACS_SNPRINTF_TYPE(struct_test_sacs_snprintf_int, &test_struct, result_string, sizeof(result_string), &format);  
  assert(result_string_size == strlen(expect_string));
  
  assert(0 == strcmp(expect_string, result_string));  
  
  
  memset(result_string, 0, sizeof(result_string));
  const size_t json_string_size = SACS_SNPRINTF_TYPE_AS_JSON(struct_test_sacs_snprintf_int, &test_struct, result_string, sizeof(result_string));
  
  assert(json_string_size == strlen(result_string));  
  puts(result_string);  
  
  
  memset(result_string, 0, sizeof(result_string));
  const size_t xml_string_size = SACS_SNPRINTF_TYPE_AS_XML(struct_test_sacs_snprintf_int, &test_struct, result_string, sizeof(result_string));
  
  assert(xml_string_size == strlen(result_string));  
  puts(result_string);
  

  memset(result_string, 0, sizeof(result_string));
  const size_t yaml_string_size = SACS_SNPRINTF_TYPE_AS_YAML(struct_test_sacs_snprintf_int, &test_struct, result_string, sizeof(result_string));
  
  assert(yaml_string_size == strlen(result_string));  
  puts(result_string);   
}




static void test_cycle_sacs_snprintf_int_array(const char* expect_string, const char* test_string)
{
  struct struct_test_sacs_snprintf_int_array test_struct = {0};
  
  puts(test_string);
  
  const size_t snprintf_result = SACS_PARSE_TYPE(struct_test_sacs_snprintf_int_array, &test_struct, test_string);
  assert(snprintf_result == strlen(test_string));
  
  char result_string[256] = {0};
  struct SacsStructFormat format = SACS_FORMAT_DEFAULT;
  
  const size_t result_string_size = SACS_SNPRINTF_TYPE(struct_test_sacs_snprintf_int_array, &test_struct, result_string, sizeof(result_string), &format);  
  assert(result_string_size == strlen(expect_string));
  
  assert(0 == strcmp(expect_string, result_string));  
  
  
  memset(result_string, 0, sizeof(result_string));
  const size_t json_string_size = SACS_SNPRINTF_TYPE_AS_JSON(struct_test_sacs_snprintf_int_array, &test_struct, result_string, sizeof(result_string));
  
  assert(json_string_size == strlen(result_string));  
  puts(result_string);  
  
  
  memset(result_string, 0, sizeof(result_string));
  const size_t xml_string_size = SACS_SNPRINTF_TYPE_AS_XML(struct_test_sacs_snprintf_int_array, &test_struct, result_string, sizeof(result_string));
  
  assert(xml_string_size == strlen(result_string));  
  puts(result_string);
  

  memset(result_string, 0, sizeof(result_string));
  const size_t yaml_string_size = SACS_SNPRINTF_TYPE_AS_YAML(struct_test_sacs_snprintf_int_array, &test_struct, result_string, sizeof(result_string));
  
  assert(yaml_string_size == strlen(result_string));  
  puts(result_string);     
}




static void test_cycle_sacs_snprintf_float(const char* expect_string, const char* test_string)
{
  struct struct_test_sacs_snprintf_float test_struct = {0};
  
  puts(test_string);
  
  const size_t snprintf_result = SACS_PARSE_TYPE(struct_test_sacs_snprintf_float, &test_struct, test_string);
  assert(snprintf_result == strlen(test_string));
  
  char result_string[256] = {0};
  struct SacsStructFormat format = SACS_FORMAT_DEFAULT;
  
  const size_t result_string_size = SACS_SNPRINTF_TYPE(struct_test_sacs_snprintf_float, &test_struct, result_string, sizeof(result_string), &format);  
  assert(result_string_size == strlen(expect_string));
  
  assert(0 == strcmp(expect_string, result_string));  
  
  
  memset(result_string, 0, sizeof(result_string));
  const size_t json_string_size = SACS_SNPRINTF_TYPE_AS_JSON(struct_test_sacs_snprintf_float, &test_struct, result_string, sizeof(result_string));
  
  assert(json_string_size == strlen(result_string));  
  puts(result_string);  
  
  
  memset(result_string, 0, sizeof(result_string));
  const size_t xml_string_size = SACS_SNPRINTF_TYPE_AS_XML(struct_test_sacs_snprintf_float, &test_struct, result_string, sizeof(result_string));
  
  assert(xml_string_size == strlen(result_string));  
  puts(result_string);
  

  memset(result_string, 0, sizeof(result_string));
  const size_t yaml_string_size = SACS_SNPRINTF_TYPE_AS_YAML(struct_test_sacs_snprintf_float, &test_struct, result_string, sizeof(result_string));
  
  assert(yaml_string_size == strlen(result_string));  
  puts(result_string);   
}




static void test_cycle_sacs_snprintf_double(const char* expect_string, const char* test_string)
{
  struct struct_test_sacs_snprintf_double test_struct = {0};
  
  puts(test_string);
  
  const size_t snprintf_result = SACS_PARSE_TYPE(struct_test_sacs_snprintf_double, &test_struct, test_string);
  assert(snprintf_result == strlen(test_string));
  
  char result_string[256] = {0};
  struct SacsStructFormat format = SACS_FORMAT_DEFAULT;
  
  const size_t result_string_size = SACS_SNPRINTF_TYPE(struct_test_sacs_snprintf_double, &test_struct, result_string, sizeof(result_string), &format);  
  assert(result_string_size == strlen(expect_string));
  
  assert(0 == strcmp(expect_string, result_string));
  
  
  memset(result_string, 0, sizeof(result_string));
  const size_t json_string_size = SACS_SNPRINTF_TYPE_AS_JSON(struct_test_sacs_snprintf_double, &test_struct, result_string, sizeof(result_string));
  
  assert(json_string_size == strlen(result_string));  
  puts(result_string);  
  
  
  memset(result_string, 0, sizeof(result_string));
  const size_t xml_string_size = SACS_SNPRINTF_TYPE_AS_XML(struct_test_sacs_snprintf_double, &test_struct, result_string, sizeof(result_string));
  
  assert(xml_string_size == strlen(result_string));  
  puts(result_string);     
  
  
  memset(result_string, 0, sizeof(result_string));
  const size_t yaml_string_size = SACS_SNPRINTF_TYPE_AS_YAML(struct_test_sacs_snprintf_double, &test_struct, result_string, sizeof(result_string));
  
  assert(yaml_string_size == strlen(result_string));  
  puts(result_string);   
}





static void test_sacs_snprintf_char(void)
{
  printf("%s\n", __FUNCTION__);
  
  
  // Test 'a'
  {
    const char test_string[] = "{.value='a'}"; 
    
    test_cycle_sacs_snprintf_char(test_string, test_string);
  }  
  
  
  // Test '\0'
  {
    const char test_string[] = "{.value='\\0'}"; 

    test_cycle_sacs_snprintf_char(test_string, test_string);    
  }
  
  
  // Test '\012'
  {
    const char test_string[] = "{.value='\\012'}"; 
    
    test_cycle_sacs_snprintf_char(test_string, test_string);     
  }
  
  
  // Test '\321'
  {
    const char test_string[] = "{.value='\\321'}"; 
    
    test_cycle_sacs_snprintf_char(test_string, test_string);     
  }
  
  
  // Test 1
  {
    const char test_string[] = "{.value=1}"; 
    const char expect_string[] = "{.value='\\001'}";
    
    test_cycle_sacs_snprintf_char(expect_string, test_string);     
  }
}




static void test_sacs_snprintf_chars(void)
{
  printf("%s\n", __FUNCTION__);
  
  // Test 'a'
  {
    const char test_string[] = "{.value=\"Hello World\"}"; 
    
    test_cycle_sacs_snprintf_chars(test_string, test_string);
  }
}




static void test_sacs_snprintf_int(void)
{
  printf("%s\n", __FUNCTION__);
  
  {
    const char test_string[] = "{.value=0}"; 
    
    test_cycle_sacs_snprintf_int(test_string, test_string);
  }
  
  {
    const char test_string[] = "{.value=1}"; 
    
    test_cycle_sacs_snprintf_int(test_string, test_string);
  }
  
  {
    const char test_string[] = "{.value=1234567890}"; 
    
    test_cycle_sacs_snprintf_int(test_string, test_string);
  }  

  {
    const char test_string[] = "{.value=-1}"; 
    
    test_cycle_sacs_snprintf_int(test_string, test_string);
  }
  
  {
    const char test_string[] = "{.value=-1234567890}"; 
    
    test_cycle_sacs_snprintf_int(test_string, test_string);
  }   
  
}



static void test_sacs_snprintf_int_array(void)
{
  printf("%s\n", __FUNCTION__);
  
  {
    const char test_string[] = "{.value={0,0,0}}"; 
    
    test_cycle_sacs_snprintf_int_array(test_string, test_string);
  }
  
  {
    const char test_string[] = "{.value={1,2,3}}"; 
    
    test_cycle_sacs_snprintf_int_array(test_string, test_string);
  }
  
  {
    const char test_string[] = "{.value={1234567890,0,0}}"; 
    
    test_cycle_sacs_snprintf_int_array(test_string, test_string);
  }  
  
  {
    const char test_string[] = "{.value={-1,-2,-3}}"; 
    
    test_cycle_sacs_snprintf_int_array(test_string, test_string);
  }
  
  {
    const char test_string[] = "{.value={-1234567890,0,0}}"; 
    
    test_cycle_sacs_snprintf_int_array(test_string, test_string);
  }   
  
}




static void test_sacs_snprintf_float(void)
{
  printf("%s\n", __FUNCTION__);
  
  {
    const char test_string[] = "{.value=0.000000}"; 
    
    test_cycle_sacs_snprintf_float(test_string, test_string);
  }
  
  
  {
    const char test_string[] = "{.value=1.000000}"; 
    
    test_cycle_sacs_snprintf_float(test_string, test_string);
  }  
  
  {
    const char test_string[] = "{.value=-1.000000}"; 
    
    test_cycle_sacs_snprintf_float(test_string, test_string);
  }   
  
  
  {
    const char test_string[] = "{.value=12.345678}"; 
    
    test_cycle_sacs_snprintf_float(test_string, test_string);
  }    
  

  {
    const char test_string[] = "{.value=12345678.000000}"; 
    
    test_cycle_sacs_snprintf_float(test_string, test_string);
  }    
}




static void test_sacs_snprintf_double(void)
{
  printf("%s\n", __FUNCTION__);
  
  {
    const char test_string[] = "{.value=0.000000}"; 
    
    test_cycle_sacs_snprintf_double(test_string, test_string);
  }
  
  
  {
    const char test_string[] = "{.value=1.000000}"; 
    
    test_cycle_sacs_snprintf_double(test_string, test_string);
  }  
  
  {
    const char test_string[] = "{.value=-1.000000}"; 
    
    test_cycle_sacs_snprintf_double(test_string, test_string);
  }   
  
  
  {
    const char test_string[] = "{.value=12.345678}"; 
    
    test_cycle_sacs_snprintf_double(test_string, test_string);
  }    
  
  
  {
    const char test_string[] = "{.value=12345678.000000}"; 
    
    test_cycle_sacs_snprintf_double(test_string, test_string);
  }    
}




void test_sacs_snprintf(void)
{
  printf("%s\n", __FUNCTION__);
  
  test_sacs_snprintf_char();
  
//  test_sacs_snprintf_chars();
  
  test_sacs_snprintf_double();
  test_sacs_snprintf_int();
  test_sacs_snprintf_int_array();
  
  test_sacs_snprintf_float();
  
  
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







