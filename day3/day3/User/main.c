/******************************************************************************
 * @file     main.c
 * @version  V1.00
 * $Revision: 1 $
 * $Date: 14/10/01 5:11p $
 * @brief    Template project for NUC230_240 series MCU
 *
 * @note
 * Copyright (C) 2014 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include <stdio.h>
#include "NUC230_240.h"


void SYS_Init(void)
{
    /* Enable IP clock */
    CLK->APBCLK = CLK_APBCLK_UART0_EN_Msk;
    CLK->APBCLK |= CLK_APBCLK_I2C0_EN_Msk;

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock and cyclesPerUs automatically. */
    SystemCoreClockUpdate();

    /* Set GPB multi-function pins for UART0 RXD and TXD */
    SYS->GPB_MFP &= ~(SYS_GPB_MFP_PB0_Msk | SYS_GPB_MFP_PB1_Msk);
    SYS->GPB_MFP |= SYS_GPB_MFP_PB0_UART0_RXD | SYS_GPB_MFP_PB1_UART0_TXD;
    /* for i2c */
    SYS->GPA_MFP &= ~(SYS_GPA_MFP_PA8_Msk | SYS_GPA_MFP_PA9_Msk);
    SYS->GPA_MFP |= SYS_GPA_MFP_PA8_I2C0_SDA | SYS_GPA_MFP_PA9_I2C0_SCL;

//    SYS->IPRSTC2 |= SYS_IPRSTC2_I2C0_RST_Msk;
}


int main()
{
    int8_t ch;

    /* Unlock protected registers */
    SYS_UnlockReg();

    SYS_Init();

    /* Lock protected registers */
//    SYS_LockReg();

    /* Init UART0 to 115200-8n1 for print message */
    UART_Open(UART0, 115200);
    I2C0->I2CLK = 0x36;
    I2C0->I2CON |= I2C_I2CON_ENS1_Msk;
    printf("CPU clock %d Hz\n",CLK_GetCPUFreq());

//    I2C_Open(I2C0, 1000000);
    printf("I2C clock %d Hz\n", I2C_GetBusClockFreq(I2C0));

    printf("Please Input Any Key\n\n");

    do {
        printf("Input: ");
        ch = getchar();
        printf("%c\n", ch);
    } while(1);
}

/*** (C) COPYRIGHT 2014 Nuvoton Technology Corp. ***/
