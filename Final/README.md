Course 1 Module 4 final assessment  
Author:William Liu  
Date:June 24 2020  

Make file usage:  
&nbsp;&nbsp;Use: make [TARGET] [PLATFORM=options] [PROJ=options] [VERB=options] [DEBUB=options]  
  
&nbsp;&nbsp;TARGET:  
&nbsp;&nbsp;&nbsp;&nbsp;<FILE>.o - to generate object file from c file  
&nbsp;&nbsp;&nbsp;&nbsp;<FILE>.i - to generate preprocessed file from c file  
&nbsp;&nbsp;&nbsp;&nbsp;<FILE>.asm - to generate assembly file from c file  
&nbsp;&nbsp;&nbsp;&nbsp;<FILE>.d - to generate dependency files from c file  
&nbsp;&nbsp;&nbsp;&nbsp;complie-all - compile all c files and generate all object files for the platform  
&nbsp;&nbsp;&nbsp;&nbsp;build - compile all c files and linke object files to final executable for the platform  
&nbsp;&nbsp;&nbsp;&nbsp;clean - remove all compiled file by platform  
  
If you want to execute compile-all build clean for MSP432  
Please add PLATFORM=MSP432  
 
&nbsp;&nbsp;PROJ options:  
&nbsp;&nbsp;&nbsp;&nbsp;COURSE1(default): only runs course1() function in main.c  
&nbsp;&nbsp;&nbsp;&nbsp;else: run C1M1 functions in stats.c  

&nbsp;&nbsp;VERB options:  
&nbsp;&nbsp;&nbsp;&nbsp;ENABLE(Default):print verbose messages  
&nbsp;&nbsp;&nbsp;&nbsp;else: don't print verbose messages  
  
&nbsp;&nbsp;PLATFORM options:  
&nbsp;&nbsp;&nbsp;&nbsp;HOST, MSP432  

&nbsp;&nbsp;DEBUG options:  
&nbsp;&nbsp;&nbsp;&nbsp;ENABLE:print some debug messages  
&nbsp;&nbsp;&nbsp;&nbsp;else(default) : don't print debug messages  
  
by using: ./final.out  
You should see all test items pass.  

Description:  
You will get more experience with Git Version control  
Writing more C-programming code  
Integrating your code with your build system.  
You will reuse your version control repository and add some new c-programming functions that manipulate memory.  
You will test your code on your host machine, but your code should compile for both the target platform and host platform.  
We will use the target platform in future assignments.  
  
After completing this assignment, you will be able to:  
Incorporate a c-program application into your Make and GCC build system  
Write c-program functions that manipulate memory  
Execute and test your application by simulating it on the host machine  
  
Implementation File Guidelines  
Makefile:  
&nbsp;&nbsp;Modify to work properly with the new file structure and meet new requirements.  
  
main.c:  
&nbsp;&nbsp;You will just need to call a function that is defined in the course1.c source file.  
&nbsp;&nbsp;However, you need to use a compile time switch to wrap this function to call.  
&nbsp;&nbsp;This way we can have a simple main() function that can switch which course deliverable we wish  
&nbsp;&nbsp;to call by specifying the -DCOURSE1 compile time switch.  
  
stats.c/stats.h:  
&nbsp;&nbsp;You need to modify your print_array() function in stats.c so that you can enable/disable debug printing with a compile time switch.  
&nbsp;&nbsp;This compile time switch should be enabled with a VERBOSE flag in the makefile ( -DVERBOSE ).  
&nbsp;&nbsp;If enabled, the print_array function should print as normal.  
&nbsp;&nbsp;If not defined, nothing should print. Additionally, you need to modify your use of printf to use  
&nbsp;&nbsp;the PRINTF macro defined in platform.h  

memory.c/memory.h:  
!!All operations need to be performed using pointer arithmetic, not array indexing  
  
&nbsp;&nbsp;uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);  
&nbsp;&nbsp;&nbsp;&nbsp;This function takes two byte pointers (one source and one destination) and a length of bytes to move from  
&nbsp;&nbsp;&nbsp;&nbsp;the source location to the destination.  
&nbsp;&nbsp;&nbsp;&nbsp;The behavior should handle overlap of source and destination.  
&nbsp;&nbsp;&nbsp;&nbsp;Copy should occur, with no data corruption.  
&nbsp;&nbsp;&nbsp;&nbsp;Should return a pointer to the destination (dst).  
  
