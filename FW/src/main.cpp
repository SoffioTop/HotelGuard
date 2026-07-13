void setup()
{
    Serial.begin(115200);

    fridge1.begin();
}

void loop()
{
    fridge1.update();

    Serial.println(fridge1.getOpenDuration());

    delay(100);
}
