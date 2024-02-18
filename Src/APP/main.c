/*************************************************************************/
/* Authors     : Ibrahim Diab                                            */ 
/* File Name   : main.c                                                  */
/* Description : Temp project to apply on building process and makefile  */
/*************************************************************************/

#define MCU STM32F103C6

#include "../../Inc/stm32f103x.h"

#include "../../Inc/LIB/common_macros.h"
#include "../../Inc/LIB/std_types.h"

#include "../../Inc/MCAL//RCC/RCC_interface.h"
#include "../../Inc/MCAL//DIO/DIO_interface.h"

volatile uint32 main_G_bss_1;
volatile uint32 main_G_bss_2;
volatile uint32 main_G_bss_3;


volatile uint32 main_G_data_1 = 1000;
volatile uint32 main_G_data_2 = 2000;
volatile uint32 main_G_data_3 = 3000;

volatile const uint32 main_G_rodata_1 = 1111;
volatile const uint32 main_G_rodata_2 = 2222;
volatile const uint32 main_G_rodata_3 = 3333;

int main(void)
{
    const uint32 main_L_rodata = 10;
    
    RCC_initSysClk();

    DIO_setPinDirection(DIO_GPIOA, DIO_PIN2, OUTPUT_SPEED_2MHZ_PP);
    DIO_setPinDirection(DIO_GPIOA, DIO_PIN3, OUTPUT_SPEED_2MHZ_PP);

    main_G_data_1 = 300;
    main_G_data_2 = 400;
    main_G_data_3 = 500;

    main_G_bss_1 = 1111;
    main_G_bss_2 = 2222;
    main_G_bss_3 = 3333;

    if(main_G_rodata_1 > 200);
    if(main_G_rodata_2 > 200);
    if(main_G_rodata_3 > 200);
    if(rodata_L_main);
        
    while (1)
    {

            DIO_setPinValue(DIO_GPIOA, DIO_PIN2, HIGH);
            DIO_setPinValue(DIO_GPIOA, DIO_PIN3, LOW);

            for(uint16 delay =0; delay <1000; delay++);

            DIO_setPinValue(DIO_GPIOA, DIO_PIN3, HIGH);
            DIO_setPinValue(DIO_GPIOA, DIO_PIN2, LOW);
    }
    return 0;
}

