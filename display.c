#include <stdint.h>
#include "twi.h"

uint8_t buffer[1024];

void i2c_write(uint8_t addr, uint8_t data, uint8_t stop){
	twi_writeTo(addr, &data, 1, 1, stop);
}

void ssd1306_i2c_begin(){
  i2c_write(0x3C, 0x00, 1);
  /*twi_writeTo(0x3C, )
  beginTransmission(0x3C);
  Wire.write((uint8_t)0x00);*/
}

void ssd1306_i2c_end(){
  //Wire.endTransmission();
}

void ssd1306_write(uint8_t b){
  i2c_write(0x3C, b, 1);
}

void ssd1306_init(){
  twi_init();
  twi_setFrequency(100000);
  ssd1306_i2c_begin();
  ssd1306_write(0xAE);
  ssd1306_write(0xD5);
  ssd1306_write(0x80);
  ssd1306_write(0xA8);
  ssd1306_write(63);
  ssd1306_write(0xD3);
  ssd1306_write(0x00);
  ssd1306_write(0x40);
  ssd1306_write(0x8D);
  ssd1306_write(0x14);
  ssd1306_write(0x20);
  ssd1306_write(0x00);
  ssd1306_write(0xA1);
  ssd1306_write(0xC8);

  ssd1306_write(0xDA);
  ssd1306_write(0x12);
  ssd1306_write(0x81);
  ssd1306_write(0x10); //contrast
  ssd1306_write(0xD9);
  ssd1306_write(0xF1);
//  ssd1306_i2c_end();

  //ssd1306_i2c_begin();
  ssd1306_write(0xDB);
  ssd1306_write(0x40);
  ssd1306_write(0xA4);
  ssd1306_write(0xA6);
  ssd1306_write(0x2E);
  ssd1306_write(0xAF);
 // ssd1306_i2c_end();
}

void ssd1306_update(){
  ssd1306_write(0x22);
  ssd1306_write(0x00);
  ssd1306_write(0xFF);
  ssd1306_write(0x21);
  ssd1306_write(0x00);
  ssd1306_write(127);
  i2c_write(0x3C, (uint8_t)0x40, 0);

  for(int i = 0;i < 1024;i++){
       i2c_write(0x3C, 0x40, i == 1023);
  }
}