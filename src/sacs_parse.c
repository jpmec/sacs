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
#include "sacs_const.h"

#include <assert.h>
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>







static size_t sacs_skip_isspace(const char* str)
{
  assert(str);
  
  const char* char_ptr = str;
  
  while (isspace(*char_ptr))
  {
    ++char_ptr;
  }
  
  return char_ptr - str;
}




static size_t sacs_skip_char(const char* str, char c)
{
  assert(str);
  
  const char* char_ptr = str;
  
  size_t count = sacs_skip_isspace(char_ptr);
  
  if (count)
  {
    char_ptr += count;
  }
  
  
  if (c == *char_ptr)
  {
    ++char_ptr;
  }
  
  
  count = sacs_skip_isspace(char_ptr);
  
  if (count)
  {
    char_ptr += count;
  }
  
  return char_ptr - str;
}




static size_t sacs_skip_field(struct SacsStructParser* parser, const char* str)
{
  assert(parser);
  assert(str);
  
  size_t indent = 0;
  const char* char_ptr = str;
  
  while ((char_ptr != '\0'))
  {
    char c = *char_ptr;

    ++char_ptr;
    
    if (parser->format.char_struct_begin == c)
    {
      ++indent;
    }
    
    if (0 == indent)
    {
      if (c == parser->format.char_field_separator)
      {
        break;
      }
      else if (parser->format.char_struct_end == c) 
      {
        break;
      }
    }
    else
    {
      if (parser->format.char_struct_end == c) 
      {
        --indent;
      }      
    }
  }
  
  return char_ptr - str;  
}




static size_t sacs_parse_array_begin(struct SacsStructParser* parser, const char* str)
{
  assert(parser);
  assert(str);
  
  return sacs_skip_char(str, parser->format.char_array_begin);
}




static size_t sacs_parse_array_end(struct SacsStructParser* parser, const char* str)
{
  assert(parser);
  assert(str);
  
  return sacs_skip_char(str, parser->format.char_array_end);
}




size_t sacs_parse_array(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str, size_t element_size, SacsParseFieldCallback_t parse_function)
{
  assert(dest);
  assert(dest_size);
  assert(element_size);
  assert(str);
  
  const char* char_ptr = str;
  
  size_t array_count = dest_size / element_size;
  
  size_t count = sacs_parse_array_begin(parser, char_ptr);
  
  if (0 < count)
  {
    char_ptr += count;
  }
  else
  {
    return 0;
  }
  
  do
  {
    count = parse_function(parser, dest, element_size, char_ptr);
    
    if (count)
    {
      char_ptr += count;
      dest += element_size;
      
      count = sacs_skip_char(char_ptr, parser->format.char_field_separator);
      char_ptr += count;
    }
  } while (--array_count);
  
  count = sacs_parse_array_end(parser, char_ptr);
  
  if (0 < count)
  {
    char_ptr += count;
  }
  else
  {
    return 0;
  }
  
  return char_ptr - str; 
}




static size_t sacs_parse_type_name(struct SacsStructParser* parser, const char* str)
{
  assert(parser);
  assert(str);
  
  const char* char_ptr = str;
  
  size_t count = sacs_skip_isspace(char_ptr);
  
  if (count)
  {
    char_ptr += count;
  }
  
  if ('(' == *char_ptr)
  {
    ++char_ptr;
  }
  else
  {
    return 0;
  }
  
  if (0 == strncmp(char_ptr, "struct ", 7))
  {
    char_ptr += 7;
  }
  
  if (isalpha(*char_ptr))
  {
    ++char_ptr;
    
    while (isalnum(*char_ptr))
    {
      ++char_ptr;      
    }
  }
  else
  {
    return 0;
  }
  
  if (')' == *char_ptr)
  {
    ++char_ptr;    
  }
  else
  {
    return 0;
  }
  
  count = sacs_skip_isspace(char_ptr);
  
  if (count)
  {
    char_ptr += count;
  }  
  
  return char_ptr - str;
}




size_t sacs_parse_bool(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str)
{
  assert(dest);
  assert(dest_size);
  assert(str);
  
  const char* char_ptr = str;
  
  bool b = false;
  
  if (*char_ptr == '1')
  {
    b = true;
    ++char_ptr;
  }
  else if (*char_ptr == '0')
  {
    const size_t len = sacs_skip_field(parser, str);
    if (len > 2)
    {
      b = true;
    }
    char_ptr += len;
  }  
  else if (0 == strncmp(char_ptr, "true", 4))
  {
    b = true;
    char_ptr += 4;
  }
  else if (0 == strncmp(char_ptr, "false", 5))
  {
    char_ptr += 5;
  }
  else
  {
    const size_t len = sacs_skip_field(parser, str);
    if (len > 1)
    {
      b = true;
    }
    char_ptr += len;
  }

  bool* dest_ptr = (bool*) dest;
  
  *dest_ptr = b;
  
  return char_ptr - str;
}




