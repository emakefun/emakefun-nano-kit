/**************************************************************************************************
 *    _____    __      __        __           __        ______   _______   _        _    ___     _
 *  / _____)  /  \    /   \     /  \         / /       / _____) |   ____| | |      | |  |   \   | |
 * | |_____  | |\ \  / /| |    / /\ \       / /____   | |_____  |  |____  | |      | |  | |\ \  | |
 * |  _____| | | \ \/ / | |   / /  \ \     / / ___/   | |_____| |  |____| | |      | |  | | \ \ | |
 * | |_____  | |  \__/  | |  / /****\ \   / /\ \____  | |_____  |  |      | \______/ |  | |  \ \| |
 *  \______) |_|        |_| /_/      \_\ /_/  \_____\  \______) |__|       \ ______ /   |_|   \___|
 *
 *
 * Emakefun Tech firmware
 *
 * Copyright (C) 2015-2020
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, in version 3.
 * learn more you can see <http://www.gnu.org/licenses/>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.
 *
 *
 * [Title]     L293D for a DC Motor
 * [Diagram]
 *         L293D PIN 1   ===================  Arduino PIN 3
 *         L293D PIN 2   ===================  Arduino PIN 5
 *         L293D PIN 4   ===================  Arduino PIN GND
 *         L293D PIN 5   ===================  Arduino PIN GND
 *         L293D PIN 7   ===================  Arduino PIN 4
 *         L293D PIN 8   ===================  Arduino PIN +5V
 *         DC MOTOR +5V  ===================  4N35 PIN 2
 *         DC MOTOR GND  ===================  4N35 PIN 5
 *         L293D PIN 5   ===================  4N35 PIN 1
 *         L293D PIN 5   ===================  4N35 PIN 4
 */
#define ENABLE 3
#define DIRB 4
#define DIRA 5

int i;

void setup()
{
  //---set pin direction
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  //---back and forth example
   Serial.println("One way, then reverse");
   digitalWrite(ENABLE,HIGH); // enable on
   for (i=0;i<5;i++)
   {
    digitalWrite(DIRA,HIGH); //one way
    digitalWrite(DIRB,LOW);
    delay(500);
    digitalWrite(DIRA,LOW);  //reverse
    digitalWrite(DIRB,HIGH);
    delay(500);
  }
  digitalWrite(ENABLE,LOW); // disable
  delay(4000);

  Serial.println("fast Slow example");
  //---fast/slow stop example
  digitalWrite(ENABLE,HIGH); //enable on
  digitalWrite(DIRA,HIGH); //one way
  digitalWrite(DIRB,LOW);
  delay(1000);
  digitalWrite(ENABLE,LOW); //slow stop
  delay(3000);
  digitalWrite(ENABLE,HIGH); //enable on
  digitalWrite(DIRA,HIGH); //one way
  digitalWrite(DIRB,LOW);
  delay(1000);
  digitalWrite(DIRA,LOW); //fast stop
  delay(3000);

  //Serial.println("PWM full then slow");
  //---PWM example, full speed then slow
  digitalWrite(ENABLE,HIGH); //enable on
  digitalWrite(DIRA,HIGH); //one way
  digitalWrite(DIRB,LOW);
  delay(2000);
  analogWrite(ENABLE,128); //half speed
  delay(2000);
  digitalWrite(ENABLE,LOW); //all done
  delay(10000);
}
