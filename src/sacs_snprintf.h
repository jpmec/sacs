/** sacs_snprintf.h

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


#ifndef SACS_SNPRINTF_H
#define SACS_SNPRINTF_H




#define SACS_SNPRINTF_FIELD_TYPE(_type_name_, _field_name_, _macro_type_) \
  SACS_SNPRINTF_FIELD(_type_name_, _field_name_, sacs_snprintf_##_macro_type_, sizeof(_macro_type_))


#define SACS_SNPRINTF_FIELD_TYPE_ARRAY(_type_name_, _field_name_, _field_size_, _macro_type_) \
  SACS_SNPRINTF_FIELD(_type_name_, _field_name_, sacs_snprintf_##_macro_type_##_array, _field_size_ * sizeof(_macro_type_))


#define SACS_SNPRINTF_FIELD(_type_name_, _field_name_, _function_, _field_size_) \
  {offsetof(struct _type_name_, _field_name_), #_field_name_, _function_, _field_size_}




#define SACS_SNPRINTF_BOOL(_type_name_, _field_name_) \
  SACS_SNPRINTF_FIELD_TYPE(_type_name_, _field_name_, bool)


#define SACS_SNPRINTF_CHAR(_type_name_, _field_name_) \
  SACS_SNPRINTF_FIELD_TYPE(_type_name_, _field_name_, char)


#define SACS_SNPRINTF_CHAR_STRING(_type_name_, _field_name_, _size_) \
  SACS_SNPRINTF_FIELD(_type_name_, _field_name_, sacs_snprintf_char_string, _size_ * sizeof(char))


#define SACS_SNPRINTF_ENUM(_type_name_, _enum_name_, _field_name_) \
SACS_SNPRINTF_FIELD(_type_name_, _field_name_, sacs_snprintf_enum, sizeof(enum _enum_name_))


#define SACS_SNPRINTF_INT(_type_name_, _field_name_) \
  SACS_SNPRINTF_FIELD_TYPE(_type_name_, _field_name_, int)


#define SACS_SNPRINTF_INT_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_SNPRINTF_FIELD_TYPE_ARRAY(_type_name_, _field_name_, _size_, int)


#define SACS_SNPRINTF_LONG(_type_name_, _field_name_) \
  SACS_SNPRINTF_FIELD_TYPE(_type_name_, _field_name_, long)


#define SACS_SNPRINTF_LONG_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_SNPRINTF_FIELD_TYPE_ARRAY(_type_name_, _field_name_, _size_, long)


#define SACS_SNPRINTF_UNSIGNED_LONG(_type_name_, _field_name_) \
  SACS_SNPRINTF_FIELD(_type_name_, _field_name_, sacs_snprintf_unsigned_long, sizeof(unsigned long))


#define SACS_SNPRINTF_UNSIGNED_LONG_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_SNPRINTF_FIELD(_type_name_, _field_name_, sacs_snprintf_unsigned_long_array, _size_ * sizeof(unsigned long))


#define SACS_SNPRINTF_DOUBLE(_type_name_, _field_name_) \
  SACS_SNPRINTF_FIELD_TYPE(_type_name_, _field_name_, double)


#define SACS_SNPRINTF_DOUBLE_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_SNPRINTF_FIELD_TYPE_ARRAY(_type_name_, _field_name_, _size_, double)


#define SACS_SNPRINTF_FLOAT(_type_name_, _field_name_) \
  SACS_SNPRINTF_FIELD_TYPE(_type_name_, _field_name_, float)


#define SACS_SNPRINTF_FLOAT_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_SNPRINTF_FIELD_TYPE_ARRAY(_type_name_, _field_name_, _size_, float)


#define SACS_SNPRINTF_STRUCT(_type_name_, _struct_name_, _field_name_) \
  SACS_SNPRINTF_FIELD(_type_name_, _field_name_, _struct_name_##_sacs_snprintf, sizeof(struct _struct_name_))


#define SACS_SNPRINTF_STRUCT_ARRAY(_type_name_, _struct_name_, _field_name_, _size_) \
  SACS_SNPRINTF_FIELD(_type_name_, _field_name_, _struct_name_##_sacs_snprintf_array, _size_ * sizeof(struct _struct_name_))


#define SACS_SNPRINTF_UINT8(_type_name_, _field_name_) \
  SACS_SNPRINTF_FIELD(_type_name_, _field_name_, sacs_snprintf_uint8, sizeof(uint8_t))


#define SACS_SNPRINTF_UINT8_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_SNPRINTF_FIELD(_type_name_, _field_name_, sacs_snprintf_uint8_array, _size_ * sizeof(uint8_t))


#define SACS_SNPRINTF_UINT8_BITFIELD(_type_name_, _field_name_, _size_) \
  SACS_SNPRINTF_FIELD(_type_name_, _field_name_, sacs_snprintf_uint8_bitfield, sizeof(uint8_t))


#define SACS_SNPRINTF_UINT16(_type_name_, _field_name_) \
  SACS_SNPRINTF_FIELD(_type_name_, _field_name_, sacs_snprintf_uint16, sizeof(uint16_t))


#define SACS_SNPRINTF_UINT16_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_SNPRINTF_FIELD(_type_name_, _field_name_, sacs_snprintf_uint16_array, _size_ * sizeof(uint16_t))


#define SACS_SNPRINTF_UINT32(_type_name_, _field_name_) \
  SACS_SNPRINTF_FIELD(_type_name_, _field_name_, sacs_snprintf_uint32, sizeof(uint32_t))


#define SACS_SNPRINTF_UINT32_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_SNPRINTF_FIELD(_type_name_, _field_name_, sacs_snprintf_uint32_array, _size_ * sizeof(uint32_t))


#define SACS_SNPRINTF_INT32(_type_name_, _field_name_) \
  SACS_SNPRINTF_FIELD(_type_name_, _field_name_, sacs_snprintf_int32, sizeof(int32_t))


#define SACS_SNPRINTF_INT32_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_SNPRINTF_FIELD(_type_name_, _field_name_, sacs_snprintf_int32_array, _size_ * sizeof(int32_t))




#define SACS_FIELD_SNPRINTFER_ARRAY(_type_name_) \
  const struct SacsFieldSnprintfer _type_name_##_sacs_field_snprintfers[] =


#define SACS_SNPRINTFABLE_STRUCT(_type_name_) \
  SACS_FIELD_SNPRINTFER_ARRAY(_type_name_)



#define SACS_SNPRINTF_FORMAT_DEFAULT \
  { \
    .str_before_field_name = SACS_STR_BEFORE_FIELD_NAME, \
    .str_after_field_name = SACS_STR_AFTER_FIELD_NAME, \
    .str_before_field_value = SACS_STR_BEFORE_FIELD_VALUE, \
    .str_after_field_value = SACS_STR_AFTER_FIELD_VALUE, \
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
    .flags = { \
      .print_field_name = 1, \
    } \
  }




#define SACS_SNPRINTF_FORMAT_C89 \
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
    .flags = { \
      .print_field_name = 0, \
    } \
  }




#define SACS_SNPRINTF_FORMAT_PRETTY \
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
    .flags = { \
      .print_field_name = 1, \
    } \
  }




#define SACS_SNPRINTFER(_type_name_, _src_) \
  struct SacsStructSnprintfer _type_name_##_sacs_snprintfer = \
  { \
    .name = #_type_name_, \
    .src = _src_, \
    .src_size = sizeof(struct _type_name_), \
    .printers_array = _type_name_##_sacs_field_snprintfers, \
    .printers_count = (sizeof(_type_name_##_sacs_field_snprintfers) / sizeof(struct SacsFieldSnprintfer)), \
    .format = SACS_SNPRINTF_FORMAT_DEFAULT, \
  };




#define SACS_SNPRINTFABLE(_type_name_) \
  size_t _type_name_##_sacs_snprintf(struct SacsStructSnprintfer* printer, char* dest, size_t dest_size, const void* value, size_t value_size); \
  size_t _type_name_##_sacs_snprintf(struct SacsStructSnprintfer* printer, char* dest, size_t dest_size, const void* value, size_t value_size) \
  { \
    SACS_SNPRINTFER(_type_name_, value); \
    if (printer) { _type_name_##_sacs_snprintfer.format = printer->format; } \
    return sacs_snprintf(dest, dest_size, &_type_name_##_sacs_snprintfer); \
  } \
  size_t _type_name_##_sacs_snprintf_array(struct SacsStructSnprintfer* printer, char* _dest_, size_t _dest_size_, const void* _value_, size_t _value_size_); \
  size_t _type_name_##_sacs_snprintf_array(struct SacsStructSnprintfer* printer, char* _dest_, size_t _dest_size_, const void* _value_, size_t _value_size_) \
  { \
    return sacs_snprintf_array(printer, _dest_, _dest_size_, _value_, _value_size_, sizeof(struct _type_name_), _type_name_##_sacs_snprintf); \
  } \
  size_t _type_name_##_sacs_snprintf_type(char* dest, size_t dest_size, const void* value, size_t value_size, struct SacsStructSnprintfFormat* format); \
  size_t _type_name_##_sacs_snprintf_type(char* dest, size_t dest_size, const void* value, size_t value_size, struct SacsStructSnprintfFormat* format) \
  { \
    if (format) \
    { \
      struct SacsStructSnprintfer printer; \
      printer.format = *format; \
      return _type_name_##_sacs_snprintf(&printer, dest, dest_size , value, value_size); \
    } \
    else \
    { \
      return _type_name_##_sacs_snprintf(NULL, dest, dest_size , value, value_size); \
    } \
  }




#define SACS_SNPRINTF_TYPE(_type_name_, _src_, _dest_, _dest_size_, _format_) \
  _type_name_##_sacs_snprintf_type(_dest_, _dest_size_, _src_, sizeof(struct _type_name_), _format_)




struct SacsStructSnprintfer;
struct SacsFieldSnprintfer;
typedef size_t (*SacsSnprintfFieldCallback_t)(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const void* value, size_t value_size);


struct SacsFieldSnprintfer
{
  size_t field_offset;
  const char* name;
  SacsSnprintfFieldCallback_t function;
  size_t field_size;
};




struct SacsStructSnprintfFormatFlags
{
  unsigned print_field_name : 1;
  unsigned print_hex_prefix : 1;
};




struct SacsStructSnprintfFormat
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
  
  struct SacsStructSnprintfFormatFlags flags;
};




struct SacsStructSnprintfState
{
  int indent;  ///< Number of indentions
};




struct SacsStructSnprintfer
{
  const char* name;
  const struct SacsFieldSnprintfer* printers_array;  ///< Pointer to an array of printers.
  size_t printers_count;                             ///< Number of elements in the array of printers.
	
  const void* src;
  size_t src_size;
  
  struct SacsStructSnprintfFormat format;
  struct SacsStructSnprintfState state;
};






/** Print a C structure.
 *  The string must be formatted like a C initializer.
 */
