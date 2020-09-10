# CLR_RegOps
A C implementation of various Macros for handling bits and bytes inside of registers (often useful in embedded programming), dependant only of the C standard library, with focus on using faster operators whenever possible.

Developed by CLR during 2017. Any criticism welcome.

Released under the GNU Lesser General Public License v3 (LGPL-3.0)

-----------------------------------------------------------------------

The aim of this "library" is to implement macros that make embedded coding with a lot of registry handling more simple to read, while also elminating the chance of making mistakes that are often hard to debug, specially while integrating systems.


Real quick use guide:

  1- Import CLR_BitOps.h and/or CLR_ByteOps.h to your project.
  
  2- #include "CLR_BitOps.h" and/or "CLR_ByteOps.h" in the files of your code expected to handle registers and bit fields.
  
  3- Invoke the macros.
  
  
An example file is provided with a CLI application using the basic functionality. If the provided documentation and comments is not enough, contact CLR for further explanations.

-----------------------------------------------------------------------

Changelog

v1.0 Initial Release.
