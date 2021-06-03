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
                         1500,  // Axe 4
                         1500,  // Axe 5
                         1500}; // Axe 6
uint16 PosAxes[6] = {1500,  // Axe 1
                         1500,  // Axe 2
                         1500,  // Axe 3
                         1500,  // Axe 4
                         1500,  // Axe 5
                         1500};

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
    if(2500 <= newPos) newPos = 2500; // fermeture
    if(newPos <= 500) newPos = 500; // ouverture
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
    if(1500 <= newPos) newPos = 1500;
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
    uint16 const minRange = 1000;
    uint16 const maxRange = 2000;
    uint8 const speedDivider = 3;
    
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_PrintString("INIT AXE 1");
    Axe1(1000,speedDivider);
    CyDelay(100);
    Axe1(2000,speedDivider);
    CyDelay(100);
    Axe1(InitPosAxes[0],speedDivider);
    CyDelay(100);
    
    /*
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_PrintString("INIT AXE 2");
    Axe2(1700,speedDivider);
    CyDelay(100);
    Axe2(InitPosAxes[1],speedDivider);
    CyDelay(100);
    
    
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_PrintString("INIT AXE 5");
    Axe5(minRange+500,speedDivider);
    CyDelay(100);
    Axe5(maxRange+400,speedDivider);
    CyDelay(100);
    
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_PrintString("INIT AXE 1");
    Axe1(minRange-500,speedDivider);
    CyDelay(100);
    Axe1(maxRange+500,speedDivider);
    CyDelay(100);
    Axe1(InitPosAxes[0],speedDivider);
    CyDelay(100);
    
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_PrintString("INIT AXE 3");
    CyDelay(100);
    Axe3(InitPosAxes[2],speedDivider);
    CyDelay(100);
    
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_PrintString("INIT AXE 4");
    Axe4(minRange,speedDivider);
    CyDelay(100);
    Axe4(maxRange,speedDivider);
    CyDelay(100);
    Axe4(InitPosAxes[3],speedDivider);
    CyDelay(100);
    
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_PrintString("REPLACE AXE 5");
    Axe5(InitPosAxes[4],speedDivider);
    CyDelay(100);
    
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_PrintString("INIT AXE 6");
    Axe6(maxRange,speedDivider);
    CyDelay(100);
    Axe6(minRange,speedDivider);
    CyDelay(100);
    Axe6(InitPosAxes[5],speedDivider);
    CyDelay(100);
    
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_PrintString("REPLACE AXE 1");
    Axe1(minRange-400,speedDivider);
    CyDelay(100);
    Axe1(maxRange+400,speedDivider);
    CyDelay(100);
    Axe1(InitPosAxes[0],speedDivider);
    CyDelay(100);
    
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_PrintString("INIT OK");
    Axe6(500,1);
    Axe6(2500,1);
    
    */
    flag = MAIN;
    return TRUE;
}// END ResetPosition

// *** MAIN *** //
int main(void)
{
    // Enable global interrupts. 
    CyGlobalIntEnable; 

    // Place your initialization/startup code here (e.g. MyInst_Start())
    uint8 unpress = TRUE;
    uint8 done = FALSE;
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
            if(unpress == TRUE)
            {
                flag = CMD;
                Axe1(PosAxes[0]+100,1);
            }
            unpress = FALSE;
            
        }
        if(SW3_Read() == FALSE)
        {
            if(unpress == TRUE)
            {
                flag = CMD;
                Axe1(PosAxes[0]-100,1);
            }
            unpress = FALSE;
            
        }
        
        if(SW2_Read() == TRUE && SW3_Read() == TRUE && unpress == FALSE)unpress = TRUE;
        if(SW2_Read() == FALSE && SW3_Read() == FALSE && unpress == TRUE)Axe1(1500,1);
        
        if(1)
        {
            Axe1(1050,3);
            Axe6(500,1);
            done = TRUE;
        }
        
    } // END while(flag == MAIN)
        
       
           
 
   //main();
} // END main

/* [] END OF FILE */
