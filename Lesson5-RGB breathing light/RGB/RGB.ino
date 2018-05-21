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
 * [Title]: RGB breathing light
 * [Diagram]
 *         Arduino PIN 11   ===================  RGB pin1 red
 *         Arduino PIN 10  ===================   RGB pin3 green
 *         Arduino PIN 9  ===================    RGB pin4 blue
 *         Arduino GND     ===================   RGB pin2  GND
 */

int led1 = 9;
int led2 = 10;
int led3 = 11;
void setup()
{
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}
void setColor(int red,int green,int blue)
{
  analogWrite(led1,255-red);
  analogWrite(led2,255-green);
  analogWrite(led3,255-blue);
}
void loop()
{
  int i,j,k;
  for(i=0,j=255;i<256;i++)
  {
    setColor(i,j,0);
    delay(4);
    j--;
  }
  delay(100);           //green to res
  for(i=0,j=255;i<256;i++)
  {
    setColor(j,0,i);
    delay(4);
    j--;
  }
  delay(100);           //red to blue
  for(i=0,j=255;i<256;i++)
  {
    setColor(0,i,j);
    delay(4);
    j--;
  }
   delay(100);          //blue to green
for(i=0,j=255;i<256;i++)
  {
    setColor(i,0,j);
    delay(4);
    j--;
  }
  delay(100);
 for(i=0,j=255;i<256;i++)
  {
    setColor(0,j,i);
    delay(4);
    j--;
  }
  delay(100);
 for(i=0,j=255;i<256;i++)
  {
    setColor(j,0,i);
    delay(4);
    j--;
  }
  delay(100);
  for(k=0;k<3;k++)
  {
    analogWrite(led1,255);
    analogWrite(led2,255);
    analogWrite(led3,255);
    delay(200);
    analogWrite(led1,0);
    analogWrite(led2,0);
    analogWrite(led3,0);
     delay(200);
  }
}
