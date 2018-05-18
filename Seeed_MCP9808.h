#ifndef _SEEED_MCP9808_H
#define _SEEED_MCP9808_H

#include <Wire.h>

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


class IIC_OPRTS
{
    public:
        void IIC_begin(){Wire.begin();}
        s32 IIC_write_byte(u8 reg,u8 byte);
        s32 IIC_write_bytes(u8 reg,u8 bytes[],u32 bytes_len);
        void IIC_read_bytes(u8 start_reg,u8* bytes,u32 bytes_len);
        void IIC_read_byte(u8 reg,u8* byte);
        void set_iic_addr(u8 IIC_ADDR);
        
    private:
        u8 _IIC_ADDR;
};



class MCP9808:public IIC_OPRTS
{
    public:
        MCP9808(u8 IIC_ADDR=DEFAULT_IIC_ADDR);
        ~MCP9808(){}
        s32 init();
        s32 set_config(u8 addr,u16 cfg);
        s32 set_upper_limit(u8 addr,u16 cfg);
        s32 set_lower_limit(u8 addr,u16 cfg);
        s32 set_critical_limit(u8 addr,u16 cfg);
        s32 read_temp_reg(u8 addr,u16 *temp);
        void get_temp(float *temp);
        s32 set_resolution(u8 addr,u8 resolution)
    private:
        float caculate_temp(u16 temp);
};




#endif
