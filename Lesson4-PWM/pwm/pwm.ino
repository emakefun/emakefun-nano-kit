int  ADPIN  = A0  ;
int  PWM_LEDPIN = 10 ;
int  value = 0 ;
float voltage = 0.0 ;
void setup()
{
  pinMode(ADPIN, INPUT);  // define ADPIN input PWM_LEDPIN output
  pinMode(PWM_LEDPIN, OUTPUT);
  Serial.begin(115200);    //Serial Baud rate is 115200
}
void loop()
{
  value =  analogRead(ADPIN);       //read analog pin raw data
  //voltage = ( ( float )value )/1023 ;
  //value = (int)voltage * 256 ;      //covert to voltage to PWM duty cycle
  analogWrite(PWM_LEDPIN, value);
  delay(1000);
}

