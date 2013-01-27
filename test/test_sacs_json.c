

#include "test_sacs_json.h"

//#include "../src/sacs.c"


//static void test_sacs_json(void)
//{
//  struct TestSacsStruct test_struct = {0};
//  
//  char result_string[1024] = {0};
//  char pretty_string[1024] = {0};
////  char ctojson_string[1024] = {0};
////  char jsontoc_string[1024] = {0};
////  char json_string[1024] = {0};
//  
//  const size_t parse_result = SACS_PARSE_TYPE(TestSacsStruct, &test_struct, test_string0);
//  assert(0 < parse_result);
//  
//  size_t result_string_size = SACS_SNPRINTF_TYPE(TestSacsStruct, &test_struct, result_string, sizeof(result_string));
//  puts(result_string);
//  
//  size_t pretty_string_size = sacs_snprettyf(pretty_string, sizeof(pretty_string), result_string, result_string_size);  
//  assert(0 < pretty_string_size);
//  puts(pretty_string);
//  
////  size_t ctojson_string_size = sacs_ctojson(ctojson_string, sizeof(ctojson_string), pretty_string, pretty_string_size);  
////  assert(0 < ctojson_string_size);
////  puts(ctojson_string);
////  
////  size_t jsontoc_string_size = sacs_jsontoc(jsontoc_string, sizeof(jsontoc_string), ctojson_string, ctojson_string_size);  
////  assert(0 < jsontoc_string_size);
////  puts(jsontoc_string);  
////  
////  size_t json_string_size = SACS_SNPRINTF_TYPE_AS_JSON(TestSacsStruct, &test_struct, json_string, sizeof(json_string));
////  assert(0 < json_string_size);
////  puts(json_string);
//}








static void test_sacs_json_bool(void)
{
  printf("%s\n", __FUNCTION__);
  
  
  // Test true
  {
    const bool expect = true;
    
    const char test_json_bool_string[] = " { .value = true } ";
    
    struct struct_test_sacs_parse_bool test_struct = {0};
    
    const size_t json_result = SACS_PARSE_TYPE(struct_test_sacs_parse_bool, &test_struct, test_json_bool_string);
    assert(json_result == strlen(test_json_bool_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test false
  {
    const bool expect = false;
    
    const char test_json_bool_string[] = " { .value = false } "; 
    
    struct struct_test_sacs_parse_bool test_struct = {0};
    
    const size_t json_result = SACS_PARSE_TYPE(struct_test_sacs_parse_bool, &test_struct, test_json_bool_string);
    assert(json_result == strlen(test_json_bool_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 0
  {
    const bool expect = 0;
    
    const char test_json_bool_string[] = " { .value = 0 } ";
    
    struct struct_test_sacs_parse_bool test_struct = {0};
    
    const size_t json_result = SACS_PARSE_TYPE(struct_test_sacs_parse_bool, &test_struct, test_json_bool_string);
    assert(json_result == strlen(test_json_bool_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 1
  {
    const bool expect = 1;
    
    const char test_json_bool_string[] = " { .value = 1 } ";
    
    struct struct_test_sacs_parse_bool test_struct = {0};
    
    const size_t json_result = SACS_PARSE_TYPE(struct_test_sacs_parse_bool, &test_struct, test_json_bool_string);
    assert(json_result == strlen(test_json_bool_string));
    
    assert(expect == test_struct.value);  
  }
  
  
  // Test 2
  {
    const bool expect = 2;
    
    const char test_json_bool_string[] = " { .value = 2 } ";
    
    struct struct_test_sacs_parse_bool test_struct = {0};
    
    const size_t json_result = SACS_PARSE_TYPE(struct_test_sacs_parse_bool, &test_struct, test_json_bool_string);
    assert(json_result == strlen(test_json_bool_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 01
  {
    const bool expect = 1;
    
    const char test_json_bool_string[] = " { .value = 01 } ";
    
    struct struct_test_sacs_parse_bool test_struct = {0};    
    
    const size_t json_result = SACS_PARSE_TYPE(struct_test_sacs_parse_bool, &test_struct, test_json_bool_string);
    assert(json_result == strlen(test_json_bool_string));
    
    assert(expect == test_struct.value);  
  }
  
  
  // Test missing field
  {
    const char test_json_bool_string[] = " { } "; 
    
    struct struct_test_sacs_parse_bool test_struct = {0};    
    
    const size_t json_result = SACS_PARSE_TYPE(struct_test_sacs_parse_bool, &test_struct, test_json_bool_string);
    assert(json_result == strlen(test_json_bool_string));
    
    assert(false == test_struct.value);  
  }
  
  // Test invalid string
  {
    const char test_json_bool_string[] = " { .value = } ";
    
    struct struct_test_sacs_parse_bool test_struct = {0};    
    
    const size_t json_result = SACS_PARSE_TYPE(struct_test_sacs_parse_bool, &test_struct, test_json_bool_string);
    assert(0 == json_result);
    
    assert(false == test_struct.value);  
  }
}






void test_sacs_json(void)
{

  test_sacs_json_bool();
  

}


