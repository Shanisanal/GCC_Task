# Variables 
# Compiler
CC = gcc

# Cross compiler
CROSS_CC = aarch64-linux-gnu-${CC}

# List of all sub directories
SUBDIR = . appTimer LedToggle 

# List of all include directories with header file
INCDIR = . appTimer LedToggle

# Dependency Flags

# Flags with include path
CFLAGS = -Wall -Wextra -O2

# Make a list of C source files in project
# foreach will iterate through SUBDIR and find all .c file
SOURCE = $(foreach D,$(SUBDIR),$(wildcard $(D)/*.c))
file_names = $(notdir $(SOURCE))

# OBJECTS list can be generated from SOURCE_FILES using patsubst
# OBJECTS = main.o appTimer/appTimer.o appLed/appLed.o Console/Console.o
OBJECTS = $(patsubst %.c,release/%.o,$(file_names))

# Create dependency files incase headers changed
DEPND_FILES = $(patsubst %.c,%.d,$(SOURCE_FILES))

# Create assembly file List
ASSEMBLY_FILES = $(patsubst %.c,release/%.s,$(file_names))

VPATH = .:appTimer:LedToggle

# Target : Dependencies
# Specify the rule for Dependencies
all : Linux Rpi

# Here Linux build depend on 4 different files
# So we need to define rules for each one of these
# Instead make a list of all these dependencis and use the list

# Linux : main.o appTimer/appTimer.o appLed/appLed.o Console/Console.o

# $@ will substitute output name with Target
# $^ will replaced with first dependency name 
# $< only use c Dependencies
#Linux : CreateRelease CreateDebug Assembly Executable Object Debug
Linux : CreateRelease Assembly Object Executable

# Build Raspberry Pi output
# Build using cross compiler
# Store target in Release folder
Rpi	: CreateRelease Assembly Object Executable

# Need to define rules for OBJECTS
# $(CC) $(notdir $^) -o Release/LinuxOutput Need to explore
Object : $(OBJECTS)
	$(CC) $^ -o release/ledtoggle.exe

# OBJECTS or .o files depend on source or .c files
# Need a rule for every .o file
# Instead of wriring all of them use %
# % operator is a wildcard means any one in list 
# Expression means anyone with .o will have dependency on corresponding .c
# $(CC) $(CFLAGS) -g $< -o Debug/$(notdir $@)
release/%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

# Need to define rules for ASSEMBLY
Assembly : $(ASSEMBLY_FILES)
	$(CC) $(CFLAGS) $^ -o release/ledtoggle_wsl.bin

# ASSEMBLY or .s files depend on source or .c files
# Need a rule for every .s file
# Expression means anyone with .o will have dependency on corresponding .c
release/%.s : %.c
	$(CC) $(CFLAGS) -S $^ -o $@

# Need to define rules for Executable
Executable : $(SOURCE) CreateRelease
	$(CC) $(CFLAGS) $(SOURCE) -o release/ledtoggle.exe

# Create folder named Release using mkdir
CreateRelease :
	mkdir -p release

Rpi : CreateRelease
	$(CROSS_CC)	\
	$(CFLAGS)	\
	$(SOURCE)	\
	-o release/ledtoggle_pi.bin

# Clean is needed to clean everything 
# Includes rules to remove and clear
.PHONY = clean
clean : 
	rm -f main
	find . -type f -name "*.o" -delete
	find . -type f -name "*.s" -delete
	find . -type f -name "*.bin" -delete
	find . -type f -name "*.exe" -delete
		
	
# Include Dependencies
# -include $(DEPND_FILES)