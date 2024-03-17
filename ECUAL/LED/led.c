#include "led.h"


/*
    Initialize the connected GPIO pin with LED
    as an output DIO pin with the given port and pin 
*/
EN_LED_Error_t LED_init(uint8_t ledPort, uint8_t ledPin) { 
    EN_DIO_Error_t error = DIO_init(ledPort, ledPin, OUT);
    return (error == DIO_OK)? LED_OK:LED_ERROR;
}

/*
    Turn on the LED by writing high voltage (Logic 1)
    to the DIO with the given port and pin 
*/
EN_LED_Error_t LED_on(uint8_t ledPort, uint8_t ledPin) {
    EN_DIO_Error_t error = DIO_write(ledPort, ledPin, HIGH);
    return (error == DIO_OK)? LED_OK:LED_ERROR;
}

/*
    Turn off the LED by writing low voltage (Logic 0)
    to the DIO with the given port and pin 
*/
EN_LED_Error_t LED_off(uint8_t ledPort, uint8_t ledPin) {
     EN_DIO_Error_t error = DIO_write(ledPort, ledPin,LOW);
     return (error == DIO_OK)? LED_OK:LED_ERROR;
}

/*
    Toggle the LED by toggling the voltage 
    on the DIO with the given port and pin 
*/
EN_LED_Error_t LED_toggle(uint8_t ledPort, uint8_t ledPin) {
    EN_DIO_Error_t error = DIO_toggle(ledPort, ledPin);
    return (error == DIO_OK)? LED_OK:LED_ERROR;
}
