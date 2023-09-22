#include <SPI.h>
#include <RFID.h>

#define SDA_DIO 9
#define RESET_DIO 8
RFID RC522(SDA_DIO, RESET_DIO);


class Cartao {
    typedef void (*OperationCallback)(String);
    
    public:
        String id_cartao = "";

    public:
        void ler(OperationCallback callback) {
            if (!RC522.isCard()) 
                return;
            
            RC522.readCardSerial();
            id_cartao = "";  
   
            for (int i = 0; i < 5; i++) {
                id_cartao += String(RC522.serNum[i], DEC);
            }

            // @TODO: só executar callback caso todos os digitos forem lidos, 
            //        pois se o cartão for removido antes da leitura de todos 
            //        os caracteres, o callback é executado
            callback(id_cartao);
        };
};