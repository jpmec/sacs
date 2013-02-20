/** sacs_yaml.h
 
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


#ifndef SACS_YAML_H
#define SACS_YAML_H


#include "sacs_snprintf.h"




#define SACS_YAML_CHAR_FIELD_SEPARATOR          '\n'
#define SACS_YAML_CHAR_FIELD_VALUE_SEPARATOR    ':'

#define SACS_YAML_CHAR_STRUCT_BEGIN    '\0'
#define SACS_YAML_CHAR_STRUCT_END      '\0'

#define SACS_YAML_CHAR_ARRAY_BEGIN    '\n'
#define SACS_YAML_CHAR_ARRAY_END      '\0'


#define SACS_YAML_STR_ARRAY_BEGIN    "\n"
#define SACS_YAML_STR_ARRAY_END      " "

#define SACS_YAML_STR_BEFORE_FIELD_VALUE        NULL
#define SACS_YAML_STR_AFTER_FIELD_VALUE         NULL

#define SACS_YAML_STR_FIELD_NAME_VALUE_SEPARATOR     ": "
#define SACS_YAML_STR_FIELD_VALUE_SEPARATOR          ": "
#define SACS_YAML_STR_BEFORE_FIELD_NAME              NULL
#define SACS_YAML_STR_AFTER_FIELD_NAME               NULL

#define SACS_YAML_STR_BEFORE_FIELD              NULL
#define SACS_YAML_STR_AFTER_FIELD               NULL

#define SACS_YAML_STR_BEFORE_ARRAY_FIELD         "- "
#define SACS_YAML_STR_AFTER_ARRAY_FIELD         NULL




#define SACS_YAML_FORMAT_DEFAULT \
  (struct SacsStructFormat) { \
    .str_before_field_name = SACS_YAML_STR_BEFORE_FIELD_NAME, \
    .str_after_field_name = SACS_YAML_STR_AFTER_FIELD_NAME, \
    .str_before_field_value = SACS_YAML_STR_BEFORE_FIELD_VALUE, \
    .str_after_field_value = SACS_YAML_STR_AFTER_FIELD_VALUE, \
    .str_before_field = SACS_YAML_STR_BEFORE_FIELD, \
    .str_after_field = SACS_YAML_STR_AFTER_FIELD, \
    .str_before_array_field = SACS_YAML_STR_BEFORE_ARRAY_FIELD, \
    .str_after_array_field = SACS_YAML_STR_AFTER_ARRAY_FIELD, \
    .str_field_value_separator = SACS_YAML_STR_FIELD_VALUE_SEPARATOR, \
    .str_field_name_value_separator = SACS_YAML_STR_FIELD_VALUE_SEPARATOR, \
    .char_field_value_separator = SACS_YAML_CHAR_FIELD_VALUE_SEPARATOR, \
    .char_field_separator = SACS_YAML_CHAR_FIELD_SEPARATOR, \
    .char_struct_begin = SACS_YAML_CHAR_STRUCT_BEGIN, \
    .char_struct_end = SACS_YAML_CHAR_STRUCT_END, \
    .char_array_end = SACS_YAML_CHAR_ARRAY_END, \
    .input = { \
      .char_array_begin = SACS_YAML_CHAR_ARRAY_BEGIN, \
    }, \
    .output = { \
      .str_array_begin = SACS_YAML_STR_ARRAY_BEGIN, \
    }, \
    .flags = { \
      .print_field_name_before_value = 1, \
    } \
  }




#define SACS_YAMLABLE(_type_name_) \
  size_t _type_name_##_sacs_snprintf_as_yaml(struct SacsStructSnprintfer* printer, char* dest, size_t dest_size, const void* value, size_t value_size, const struct SacsStructFormat* format); \
  size_t _type_name_##_sacs_snprintf_as_yaml(struct SacsStructSnprintfer* printer, char* dest, size_t dest_size, const void* value, size_t value_size, const struct SacsStructFormat* format) \
  { \
    SACS_SNPRINTFER(_type_name_, value); \
    if (format) \
    { \
      _type_name_##_sacs_snprintfer.format = *format; \
    } \
    else \
    { \
      _type_name_##_sacs_snprintfer.format = SACS_YAML_FORMAT_DEFAULT; \
    } \
    return sacs_snprintf(dest, dest_size, &_type_name_##_sacs_snprintfer); \
  } \
  size_t _type_name_##_sacs_snprintf_type_as_yaml(char* dest, size_t dest_size, const void* value, size_t value_size, const struct SacsStructFormat* format); \
  size_t _type_name_##_sacs_snprintf_type_as_yaml(char* dest, size_t dest_size, const void* value, size_t value_size, const struct SacsStructFormat* format) \
  { \
    return _type_name_##_sacs_snprintf_as_yaml(NULL, dest, dest_size , value, value_size, format); \
  }




#define SACS_SNPRINTF_TYPE_AS_YAML(_type_name_, _src_, _dest_, _dest_size_, _format_) \
  _type_name_##_sacs_snprintf_type_as_yaml(_dest_, _dest_size_, _src_, sizeof(struct _type_name_), _format_)






/** Converts C structure syntax to YAML.
 */
size_t sacs_ctoyaml(char* dest, size_t dest_size, const char* src, size_t src_size);
          

/** Converts YAML to C structure syntax.
 */
size_t sacs_yamltoc(char* dest, size_t dest_size, const char* src, size_t src_size);




#endif
