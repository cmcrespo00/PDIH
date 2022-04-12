// C++ code
//
void setup()
{
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  delay(200); // Wait for 0,2 second(s)
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(200); // Wait for 0,2 second(s)
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  delay(200); // Wait for 0,2 second(s)
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  delay(200); // Wait for 0,2 second(s)
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  delay(200); // Wait for 0,2 second(s)
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(200); // Wait for 0,2 second(s)
}