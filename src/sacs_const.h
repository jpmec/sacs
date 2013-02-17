/** sacs.h
 
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


#ifndef SACS_CONST_H
#define SACS_CONST_H




/*
 * SACS library constants.
 */
#define SACS_CHAR_COMMA                    ','
#define SACS_CHAR_SINGLE_QUOTE             '\''
#define SACS_CHAR_DOUBLE_QUOTE             '"'
#define SACS_CHAR_LEFT_BRACE               '{'
#define SACS_CHAR_RIGHT_BRACE              '}'
#define SACS_CHAR_LEFT_BRACKET             '['
#define SACS_CHAR_RIGHT_BRACKET            ']'
#define SACS_CHAR_DOT                      '.'
#define SACS_CHAR_EQUALS                   '='
#define SACS_CHAR_BACKSLASH                '\\'
#define SACS_CHAR_QUESTION                 '\?'

#define SACS_CHAR_BELL_ALERT               '\a'
#define SACS_CHAR_BACKSPACE                '\b'
#define SACS_CHAR_FORMFEED                 '\f'
#define SACS_CHAR_NEWLINE                  '\n'
#define SACS_CHAR_RETURN                   '\r'
#define SACS_CHAR_TAB                      '\t'
#define SACS_CHAR_VTAB                     '\v'

#define SACS_CHAR_BEGIN_FIELD              SACS_CHAR_DOT
#define SACS_CHAR_FIELD_SEPARATOR          SACS_CHAR_COMMA
#define SACS_CHAR_FIELD_VALUE_SEPARATOR    SACS_CHAR_EQUALS

#define SACS_CHAR_STRUCT_BEGIN             SACS_CHAR_LEFT_BRACE
#define SACS_CHAR_STRUCT_END               SACS_CHAR_RIGHT_BRACE

#define SACS_CHAR_ARRAY_BEGIN              SACS_CHAR_LEFT_BRACE
#define SACS_CHAR_ARRAY_END                SACS_CHAR_RIGHT_BRACE

#define SACS_CHAR_CHAR_BEGIN               SACS_CHAR_SINGLE_QUOTE
#define SACS_CHAR_CHAR_END                 SACS_CHAR_SINGLE_QUOTE

#define SACS_CHAR_STRING_BEGIN             SACS_CHAR_DOUBLE_QUOTE
#define SACS_CHAR_STRING_END               SACS_CHAR_DOUBLE_QUOTE

#define SACS_STR_FIELD_VALUE_SEPARATOR     "="

#define SACS_STR_BEFORE_FIELD_NAME         "."
#define SACS_STR_AFTER_FIELD_NAME          NULL

#define SACS_STR_BEFORE_FIELD_VALUE        NULL
#define SACS_STR_AFTER_FIELD_VALUE         NULL

#define SACS_STR_BEFORE_FIELD              NULL
#define SACS_STR_AFTER_FIELD               NULL

#define SACS_STR_BEFORE_ARRAY_FIELD        NULL
#define SACS_STR_AFTER_ARRAY_FIELD         NULL

#define SACS_STR_UINT8_FORMAT              "0x%02X"
#define SACS_STR_UINT16_FORMAT             "0x%04X"
#define SACS_STR_UINT32_FORMAT             "0x%08X"


#define SACS_STR_FIELD_VALUE_SEPARATOR_PRETTY     " = "
#define SACS_STR_BEFORE_FIELD_NAME_PRETTY         "."
#define SACS_STR_AFTER_FIELD_NAME_PRETTY          NULL
#define SACS_STR_BEFORE_FIELD_VALUE_PRETTY        NULL
#define SACS_STR_AFTER_FIELD_VALUE_PRETTY         NULL

#define SACS_STR_BEFORE_FIELD_PRETTY              NULL
#define SACS_STR_AFTER_FIELD_PRETTY               "\n"

#define SACS_STR_BEFORE_ARRAY_FIELD_PRETTY        NULL
#define SACS_STR_AFTER_ARRAY_FIELD_PRETTY         NULL




#endif//SACS_CONST_H
