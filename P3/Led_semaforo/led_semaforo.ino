// C++ code
//
void setup()
{
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, LOW);
  digitalWrite(11, HIGH);
  delay(1500); // Wait for 1,5 second(s)
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  delay(1500); // Wait for 1,5 second(s)
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  delay(1500); // Wait for 1,5 second(s)
}