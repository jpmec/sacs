/** sacs_json.c
 
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






size_t sacs_ctojson(char* dest, size_t dest_size, const char* src, size_t src_size)
{
  assert(dest);
  assert(dest_size);
  assert(src);
  assert(src_size);
  
  bool expect_dot = false;
  
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
    
    ++src_char;
    
    // handle special characters
    if (expect_dot && ('.' == c))
    {
      expect_dot = false;
      continue;
    }
    
    
    // copy the value
    *dest_char = c;
    
    
    // increment destination
    --dest_size;
    if (!dest_size)
    {
      break;
    }
    else
    {
      ++dest_char;
    }
    
    
    // handle special characters
    if (SACS_CHAR_FIELD_VALUE_SEPARATOR == c)
    {
      char* prev = dest_char - 1;
      *prev = ':';
    }   
    
    else if (SACS_CHAR_FIELD_SEPARATOR == c)
    {
      expect_dot = true;
    }
    
    else if (SACS_CHAR_STRUCT_BEGIN == c)
    {
      expect_dot = true;
    }
    
    else if (SACS_CHAR_STRUCT_END == c)
    {
      expect_dot = false;
    }    
    
  } while(--src_size);
  
  *dest_char = '\0';  
  
  return dest_char - dest;
}




size_t sacs_jsontoc(char* dest, size_t dest_size, const char* src, size_t src_size)
{
  assert(dest);
  assert(dest_size);
  assert(src);
  assert(src_size);
  
  bool need_dot = false;
  
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
    
    ++src_char;
    
    // handle special characters
    if (need_dot && isalpha(c))
    {
      // copy the value
      *dest_char = '.';
      
      // increment destination
      --dest_size;
      if (!dest_size)
      {
        break;
      }
      else
      {
        ++dest_char;
      }
      
      need_dot = false;
    }
    
    
    // copy the value
    *dest_char = c;
    
    
    // increment destination
    --dest_size;
    if (!dest_size)
    {
      break;
    }
    else
    {
      ++dest_char;
    }
    
    
    // handle special characters
    if (':' == c)
    {
      char* prev = dest_char - 1;
      *prev = SACS_CHAR_FIELD_VALUE_SEPARATOR;
    }   
    
    else if (SACS_CHAR_FIELD_SEPARATOR == c)
    {
      need_dot = true;
    }
    
    else if ('{' == c)
    {
      need_dot = true;
    }
    
    else if ('}' == c)
    {
      need_dot = false;
    }    
    
  } while(--src_size);
  
  *dest_char = '\0';  
  
  return dest_char - dest;
}


