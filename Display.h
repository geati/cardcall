#include "LiquidCrystal.h"

// @TODO: remover referencias ao LCD em todas os métodos e descobrir como
// torná-lo um atributo

class Display {
 private:
  String default_lin1;
  String default_lin2;
  String curr_lin1;
  String curr_lin2;
  long waitTime = 5000;
  long endtime = 0;
  bool change = true;

 public:
  Display(String lin1, String lin2) {
    default_lin1 = lin1;
    default_lin2 = lin2;
    curr_lin1 = lin1;
    curr_lin2 = lin2;
  };

  void reset(LiquidCrystal &lcd) {
    change = true;
    curr_lin1 = default_lin1;
    curr_lin2 = default_lin2;
  }

  void print(String lin1, String lin2) {
    change = true;
    curr_lin1 = lin1;
    curr_lin2 = lin2;
  }

  void update(LiquidCrystal &lcd) {
    if (endtime > 0 && millis() >= endtime) {
        endtime = 0;
        reset(lcd);
        return;
    }

    if (!change) return;
    change = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(curr_lin1);
    lcd.setCursor(0, 1);
    lcd.print(curr_lin2);
    endtime = millis() + waitTime;
  }
};