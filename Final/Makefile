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

#------------------------------------------------------------------------------
# Use: make [TARGET] [PLATFORM=options] [PROJ=options] [VERB=options] [DEBUB=options]
#
# TARGET:
#     <FILE>.o - to generate object file from c file
#     <FILE>.i - to generate preprocessed file from c file
#     <FILE>.asm - to generate assembly file from c file
#     <FILE>.d - to generate dependency files from c file
#     complie-all - compile all c files and generate all object files for the platform
#     build - compile all c files and linke object files to final executable for the platform
#     clean - remove all compiled file by platform
#
# If you want to execute compile-all build clean for MSP432
# Please add PLATFORM=MSP432
# 
# PROJ options:
#     COURSE1(default): only runs course1() function in main.c
#     else: run C1M1 functions in stats.c
#
# VERB options:
#     ENABLE(Default):print verbose messages 
#     else: don't print verbose messages
#
# PLATFORM options:
#     HOST, MSP432
#
# DEBUG options:
#     ENABLE:print some debug messages
#     else(default) : don't print debug messages
#------------------------------------------------------------------------------
include sources.mk
TARGET = final
#Platform options,default is HOST
PLATFORM = HOST
PROJ = COURSE1
VERB = ENABLE
DEBUG = DISABLE

ifeq ($(DEBUG),ENABLE)
	DEBUGFLAG = -DDEBUG
else
	DEBUGFLAG = 
endif

ifeq ($(PROJ),COURSE1)
	PROJFLAGS = -DCOURSE1
else
	PROJFLAGS =
endif

ifeq ($(VERB),ENABLE)
	PRINTFLAGS = -DVERBOSE
else
	PRINTFLAGS =
endif


#Common Platform Flags
FLAGS = -Wall \
	-Werror\
	-g \
	-O0\
	-std=c99
SIZE = size

#CC => Compiler program
#LDFLAGS => options pass to Linker
#CFLAGS => options for compiler program
#CPPFLAGS => informations for preprocessor

#Variables for PLATFORM=HOST
ifeq ($(PLATFORM),HOST)
	CC = gcc
	LDFLAGS = -Wl,-Map=$(TARGET).map
	CFLAGS = $(FLAGS)
	CPPFLAGS = -DHOST $(PROJFLAGS) $(PRINTFLAGS) $(DEBUGFLAG) $(INCLUDES)
endif

#Variables for PLATFORM=MSP432
ifeq ($(PLATFORM),MSP432)
        #override SOURCES in sources.mk when PLATFORM = MSP432
	SOURCES = ./src/main.c \
		./src/memory.c \
		./src/data.c \
		./src/stats.c \
		./src/course1.c \
		./src/interrupts_msp432p401r_gcc.c \
		./src/startup_msp432p401r_gcc.c \
	  	./src/system_msp432p401r.c

	CC = arm-none-eabi-gcc
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	CFLAGS = $(FLAGS) $(ARM_OTHER_FLAGS) -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS)
	CPPFLAGS = -DMSP432 $(PROJFLAGS) $(PRINTFLAGS) $(DEBUGFLAG) $(INCLUDES)
	
	# Architectures Specific Flags
	LINKER_FILE= ./msp432p401r.lds
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	ARM_OTHER_FLAGS = -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
endif

PRES = $(SOURCES:.c=.i)
OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)
ASMS = $(SOURCES:.c=.asm)

#generate object files for .c files
%.o : %.c
	$(CC) -c $< $(CPPFLAGS) $(CFLAGS) -o $@

#generate assembly file for .c files
%.asm : %.c
	$(CC) -S $< $(CPPFLAGS) $(CFLAGS) -o $@

#generate preprocessed file for .c files
%.i : %.c
	$(CC) -E $< $(CPPFLAGS) -o $@

#gnerate dependency files for .c files
%.d : %.c
	$(CC) -E -M $< $(CPPFLAGS) -o $@


#generate all object files for all source files(no link)
.PHONY: compile-all
compile-all:$(OBJS)

.PHONY: build
build: $(DEPS)
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPS) $(ASMS) $(PRES) $(TARGET).out $(TARGET).map



