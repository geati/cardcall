// @TODO: só executar callback caso todos os digitos forem lidos,
//        pois se o cartão for removido antes da leitura de todos
//        os caracteres, o callback é executado

#include <RFID.h>
#include <SPI.h>

#define SDA_DIO 9
#define RESET_DIO 8

RFID RC522(SDA_DIO, RESET_DIO);

class Cartao {
  typedef void (*OperationCallback)(String);

 public:
  String cartao_id = "";
  String cartao_id_last = "-";

 public:
  void ler(OperationCallback callback) {
    if (!RC522.isCard()) return;

    RC522.readCardSerial();
    cartao_id = "";

    for (int i = 0; i < 5; i++) {
      cartao_id += String(RC522.serNum[i], DEC);
    }

    if (cartao_id_last == cartao_id) return;

    callback(cartao_id);
    cartao_id_last = cartao_id;
  };
};