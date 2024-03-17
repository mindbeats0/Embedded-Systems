#include "dio.h"

/*
     Initialize DIO pin as input or output pin. 
     Given port 'X' and pin 'N':
     set Nth bit in DDRX register with 
     0 if DIO is an input pin and 1 if DIO is an output pin
*/
EN_DIO_Error_t DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction) {
    switch (portNumber) {
        case PORT_A:
            if(direction == IN) {
                CLEAR_BIT(DDRA,pinNumber);
            }
            else if(direction == OUT) {
                SET_BIT(DDRA,pinNumber);
            }
            else {
                return DIO_ERROR;
            }
            break;
        case PORT_B:
            if(direction == IN) {
                CLEAR_BIT(DDRB,pinNumber);
            }
            else if(direction == OUT) {
                 SET_BIT(DDRB,pinNumber);
            }
            else {
                return DIO_ERROR;
            }
            break;
        case PORT_C:
            if(direction == IN) {
                CLEAR_BIT(DDRC,pinNumber);
            }
            else if(direction == OUT) {
                 SET_BIT(DDRC,pinNumber);
            }
            else {
                return DIO_ERROR;
            }
            break;
        case PORT_D:
            if(direction == IN) {
               CLEAR_BIT(DDRD,pinNumber);
            }
            else if(direction == OUT) {
                 SET_BIT(DDRD,pinNumber);
            }
            else {
                return DIO_ERROR;
            }
        default:
            break;
    }
    return DIO_OK;
}

/*
     Write value 0 or 1 on DIO pin.
     Given port 'X' and pin 'N':
     if value = 0, set Nth bit in PORTX register with 0
     if value = 1, set Nth bit in PORTX register with 1
*/
EN_DIO_Error_t DIO_write(uint8_t portNumber, uint8_t pinNumber,uint8_t value) {
    switch (portNumber)
    {
        case PORT_A:
            if(value == LOW) {
                CLEAR_BIT(PORTA,pinNumber);
            }
            else if(value == HIGH) {
                SET_BIT(PORTA,pinNumber);
            }
            else {
                return DIO_ERROR;
            }
            break;
        case PORT_B:
            if(value == LOW) {
                CLEAR_BIT(PORTB,pinNumber);
            }
            else if(value == HIGH) {
                SET_BIT(PORTB,pinNumber);
            }
            else {
                return DIO_ERROR;
            }
            break;

        case PORT_C:
            if(value == LOW) {
                CLEAR_BIT(PORTC,pinNumber);
            }
            else if(value == HIGH) {
                SET_BIT(PORTC,pinNumber);
            }
            else {
                return DIO_ERROR;
            }
            break;

        case PORT_D:
            if(value == LOW) {
                CLEAR_BIT(PORTD,pinNumber);
            }
            else if(value == HIGH) {
                SET_BIT(PORTD,pinNumber);
            }
            else {
                return DIO_ERROR;
            }
        default:
            break;
    }
    return DIO_OK;
}

/*
     Read value on DIO pin.
     Given port 'X' and pin 'N':
     set value = 0 if Nth bit in PINX register is 0 
     set value = 1 if Nth bit in PINX register is 1 
*/
EN_DIO_Error_t DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t *value) {
    switch (portNumber) {
        case PORT_A:
            *value = GET_BIT(PINA,pinNumber);
        break;
        case PORT_B:
             *value = GET_BIT(PINB,pinNumber);
        break;
        case PORT_C:
             *value = GET_BIT(PINC,pinNumber);
        break;
        case PORT_D:
             *value = GET_BIT(PIND,pinNumber);
        break;

        default:
            break;
    }

    return DIO_OK;
}

/*
     Toggle value on DIO pin.
     Given port 'X' and pin 'N':
     toggle Nth bit in PORTX register 
*/
EN_DIO_Error_t DIO_toggle(uint8_t portNumber, uint8_t pinNumber) {
        switch (portNumber) {
        case PORT_A:
            TOGGLE_BIT(PORTA,pinNumber);
        break;
        case PORT_B:
            TOGGLE_BIT(PORTB,pinNumber);
        break;
         case PORT_C:
            TOGGLE_BIT(PORTC,pinNumber);
        break;

         case PORT_D:
            TOGGLE_BIT(PORTD,pinNumber);
        break;
        default:
            break;
    }
    return DIO_OK; 
}