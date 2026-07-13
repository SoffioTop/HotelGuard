/*
 * HotelGuard
 * File: alarm.h
 *
 * Gestione del buzzer.
 */

#pragma once

#include <Arduino.h>
#include "defcon.h"
#include "fridge.h"

class Alarm
{
public:

    explicit Alarm(uint8_t pin);

    void begin();

    void update(Fridge fridges[], uint8_t count);

private:

    uint8_t pin;

    Defcon activeDefcon;

    int activeFridge;
};
