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
 
//***************************** Global Variables ****************************** 
 
//**************************** Forward Declarations *************************** 
void DisplayCurrentTime();   
void DisplayFormattedTime(uint8_t* plabel, struct tm* t, bool blShowEpoch, time_t Epoch) ;
 
//***************************** Class Declaration ***************************** 
 
//*********************** Inline Method Implementations *********************** 
 
#endif // _APPTIMER_H_ 
// EOF 
