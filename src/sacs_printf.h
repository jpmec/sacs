/** sacs_printf.h
 
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


#ifndef SACS_PRINTF_H
#define SACS_PRINTF_H


#include "sacs_format.h"



#define SACS_PRINTF_FIELD_TYPE(_type_name_, _field_name_, _macro_type_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_##_macro_type_, sizeof(_macro_type_))


#define SACS_PRINTF_FIELD_TYPE_ARRAY(_type_name_, _field_name_, _field_size_, _macro_type_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_##_macro_type_##_array, _field_size_ * sizeof(_macro_type_))


#define SACS_PRINTF_FIELD(_type_name_, _field_name_, _function_, _field_size_) \
  {offsetof(struct _type_name_, _field_name_), #_field_name_, _function_, _field_size_}




#define SACS_PRINTF_BOOL(_type_name_, _field_name_) \
  SACS_PRINTF_FIELD_TYPE(_type_name_, _field_name_, bool)


#define SACS_PRINTF_CHAR(_type_name_, _field_name_) \
  SACS_PRINTF_FIELD_TYPE(_type_name_, _field_name_, char)


#define SACS_PRINTF_CHAR_STRING(_type_name_, _field_name_, _size_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_char_string, _size_ * sizeof(char))


#define SACS_PRINTF_ENUM(_type_name_, _enum_name_, _field_name_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_enum, sizeof(enum _enum_name_))


#define SACS_PRINTF_INT(_type_name_, _field_name_) \
  SACS_PRINTF_FIELD_TYPE(_type_name_, _field_name_, int)


#define SACS_PRINTF_INT_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_PRINTF_FIELD_TYPE_ARRAY(_type_name_, _field_name_, _size_, int)


#define SACS_PRINTF_LONG(_type_name_, _field_name_) \
  SACS_PRINTF_FIELD_TYPE(_type_name_, _field_name_, long)


#define SACS_PRINTF_LONG_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_PRINTF_FIELD_TYPE_ARRAY(_type_name_, _field_name_, _size_, long)


#define SACS_PRINTF_UNSIGNED_LONG(_type_name_, _field_name_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_unsigned_long, sizeof(unsigned long))


#define SACS_PRINTF_UNSIGNED_LONG_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_unsigned_long_array, _size_ * sizeof(unsigned long))


#define SACS_PRINTF_DOUBLE(_type_name_, _field_name_) \
  SACS_PRINTF_FIELD_TYPE(_type_name_, _field_name_, double)


#define SACS_PRINTF_DOUBLE_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_PRINTF_FIELD_TYPE_ARRAY(_type_name_, _field_name_, _size_, double)


#define SACS_PRINTF_FLOAT(_type_name_, _field_name_) \
  SACS_PRINTF_FIELD_TYPE(_type_name_, _field_name_, float)


#define SACS_PRINTF_FLOAT_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_PRINTF_FIELD_TYPE_ARRAY(_type_name_, _field_name_, _size_, float)


#define SACS_PRINTF_STRUCT(_type_name_, _struct_name_, _field_name_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, _struct_name_##_sacs_printf, sizeof(struct _struct_name_))


#define SACS_PRINTF_STRUCT_ARRAY(_type_name_, _struct_name_, _field_name_, _size_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, _struct_name_##_sacs_printf_array, _size_ * sizeof(struct _struct_name_))


#define SACS_PRINTF_UINT8(_type_name_, _field_name_) \
  SACS_PRINTF_FIELD_TYPE(_type_name_, _field_name_, uint8_t)


#define SACS_PRINTF_UINT8_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_PRINTF_FIELD_TYPE_ARRAY(_type_name_, _field_name_, _size_, uint8_t)


#define SACS_PRINTF_UINT8_BITFIELD(_type_name_, _field_name_, _size_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_uint8_bitfield, sizeof(uint8_t))


#define SACS_PRINTF_UINT16(_type_name_, _field_name_) \
  SACS_PRINTF_FIELD_TYPE(_type_name_, _field_name_, uint16_t)


#define SACS_PRINTF_UINT16_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_PRINTF_FIELD_TYPE_ARRAY(_type_name_, _field_name_, _size_, uint16_t)


#define SACS_PRINTF_UINT32(_type_name_, _field_name_) \
  SACS_PRINTF_FIELD_TYPE(_type_name_, _field_name_, uint32_t)


#define SACS_PRINTF_UINT32_ARRAY(_type_name_, _field_name_, _size_) \
SACS_PRINTF_FIELD_TYPE_ARRAY(_type_name_, _field_name_, _size_, uint32_t)


#define SACS_PRINTF_INT32(_type_name_, _field_name_) \
  SACS_PRINTF_FIELD_TYPE(_type_name_, _field_name_, int32_t)


#define SACS_PRINTF_INT32_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_PRINTF_FIELD_TYPE_ARRAY(_type_name_, _field_name_, _size_, int32_t)




#define SACS_FIELD_PRINTFER_ARRAY(_type_name_) \
  const struct SacsFieldPrintfer _type_name_##_sacs_field_printfers[] =


#define SACS_PRINTFABLE_STRUCT(_type_name_) \
  SACS_FIELD_PRINTER_ARRAY(_type_name_)




//#define SACS_PRINTF_FORMAT_DEFAULT \
//  { \
//    .str_before_field_name = SACS_STR_BEFORE_FIELD_NAME, \
//    .str_after_field_name = SACS_STR_AFTER_FIELD_NAME, \
//    .str_before_field_value = SACS_STR_BEFORE_FIELD_VALUE, \
//    .str_after_field_value = SACS_STR_AFTER_FIELD_VALUE, \
//    .str_before_field = SACS_STR_BEFORE_FIELD, \
//    .str_after_field = SACS_STR_AFTER_FIELD, \
//    .str_before_array_field = SACS_STR_BEFORE_ARRAY_FIELD, \
//    .str_after_array_field = SACS_STR_AFTER_ARRAY_FIELD, \
//    .str_field_name_value_separator = SACS_STR_FIELD_VALUE_SEPARATOR, \
//    .str_uint8_format = SACS_STR_UINT8_FORMAT, \
//    .str_uint16_format = SACS_STR_UINT16_FORMAT, \
//    .str_uint32_format = SACS_STR_UINT32_FORMAT, \
//    .char_field_value_separator = SACS_CHAR_FIELD_VALUE_SEPARATOR, \
//    .char_field_separator = SACS_CHAR_FIELD_SEPARATOR, \
//    .char_struct_begin = SACS_CHAR_STRUCT_BEGIN, \
//    .char_struct_end = SACS_CHAR_STRUCT_END, \
//    .char_array_begin = SACS_CHAR_ARRAY_BEGIN, \
//    .char_array_end = SACS_CHAR_ARRAY_END, \
//    .flags = { \
//      .print_field_name = 1, \
//    } \
//  }




//#define SACS_PRINTF_FORMAT_C89 \
//  { \
//    .str_before_field_name = SACS_STR_BEFORE_FIELD_NAME, \
//    .str_after_field_name = SACS_STR_AFTER_FIELD_NAME, \
//    .str_before_field = SACS_STR_BEFORE_FIELD, \
//    .str_after_field = SACS_STR_AFTER_FIELD, \
//    .str_before_array_field = SACS_STR_BEFORE_ARRAY_FIELD, \
//    .str_after_array_field = SACS_STR_AFTER_ARRAY_FIELD, \
//    .str_field_name_value_separator = SACS_STR_FIELD_VALUE_SEPARATOR, \
//    .str_uint8_format = SACS_STR_UINT8_FORMAT, \
//    .str_uint16_format = SACS_STR_UINT16_FORMAT, \
//    .str_uint32_format = SACS_STR_UINT32_FORMAT, \
//    .char_field_value_separator = SACS_CHAR_FIELD_VALUE_SEPARATOR, \
//    .char_field_separator = SACS_CHAR_FIELD_SEPARATOR, \
//    .char_struct_begin = SACS_CHAR_STRUCT_BEGIN, \
//    .char_struct_end = SACS_CHAR_STRUCT_END, \
//    .char_array_begin = SACS_CHAR_ARRAY_BEGIN, \
//    .char_array_end = SACS_CHAR_ARRAY_END, \
//    .flags = { \
//      .print_field_name = 0, \
//    } \
//  }




//#define SACS_PRINTF_FORMAT_PRETTY \
//  { \
//    .str_before_field_name = SACS_STR_BEFORE_FIELD_NAME_PRETTY, \
//    .str_after_field_name = SACS_STR_AFTER_FIELD_NAME_PRETTY, \
//    .str_before_field = SACS_STR_BEFORE_FIELD_PRETTY, \
//    .str_after_field = SACS_STR_AFTER_FIELD_PRETTY, \
//    .str_before_array_field = SACS_STR_BEFORE_ARRAY_FIELD_PRETTY, \
//    .str_after_array_field = SACS_STR_AFTER_ARRAY_FIELD_PRETTY, \
//    .str_field_name_value_separator = SACS_STR_FIELD_VALUE_SEPARATOR_PRETTY, \
//    .str_uint8_format = SACS_STR_UINT8_FORMAT, \
//    .str_uint16_format = SACS_STR_UINT16_FORMAT, \
//    .str_uint32_format = SACS_STR_UINT32_FORMAT, \
//    .char_field_value_separator = SACS_CHAR_FIELD_VALUE_SEPARATOR, \
//    .char_field_separator = SACS_CHAR_FIELD_SEPARATOR, \
//    .char_struct_begin = SACS_CHAR_STRUCT_BEGIN, \
//    .char_struct_end = SACS_CHAR_STRUCT_END, \
//    .char_array_begin = SACS_CHAR_ARRAY_BEGIN, \
//    .char_array_end = SACS_CHAR_ARRAY_END, \
//    .flags = { \
//      .print_field_name = 1, \
//    } \
//  }




#define SACS_PRINTFER(_type_name_, _src_) \
  struct SacsStructPrintfer _type_name_##_sacs_printfer = \
  { \
    .name = #_type_name_, \
    .src = _src_, \
    .src_size = sizeof(struct _type_name_), \
    .printers_array = _type_name_##_sacs_field_printfers, \
    .printers_count = (sizeof(_type_name_##_sacs_field_printfers) / sizeof(struct SacsFieldPrintfer)) \
    .format = SACS_FORMAT_DEFAULT, \
  };




#define SACS_PRINTFABLE(_type_name_) \
  size_t _type_name_##_sacs_printf(struct SacsStructPrintfer* printer, const void* value, size_t value_size); \
  size_t _type_name_##_sacs_printf(struct SacsStructPrintfer* printer, const void* value, size_t value_size) \
  { \
    SACS_PRINTFER(_type_name_, value); \
    if (printer) { _type_name_##_sacs_printfer.fprinter.format = printer->fprinter.format; } \
    return sacs_printf(&_type_name_##_sacs_printfer); \
  } \
  size_t _type_name_##_sacs_printf_array(struct SacsStructPrintfer* printer, const void* value, size_t value_size); \
  size_t _type_name_##_sacs_printf_array(struct SacsStructPrintfer* printer, const void* value, size_t value_size) \
  { \
    return sacs_printf_array(printer, value, value_size, sizeof(struct _type_name_), _type_name_##_sacs_printf); \
  } \
  size_t _type_name_##_sacs_printf_type(const void* value, size_t value_size, struct SacsStructFormat* format); \
  size_t _type_name_##_sacs_printf_type(const void* value, size_t value_size, struct SacsStructFormat* format) \
  { \
    if (format) \
    { \
      struct SacsStructPrintfer printer; \
      printer.fprinter.format = *format; \
      return _type_name_##_sacs_printf(&printer, value, value_size); \
    } \
    else \
    { \
      return _type_name_##_sacs_printf(NULL, value, value_size); \
    } \
  }




#define SACS_PRINTF_TYPE(_type_name_, _src_) \
_type_name_##_sacs_printf(_src_, sizeof(struct _type_name_))




struct SacsStructPrintfer;
struct SacsFieldPrintfer;
typedef size_t (*SacsPrintfFieldCallback_t)(struct SacsStructPrintfer* printer, const void* value, size_t value_size);


struct SacsFieldPrintfer
{
  size_t field_offset;
  const char* name;
  SacsPrintfFieldCallback_t function;
  size_t field_size;
};




struct SacsStructPrintfFormatFlags
{
  unsigned print_field_name : 1;
  unsigned print_hex_prefix : 1;
};




struct SacsStructPrintfFormat
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
  
  const char* str_uint8_format;  
  const char* str_uint16_format;  
  const char* str_uint32_format;
  
  char char_field_value_separator;
  char char_field_separator;
  char char_struct_begin;
  char char_struct_end; 
  char char_array_begin;
  char char_array_end;
  
  int indent_space_count;  ///< Number of spaces for each indent level.
  
  struct SacsStructPrintfFormatFlags flags;
};




struct SacsStructPrintfState
{
  int indent;  ///< Number of indentions
};




struct SacsStructPrintfer
{
  struct SacsStructFprintfer fprinter;
//  const char* name;
//  const struct SacsFieldPrintfer* printers_array;  ///< Pointer to an array of printers.
//  size_t printers_count;                           ///< Number of elements in the array of printers.
	
//  const void* src;
//  size_t src_size;
  
//  struct SacsStructPrintfFormat format;
//  struct SacsStructPrintfState state;
};




/** Parse a string and convert to a C structure.
 *  The string must be formatted like a C initializer.
 *  All data in destination is set to 0 before processing the string.
 */
