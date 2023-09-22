#include "Timer.h"
#include "Cartao.h"

Cartao cartao;
Timer timer(3000);
Timer timer2(5000);

void setup() {
  SPI.begin();
  RC522.init();
  Serial.begin(115200);
  delay(1000);  
}

// int callbackAqui() {
//   Serial.println("asdad 1111");
// }

void ronaldo(String id_cartao) {
  Serial.println(id_cartao);
}

void loop() {  
  cartao.ler(ronaldo);

  // // 
  // timer.init();
  // timer.counter(callbackAqui);
}
