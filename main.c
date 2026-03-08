//**************************** GCC_Task ****************************** 
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
#include "appTimer/appTimer.h"

//******************************* Local Types ********************************* 
 
//***************************** Local Constants ******************************* 
 
//***************************** Local Variables ******************************* 
 
//****************************** Local Functions ****************************** 

//****************************** main ******************************
// Purpose : Continuously display formatted time information in multiple timezones
//           (GMT, IST, PST) along with optional epoch time. The display refreshes
//           every second to show real-time updates.
// Inputs  : None
// Outputs : None
// Return  : int - Returns 0 upon successful completion.
// Notes   : 
//   - Calls DisplayCurrentTime() to print the current time details.
//   - Uses sleep(1) to refresh the output every second.
//   - Runs indefinitely until manually terminated.
//*****************************************************************************

int main(void)
{
    while(1)
    {
        printf("==================================\n");
        DisplayCurrentTime();   
        printf("==================================\n\n");
        sleep(1);   
    }
    return 0;
}

// EOF
