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
    // Se il livello è cambiato, lo memorizziamo.
    // In futuro qui cambieremo il pattern del buzzer.
    if (currentDefcon != activeDefcon)
    {
        activeDefcon = currentDefcon;
    }

    switch (activeDefcon)
    {
        case Defcon::Emergency:
            digitalWrite(pin, HIGH);
            break;

        case Defcon::Alarm:
        case Defcon::Warning:
        case Defcon::Notice:
        case Defcon::Normal:
        default:
            digitalWrite(pin, LOW);
            break;
    }
}
