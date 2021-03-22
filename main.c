/*!**********************************************************************************************************************
@file main.c                                                                
@brief Main system file for the ENCM 369 firmware.  
***********************************************************************************************************************/

#include "configuration.h"


/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_"
***********************************************************************************************************************/
/* New variables */
volatile u32 G_u32SystemTime1ms = 0;     /*!< @brief Global system time incremented every ms, max 2^32 (~49 days) */
volatile u32 G_u32SystemTime1s  = 0;     /*!< @brief Global system time incremented every second, max 2^32 (~136 years) */
volatile u32 G_u32SystemFlags   = 0;     /*!< @brief Global system flags */

/*--------------------------------------------------------------------------------------------------------------------*/
/* External global variables defined in other files (must indicate which file they are defined in) */


/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "Main_" and be declared as static.
***********************************************************************************************************************/


/*!**********************************************************************************************************************
@fn void main(void)
@brief Main program where all tasks are initialized and executed.


***********************************************************************************************************************/

void main(void)
{
  G_u32SystemFlags |= _SYSTEM_INITIALIZING;

  /* Low level initialization */
  ClockSetup();
  SysTickSetup();
  GpioSetup();
  
  /* Driver initialization */
 
  /* Application initialization */
  UserAppInitialize();
  
  /* Exit initialization */
    
  /* Super loop */  
  while(1)
  {
    /* Drivers */
       
   /* Applications */
#if 0  //timer used for triangle/sawooth wave
      TimeXus(2);
      while(PIR3bits.TMR0IF ==0x00);
      DAC1DATL +=4;
#endif      
#if 1      //timer for sinewave 
     
    UserAppRun();
    /* System sleep */
    HEARTBEAT_OFF();
    SystemSleep();
    TimeXus(10);   //delay that obtains frequency closest to 1.00kHz
    while((PIR3 & 0x80) == 0x00){
    }
    HEARTBEAT_ON();
#endif
  } /* end while(1) main super loop */
  
} /* end main() */




/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File */
/*--------------------------------------------------------------------------------------------------------------------*/
