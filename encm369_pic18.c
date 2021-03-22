/*!**********************************************************************************************************************
@file encm369_pic18.c                                                                
@brief This file provides core and GPIO functions for the ENCM 369 PIC activities.


------------------------------------------------------------------------------------------------------------------------
GLOBALS
- NONE

CONSTANTS
- NONE

TYPES
- NONE

PUBLIC FUNCTIONS
- 

PROTECTED FUNCTIONS
- 

***********************************************************************************************************************/

#include "configuration.h"

/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_xxBsp"
***********************************************************************************************************************/
/* New variables */




/*--------------------------------------------------------------------------------------------------------------------*/
/* Existing variables (defined in other files -- should all contain the "extern" keyword) */
extern volatile u32 G_u32SystemTime1ms;        /*!< @brief From main.c */
extern volatile u32 G_u32SystemTime1s;         /*!< @brief From main.c */
extern volatile u32 G_u32SystemFlags;          /*!< @brief From main.c */

/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "Bsp_" and be declared as static.
***********************************************************************************************************************/

/***********************************************************************************************************************
Function Definitions
***********************************************************************************************************************/


/*--------------------------------------------------------------------------------------------------------------------*/
/*! @protectedsection */                                                                                            
/*--------------------------------------------------------------------------------------------------------------------*/



/*!---------------------------------------------------------------------------------------------------------------------
@fn void ClockSetup(void)

@brief Loads all registers required to set up the processor clocks.

Requires:
- NONE

Promises:
- EFC is set up with proper flash access wait states based on 48MHz system clock
- PMC is set up with proper oscillators and clock sources

*/
void ClockSetup(void)
{
 
  
} /* end ClockSetup */


/*!---------------------------------------------------------------------------------------------------------------------
@fn void GpioSetup(void)

@brief Loads registers required to set up GPIO on the processor.

Requires:
- All configurations must match connected hardware.

Promises:
- Output pin for PA31_HEARTBEAT is configured

*/
void GpioSetup(void)
{
  LATA = 0x00; //set PORTS to off at first
  ANSELA = 0x00; //0 means digital function, 1 means analog function
  TRISA = 0x00; // set to 1 = input, 0 = output
  DAC1CON = 0xA0; // [7] 1 (Enable), [6], X, [5:4] 10, (DACXOUT on pin 2 enabled) [3:2] 00 (VDD positive reference), [1] X, [0] 0 (VSS Negative Reference)
  
} /* end GpioSetup() */


/*!---------------------------------------------------------------------------------------------------------------------
@fn  void SysTickSetup(void)

@brief Initializes the 1ms and 1s System Ticks off the core timer.

Requires:
- NVIC is setup and SysTick handler is installed

Promises:
- Both global system timers are reset and the SysTick core timer is configured for 1ms intervals

*/
void SysTickSetup(void)
{
  G_u32SystemTime1ms = 0;      
  G_u32SystemTime1s  = 0;   
  
} /* end SysTickSetup() */



/*!---------------------------------------------------------------------------------------------------------------------
@fn void SystemSleep(void)

@brief Puts the system into sleep mode.  


Requires:
- 
 * 
Promises:
- 

*/
void SystemSleep(void)
{    
  
} /* end SystemSleep(void) */



/*--------------------------------------------------------------------------------------------------------------------*/
/*! @publicsection */                                                                                            
/*--------------------------------------------------------------------------------------------------------------------*/



/*--------------------------------------------------------------------------------------------------------------------*/
/*! @privatesection */                                                                                            
/*--------------------------------------------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File */
/*--------------------------------------------------------------------------------------------------------------------*/



