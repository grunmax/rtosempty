#include <Arduino.h>
#include "builtinled.h"

int ONBOARD_LED = 2;
TaskHandle_t notHandler = NULL;

LEDParams ledParams = {
    .led = ONBOARD_LED,
    .time = 3000};

void setupOnBoardLed()
{
    pinMode(ONBOARD_LED, OUTPUT);
}

void blink_task(void *pvParameter)
{
    LEDParams *l = (LEDParams *)pvParameter;

    for (;;)
    {
        vTaskDelay(l->time / portTICK_RATE_MS);
        digitalWrite(l->led, HIGH);
        vTaskDelay(10 / portTICK_RATE_MS);
        digitalWrite(l->led, LOW);
    }
}
