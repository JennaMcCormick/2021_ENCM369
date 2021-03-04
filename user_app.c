/*!*********************************************************************************************************************
@file user_app.c                                                                
@brief User's tasks / applications are written here.  This description
should be replaced by something specific to the task.

------------------------------------------------------------------------------------------------------------------------
GLOBALS
- NONE

CONSTANTS
- NONE

TYPES
- NONE

PUBLIC FUNCTIONS
- NONE

PROTECTED FUNCTIONS
- void UserApp1Initialize(void)
- void UserApp1Run(void)


**********************************************************************************************************************/

#include "configuration.h"

/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_<type>UserApp1"
***********************************************************************************************************************/
/* New variables */
volatile u8 G_u8UserAppFlags;                             /*!< @brief Global state flags */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Existing variables (defined in other files -- should all contain the "extern" keyword) */
extern volatile u32 G_u32SystemTime1ms;                   /*!< @brief From main.c */
extern volatile u32 G_u32SystemTime1s;                    /*!< @brief From main.c */
extern volatile u32 G_u32SystemFlags;                     /*!< @brief From main.c */


/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "UserApp_<type>" and be declared as static.
***********************************************************************************************************************/


/**********************************************************************************************************************
Function Definitions
**********************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------*/
/*! @publicsection */                                                                                            
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------*/
/*! @protectedsection */                                                                                            
/*--------------------------------------------------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------------------------------------------------
@fn void UserAppInitialize(void)

@brief
Initializes the application's variables.

Should only be called once in main init section.

Requires:
- NONE

Promises:
- NONE

*/
void UserAppInitialize(void)
{
    LATA = 0x80;
    T0CON0 = 0x90;
    T0CON1 = 0x54;
} /* end UserAppInitialize() */

  
/*!----------------------------------------------------------------------------------------------------------------------
@fn void UserAppRun(void)

@brief Application code that runs once per system loop

Requires:
- 

Promises:
- 

*/
void UserAppRun(void)
{
    static u16 u16Counter = 0x00; // sets counter to 0
    static u8 u8Index = 0;
    u8 au8Pattern[] = {0x01,0x02,0x04,0x08,0x10,0x20};
    if(u16Counter == 0x1F4)
    {
        u16Counter =0;
        LATA = au8Pattern[u8Index];
        u8Index++;
        if(u8Index == 6) 
        {
            u8Index = 0;
        }
    }
    u16Counter++;
    
       
   // }
} 
/* end UserAppRun */
/*------------------------------------------------------------------------------------------------------------------*/
/*! @privatesection */                                                                                            
/*--------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------
 void TimeXus(INPUT_PARAMETER_)
 * Sets Timer0 to count u16Microseconds_
 * 
 * Requires:
 * -Timer0 configured such that each timer trick is 1 microsecond
 *-INPUT_PARAMETER_ is the value in microseconds to time from 1 to 65535
 * 
 * Promises:
 * -Pre-loads TMR0H:L to lock out the desired periods
 * -TMR0IF cleared
 * _Timer0 enabled
 */

void TimeXus(u16 INPUT_PARAMETER_) 
{
   /* Disable the timer*/
    T0CON0 = T0CON0 & 0x7F;
    /*Load TMROLF and TMROH*/
    TMR0H = (0xffff - INPUT_PARAMETER_) >>8;
    TMR0L = (0xffff - INPUT_PARAMETER_) <<8;
    /* Clear TMR0IF and enable Timer 0*/
    PIR3 = PIR3 & 0x7f;
    T0CON0 = T0CON0 | 0x80;
}




/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/
