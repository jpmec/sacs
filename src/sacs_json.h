/** sacs_json.h
 
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


#ifndef SACS_JSON_H
#define SACS_JSON_H


#include "sacs_snprintf.h"




#define SACS_JSON_CHAR_FIELD_SEPARATOR          ','
#define SACS_JSON_CHAR_FIELD_VALUE_SEPARATOR    ':'

#define SACS_JSON_CHAR_STRUCT_BEGIN    '{'
#define SACS_JSON_CHAR_STRUCT_END      '}'

#define SACS_JSON_CHAR_ARRAY_BEGIN    '['
#define SACS_JSON_CHAR_ARRAY_END      ']'

#define SACS_JSON_STR_BEFORE_FIELD_NAME    ""
#define SACS_JSON_STR_AFTER_FIELD_NAME     ""


#define SACS_JSON_SNPRINTF_FORMAT \





#define SACS_JSONABLE(_type_name_) \
  size_t _type_name_##_sacs_snprintf_as_json(struct SacsStructSnprintfer* printer, char* dest, size_t dest_size, const void* value, size_t value_size); \
  size_t _type_name_##_sacs_snprintf_as_json(struct SacsStructSnprintfer* printer, char* dest, size_t dest_size, const void* value, size_t value_size) \
  { \
    SACS_SNPRINTFER(_type_name_, value); \
    _type_name_##_sacs_snprintfer.format = (struct SacsStructSnprintfFormat) { \
      .str_before_field_name = SACS_JSON_STR_BEFORE_FIELD_NAME, \
      .str_after_field_name = SACS_JSON_STR_AFTER_FIELD_NAME, \
      .char_field_value_separator = SACS_JSON_CHAR_FIELD_VALUE_SEPARATOR, \
      .char_field_separator = SACS_JSON_CHAR_FIELD_SEPARATOR, \
      .char_struct_begin = SACS_JSON_CHAR_STRUCT_BEGIN, \
      .char_struct_end = SACS_JSON_CHAR_STRUCT_END, \
      .char_array_begin = SACS_JSON_CHAR_ARRAY_BEGIN, \
      .char_array_end = SACS_JSON_CHAR_ARRAY_END, \
    }; \
    return sacs_snprintf(dest, dest_size, &_type_name_##_sacs_snprintfer); \
  } \
  size_t _type_name_##_sacs_snprintf_type_as_json(char* dest, size_t dest_size, const void* value, size_t value_size); \
  size_t _type_name_##_sacs_snprintf_type_as_json(char* dest, size_t dest_size, const void* value, size_t value_size) \
  { \
    return _type_name_##_sacs_snprintf_as_json(NULL, dest, dest_size , value, value_size); \
  }




#define SACS_SNPRINTF_TYPE_AS_JSON(_type_name_, _src_, _dest_, _dest_size_) \
  _type_name_##_sacs_snprintf_type_as_json(_dest_, _dest_size_, _src_, sizeof(struct _type_name_))




/** Converts C structure syntax to JSON.
 */
size_t sacs_ctojson(char* dest, size_t dest_size, const char* src, size_t src_size);
          

/** Converts C structure syntax to JSON.
 */
size_t sacs_jsontoc(char* dest, size_t dest_size, const char* src, size_t src_size);




#endif
