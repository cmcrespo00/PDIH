// C++ code
void setup(){
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);     //pin de salida de la LED roja
  pinMode(12, OUTPUT);     //pin de salida de la LED amarilla
  pinMode(13, OUTPUT);     //pin de salida de la LED verde
}

void loop(){
  // put your main code here, to run repeatedly:
  digitalWrite(13, LOW);   //Apagar LED verde
  digitalWrite(11, HIGH);  //Encender LED roja
  delay(1500);              // Esperar durante 1,5 segundos
  digitalWrite(11, LOW);   //Apagar LED roja
  digitalWrite(12, HIGH);  //Encender LED amarilla
  delay(1500);              // Esperar durante 1,5 segundos
  digitalWrite(12, LOW);   //Apagar LED amarilla
  digitalWrite(13, HIGH);  //Encender LED verde
  delay(1500);              // Esperar durante 1,5 segundos
}
