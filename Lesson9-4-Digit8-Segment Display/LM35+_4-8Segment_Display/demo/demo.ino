/**************************************************************************************************
      _____    __      __        __           __        ______   _______   _        _    ___     _
    / _____)  /  \    /   \     /  \         / /       / _____) |   ____| | |      | |  |   \   | |
   | |_____  | |\ \  / /| |    / /\ \       / /____   | |_____  |  |____  | |      | |  | |\ \  | |
   |  _____| | | \ \/ / | |   / /  \ \     / / ___/   | |_____| |  |____| | |      | |  | | \ \ | |
   | |_____  | |  \__/  | |  / /****\ \   / /\ \____  | |_____  |  |      | \______/ |  | |  \ \| |
    \______) |_|        |_| /_/      \_\ /_/  \_____\  \______) |__|       \ ______ /   |_|   \___|


   Emakefun Tech firmware

   Copyright (C) 2015-2020

   This program is free software: you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation, in version 3.
   learn more you can see <http://www.gnu.org/licenses/>.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.


   [Title]     4x8bit Numeric led Display the count down numble .
   [Diagram]
           Arduino PIN 2   ===================  8bit Numeric led a
           Arduino PIN 3   ===================  8bit Numeric led b
           Arduino PIN 4   ===================  8bit Numeric led c
           Arduino PIN 5   ===================  8bit Numeric led d
           Arduino PIN 6   ===================  8bit Numeric led e
           Arduino PIN 7   ===================  8bit Numeric led f
           Arduino PIN 8   ===================  8bit Numeric led g
           Arduino PIN 9   ===================  8bit Numeric led h
           Arduino PIN 10   ===================  8bit Numeric led D1
           Arduino PIN 11  ===================  8bit Numeric led D2
           Arduino PIN 12  ===================  8bit Numeric led D3
           Arduino PIN 13  ===================  8bit Numeric led D4
           Arduino PIN A5  ===================  LM35 numble2 wire
*/
const int pinLM = A5;

const int Vmax = 625;   //5000:1024
const int LMmax = 128;

const int pinChoose[4] = {10, 11, 12, 13};
const int pinLCD[8] = {2, 3, 4, 5, 6, 7, 8, 9};
const int num[17] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x80};
// 0123456789 AbCdEF.  + 17

int flash = 2;
void setup()
{
  pinMode(pinLM, INPUT);
  for (int i = 0; i < 4; i++)
  {
    pinMode(pinChoose[i], OUTPUT);
  }
  for (int i = 0; i < 8; i++)
  {
    pinMode(pinLCD[i], OUTPUT);
  }
  Serial.begin( 9600 );
}

void loop()
{
  unsigned int t = analogRead(pinLM);
  t = t * Vmax / LMmax;
  Serial.println( t );
  for (int i = 200; i; i--)
  {
    show_t( t );
  }
  flash = ~flash;
}

void show_num(int nx) {
  for (int i = 0; i < 8; i++)
    digitalWrite(pinLCD[i], ((1 << i)&nx));
}

void show_t(int x) {
  for (int i = 3; i >= 0; i--) {
    digitalWrite(pinChoose[i], LOW);
    if (x) {
      if ( i == flash ) {
        show_num( num[x % 10] | 0x80 );
      } else {
        show_num( num[x % 10] );
      }
    } else {
      show_num( 0x00 );
    }
    delay(1);
    show_num( 0x00 );       //clean
    x /= 10;
    digitalWrite(pinChoose[i], HIGH);
  }
}
