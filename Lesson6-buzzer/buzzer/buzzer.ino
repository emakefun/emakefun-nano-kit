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
 * [Title]    product two frequeces sound
 * [diagram]
 *           Arduino  pin8  ===================   buzzer positive wire
 *
 */
int buzzer = 8;
void frequence_1(void)    // 1k HZ
{
    int i ;
    for(i=0;i<80;i++)
    {
        digitalWrite(buzzer,HIGH);  //sound production
        delay(1);
        digitalWrite(buzzer,LOW);
        delay(1);
    }
}

void frequency_2(void)    // 500 HZ
{
    int i ;
    for(i=0;i<100;i++)
    {
        digitalWrite(buzzer,HIGH);  //sound production
        delay(2);
        digitalWrite(buzzer,LOW);
        delay(2);
    }
}

void setup()
{
	  pinMode(buzzer,OUTPUT);
}
void loop()
{
    frequence_1();
    delay(100);
    frequency_2();
}