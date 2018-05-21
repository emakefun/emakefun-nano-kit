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
 * [Title]     4x8bit Numeric led Display the count down numble .
 * [Diagram]
 *         Arduino PIN 2   ===================  8bit Numeric led a
 *         Arduino PIN 3   ===================  8bit Numeric led b
 *         Arduino PIN 4   ===================  8bit Numeric led c
 *         Arduino PIN 5   ===================  8bit Numeric led d
 *         Arduino PIN 6   ===================  8bit Numeric led e
 *         Arduino PIN 7   ===================  8bit Numeric led f
 *         Arduino PIN 8   ===================  8bit Numeric led g
 *         Arduino PIN 9   ===================  8bit Numeric led h
 *         Arduino PIN 10   ===================  8bit Numeric led D1
 *         Arduino PIN 11  ===================  8bit Numeric led D2
 *         Arduino PIN 12  ===================  8bit Numeric led D3
 *         Arduino PIN 13  ===================  8bit Numeric led D4
 */
#define d_a 2
#define d_b 3
#define d_c 4
#define d_d 5
#define d_e 6
#define d_f 7
#define d_g 8
#define d_h 9

#define COM1 10
#define COM2 11
#define COM3 12
#define COM4 13

unsigned char num[17][8] = {
 //a  b  c  d  e  f  g  h
  {1, 1, 1, 1, 1, 1, 0, 0},     //0
  {0, 1, 1, 0, 0, 0, 0, 0},     //1
  {1, 1, 0, 1, 1, 0, 1, 0},     //2
  {1, 1, 1, 1, 0, 0, 1, 0},     //3
  {0, 1, 1, 0, 0, 1, 1, 0},     //4
  {1, 0, 1, 1, 0, 1, 1, 0},     //5
  {1, 0, 1, 1, 1, 1, 1, 0},     //6
  {1, 1, 1, 0, 0, 0, 0, 0},     //7
  {1, 1, 1, 1, 1, 1, 1, 0},     //8
  {1, 1, 1, 1, 0, 1, 1, 0},     //9
  {1, 1, 1, 0, 1, 1, 1, 1},     //A
  {1, 1, 1, 1, 1, 1, 1, 1},     //B
  {1, 0, 0, 1, 1, 1, 0, 1},     //C
  {1, 1, 1, 1, 1, 1, 0, 1},     //D
  {1, 0, 0, 1, 1, 1, 1, 1},     //E
  {1, 0, 0, 0, 1, 1, 1, 1},     //F
  {0, 0, 0, 0, 0, 0, 0, 1},     //.
};

void setup()
{
    pinMode(d_a,OUTPUT);
    pinMode(d_b,OUTPUT);
    pinMode(d_c,OUTPUT);
    pinMode(d_d,OUTPUT);
    pinMode(d_e,OUTPUT);
    pinMode(d_f,OUTPUT);
    pinMode(d_g,OUTPUT);
    pinMode(d_h,OUTPUT);

    pinMode(COM1,OUTPUT);
    pinMode(COM2,OUTPUT);
    pinMode(COM3,OUTPUT);
    pinMode(COM4,OUTPUT);
}

void loop()
{
  for(int l = 0; l < 10; l++ )
  {
    for(int k = 0; k < 10; k++)
    {
      for(int j = 0; j < 10; j++)
      {
        for(int i = 0;i < 10; i++)
        {
          //1000/8=125
          for(int q = 0;q<125;q++)
          {
            Display(1,l);
            delay(2);
            Display(2,k);
            delay(2);
            Display(3,j);
            delay(2);
            Display(4,i);
            delay(2);
          }
        }
      }
    }
  }
}

void Display(unsigned char com,unsigned char n) {
    digitalWrite(d_a,LOW);
    digitalWrite(d_b,LOW);
    digitalWrite(d_c,LOW);
    digitalWrite(d_d,LOW);
    digitalWrite(d_e,LOW);
    digitalWrite(d_f,LOW);
    digitalWrite(d_g,LOW);
    digitalWrite(d_h,LOW);

    switch(com) {
        case 1:
            digitalWrite(COM1,LOW);
            digitalWrite(COM2,HIGH);
            digitalWrite(COM3,HIGH);
            digitalWrite(COM4,HIGH);
            break;
        case 2:
            digitalWrite(COM1,HIGH);
            digitalWrite(COM2,LOW);
            digitalWrite(COM3,HIGH);
            digitalWrite(COM4,HIGH);
            break;
        case 3:
            digitalWrite(COM1,HIGH);
            digitalWrite(COM2,HIGH);
            digitalWrite(COM3,LOW);
            digitalWrite(COM4,HIGH);
            break;
        case 4:
            digitalWrite(COM1,HIGH);
            digitalWrite(COM2,HIGH);
            digitalWrite(COM3,HIGH);
            digitalWrite(COM4,LOW);
            break;
        default:break;
    }
    digitalWrite(d_a,num[n][0]);
    digitalWrite(d_b,num[n][1]);
    digitalWrite(d_c,num[n][2]);
    digitalWrite(d_d,num[n][3]);
    digitalWrite(d_e,num[n][4]);
    digitalWrite(d_f,num[n][5]);
    digitalWrite(d_g,num[n][6]);
    digitalWrite(d_h,num[n][7]);
}
