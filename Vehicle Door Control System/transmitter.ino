#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <mcp2515.h>

MCP2515 can(10); // Create an MCP2515 object with chip select pin 10
LiquidCrystal_I2C lcd(0x27, 16, 2); // Address of I2C LCD, number of columns, number of rows

void setup() {
  Serial.begin(9600);
  
  // Initialize MCP2515 chip
  can.reset();
  can.setBitrate(CAN_500KBPS);
  can.setNormalMode();
  
  // Initialize I2C LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.print("Merhaba"); // Display "Merhaba" on the LCD
  delay(1000);
  lcd.print(" Dunya"); // Display " Dunya" on the LCD
  delay(1500);
  lcd.clear();
}

void loop() {
  can_frame canMsg1;
  if (can.readMessage(&canMsg1) == MCP2515::ERROR_OK) {
    // Print message data to I2C LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ID:");
    lcd.print(canMsg1.can_id, HEX); // Print the message ID in hexadecimal format
    
    lcd.setCursor(0, 1);
    lcd.print("Data: ");
    
    for(int i=0; i<canMsg1.can_dlc; i++) {
      lcd.print(canMsg1.data[i]); // Print each byte of the message data on the LCD
    }
  } 
}