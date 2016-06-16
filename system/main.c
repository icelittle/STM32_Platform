/*
 *
 *  JUMA.IO - JUMA SDK for STM families
 *
 *  Copyright (C) 2013-2016  JUMA Technology
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the Apache V2 License as published by
 *  the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */
#include "bsp_common.h"
#include "hci.h"
#include "osal.h"
#include "profile_application.h"
#include "debug.h"
#include "bluenrg_utils.h"
#include "bluenrg_interface.h"
#include "stm32xx_timerserver.h" 
#include <stdio.h>

tProfileApplContext profileApplContext; /* Profile Application Context */
RTC_HandleTypeDef hrtc;  /* RTC handler declaration */

void GPIO_Init()
{
    GPIO_InitTypeDef  GPIO_InitStruct;

    /* Enable the GPIOA Clock */
    __GPIOA_CLK_ENABLE();

    /* Configure the GPIOA_0 pin */
    GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FAST;

    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
	
		/* Configure the GPIOA_1 pin */
    GPIO_InitStruct.Pin = GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed = GPIO_SPEED_FAST;

    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	
}

extern void on_ready(void);

int main(void)
{
		uint32_t temp_i = 0;
		bsp_init();
    on_ready();

		/* Configure the RTC */
//		TIMER_Init(&hrtc);
//		TIMER_Create(eTimerModuleID_BlueNRG_Profile_App, &(profileApplContext.profileTimer_Id), eTimerMode_Repeated, 0);

		/* Set current BlueNRG profile (HRM, HTM, GS, ...) */
		Osal_MemSet(&profileApplContext,0,sizeof(tProfileApplContext));
		BNRG_Set_Current_profile();
		BNRG_Profiles_Init(); 
		profileApplContext.initProfileFunc();
		BLE_Profile_Write_DeviceState(APPL_UNINITIALIZED);
	
    while(1)
  	{
				HCI_Process();
				profileApplContext.profileStateMachineFunc();
				if (Profile_Process_Q() == 0x00)
				{
						profileApplContext.profileApplicationProcessFunc();
				}
    }
}

