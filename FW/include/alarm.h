/*
 * HotelGuard
 * File: alarm.h
 *
 * Gestione del buzzer.
 */

#pragma once

#include <Arduino.h>
#include "defcon.h"

class Alarm
{
public:

    explicit Alarm(uint8_t pin);

    void begin();

    void update(Defcon currentDefcon);

private:

    uint8_t pin;

    Defcon activeDefcon;
};
