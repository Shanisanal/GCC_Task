//**************************** Cross_Compilation_Task ****************************** 
//  Copyright (c) 2026 Trenser Technology Solutions
//  All Rights Reserved 
//***************************************************************************** 
// 
// File      : main.c 
// Summary   : Entry point for time display application 
// Note      : Calls functions from appTimer module to show GMT, IST, PST and Epoch 
// Author    : Shani 
// Date      : Feb 11, 2026 
// 
//***************************************************************************** 

//******************************* Include Files *******************************
#include <stdio.h>
#include <unistd.h>     
#include <stdbool.h>
#include "appTimer/appTimer.h"
#include "LedToggle/LedToggle.h"

//******************************* Local Types ********************************* 
 
//***************************** Local Constants ******************************* 
 
//***************************** Local Variables ******************************* 
 
//****************************** Local Functions ****************************** 

//****************************** main ******************************
// Purpose : Continuously toggle the LED state every second.
//           Demonstrates simple LED simulation by alternating
//           between ON and OFF states.
// Inputs  : None
// Outputs : None
// Return  : int - Returns 0 upon successful completion.
// Notes   : 
//   - Calls ToggleLED() to print or simulate LED state.
//   - Uses sleep(1) to wait one second between toggles.
//   - Runs indefinitely until manually terminated.
//*****************************************************************************

int main(void)
{
    bool bLedState = false;

    while(1)
    {

        ToggleLED(bLedState);

        bLedState = !bLedState;
        sleep(1);   
    }

    return 0;
}

// EOF
