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
#define SEG_A 2
#define SEG_B 3
#define SEG_C 4
#define SEG_D 5
#define SEG_E 6
#define SEG_F 7
#define SEG_G 8
#define SEG_H 9

#define COM1 10
#define COM2 11
#define COM3 12
#define COM4 13


unsigned char table[10][8] =
{
	{0,0,1,1,1,1,1,1},			//0
	{0,0,0,0,0,1,1,0},			//1
	{0,1,0,1,1,0,1,1},			//2
	{0,1,0,0,1,1,1,1},			//3
	{0,1,1,0,0,1,1,0},			//4
	{0,1,1,0,1,1,0,1},			//5
	{0,1,1,1,1,1,0,1},			//6
	{0,0,0,0,0,1,1,1},			//7
	{0,1,1,1,1,1,1,1},			//8
	{0,1,1,0,1,1,1,1}			//9
};

void setup()
{
	pinMode(SEG_A,OUTPUT);
	pinMode(SEG_B,OUTPUT);
	pinMode(SEG_C,OUTPUT);
	pinMode(SEG_D,OUTPUT);
	pinMode(SEG_E,OUTPUT);
	pinMode(SEG_F,OUTPUT);
	pinMode(SEG_G,OUTPUT);
	pinMode(SEG_H,OUTPUT);

	pinMode(COM1,OUTPUT);
	pinMode(COM2,OUTPUT);
	pinMode(COM3,OUTPUT);
	pinMode(COM4,OUTPUT);
}

void loop()
{
	Display(1,1);			//bit1 display 1
	delay(500);
	Display(2,2);			//bit2 display 2
	delay(500);
	Display(3,3);			//bit3 display 3
	delay(500);
	Display(4,4);			//bit4 display 4
	delay(500);
}

void Display(unsigned char com,unsigned char num)
{
	digitalWrite(SEG_A,LOW);
	digitalWrite(SEG_B,LOW);
	digitalWrite(SEG_C,LOW);
	digitalWrite(SEG_D,LOW);
	digitalWrite(SEG_E,LOW);
	digitalWrite(SEG_F,LOW);
	digitalWrite(SEG_G,LOW);
	digitalWrite(SEG_H,LOW);

	switch(com)
	{
		case 1:
			digitalWrite(COM1,LOW);		//select bit1
			digitalWrite(COM2,HIGH);
			digitalWrite(COM3,HIGH);
			digitalWrite(COM4,HIGH);
			break;
		case 2:
			digitalWrite(COM1,HIGH);
			digitalWrite(COM2,LOW);		//select bit2
			digitalWrite(COM3,HIGH);
			digitalWrite(COM4,HIGH);
			break;
		case 3:
			digitalWrite(COM1,HIGH);
			digitalWrite(COM2,HIGH);
			digitalWrite(COM3,LOW);		//select bit3
			digitalWrite(COM4,HIGH);
			break;
		case 4:
			digitalWrite(COM1,HIGH);
			digitalWrite(COM2,HIGH);
			digitalWrite(COM3,HIGH);
			digitalWrite(COM4,LOW);		//select bit4
			break;
		default:break;
	}

	digitalWrite(SEG_A,table[num][7]);
	digitalWrite(SEG_B,table[num][6]);
	digitalWrite(SEG_C,table[num][5]);
	digitalWrite(SEG_D,table[num][4]);
	digitalWrite(SEG_E,table[num][3]);
	digitalWrite(SEG_F,table[num][2]);
	digitalWrite(SEG_G,table[num][1]);
	digitalWrite(SEG_H,table[num][0]);
}
