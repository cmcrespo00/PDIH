// C++ code

void setup(){
  // put your setup code here, to run once:
  pinMode(7, INPUT);           //pin de entrada del INTERRUPTOR
  pinMode(13, OUTPUT);         //pin de salida de la LED roja
}

void loop(){
  // put your main code here, to run repeatedly:
  //Comprueba si el interruptor está encendido
  if ((digitalRead(7) == true)) {
    digitalWrite(13, HIGH);     //Encender LED roja
  }
  
  //Comprueba si el interruptor está apagado
  else if ((digitalRead(7) == false)) {
    digitalWrite(13, LOW);      //Apagar LED roja
  }
}
