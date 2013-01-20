

#include <stdio.h>

#include "test_sacs_parse.h"

#include "../src/sacs.h"
#include "../src/sacs.c"




#include "struct_test_sacs_parse_bool.h"


static void test_sacs_parse_bool(void)
{
  printf("%s\n", __FUNCTION__);
  
  
  // Test true
  {
    const bool expect = true;
    
    const char test_parse_bool_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .bool_value = true,      "
    "  };                         ";   

    struct struct_test_sacs_parse_bool test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_bool, &test_struct, test_parse_bool_string);
    assert(parse_result == strlen(test_parse_bool_string));

    assert(expect == test_struct.bool_value);
  }
  
  
  // Test false
  {
    const bool expect = false;
    
    const char test_parse_bool_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .bool_value = false,     "
    "  };                         "; 

    struct struct_test_sacs_parse_bool test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_bool, &test_struct, test_parse_bool_string);
    assert(parse_result == strlen(test_parse_bool_string));
  
    assert(expect == test_struct.bool_value);
  }
  
  
  // Test 0
  {
    const bool expect = 0;
    
    const char test_parse_bool_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .bool_value = 0,         "
    "  };                         "; 

    struct struct_test_sacs_parse_bool test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_bool, &test_struct, test_parse_bool_string);
    assert(parse_result == strlen(test_parse_bool_string));
  
    assert(expect == test_struct.bool_value);
  }
  
  
  // Test 1
  {
    const bool expect = 1;
    
    const char test_parse_bool_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .bool_value = 1,         "
    "  };                         "; 
  
    struct struct_test_sacs_parse_bool test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_bool, &test_struct, test_parse_bool_string);
    assert(parse_result == strlen(test_parse_bool_string));
  
    assert(expect == test_struct.bool_value);  
  }
  
  
  // Test 2
  {
    const bool expect = 2;
    
    const char test_parse_bool_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .bool_value = 2,         "
    "  };                         "; 
  
    struct struct_test_sacs_parse_bool test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_bool, &test_struct, test_parse_bool_string);
    assert(parse_result == strlen(test_parse_bool_string));
  
    assert(expect == test_struct.bool_value);
  }

  
  // Test 01
  {
    const bool expect = 2;
    
    const char test_parse_bool_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .bool_value = 01,        "
    "  };                         "; 

    struct struct_test_sacs_parse_bool test_struct = {0};    
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_bool, &test_struct, test_parse_bool_string);
    assert(parse_result == strlen(test_parse_bool_string));
  
    assert(expect == test_struct.bool_value);  
  }
  
  
  // Test missing field
  {
    const char test_parse_bool_string[] = 
    "  (struct TestSacsStruct) {  "
    "  };                         "; 
  
    struct struct_test_sacs_parse_bool test_struct = {0};    
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_bool, &test_struct, test_parse_bool_string);
    assert(parse_result == strlen(test_parse_bool_string));
  
    assert(false == test_struct.bool_value);  
  }
  
  // Test invalid string
  {
    const char test_parse_bool_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .bool_value =,           "
    "  };                         "; 

    struct struct_test_sacs_parse_bool test_struct = {0};    
  
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_bool, &test_struct, test_parse_bool_string);
    assert(parse_result == strlen(test_parse_bool_string));
  
    assert(false == test_struct.bool_value);  
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
    "    .char_value = 'a',       "
    "  };                         "; 
    
    struct struct_test_sacs_parse_char test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_char, &test_struct, test_parse_char_string);
    assert(parse_result == strlen(test_parse_char_string));
    
    assert(expect == test_struct.char_value);  
  }  
  
  
  // Test '\0'
  {
    const char expect = '\0';
    
    const char test_parse_char_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .char_value = '\\0',     "
    "  };                         "; 
    
    struct struct_test_sacs_parse_char test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_char, &test_struct, test_parse_char_string);
    assert(parse_result == strlen(test_parse_char_string));
    
    assert(expect == test_struct.char_value);  
  } 

  
  // Test 0
  {
    const char expect = 0;
    
    const char test_parse_char_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .char_value = 0,         "
    "  };                         ";   
  
    struct struct_test_sacs_parse_char test_struct = {0};
  
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_char, &test_struct, test_parse_char_string);
    assert(parse_result == strlen(test_parse_char_string));
  
    assert(expect == test_struct.char_value);
  }
  
  
  // Test 0x31
  {
    const char expect = 0x31;
    
    const char test_parse_char_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .char_value = 0x31,      "
    "  };                         ";   
    
    struct struct_test_sacs_parse_char test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_char, &test_struct, test_parse_char_string);
    assert(parse_result == strlen(test_parse_char_string));
    
    assert(expect == test_struct.char_value);
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
    "    .chars_value = \"Hello World\", "
    "  };                                ";   
    
    struct struct_test_sacs_parse_chars test_struct = {0};
  
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_chars, &test_struct, test_parse_chars_string);
    assert(parse_result == strlen(test_parse_chars_string));
  
    assert(0 == strcmp(expect, test_struct.chars_value));
  }
  
  // Test empty string
  {
    const char expect[] = "";
    
    const char test_parse_chars_string[] = 
    "  (struct TestSacsStruct) { "
    "    .chars_value = \"\",    "
    "  };                        ";   
  
    struct struct_test_sacs_parse_chars test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_chars, &test_struct, test_parse_chars_string);
    assert(parse_result == strlen(test_parse_chars_string));
  
    assert(0 == strcmp(expect, test_struct.chars_value));
  }
  
  
  // Test array
  {
    const char expect[] = {'h', 'i', '\0'};
    
    const char test_parse_chars_string[] = 
    "  (struct TestSacsStruct) {           "
    "    .chars_value = {'h', 'i', '\\0'},  "
    "  };                                  ";   
    
    struct struct_test_sacs_parse_chars test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_chars, &test_struct, test_parse_chars_string);
    
    size_t expect_parse_result = strlen(test_parse_chars_string);
    assert(expect_parse_result == parse_result);
    
    assert(0 == strcmp(expect, test_struct.chars_value));
  }  
  
  
  // Test escape characters
  {
    char expect[] = "\a\b\f\n\r\t\v\'\?";
    
    const char test_parse_chars_string[] = 
    "  (struct TestSacsStruct) {                   "
    "    .chars_value = \"\a\b\f\n\r\t\v\'\?\",    "
    "  };                                          ";   
    
    struct struct_test_sacs_parse_chars test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_chars, &test_struct, test_parse_chars_string);
    
    size_t expect_parse_result = strlen(test_parse_chars_string);
    assert(expect_parse_result == parse_result);
    
    assert(0 == strcmp(expect, test_struct.chars_value));
  }  
  
  
  // Test escape characters
  {
    char expect[] = "\x31\x32";
    
    const char test_parse_chars_string[] = 
    "  (struct TestSacsStruct) {           "
    "    .chars_value = \"\x31\x32\",      "
    "  };                                  ";   
    
    struct struct_test_sacs_parse_chars test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_chars, &test_struct, test_parse_chars_string);
    
    size_t expect_parse_result = strlen(test_parse_chars_string);
    assert(expect_parse_result == parse_result);
    
    assert(0 == strcmp(expect, test_struct.chars_value));
  }  
  
  
  // Test missing value
  {
    const char test_parse_chars_string[] = 
    "  (struct TestSacsStruct) { "
    "    .chars_value =,         "
    "  };                        ";   

    struct struct_test_sacs_parse_chars test_struct = {0};

    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_chars, &test_struct, test_parse_chars_string);
    assert(parse_result == 0);
  }
  
  
  // Test number
  {
    const char test_parse_chars_string[] = 
    "  (struct TestSacsStruct) { "
    "    .chars_value = 1,       "
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
  
  
  // Test 0
  {
    double expect = 0;
    
    const char test_parse_double_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .double_value = 0,          "
    "  };                         ";   
    
    struct struct_test_sacs_parse_double test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_double, &test_struct, test_parse_double_string);
    assert(parse_result == strlen(test_parse_double_string));
    
    assert(expect == test_struct.double_value);
  }
  
  
  // Test 1
  {
    double expect = 1;
    
    const char test_parse_double_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .double_value = 1,          "
    "  };                         ";   
    
    struct struct_test_sacs_parse_double test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_double, &test_struct, test_parse_double_string);
    assert(parse_result == strlen(test_parse_double_string));
    
    assert(expect == test_struct.double_value);
  }
  
  
  // Test 01
  {
    double expect = 01;
    
    const char test_parse_double_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .double_value = 01,         "
    "  };                         ";   
    
    struct struct_test_sacs_parse_double test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_double, &test_struct, test_parse_double_string);
    assert(parse_result == strlen(test_parse_double_string));
    
    assert(expect == test_struct.double_value);
  }
  
  
  // Test 'a'
  {
    double expect = 'a';
    
    const char test_parse_double_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .double_value = 'a',        "
    "  };                         ";   
    
    struct struct_test_sacs_parse_double test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_double, &test_struct, test_parse_double_string);
    assert(parse_result == strlen(test_parse_double_string));
    
    assert(expect == test_struct.double_value);
  }
  
  
  // Test 0x1
  {
    double expect = 0x1;
    
    const char test_parse_double_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .double_value = 0x1,        "
    "  };                         ";   
    
    struct struct_test_sacs_parse_double test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_double, &test_struct, test_parse_double_string);
    assert(parse_result == strlen(test_parse_double_string));
    
    assert(expect == test_struct.double_value);
  }
  
  
  // Test 0xABCDEF
  {
    double expect = 0xABCDEF;
    
    const char test_parse_double_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .double_value = 0xABCDEF,   "
    "  };                         ";   
    
    struct struct_test_sacs_parse_double test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_double, &test_struct, test_parse_double_string);
    assert(parse_result == strlen(test_parse_double_string));
    
    assert(expect == test_struct.double_value);
  }
  
  
  // Test 0b1
  {
    double expect = 1;  // Note, C does not support 0b prefix
    
    const char test_parse_double_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .double_value = 0b1,        "
    "  };                         ";   
    
    struct struct_test_sacs_parse_double test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_double, &test_struct, test_parse_double_string);
    assert(parse_result == strlen(test_parse_double_string));
    
    assert(expect == test_struct.double_value);
  }
  
  
  // Test 0b01
  {
    double expect = 1;  // Note, C does not support 0b prefix
    
    const char test_parse_double_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .double_value = 0b01,        "
    "  };                         ";   
    
    struct struct_test_sacs_parse_double test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_double, &test_struct, test_parse_double_string);
    assert(parse_result == strlen(test_parse_double_string));
    
    assert(expect == test_struct.double_value);
  }
  
  
  // Test 0b101
  {
    double expect = 5;  // Note, C does not support 0b prefix
    
    const char test_parse_double_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .double_value = 0b101,        "
    "  };                         ";   
    
    struct struct_test_sacs_parse_double test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_double, &test_struct, test_parse_double_string);
    assert(parse_result == strlen(test_parse_double_string));
    
    assert(expect == test_struct.double_value);
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
    "    .int_value = 0,          "
    "  };                         ";   

    struct struct_test_sacs_parse_int test_struct = {0};

    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_int, &test_struct, test_parse_int_string);
    assert(parse_result == strlen(test_parse_int_string));
  
    assert(expect == test_struct.int_value);
  }
  
  
  // Test 1
  {
    int expect = 1;
    
    const char test_parse_int_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .int_value = 1,          "
    "  };                         ";   
    
    struct struct_test_sacs_parse_int test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_int, &test_struct, test_parse_int_string);
    assert(parse_result == strlen(test_parse_int_string));
    
    assert(expect == test_struct.int_value);
  }
  
  
  // Test 01
  {
    int expect = 01;
    
    const char test_parse_int_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .int_value = 01,         "
    "  };                         ";   
    
    struct struct_test_sacs_parse_int test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_int, &test_struct, test_parse_int_string);
    assert(parse_result == strlen(test_parse_int_string));
    
    assert(expect == test_struct.int_value);
  }
  
  
  // Test 'a'
  {
    int expect = 'a';
    
    const char test_parse_int_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .int_value = 'a',        "
    "  };                         ";   
    
    struct struct_test_sacs_parse_int test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_int, &test_struct, test_parse_int_string);
    assert(parse_result == strlen(test_parse_int_string));
    
    assert(expect == test_struct.int_value);
  }
  
  
  // Test 0x1
  {
    int expect = 0x1;
    
    const char test_parse_int_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .int_value = 0x1,        "
    "  };                         ";   
    
    struct struct_test_sacs_parse_int test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_int, &test_struct, test_parse_int_string);
    assert(parse_result == strlen(test_parse_int_string));
    
    assert(expect == test_struct.int_value);
  }
  
  
  // Test 0xABCDEF
  {
    int expect = 0xABCDEF;
    
    const char test_parse_int_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .int_value = 0xABCDEF,   "
    "  };                         ";   
    
    struct struct_test_sacs_parse_int test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_int, &test_struct, test_parse_int_string);
    assert(parse_result == strlen(test_parse_int_string));
    
    assert(expect == test_struct.int_value);
  }
  
  
  // Test 0b1
  {
    int expect = 1;  // Note, C does not support 0b prefix
    
    const char test_parse_int_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .int_value = 0b1,        "
    "  };                         ";   
    
    struct struct_test_sacs_parse_int test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_int, &test_struct, test_parse_int_string);
    assert(parse_result == strlen(test_parse_int_string));
    
    assert(expect == test_struct.int_value);
  }
  
  
  // Test 0b01
  {
    int expect = 1;  // Note, C does not support 0b prefix
    
    const char test_parse_int_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .int_value = 0b01,        "
    "  };                         ";   
    
    struct struct_test_sacs_parse_int test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_int, &test_struct, test_parse_int_string);
    assert(parse_result == strlen(test_parse_int_string));
    
    assert(expect == test_struct.int_value);
  }
  
  
  // Test 0b101
  {
    int expect = 5;  // Note, C does not support 0b prefix
    
    const char test_parse_int_string[] = 
    "  (struct TestSacsStruct) {  "
    "    .int_value = 0b101,        "
    "  };                         ";   
    
    struct struct_test_sacs_parse_int test_struct = {0};
    
    const size_t parse_result = SACS_PARSE_TYPE(struct_test_sacs_parse_int, &test_struct, test_parse_int_string);
    assert(parse_result == strlen(test_parse_int_string));
    
    assert(expect == test_struct.int_value);
  }  

}









void test_sacs_parse(void)
{
  test_sacs_parse_bool();
  test_sacs_parse_char();
  test_sacs_parse_chars();
  test_sacs_parse_int();
}


