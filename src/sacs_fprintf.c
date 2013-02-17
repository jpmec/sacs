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




size_t sacs_fprintf_array(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size, size_t element_size, SacsFprintfFieldCallback_t print_function)
{
  assert(printer);
  assert(file);
  assert(value);  
  assert(value_size);
    
  size_t file_count = 0;
  file_count += fprintf(file, "%c", printer->format.char_array_begin);
  
  size_t array_count = value_size / element_size;
  
  do
  {
    file_count += print_function(printer, file, value, element_size);  
    
    value += element_size;
    
    file_count += fprintf(file, ",");
    
  } while (--array_count);
  
  file_count += fprintf(file, "%c", printer->format.char_array_end); 
  
  return file_count;  
}




static size_t sacs_fprintf_field_name(struct SacsStructFprintfer* printer, FILE* file, const char* field_name)
{
  assert(file);
  assert(field_name);
  
  size_t count = fprintf(file, ".%s", field_name);
  
  return count;
}




size_t sacs_fprintf_partial(FILE* file, struct SacsStructFprintfer* printer)
{
  assert(file);
  assert(printer);
  
  size_t count = 0;
  
  const struct SacsFieldFprintfer* field_printer = NULL;
  
  for (size_t i = 0; i < printer->printers_count; ++i)
  {
    field_printer = &printer->printers_array[i];
    
    if (printer->format.flags.print_field_name_before_value)
    {
      count += sacs_fprintf_field_name(printer, file, field_printer->name);
      count += printf("=");
    }
    
    const void* src = printer->src + field_printer->field_offset;
    count += field_printer->function(printer, file, src, field_printer->field_size);
    
    count += printf(",");
  }
  
  return count;
}




size_t sacs_fprintf(FILE* file, struct SacsStructFprintfer* printer)
{
  assert(file);
  assert(printer);
  
  size_t count = fprintf(file, "{");
  
  // may have data
  count += sacs_fprintf_partial(file, printer);
  
  count += fprintf(file, "}");
  
  return count;
}




size_t sacs_fprintf_bool(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size)
{
  assert(file);
  assert(value);
  assert(value_size);
  
  const bool* bool_value = (const bool*) value;
  
  if (*bool_value)
  {
    return fprintf(file, "true");
  }
  else
  {
    return fprintf(file, "false");    
  }
}




size_t sacs_fprintf_char(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size)
{
  assert(file);
  assert(value);
  assert(value_size);
    
  const char* char_value = (const char*) value;
  
  if (isgraph(*char_value))
  {
    return fprintf(file, "'%c'", *char_value);
  }
  else
  {
    return fprintf(file, "'\\%02X'", *char_value);    
  }
}




size_t sacs_fprintf_char_string(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size)
{
  assert(file);
  assert(value);
  assert(value_size);
  
  const char* string_value = (const char*) value;
  
  return fprintf(file, "\"%s\"", string_value);   
}




size_t sacs_fprintf_enum(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size)
{
  assert(file);
  assert(value);
  assert(value_size);
 
  switch (value_size)
  {
    case 1:
    {
      const uint8_t* ptr = (uint8_t*) value;
      const long long_value = *ptr;
      
      return sacs_fprintf_long(printer, file, &long_value, sizeof(long_value));      
    } break;
      
    case 2:
    {  
      const uint16_t* ptr = (uint16_t*) value;
      const long long_value = *ptr;
      
      return sacs_fprintf_long(printer, file, &long_value, sizeof(long_value));      
    } break;
      
    case 4:
    {
      const uint32_t* ptr = (uint32_t*) value;
      const long long_value = *ptr;
      
      return sacs_fprintf_long(printer, file, &long_value, sizeof(long_value)); 
    } break;
      
    case 8:
    {
      const uint64_t* ptr = (uint64_t*) value;
      const long long_value = *ptr;
      
      return sacs_fprintf_long(printer, file, &long_value, sizeof(long_value)); 
    } break;
  }
  
  return 0;
}




size_t sacs_fprintf_int(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size)
{
  assert(file);
  assert(value);
  assert(value_size);
  
  const int* int_value = (const int*) value;
  
  return fprintf(file, "%d", *int_value);
}




