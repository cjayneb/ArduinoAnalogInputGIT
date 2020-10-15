const int potentiometer_pin = A0;
const int greenLedPin2 = 10;
const int greenLedPin1 = 11;
const int redLedPin = 9;
int output_value = 0;
int potentiometer_value = 0;
const int firstTemp = 50;
const int secondTemp = 150;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(greenLedPin1, OUTPUT);
  pinMode(greenLedPin2, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin1, LOW);
  pinMode(greenLedPin2, LOW);
  pinMode(redLedPin, LOW);

  Serial.begin(9600);
}

void loop() {
  
  potentiometer_value = analogRead(potentiometer_pin);
  Serial.println(potentiometer_value);
  output_value = map(potentiometer_value, 0, 1023, 0, 255);

  if(output_value > 0 && output_value <= 50){
    
    analogWrite(greenLedPin1, output_value);
    digitalWrite(greenLedPin2, LOW);
    digitalWrite(redLedPin, LOW);
    
  }
  else if(output_value > 50 && output_value <= 150){
    analogWrite(greenLedPin1, firstTemp);
    analogWrite(greenLedPin2, output_value);
    digitalWrite(redLedPin, LOW);
  }
  else if(output_value > 150 && output_value <= 254){
    analogWrite(greenLedPin1, firstTemp);
    analogWrite(greenLedPin2, secondTemp);
    analogWrite(redLedPin, output_value);
  }
  else{
    analogWrite(greenLedPin1, output_value);
    analogWrite(greenLedPin2, output_value);
    analogWrite(redLedPin, output_value);
  }
  

  delay(1);
}
