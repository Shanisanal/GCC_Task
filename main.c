//**************************** GCC_Task ***************************************
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

//****************************** main *****************************************
// Purpose : Continuously display formatted time information in multiple timezones
//           (GMT, IST, PST) along with optional epoch time.
// Inputs  : None
// Outputs : None
// Return  : Returns 0 upon successful completion.
// Notes   : Runs indefinitely until manually terminated.
//*****************************************************************************

int main(void)
{
    bool blDisplaySuccess = false;
    int lReturnCode = 1;

    while(1)
    {
       blDisplaySuccess = GetCurrentTimeDate();

       if(blDisplaySuccess == true)
       {
            printf("==================================\n");
            fflush(stdout);
            lReturnCode = 0;
       }
       else
       {
            lReturnCode = 1;
       }

       sleep(1);   
    }
    return lReturnCode;
}

// EOF
