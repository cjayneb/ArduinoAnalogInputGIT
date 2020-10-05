const int sensorPin = A0;
const int greenLedPin = 10;
const int blueLedPin = 9;
const int redLedPin = 11;
int outputValue = 0;
int sensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  //Serial.print(" ");
  outputValue = map(sensorValue, 0, 1023, 0, 255);

  
  analogWrite(greenLedPin, outputValue);
  analogWrite(blueLedPin, outputValue);
  analogWrite(redLedPin, outputValue);
  
  
  //analogWrite(LEDPin, outputValue);

  delay(2);
}
