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
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    uint16 res;
    uint16 calc;
    
    PWM_1_Start();
    ADC_SAR_1_Start();
    LCD_Char_1_Start();
    uint8 ctrl = 2;
    uint8 press = 0;
    Control_Reg_1_Write(ctrl);
    
    for(;;)
    {
        if(SW2_Read() == 0 && !press)
        {   
            if(ctrl == 0) ctrl++;;
            ctrl--;
            Control_Reg_1_Write(ctrl);
            press = 1;
        }
        
        if(SW3_Read() == 0 && !press)
        {
            if(ctrl == 5) ctrl--;
            ctrl++;
            Control_Reg_1_Write(ctrl);
            press = 1;
        }
        
        if(SW2_Read() && SW3_Read())press = 0;
        
        ADC_SAR_1_StartConvert();
        ADC_SAR_1_IsEndConversion(ADC_SAR_1_WAIT_FOR_RESULT);
        res = ADC_SAR_1_GetResult16();
        
        LCD_Char_1_Position(0,0);
        LCD_Char_1_PrintString("Axe N :");
        LCD_Char_1_Position(1,0);
        
        //controle potentiometre
        
        calc = (2500 * res)/1023;
        if(calc <= 500) calc = 500;
        if(calc >= 2500) calc = 2500;
        //LCD_Char_1_PrintNumber(calc);
        LCD_Char_1_PrintNumber(Control_Reg_1_Read());
        PWM_1_WriteCompare(calc);
        CyDelay(50);
        LCD_Char_1_ClearDisplay();/**/
        
        //contre auto
        /*
        for(int i = 10; i<24; i++)
        {
            calc = i;//(34 * i)/1023;
            if(calc == 0) calc = 1;
            LCD_Char_1_PrintNumber(calc);
            PWM_1_WriteCompare(calc);
            CyDelay(100);
            LCD_Char_1_ClearDisplay();
        }
        
        for(int i = 23; i>9; i--)
        {
            calc = i;// (34 * i)/1023;
            if(calc == 0) calc = 1;
            LCD_Char_1_PrintNumber(calc);
            PWM_1_WriteCompare(calc);
            CyDelay(100);
            LCD_Char_1_ClearDisplay();
        }*/
        /* Place your application code here. */
        
        
        
    }
}

/* [] END OF FILE */
