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
              
uint16 InitPosAxes[6] = {1500,  // Axe 1
                         1500,  // Axe 2
                         1500,  // Axe 3
                         1400,  // Axe 4
                         1500,  // Axe 5
                         1600}; // Axe 6
uint16 PosAxes[6] = {};

// *** FUNCTIONS *** //

// Controle des Axes

// Axe rotation bras
uint8 Axe1(uint16 newPos, uint8 movespeed)
{
    if(2500 <= newPos) newPos = 2500;
    if(newPos <= 500) newPos = 500;
    while(newPos != PosAxes[0])
    {
        CyDelay(MOVESPEED * movespeed);
        PWM_1_WriteCompare(PosAxes[0]);
        if(PosAxes[0] <= newPos)PosAxes[0]++;
        else if(newPos <= PosAxes[0])PosAxes[0]--;
        else newPos++;
    }
    flag = MAIN;
    return TRUE;
} // END Axe1

// Axe bras
uint8 Axe2(uint16 newPos, uint8 movespeed)
{
    if(2500 <= newPos) newPos = 2500;
    if(newPos <= 500) newPos = 500;
    while(newPos != PosAxes[1])
    {
        CyDelay(MOVESPEED * movespeed);
        PWM_2_WriteCompare(PosAxes[1]);
        if(PosAxes[1] <= newPos)PosAxes[1]++;
        else if(newPos <= PosAxes[1])PosAxes[1]--;
        else newPos++;
    }
    flag = MAIN;
    return TRUE;
}// END Axe2

// Axe avant-bras
uint8 Axe3(uint16 newPos, uint8 movespeed)
{
    if(2500 <= newPos) newPos = 2500;
    if(newPos <= 500) newPos = 500;
    while(newPos != PosAxes[2])
    {
        CyDelay(MOVESPEED * movespeed);
        PWM_3_WriteCompare(PosAxes[2]);
        if(PosAxes[2] <= newPos)PosAxes[2]++;
        else if(newPos <= PosAxes[2])PosAxes[2]--;
        else newPos++;
    }
    flag = MAIN;
    return TRUE;
}// END Axe3

// Axe rotation poigné
uint8 Axe4(uint16 newPos, uint8 movespeed)
{
    if(2500 <= newPos) newPos = 2500;
    if(newPos <= 500) newPos = 500;
    while(newPos != PosAxes[3])
    {
        CyDelay(MOVESPEED * movespeed);
        PWM_4_WriteCompare(PosAxes[3]);
        if(PosAxes[3] <= newPos)PosAxes[3]++;
        else if(newPos <= PosAxes[3])PosAxes[3]--;
        else newPos++;
    }
    flag = MAIN;
    return TRUE;
}// END Axe4

// Axe pivot poigné
uint8 Axe5(uint16 newPos, uint8 movespeed)
{
    if(2500 <= newPos) newPos = 2500;
    if(newPos <= 500) newPos = 500;
    while(newPos != PosAxes[4])
    {
        CyDelay(MOVESPEED * movespeed);
        PWM_5_WriteCompare(PosAxes[4]);
        if(PosAxes[4] <= newPos)PosAxes[4]++;
        else if(newPos <= PosAxes[4])PosAxes[4]--;
        else newPos++;
    }
    flag = MAIN;
    return TRUE;
}// END Axe5

// Axe pince
uint8 Axe6(uint16 newPos, uint8 movespeed)
{
    if(1600 <= newPos) newPos = 1600;
    if(newPos <= 750) newPos = 750;
    while(newPos != PosAxes[5])
    {   
        CyDelay(MOVESPEED * movespeed);
        PWM_6_WriteCompare(PosAxes[5]);
        if(PosAxes[5] <= newPos)PosAxes[5]++;
        else if(newPos <= PosAxes[5])PosAxes[5]--;
        else newPos++;
    }
    flag = MAIN;
    return TRUE;
}// END Axe6

// 
// Initialise la position du bras
uint8 ResetPosition()
{
    uint16 const minRange = 850;
    uint16 const maxRange = 1850;
    uint8 const speedDivider = 3;
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_PrintString("INIT AXE 1");
    Axe1(minRange,speedDivider);
    Axe1(maxRange,speedDivider);
    Axe1(InitPosAxes[0],speedDivider);
    
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_PrintString("INIT AXE 2");
    //PWM_3_Stop();
    //Axe2(1000,speedDivider);
    //Axe2(1700,speedDivider);
    Axe2(InitPosAxes[1],speedDivider);
    //PWM_3_Start();
    
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_PrintString("INIT AXE 3");
    //Axe3(minRange,speedDivider);
    //Axe3(maxRange,speedDivider);
    Axe3(InitPosAxes[2],speedDivider);
    
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_PrintString("INIT AXE 4");
    Axe4(minRange,speedDivider);
    Axe4(maxRange,speedDivider);
    Axe4(InitPosAxes[3],speedDivider);
    
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_PrintString("INIT AXE 5");
    Axe5(minRange,speedDivider);
    Axe5(maxRange,speedDivider);
    Axe5(InitPosAxes[4],speedDivider);
    
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_PrintString("INIT AXE 6");
    Axe6(maxRange,speedDivider);
    Axe6(minRange,speedDivider);
    Axe6(InitPosAxes[5],speedDivider);
    
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_PrintString("INIT OK");
    Axe6(500,1);
    Axe6(2500,1);
    
    flag = MAIN;
    return TRUE;
}// END ResetPosition

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
        
        LCD_Char_1_Start();
        LCD_Char_1_ClearDisplay();
        
        ResetPosition();
        flag = MAIN;
    }// END if(flag == FREE)

    
    while(flag == MAIN)
    {
        
        if(SW2_Read() == FALSE)
        {
            flag = CMD; 
            //CloseHand();
            Axe6(850,1);
            
        }
        if(SW3_Read() == FALSE)
        {
            flag = CMD;
            //OpenHand();
            Axe6(1500,1);
           
        }
    } // END while(flag == MAIN)
        
       
           
 
   main();
} // END main

/* [] END OF FILE */
