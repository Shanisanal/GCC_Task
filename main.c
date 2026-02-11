//**************************** PROJECT X ****************************** 
//  Copyright (c) 2026 
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
 
//*********************** Class Method Implementations ************************

int main(void)
{
    while(1)
    {
        printf("=====================================\n");
        DisplayCurrentTime();   
        printf("=====================================\n\n");

        sleep(1);   
    }

    return 0;
}

// EOF
