// C++ code
void setup(){
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);          //pin de salida de la LED roja
  pinMode(7, INPUT);            //pin de entrada del SENSOR PIR
}

void loop(){
  // put your main code here, to run repeatedly:
  //Comprueba si hay movimiento cerca del sensor PIR
  if ((digitalRead(7) == HIGH)) {
    digitalWrite(13, HIGH);     //Encender LED roja
  } else {
    digitalWrite(13, LOW);      //Apagar LED roja
  }
}
