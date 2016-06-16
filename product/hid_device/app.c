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
#include "app.h"
#include "bsp_common.h"
#include "juma_sensor.h"

#define UPDATE_INTERVAL 100

static void led_on(void* arg);
static void led_off(void* arg);

const char* board_name = "Cannon STag";

void on_ready(void)
{
    BSP_LED_On(LED0);
}


static void led_on(void* arg)
{
    BSP_LED_On(LED0);
}

static void led_off(void* arg)
{
    BSP_LED_Off(LED0);
}