size_t sacs_parse_char(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str)
{
  assert(dest);
  assert(dest_size);
  assert(str);
  
  const char* char_ptr = str;
  
  size_t count = sacs_skip_char(char_ptr, SACS_CHAR_SINGLE_QUOTE);
  
  if (count)
  {
    char_ptr += count;
    
    char c = *char_ptr;
    
    // handle escape characters
    if (SACS_CHAR_BACKSLASH == c)
    {
      ++char_ptr;
      
      c = * char_ptr;
      
      switch (c)
      {
        case SACS_CHAR_BACKSLASH:
        {
          c = SACS_CHAR_BACKSLASH;
        } break;
          
        case SACS_CHAR_DOUBLE_QUOTE:
        {
          c = SACS_CHAR_DOUBLE_QUOTE;
        } break;   
          
        case SACS_CHAR_SINGLE_QUOTE:
        {
          c = SACS_CHAR_SINGLE_QUOTE;
        } break;
          
        case SACS_CHAR_QUESTION:
        {
          c = SACS_CHAR_QUESTION;
        } break;          
          
        case '0':
        {
          c = 0;
        } break;
          
        case 'a':
        {
          c = SACS_CHAR_BELL_ALERT;
        } break;
        
        case 'b':
        {
          c = SACS_CHAR_BACKSPACE;
        } break;

        case 'f': 
        {
          c = SACS_CHAR_FORMFEED;
        } break;
          
        case 'n':
        {
          c = SACS_CHAR_NEWLINE;
        } break;
          
        case 'r':
        {
          c = SACS_CHAR_RETURN;
        } break;
          
        case 't':
        {
          c = SACS_CHAR_TAB;
        } break;
          
        case 'v':
        {
          c = SACS_CHAR_VTAB;
        } break;
          
        default:
          return 0; // bad format
      }
    }
    
    ++char_ptr;
    
    count = sacs_skip_char(char_ptr, SACS_CHAR_SINGLE_QUOTE);
    
    if (count)
    {
      char_ptr += count;
    }
    
    char* dest_ptr = (char*) dest;
    
    *dest_ptr = c;
    
    return char_ptr - str;
  }
  
  else if ((0 == count) && isdigit(*str))
  {
    int i = 0;
    count = sacs_parse_int(parser, &i, sizeof(i), str);
    
    if (count)
    {
      char* char_value_ptr = dest;
      *char_value_ptr = (char) i;
      
      char_ptr += count;        
    }
    
    return char_ptr - str;
  }
    
  return 0;
}




size_t sacs_parse_char_array(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str)
{
  assert(dest);
  assert(dest_size);
  assert(str);
  
  return sacs_parse_array(parser, dest, dest_size, str, sizeof(char), sacs_parse_char);
}




size_t sacs_parse_char_string(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str)
{
  assert(dest);
  assert(dest_size);
  assert(str);
  
  const char* char_ptr = str;
  char* dest_ptr = (char*) dest;
  
  size_t count = sacs_skip_char(char_ptr, SACS_CHAR_DOUBLE_QUOTE);
  
  if (count)
  {
    char_ptr += count;
    
    char c = 0;
    do
    {
      c = *char_ptr;
      
      if (SACS_CHAR_DOUBLE_QUOTE == c)
      {
        break;
      }
      
      *dest_ptr = c;
      
      ++dest_ptr;
      ++char_ptr;
      
    } while (c);
    
    
    count = sacs_skip_char(char_ptr, SACS_CHAR_DOUBLE_QUOTE);  
    
    if (count)
    {
      char_ptr += count;
    }    
  }
  
  
  if (0 == count)
  {
    count = sacs_skip_char(char_ptr, parser->format.char_array_begin);
    
    if (count)
    {
      count = sacs_parse_char_array(parser, dest, dest_size, char_ptr);
      char_ptr += count;
    }
  }
  
  return char_ptr - str;
}




size_t sacs_parse_double(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str)
{
  assert(dest);
  assert(dest_size);
  assert(str);
  
  const char* char_ptr = str;
  
  size_t count = sacs_skip_isspace(char_ptr);
  
  if (count)
  {
    char_ptr += count;
  }
  
  // check for hex
  char* end_ptr = 0;
  double value = strtod(char_ptr, &end_ptr);
  
  if (end_ptr)
  {
    count = end_ptr - char_ptr;
    char_ptr += count;
    
    double* double_ptr = dest;
    *double_ptr = value;
  }
  
  count = sacs_skip_isspace(char_ptr);
  
  if (count)
  {
    char_ptr += count;
  }
  
  return char_ptr - str;
}




