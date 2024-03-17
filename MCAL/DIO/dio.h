
#ifndef DIO_H
#define DIO_H

#include "../../Utilities/registers.h"
#include "../../Utilities/types.h"
#include "../../Utilities/bit_manipulation.h"

typedef enum EN_DIO_Error_t {
    DIO_OK, DIO_ERROR
} EN_DIO_Error_t ;

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define IN 0
#define OUT 1

#define LOW 0
#define HIGH 1


EN_DIO_Error_t DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction);
EN_DIO_Error_t DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value);
EN_DIO_Error_t DIO_toggle(uint8_t pinNumber, uint8_t portNumber);
EN_DIO_Error_t DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);

#endif
