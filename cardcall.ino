#include <LiquidCrystal.h>
#include "Timer.h"
#include "Cartao.h"

//
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//
Cartao cartao;
Timer timer(3000);
Timer timer2(5000);

void setup() {
  // Serial Settings
  Serial.begin(115200);
  Serial.println("UP AND RUNNING!");
  
  // RFI Settings
  SPI.begin();
  RC522.init();
  
  // LCD Settings
  lcd.begin(16, 2);
  lcd.setCursor(2, 0);
  lcd.print("Aproxime seu");

  //
  delay(1000);  
}

void onReadCard(String card_id) {
  Serial.println(card_id);
}

void loop() {  
  cartao.ler(onReadCard);
}
