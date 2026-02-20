# Compiler setup
CC       = gcc
CROSS_CC = aarch64-linux-gnu-$(CC)
CFLAGS   = -Wall -Wextra -O2
DEBUGFLAGS = -Wall -Wextra -O0 -g

# Source directories (flexible to add more)
SRC_DIRS = appTimer LedToggle

# Search for .c source files inside the source directories
vpath %.c $(SRC_DIRS)

# Collect all .c files automatically (include project root `main.c`)
SRCS = $(wildcard main.c) $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))

# Name of the program's main executable (only one executable is produced)
MAIN = ledtoggle

# Extract base filenames (without path or extension)
BASENAMES = $(basename $(notdir $(SRCS)))

# Release and debug folders
RELEASE_DIR = release
DEBUG_DIR   = debug

# Targets
TARGETS = linux rpi

$(RELEASE_DIR):
	mkdir -p	$(RELEASE_DIR)

$(DEBUG_DIR)/:
	mkdir -p	$(DEBUG_DIR)

# Pattern rules for release builds
$(RELEASE_DIR)/%_linux.o: %.c |	$(RELEASE_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(RELEASE_DIR)/%_linux.s: %.c |	$(RELEASE_DIR)
	$(CC) $(CFLAGS) -S $< -o $@

$(RELEASE_DIR)/%_linux.exe: $(RELEASE_DIR)/%_linux.o |	$(RELEASE_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(RELEASE_DIR)/%_rpi.o: %.c
	$(CROSS_CC) $(CFLAGS) -c $< -o $@

$(RELEASE_DIR)/%_rpi.s: %.c
	$(CROSS_CC) $(CFLAGS) -S $< -o $@

$(RELEASE_DIR)/%_rpi.exe: $(RELEASE_DIR)/%_rpi.o
	$(CROSS_CC) $(CFLAGS) $< -o $@

# Pattern rules for debug builds (ensure debug dir exists before writing files)
$(DEBUG_DIR)/%_linux.o: %.c | $(DEBUG_DIR)/
	$(CC) $(DEBUGFLAGS) -c $< -o $@

$(DEBUG_DIR)/%_linux.s: %.c | $(DEBUG_DIR)/
	$(CC) $(DEBUGFLAGS) -S $< -o $@

$(DEBUG_DIR)/%_linux.exe: $(DEBUG_DIR)/%_linux.o | $(DEBUG_DIR)/
	$(CC) $(DEBUGFLAGS) $< -o $@

$(DEBUG_DIR)/%_rpi.o: %.c | $(DEBUG_DIR)/
	$(CROSS_CC) $(DEBUGFLAGS) -c $< -o $@

$(DEBUG_DIR)/%_rpi.s: %.c | $(DEBUG_DIR)/
	$(CROSS_CC) $(DEBUGFLAGS) -S $< -o $@

$(DEBUG_DIR)/%_rpi.exe: $(DEBUG_DIR)/%_rpi.o | $(DEBUG_DIR)/
	$(CROSS_CC) $(DEBUGFLAGS) $< -o $@

# Build lists
RELEASE_LINUX_O   = $(addprefix $(RELEASE_DIR)/,$(addsuffix _linux.o,$(BASENAMES)))
RELEASE_LINUX_S   = $(addprefix $(RELEASE_DIR)/,$(addsuffix _linux.s,$(BASENAMES)))
RELEASE_LINUX_EXE = $(RELEASE_DIR)/$(MAIN)_linux.exe

# Link the single release executable from all release object files
$(RELEASE_DIR)/$(MAIN)_linux.exe: $(RELEASE_LINUX_O) | $(RELEASE_DIR)
	$(CC) $(CFLAGS) $^ -o $@

Linux: $(RELEASE_LINUX_O) $(RELEASE_LINUX_S) $(RELEASE_LINUX_EXE)

RELEASE_RPI_O = $(addprefix $(RELEASE_DIR)/,$(addsuffix _rpi.o,$(BASENAMES)))
RELEASE_RPI_S = $(addprefix $(RELEASE_DIR)/,$(addsuffix _rpi.s,$(BASENAMES)))
RELEASE_RPI_EXE = $(RELEASE_DIR)/$(MAIN)_rpi.exe

Rpi:	$(RELEASE_RPI_O) $(RELEASE_RPI_S) $(RELEASE_RPI_EXE)

# Link the single RPi executable from all _rpi.o object files
$(RELEASE_DIR)/$(MAIN)_rpi.exe: $(RELEASE_RPI_O) | $(RELEASE_DIR)
	$(CROSS_CC) $(CFLAGS) $^ -o $@

DEBUG_LINUX_O   = $(addprefix $(DEBUG_DIR)/,$(addsuffix _linux.o,$(BASENAMES)))
DEBUG_LINUX_S   = $(addprefix $(DEBUG_DIR)/,$(addsuffix _linux.s,$(BASENAMES)))
DEBUG_LINUX_EXE = $(DEBUG_DIR)/$(MAIN)_linux.exe

DEBUG_RPI_O     = $(addprefix $(DEBUG_DIR)/,$(addsuffix _rpi.o,$(BASENAMES)))
DEBUG_RPI_S     = $(addprefix $(DEBUG_DIR)/,$(addsuffix _rpi.s,$(BASENAMES)))
DEBUG_RPI_EXE   = $(DEBUG_DIR)/$(MAIN)_rpi.exe

# Link debug executables from all debug object files
$(DEBUG_DIR)/$(MAIN)_linux.exe: $(DEBUG_LINUX_O) | $(DEBUG_DIR)
	$(CC) $(DEBUGFLAGS) $^ -o $@

$(DEBUG_DIR)/$(MAIN)_rpi.exe: $(DEBUG_RPI_O) | $(DEBUG_DIR)
	$(CROSS_CC) $(DEBUGFLAGS) $^ -o $@

# Phony targets
.PHONY: all Linux Rpi debug clean

all: $(RELEASE_LINUX) $(RELEASE_RPI)

debug: $(DEBUG_LINUX_EXE) $(DEBUG_RPI_EXE)

clean:
	rm -rf $(RELEASE_DIR)/* $(DEBUG_DIR)/*
