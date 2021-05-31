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
    
    for(;;)
    {
        ADC_SAR_1_StartConvert();
        ADC_SAR_1_IsEndConversion(ADC_SAR_1_WAIT_FOR_RESULT);
        res = ADC_SAR_1_GetResult16();
        
        LCD_Char_1_Position(0,0);
        LCD_Char_1_PrintString("PWM :");
        LCD_Char_1_Position(1,0);
        
        //controle potentiometre
        /*
        calc = (34 * res)/1023;
        if(calc == 0) calc = 1;
        LCD_Char_1_PrintNumber(calc);
        PWM_1_WriteCompare(calc);
        CyDelay(100);
        LCD_Char_1_ClearDisplay();*/
        
        //controle auto
         
        for(int i = 100; i<1024; i++)
        {
            calc = (34 * i)/1023;
            if(calc == 0) calc = 1;
            LCD_Char_1_PrintNumber(calc);
            PWM_1_WriteCompare(calc);
            CyDelay(1);
            LCD_Char_1_ClearDisplay();
        }
        
        for(int i = 1023; i>100; i--)
        {
            calc = (34 * i)/1023;
            if(calc == 0) calc = 1;
            LCD_Char_1_PrintNumber(calc);
            PWM_1_WriteCompare(calc);
            CyDelay(1);
            LCD_Char_1_ClearDisplay();
        }
        /* Place your application code here. */
        
        //667kHz - 400kHz
        
        
    }
}

/* [] END OF FILE */