size_t sacs_parse_double_array(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str)
{
  assert(dest);
  assert(dest_size);
  assert(str);
  
  return sacs_parse_array(parser, dest, dest_size, str, sizeof(double), sacs_parse_double);
}




size_t sacs_parse_enum(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str)
{
  assert(dest);
  assert(dest_size);
  assert(str);
  
  const char* char_ptr = str;
  
  if (isalpha(*char_ptr))
  {
    // parse the string
    // TODO
    
  }
  else if (isdigit(*char_ptr))
  {
    long temp_long = 0;
    
    // parse the number
    size_t count = sacs_parse_long(parser, &temp_long, sizeof(temp_long), str);
    char_ptr += count;
    
    // convert to enum
    switch (dest_size)
    {
      case 1:
      {
        uint8_t* ptr = (uint8_t*) dest;
        *ptr = temp_long & 0xFF;
      } break;
        
      case 2:
      {
        uint16_t* ptr = (uint16_t*) dest;
        *ptr = temp_long & 0xFFFF;
      } break;

      case 4:
      {
        uint32_t* ptr = (uint32_t*) dest;
        *ptr = temp_long & 0xFFFFFFFF;
      } break; 

      case 8:
      {
        uint64_t* ptr = (uint64_t*) dest;
        *ptr = temp_long & 0xFFFFFFFFFFFFFFFF;
      } break;
    }
  }
    
  return char_ptr - str;
}




size_t sacs_parse_int(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str)
{
  assert(dest);
  assert(dest_size);
  assert(str);
  
  const char* char_ptr = str;
  
  size_t count = sacs_skip_isspace(char_ptr);
  
  if (count)
  {
    char_ptr += count;
  }
  
  // reset value count
  count = 0;

  if (('0' == str[0]) )
  {
    int base = 10;
    
    switch (str[1])
    {
      case 'x': base = 16; break;
      case 'b': 
      {
        base = 2;
        char_ptr += 2;
      } break; 
    }
    
    // try to convert hexadecimal
    char* end_ptr = 0;
    long value = strtol(char_ptr, &end_ptr, base);
    
    if (end_ptr)
    {
      count = end_ptr - char_ptr;
      char_ptr += count;
      
      int* long_ptr = dest;
      *long_ptr = (int) value;
    }
  }  
  
  if (0 == count)
  {
    // try to convert decimal
    char* end_ptr = 0;
    long value = strtol(char_ptr, &end_ptr, 10);
  
    if (end_ptr)
    {
      count = end_ptr - char_ptr;
      char_ptr += count;
    
      int* long_ptr = dest;
      *long_ptr = (int) value;
    }
  }
  
  if (0 == count)
  {
    char c = 0;
    count = sacs_parse_char(parser, &c, sizeof(c), str);
    
    if (count)
    {
      int* long_ptr = dest;
      *long_ptr = (int) c;
      
      char_ptr += count;        
    }
  }
  
  if (0 == count)
  {
    count = sacs_skip_field(parser, str);
    char_ptr += count;
  }
  
  count = sacs_skip_isspace(char_ptr);
  
  if (count)
  {
    char_ptr += count;
  }
  
  return char_ptr - str;
}




size_t sacs_parse_int_array(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str)
{
  assert(dest);
  assert(dest_size);
  assert(str);
  
  return sacs_parse_array(parser, dest, dest_size, str, sizeof(int), sacs_parse_int);
}




size_t sacs_parse_long(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str)
{
  assert(dest);
  assert(dest_size);
  assert(str);
  
  const char* char_ptr = str;
  
  size_t count = sacs_skip_isspace(char_ptr);
  
  if (count)
  {
    char_ptr += count;
  }
  
  // check for hex
  char* end_ptr = 0;
  long value = strtol(char_ptr, &end_ptr, 10);
  
  if (end_ptr)
  {
    count = end_ptr - char_ptr;
    char_ptr += count;
    
    long* long_ptr = dest;
    *long_ptr = value;
  }
  
  count = sacs_skip_isspace(char_ptr);
  
  if (count)
  {
    char_ptr += count;
  }
  
  return char_ptr - str;
}




size_t sacs_parse_long_array(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str)
{
  assert(dest);
  assert(dest_size);
  assert(str);
  
  return sacs_parse_array(parser, dest, dest_size, str, sizeof(long), sacs_parse_long);
}




