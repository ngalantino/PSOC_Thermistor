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
#include "math.h"  // Math functions
#include "float.h" // Floating point routines

uint8 count_1;
uint32 loop_counter, LCD_write_counter, thermistor_R;
uint16 R_1_result, thermistor_result;
int16 thermistor_mV, R_1_mV, temperature;
float R_1_result_f, R_1_mV_f, thermistor_mV_f, ratio_f, voltage_f;
float thermistor_RA_f, thermistor_RB_f;
float current_mA_f, temperature_K_f;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    ADC_DelSig_1_Start(); // Power up ADC
    AMux_1_Start(); // Power up MUX
    
    

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    LCD_Char_1_Start(); 
    LCD_Char_1_Position(0, 0);
    LCD_Char_1_PrintString("Thermistor Test");
    
    while(1)
    {
        Pin_1_Write(1);
        
        loop_counter++;
        LCD_write_counter++;
        
        AMux_1_Select(0);  // Select channel 0 on MUX for 10K resistor.
        ADC_DelSig_1_StartConvert();  // Start ADC conversions.
        
        ADC_DelSig_1_IsEndConversion(ADC_DelSig_1_WAIT_FOR_RESULT);  // Wait for ADC to finish conversion
        
        LCD_Char_1_Position(1, 1);
        LCD_Char_1_PrintString("                ");
        LCD_Char_1_Position(1, 6);
        LCD_Char_1_PrintU32Number(loop_counter);
        CyDelay(250);
        
        Pin_1_Write(0);
        
        
        
        
        
    }
}

/* [] END OF FILE */
