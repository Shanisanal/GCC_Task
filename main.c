//**************************** PROJECT X ****************************** 
//  Copyright (c) 2026 
//  All Rights Reserved 
//***************************************************************************** 
// 
// File      : main.c 
// Summary   : Entry point for time display application 
// Note      : Calls functions from appTimer module to show GMT, IST, PST and Epoch 
// Author    : Your Name 
// Date      : Feb 11, 2026 
// 
//***************************************************************************** 

#include <stdio.h>
#include <unistd.h>     // for sleep()
#include "appTimer/appTimer.h"


int main(void)
{
    while(1)
    {
        printf("=====================================\n");
        displayCurrentTime();   
        printf("=====================================\n\n");

        sleep(1);   
    }

    return 0;
}

// EOF
