

#include <assert.h>
#include <stdio.h>
#include <string.h>


#include "test_sacs_parse.h"

#include "../src/sacs.h"




#include "struct_test_sacs_parse_bool.h"


static void test_sacs_parse_bool(void)
{
  printf("%s\n", __FUNCTION__);
  
  
  // Test true
  {
    const bool expect = true;
    
    const char test_parse_bool_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = true,      "
    "  };                         ";   

    struct struct_test_sacs_parse_bool test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_bool, &test_struct, test_parse_bool_string);
    assert(parse_result == strlen(test_parse_bool_string));

    assert(expect == test_struct.value);
  }
  
  
  // Test false
  {
    const bool expect = false;
    
    const char test_parse_bool_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = false,     "
    "  };                         "; 

    struct struct_test_sacs_parse_bool test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_bool, &test_struct, test_parse_bool_string);
    assert(parse_result == strlen(test_parse_bool_string));
  
    assert(expect == test_struct.value);
  }
  
  
  // Test 0
  {
    const bool expect = 0;
    
    const char test_parse_bool_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 0,         "
    "  };                         "; 

    struct struct_test_sacs_parse_bool test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_bool, &test_struct, test_parse_bool_string);
    assert(parse_result == strlen(test_parse_bool_string));
  
    assert(expect == test_struct.value);
  }
  
  
  // Test 1
  {
    const bool expect = 1;
    
    const char test_parse_bool_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 1,         "
    "  };                         "; 
  
    struct struct_test_sacs_parse_bool test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_bool, &test_struct, test_parse_bool_string);
    assert(parse_result == strlen(test_parse_bool_string));
  
    assert(expect == test_struct.value);  
  }
  
  
  // Test 2
  {
    const bool expect = 2;
    
    const char test_parse_bool_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 2,         "
    "  };                         "; 
  
    struct struct_test_sacs_parse_bool test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_bool, &test_struct, test_parse_bool_string);
    assert(parse_result == strlen(test_parse_bool_string));
  
    assert(expect == test_struct.value);
  }

  
  // Test 01
  {
    const bool expect = 2;
    
    const char test_parse_bool_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 01,        "
    "  };                         "; 

    struct struct_test_sacs_parse_bool test_struct = {0};    
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_bool, &test_struct, test_parse_bool_string);
    assert(parse_result == strlen(test_parse_bool_string));
  
    assert(expect == test_struct.value);  
  }
  
  
  // Test missing field
  {
    const char test_parse_bool_string[] = 
    "  (struct TestSacsStruct) {  "
    "  };                         "; 
  
    struct struct_test_sacs_parse_bool test_struct = {0};    
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_bool, &test_struct, test_parse_bool_string);
    assert(parse_result == strlen(test_parse_bool_string));
  
    assert(false == test_struct.value);  
  }
  
  // Test invalid string
  {
    const char test_parse_bool_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value =,           "
    "  };                         "; 

    struct struct_test_sacs_parse_bool test_struct = {0};    
  
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_bool, &test_struct, test_parse_bool_string);
    assert(parse_result == strlen(test_parse_bool_string));
  
    assert(false == test_struct.value);  
  }
}






#include "struct_test_sacs_parse_char.h"


