/** sacs.c
 
 Simple API for C Structures.
 
 
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


#include "sacs.h"

#include <assert.h>
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>




#define DEFINE_SNPRINTF_ARRAY_FUNCTION(_type_name_) \
  size_t sacs_snprintf_##_type_name_##_array(char* str, size_t str_size, const void* value, size_t value_size) \
  { \
    assert(str); \
    assert(str_size); \
    assert(value); \
    assert(value_size); \
    \
    return sacs_snprintf_array(str, str_size, value, value_size, sizeof(_type_name_), sacs_snprintf_##_type_name_); \
  }




size_t sacs_snprintf_array(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const void* value, size_t value_size, size_t element_size, SacsSnprintfFieldCallback_t snprintf_function)
{
  assert(str);
  assert(str_size);
  assert(value);
  assert(value_size);
  assert(element_size);
  assert(snprintf_function);
  
  const char* str_start = str;
  
  size_t array_count = value_size / element_size;
  
  
  if (printer->format.char_array_begin)
  {
    size_t count = snprintf(str, str_size, "%c", printer->format.char_array_begin);
    str += count;
    str_size -= count;
  }
  
  do
  {
    if (printer->format.str_before_array_field)
    {
      size_t count = snprintf(str, str_size, "%s", printer->format.str_before_array_field);
      str += count;
      str_size -= count;      
    }
    
    size_t count = snprintf_function(printer, str, str_size, value, element_size); 
    str += count;
    str_size -= count;
    value += element_size;
    
    if (printer->format.str_after_array_field)
    {
      size_t count = snprintf(str, str_size, "%s", printer->format.str_after_array_field);
      str += count;
      str_size -= count;      
    }    
    
    if (array_count > 1)
    {
      if (printer->format.char_field_separator)
      {
        *str = printer->format.char_field_separator;
        ++str;
        --str_size;
      }
    }
    
  } while (--array_count);
  
  if (printer->format.char_array_end)
  {
    size_t count = snprintf(str, str_size, "%c", printer->format.char_array_end);
    str += count;
    str_size -= count;  
  }
  
  return str - str_start;
}




static size_t sacs_snprintf_field_name(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const char* field_name)
{
  assert(printer);
  assert(str);
  assert(str_size);
  assert(field_name);
  
  char* char_ptr = str;
  
  if (printer->format.str_before_field_name)
  {
    const size_t count = snprintf(char_ptr, str_size, "%s", printer->format.str_before_field_name);    
    char_ptr += count;
    str_size -= count;
  }
  
  
  const size_t count = snprintf(char_ptr, str_size, "%s", field_name);
  char_ptr += count;
  str_size -= count;
  
  
  if (printer->format.str_after_field_name)
  {
    const size_t count = snprintf(char_ptr, str_size, "%s", printer->format.str_after_field_name);    
    char_ptr += count;
    str_size -= count;
  }
  
  return char_ptr - str;
}




static size_t sacs_snprintf_field_value(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const struct SacsFieldSnprintfer* field_printer)
{
  assert(printer);
  assert(str);
  assert(str_size);
  assert(field_printer);

  char* char_ptr = str;
  
  if (printer->format.str_before_field)
  {
    size_t count = snprintf(char_ptr, str_size, "%s", printer->format.str_before_field);
    char_ptr += count;
    str_size -= count;
  }
  
  const void* src = printer->src + field_printer->field_offset;
  size_t count = field_printer->function(printer, char_ptr, str_size, src, field_printer->field_size);
  char_ptr += count;
  str_size -= count;
  
  if (printer->format.str_after_field)
  {
    size_t count = snprintf(char_ptr, str_size, "%s", printer->format.str_after_field);
    char_ptr += count;
    str_size -= count;
  }
  
  return char_ptr - str;
}




size_t sacs_snprintf_partial(char* str, size_t str_size, struct SacsStructSnprintfer* printer)
{
  assert(printer);
  assert(str);
  assert(str_size);
  
  char* char_ptr = str;
  size_t count = 0;
  
  const struct SacsFieldSnprintfer* field_printer = printer->printers_array;
  
  size_t printers_count = printer->printers_count;
  
  do
  {
    if (printer->format.flags.print_field_name_before_value)
    {
      count = sacs_snprintf_field_name(printer, char_ptr, str_size, field_printer->name);
      char_ptr += count;
      str_size -= count;
    
      if (printer->format.str_field_name_value_separator)
      {
        count = snprintf(char_ptr, str_size, "%s", printer->format.str_field_name_value_separator);
        char_ptr += count;
        str_size -= count;
      }
    }
    
    
    count = sacs_snprintf_field_value(printer, char_ptr, str_size, field_printer);
    char_ptr += count;
    str_size -= count;

    
    if (printer->format.flags.print_field_name_after_value)
    {
      count = sacs_snprintf_field_name(printer, char_ptr, str_size, field_printer->name);
      char_ptr += count;
      str_size -= count;
    }    
    
    if (1 < printers_count)
    {
      if (printer->format.char_field_separator)
      {
        count = snprintf(char_ptr, str_size, "%c", printer->format.char_field_separator);
        char_ptr += count;
        str_size -= count;
      }
    }
    
    ++field_printer;
    --printers_count;
  } while (printers_count);
  
  return char_ptr - str;
}




size_t sacs_snprintf(char* str, size_t str_size, struct SacsStructSnprintfer* printer)
{
  assert(printer);
  assert(str);
  assert(str_size);
  
  char* char_ptr = str;
  
  if (printer->format.char_struct_begin)
  {
    size_t count = snprintf(char_ptr, str_size, "%c", printer->format.char_struct_begin);
    char_ptr += count;
    str_size -= count;
  }
  
  // may have data
  size_t count = sacs_snprintf_partial(char_ptr, str_size, printer);
  char_ptr += count;
  str_size -= count;  
  
  if (printer->format.char_struct_end)
  {
    count = snprintf(char_ptr, str_size, "%c", printer->format.char_struct_end);
    char_ptr += count;
    str_size -= count;  
  }
  
  return char_ptr - str;
}




size_t sacs_snprintf_bool(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const void* value, size_t value_size)
{
  assert(printer);  
  assert(str);
  assert(str_size);
  assert(value);
  assert(value_size);  
  
  const bool* bool_value = (const bool*) value;
  
  if (bool_value)
  {
    return snprintf(str, str_size, "true");
  }
  else
  {
    return snprintf(str, str_size, "false");    
  }
}




size_t sacs_snprintf_char(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const void* value, size_t value_size)
{
  assert(printer);  
  assert(str);
  assert(str_size);
  assert(value);
  assert(value_size);  
  
  const char* char_value = (const char*) value;
  
  char c = *char_value;

  if ('\0' == c)
  {
    return snprintf(str, str_size, "\'\\0\'");    
  }
  else if (isgraph(c))
  {
    char* char_ptr = str;
    
    if (printer->format.char_char_begin)
    {
      *char_ptr = printer->format.char_char_begin;
      ++char_ptr;
      --str_size;
      if (0 == str_size)
      {
        return 0;
      }
    }
    
    size_t count = snprintf(char_ptr, str_size, "%c", c);
    char_ptr += count;
    str_size -= count;
    
    if (printer->format.char_char_end)
    {
      *char_ptr = printer->format.char_char_end;
      ++char_ptr;
      --str_size;
      if (0 == str_size)
      {
        return 0;
      }
    }
    
    return char_ptr - str;  
  }
  else
  {
    unsigned char u = c;
    return snprintf(str, str_size, "'\\%03o'", u);    
  }
}




size_t sacs_snprintf_enum(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const void* value, size_t value_size)
{
  assert(printer);  
  assert(str);
  assert(str_size);
  assert(value);
  assert(value_size);  
  
  switch (value_size)
  {
    case 1:
    {
      const uint8_t* ptr = (uint8_t*) value;
      const long long_value = *ptr;
      
      return sacs_snprintf_long(printer, str, str_size, &long_value, sizeof(long_value));      
    } break;
    
    case 2:
    {  
      const uint16_t* ptr = (uint16_t*) value;
      const long long_value = *ptr;
      
      return sacs_snprintf_long(printer, str, str_size, &long_value, sizeof(long_value));      
    } break;
    
    case 4:
    {
      const uint32_t* ptr = (uint32_t*) value;
      const long long_value = *ptr;
      
      return sacs_snprintf_long(printer, str, str_size, &long_value, sizeof(long_value)); 
    } break;
    
    case 8:
    {
      const uint64_t* ptr = (uint64_t*) value;
      const long long_value = *ptr;
      
      return sacs_snprintf_long(printer, str, str_size, &long_value, sizeof(long_value)); 
    } break;
  }
  
  return 0;
}




size_t sacs_snprintf_int(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const void* value, size_t value_size)
{
  assert(printer);
  assert(str);
  assert(str_size);
  assert(value);
  assert(value_size);
  
  const int* int_value = (const int*) value;
  
  return snprintf(str, str_size, "%i", *int_value);
}




size_t sacs_snprintf_int_array(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const void* value, size_t value_size)
{
  assert(printer);  
  assert(str);
  assert(str_size);
  assert(value);
  assert(value_size);
  
  return sacs_snprintf_array(printer, str, str_size, value, value_size, sizeof(int), sacs_snprintf_int);
}




size_t sacs_snprintf_long(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const void* value, size_t value_size)
{
  assert(printer);  
  assert(str);
  assert(str_size);
  assert(value);
  assert(value_size);
  
  const long* long_value = (const long*) value;
  
  return snprintf(str, str_size, "%li", *long_value);
}




size_t sacs_snprintf_long_array(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const void* value, size_t value_size)
{
  assert(printer);  
  assert(str);
  assert(str_size);
  assert(value);
  assert(value_size);
  
  return sacs_snprintf_array(printer, str, str_size, value, value_size, sizeof(long), sacs_snprintf_long);
}




size_t sacs_snprintf_unsigned_long(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const void* value, size_t value_size)
{
  assert(str);
  assert(str_size);
  assert(value);
  assert(value_size);  
  
  const unsigned long* unsigned_long_value = (const unsigned long*) value;
  
  return snprintf(str, str_size, "%lu", *unsigned_long_value);  
}




size_t sacs_snprintf_unsigned_long_array(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const void* value, size_t value_size)
{
  assert(str);
  assert(str_size);
  assert(value);
  assert(value_size);
  
  return sacs_snprintf_array(printer, str, str_size, value, value_size, sizeof(unsigned long), sacs_snprintf_unsigned_long);
}




size_t sacs_snprintf_double(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const void* value, size_t value_size)
{
  assert(str);
  assert(str_size);
  assert(value); 
  assert(value_size);  
  
  const double* double_value = (const double*) value;
  
  return snprintf(str, str_size, "%f", *double_value);  
}




size_t sacs_snprintf_double_array(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const void* value, size_t value_size)
{
  assert(str);
  assert(str_size);
  assert(value);
  assert(value_size);  
  
  return sacs_snprintf_array(printer, str, str_size, value, value_size, sizeof(double), sacs_snprintf_double);
}




size_t sacs_snprintf_float(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const void* value, size_t value_size)
{
  assert(str);
  assert(str_size);
  assert(value); 
  assert(value_size);  
  
  const float* float_value = (const float*) value;
  
  return snprintf(str, str_size, "%f", *float_value);  
}




size_t sacs_snprintf_float_array(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const void* value, size_t value_size)
{
  assert(str);
  assert(str_size);
  assert(value);
  assert(value_size);  
  
  return sacs_snprintf_array(printer, str, str_size, value, value_size, sizeof(float), sacs_snprintf_float);
}




size_t sacs_snprintf_char_string(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const void* value, size_t value_size)
{
  assert(str);
  assert(str_size);
  assert(value);
  assert(value_size);  
  
  const char* string_value = (const char*) value;
  
  return snprintf(str, str_size, "\"%s\"", string_value);   
}




size_t sacs_snprintf_uint8(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const void* value, size_t value_size)
{
  assert(str);
  assert(str_size);
  assert(value);
  assert(value_size);  
  
  const uint8_t* uint8_value = (const uint8_t*) value;
  
  return snprintf(str, str_size, "0x%02X", *uint8_value);
}




size_t sacs_snprintf_uint8_array(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const void* value, size_t value_size)
{
  assert(str);
  assert(str_size);
  assert(value);
  assert(value_size);
  
  return sacs_snprintf_array(printer, str, str_size, value, value_size, sizeof(uint8_t), sacs_snprintf_uint8);
}




size_t sacs_snprintf_uint16(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const void* value, size_t value_size)
{
  assert(str);
  assert(str_size);
  assert(value);
  assert(value_size);  
  
  const uint16_t* uint16_value = (const uint16_t*) value;
  
  return snprintf(str, str_size, "0x%04X", *uint16_value);  
}




size_t sacs_snprintf_uint16_array(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const void* value, size_t value_size)
{
  assert(str);
  assert(str_size);
  assert(value);
  assert(value_size);
  
  return sacs_snprintf_array(printer, str, str_size, value, value_size, sizeof(uint16_t), sacs_snprintf_uint16);
}




size_t sacs_snprintf_uint32(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const void* value, size_t value_size)
{
  assert(str);
  assert(str_size);
  assert(value);
  assert(value_size);  
  
  const uint32_t* uint32_value = (const uint32_t*) value;
  
//  return snprintf(str, str_size, "0x%08X", *uint32_value);
  return snprintf(str, str_size, printer->format.str_uint32_format, *uint32_value);
}




size_t sacs_snprintf_uint32_array(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const void* value, size_t value_size)
{
  assert(str);
  assert(str_size);
  assert(value);
  assert(value_size);
  
  return sacs_snprintf_array(printer, str, str_size, value, value_size, sizeof(uint32_t), sacs_snprintf_uint32);
}




size_t sacs_snprintf_int32(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const void* value, size_t value_size)
{
  assert(str);
  assert(str_size);
  assert(value);
  assert(value_size);  
  
  const int32_t* int32_value = (const int32_t*) value;
  
  return snprintf(str, str_size, "%i", *int32_value);   
}




size_t sacs_snprintf_int32_array(struct SacsStructSnprintfer* printer, char* str, size_t str_size, const void* value, size_t value_size)
{
  assert(str);
  assert(str_size);
  assert(value);
  assert(value_size);
  
  return sacs_snprintf_array(printer, str, str_size, value, value_size, sizeof(int32_t), sacs_snprintf_int32);
}
