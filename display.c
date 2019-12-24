void ssd1306_i2c_begin(){
  Wire.beginTransmission(0x3C);
  Wire.write((uint8_t)0x00);
}

void ssd1306_i2c_end(){
  Wire.endTransmission();
}

void ssd1306_write(uint8_t b){
  Wire.write(b);
}

void ssd1306_init(){
  Wire.begin();
  Wire.setClock(100000);
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
  ssd1306_i2c_end();

  ssd1306_i2c_begin();
  ssd1306_write(0xDA);
  ssd1306_write(0x12);
  ssd1306_write(0x81);
  ssd1306_write(0x10); //contrast
  ssd1306_write(0xD9);
  ssd1306_write(0xF1);
  ssd1306_i2c_end();

  ssd1306_i2c_begin();
  ssd1306_write(0xDB);
  ssd1306_write(0x40);
  ssd1306_write(0xA4);
  ssd1306_write(0xA6);
  ssd1306_write(0x2E);
  ssd1306_write(0xAF);
  ssd1306_i2c_end();
}

void ssd1306_update(){
  ssd1306_i2c_begin();
  ssd1306_write(0x22);
  ssd1306_write(0x00);
  ssd1306_write(0xFF);
  ssd1306_write(0x21);
  ssd1306_write(0x00);
  ssd1306_write(127);
  ssd1306_i2c_end();

  for(int i = 0;i < 1024;i++){
       if(i % 16 == 0){
        if(i) Wire.endTransmission();
        Wire.beginTransmission(0x3C);
        Wire.write((uint8_t)0x40);
       }
       Wire.write(buffer[i]);
  }
  ssd1306_i2c_end();
}