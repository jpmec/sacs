/** sacs_parse.h
 
 Author: Joshua Petitt
 Available at: https://github.com/jpmec/sacs
 
 
 Copyright (c) 2012 Joshua Petitt
 Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
 to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
 and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
*/


#ifndef SACS_PARSE_H
#define SACS_PARSE_H


#include "sacs_const.h"
#include "sacs_format.h"



#define SACS_PARSE_FIELD(_type_name_, _field_name_, _function_, _field_size_) \
  {offsetof(struct _type_name_, _field_name_), #_field_name_, _function_, _field_size_}

#define SACS_PARSE_BOOL(_type_name_, _field_name_) \
  SACS_PARSE_FIELD(_type_name_, _field_name_, sacs_parse_bool, sizeof(bool))

#define SACS_PARSE_CHAR(_type_name_, _field_name_) \
  SACS_PARSE_FIELD(_type_name_, _field_name_, sacs_parse_char, sizeof(char))

#define SACS_PARSE_INT(_type_name_, _field_name_) \
  SACS_PARSE_FIELD(_type_name_, _field_name_, sacs_parse_int, sizeof(int))

#define SACS_PARSE_INT_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_PARSE_FIELD(_type_name_, _field_name_, sacs_parse_int_array, _size_ * sizeof(int))

#define SACS_PARSE_LONG(_type_name_, _field_name_) \
  SACS_PARSE_FIELD(_type_name_, _field_name_, sacs_parse_long, sizeof(long))

#define SACS_PARSE_LONG_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_PARSE_FIELD(_type_name_, _field_name_, sacs_parse_long_array, _size_ * sizeof(long))

#define SACS_PARSE_UNSIGNED_INT(_type_name_, _field_name_) \
  SACS_PARSE_FIELD(_type_name_, _field_name_, sacs_parse_unsigned_int, sizeof(unsigned int))

#define SACS_PARSE_UNSIGNED_INT_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_PARSE_FIELD(_type_name_, _field_name_, sacs_parse_unsigned_int_array, _size_ * sizeof(unsigned int))

#define SACS_PARSE_UNSIGNED_LONG(_type_name_, _field_name_) \
  SACS_PARSE_FIELD(_type_name_, _field_name_, sacs_parse_unsigned_long, sizeof(unsigned long))

#define SACS_PARSE_UNSIGNED_LONG_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_PARSE_FIELD(_type_name_, _field_name_, sacs_parse_unsigned_long_array, _size_ * sizeof(unsigned long))

#define SACS_PARSE_DOUBLE(_type_name_, _field_name_) \
  SACS_PARSE_FIELD(_type_name_, _field_name_, sacs_parse_double, sizeof(double))

#define SACS_PARSE_DOUBLE_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_PARSE_FIELD(_type_name_, _field_name_, sacs_parse_double_array, _size_ * sizeof(double))

#define SACS_PARSE_FLOAT(_type_name_, _field_name_) \
SACS_PARSE_FIELD(_type_name_, _field_name_, sacs_parse_float, sizeof(float))

#define SACS_PARSE_FLOAT_ARRAY(_type_name_, _field_name_, _size_) \
SACS_PARSE_FIELD(_type_name_, _field_name_, sacs_parse_float_array, _size_ * sizeof(float))

#define SACS_PARSE_CHAR_STRING(_type_name_, _field_name_, _size_) \
  SACS_PARSE_FIELD(_type_name_, _field_name_, sacs_parse_char_string, _size_ * sizeof(char))

#define SACS_PARSE_ENUM(_type_name_, _enum_name_, _field_name_) \
  SACS_PARSE_FIELD(_type_name_, _field_name_, sacs_parse_enum, sizeof(enum _enum_name_))

#define SACS_PARSE_STRUCT(_type_name_, _struct_name_, _field_name_) \
  SACS_PARSE_FIELD(_type_name_, _field_name_, _struct_name_##_sacs_parse_struct, sizeof(struct _struct_name_))

#define SACS_PARSE_STRUCT_ARRAY(_type_name_, _struct_name_, _field_name_, _size_) \
  SACS_PARSE_FIELD(_type_name_, _field_name_, _struct_name_##_sacs_parse_struct_array, _size_ * sizeof(struct _struct_name_))

#define SACS_PARSE_UINT8(_type_name_, _field_name_) \
  SACS_PARSE_FIELD(_type_name_, _field_name_, sacs_parse_uint8, sizeof(uint8_t))

#define SACS_PARSE_UINT8_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_PARSE_FIELD(_type_name_, _field_name_, sacs_parse_uint8_array, _size_ * sizeof(uint8_t))

#define SACS_PARSE_UINT16(_type_name_, _field_name_) \
  SACS_PARSE_FIELD(_type_name_, _field_name_, sacs_parse_uint16, sizeof(uint16_t))

#define SACS_PARSE_UINT16_ARRAY(_type_name_, _field_name_, _size_) \
 SACS_PARSE_FIELD(_type_name_, _field_name_, sacs_parse_uint16, _size_ * sizeof(uint16_t))

#define SACS_PARSE_UINT32(_type_name_, _field_name_) \
  SACS_PARSE_FIELD(_type_name_, _field_name_, sacs_parse_uint32, sizeof(uint32_t))

#define SACS_PARSE_UINT32_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_PARSE_FIELD(_type_name_, _field_name_, sacs_parse_uint32_array, _size_* sizeof(uint32_t))

#define SACS_PARSE_INT32(_type_name_, _field_name_) \
  SACS_PARSE_FIELD(_type_name_, _field_name_, sacs_parse_int32, sizeof(int32_t))

#define SACS_PARSE_INT32_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_PARSE_FIELD(_type_name_, _field_name_, sacs_parse_int32_array, _size_ * sizeof(int32_t))

#define SACS_FIELD_PARSER_ARRAY(_type_name_) \
  const struct SacsFieldParser _type_name_##_sacs_field_parsers[] =




#define SACS_STRUCT_PARSER(_type_name_, _dest_) \
  struct SacsStructParser _type_name_##_sacs_parser = \
  { \
    .name = #_type_name_, \
    .dest = _dest_, \
    .dest_size = sizeof(struct _type_name_), \
    .parsers_array = _type_name_##_sacs_field_parsers, \
    .parsers_count = (sizeof(_type_name_##_sacs_field_parsers) / sizeof(struct SacsFieldParser)), \
    .format = { \
      .char_field_value_separator = SACS_CHAR_FIELD_VALUE_SEPARATOR, \
      .char_field_separator = SACS_CHAR_FIELD_SEPARATOR, \
      .char_struct_begin = SACS_CHAR_STRUCT_BEGIN, \
      .char_struct_end = SACS_CHAR_STRUCT_END, \
      .char_array_end = SACS_CHAR_ARRAY_END, \
      .input = { \
        .char_array_begin = SACS_CHAR_ARRAY_BEGIN, \
      }, \
      .output = { \
        .str_array_begin = SACS_STR_ARRAY_BEGIN, \
      }, \
    }, \
  };


#define SACS_ARRAY_PARSER(_type_name_, _dest_) \
  struct SacsArrayParser _type_name_##_sacs_parser = \
  { \
    .name = #_type_name_, \
    .dest = _dest_, \
    .dest_size = sizeof(struct _type_name_), \
    .parsers_array = _type_name_##_sacs_field_parsers, \
    .parsers_count = 1, \
    .format = { \
      .char_field_value_separator = SACS_CHAR_FIELD_VALUE_SEPARATOR, \
      .char_field_separator = SACS_CHAR_FIELD_SEPARATOR, \
      .char_struct_begin = SACS_CHAR_STRUCT_BEGIN, \
      .char_struct_end = SACS_CHAR_STRUCT_END, \
      .char_array_begin = SACS_CHAR_ARRAY_BEGIN, \
      .char_array_end = SACS_CHAR_ARRAY_END, \
    }, \
  };


#define SACS_PARSE_PARTIAL(_type_name_, _str_) \
  sacs_partial(&_type_name_##_sacs_parser, _str_)


#define SACS_PARSABLE(_type_name_) \
  size_t _type_name_##_sacs_parse_struct(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str); \
  size_t _type_name_##_sacs_parse_struct(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str) \
  { \
    SACS_STRUCT_PARSER(_type_name_, dest); \
    return sacs_parse(&_type_name_##_sacs_parser, str); \
  } \
  size_t _type_name_##_sacs_parse_struct_array(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str); \
  size_t _type_name_##_sacs_parse_struct_array(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str) \
  { \
    return sacs_parse_array(parser, dest, dest_size, str, sizeof(struct _type_name_), _type_name_##_sacs_parse_struct); \
  } \
  size_t _type_name_##_sacs_parse_type(void* dest, size_t dest_size, const char* str); \
  size_t _type_name_##_sacs_parse_type(void* dest, size_t dest_size, const char* str) \
  { \
    return _type_name_##_sacs_parse_struct(NULL, dest, dest_size , str); \
  }


#define SACS_PARSE_TYPE(_type_name_, _dest_, _str_) \
  _type_name_##_sacs_parse_type(_dest_, sizeof(struct _type_name_), _str_)


#define SACS_PARSE_ARRAY(_type_name_, _dest_, _dest_count_, _str_) 



struct SacsStructParser;
struct SacsFieldParser;
typedef size_t (*SacsParseFieldCallback_t)(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str);




struct SacsFieldParser
{
  size_t field_offset;
  const char* name;
  SacsParseFieldCallback_t function;
  size_t field_size;
};




//struct SacsStructFormat
//{
//  char char_field_value_separator;
//  char char_field_separator;
//  char char_struct_begin;
//  char char_struct_end; 
//  char char_array_begin;
//  char char_array_end; 
//};




enum SacsParseError
{
  SACS_PARSER_ERROR_NONE,
  SACS_PARSER_ERROR_BAD_FORMAT,
};




struct SacsStructParser
{
  const char* name;  
  const struct SacsFieldParser* parsers_array;  // Pointer to an array of parsers.
  size_t parsers_count;                         // Number of elements in the array of parsers.
	
  void* dest;
  size_t dest_size;
  
  struct SacsStructFormat format;
  
  enum SacsParseError error;
};




struct SacsArrayParser
{
  const struct SacsFieldParser* parsers_array;  // Pointer to an array of parsers.
  size_t parsers_count;                         // Number of elements in the array of parsers.
	
  void* dest;
  size_t dest_size;
  
  struct SacsStructFormat format;
  
  enum SacsParseError error;
};




/** Function to iterate over all elements in a string, calling the parse function for each.
 */
size_t sacs_parse_array(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str, size_t element_size, SacsParseFieldCallback_t parse_function);


/** Parse a string and convert to a C structure.
 *  The string must be formatted like a C initializer.
 *  All data in destination is set to 0 before processing the string.
 *  Returns number of characters parsed.
 */
size_t sacs_parse(struct SacsStructParser* parser, const char* str);


/** Parse a string and convert to a C structure.
 *  String may represent only a part of a complete initializer.
 *  Does not affect destination data that is not found in the string.
 */
size_t sacs_parse_partial(struct SacsStructParser* parser, const char* str);





#define DECLARE_SACS_PARSE_TYPE(_typename_) \
  size_t sacs_parse_##_typename_(struct SacsStructParser*, void* dest, size_t dest_size, const char* str)




/** Parse a boolean value.
 *  Returns number of chars parsed.
 */
DECLARE_SACS_PARSE_TYPE(bool);


/** Parse a single character.
 *  Returns number of chars parsed.
 */
DECLARE_SACS_PARSE_TYPE(char);


/** Parse an array of characters.
 *  Array is not required to be null-terminated.
 *  Returns number of chars parsed.
 */
DECLARE_SACS_PARSE_TYPE(char_array);


/** Parse a null-terminated string of characters.
 *  Returns number of chars parsed. 
 */
DECLARE_SACS_PARSE_TYPE(char_string);


/** Parse a double using strtod.
 *  Returns number of chars parsed. 
 */
DECLARE_SACS_PARSE_TYPE(double);


/** Parse an array of doubles using strtod.
 *  Returns number of chars parsed. 
 */
DECLARE_SACS_PARSE_TYPE(double_array);


/** Parse an enumeration.
 *  Returns number of chars parsed.
 */
DECLARE_SACS_PARSE_TYPE(enum);


/** Parse a float using atof.
 *  Returns number of chars parsed. 
 */
DECLARE_SACS_PARSE_TYPE(float);


/** Parse an array of floats using atof.
 *  Returns number of chars parsed. 
 */
DECLARE_SACS_PARSE_TYPE(float_array);


/** Parse an int using strtol.
 *  Returns number of chars parsed. 
 */
DECLARE_SACS_PARSE_TYPE(int);


/** Parse a int array using strtol.
 *  Returns number of chars parsed. 
 */
DECLARE_SACS_PARSE_TYPE(int_array);


/** Parse a long using strtol.
 *  Returns number of chars parsed. 
 */
DECLARE_SACS_PARSE_TYPE(long);


/** Parse a long array using strtol.
 *  Returns number of chars parsed. 
 */
DECLARE_SACS_PARSE_TYPE(long_array);


/** Parse an unsigned int.
 *  Returns number of chars parsed. 
 */
DECLARE_SACS_PARSE_TYPE(unsigned_int);


/** Parse an unsigned int.
 *  Returns number of chars parsed. 
 */
DECLARE_SACS_PARSE_TYPE(unsigned_int_array);


/** Parse an unsigned long using strtoul.
 *  Returns number of chars parsed. 
 */
DECLARE_SACS_PARSE_TYPE(unsigned_long);


/** Parse an unsigned long using strtoul.
 *  Returns number of chars parsed. 
 */
DECLARE_SACS_PARSE_TYPE(unsigned_long_array);


/** Parse a uint8_t using strtoul.
 *  Returns number of chars parsed. 
 */
DECLARE_SACS_PARSE_TYPE(uint8);


/** Parse a uint8_t using strtoul.
 *  Returns number of chars parsed. 
 */
DECLARE_SACS_PARSE_TYPE(uint8_array);


/** Parse a uint16_t using strtoul.
 *  Returns number of chars parsed. 
 */
DECLARE_SACS_PARSE_TYPE(uint16);


/** Parse a uint16_t array using strtoul.
 *  Returns number of chars parsed. 
 */
DECLARE_SACS_PARSE_TYPE(uint16_array);


/** Parse a uint32_t using strtoul.
 *  Returns number of chars parsed. 
 */
DECLARE_SACS_PARSE_TYPE(uint32);


/** Parse a uint32_t array using strtoul.
 *  Returns number of chars parsed. 
 */
DECLARE_SACS_PARSE_TYPE(uint32_array);


/** Parse a int32_t using strtol.
 *  Returns number of chars parsed. 
 */
DECLARE_SACS_PARSE_TYPE(int32);


/** Parse a int32_t using strtol.
 *  Returns number of chars parsed. 
 */
DECLARE_SACS_PARSE_TYPE(int32_array);




#endif
