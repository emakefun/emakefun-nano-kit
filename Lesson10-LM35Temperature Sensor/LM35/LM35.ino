int Temp_Pin = A0;              // analog pin line LM35 numble 2 wire
int val;  
int dat;  
float voltage = 0.0 ;
void setup()
{
    Serial.begin(115200);       //init serial Baud rate 115200
}
void loop()
{
    val = analogRead(Temp_Pin);       //  read analog raw data
    voltage = ( ( float )val )/1023;
    voltage = voltage * 5 ;            // convert analog value to real voltage
    dat =  voltage * 100;               // convert voltage to temprature
    Serial.print("Current Temp : ");
    Serial.print(dat);
    Serial.println("C"); 
    delay(500);                          // Delay 0.5 s
}

