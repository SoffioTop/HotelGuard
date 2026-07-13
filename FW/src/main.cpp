#include <Arduino.h>

#include "pins.h"
#include "fridge.h"
#include "alarm.h"

Fridge fridges[MAX_FRIDGES];

Alarm alarm(PIN_BUZZER);

void setup()
{
    fridge1.begin();
    fridge2.begin();

    alarm.begin();
}

void loop()
{
    fridge1.update();
    fridge2.update();

    Defcon currentDefcon = Defcon::Normal;

    if (fridge1.getDefcon() < currentDefcon)
        currentDefcon = fridge1.getDefcon();

    if (fridge2.getDefcon() < currentDefcon)
        currentDefcon = fridge2.getDefcon();

    alarm.update(currentDefcon);
}
