/*
 * HotelGuard
 * File: fridge.cpp
 *
 * Gestione di una singola cella frigorifera.
 */

#include "fridge.h"

Fridge::Fridge(uint8_t pin)
{
    this->pin = pin;

    open = false;
    previousOpen = false;

    openedTimestamp = 0;

    defcon = Defcon::Normal;
}

void Fridge::begin()
{
    pinMode(pin, INPUT_PULLUP);
}

void Fridge::update()
{
    // Con i contatti puliti:
    // Porta aperta = circuito aperto = HIGH
    // Porta chiusa = circuito chiuso = LOW

    open = digitalRead(pin);

    // Porta appena aperta
    if (!previousOpen && open)
    {
        openedTimestamp = millis();
        defcon = Defcon::Notice;
    }

    // Porta appena chiusa
    if (previousOpen && !open)
    {
        openedTimestamp = 0;
        defcon = Defcon::Normal;
    }

    previousOpen = open;
}

bool Fridge::isOpen() const
{
    return open;
}

Defcon Fridge::getDefcon() const
{
    return defcon;
}

unsigned long Fridge::getOpenDuration() const
{
    if (!open)
        return 0;

    return millis() - openedTimestamp;
}
