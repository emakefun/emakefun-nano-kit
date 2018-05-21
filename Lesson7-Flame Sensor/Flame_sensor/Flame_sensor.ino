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
 * [Title]    fire sensor control buzzer turn on/off
 * [diagram]
 *         Arduino PIN 5   ===================  fire sensor pin
 *         Arduino PIN 9   ===================  Active buzzer positive pole
 */

int fire_pin = A5;     // define analog 5 pin for fire-sensor pin
int buzzer = 9;        // buzzer dirver pin
int val = 0;
int count = 0;
void setup()
{
    pinMode(buzzer,OUTPUT);        // buzzer pin is output
    pinMode(fire_pin,INPUT);       // fire-sensor pin is input
    Serial.begin(115200);          // init baud rate is 115200
    digitalWrite(buzzer,LOW);      // buzzer default value is 0
}
void loop()
{
    val = analogRead(fire_pin);    // get fire-sensor analog value
    Serial.println(val);
    if ( val < 600 )                // get value > 600 counet add
    {
        count++;
    }
    else {
       count = 0;
    }
    if( count >= 5 )              // count > 5 ensure infrared radiation found and give an alarm
    {
        digitalWrite(buzzer, HIGH);
    } else {
        digitalWrite(buzzer, LOW);   // disable an alarm
    }
    delay(500);
}
