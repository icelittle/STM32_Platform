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

int main(void)
{
		uint32_t temp_i = 0;
		bsp_init();
    dispatch_init();
    on_ready();
	  GPIO_Init();
	
    while(1)
  	{
				if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)) {
						temp_i++;
						printf("ok : %d!\r\n", temp_i);
						HAL_Delay(20);
				}
    }
}

