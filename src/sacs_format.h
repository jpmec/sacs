/** sacs_format.h

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


#ifndef SACS_FORMAT_H
#define SACS_FORMAT_H





#define SACS_FORMAT_DEFAULT \
  { \
    .str_before_field_name = SACS_STR_BEFORE_FIELD_NAME, \
    .str_after_field_name = SACS_STR_AFTER_FIELD_NAME, \
    .str_before_field_value = SACS_STR_BEFORE_FIELD_VALUE, \
    .str_after_field_value = SACS_STR_AFTER_FIELD_VALUE, \
    .str_before_field = SACS_STR_BEFORE_FIELD, \
    .str_after_field = SACS_STR_AFTER_FIELD, \
    .str_before_array_field = SACS_STR_BEFORE_ARRAY_FIELD, \
    .str_after_array_field = SACS_STR_AFTER_ARRAY_FIELD, \
    .str_field_value_separator = SACS_STR_FIELD_VALUE_SEPARATOR, \
    .str_field_name_value_separator = SACS_STR_FIELD_VALUE_SEPARATOR, \
    .str_uint8_format = SACS_STR_UINT8_FORMAT, \
    .str_uint16_format = SACS_STR_UINT16_FORMAT, \
    .str_uint32_format = SACS_STR_UINT32_FORMAT, \
    .char_field_value_separator = SACS_CHAR_FIELD_VALUE_SEPARATOR, \
    .char_field_separator = SACS_CHAR_FIELD_SEPARATOR, \
    .char_struct_begin = SACS_CHAR_STRUCT_BEGIN, \
    .char_struct_end = SACS_CHAR_STRUCT_END, \
    .char_array_begin = SACS_CHAR_ARRAY_BEGIN, \
    .char_array_end = SACS_CHAR_ARRAY_END, \
    .char_char_begin = SACS_CHAR_CHAR_BEGIN, \
    .char_char_end = SACS_CHAR_CHAR_END, \
    .flags = { \
      .print_field_name_before_value = 1, \
    } \
  }




#define SACS_FORMAT_C89 \
  { \
    .str_before_field_name = SACS_STR_BEFORE_FIELD_NAME, \
    .str_after_field_name = SACS_STR_AFTER_FIELD_NAME, \
    .str_before_field = SACS_STR_BEFORE_FIELD, \
    .str_after_field = SACS_STR_AFTER_FIELD, \
    .str_before_array_field = SACS_STR_BEFORE_ARRAY_FIELD, \
    .str_after_array_field = SACS_STR_AFTER_ARRAY_FIELD, \
    .str_field_name_value_separator = SACS_STR_FIELD_VALUE_SEPARATOR, \
    .str_uint8_format = SACS_STR_UINT8_FORMAT, \
    .str_uint16_format = SACS_STR_UINT16_FORMAT, \
    .str_uint32_format = SACS_STR_UINT32_FORMAT, \
    .char_field_value_separator = SACS_CHAR_FIELD_VALUE_SEPARATOR, \
    .char_field_separator = SACS_CHAR_FIELD_SEPARATOR, \
    .char_struct_begin = SACS_CHAR_STRUCT_BEGIN, \
    .char_struct_end = SACS_CHAR_STRUCT_END, \
    .char_array_begin = SACS_CHAR_ARRAY_BEGIN, \
    .char_array_end = SACS_CHAR_ARRAY_END, \
    .char_char_begin = SACS_CHAR_CHAR_BEGIN, \
    .char_char_end = SACS_CHAR_CHAR_END, \
    .flags = { \
      .print_field_name_before_value = 0, \
    } \
  }




#define SACS_FORMAT_PRETTY \
  { \
    .str_before_field_name = SACS_STR_BEFORE_FIELD_NAME_PRETTY, \
    .str_after_field_name = SACS_STR_AFTER_FIELD_NAME_PRETTY, \
    .str_before_field = SACS_STR_BEFORE_FIELD_PRETTY, \
    .str_after_field = SACS_STR_AFTER_FIELD_PRETTY, \
    .str_before_array_field = SACS_STR_BEFORE_ARRAY_FIELD_PRETTY, \
    .str_after_array_field = SACS_STR_AFTER_ARRAY_FIELD_PRETTY, \
    .str_field_name_value_separator = SACS_STR_FIELD_VALUE_SEPARATOR_PRETTY, \
    .str_uint8_format = SACS_STR_UINT8_FORMAT, \
    .str_uint16_format = SACS_STR_UINT16_FORMAT, \
    .str_uint32_format = SACS_STR_UINT32_FORMAT, \
    .char_field_value_separator = SACS_CHAR_FIELD_VALUE_SEPARATOR, \
    .char_field_separator = SACS_CHAR_FIELD_SEPARATOR, \
    .char_struct_begin = SACS_CHAR_STRUCT_BEGIN, \
    .char_struct_end = SACS_CHAR_STRUCT_END, \
    .char_array_begin = SACS_CHAR_ARRAY_BEGIN, \
    .char_array_end = SACS_CHAR_ARRAY_END, \
    .char_char_begin = SACS_CHAR_CHAR_BEGIN, \
    .char_char_end = SACS_CHAR_CHAR_END, \
    .flags = { \
      .print_field_name_before_value = 1, \
    } \
  }






struct SacsStructFormatFlags
{
  unsigned print_field_name_before_value : 1;
  unsigned print_field_name_after_value : 1;
  unsigned print_hex_prefix : 1;
};




struct SacsStructFormat
{
  const char* str_before_field_name;
  const char* str_after_field_name;
  const char* str_before_field_value;
  const char* str_after_field_value;  
  const char* str_before_field;
  const char* str_after_field;
  const char* str_before_array_field;
  const char* str_after_array_field;   
  const char* str_field_name_value_separator;
  const char* str_field_value_separator;

  const char* str_uint8_format;  
  const char* str_uint16_format;  
  const char* str_uint32_format;
  
  char char_field_value_separator;
  char char_field_separator;
  char char_struct_begin;
  char char_struct_end; 
  char char_array_begin;
  char char_array_end;
  char char_char_begin;
  char char_char_end;
  
  int indent_space_count;  ///< Number of spaces for each indent level.
  
  struct SacsStructFormatFlags flags;
};




struct SacsStructFormatState
{
  int indent;  ///< Number of indentions
};




#endif
