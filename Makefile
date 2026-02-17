CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC = main.c LedToggle/LedToggle.c
OBJ = $(SRC:.c=.o)
ASM = $(SRC:.c=.s)
TARGET = ledtoggle.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.s: %.c
	$(CC) $(CFLAGS) -S $< -o $@

assembly: $(ASM)

clean:
	rm -f $(OBJ) $(ASM) $(TARGET)

