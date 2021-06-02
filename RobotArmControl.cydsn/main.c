/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
// Valeur booleene
#define TRUE  1
#define FALSE 0

// Flags d'instructions
#define FREE  0
#define MAIN  1
#define CMD   2

#include "project.h"

// *** GLOBAL VARS *** //

              // Axe    1,  2,   3,   4,  5,   6
uint16 PosAxes[6] = {1500,850,1500,1500,850,1500};

// *** FUNCTIONS *** //

// Initialise la position du bras
uint8 ResetPosition()
{
    for(uint8 i=0; i<6; i+=1)
    {
        CyDelay(1);
    }
    return TRUE;
}
// Maintien la position du bras
uint8 SteadyPosition()
{
    for(uint8 i=0; i<6; i+=1)
    {
        
    }
    return TRUE;
}

// Fermeture de la pince
void CloseHand(uint8 muxAxe)
{
    Control_Reg_1_Write(muxAxe);
    for(int i=750 ;i<1501; i+=1) 
    {
        PWM_1_WriteCompare(i);
        CyDelay(1);
    }
} // END CloseHand

// Ouverture de la pince
void OpenHand(uint8 muxAxe)
{
    Control_Reg_1_Write(muxAxe);
    for(int i=1500; i>749; i-=1)
    {
        PWM_1_WriteCompare(i);
        CyDelay(1);
    }    
} // END OpenHand

// *** MAIN *** //
int main(void)
{
    // Enable global interrupts. 
    CyGlobalIntEnable; 

    // Place your initialization/startup code here (e.g. MyInst_Start())
    
    /*
    uint16 res;
    uint16 calc;
    uint8 press = 0;
    uint8 ctrl = 0;
    */
    
    // Init position replier - par defaut
    /*
    uint16 PosAxe1 = 1500;
    uint16 PosAxe2 = 850;
    uint16 PosAxe3 = 1500;
    uint16 PosAxe4 = 1500;
    uint16 PosAxe5 = 850;
    uint16 PosAxe6 = 1500;
    */
    
    
    LCD_Char_1_Start();
    PWM_1_Start();
    ADC_SAR_1_Start();

    AMux_1_Start();
    AMux_1_Select(0);
    
    /*
    for(int i = 0; i<7; i++)
    {
        Control_Reg_1_Write(i);
        AMux_1_Select(i);
        PWM_1_WriteCompare(1500);
        CyDelay(1500);
    }
    */
    
    for(;;)
    {
        if(SW2_Read() == FALSE) CloseHand(5);
        if(SW3_Read() == FALSE) OpenHand(5);
    
        /*if(SW2_Read() == 0 && !press)
        {   
            if(ctrl == 0) ctrl++;;
            ctrl--;
            Control_Reg_1_Write(ctrl);
            AMux_1_Select(ctrl);
            press = 1;
        }
        
        if(SW3_Read() == 0 && !press)
        {
            if(ctrl == 8) ctrl--;
            ctrl++;
            Control_Reg_1_Write(ctrl);
            AMux_1_Select(ctrl);
            press = 1;
        }
        
        if(SW2_Read() && SW3_Read()){
            
            press = 0;
        }
        
        ADC_SAR_1_StartConvert();
        ADC_SAR_1_IsEndConversion(ADC_SAR_1_WAIT_FOR_RESULT);
        res = ADC_SAR_1_GetResult16();
    
        
        LCD_Char_1_Position(0,0);
        LCD_Char_1_PrintString("Axe N :");
        LCD_Char_1_Position(1,0);
        
        calc = (2500 * res)/1023;
            if(calc <= 500) calc = 500;
            if(calc >= 2500) calc = 2500;
            
            LCD_Char_1_Position(0,8);
            LCD_Char_1_PrintNumber(Control_Reg_1_Read());
            LCD_Char_1_Position(1,0);
            LCD_Char_1_PrintNumber(calc);
            PWM_1_WriteCompare(calc);
            CyDelay(50);
            LCD_Char_1_ClearDisplay();
        
        //controle auto
            
        for(int i = 10; i < 1014; i++){
            calc = (2500 * res)/1023;
            if(calc <= 500) calc = 500;
            if(calc >= 2500) calc = 2500;
            //LCD_Char_1_PrintNumber(calc);
            LCD_Char_1_PrintNumber(Control_Reg_1_Read());
            PWM_1_WriteCompare(calc);
            CyDelay(50);
            LCD_Char_1_ClearDisplay();
        }
        
        for(int i = 1013; i > 10; i--){
            calc = (2500 * res)/1023;
            if(calc <= 500) calc = 500;
            if(calc >= 2500) calc = 2500;
            //LCD_Char_1_PrintNumber(calc);
            LCD_Char_1_PrintNumber(Control_Reg_1_Read());
            PWM_1_WriteCompare(calc);
            CyDelay(50);
            LCD_Char_1_ClearDisplay();
        }*/
       
        
        
    }
}

/* [] END OF FILE */
