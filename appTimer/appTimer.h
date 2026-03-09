//****************************** appTimer *************************************
// Copyright (c) 2026 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File     : appTimer.h
// Summary  : Header file for appTimer module
// Note     : Provides function declarations for time display utilities 
// Author   : Shani 
// Date     : Feb 11, 2026 
//
//*****************************************************************************
 
#ifndef _APPTIMER_H_ 
#define _APPTIMER_H_ 
 
//******************************* Include Files ******************************* 
#include <time.h>   
#include <stdio.h>  
#include <stdbool.h>
#include <stdint.h>
 
//******************************* Global Types ******************************** 
 
//***************************** Global Constants ****************************** 
 #define ARRAY_SIZE      32
 
//***************************** Global Variables ****************************** 
typedef struct _TimeDisplayInfo_
{
    uint8_t ucLabel[ARRAY_SIZE];
    uint8_t ucDate[ARRAY_SIZE];
    uint8_t ucTime[ARRAY_SIZE];
    bool blShowEpoch;
    long lEpoch;
} TimeDisplayInfo; 

//**************************** Forward Declarations *************************** 
bool GetCurrentTimeDate(TimeDisplayInfo* pstTimeInfo);
void DisplayFormattedTime(const char* pcLabel, struct tm* pstTimeInfo, 
                                            bool blShowEpoch, long lEpoch) ;
                                            
//***************************** Class Declaration ***************************** 
 
//*********************** Inline Method Implementations *********************** 
 
#endif // _APPTIMER_H_ 
// EOF
