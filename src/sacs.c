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
#include "sacs_util.h"

#include <assert.h>
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>


#ifdef SACS_USE_PARSE
  #include "sacs_parse.c"
#endif

#ifdef SACS_USE_FPRINTF
  #include "sacs_fprintf.c"
#endif


#ifdef SACS_USE_FPRINTF
  #include "sacs_printf.c"
#endif


#ifdef SACS_USE_SNPRINTF
  #include "sacs_snprintf.c"
#endif


#ifdef SACS_USE_JSON
  #include "sacs_json.c"
#endif


#ifdef SACS_USE_XML
 #include "sacs_xml.c"
#endif







size_t sacs_snprettyf(char* dest, size_t dest_size, const char* src, size_t src_size)
{
  assert(dest);
  assert(dest_size);
  assert(src);
  assert(src_size);
  
  size_t indent = 0;
  
  char* dest_char = dest;
  const char* src_char = src;
  
  do 
  {
    // get the value
    char c = *src_char;
    
    if ('\0' == c)
    {
      break;
    }

    else if (SACS_CHAR_RIGHT_BRACE == c)
    {
      --indent;
    }    
    
    ++src_char;
    
//    if (SACS_CHAR_FIELD_VALUE_SEPARATOR == c)
//    {
//      *dest_char = '\t';
//      
//      --dest_size;
//      if (!dest_size)
//      {
//        break;
//      }
//      else
//      {
//        ++dest_char;
//      }
//    }
//    else if ('}' == *src_char)
//    {
//      --indent;
//    }    
    
    // copy the value
    *dest_char = c;
    
    --dest_size;
    if (!dest_size)
    {
      break;
    }
    else
    {
      ++dest_char;
    }
    
    if (SACS_CHAR_FIELD_SEPARATOR == c)
    {
      *dest_char = '\n';
      
      --dest_size;
      if (!dest_size)
      {
        break;
      }
      else
      {
        ++dest_char;
      }
      
      // indent
      for (size_t i = 0; i < indent; ++i)
      {
        *dest_char = '\t';
        
        --dest_size;
        if (!dest_size)
        {
          break;
        }
        else
        {
          ++dest_char;
        }        
      }      
    }
    else if (SACS_CHAR_LEFT_BRACE == c)
    {
      ++indent;
      
      *dest_char = '\n';
      
      --dest_size;
      if (!dest_size)
      {
        break;
      }
      else
      {
        ++dest_char;
      }
      
      // indent
      for (size_t i = 0; i < indent; ++i)
      {
        *dest_char = '\t';
        
        --dest_size;
        if (!dest_size)
        {
          break;
        }
        else
        {
          ++dest_char;
        }        
      }
    }

    
//    else if (SACS_CHAR_FIELD_VALUE_SEPARATOR == c)
//    {
//      *dest_char = '\t';
//      
//      --dest_size;
//      if (!dest_size)
//      {
//        break;
//      }
//      else
//      {
//        ++dest_char;
//      }
//    }    
    
  } while(--src_size);
  
  *dest_char = '\0';  
  
  return dest_char - dest;
}




size_t sacs_sncompact(char* dest, size_t dest_size, const char* src, size_t src_size)
{
  assert(dest);
  assert(dest_size);
  assert(src);
  assert(src_size);
  
  bool in_quotes = false;
  const char* dest_start = dest;
  
  do
  {
    if (!dest_size)
      break;
    
    const char c = *src;
    
    if ('"' == c)
    {
      in_quotes = !in_quotes;
    }
    
    if (in_quotes || !isspace(*src))
    {
      *dest = c;
      ++dest;
      --dest_size;
    }

    ++src;
    
  } while(--src_size);
  
  return dest - dest_start;
}




size_t sacs_snbintohex(char* dest, size_t dest_size, void* src, size_t src_size)
{
  assert(dest);
  assert(dest_size);
  assert(src);
  assert(src_size);
  
  const char* dest_start = dest;
  
  const uint8_t* src_ptr = (uint8_t*) src;
  
  do
  {
    if (!dest_size)
      break;
    
    const unsigned value = *src_ptr;
    const size_t count = snprintf(dest, dest_size, "%02X", value);
    
    dest += count;
    dest_size -= count;
    
    ++src_ptr;

  } while(--src_size);
  
  return dest - dest_start;
}



