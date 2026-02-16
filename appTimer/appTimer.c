//**************************** appTimer ****************************** 
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
 
//******************************* Local Types ********************************* 
 
//***************************** Local Constants ******************************* 

#define ARRAY_SIZE      32
//***************************** Local Variables ******************************* 
 
//****************************** Local Functions ****************************** 
 
//****************************** DisplayFormattedTime ******************************
// Purpose : Display formatted time information including date, time, and optional epoch.
// Inputs  : plabel      - Pointer to a string label to print above the time/date.
//           t           - Pointer to a struct tm containing the time information.
//           blShowEpoch - Boolean flag to indicate whether to display epoch time.
//           Epoch       - Epoch time value to display if blShowEpoch is true.
// Outputs : None
// Return  : None
// Notes   : None
//*****************************************************************************

void DisplayFormattedTime(uint8_t* plabel, struct tm* pTimeInfo, bool blShowEpoch, time_t Epoch) 
{
    uint8_t ucDateStr[ARRAY_SIZE];
    uint8_t ucTimeStr[ARRAY_SIZE];

    strftime(ucDateStr, sizeof(ucDateStr), "%d/%m/%Y", pTimeInfo);//pTimeInfo
    strftime(ucTimeStr, sizeof(ucTimeStr), "%I:%M:%S %p", pTimeInfo);

    printf("%s\n----------------\n", plabel);
    printf("Time : %s\n", ucTimeStr);
    printf("Date : %s\n", ucDateStr);

    if (blShowEpoch == true) 
    {
        printf("Epoch: %ld\n", Epoch);
    }
    printf("\n");
}

//****************************** DisplayCurrentTime ******************************
// Purpose : Retrieve and display the current system time in multiple time zones.
// Inputs  : None
// Outputs : Prints formatted time and date for UTC, IST, and PST to the console.
// Return  : None
// Notes   : None
//*****************************************************************************

void DisplayCurrentTime() 
{
    time_t RawTime;
    struct tm TimeInfo;

    // Get current system time
    time(&RawTime);

    // GMT (UTC)
    gmtime_r(&RawTime, &TimeInfo);
    DisplayFormattedTime("UTC (0:00)", &TimeInfo, true, RawTime);

    // IST (+05:30)
    time_t ISTTime = RawTime + 19800; 
    gmtime_r(&ISTTime, &TimeInfo);
    DisplayFormattedTime("IST (+05:30)", &TimeInfo, false, 0);

    // PST (-8:00)
    time_t PSTTime = RawTime - 28800;
    gmtime_r(&PSTTime, &TimeInfo);
    DisplayFormattedTime("PST (-8:00)", &TimeInfo, false, 0);
}