size_t sacs_snprintf(char* str, size_t str_size, struct SacsStructSnprintfer*);


/** Print part of a C structure.
 */
size_t sacs_snprintf_partial(char* str, size_t str_size, struct SacsStructSnprintfer*);


/** Function to iterate over all elements in a string, calling the print function for each.
 */
size_t sacs_snprintf_array(struct SacsStructSnprintfer*, char* str, size_t str_size, const void* value, size_t value_size, size_t element_size, SacsSnprintfFieldCallback_t snprintf_function);




#define DECLARE_SACS_SNPRINTF_TYPE(_typename_) \
  size_t sacs_snprintf_##_typename_(struct SacsStructSnprintfer*, char* str, size_t str_size, const void* value, size_t value_size)


DECLARE_SACS_SNPRINTF_TYPE(bool);
DECLARE_SACS_SNPRINTF_TYPE(char);
DECLARE_SACS_SNPRINTF_TYPE(char_string);
DECLARE_SACS_SNPRINTF_TYPE(enum);
DECLARE_SACS_SNPRINTF_TYPE(int);
DECLARE_SACS_SNPRINTF_TYPE(int_array);
DECLARE_SACS_SNPRINTF_TYPE(long);
DECLARE_SACS_SNPRINTF_TYPE(long_array);
DECLARE_SACS_SNPRINTF_TYPE(unsigned_long);
DECLARE_SACS_SNPRINTF_TYPE(unsigned_long_array);
DECLARE_SACS_SNPRINTF_TYPE(double);
DECLARE_SACS_SNPRINTF_TYPE(double_array);
DECLARE_SACS_SNPRINTF_TYPE(float);
DECLARE_SACS_SNPRINTF_TYPE(float_array);
DECLARE_SACS_SNPRINTF_TYPE(uint8);
DECLARE_SACS_SNPRINTF_TYPE(uint8_array);
DECLARE_SACS_SNPRINTF_TYPE(uint16);
DECLARE_SACS_SNPRINTF_TYPE(uint16_array);
DECLARE_SACS_SNPRINTF_TYPE(uint32);
DECLARE_SACS_SNPRINTF_TYPE(uint32_array);
DECLARE_SACS_SNPRINTF_TYPE(int32);
DECLARE_SACS_SNPRINTF_TYPE(int32_array);




#endif
