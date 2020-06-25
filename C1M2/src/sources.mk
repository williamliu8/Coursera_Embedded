#******************************************************************************
# Copyright (C) 2020 by William Liu
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. William Liu is not liable for any
# misuse of this material. 
#
#*****************************************************************************
# Add your Source files to this variable
# SOURCES for PLATFORM = HOST
SOURCES = main.c \
	  memory.c 
	

# Add your include paths to this variable
INCLUDES = -I../include/CMSIS -I ../include/common -I ../include/msp432
