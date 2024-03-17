#ifndef APPLICATION_H
#define APPLICATION_H

#include "../ECUAL/Button/button.h"
#include "../ECUAL/LED/led.h"

// Traffic State (for cars)
typedef enum EN_trafficState_t {
        GREEN, YELLOW_STOP, RED, YELLOW_GO
} EN_trafficState_t;

typedef enum EN_trafficMode_t {
        NORMAL,PEDESTRIAN
} EN_trafficMode_t;


#define TRAFFIC_GREEN_PORT  LED_1_PORT
#define TRAFFIC_YELLOW_PORT LED_2_PORT
#define TRAFFIC_RED_PORT    LED_3_PORT
#define PED_GREEN_PORT      LED_4_PORT
#define PED_YELLOW_PORT     LED_5_PORT
#define PED_RED_PORT        LED_6_PORT
#define PED_MODE_PORT       LED_7_PORT

#define TRAFFIC_GREEN_PIN  LED_1_PIN
#define TRAFFIC_YELLOW_PIN LED_2_PIN
#define TRAFFIC_RED_PIN    LED_3_PIN
#define PED_GREEN_PIN      LED_4_PIN
#define PED_YELLOW_PIN     LED_5_PIN
#define PED_RED_PIN        LED_6_PIN
#define PED_MODE_PIN       LED_7_PIN

#define PED_WAIT_BUTTON_PORT BUTTON_1_PORT
#define PED_WAIT_BUTTON_PIN  BUTTON_1_PIN

void APP_init();
void APP_start();
#endif
