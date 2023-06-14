#include <freertos/task.h>

  typedef struct {
  int led;
  int time;
} LEDParams;

extern LEDParams ledParams;
extern TaskHandle_t notHandler;

void setupOnBoardLed();
void blink_task(void *pvParameter);