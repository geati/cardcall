#include "LiquidCrystal.h"

class Registro{
    typedef void (*OperationCallback)(String);
    public:
        int status_aula = 1;
        String Aluno = "Edson";
        String card_id = card_id;
    public:
        void entradaAluno(String card_id, LiquidCrystal &lcd, OperationCallback callback) {
            if (card_id == "1254724954157" && status_aula == 1) {
                lcd.clear();
                lcd.setCursor(2, 0);
                lcd.print("Boa aula");
                lcd.setCursor(2, 1);
                lcd.print("Registrado");
                lcd.setCursor(0, 1);
                Serial.println("Entrou");
                callback(Aluno + " Presente");
            }
        };
    

};