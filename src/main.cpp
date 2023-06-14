#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <SoftwareSerial.h>

#include "led/builtinled.h"


void setup()
{
    Serial.begin(115200);
    setupOnBoardLed();
    xTaskCreate(&blink_task, "blink_task", configMINIMAL_STACK_SIZE, &ledParams, tskIDLE_PRIORITY, NULL);
}

void loop() {}