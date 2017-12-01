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
 * [Title]    keypad control led light
 * [diagram]
 *         Arduino PIN 11  ===================  led control gpio
 *         Arduino PIN 7   ===================  keypad pin
 */
int led_out = 11 ;  //GPIO 11  LED pin
int keypad_pin = 7; //GPIO 7 key pin
int value;
void setup()
{
    pinMode(led_out,OUTPUT);    		// init led pin output
    pinMode(keypad_pin,INPUT);          // init key pin input
}
void loop()
{
        value = digitalRead(keypad_pin);    // read key pad pin vaule
        if( value == LOW )
        {
            digitalWrite(led_out,LOW);      // if key value is down  turn on LED
        }
        else
        {
            digitalWrite(led_out,HIGH);     // if key value is down  turn off LED
        }
}