size_t sacs_parse_unsigned_long(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str)
{
  assert(dest);
  assert(dest_size);
  assert(str);
  
  const char* char_ptr = str;
  
  size_t count = sacs_skip_isspace(char_ptr);
  
  if (count)
  {
    char_ptr += count;
  }
  
  // check for hex
  char* end_ptr = 0;
  unsigned long value = 0;
  
  if (0 == strncmp("0x", char_ptr, 2))
  {
    value = strtoul(char_ptr, &end_ptr, 16);  // hexadecimal conversion
  }
  else
  {
    value = strtoul(char_ptr, &end_ptr, 10);  // decimal conversion
  }
  
  if (end_ptr)
  {
    count = end_ptr - char_ptr;
    char_ptr += count;
    
    unsigned long* unsigned_long_ptr = dest;
    *unsigned_long_ptr = value;
  }
  
  count = sacs_skip_isspace(char_ptr);
  
  if (count)
  {
    char_ptr += count;
  }
  
  return char_ptr - str;
}




size_t sacs_parse_unsigned_long_array(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str)
{
  assert(dest);
  assert(dest_size);
  assert(str);
  
  return sacs_parse_array(parser, dest, dest_size, str, sizeof(unsigned long), sacs_parse_unsigned_long);
}




size_t sacs_parse_uint8(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str)
{
  assert(dest);
  assert(dest_size);
  assert(str);
  
  unsigned long result = 0;
  size_t count = sacs_parse_unsigned_long(parser, &result, sizeof(result), str);
  
  if (count)
  {
    if (result > UINT8_MAX)
    {
      return 0;
    }    
    
    uint8_t* uint8_ptr = (uint8_t*) dest;
    *uint8_ptr = 0xFF & result;
  }
  
  return count;
}




size_t sacs_parse_uint8_array(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str)
{
  assert(dest);
  assert(dest_size);
  assert(str);
  
  return sacs_parse_array(parser, dest, dest_size, str, sizeof(uint8_t), sacs_parse_uint8);
}




size_t sacs_parse_uint16(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str)
{
  assert(dest);
  assert(dest_size);
  assert(str);
  
  unsigned long result = 0;
  size_t count = sacs_parse_unsigned_long(parser, &result, sizeof(result), str);
  
  if (count)
  {
    if (result > UINT16_MAX)
    {
      return 0;
    }    
    
    uint16_t* uint16_ptr = (uint16_t*) dest;
    *uint16_ptr = 0xFFFF & result;
  }
  
  return count;
}




size_t sacs_parse_uint32(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str)
{
  assert(dest);
  assert(dest_size);
  assert(str);
  
  unsigned long result = 0;
  size_t count = sacs_parse_unsigned_long(parser, &result, sizeof(result), str);
  
  if (count)
  {
    if (result > UINT32_MAX)
    {
      return 0;
    }    
    
    uint32_t* uint32_ptr = (uint32_t*) dest;
    *uint32_ptr = 0xFFFFFFFF & result;
  }
  
  return count;
}




size_t sacs_parse_uint32_array(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str)
{
  assert(dest);
  assert(dest_size);
  assert(str);
  
  return sacs_parse_array(parser, dest, dest_size, str, sizeof(uint32_t), sacs_parse_uint32);
}




size_t sacs_parse_int32(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str)
{
  assert(dest);
  assert(dest_size);
  assert(str);
  
  long result = 0;
  size_t count = sacs_parse_long(parser, &result, sizeof(result), str);
  
  if (count)
  {
    if (result > INT32_MAX)
    {
      return 0;
    }
    
    int32_t* int32_ptr = (int32_t*) dest;
    *int32_ptr = result;
  }
  
  return count;
}




size_t sacs_parse_int32_array(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str)
{
  assert(dest);
  assert(dest_size);
  assert(str);
  
  return sacs_parse_array(parser, dest, dest_size, str, sizeof(int32_t), sacs_parse_int32);
}





size_t sacs_parse_float(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str)
{
  assert(dest);
  assert(dest_size);
  assert(str);
  
  const char* char_ptr = str;
  
  size_t count = sacs_skip_isspace(char_ptr);
  
  if (count)
  {
    char_ptr += count;
  }
  
  char* end_ptr = 0;
  const double double_value = strtod(char_ptr, &end_ptr);
  
  if (end_ptr)
  {
    count = end_ptr - char_ptr;
    char_ptr += count;
   
    const float float_value = (float) double_value;    
    float* float_ptr = dest;
    *float_ptr = float_value;
  }
  
  count = sacs_skip_isspace(char_ptr);
  
  if (count)
  {
    char_ptr += count;
  }
  
  return char_ptr - str;
}




