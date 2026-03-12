int LED = 9; // PWM Pin for LED 
int brightness = 0;
int FadeAmount = 5; // Amount to increase/ decrease brightness

void setup(){
  pinMode(LED,OUTPUT);
}

void loop(){
  analogWrite(LED,brightness);// Set LED for brightness
  brightness = brightness + FadeAmount; //Change Brightness
  
  // reverse when limit reaches
  if (brightness<=0 || brightness>=255){
    FadeAmount = -FadeAmount;
  }
  delay(1000);
}