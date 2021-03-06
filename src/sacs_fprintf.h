/** sacs_fprintf.h
 
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


#ifndef SACS_FPRINTF_H
#define SACS_FPRINTF_H




#define SACS_FPRINTF_FIELD_TYPE(_type_name_, _field_name_, _macro_type_) \
  SACS_FPRINTF_FIELD(_type_name_, _field_name_, sacs_fprintf_##_macro_type_, sizeof(_macro_type_))


#define SACS_FPRINTF_FIELD_TYPE_ARRAY(_type_name_, _field_name_, _field_size_, _macro_type_) \
  SACS_FPRINTF_FIELD(_type_name_, _field_name_, sacs_fprintf_##_macro_type_##_array, _field_size_ * sizeof(_macro_type_))


#define SACS_FPRINTF_FIELD(_type_name_, _field_name_, _function_, _field_size_) \
  {offsetof(struct _type_name_, _field_name_), #_field_name_, _function_, _field_size_}




#define SACS_FPRINTF_BOOL(_type_name_, _field_name_) \
  SACS_FPRINTF_FIELD_TYPE(_type_name_, _field_name_, bool)


#define SACS_FPRINTF_CHAR(_type_name_, _field_name_) \
  SACS_FPRINTF_FIELD_TYPE(_type_name_, _field_name_, char)


#define SACS_FPRINTF_CHAR_STRING(_type_name_, _field_name_, _size_) \
  SACS_FPRINTF_FIELD(_type_name_, _field_name_, sacs_fprintf_char_string, _size_ * sizeof(char))


#define SACS_FPRINTF_ENUM(_type_name_, _enum_name_, _field_name_) \
  SACS_FPRINTF_FIELD(_type_name_, _field_name_, sacs_fprintf_enum, sizeof(enum _enum_name_))


#define SACS_FPRINTF_INT(_type_name_, _field_name_) \
  SACS_FPRINTF_FIELD_TYPE(_type_name_, _field_name_, int)


#define SACS_FPRINTF_INT_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_FPRINTF_FIELD_TYPE_ARRAY(_type_name_, _field_name_, _size_, int)


#define SACS_FPRINTF_LONG(_type_name_, _field_name_) \
  SACS_FPRINTF_FIELD_TYPE(_type_name_, _field_name_, long)


#define SACS_FPRINTF_LONG_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_FPRINTF_FIELD_TYPE_ARRAY(_type_name_, _field_name_, _size_, long)


#define SACS_FPRINTF_UNSIGNED_LONG(_type_name_, _field_name_) \
  SACS_FPRINTF_FIELD(_type_name_, _field_name_, sacs_fprintf_unsigned_long, sizeof(unsigned long))


#define SACS_FPRINTF_UNSIGNED_LONG_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_FPRINTF_FIELD(_type_name_, _field_name_, sacs_fprintf_unsigned_long_array, _size_ * sizeof(unsigned long))


#define SACS_FPRINTF_DOUBLE(_type_name_, _field_name_) \
  SACS_FPRINTF_FIELD_TYPE(_type_name_, _field_name_, double)


#define SACS_FPRINTF_DOUBLE_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_FPRINTF_FIELD_TYPE_ARRAY(_type_name_, _field_name_, _size_, double)


#define SACS_FPRINTF_FLOAT(_type_name_, _field_name_) \
  SACS_FPRINTF_FIELD_TYPE(_type_name_, _field_name_, float)


#define SACS_FPRINTF_FLOAT_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_FPRINTF_FIELD_TYPE_ARRAY(_type_name_, _field_name_, _size_, float)


#define SACS_FPRINTF_STRUCT(_type_name_, _struct_name_, _field_name_) \
  SACS_FPRINTF_FIELD(_type_name_, _field_name_, _struct_name_##_sacs_fprintf, sizeof(struct _struct_name_))


#define SACS_FPRINTF_STRUCT_ARRAY(_type_name_, _struct_name_, _field_name_, _size_) \
  SACS_FPRINTF_FIELD(_type_name_, _field_name_, _struct_name_##_sacs_fprintf_array, _size_ * sizeof(struct _struct_name_))


#define SACS_FPRINTF_UINT8(_type_name_, _field_name_) \
  SACS_FPRINTF_FIELD_TYPE(_type_name_, _field_name_, uint8_t)


#define SACS_FPRINTF_UINT8_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_FPRINTF_FIELD_TYPE_ARRAY(_type_name_, _field_name_, _size_, uint8_t)


#define SACS_FPRINTF_UINT8_BITFIELD(_type_name_, _field_name_, _size_) \
  SACS_FPRINTF_FIELD(_type_name_, _field_name_, sacs_fprintf_uint8_bitfield, sizeof(uint8_t))


#define SACS_FPRINTF_UINT16(_type_name_, _field_name_) \
  SACS_FPRINTF_FIELD_TYPE(_type_name_, _field_name_, uint16_t)


#define SACS_FPRINTF_UINT16_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_FPRINTF_FIELD_TYPE_ARRAY(_type_name_, _field_name_, _size_, uint16_t)


#define SACS_FPRINTF_UINT32(_type_name_, _field_name_) \
  SACS_FPRINTF_FIELD_TYPE(_type_name_, _field_name_, uint32_t)


#define SACS_FPRINTF_UINT32_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_FPRINTF_FIELD_TYPE_ARRAY(_type_name_, _field_name_, _size_, uint32_t)


#define SACS_FPRINTF_INT32(_type_name_, _field_name_) \
  SACS_FPRINTF_FIELD_TYPE(_type_name_, _field_name_, int32_t)


#define SACS_FPRINTF_INT32_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_FPRINTF_FIELD_TYPE_ARRAY(_type_name_, _field_name_, _size_, int32_t)




#define SACS_FIELD_FPRINTFER_ARRAY(_type_name_) \
  const struct SacsFieldFprintfer _type_name_##_sacs_field_fprintfers[] =


#define SACS_FPRINTFABLE_STRUCT(_type_name_) \
  SACS_FIELD_FPRINTFER_ARRAY(_type_name_)




#define SACS_FPRINTFER(_type_name_, _src_) \
  struct SacsStructFprintfer _type_name_##_sacs_fprintfer = \
  { \
    .name = #_type_name_, \
    .src = _src_, \
    .src_size = sizeof(struct _type_name_), \
    .printers_array = _type_name_##_sacs_field_fprintfers, \
    .printers_count = (sizeof(_type_name_##_sacs_field_fprintfers) / sizeof(struct SacsFieldFprintfer)), \
    .format = SACS_FORMAT_DEFAULT, \
  };




#define SACS_FPRINTFABLE(_type_name_) \
  size_t _type_name_##_sacs_fprintf(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size); \
  size_t _type_name_##_sacs_fprintf(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size) \
  { \
    SACS_FPRINTFER(_type_name_, value); \
    if (printer) { _type_name_##_sacs_fprintfer.format = printer->format; } \
    return sacs_fprintf(file, &_type_name_##_sacs_fprintfer); \
  } \
  size_t _type_name_##_sacs_fprintf_array(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size); \
  size_t _type_name_##_sacs_fprintf_array(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size) \
  { \
    return sacs_fprintf_array(printer, file, value, value_size, sizeof(struct _type_name_), _type_name_##_sacs_fprintf); \
  } \
  size_t _type_name_##_sacs_fprintf_type(FILE* file, const void* value, size_t value_size, struct SacsStructFormat* format); \
  size_t _type_name_##_sacs_fprintf_type(FILE* file, const void* value, size_t value_size, struct SacsStructFormat* format) \
  { \
    if (format) \
    { \
      struct SacsStructFprintfer printer; \
      printer.format = *format; \
      return _type_name_##_sacs_fprintf(&printer, file, value, value_size); \
    } \
    else \
    { \
      return _type_name_##_sacs_fprintf(NULL, file, value, value_size); \
    } \
  }




#define SACS_FPRINTF_TYPE(_type_name_, _src_, _file_) \
  _type_name_##_sacs_fprintf_type(_file_, _src_, sizeof(struct _type_name_))




struct SacsStructFprintfer;
struct SacsFieldFprintfer;
typedef size_t (*SacsFprintfFieldCallback_t)(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size);


struct SacsFieldFprintfer
{
  size_t field_offset;
  const char* name;
  SacsFprintfFieldCallback_t function;
  size_t field_size;
};




struct SacsStructFprintfer
{
  const char* name;
  const struct SacsFieldFprintfer* printers_array;  ///< Pointer to an array of printers.
  size_t printers_count;                             ///< Number of elements in the array of printers.
	
  const void* src;
  size_t src_size;
  
  struct SacsStructFormat format;
  struct SacsStructFormatState state;
};




/** Parse a string and convert to a C structure.
 *  The string must be formatted like a C initializer.
 *  All data in destination is set to 0 before processing the string.
 */
