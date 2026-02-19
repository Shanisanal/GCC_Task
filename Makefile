CC = gcc
CROSS_CC = aarch64-linux-gnu-gcc
CFLAGS = -Wall -Wextra -O2
SRC = main.c LedToggle/LedToggle.c appTimer/appTimer.c
OBJ = $(SRC:.c=.o)
ASM = $(SRC:.c=.s)
LINUX_TARGET = release/ledtoggle_wsl.bin 
RPI_TARGET = release/ledtoggle_pi.bin

all: linux rpi

# Build for WSL / native Linux 
linux: $(SRC) 
	$(CC) $(CFLAGS) $(SRC) -o $(LINUX_TARGET) 
	
# Build for Raspberry Pi (ARM cross-compile) 
rpi: $(SRC) 
	$(CROSS_CC) $(CFLAGS) -march=armv8-a $(SRC) -o $(RPI_TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.s: %.c
	$(CC) $(CFLAGS) -S $< -o $@

assembly: $(ASM)

clean:
	rm -f $(OBJ) $(ASM) $(LINUX_TARGET) $(RPI_TARGET)

