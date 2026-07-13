/*
 * HotelGuard
 * File: fridge.h
 *
 * Gestione di una singola cella frigorifera.
 */

#pragma once

#include <Arduino.h>
#include "defcon.h"

class Fridge
{
public:

    explicit Fridge(uint8_t pin);

    void begin();
    void update();

    bool isOpen() const;

    Defcon getDefcon() const;

    unsigned long getOpenDuration() const;

private:

    uint8_t pin;

    bool open;
    bool previousOpen;

    unsigned long openedTimestamp;

    Defcon defcon;
};
