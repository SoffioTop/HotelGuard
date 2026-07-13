#include <Arduino.h>

#include "pins.h"
#include "fridge.h"
#include "alarm.h"

Fridge fridge1(PIN_FRIDGE_1);
Fridge fridge2(PIN_FRIDGE_2);

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
