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
 * [Title]    Read current temprature and output by arduino uno serial port
 * [diagram]
 *            Arduino  pin0  ===================   LM35 numble2 wire
 *
 */
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
    val = analogRead(Temp_Pin);         //  read analog raw data
    voltage = ( ( float )val )/1023 ;
    voltage = voltage * 5 ;              // convert analog value to real voltage
    dat =  voltage * 100;                // convert voltage to temprature
    Serial.print("Current Temp : ");
    Serial.print(dat);
    Serial.println("C");
    delay(500);                          // Delay 0.5 s
}