&nbsp;&nbsp;uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);  
&nbsp;&nbsp;&nbsp;&nbsp;This function takes two byte pointers (one source and one destination) and a length of bytes to copy from  
&nbsp;&nbsp;&nbsp;&nbsp;the source location to the destination.  
&nbsp;&nbsp;&nbsp;&nbsp;The behavior is undefined if there is overlap of source and destination. Copy should still occur, but will likely corrupt your data.  
&nbsp;&nbsp;Should return a pointer to the destination (dst).  
  
&nbsp;&nbsp;uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);  
&nbsp;&nbsp;&nbsp;&nbsp;This should take a pointer to a source memory location, a length in bytes and set all locations of that memory to a given value.  
&nbsp;&nbsp;&nbsp;&nbsp;Should return a pointer to the source (src).  
&nbsp;&nbsp;&nbsp;&nbsp;You should NOT reuse the set_all() function  
  
&nbsp;&nbsp;uint8_t * my_memzero(uint8_t * src, size_t length);  
&nbsp;&nbsp;&nbsp;&nbsp;This should take a pointer to a memory location, a length in bytes and zero out all of the memory.  
&nbsp;&nbsp;&nbsp;&nbsp;Should return a pointer to the source (src).  
&nbsp;&nbsp;&nbsp;&nbsp;You should NOT reuse the clear_all() function  
  
&nbsp;&nbsp;uint8_t * my_reverse(uint8_t * src, size_t length);  
&nbsp;&nbsp;&nbsp;&nbsp;This should take a pointer to a memory location and a length in bytes and reverse the order of all of the bytes.  
&nbsp;&nbsp;&nbsp;&nbsp;Should return a pointer to the source.  
  
&nbsp;&nbsp;int32_t * reserve_words(size_t length);  
&nbsp;&nbsp;&nbsp;&nbsp;This should take number of words to allocate in dynamic memory  
&nbsp;&nbsp;&nbsp;&nbsp;Should return a pointer to memory if successful, or a Null Pointer if not successful  
  
&nbsp;&nbsp;void free_words(int32_t * src);  
&nbsp;&nbsp;&nbsp;&nbsp;Should free a dynamic memory allocation by providing the pointer src to the function  
  
data.c/data.h:  
!!All operations need to be performed using pointer arithmetic, not array indexing  
!!You may not use any string functions or libraries  
&nbsp;&nbsp;uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)  
&nbsp;&nbsp;&nbsp;&nbsp;Integer-to-ASCII needs to convert data from a standard integer type into an ASCII string.   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;You should be able to support bases 2 to 16 by specifying the integer value of the base you wish to convert to (base).  
&nbsp;&nbsp;&nbsp;&nbsp;Copy the converted character string to the uint8_t* pointer passed in as a parameter (ptr)  
&nbsp;&nbsp;&nbsp;&nbsp;The signed 32-bit number will have a maximum string size (Hint: Think base 2).  
&nbsp;&nbsp;&nbsp;&nbsp;You must place a null terminator at the end of the converted c-string  
&nbsp;&nbsp;&nbsp;&nbsp;Function should return the length of the converted data (including a negative sign).  
&nbsp;&nbsp;&nbsp;&nbsp;Example my_itoa(ptr, 1234, 10) should return an ASCII string length of 5 (including the null terminator).  
&nbsp;&nbsp;&nbsp;&nbsp;This function needs to handle signed data.  
  
&nbsp;&nbsp;int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)  
&nbsp;&nbsp;&nbsp;&nbsp;ASCII-to-Integer needs to convert data back from an ASCII represented string into an integer type.  
&nbsp;&nbsp;&nbsp;&nbsp;The character string to convert is passed in as a uint8_t * pointer (ptr).  
&nbsp;&nbsp;&nbsp;&nbsp;The number of digits in your character set is passed in as a uint8_t integer (digits).  
&nbsp;&nbsp;&nbsp;&nbsp;You should be able to support bases 2 to 16.  
&nbsp;&nbsp;&nbsp;&nbsp;The converted 32-bit signed integer should be returned.  
&nbsp;&nbsp;&nbsp;&nbsp;This function needs to handle signed data.  
