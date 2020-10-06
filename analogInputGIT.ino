const int sensorPin = A0;
const int greenLedPin2 = 10;
const int greenLedPin1 = 11;
const int redLedPin = 9;
int outputValue = 0;
int sensorValue = 0;
int firstTemp = 50;
int secondTemp = 150;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(greenLedPin1, OUTPUT);
  pinMode(greenLedPin2, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin1, LOW);
  pinMode(greenLedPin2, LOW);
  pinMode(redLedPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  //Serial.print(" ");
  outputValue = map(sensorValue, 0, 1023, 0, 255);

  if(outputValue > 0 && outputValue <= 50){
    
    analogWrite(greenLedPin1, outputValue);
    digitalWrite(greenLedPin2, LOW);
    digitalWrite(redLedPin, LOW);
    
  }
  else if(outputValue > 50 && outputValue <= 150){
    analogWrite(greenLedPin1, firstTemp);
    analogWrite(greenLedPin2, outputValue);
    digitalWrite(redLedPin, LOW);
  }
  else if(outputValue > 150 && outputValue <= 254){
    analogWrite(greenLedPin1, firstTemp);
    analogWrite(greenLedPin2, secondTemp);
    analogWrite(redLedPin, outputValue);
  }
  else{
    analogWrite(greenLedPin1, outputValue);
    analogWrite(greenLedPin2, outputValue);
    analogWrite(redLedPin, outputValue);
  }
  
  
  
  //analogWrite(LEDPin, outputValue);

  delay(1);
}
