//**************************** PROJECT X ****************************** 
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
 
//***************************** Local Variables ******************************* 
 
//****************************** Local Functions ****************************** 
 
//*********************** Class Method Implementations ************************ 

void displayFormattedTime(const char* label, struct tm* t, int showEpoch, time_t epoch) {
    char dateStr[32];
    char timeStr[32];

    // Format date and time
    strftime(dateStr, sizeof(dateStr), "%d/%m/%Y", t);
    strftime(timeStr, sizeof(timeStr), "%I:%M:%S %p", t);

    // Print in your desired format
    printf("%s\n----------------\n", label);
    printf("Time : %s\n", timeStr);
    printf("Date : %s\n", dateStr);

    if (showEpoch) {
        printf("Epoch: %ld\n", epoch);
    }
    printf("\n");
}

void displayCurrentTime() {
    time_t rawtime;
    struct tm timeinfo;

    // Get current system time
    time(&rawtime);

    // GMT (UTC)
    gmtime_r(&rawtime, &timeinfo);
    displayFormattedTime("UTC (0:00)", &timeinfo, 1, rawtime);

    // IST (+05:30)
    time_t istTime = rawtime + 19800; // 5h30m offset in seconds
    gmtime_r(&istTime, &timeinfo);
    displayFormattedTime("IST (+05:30)", &timeinfo, 0, 0);

    // PST (-8:00)
    time_t pstTime = rawtime - 28800; // 8h offset in seconds
    gmtime_r(&pstTime, &timeinfo);
    displayFormattedTime("PST (-8:00)", &timeinfo, 0, 0);
}
