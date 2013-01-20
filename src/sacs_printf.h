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




#define SACS_PRINTF_FIELD(_type_name_, _field_name_, _function_, _field_size_) \
  {offsetof(struct _type_name_, _field_name_), #_field_name_, _function_, _field_size_}


#define SACS_PRINTF_BOOL(_type_name_, _field_name_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_bool, sizeof(bool))


#define SACS_PRINTF_CHAR(_type_name_, _field_name_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_char, sizeof(char))


#define SACS_PRINTF_INT(_type_name_, _field_name_) \
SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_int, sizeof(int))


#define SACS_PRINTF_INT_ARRAY(_type_name_, _field_name_, _size_) \
SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_int_array, _size_ * sizeof(int))


#define SACS_PRINTF_LONG(_type_name_, _field_name_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_long, sizeof(long))


#define SACS_PRINTF_LONG_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_long_array, _size_ * sizeof(long))


#define SACS_PRINTF_UNSIGNED_LONG(_type_name_, _field_name_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_unsigned_long, sizeof(unsigned long))


#define SACS_PRINTF_UNSIGNED_LONG_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_unsigned_long_array, _size_ * sizeof(unsigned long))


#define SACS_PRINTF_DOUBLE(_type_name_, _field_name_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_double, sizeof(double))


#define SACS_PRINTF_DOUBLE_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_double_array, _size_ * sizeof(double))


#define SACS_PRINTF_FLOAT(_type_name_, _field_name_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_float, sizeof(float))


#define SACS_PRINTF_FLOAT_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_float_array, _size_ * sizeof(float))


#define SACS_PRINTF_CHAR_STRING(_type_name_, _field_name_, _size_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_char_string, _size_ * sizeof(char))


#define SACS_PRINTF_ENUM(_type_name_, _enum_name_, _field_name_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_enum, sizeof(enum _enum_name_))


#define SACS_PRINTF_STRUCT(_type_name_, _struct_name_, _field_name_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, _struct_name_##_sacs_printf, sizeof(struct _struct_name_))


#define SACS_PRINTF_STRUCT_ARRAY(_type_name_, _struct_name_, _field_name_, _size_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, _struct_name_##_sacs_printf_array, _size_ * sizeof(struct _struct_name_))


#define SACS_PRINTF_UINT8(_type_name_, _field_name_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_uint8, sizeof(uint8_t))


#define SACS_PRINTF_UINT8_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_uint8_array, _size_ * sizeof(uint8_t))


#define SACS_PRINTF_UINT16(_type_name_, _field_name_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_uint16, sizeof(uint16_t))


#define SACS_PRINTF_UINT16_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_uint16_array, _size_ * sizeof(uint16_t))


#define SACS_PRINTF_UINT32(_type_name_, _field_name_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_uint32, sizeof(uint32_t))


#define SACS_PRINTF_UINT32_ARRAY(_type_name_, _field_name_, _size_) \
SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_uint32_array, _size_ * sizeof(uint32_t))


#define SACS_PRINTF_INT32(_type_name_, _field_name_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_int32, sizeof(int32_t))


#define SACS_PRINTF_INT32_ARRAY(_type_name_, _field_name_, _size_) \
  SACS_PRINTF_FIELD(_type_name_, _field_name_, sacs_printf_int32_array, _size_ * sizeof(int32_t))


#define SACS_FIELD_PRINTFER_ARRAY(_type_name_) \
  const struct SacsFieldPrintfer _type_name_##_sacs_field_printfers[] =


#define SACS_PRINTFABLE_STRUCT(_type_name_) \
  SACS_FIELD_PRINTER_ARRAY(_type_name_)


