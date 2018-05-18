#include "Seeed_MCP9808.h"







s32 MCP9808::set_config(u8 addr,u16 cfg)
{
    return IIC_write_bytes(addr,(u8*)&cfg,sizeof(u16));
}

s32 MCP9808::set_upper_limit(u8 addr,u16 cfg)
{
    return IIC_write_bytes(addr,(u8*)&cfg,sizeof(u16));
}

s32 MCP9808::set_lower_limit(u8 addr,u16 cfg)
{
    return IIC_write_bytes(addr,(u8*)&cfg,sizeof(u16));
}

s32 MCP9808::set_critical_limit(u8 addr,u16 cfg)
{
    return IIC_write_bytes(addr,(u8*)&cfg,sizeof(u16));
}

s32 MCP9808::set_resolution(u8 addr,u8 resolution)
{
    return IIC_write_byte(addr,resolution);
}



s32 MCP9808::read_temp_reg(u8 addr,u16 *temp)
{
    IIC_read_bytes(addr,(u8*)temp,sizeof(u16));
}
float MCP9808::caculate_temp(u16 temp)
{
    
}
void MCP9808::get_temp(float *temp)
{
    
}






s32 MCP9808::init()
{
    s32 ret=0;
    IIC_begin();
    u16 cfg_data=0x0039;
    if(set_config(SET_CONFIG_ADDR,cfg_data))
    {
        return -1;
    }


}   

MCP9808::MCP9808(u8 IIC_ADDR)
{
    set_iic_addr(IIC_ADDR);
}




/**********************************************************************************************************/
/************************************************IIC PART************************************************/
/**********************************************************************************************************/
// void IIC_OPRTS::IIC_begin()
// {
//     Wire.begin();
// }


s32 IIC_OPRTS::IIC_write_byte(u8 reg,u8 byte)
{
    Wire.beginTransmission(_IIC_ADDR);
    Wire.write(reg);
    Wire.write(byte);
    return Wire.endTransmission();
}

s32 IIC_OPRTS::IIC_write_bytes(u8 reg,u8 bytes[],u32 bytes_len)
{
    Wire.beginTransmission(_IIC_ADDR);
    Wire.write(reg);
    for(int i=0;i<bytes_len;i++)
    {
        Wire.write(bytes[i]);
    }
    return Wire.endTransmission();
}

void IIC_OPRTS::IIC_read_byte(u8 reg,u8* byte)
{
    Wire.beginTransmission(_IIC_ADDR);
    Wire.write(reg);
    Wire.endTransmission(false);

    Wire.requestFrom(_IIC_ADDR,(u8)1);
    while(1!=Wire.available());
    *byte=Wire.read();
    
}

void IIC_OPRTS::IIC_read_bytes(u8 start_reg,u8* bytes,u32 bytes_len)
{
    Wire.beginTransmission(_IIC_ADDR);
    Wire.write(start_reg);
    Wire.endTransmission(false);

    Wire.requestFrom(_IIC_ADDR,(u8)bytes_len);
     while(bytes_len!=Wire.available());
    for(int i=0;i<bytes_len;i++)
    {
        bytes[i]=Wire.read();
    }
}

void IIC_OPRTS::set_iic_addr(u8 IIC_ADDR)
{
    _IIC_ADDR=IIC_ADDR;
}