size_t sacs_fprintf_int_array(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size)
{
  assert(file);
  assert(value);  
  assert(value_size);
  
  return sacs_fprintf_array(printer, file, value, value_size, sizeof(int), sacs_fprintf_int);
}



size_t sacs_fprintf_long(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size)
{
  assert(file);
  assert(value);
  assert(value_size);
  
  const long* long_value = (const long*) value;
  
  return fprintf(file, "%li", *long_value);
}




size_t sacs_fprintf_long_array(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size)
{
  assert(file);
  assert(value);  
  assert(value_size);
  
  return sacs_fprintf_array(printer, file, value, value_size, sizeof(long), sacs_fprintf_long);
}




size_t sacs_fprintf_unsigned_long(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size)
{
  assert(file);
  assert(value); 
  assert(value_size);
  
  const unsigned long* unsigned_long_value = (const unsigned long*) value;
  
  return fprintf(file, "%lu", *unsigned_long_value);  
}




size_t sacs_fprintf_unsigned_long_array(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size)
{
  assert(file);
  assert(value);  
  assert(value_size);
  
  return sacs_fprintf_array(printer, file, value, value_size, sizeof(unsigned long), sacs_fprintf_unsigned_long);
}




size_t sacs_fprintf_double(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size)
{
  assert(file);
  assert(value);  
  assert(value_size);
  
  const double* double_value = (const double*) value;
  
  return fprintf(file, "%f", *double_value);  
}




size_t sacs_fprintf_double_array(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size)
{
  assert(file);
  assert(value);  
  assert(value_size);
  
  return sacs_fprintf_array(printer, file, value, value_size, sizeof(double), sacs_fprintf_double);
}




size_t sacs_fprintf_float(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size)
{
  assert(file);
  assert(value);  
  assert(value_size);
  
  const float* float_value = (const float*) value;
  
  return fprintf(file, "%f", *float_value);  
}




size_t sacs_fprintf_float_array(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size)
{
  assert(file);
  assert(value);  
  assert(value_size);
  
  return sacs_fprintf_array(printer, file, value, value_size, sizeof(float), sacs_fprintf_float);
}




size_t sacs_fprintf_uint8(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size)
{
  assert(file);
  assert(value);
  assert(value_size);
  
  const uint8_t* uint8_value = (const uint8_t*) value;
  
  return fprintf(file, "0x%02X", *uint8_value);
}




size_t sacs_fprintf_uint8_array(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size)
{
  assert(file);
  assert(value);  
  assert(value_size);
  
  return sacs_fprintf_array(printer, file, value, value_size, sizeof(uint8_t), sacs_fprintf_uint8);
}




size_t sacs_fprintf_uint16(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size)
{
  assert(file);
  assert(value);
  
  const uint16_t* uint16_value = (const uint16_t*) value;
  
  return fprintf(file, "0x%04X", *uint16_value);  
}




size_t sacs_fprintf_uint16_array(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size)
{
  assert(file);
  assert(value);  
  assert(value_size);
  
  return sacs_fprintf_array(printer, file, value, value_size, sizeof(uint16_t), sacs_fprintf_uint16);
}




size_t sacs_fprintf_uint32(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size)
{
  assert(file);
  assert(value);
  assert(value_size);
  
  const uint32_t* uint32_value = (const uint32_t*) value;
  
  return fprintf(file, "0x%08X", *uint32_value);  
}




size_t sacs_fprintf_uint32_array(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size)
{
  assert(file);
  assert(value);  
  assert(value_size);
  
  return sacs_fprintf_array(printer, file, value, value_size, sizeof(uint32_t), sacs_fprintf_uint32);
}




size_t sacs_fprintf_int32(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size)
{
  assert(file);
  assert(value);
  assert(value_size);
  
  const int32_t* int32_value = (const int32_t*) value;
  
  return fprintf(file, "%i", *int32_value);   
}




size_t sacs_fprintf_int32_array(struct SacsStructFprintfer* printer, FILE* file, const void* value, size_t value_size)
{
  assert(file);
  assert(value);  
  assert(value_size);
  
  return sacs_fprintf_array(printer, file, value, value_size, sizeof(int32_t), sacs_fprintf_int32);
}

