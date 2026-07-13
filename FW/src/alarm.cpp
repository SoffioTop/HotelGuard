/*
 * HotelGuard
 * File: alarm.cpp
 *
 * Gestione del buzzer.
 */

#include "alarm.h"

Alarm::Alarm(uint8_t pin)
{
    this->pin = pin;
    activeDefcon = Defcon::Normal;
}

void Alarm::begin()
{
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}

void Alarm::update(Defcon currentDefcon)
{
    activeDefcon = currentDefcon;

    if (activeDefcon == Defcon::Emergency)
    {
        digitalWrite(pin, HIGH);
    }
    else
    {
        digitalWrite(pin, LOW);
    }
}
