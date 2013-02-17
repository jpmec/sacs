SACS
====

The Good
========

Simple API for C Structures

The SACS library allows for easier serialization of C structures.  
The goal of the SACS library is to allow a simple way to read/write C structures from/to strings.
The library parses and prints text that is formatted like a C structure initializer.
Any valid C code text that can be compiled can be read by SACS at run-time.
 
 http://en.wikipedia.org/wiki/Struct_%28C_programming_language%29#Struct_initialization

SACS also has some 'enhancements' built in, such as reading boolean and binary values. 
 
The SACS library:

*   uses an event-driven parser, similar to SAX: http://en.wikipedia.org/wiki/Simple_API_for_XML
*   uses only the C standard library.  No other dependencies are needed.
*   does not malloc() any memory.  The library user must allocate all necessary memory in advance.
*   does not create any DOM object.  The data is written/read straight from the native C structure.

The SACS library is free! (See the License below)


Data types
----------
The data types supported by SACS can be found in the sacs.h file.  
SACS supports the C standard datatypes and the data types defined in the <stdint.h> file.
SACS allows structures to be nested.

Bitfields are not (yet?) supported by SACS.  An attempt has been made to support them, but it is not robust nor dependable.
The C standard does not define the order in which bitfields are stored,
therefore bitfields should not be used in structures intended on being serialized.
If you need to store 1-bit values, it is recommended that you use an unsigned value in the structure,
and access the individual bits using conventional C methods.


The Parsers
----------
A SACS parser will parse null-terminated strings of data.  
It will attempt to convert the string data into a representation needed by the C structure.  
A SACS parser should support any legal C syntax for initializing a structure.


The Emitters
------------
SACS can convert C structures into null-terminated strings.  The default SACS behavior is to emit valid C structure syntax.

SACS can also emit other formats, such as JSON, XML and YAML.

**All valid C structures can be emitted as valid JSON, XML and YAML.**

**Not all valid JSON, XML and YAML can be parsed as a valid C structure.**




The Bad
=======
It doesn't work… yet.  Parts of the functionality are in place, along with the general framework for generating.

> **If you are expecting to download this library and it "just work" you will be very dissapointed.**



The Ugly
=======
The SACS framework is built using the C preprocessor.  
Therefore, any problem with formatting when writing C code that uses SACS causes weird, hard to debug compiler messages.
This problem may or may not improve in the future.  The code is freely available for examination.



The FAQs
========


**SACS doesn't work with Microsoft Visual C++?**
Microsoft Visual C++ does not support C99 features such as named designators.
Also, Microsoft Visual C++ does not compile C99 code.  Therefore, SACS probably won't ever work with MSVC++.  Sorry.  The source code is available if you want to port it yourself.




The License
===========

Author: Joshua Petitt
Available at: https://github.com/jpmec/sacs
 
 
Copyright (c) 2013 Joshua Petitt
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.




The Extras
==========
I hope you find the SACS library to be useful.  If you use it in a project, please send me a link, I'd love to know how it is being used in the wild.  Also, if you find a bug or make a great improvement, then make a Pull Request and I'll try to integrate the fix or feature.  Thanks!
