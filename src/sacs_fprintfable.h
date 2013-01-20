/** sacs_fprintfable.h
 
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




#include "sacs_undef.h"




#define sacs_struct(_type_name_) \
  SACS_FIELD_FPRINTFER_ARRAY(_type_name_)


#define sacs_bool(_field_name_) \
  SACS_FPRINTF_BOOL(SACS_STRUCT, _field_name_),


#define sacs_char(_field_name_) \
  SACS_FPRINTF_CHAR(SACS_STRUCT, _field_name_),


#define sacs_int(_field_name_) \
  SACS_FPRINTF_INT(SACS_STRUCT, _field_name_),


#define sacs_int_array(_field_name_, _size_) \
  SACS_FPRINTF_INT_ARRAY(SACS_STRUCT, _field_name_, _size_),


#define sacs_long(_field_name_) \
  SACS_FPRINTF_LONG(SACS_STRUCT, _field_name_),


#define sacs_long_array(_field_name_, _size_) \
  SACS_FPRINTF_LONG_ARRAY(SACS_STRUCT, _field_name_, _size_),


#define sacs_unsigned_long(_field_name_) \
  SACS_FPRINTF_UNSIGNED_LONG(SACS_STRUCT, _field_name_),


#define sacs_unsigned_long_array(_field_name_, _size_) \
  SACS_FPRINTF_UNSIGNED_LONG_ARRAY(SACS_STRUCT, _field_name_, _size_),


#define sacs_double(_field_name_) \
  SACS_FPRINTF_DOUBLE(SACS_STRUCT, _field_name_),


#define sacs_double_array(_field_name_, _size_) \
  SACS_FPRINTF_DOUBLE_ARRAY(SACS_STRUCT, _field_name_, _size_),


#define sacs_float(_field_name_) \
  SACS_FPRINTF_FLOAT(SACS_STRUCT, _field_name_),


#define sacs_float_array(_field_name_, _size_) \
  SACS_FPRINTF_FLOAT_ARRAY(SACS_STRUCT, _field_name_, _size_),


#define sacs_char_string(_field_name_, _size_) \
  SACS_FPRINTF_CHAR_STRING(SACS_STRUCT, _field_name_, _size_),


#define sacs_inner_enum(_enum_name_, _field_name_) \
  SACS_FPRINTF_ENUM(SACS_STRUCT, _enum_name_, _field_name_),


#define sacs_inner_struct(_struct_name_, _field_name_) \
  SACS_FPRINTF_STRUCT(SACS_STRUCT, _struct_name_, _field_name_),


#define sacs_inner_struct_array(_struct_name_, _field_name_, _size_) \
  SACS_FPRINTF_STRUCT_ARRAY(SACS_STRUCT, _struct_name_, _field_name_, _size_),


#define sacs_uint8(_field_name_) \
  SACS_FPRINTF_UINT8(SACS_STRUCT, _field_name_),


#define sacs_uint8_array(_field_name_, _size_) \
  SACS_FPRINTF_UINT8_ARRAY(SACS_STRUCT, _field_name_, _size_),


#define sacs_uint16(_field_name_) \
  SACS_FPRINTF_UINT16(SACS_STRUCT, _field_name_),


#define sacs_uint16_array(_field_name_, _size_) \
  SACS_FPRINTF_UINT16_ARRAY(SACS_STRUCT, _field_name_, _size_),


#define sacs_uint32(_field_name_) \
  SACS_FPRINTF_UINT32(SACS_STRUCT, _field_name_),


#define sacs_uint32_array(_field_name_, _size_) \
  SACS_FPRINTF_UINT32_ARRAY(SACS_STRUCT, _field_name_, _size_),


#define sacs_int32(_field_name_) \
  SACS_FPRINTF_INT32(SACS_STRUCT, _field_name_),


#define sacs_int32_array(_field_name_, _size_) \
  SACS_FPRINTF_INT32_ARRAY(SACS_STRUCT, _field_name_, _size_),


#define sacs_struct_begin(_type_name_) \
sacs_struct(_type_name_) {


#define sacs_struct_end(_type_name_) \
};  SACS_FPRINTFABLE(_type_name_);