#define SACS_PRINTFER(_type_name_, _src_) \
  struct SacsStructPrintfer _type_name_##_sacs_printfer = \
  { \
    .name = #_type_name_, \
    .src = _src_, \
    .src_size = sizeof(struct _type_name_), \
    .printers_array = _type_name_##_sacs_field_printfers, \
    .printers_count = (sizeof(_type_name_##_sacs_field_printfers) / sizeof(struct SacsFieldPrintfer)) \
  };


#define SACS_PRINTFABLE(_type_name_) \
  SACS_FPRINTFABLE(_type_name);


#define SACS_PRINTF(_type_name_) \
  sacs_printf(&_type_name_##_sacs_printfer)


#define SACS_PRINTF_TYPE(_type_name_, _src_) \
  _type_name_##_sacs_printf(_src_, sizeof(struct _type_name_))




struct SacsStructPrintfer;
struct SacsFieldPrintfer;
typedef size_t (*SacsPrintfFieldCallback_t)(const void* value, size_t value_size);




struct SacsFieldPrintfer
{
  struct SacsFieldFprintfer fprinter;
};




struct SacsStructPrintfer
{
  struct SacsStructFprintfer fprinter;
};




/** Print an array of values using the given print function.
 */
size_t sacs_printf_array(struct SacsStructPrintfer* printer, const void* value, size_t value_size, size_t element_size, SacsPrintfFieldCallback_t print_function);


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


/** Print a boolean value using printf.
 *  Returns number of chars printed.
 */
size_t sacs_printf_bool(struct SacsStructPrintfer* printer, const void* value, size_t value_size);


/** Print a single character using printf.
 *  Returns number of chars printed.
 */
size_t sacs_printf_char(struct SacsStructPrintfer* printer, const void* value, size_t value_size);


/** Print a null-terminated string of characters using printf.
 *  Returns number of chars printed.
 */
size_t sacs_printf_char_string(struct SacsStructPrintfer* printer, const void* value, size_t value_size);


/** Print an enum string using printf.
 *  Returns number of chars printed.
 */
size_t sacs_printf_enum(struct SacsStructPrintfer* printer, const void* value, size_t value_size);


/** Print a int using printf.
 *  Returns number of chars printed.
 */
size_t sacs_printf_int(struct SacsStructPrintfer* printer, const void* value, size_t value_size);


/** Print a int array using printf.
 *  Returns number of chars printed.
 */
size_t sacs_printf_int_array(struct SacsStructPrintfer* printer, const void* value, size_t value_size);


/** Print a long using printf.
 *  Returns number of chars printed.
 */
size_t sacs_printf_long(struct SacsStructPrintfer* printer, const void* value, size_t value_size);


/** Print a long array using printf.
 *  Returns number of chars printed.
 */
size_t sacs_printf_long_array(struct SacsStructPrintfer* printer, const void* value, size_t value_size);


/** Print an unsigned long using printf.
 *  Returns number of chars printed.
 */
size_t sacs_printf_unsigned_long(struct SacsStructPrintfer* printer, const void* value, size_t value_size);


/** Print an unsigned long array using printf.
 *  Returns number of chars printed.
 */
size_t sacs_printf_unsigned_long_array(struct SacsStructPrintfer* printer, const void* value, size_t value_size);


/** Print a double using printf.
 *  Returns number of chars printed.
 */
size_t sacs_printf_double(struct SacsStructPrintfer* printer, const void* value, size_t value_size);


/** Print a double using printf.
 *  Returns number of chars printed.
 */
size_t sacs_printf_double_array(struct SacsStructPrintfer* printer, const void* value, size_t value_size);


/** Print a float using printf.
 *  Returns number of chars printed.
 */
size_t sacs_printf_float(struct SacsStructPrintfer* printer, const void* value, size_t value_size);


/** Print a float using printf.
 *  Returns number of chars printed.
 */
size_t sacs_printf_float_array(struct SacsStructPrintfer* printer, const void* value, size_t value_size);


/** Print a uint8_t using printf.
 *  Returns number of chars printed.
 */
size_t sacs_printf_uint8(struct SacsStructPrintfer* printer, const void* value, size_t value_size);


/** Print a uint8_t array using printf.
 *  Returns number of chars printed.
 */
size_t sacs_printf_uint8_array(struct SacsStructPrintfer* printer, const void* value, size_t value_size);


/** Print a uint16_t using printf.
 *  Returns number of chars printed.
 */
size_t sacs_printf_uint16(struct SacsStructPrintfer* printer, const void* value, size_t value_size);


/** Print a uint16_t array using printf.
 *  Returns number of chars printed.
 */
size_t sacs_printf_uint16_array(struct SacsStructPrintfer* printer, const void* value, size_t value_size);


/** Print a uint32_t using printf.
 *  Returns number of chars printed.
 */
size_t sacs_printf_uint32(struct SacsStructPrintfer* printer, const void* value, size_t value_size);


/** Print a uint32_t array using printf.
 *  Returns number of chars printed.
 */
size_t sacs_printf_uint32_array(struct SacsStructPrintfer* printer, const void* value, size_t value_size);


/** Print an int32_t using printf.
 *  Returns number of chars printed.
 */
size_t sacs_printf_int32(struct SacsStructPrintfer* printer, const void* value, size_t value_size);


/** Print an int32_t array using printf.
 *  Returns number of chars printed.
 */
size_t sacs_printf_int32_array(struct SacsStructPrintfer* printer, const void* value, size_t value_size);

