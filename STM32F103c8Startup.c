/* Author       : Ibrahim Diab   www.linkedin.com/in/ibrahim-diab1 */
/* Description  : Startup file for STM32F103c8                     */
/* Requirements : Memory boundaries Symbols from linker script     */

#include "Inc/LIB/std_types.h"  

#ifndef NULL
#define NULL (void*)0
#endif

#define SRAM_START      (0x20000000)
#define SRAM_SIZE       (20 * 1024)
#define SRAM_END        (0x20005000)
#define STACK_START     SRAM_END

extern uint32 _erodata;
extern uint32 _sdata;
extern uint32 _edata;
extern uint32 _sbss;
extern uint32 _ebss;

int main(void);

void Default_Handler(void)
{
    while(1);
}

void Reset_Handler(void)
{
    uint8 * src , *dst;
    uint32 size;

    // Reserve and initialize .bss section in SRAM.
    dst = (uint8*)&_sbss;
    size = ((uint32)&_ebss - (uint32)&_sbss);
    for(uint32 block =0; block < size; block++)
    {
        *dst = 0;
        dst++;
    }

    // Copy .data section from Flash to SRAM
    dst = (uint8*)&_sdata;
    src = (uint8*)&_erodata;
    size = ((uint32)&_edata - (uint32)&_sdata);
    for(uint32 block =0; block < size; block++)
    {
        *dst = *src;
        ++src;
        ++dst;
    }

    // Calling main function finally :)
    main();
}

