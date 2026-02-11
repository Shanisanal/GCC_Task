nano Makefile

CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC = main.c appTimer/appTimer.c
OBJ = $(SRC:.c=.o)
ASM = $(SRC:.c=.s)
TARGET = appTimerDemo

all: $(TARGET)

$(TARGET): $(OBJ)
 $(CC) $(OBJ) -o $@

%.o: %.c
 $(CC) $(CFLAGS) -c $< -o $@

%.s: %.c
 $(CC) $(CFLAGS) -S $< -o $@

assembly: $(ASM)

CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC = main.c appTimer/appTimer.c
OBJ = $(SRC:.c=.o)
ASM = $(SRC:.c=.s)
TARGET = appTimerDemo

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
CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC = main.c appTimer/appTimer.c
OBJ = $(SRC:.c=.o)
ASM = $(SRC:.c=.s)
TARGET = appTimerDemo

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

clean:
 rm -f $(OBJ) $(ASM) $(TARGET)

