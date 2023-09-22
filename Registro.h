class Registro {
  typedef void (*OperationCallback)(String);

 public:
  int status_aula = 1;
  String Aluno = "Edson";

 public:
  void entradaAluno(String card_id, Display &display) {
    if (card_id == "1254724954157" && status_aula == 1) {
      display.print("Oie", "CICLANO");
    }

    if (card_id == "21117320129170" && status_aula == 1) {
      display.print("Oie", "BELTRANO");
    }
  };
};