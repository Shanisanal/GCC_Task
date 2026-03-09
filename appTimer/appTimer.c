//**************************** appTimer *************************************** 
// Copyright (c) 2026 Trenser Technology Solutions
// All Rights Reserved
//***************************************************************************** 
// 
// File      : appTimer.c 
// Summary   : Implementation of time display functions for GMT, IST, PST and Epoch time 
// Note      : Provides functions declared in appTimer.h 
// Author    : Shani
// Date      : Feb 11, 2026 
// 
//***************************************************************************** 
 
//******************************* Include Files ******************************* 
#include <stdio.h>
#include <time.h>
#include "appTimer.h"
#include <stdbool.h>
 
//******************************* Local Types ********************************* 
 
//***************************** Local Constants ******************************* 
#define OFFSET_IST      19800   
#define OFFSET_PST      28800   
#define LABEL_UTC       "UTC (0:00)"
#define LABEL_IST       "IST (+05:30)"
#define LABEL_PST       "PST (-08:00)"
 #define ARRAY_SIZE      32

//***************************** Local Variables ******************************* 
 
//****************************** Local Functions ****************************** 
 
//****************************** DisplayFormattedTime **************************
// Purpose : Display formatted time information including date, time, and epoch.
// Inputs  : pcLabel    - Pointer to a string label to print above the time/date.
//           pstTimeInfo- Pointer to a struct tm containing the time information.
//           blShowEpoch- Boolean flag to indicate whether to display epoch time.
//           lEpoch     - Epoch time value to display if blShowEpoch is true.
// Outputs : None
// Return  : None
// Notes   : None
//*****************************************************************************

void DisplayFormattedTime(const char* pcLabel, struct tm* pstTimeInfo, 
                                            bool blShowEpoch, long lEpoch) 
{
    uint8_t ucDateStr[ARRAY_SIZE]= {0};
    uint8_t ucTimeStr[ARRAY_SIZE]= {0};

    if(pcLabel == NULL || pstTimeInfo == NULL) 
    {
        return;
    }

    strftime((char*)ucDateStr, sizeof(ucDateStr), "%d/%m/%Y", pstTimeInfo);
    strftime((char*)ucTimeStr, sizeof(ucTimeStr), "%I:%M:%S %p", pstTimeInfo);

    printf("%s\n----------------\n", pcLabel);
    printf("Time : %s\n", ucTimeStr);
    printf("Date : %s\n", ucDateStr);

    if (blShowEpoch == true) 
    {
        printf("Epoch: %ld\n", lEpoch);
    }
    printf("\n");
}

//****************************** GetCurrentTimeDate ******************************
// Purpose : Retrieve and display the current system time in multiple time zones.
// Inputs  : TimeDisplayInfo 
// Outputs : None
// Return  : None
// Notes   : None
//*****************************************************************************

bool GetCurrentTimeDate(void) 
{
    long lRawTime = 0;
    struct tm stTimeInfo = {0};
    bool blGetTimeSuccess = true;
    long lISTTime = 0;
    long lPSTTime = 0;

    if(blGetTimeSuccess == true)
    {
        time(&lRawTime);

        struct tm* lUTCResult = gmtime_r(&lRawTime, &stTimeInfo);

        if(lUTCResult != NULL)
        {
            DisplayFormattedTime(LABEL_UTC, &stTimeInfo, true, lRawTime);
        }
        else
        {
            blGetTimeSuccess =  false;
        }
    }

    if(blGetTimeSuccess == true)
    {
        lISTTime = lRawTime + OFFSET_IST;

        struct tm*  lISTResult = gmtime_r(&lISTTime, &stTimeInfo);

        if(lISTResult != NULL)
        {
            DisplayFormattedTime(LABEL_IST, &stTimeInfo, false, 0);
        }
        else
        {
            blGetTimeSuccess =  false;
        }
    }

    if(blGetTimeSuccess == true)
    {
        lPSTTime = lRawTime - OFFSET_PST;

        struct tm*  lPSTResult = gmtime_r(&lPSTTime, &stTimeInfo);

        if(lPSTResult != NULL)
        {
            DisplayFormattedTime(LABEL_PST, &stTimeInfo, false, 0);
        }
        else
        {
            blGetTimeSuccess =  false;
        }
  
    }

    return blGetTimeSuccess;
}

// EOF