static void test_sacs_parse_char(void)
{
  printf("%s\n", __FUNCTION__);
  
  // Test 'a'
  {
    const char expect = 'a';
    
    const char test_parse_char_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 'a',       "
    "  };                         "; 
    
    struct struct_test_sacs_parse_char test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_char, &test_struct, test_parse_char_string);
    assert(parse_result == strlen(test_parse_char_string));
    
    assert(expect == test_struct.value);  
  }  
  
  
  // Test '\0'
  {
    const char expect = '\0';
    
    const char test_parse_char_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = '\\0',     "
    "  };                         "; 
    
    struct struct_test_sacs_parse_char test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_char, &test_struct, test_parse_char_string);
    assert(parse_result == strlen(test_parse_char_string));
    
    assert(expect == test_struct.value);  
  } 

  
  // Test 0
  {
    const char expect = 0;
    
    const char test_parse_char_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 0,         "
    "  };                         ";   
  
    struct struct_test_sacs_parse_char test_struct = {0};
  
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_char, &test_struct, test_parse_char_string);
    assert(parse_result == strlen(test_parse_char_string));
  
    assert(expect == test_struct.value);
  }
  
  
  // Test 0x31
  {
    const char expect = 0x31;
    
    const char test_parse_char_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 0x31,      "
    "  };                         ";   
    
    struct struct_test_sacs_parse_char test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_char, &test_struct, test_parse_char_string);
    assert(parse_result == strlen(test_parse_char_string));
    
    assert(expect == test_struct.value);
  }
  
  // Test '\31'
  {
    const char expect = '\31';  // will interpret as octal
    
    const char test_parse_char_string[] = "{.value = '\\31',}";   
    
    struct struct_test_sacs_parse_char test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_char, &test_struct, test_parse_char_string);
    assert(parse_result == strlen(test_parse_char_string));
    
    assert(expect == test_struct.value);
  }
  
  // Test '\99'
  {
    const char expect = 9;  // will discard the \9 and parse the 9
    
    const char test_parse_char_string[] = "{.value = '\\99',}";   
    
    struct struct_test_sacs_parse_char test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_char, &test_struct, test_parse_char_string);
    assert(parse_result == strlen(test_parse_char_string));
    
    assert(expect == test_struct.value);
  }
}





#include "struct_test_sacs_parse_chars.h"


static void test_sacs_parse_chars(void)
{
  printf("%s\n", __FUNCTION__);
  
  // Test typical string  
  {
    const char expect[] = "Hello World";
    
    const char test_parse_chars_string[] = 
    "  (struct TestSacsStruct) {         "
    "    .value = \"Hello World\", "
    "  };                                ";   
    
    struct struct_test_sacs_parse_chars test_struct = {0};
  
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_chars, &test_struct, test_parse_chars_string);
    assert(parse_result == strlen(test_parse_chars_string));
  
    assert(0 == strcmp(expect, test_struct.value));
  }
  
  // Test empty string
  {
    const char expect[] = "";
    
    const char test_parse_chars_string[] = 
    "  (struct TestSacsStruct) { "
    "    .value = \"\",    "
    "  };                        ";   
  
    struct struct_test_sacs_parse_chars test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_chars, &test_struct, test_parse_chars_string);
    assert(parse_result == strlen(test_parse_chars_string));
  
    assert(0 == strcmp(expect, test_struct.value));
  }
  
  
  // Test array
  {
    const char expect[] = {'h', 'i', '\0'};
    
    const char test_parse_chars_string[] = 
    "  (struct TestSacsStruct) {           "
    "    .value = {'h', 'i', '\\0'},  "
    "  };                                  ";   
    
    struct struct_test_sacs_parse_chars test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_chars, &test_struct, test_parse_chars_string);
    
    size_t expect_parse_result = strlen(test_parse_chars_string);
    assert(expect_parse_result == parse_result);
    
    assert(0 == strcmp(expect, test_struct.value));
  }  
  
  
  // Test escape characters
  {
    char expect[] = "\a\b\f\n\r\t\v\'\?";
    
    const char test_parse_chars_string[] = 
    "  (struct TestSacsStruct) {                   "
    "    .value = \"\a\b\f\n\r\t\v\'\?\",    "
    "  };                                          ";   
    
    struct struct_test_sacs_parse_chars test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_chars, &test_struct, test_parse_chars_string);
    
    size_t expect_parse_result = strlen(test_parse_chars_string);
    assert(expect_parse_result == parse_result);
    
    assert(0 == strcmp(expect, test_struct.value));
  }  
  
  
  // Test escape characters
  {
    char expect[] = "\x31\x32";
    
    const char test_parse_chars_string[] = 
    "  (struct TestSacsStruct) {           "
    "    .value = \"\x31\x32\",      "
    "  };                                  ";   
    
    struct struct_test_sacs_parse_chars test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_chars, &test_struct, test_parse_chars_string);
    
    size_t expect_parse_result = strlen(test_parse_chars_string);
    assert(expect_parse_result == parse_result);
    
    assert(0 == strcmp(expect, test_struct.value));
  }  
  
  
  // Test missing value
  {
    const char test_parse_chars_string[] = 
    "  (struct TestSacsStruct) { "
    "    .value =,         "
    "  };                        ";   

    struct struct_test_sacs_parse_chars test_struct = {0};

    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_chars, &test_struct, test_parse_chars_string);
    assert(parse_result == 0);
  }
  
  
  // Test number
  {
    const char test_parse_chars_string[] = 
    "  (struct TestSacsStruct) { "
    "    .value = 1,       "
    "  };                        ";   
  
    struct struct_test_sacs_parse_chars test_struct = {0};
  
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_chars, &test_struct, test_parse_chars_string);
    assert(parse_result == 0);
  }
}