size_t sacs_parse_float_array(struct SacsStructParser* parser, void* dest, size_t dest_size, const char* str)
{
  assert(dest);
  assert(dest_size);
  assert(str);
  
  return sacs_parse_array(parser, dest, dest_size, str, sizeof(float), sacs_parse_float);
}




static size_t sacs_parse_struct_begin(struct SacsStructParser* parser, const char* str)
{
  assert(parser);
  assert(str);
  
  return sacs_skip_char(str, parser->format.char_struct_begin);
}




static size_t sacs_parse_struct_end(struct SacsStructParser* parser, const char* str)
{
  assert(parser);
  assert(str);
  
  return sacs_skip_char(str, parser->format.char_struct_end);
}




static size_t sacs_parse_field_name(const char* field_name, const char* str)
{
  assert(field_name);
  assert(str);
  
  const char* char_ptr = str;
  
  size_t count = sacs_skip_char(char_ptr, '.');
  
  if (count)
  {
    char_ptr += count;
  }
  else
  {
    return 0;
  }
  
  while ('\0' != *field_name)
  {
    if (*field_name != *char_ptr)
    {
      return 0;
    }
    ++char_ptr;
    ++field_name;
  }
  
  return char_ptr - str;
}




static size_t sacs_parse_field(struct SacsStructParser* parser, const char* str)
{
  assert(parser);
  assert(str);
  
  if (parser->format.char_struct_end == *str)
  {
    return 0;
  }  
  
  const char* char_ptr = str;

  size_t count = 0;
  
  const struct SacsFieldParser* field_parser = NULL;
  
  for (size_t i = 0; i < parser->parsers_count; ++i)
  {
    const struct SacsFieldParser* temp_field_parser = &parser->parsers_array[i];
    
    count = sacs_parse_field_name(temp_field_parser->name, char_ptr);
    
    if (count)
    {
      field_parser = temp_field_parser;
      char_ptr += count;
      break;
    }
  }
  
  if (NULL == field_parser)
  {
    count = sacs_skip_field(parser, char_ptr);
    
    if (count)
    {
      char_ptr += count;
    }    
  }
  else
  {
    count = sacs_skip_char(char_ptr, parser->format.char_field_value_separator);
    
    if (count)
    {
      char_ptr += count;
    }
    else
    {
      return 0;
    }
    
    void* dest = parser->dest + field_parser->field_offset;
    count = field_parser->function(parser, dest, field_parser->field_size, char_ptr);
    
    if (count)
    {
      char_ptr += count;
    }
    else
    {
      return 0;
    }
  }
  
  count = sacs_skip_char(char_ptr, parser->format.char_field_separator);
  
  if (count)
  {
    char_ptr += count;
  }
  
  return char_ptr - str;
}




size_t sacs_parse_partial(struct SacsStructParser* parser, const char* str)
{
  assert(parser);
  assert(str);
  
  const char* char_ptr = str;
  
  size_t count = 0;
  do
  {
    count = sacs_parse_field(parser, char_ptr);
    
    if (count)
    {
      char_ptr += count;
    }
    
  } while (count);
  
  return char_ptr - str;
}




size_t sacs_parse(struct SacsStructParser* parser, const char* str)
{
  assert(parser);
  assert(str);
  
  if (SACS_PARSER_ERROR_NONE != parser->error)
  {
    return 0;
  }
  
  const char* char_ptr = str;
  
  // initialize the structure memory
  memset(parser->dest, 0, parser->dest_size);  
  
  // may have type name
  size_t count = sacs_parse_type_name(parser, char_ptr);
  
  if (count)
  {
    char_ptr += count;
  }
  
  // must have {
  count = sacs_parse_struct_begin(parser, char_ptr);
  
  if (count)
  {
    char_ptr += count;
  }
  else
  {
    parser->error = SACS_PARSER_ERROR_BAD_FORMAT;
    return 0;
  }
  
  // may have data
  count = sacs_parse_partial(parser, char_ptr);
  
  if (count)
  {
    char_ptr += count;
  }
  
  // must have }
  count = sacs_parse_struct_end(parser, char_ptr);
  
  if (count)
  {
    char_ptr += count;
  }
  else
  {
    parser->error = SACS_PARSER_ERROR_BAD_FORMAT;    
    return 0;
  }  
  
  
  // may have ;
  count = sacs_skip_char(char_ptr, ';');
  
  if (count)
  {
    char_ptr += count;
  }  
	
  // return number bytes processed
  return char_ptr - str;
}
