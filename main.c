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
 #define NUM_ZONES           3

//***************************** Local Variables ******************************* 
 
//****************************** Local Functions ****************************** 

//****************************** main *****************************************
// Purpose : Continuously display formatted time information in multiple timezones
//           (GMT, IST, PST) along with optional epoch time. The display refreshes
//           every second to show real-time updates.
// Inputs  : None
// Outputs : None
// Return  : Returns 0 upon successful completion.
// Notes   : 
//   - Calls GetCurrentTimeDate() to print the current time details.
//   - Uses sleep(1) to refresh the output every second.
//   - Runs indefinitely until manually terminated.
//*****************************************************************************

int main(void)
{
    TimeDisplayInfo stTimeInfo[NUM_ZONES] = {0};
    bool blDisplaySuccess = false;
   
    while(1)
    {
       blDisplaySuccess = GetCurrentTimeDate(stTimeInfo);

       if(blDisplaySuccess == true)
       {
            printf("==================================\n");

            for(int i = 0; i < NUM_ZONES; i++)
            {
                printf("%s\n", stTimeInfo[i].ucLabel);
                printf("----------------\n");
                printf("Time : %s\n", stTimeInfo[i].ucTime);
                printf("Date : %s\n", stTimeInfo[i].ucDate);
                
                if(stTimeInfo[i].blShowEpoch)
                {
                    printf("Epoch: %ld\n", stTimeInfo[i].lEpoch);
                }
                printf("\n");
            }

            printf("==================================\n\n");
       }
       sleep(1);   
    }
    return 0;
}

// EOF
