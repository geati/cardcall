#include <LiquidCrystal.h>
#include "Timer.h"
#include "Cartao.h"
#include "Registro.h"

//


//
Cartao cartao;
Registro registro;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Timer timer(3000);
Timer timer2(5000);

void setup() {
  // Serial Settings
  Serial.begin(115200);
  
  // RFI Settings
  SPI.begin();
  RC522.init();
  
  // LCD Settings
  
  lcd.begin(16, 2);
  lcd.clear(); 


  //
  delay(1000);  
}

void onReadCard(String card_id) {
  Serial.println(card_id);
}

void loop() { 
  lcd.setCursor(2, 0);
  lcd.print("Aproxime seu"); 
  lcd.setCursor(2, 1);
  lcd.print("Cartao!");
  cartao.ler(onReadCard);
  if (cartao.id_cartao != "") {
    registro.entradaAluno(cartao.id_cartao, lcd, onReadCard);
    cartao.id_cartao = "";
  }
}
