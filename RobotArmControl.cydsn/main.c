/* ========================================
 *
 * Copyright Pesage du Sud-Ouest, 2021
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Pesage du Sud-Ouest.
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

// Rapidité des mouvement
// 0 plus rapide | 10+ moins rapide
// defaut 1
#define MOVESPEED 1

#include "project.h"

// *** GLOBAL VARS *** //

uint8 flag = FREE;
              // Axe    1,  2,   3,   4,  5,   6
uint16 InitPosAxes[6] = {1500,850,1500,1500,1500,1500};
uint16 PosAxes[6] = {1500,850,1500,1500,1500,1500};

// *** FUNCTIONS *** //

// Initialise la position du bras
uint8 ResetPosition()
{
   flag = MAIN;
   return TRUE;
}// END ResetPosition

// Controle des Axes

// Axe rotation bras
uint8 Axe1(uint16 newPos)
{
    while(newPos != PosAxes[0])
    {
        CyDelay(MOVESPEED);
        PWM_1_WriteCompare(PosAxes[0]);
        if(PosAxes[0] <= newPos)PosAxes[0]++;
        else if(newPos <= PosAxes[0])PosAxes[0]--;
        else newPos++;
    }
    flag = MAIN;
    return TRUE;
} // END Axe1

// Axe bras
uint8 Axe2(uint16 newPos)
{
    while(newPos != PosAxes[1])
    {
        CyDelay(MOVESPEED);
        PWM_2_WriteCompare(PosAxes[1]);
        if(PosAxes[0] <= newPos)PosAxes[1]++;
        else if(newPos <= PosAxes[0])PosAxes[1]--;
        else newPos++;
    }
    flag = MAIN;
    return TRUE;
    flag = MAIN;
    return TRUE;
}// END Axe2

// Axe avant-bras
uint8 Axe3(uint16 newPos)
{
    while(newPos != PosAxes[2])
    {
        CyDelay(MOVESPEED);
        PWM_1_WriteCompare(PosAxes[2]);
        if(PosAxes[0] <= newPos)PosAxes[2]++;
        else if(newPos <= PosAxes[0])PosAxes[2]--;
        else newPos++;
    }
    flag = MAIN;
    return TRUE;
}// END Axe3

// Axe rotation poigné
uint8 Axe4(uint16 newPos)
{
    while(newPos != PosAxes[3])
    {
        CyDelay(MOVESPEED);
        PWM_1_WriteCompare(PosAxes[3]);
        if(PosAxes[0] <= newPos)PosAxes[3]++;
        else if(newPos <= PosAxes[0])PosAxes[3]--;
        else newPos++;
    }
    flag = MAIN;
    return TRUE;
}// END Axe4

// Axe pivot poigné
uint8 Axe5(uint16 newPos)
{
    while(newPos != PosAxes[4])
    {
        CyDelay(MOVESPEED);
        PWM_1_WriteCompare(PosAxes[4]);
        if(PosAxes[0] <= newPos)PosAxes[4]++;
        else if(newPos <= PosAxes[0])PosAxes[4]--;
        else newPos++;
    }
    flag = MAIN;
    return TRUE;
}// END Axe5

// Axe pince
uint8 Axe6(uint16 newPos)
{
    if(1600 <= newPos) newPos = 1600;
    if(newPos <= 750) newPos = 750;
    while(newPos != PosAxes[5])
    {   
        CyDelay(MOVESPEED);
        PWM_6_WriteCompare(PosAxes[5]);
        if(PosAxes[0] <= newPos)PosAxes[5]++;
        else if(newPos <= PosAxes[0])PosAxes[5]--;
        else newPos++;
    }
    flag = MAIN;
    return TRUE;
}// END Axe6

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
    if(flag == FREE)
    {
        PWM_1_Start();
        PWM_2_Start();
        PWM_3_Start();
        PWM_4_Start();
        PWM_5_Start();
        PWM_6_Start();
        
        PWM_1_WriteCompare(PosAxes[0]);
        PWM_2_WriteCompare(PosAxes[1]);
        PWM_3_WriteCompare(PosAxes[2]);
        PWM_4_WriteCompare(PosAxes[3]);
        PWM_5_WriteCompare(PosAxes[4]);
        PWM_6_WriteCompare(PosAxes[5]);
        //ResetPosition();
        flag = MAIN;
    }// END if(flag == FREE)

    /*
    for(int i = 0; i<7; i++)
    {
        Control_Reg_1_Write(i);
        AMux_1_Select(i);
        PWM_1_WriteCompare(1500);
        CyDelay(1500);
    }
    */
    
    while(flag == MAIN)
    {
        
        if(SW2_Read() == FALSE)
        {
            flag = CMD; 
            //CloseHand();
            Axe6(500);
        }
        if(SW3_Read() == FALSE)
        {
            flag = CMD;
            //OpenHand();
            Axe6(2500);
        }
    } // END while(flag == MAIN)
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
       
           
 
   main();
} // END main

/* [] END OF FILE */
