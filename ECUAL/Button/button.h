
#ifndef BUTTON_H
#define BUTTON_H

#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/Interrupts/interrupts.h"

typedef enum EN_buttonError_t {
     BUTTON_OK, BUTTON_ERROR
} EN_buttonError_t ;

#define EXTERNAL_INT_BUTTON_PORT PORT_D
#define EXTERNAL_INT_BUTTON_PIN PIN2

#define LOW 0
#define HIGH 1

EN_buttonError_t BUTTON_init(uint8_t buttonPort, uint8_t buttonPin);
EN_buttonError_t BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value);
#endif
