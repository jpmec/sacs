/** sacs_util.h
 
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


#ifndef SACS_UTIL_H
#define SACS_UTIL_H




/** Pretty-print a C structure string.
 *  Returns number of chars printed.
 */
size_t sacs_snprettyf(char* dest, size_t dest_size, const char* src, size_t src_size);


/** Remove all characters from a string where isspace(c) returns true.
 */
size_t sacs_sncompact(char* dest, size_t dest_size, const char* src, size_t src_size);


/** Convert binary into hex string.
 *  Returns number of characters written to dest.
 */
size_t sacs_snbintohex(char* dest, size_t dest_size, void* src, size_t src_size);




#endif//SACS_UTIL_H
