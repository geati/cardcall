#include "Cartao.h"
#include "Display.h"
#include "Registro.h"
#include "Timer.h"

//
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//
Cartao cartao;
Registro registro;
Timer timer2(10000);
Display display("Aproxime o seu", "cartao:");

void setup() {
  // Serial Settings
  Serial.begin(115200);

  // RFI Settings
  SPI.begin();
  RC522.init();

  //
  lcd.begin(16, 2);
  lcd.clear();

  //
  delay(1000);
};

void onReadCard(String card_id) {
  Serial.println(card_id);
  registro.entradaAluno(cartao.cartao_id, display);
};

void loop() {
  display.update(lcd);
  cartao.ler(onReadCard);
};