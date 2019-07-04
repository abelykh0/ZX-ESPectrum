/*
   AY Emulator funcions
*/

#include <Arduino.h>

uint8_t ay_register_table[14];
uint8_t ay_command[3];

void ay_reset()
{
  uint8_t ay_reset_table[29];

  memset(ay_reset_table,0,29);
  //memset(ay_register_table,0,14);
  ay_reset_table[0] = 255;
  for(byte i = 0; i < 14; i++)
  {
     ay_reset_table[i*2+1]=i;
  }
  Serial2.write(ay_register_table,29);
}

void ay_write_register(uint8_t ay_register, uint8_t value)
{
ay_command[0]=0xff;
            ay_command[1]=ay_register;
            ay_command[2]=value;
            Serial2.write(ay_command,3);
            ay_register_table[ay_register]=value;
}

uint8_t ay_read_register(uint8_t ay_register)
{
  return ay_register_table[ay_register];
}

void ay_restore()
{
  for (uint8_t ay_register=0;ay_register < 14; ay_register++)
  {
    ay_write_register(ay_register,ay_register_table[ay_register]);
  }
}
