
#ifndef LED_H
#define LED_H

#include "../../MCAL/DIO/dio.h"

typedef enum EN_LED_Error_t {
    LED_OK, LED_ERROR
} EN_LED_Error_t ;

/* Traffic LEDs */
#define LED_1_PORT PORT_A
#define LED_2_PORT PORT_A
#define LED_3_PORT PORT_A
#define LED_4_PORT PORT_B
#define LED_5_PORT PORT_B
#define LED_6_PORT PORT_B

#define LED_1_PIN PIN0
#define LED_2_PIN PIN1
#define LED_3_PIN PIN2
#define LED_4_PIN PIN0
#define LED_5_PIN PIN1
#define LED_6_PIN PIN2

/* PEDESTRIAN Mode LED */
#define LED_7_PORT PORT_D
#define LED_7_PIN PIN3

/* Testing LEDs */
#define LED_8_PORT PORT_C
#define LED_9_PORT PORT_C
#define LED_8_PIN PIN0
#define LED_9_PIN PIN1

EN_LED_Error_t LED_init(uint8_t ledPort, uint8_t ledPin);
EN_LED_Error_t LED_on(uint8_t ledPort, uint8_t ledPin);
EN_LED_Error_t LED_off(uint8_t ledPort, uint8_t ledPin);
EN_LED_Error_t LED_toggle(uint8_t ledPort, uint8_t ledPin);

#endif