#include "struct_test_sacs_parse_double.h"


static void test_sacs_parse_double(void)
{
  printf("%s\n", __FUNCTION__);
 
  
  // Test 0.0
  {
    double expect = 0.0;
    
    const char test_parse_double_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 0.0,            "
    "  };                         ";   
    
    struct struct_test_sacs_parse_double test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_double, &test_struct, test_parse_double_string);
    assert(parse_result == strlen(test_parse_double_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 1.0
  {
    double expect = 1.0;
    
    const char test_parse_double_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 1.0,            "
    "  };                         ";   
    
    struct struct_test_sacs_parse_double test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_double, &test_struct, test_parse_double_string);
    assert(parse_result == strlen(test_parse_double_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 0.12345
  {
    double expect = 0.12345;
    
    const char test_parse_double_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 0.12345,        "
    "  };                         ";   
    
    struct struct_test_sacs_parse_double test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_double, &test_struct, test_parse_double_string);
    assert(parse_result == strlen(test_parse_double_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 9E3
  {
    double expect = 9E3;
    
    const char test_parse_double_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 9E3,            "
    "  };                         ";   
    
    struct struct_test_sacs_parse_double test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_double, &test_struct, test_parse_double_string);
    assert(parse_result == strlen(test_parse_double_string));
    
    assert(expect == test_struct.value);
  }
  
  // Test 1
  {
    double expect = 1;
    
    const char test_parse_double_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 1,          "
    "  };                         ";   
    
    struct struct_test_sacs_parse_double test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_double, &test_struct, test_parse_double_string);
    assert(parse_result == strlen(test_parse_double_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 01
  {
    double expect = 01;
    
    const char test_parse_double_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 01,         "
    "  };                         ";   
    
    struct struct_test_sacs_parse_double test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_double, &test_struct, test_parse_double_string);
    assert(parse_result == strlen(test_parse_double_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 'a'
  {
    double expect = 'a';
    
    const char test_parse_double_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 'a',        "
    "  };                         ";   
    
    struct struct_test_sacs_parse_double test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_double, &test_struct, test_parse_double_string);
    assert(parse_result == strlen(test_parse_double_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 0x1
  {
    double expect = 0x1;
    
    const char test_parse_double_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 0x1,        "
    "  };                         ";   
    
    struct struct_test_sacs_parse_double test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_double, &test_struct, test_parse_double_string);
    assert(parse_result == strlen(test_parse_double_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 0xABCDEF
  {
    double expect = 0xABCDEF;
    
    const char test_parse_double_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 0xABCDEF,   "
    "  };                         ";   
    
    struct struct_test_sacs_parse_double test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_double, &test_struct, test_parse_double_string);
    assert(parse_result == strlen(test_parse_double_string));
    
    assert(expect == test_struct.value);
  }
  
}







#include "struct_test_sacs_parse_int.h"


static void test_sacs_parse_int(void)
{
  printf("%s\n", __FUNCTION__);
  
  
  // Test 0
  {
    int expect = 0;
    
    const char test_parse_int_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 0,          "
    "  };                         ";   

    struct struct_test_sacs_parse_int test_struct = {0};

    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_int, &test_struct, test_parse_int_string);
    assert(parse_result == strlen(test_parse_int_string));
  
    assert(expect == test_struct.value);
  }
  
  
  // Test 1
  {
    int expect = 1;
    
    const char test_parse_int_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 1,          "
    "  };                         ";   
    
    struct struct_test_sacs_parse_int test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_int, &test_struct, test_parse_int_string);
    assert(parse_result == strlen(test_parse_int_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 01
  {
    int expect = 01;
    
    const char test_parse_int_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 01,         "
    "  };                         ";   
    
    struct struct_test_sacs_parse_int test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_int, &test_struct, test_parse_int_string);
    assert(parse_result == strlen(test_parse_int_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 'a'
  {
    int expect = 'a';
    
    const char test_parse_int_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 'a',        "
    "  };                         ";   
    
    struct struct_test_sacs_parse_int test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_int, &test_struct, test_parse_int_string);
    assert(parse_result == strlen(test_parse_int_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 0x1
  {
    int expect = 0x1;
    
    const char test_parse_int_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 0x1,        "
    "  };                         ";   
    
    struct struct_test_sacs_parse_int test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_int, &test_struct, test_parse_int_string);
    assert(parse_result == strlen(test_parse_int_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 0xABCDEF
  {
    int expect = 0xABCDEF;
    
    const char test_parse_int_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 0xABCDEF,   "
    "  };                         ";   
    
    struct struct_test_sacs_parse_int test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_int, &test_struct, test_parse_int_string);
    assert(parse_result == strlen(test_parse_int_string));
    
    assert(expect == test_struct.value);
  }
  
}




#include "struct_test_sacs_parse_int_array.h"


static void test_sacs_parse_int_array(void)
{
  printf("%s\n", __FUNCTION__);
  
  // Test typical array
  {
    const int expect[] = {1, 2, 3};
    
    const char test_parse_int_array_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = {1, 2, 3},      "
    "  };                         ";   
    
    struct struct_test_sacs_parse_int_array test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_int_array, &test_struct, test_parse_int_array_string);
    assert(parse_result == strlen(test_parse_int_array_string));
    
    assert(0 == memcmp(expect, test_struct.value, sizeof(expect)));
  }
  
  // Test zero initialization
  {
    const char expect[] = {0};
    
    const char test_parse_int_array_string[] = 
    "  (struct TestSacsStruct) { "
    "    .value = {0},           "
    "  };                        ";   
    
    struct struct_test_sacs_parse_int_array test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_int_array, &test_struct, test_parse_int_array_string);
    assert(parse_result == strlen(test_parse_int_array_string));
    
    assert(0 == memcmp(expect, test_struct.value, sizeof(expect)));
  }
  
  
  // Test array
  {
    const int expect[] = {'h', 'i', '\0'};
    
    const char test_parse_int_array_string[] = 
    "  (struct TestSacsStruct) {           "
    "    .value = {'h', 'i', '\\0'},  "
    "  };                                  ";   
    
    struct struct_test_sacs_parse_int_array test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_int_array, &test_struct, test_parse_int_array_string);
    
    size_t expect_parse_result = strlen(test_parse_int_array_string);
    assert(expect_parse_result == parse_result);
    
    assert(0 == memcmp(expect, test_struct.value, sizeof(expect)));
  }
  
  
  // Test array
  {
    const int expect[] = {0x01, 0x02, 0x03};
    
    const char test_parse_int_array_string[] = 
    "  (struct TestSacsStruct) {       "
    "    .value = {0x01, 0x02, 0x03},  "
    "  };                              ";   
    
    struct struct_test_sacs_parse_int_array test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_int_array, &test_struct, test_parse_int_array_string);
    
    size_t expect_parse_result = strlen(test_parse_int_array_string);
    assert(expect_parse_result == parse_result);
    
    assert(0 == memcmp(expect, test_struct.value, sizeof(expect)));
  }
}




#include "struct_test_sacs_parse_unsigned_int.h"


static void test_sacs_parse_unsigned_int(void)
{
  printf("%s\n", __FUNCTION__);
  
  
  // Test 0
  {
    unsigned int expect = 0;
    
    const char test_parse_unsigned_int_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 0,          "
    "  };                         ";   
    
    struct struct_test_sacs_parse_unsigned_int test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_unsigned_int, &test_struct, test_parse_unsigned_int_string);
    assert(parse_result == strlen(test_parse_unsigned_int_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 1
  {
    unsigned int expect = 1;
    
    const char test_parse_unsigned_int_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 1,          "
    "  };                         ";   
    
    struct struct_test_sacs_parse_unsigned_int test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_unsigned_int, &test_struct, test_parse_unsigned_int_string);
    assert(parse_result == strlen(test_parse_unsigned_int_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 01
  {
    unsigned int expect = 01;
    
    const char test_parse_unsigned_int_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 01,         "
    "  };                         ";   
    
    struct struct_test_sacs_parse_unsigned_int test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_unsigned_int, &test_struct, test_parse_unsigned_int_string);
    assert(parse_result == strlen(test_parse_unsigned_int_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 'a'
  {
    unsigned int expect = 'a';
    
    const char test_parse_unsigned_int_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 'a',        "
    "  };                         ";   
    
    struct struct_test_sacs_parse_unsigned_int test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_unsigned_int, &test_struct, test_parse_unsigned_int_string);
    assert(parse_result == strlen(test_parse_unsigned_int_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 0x1
  {
    unsigned int expect = 0x1;
    
    const char test_parse_unsigned_int_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 0x1,        "
    "  };                         ";   
    
    struct struct_test_sacs_parse_unsigned_int test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_unsigned_int, &test_struct, test_parse_unsigned_int_string);
    assert(parse_result == strlen(test_parse_unsigned_int_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 0xABCDEF
  {
    unsigned int expect = 0xABCDEF;
    
    const char test_parse_unsigned_int_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 0xABCDEF,   "
    "  };                         ";   
    
    struct struct_test_sacs_parse_unsigned_int test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_unsigned_int, &test_struct, test_parse_unsigned_int_string);
    assert(parse_result == strlen(test_parse_unsigned_int_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 0b1
  {
    unsigned int expect = 1;  // Note, C does not support 0b prefix
    
    const char test_parse_unsigned_int_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 0b1,        "
    "  };                         ";   
    
    struct struct_test_sacs_parse_unsigned_int test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_unsigned_int, &test_struct, test_parse_unsigned_int_string);
    assert(parse_result == strlen(test_parse_unsigned_int_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 0b01
  {
    unsigned int expect = 1;  // Note, C does not support 0b prefix
    
    const char test_parse_unsigned_int_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 0b01,        "
    "  };                         ";   
    
    struct struct_test_sacs_parse_unsigned_int test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_unsigned_int, &test_struct, test_parse_unsigned_int_string);
    assert(parse_result == strlen(test_parse_unsigned_int_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 0b101
  {
    unsigned int expect = 5;  // Note, C does not support 0b prefix
    
    const char test_parse_unsigned_int_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 0b101,        "
    "  };                         ";   
    
    struct struct_test_sacs_parse_unsigned_int test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_unsigned_int, &test_struct, test_parse_unsigned_int_string);
    assert(parse_result == strlen(test_parse_unsigned_int_string));
    
    assert(expect == test_struct.value);
  }  
  
}



#include "struct_test_sacs_parse_unsigned_long.h"


static void test_sacs_parse_unsigned_long(void)
{
  printf("%s\n", __FUNCTION__);
  
  
  // Test 0
  {
    unsigned long expect = 0;
    
    const char test_parse_unsigned_long_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 0,          "
    "  };                         ";   
    
    struct struct_test_sacs_parse_unsigned_long test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_unsigned_long, &test_struct, test_parse_unsigned_long_string);
    assert(parse_result == strlen(test_parse_unsigned_long_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 1
  {
    unsigned long expect = 1;
    
    const char test_parse_unsigned_long_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 1,          "
    "  };                         ";   
    
    struct struct_test_sacs_parse_unsigned_long test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_unsigned_long, &test_struct, test_parse_unsigned_long_string);
    assert(parse_result == strlen(test_parse_unsigned_long_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 01
  {
    unsigned long expect = 01;
    
    const char test_parse_unsigned_long_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 01,         "
    "  };                         ";   
    
    struct struct_test_sacs_parse_unsigned_long test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_unsigned_long, &test_struct, test_parse_unsigned_long_string);
    assert(parse_result == strlen(test_parse_unsigned_long_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 'a'
  {
    unsigned long expect = 'a';
    
    const char test_parse_unsigned_long_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 'a',        "
    "  };                         ";   
    
    struct struct_test_sacs_parse_unsigned_long test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_unsigned_long, &test_struct, test_parse_unsigned_long_string);
    assert(parse_result == strlen(test_parse_unsigned_long_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 0x1
  {
    unsigned long expect = 0x1;
    
    const char test_parse_unsigned_long_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 0x1,        "
    "  };                         ";   
    
    struct struct_test_sacs_parse_unsigned_long test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_unsigned_long, &test_struct, test_parse_unsigned_long_string);
    assert(parse_result == strlen(test_parse_unsigned_long_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 0xABCDEF
  {
    unsigned long expect = 0xABCDEF;
    
    const char test_parse_unsigned_long_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 0xABCDEF,   "
    "  };                         ";   
    
    struct struct_test_sacs_parse_unsigned_long test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_unsigned_long, &test_struct, test_parse_unsigned_long_string);
    assert(parse_result == strlen(test_parse_unsigned_long_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 0b1
  {
    unsigned long expect = 1;  // Note, C does not support 0b prefix
    
    const char test_parse_unsigned_long_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 0b1,        "
    "  };                         ";   
    
    struct struct_test_sacs_parse_unsigned_long test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_unsigned_long, &test_struct, test_parse_unsigned_long_string);
    assert(parse_result == strlen(test_parse_unsigned_long_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 0b01
  {
    unsigned long expect = 1;  // Note, C does not support 0b prefix
    
    const char test_parse_unsigned_long_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 0b01,        "
    "  };                         ";   
    
    struct struct_test_sacs_parse_unsigned_long test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_unsigned_long, &test_struct, test_parse_unsigned_long_string);
    assert(parse_result == strlen(test_parse_unsigned_long_string));
    
    assert(expect == test_struct.value);
  }
  
  
  // Test 0b101
  {
    unsigned long expect = 5;  // Note, C does not support 0b prefix
    
    const char test_parse_unsigned_long_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .value = 0b101,        "
    "  };                         ";   
    
    struct struct_test_sacs_parse_unsigned_long test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_unsigned_long, &test_struct, test_parse_unsigned_long_string);
    assert(parse_result == strlen(test_parse_unsigned_long_string));
    
    assert(expect == test_struct.value);
  }  
  
}







void test_sacs_parse(void)
{
  test_sacs_parse_bool();
  test_sacs_parse_char();
  test_sacs_parse_chars();
  test_sacs_parse_double();
  test_sacs_parse_int();
  test_sacs_parse_int_array();
  test_sacs_parse_unsigned_int();
  test_sacs_parse_unsigned_long();
}


