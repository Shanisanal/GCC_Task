//**************************** LedToggle ****************************** 
// Copyright (c) 2026 Trenser Technology Solutions
// All Rights Reserved
//***************************************************************************** 
// 
// File      : LedToggle.c 
// Summary   : Implementation of LED toggle print functionality for simulation purposes
// Note      : Provides functions declared in LedToggle.h  
// Author    : Shani
// Date      : Feb 17, 2026 
// 
//***************************************************************************** 
 
//******************************* Include Files ******************************* 
#include <stdio.h>
#include <stdbool.h>
#include "LedToggle.h"
 
//******************************* Local Types ********************************* 

//***************************** Local Constants ******************************* 

//***************************** Local Variables ******************************* 
 
//****************************** Local Functions ****************************** 
 
//******************************** ToggleLED ************************************
// Purpose : Display the current LED state as either "LED ON" or "LED OFF".
// Inputs  : bLedState - Boolean flag indicating the LED state.
//                     - true  : LED is ON
//                     - false : LED is OFF
// Outputs : Produces terminal print indicating the LED state.
// Return  : None
// Notes   : None
//********************************************************************************
void ToggleLED(bool bLedState)
{
    if(bLedState == true)
    {
        printf("LED ON\n");
    }
    else 
    {
        printf("LED OFF\n");
    }


}