/** sacs.h
 
Simple API for C Structures.
 
The SACS library allows for easier serialization of C structures.  
The library parses and prints text that is formatted like a C structure initializer.
There should be no difference between C code that can be compiled and text that can be read by SACS at run-time.
The SACS framework relies heavily on the C preprocessor to generate application-specific code.
 
 http://en.wikipedia.org/wiki/Struct_%28C_programming_language%29#Struct_initialization
 
 
The SACS library:
  + uses an event-driven parser, similar to SAX: http://en.wikipedia.org/wiki/Simple_API_for_XML
  + uses only the C standard library.  No other dependencies are needed.
  + does not malloc() any memory.  The library user must allocate all necessary memory in advance.
  + does not create any DOM object.  The data is written/read straight from the native C structure.

 

 
 
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


#ifndef SACS_H
#define SACS_H


/* 
 * Library configuration
 */
#define SACS_USE_PARSE
#define SACS_USE_FPRINTF
#define SACS_USE_PRINTF
#define SACS_USE_SNPRINTF
#define SACS_USE_JSON
#define SACS_USE_XML
#define SACS_USE_YAML


#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>




/*
 * Definition macros for SACS library types.
 * These types can be used when defining serializable structures.
 */

#define bool__(_field_name_)                                   sacs_bool(_field_name_)

#define char__(_field_name_)                                   sacs_char(_field_name_)
#define chars__(_field_name_, _size_)                          sacs_char_string(_field_name_, _size_)

#define double__(_field_name_)                                 sacs_double(_field_name_)
#define double_array__(_field_name_, _size_)                   sacs_double_array(_field_name_, _size_)

#define float__(_field_name_)                                  sacs_float(_field_name_)
#define float_array__(_field_name_, _size_)                    sacs_float_array(_field_name_, _size_)

#define int__(_field_name_)                                    sacs_int(_field_name_)
#define int_array__(_field_name_, _size_)                      sacs_int_array(_field_name_, _size_)

#define long__(_field_name_)                                   sacs_long(_field_name_)
#define long_array__(_field_name_, _size_)                     sacs_long_array(_field_name_, _size_)

#define unsigned_int__(_field_name_)                           sacs_unsigned_int(_field_name_)
#define unsigned_int_array__(_field_name_, _size_)             sacs_unsigned_int_array(_field_name_, _size_)
#define unsigned_int_bitfield__(_field_name_, _bits_)          sacs_unsigned_int_bitfield(_field_name_, _bits_)

#define unsigned_long__(_field_name_)                          sacs_unsigned_long(_field_name_)
#define unsigned_long_array__(_field_name_, _size_)            sacs_unsigned_long_array(_field_name_, _size_)
#define unsigned_long_bitfield__(_field_name_, _bits_)         sacs_unsigned_long_bitfield(_field_name_, _bits_)


#define int32__(_field_name_)                                  sacs_int32(_field_name_) 
#define int32_array__(_field_name_, _size_)                    sacs_int32_array(_field_name_, _size_) 

#define uint8__(_field_name_)                                  sacs_uint8(_field_name_)
#define uint8_array__(_field_name_, _size_)                    sacs_uint8_array(_field_name_, _size_)
#define uint8_bitfield__(_field_name_, _bits_)                 sacs_uint8_bitfield(_field_name_, _bits_)

#define uint16__(_field_name_)                                 sacs_uint16(_field_name_) 
#define uint16_array__(_field_name_, _size_)                   sacs_uint16_array(_field_name_, _size_) 
#define uint16_bitfield__(_field_name_, _bits_)                sacs_uint16_bitfield(_field_name_, _bits_)

#define uint32__(_field_name_)                                 sacs_uint32(_field_name_) 
#define uint32_array__(_field_name_, _size_)                   sacs_uint32_array(_field_name_, _size_) 
#define uint32_bitfield__(_field_name_, _bits_)                sacs_uint32_bitfield(_field_name_, _bits_)

#define uint64__(_field_name_)                                 sacs_uint64(_field_name_) 
#define uint64_array__(_field_name_, _size_)                   sacs_uint64_array(_field_name_, _size_) 
#define uint64_bitfield__(_field_name_, _bits_)                sacs_uint64_bitfield(_field_name_, _bits_)


#define struct__(_struct_name_, _field_name_)                  sacs_inner_struct(_struct_name_, _field_name_)
#define struct_array__(_struct_name_, _field_name_, _size_)    sacs_inner_struct_array(_struct_name_, _field_name_, _size_)

#define struct_begin(_type_name_)                              sacs_struct_begin(_type_name_)
#define struct_end(_type_name_)                                sacs_struct_end(_type_name_)


#define enum__(_enum_name_, _field_name_)                      sacs_inner_enum(_enum_name_, _field_name_)
#define enum_value__(_label_, _value_)                         sacs_enum_value(_label_, _value_)
#define enum_auto_value__(_label_)                             sacs_enum_auto_value(_label_)

#define enum_begin(_enum_name_)                                sacs_enum_begin(_enum_name_)
#define enum_end(_enum_name_)                                  sacs_enum_end(_enum_name_)







/*
 * Library configuration
 */

#ifdef SACS_USE_PARSE
  #include "sacs_parse.h"
#endif

#ifdef SACS_USE_FPRINTF
  #include "sacs_fprintf.h"
#endif

#ifdef SACS_USE_PRINTF
  #include "sacs_printf.h"
#endif

#ifdef SACS_USE_SNPRINTF
  #include "sacs_snprintf.h"
#endif

#ifdef SACS_USE_JSON
  #include "sacs_json.h"
#endif

#ifdef SACS_USE_YAML
  #include "sacs_xml.h"
#endif

#ifdef SACS_USE_YAML
  #include "sacs_yaml.h"
#endif




#endif//SACS_H