void NMI_Handler                (void) __attribute__((weak,alias("Default_Handler")));
void HardFault_Handler          (void) __attribute__((weak,alias("Default_Handler")));
void MemManage_Handler          (void) __attribute__((weak,alias("Default_Handler")));
void BusFault_Handler           (void) __attribute__((weak,alias("Default_Handler")));
void UsageFault_Handler         (void) __attribute__((weak,alias("Default_Handler")));
void SVC_Handler                (void) __attribute__((weak,alias("Default_Handler")));
void DebugMon_Handler           (void) __attribute__((weak,alias("Default_Handler")));
void PendSV_Handler             (void) __attribute__((weak,alias("Default_Handler")));
void SysTick_Handler            (void) __attribute__((weak,alias("Default_Handler")));
void WWDG_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void PVD_IRQHandler             (void) __attribute__((weak,alias("Default_Handler")));
void TAMP_STAMP_IRQHandler      (void) __attribute__((weak,alias("Default_Handler")));
void RTC_WKUP_IRQHandler        (void) __attribute__((weak,alias("Default_Handler")));
void FLASH_IRQHandler           (void) __attribute__((weak,alias("Default_Handler")));
void RCC_IRQHandler             (void) __attribute__((weak,alias("Default_Handler")));
void EXTI0_IRQHandler           (void) __attribute__((weak,alias("Default_Handler")));
void EXTI1_IRQHandler           (void) __attribute__((weak,alias("Default_Handler")));
void EXTI2_IRQHandler           (void) __attribute__((weak,alias("Default_Handler")));
void EXTI3_IRQHandler           (void) __attribute__((weak,alias("Default_Handler")));
void EXTI4_IRQHandler           (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Stream1_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Stream2_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Stream3_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Stream4_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Stream5_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Stream6_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA1_Stream7_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void ADC1_2_IRQHandler          (void) __attribute__((weak,alias("Default_Handler")));
void USB_HP_CAN_TX_IRQHandler   (void) __attribute__((weak,alias("Default_Handler")));
void USB_LP_CAN_RX0_IRQHandler  (void) __attribute__((weak,alias("Default_Handler")));
void CAN1_RX1_IRQHandler        (void) __attribute__((weak,alias("Default_Handler")));
void CAN1_SCE_IRQHandler        (void) __attribute__((weak,alias("Default_Handler")));
void EXTI9_5_IRQHandler         (void) __attribute__((weak,alias("Default_Handler")));
void TIM1_BRK_TIM9_IRQHandler   (void) __attribute__((weak,alias("Default_Handler")));
void TIM1_UP_TIM10_IRQHandler   (void) __attribute__((weak,alias("Default_Handler")));
void TIM1_TRG_COM_TIM11_IRQHandl(void) __attribute__((weak,alias("Default_Handler")));
void TIM1_CC_IRQHandler         (void) __attribute__((weak,alias("Default_Handler")));
void TIM2_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void TIM3_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void TIM4_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void I2C1_EV_IRQHandler         (void) __attribute__((weak,alias("Default_Handler")));
void I2C1_ER_IRQHandler         (void) __attribute__((weak,alias("Default_Handler")));
void I2C2_EV_IRQHandler         (void) __attribute__((weak,alias("Default_Handler")));
void I2C2_ER_IRQHandler         (void) __attribute__((weak,alias("Default_Handler")));
void SPI1_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void SPI2_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void USART1_IRQHandler          (void) __attribute__((weak,alias("Default_Handler")));
void USART2_IRQHandler          (void) __attribute__((weak,alias("Default_Handler")));
void USART3_IRQHandler          (void) __attribute__((weak,alias("Default_Handler")));
void EXTI15_10_IRQHandler       (void) __attribute__((weak,alias("Default_Handler")));
void RTC_Alarm_IRQHandler       (void) __attribute__((weak,alias("Default_Handler")));
void OTG_FS_WKUP_IRQHandler     (void) __attribute__((weak,alias("Default_Handler")));
void TIM8_BRK_TIM12_IRQHandler  (void) __attribute__((weak,alias("Default_Handler")));
void TIM8_UP_TIM13_IRQHandler   (void) __attribute__((weak,alias("Default_Handler")));
void TIM8_TRG_COM_TIM14_IRQHandl(void) __attribute__((weak,alias("Default_Handler")));
void TIM8_CC_IRQHandler         (void) __attribute__((weak,alias("Default_Handler")));
void ADC3_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void FSMC_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void SDIO_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void TIM5_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void SPI3_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void UART4_IRQHandler           (void) __attribute__((weak,alias("Default_Handler")));
void UART5_IRQHandler           (void) __attribute__((weak,alias("Default_Handler")));
void TIM6_DAC_IRQHandler        (void) __attribute__((weak,alias("Default_Handler")));
void TIM7_IRQHandler            (void) __attribute__((weak,alias("Default_Handler")));
void DMA2_Stream1_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA2_Stream2_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA2_Stream3_IRQHandler    (void) __attribute__((weak,alias("Default_Handler")));
void DMA2_Stream4_5_IRQHandler  (void) __attribute__((weak,alias("Default_Handler")));



uint32 isr_vector[] __attribute__ ((section(".isr_vector")))=
{
    STACK_START                           ,
    (uint32)&Reset_Handler                ,
    (uint32)&NMI_Handler                  ,
    (uint32)&HardFault_Handler            ,
    (uint32)&MemManage_Handler            ,
    (uint32)&BusFault_Handler             ,
    (uint32)&UsageFault_Handler           ,
     NULL                                 ,
     NULL                                 ,
     NULL                                 ,
     NULL                                 ,
    (uint32)&SVC_Handler                  ,
    (uint32)&DebugMon_Handler             ,
     NULL                                 ,
    (uint32)&PendSV_Handler               ,
    (uint32)&SysTick_Handler              ,
    (uint32)&WWDG_IRQHandler              ,
    (uint32)&PVD_IRQHandler               ,
    (uint32)&TAMP_STAMP_IRQHandler        ,
    (uint32)&RTC_WKUP_IRQHandler          ,
    (uint32)&FLASH_IRQHandler             ,
    (uint32)&RCC_IRQHandler               ,
    (uint32)&EXTI0_IRQHandler             ,
    (uint32)&EXTI1_IRQHandler             ,
    (uint32)&EXTI2_IRQHandler             ,
    (uint32)&EXTI3_IRQHandler             ,
    (uint32)&EXTI4_IRQHandler             ,
    (uint32)&DMA1_Stream1_IRQHandler      ,
    (uint32)&DMA1_Stream2_IRQHandler      ,
    (uint32)&DMA1_Stream3_IRQHandler      ,
    (uint32)&DMA1_Stream4_IRQHandler      ,
    (uint32)&DMA1_Stream5_IRQHandler      ,
    (uint32)&DMA1_Stream6_IRQHandler      ,
    (uint32)&DMA1_Stream7_IRQHandler      ,
    (uint32)&ADC1_2_IRQHandler            ,
    (uint32)&USB_HP_CAN_TX_IRQHandler     ,
    (uint32)&USB_LP_CAN_RX0_IRQHandler    ,
    (uint32)&CAN1_RX1_IRQHandler          ,
    (uint32)&CAN1_SCE_IRQHandler          ,
    (uint32)&EXTI9_5_IRQHandler           ,
    (uint32)&TIM1_BRK_TIM9_IRQHandler     ,
    (uint32)&TIM1_UP_TIM10_IRQHandler     ,
    (uint32)&TIM1_TRG_COM_TIM11_IRQHandl  ,
    (uint32)&TIM1_CC_IRQHandler           ,
    (uint32)&TIM2_IRQHandler              ,
    (uint32)&TIM3_IRQHandler              ,
    (uint32)&TIM4_IRQHandler              ,
    (uint32)&I2C1_EV_IRQHandler           ,
    (uint32)&I2C1_ER_IRQHandler           ,
    (uint32)&I2C2_EV_IRQHandler           ,
    (uint32)&I2C2_ER_IRQHandler           ,
    (uint32)&SPI1_IRQHandler              ,
    (uint32)&SPI2_IRQHandler              ,
    (uint32)&USART1_IRQHandler            ,
    (uint32)&USART2_IRQHandler            ,
    (uint32)&USART3_IRQHandler            ,
    (uint32)&EXTI15_10_IRQHandler         ,
    (uint32)&RTC_Alarm_IRQHandler         ,
    (uint32)&OTG_FS_WKUP_IRQHandler       ,
    (uint32)&TIM8_BRK_TIM12_IRQHandler    ,
    (uint32)&TIM8_UP_TIM13_IRQHandler     ,
    (uint32)&TIM8_TRG_COM_TIM14_IRQHandl  ,
    (uint32)&TIM8_CC_IRQHandler           ,
    (uint32)&ADC3_IRQHandler              ,
    (uint32)&FSMC_IRQHandler              ,
    (uint32)&SDIO_IRQHandler              ,
    (uint32)&TIM5_IRQHandler              ,
    (uint32)&SPI3_IRQHandler              ,
    (uint32)&UART4_IRQHandler             ,
    (uint32)&UART5_IRQHandler             ,
    (uint32)&TIM6_DAC_IRQHandler          ,
    (uint32)&TIM7_IRQHandler              ,
    (uint32)&DMA2_Stream1_IRQHandler      ,
    (uint32)&DMA2_Stream2_IRQHandler      ,
    (uint32)&DMA2_Stream3_IRQHandler      ,
    (uint32)&DMA2_Stream4_5_IRQHandler
};