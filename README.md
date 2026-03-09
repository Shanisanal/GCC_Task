##  AppTimer Task
##  Project Overview
- C program to display the system’s current time in real-time.
- Shows time and date in GMT, IST, and PST timezones.
- Displays Epoch time in GMT with date.
- Refreshes the time every second.

##  Files
- `main.c` → Entry point, calls time display functions.
- `appTimer/appTimer.c` → Implementation of time and formatting logic.
- `appTimer/appTimer.h` → Header file with function declarations.
- `.gitignore` → Ignores generated build artifacts (`*.o`, `*.s`, 
`*.exe`).

##  Compilation and Run
### Direct GCC command:
- gcc main.c appTimer/appTimer.c -o appTimerexe
- ./appTimerexe 
