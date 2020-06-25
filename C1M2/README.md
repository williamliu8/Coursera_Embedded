Course 1 Module 2 assessment  
Author:William Liu  
Date:June 14 2020  
  
Makefile usage:  
make [TARGET] [PLATFORM=Platform options]  
&nbsp;&nbsp;TARGET:  
&nbsp;&nbsp;&nbsp;&nbsp;<FILE>.o - to generate object file from c file  
&nbsp;&nbsp;&nbsp;&nbsp;<FILE>.i - to generate preprocessed file from c file  
&nbsp;&nbsp;&nbsp;&nbsp;<FILE>.asm - to generate assembly file from c file  
&nbsp;&nbsp;&nbsp;&nbsp;<FILE>.d - to generate dependency files from c file  
&nbsp;&nbsp;complie-all - compile all c files and generate all object files for the platform  
&nbsp;&nbsp;build - compile all c files and linke object files to final executable for the platform  
&nbsp;&nbsp;clean - remove all compiled file by platform  
If you want to execute compile-all, build, clean for MSP432  
Please add PLATFORM=MSP432  
  
Platform options:  
&nbsp;&nbsp;HOST, MSP432  
  
Description:  
You will create a build system using the GNU tools, GCC and GNU Make.  
This assignment will require you to compile multiple files, link them together and create a final output executable.  
Some files will be provided for you, but you will need to support two platforms; the host environment and the target embedded system MSP432.  
The host system will allow you to simulate software on a host platform.  
The target system will be used in upcoming assignments as we begin to create our microcontroller applications.  
  
After completing this assignment, you will be able to:  
Use GCC and GNU Make to create a command line build system.  
Write a makefile that can natively and cross compile an application.  
Generate preprocessor, assembly, object, dependency, executable, and map output files.  
  
Implementation File Guidelines  
You will write a makefile that can compile multiple source files and support two platform targets.  
You will be given a folder structure and a set of source files.  
  
Files  
msp432p401r.lds - The linker file you are to use for linking  

'src' folder : contains five source files (*.c)  
Makefile  
&nbsp;&nbsp;The makefile you are to edit for the assignment  
sources.mk  
&nbsp;&nbsp;The source file you are to edit for the assignment  
main.c  
&nbsp;&nbsp;Main file you are to work with  
memory.c  
&nbsp;&nbsp;File that interacts with memory through an IO abstraction interface  
interrupts_msp432p401r_gcc.c  
&nbsp;&nbsp;MSP432 specific C-file for interrupts  
startup_msp432p401r_gcc.c  
&nbsp;&nbsp;MSP432 specific C-file for startup  
system_msp432p401r.c  
&nbsp;&nbsp;MSP432 specific C-file for for system information  
  
'include'folder : contains the three directories of supporting header files  
common  
&nbsp;&nbsp;Contains common headers for both platform targets  
msp432  
&nbsp;&nbsp;Contains MSP432 platform headers  
CMSIS  
&nbsp;&nbsp;Contains ARM architecture specific headers  
  
Inside the common folder, you have been provided  
memory.h  
platform.h  
&nbsp;&nbsp;The platform.h file gives you an interface to printf using the macro PRINTF as a mechanism to reduce the dependencies on the stdio.h library.  
  
README.md  
&nbsp;&nbsp;This file.  
