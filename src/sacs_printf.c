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




size_t sacs_printf_array(struct SacsStructPrintfer* printer, const void* value, size_t value_size, size_t element_size, SacsPrintfFieldCallback_t print_function)
{
  assert(value);  
  assert(value_size);
  assert(element_size);
  assert(print_function);
  
  size_t file_count = 0;
  file_count += fprintf(stdout, "{");
  
  size_t array_count = value_size / element_size;
  
  do
  {
    file_count += print_function(value, element_size);  
    
    value += element_size;
    
    file_count += fprintf(stdout, ",");
    
  } while (--array_count);
  
  file_count += fprintf(stdout, "}"); 
  
  return file_count;  
}




static size_t sacs_printf_field_name(const char* field_name)
{
  assert(field_name);
  
  size_t count = printf(".%s", field_name);
  
  return count;
}




size_t sacs_printf_partial(struct SacsStructPrintfer* printer)
{
  assert(printer);
  
  return sacs_fprintf_partial(stdout, &printer->fprinter);
}




size_t sacs_printf(struct SacsStructPrintfer* printer)
{
  assert(printer);
  
  size_t count = printf("{");
  
  // may have data
  count += sacs_printf_partial(printer);
  
  count += printf("}");
  
  return count;
}




size_t sacs_printf_bool(struct SacsStructPrintfer* printer, const void* value, size_t value_size)
{
  assert(printer);
  
  return sacs_fprintf_bool(&printer->fprinter, stdout, value, value_size); 
}




size_t sacs_printf_char(struct SacsStructPrintfer* printer, const void* value, size_t value_size)
{
  return sacs_fprintf_char(&printer->fprinter, stdout, value, value_size); 
}




size_t sacs_printf_enum(struct SacsStructPrintfer* printer, const void* value, size_t value_size)
{
  return sacs_fprintf_enum(&printer->fprinter, stdout, value, value_size); 
}




size_t sacs_printf_int(struct SacsStructPrintfer* printer, const void* value, size_t value_size)
{
  return sacs_fprintf_int(&printer->fprinter, stdout, value, value_size); 
}




size_t sacs_printf_int_array(struct SacsStructPrintfer* printer, const void* value, size_t value_size)
{
  return sacs_fprintf_int_array(&printer->fprinter, stdout, value, value_size); 
}




size_t sacs_printf_long(struct SacsStructPrintfer* printer, const void* value, size_t value_size)
{
  return sacs_fprintf_long(&printer->fprinter, stdout, value, value_size); 
}




size_t sacs_printf_long_array(struct SacsStructPrintfer* printer, const void* value, size_t value_size)
{
  return sacs_fprintf_long_array(&printer->fprinter, stdout, value, value_size); 
}




size_t sacs_printf_unsigned_long(struct SacsStructPrintfer* printer, const void* value, size_t value_size)
{
  return sacs_fprintf_unsigned_long(&printer->fprinter, stdout, value, value_size);  
}




size_t sacs_printf_unsigned_long_array(struct SacsStructPrintfer* printer, const void* value, size_t value_size)
{
  return sacs_fprintf_unsigned_long_array(&printer->fprinter, stdout, value, value_size);  
}




size_t sacs_printf_double(struct SacsStructPrintfer* printer, const void* value, size_t value_size)
{
  return sacs_fprintf_double(&printer->fprinter, stdout, value, value_size);   
}




size_t sacs_printf_double_array(struct SacsStructPrintfer* printer, const void* value, size_t value_size)
{
  return sacs_fprintf_double_array(&printer->fprinter, stdout, value, value_size);   
}




size_t sacs_printf_float(struct SacsStructPrintfer* printer, const void* value, size_t value_size)
{
  return sacs_fprintf_float(&printer->fprinter, stdout, value, value_size);   
}




size_t sacs_printf_float_array(struct SacsStructPrintfer* printer, const void* value, size_t value_size)
{
  return sacs_fprintf_float_array(&printer->fprinter, stdout, value, value_size);   
}




size_t sacs_printf_char_string(struct SacsStructPrintfer* printer, const void* value, size_t value_size)
{
  return sacs_fprintf_char_string(&printer->fprinter, stdout, value, value_size);   
}




size_t sacs_printf_uint8(struct SacsStructPrintfer* printer, const void* value, size_t value_size)
{
  return sacs_fprintf_uint8(&printer->fprinter, stdout, value, value_size); 
}




size_t sacs_printf_uint8_array(struct SacsStructPrintfer* printer, const void* value, size_t value_size)
{
  return sacs_fprintf_uint8_array(&printer->fprinter, stdout, value, value_size); 
}




size_t sacs_printf_uint16(struct SacsStructPrintfer* printer, const void* value, size_t value_size)
{
  return sacs_fprintf_uint16(&printer->fprinter, stdout, value, value_size); 
}




size_t sacs_printf_uint16_array(struct SacsStructPrintfer* printer, const void* value, size_t value_size)
{
  return sacs_fprintf_uint16_array(&printer->fprinter, stdout, value, value_size); 
}




size_t sacs_printf_uint32(struct SacsStructPrintfer* printer, const void* value, size_t value_size)
{
  return sacs_fprintf_uint32(&printer->fprinter, stdout, value, value_size);
}




size_t sacs_printf_uint32_array(struct SacsStructPrintfer* printer, const void* value, size_t value_size)
{
  return sacs_fprintf_uint32_array(&printer->fprinter, stdout, value, value_size); 
}




size_t sacs_printf_int32(struct SacsStructPrintfer* printer, const void* value, size_t value_size)
{ 
  return sacs_fprintf_int32(&printer->fprinter, stdout, value, value_size);  
}




size_t sacs_printf_int32_array(struct SacsStructPrintfer* printer, const void* value, size_t value_size)
{ 
  return sacs_fprintf_int32_array(&printer->fprinter, stdout, value, value_size);  
}
