/*
 * Seeed_MCP9808.h
 * Driver for DIGITAL I2C HUMIDITY AND TEMPERATURE SENSOR
 *  
 * Copyright (c) 2018 Seeed Technology Co., Ltd.
 * Website    : www.seeed.cc
 * Author     : downey
 * Create Time: May 2018
 * Change Log :
 *
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef _SEEED_MCP9808_H
#define _SEEED_MCP9808_H

#include <Wire.h>
#include <Arduino.h>

typedef int s32;
typedef long unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

#define SET_CONFIG_ADDR           0X01
#define SET_UPPER_LIMIT_ADDR      0X02
#define SET_LOWER_LIMIT_ADDR      0X03
#define SET_CRITICAL_LIMIT_ADDR   0X04

#define AMBIENT_TEMPERATURE_ADDR  0X05
#define SET_RESOLUTION_ADDR       0X08


#define DEFAULT_IIC_ADDR  0X18


#define RESOLUTION_0_5_DEGREE               0
#define RESOLUTION_0_25_DEGREE              0X01
#define RESOLUTION_0_125_DEGREE             0X02
#define RESOLUTION_0_0625_DEGREE            0X03
#define SIGN_BIT                            0X10

class IIC_OPRTS
{
    public:
        void IIC_begin(){Wire.begin();}
        s32 IIC_write_byte(u8 reg,u8 byte);
        void IIC_read_byte(u8 reg,u8* byte);
        void set_iic_addr(u8 IIC_ADDR);
        void IIC_read_16bit(u8 start_reg,u16 *value);
        s32 IIC_write_16bit(u8 reg,u16 value);
    private:
        u8 _IIC_ADDR;
};



class MCP9808:public IIC_OPRTS
{
    public:
        MCP9808(u8 IIC_ADDR=DEFAULT_IIC_ADDR);
        ~MCP9808(){};
        s32 init();
        s32 set_config(u8 addr,u16 cfg);
        s32 set_upper_limit(u8 addr,u16 cfg);
        s32 set_lower_limit(u8 addr,u16 cfg);
        s32 set_critical_limit(u8 addr,u16 cfg);
        s32 read_temp_reg(u8 addr,u16 *temp);
        void get_temp(float *temp);
        s32 set_resolution(u8 addr,u8 resolution);
    private:
        float caculate_temp(u16 temp);
};




#endif