size_t sacs_printf(struct SacsStructPrintfer* printer);


/** Parse a string and convert to a C structure.
 *  String may represent only a part of a complete initializer.
 *  Does not affect destination data that is not found in the string.
 */
size_t sacs_printf_partial(struct SacsStructPrintfer* printer);


/** Print an array of values using the given print function.
 */
size_t sacs_printf_array(struct SacsStructPrintfer* printer, const void* value, size_t value_size, size_t element_size, SacsPrintfFieldCallback_t print_function);




#define DECLARE_SACS_PRINTF_TYPE(_typename_) \
  size_t sacs_printf_##_typename_(struct SacsStructPrintfer*, const void* value, size_t value_size)



DECLARE_SACS_PRINTF_TYPE(bool);
DECLARE_SACS_PRINTF_TYPE(char);
DECLARE_SACS_PRINTF_TYPE(char_string);
DECLARE_SACS_PRINTF_TYPE(enum);
DECLARE_SACS_PRINTF_TYPE(int);
DECLARE_SACS_PRINTF_TYPE(int_array);
DECLARE_SACS_PRINTF_TYPE(long);
DECLARE_SACS_PRINTF_TYPE(long_array);
DECLARE_SACS_PRINTF_TYPE(unsigned_long);
DECLARE_SACS_PRINTF_TYPE(unsigned_long_array);
DECLARE_SACS_PRINTF_TYPE(double);
DECLARE_SACS_PRINTF_TYPE(double_array);
DECLARE_SACS_PRINTF_TYPE(float);
DECLARE_SACS_PRINTF_TYPE(float_array);
DECLARE_SACS_PRINTF_TYPE(uint8);
DECLARE_SACS_PRINTF_TYPE(uint8_array);
DECLARE_SACS_PRINTF_TYPE(uint16);
DECLARE_SACS_PRINTF_TYPE(uint16_array);
DECLARE_SACS_PRINTF_TYPE(uint32);
DECLARE_SACS_PRINTF_TYPE(uint32_array);
DECLARE_SACS_PRINTF_TYPE(int32);
DECLARE_SACS_PRINTF_TYPE(int32_array);




#endif
