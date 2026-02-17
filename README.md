##  Project Overview
- C program to simulate an LED toggling between ON and OFF states.
- Displays the LED state in the console output.
- The toggling happens every second in real time.

##  Files
- `main.c` → Entry point, calls LED toggling functions.
- `appTimer/appTimer.c` → Implementation of the LED toggle function.
- `appTimer/appTimer.h` → Header file with function declarations.
- `.gitignore` → Ignores generated build artifacts (`*.o`, `*.s`, `ledtoggle.exe`).

##  Compilation and Run
### Direct GCC command:
- gcc main.c LedToggle/LedToggle.c -o ledtoggle.exe
- ./ledtoggle.exe