size_t sacs_fprintf(FILE* file, struct SacsStructFprintfer* printer);


/** Parse a string and convert to a C structure.
 *  String may represent only a part of a complete initializer.
 *  Does not affect destination data that is not found in the string.
 */
size_t sacs_fprintf_partial(FILE* file, struct SacsStructFprintfer* printer);


/** Function to iterate over all elements in a string, calling the print function for each.
 */
size_t sacs_fprintf_array(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size, size_t element_size, SacsFprintfFieldCallback_t print_function);




#define DECLARE_SACS_FPRINTF_TYPE(_typename_) \
  size_t sacs_fprintf_##_typename_(struct SacsStructFprintfer*, FILE* file, const void* value, size_t value_size)



DECLARE_SACS_FPRINTF_TYPE(bool);
DECLARE_SACS_FPRINTF_TYPE(char);
DECLARE_SACS_FPRINTF_TYPE(char_string);
DECLARE_SACS_FPRINTF_TYPE(enum);
DECLARE_SACS_FPRINTF_TYPE(int);
DECLARE_SACS_FPRINTF_TYPE(int_array);
DECLARE_SACS_FPRINTF_TYPE(long);
DECLARE_SACS_FPRINTF_TYPE(long_array);
DECLARE_SACS_FPRINTF_TYPE(unsigned_long);
DECLARE_SACS_FPRINTF_TYPE(unsigned_long_array);
DECLARE_SACS_FPRINTF_TYPE(double);
DECLARE_SACS_FPRINTF_TYPE(double_array);
DECLARE_SACS_FPRINTF_TYPE(float);
DECLARE_SACS_FPRINTF_TYPE(float_array);
DECLARE_SACS_FPRINTF_TYPE(uint8);
DECLARE_SACS_FPRINTF_TYPE(uint8_array);
DECLARE_SACS_FPRINTF_TYPE(uint16);
DECLARE_SACS_FPRINTF_TYPE(uint16_array);
DECLARE_SACS_FPRINTF_TYPE(uint32);
DECLARE_SACS_FPRINTF_TYPE(uint32_array);
DECLARE_SACS_FPRINTF_TYPE(int32);
DECLARE_SACS_FPRINTF_TYPE(int32_array);




#endif
