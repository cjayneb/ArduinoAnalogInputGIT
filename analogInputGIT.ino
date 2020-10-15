const int potentiometer_pin = A0;
const int green_led_pin2 = 10;
const int green_led_pin1 = 11;
const int red_led_pin = 9;
int output_value = 0;
int potentiometer_value = 0;
const int first_temp = 50;
const int second_temp = 150;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(green_led_pin1, OUTPUT);
  pinMode(green_led_pin2, OUTPUT);
  pinMode(red_led_pin, OUTPUT);
  pinMode(green_led_pin1, LOW);
  pinMode(green_led_pin2, LOW);
  pinMode(red_led_pin, LOW);

  Serial.begin(9600);
}

void loop() {
  
  potentiometer_value = analogRead(potentiometer_pin);
  Serial.println(potentiometer_value);
  output_value = map(potentiometer_value, 0, 1023, 0, 255);

  if(output_value >= 0 && output_value <= 50){
    
    analogWrite(green_led_pin1, output_value);
    digitalWrite(green_led_pin2, LOW);
    digitalWrite(red_led_pin, LOW);
    
  }
  else if(output_value > 50 && output_value <= 150){
    analogWrite(green_led_pin1, first_temp);
    analogWrite(green_led_pin2, output_value);
    digitalWrite(red_led_pin, LOW);
  }
  else if(output_value > 150 && output_value <= 254){
    analogWrite(green_led_pin1, first_temp);
    analogWrite(green_led_pin2, second_temp);
    analogWrite(red_led_pin, output_value);
  }
  else{
    digitalWrite(red_led_pin, LOW);
    digitalWrite(green_led_pin1, LOW);
    digitalWrite(green_led_pin2, LOW);
  
    delay(500);

    analogWrite(green_led_pin1, output_value);
    analogWrite(green_led_pin2, output_value);
    analogWrite(red_led_pin, output_value);

    delay(500);
    
  }
  
  delay(2);
  
}
