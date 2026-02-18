##  Project Overview
- C program to simulate an LED toggling between ON and OFF states.
- Displays the LED state in the console output.
- The toggling happens every second in real time.

##  Files
- `main.c` → Entry point, calls LED toggling functions.
- `LedToggle/LedToggle.c` → Implementation of the LED toggle function.
- `LedToggle/LedToggle.h` → Header file with function declarations.
- `.gitignore` → Ignores generated build artifacts (`*.o`, `*.s`, `.exe`,`.bin`).

##  Compilation and Run
### Direct GCC command:
- gcc main.c LedToggle/LedToggle.c -o ledtoggle.exe
- ./ledtoggle.exe
- ./ledtoggle_wsl.bin
