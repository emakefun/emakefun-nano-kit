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
 * [Title]:   RGB breathing light
 * [Diagram]
 *         Arduino PIN 11   ===================  RGB pin1 red
 *         Arduino PIN 10  ===================   RGB pin3 green
 *         Arduino PIN 9  ===================    RGB pin4 blue
 *         Arduino GND     ===================   RGB pin2  GND
 *
 */
#define RGB_RED    11
#define RGB_GREEN  10
#define RGB_BLUE   9

void setup()
{
    pinMode(RGB_RED,OUTPUT);
    pinMode(RGB_GREEN,OUTPUT);
    pinMode(RGB_BLUE,OUTPUT);
}

void setColor(int red,int green,int blue)
{
    analogWrite(RGB_RED,red);
    analogWrite(RGB_GREEN,green);
    analogWrite(RGB_BLUE,blue);
}

void loop()
{
    int i;
    for (i=0; i<256; i++)
    {
        setColor(i, 0, 0);
        delay(4);
    }
    delay(500);           //turn the RGB LED red smoth

    for (i=0; i < 256; i++)
    {
        setColor(0, i, 0);
        delay(4);
    }
    delay(500);           //turn the RGB LED green smoth

    for (i=0; i < 256; i++)
    {
        setColor(0, 0, i);
        delay(4);
    }
    delay(100);           //turn the RGB LED blue smoth
}
