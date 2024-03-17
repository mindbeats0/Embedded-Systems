#include "button.h"
/*
    Initialize the button as a trigger for an interrupt. 
    1. enable global interrupts.
    2. enable interrupt used with button 
    2. configure the connected GPIO pin with button
       as an input DIO pin with the given port and pin 
*/
EN_buttonError_t BUTTON_init(uint8_t buttonPort, uint8_t buttonPin) {
    GLOBAL_INT_enable();
    EN_INT_Error_t intError = INT_enable(INT0, RISING_EDGE); 
    EN_DIO_Error_t DIOError = DIO_init(buttonPort, buttonPin, IN);
    return (intError == INT_OK && DIOError == DIO_OK)? BUTTON_OK:BUTTON_ERROR;
}

/*
    Read the value on the connected GPIO with button
*/
EN_buttonError_t BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value) {
    EN_DIO_Error_t error = DIO_read(buttonPort, buttonPin, value);
    return (error == DIO_OK)? BUTTON_OK:BUTTON_ERROR;
}