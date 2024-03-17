#include "interrupts.h"
/*
    Enable Globale interrupts:
    by Setting bit 7 in the status register to 1 
    or Calling sei() function
*/
EN_INT_Error_t GLOBAL_INT_enable() {
    sei();
    return INT_OK;
}

/*
    Disable Globale interrupts:
    by Setting bit 7 in the status register to 0
    or Calling cli() function
*/
EN_INT_Error_t GLOBAL_INT_disable() {
    cli();
    return INT_OK;
}

/*
     Enable external interrupt and set its sense.
     First check if given interrupt is INT2, mode can not be LOW_LEVEL or LOGICAL_CHANGE.

     Second, set MCUCR register bits according to the needed interrupt sense:
     for LOW_LEVEL sense, set MCUCR register with 0x00.
     for LOGICAL_CHANGE, set MCUCR register with 0x02.
     for FALLING_EDGE sense, set MCUCR register with 0x03.
     for RISING_EDGE sense, set MCUCR register with 0x04.

     Third, enable external interrupts.
     for INT0, set 6th bit of GICR register to 1
     for INT1, set 7th bit of GICR register to 1
     for INT2, set 5th bit of GICR register to 1
*/
EN_INT_Error_t INT_enable(uint8_t interrupt, uint8_t mode) {

     if(interrupt == INT2){
        if( mode == LOW_LEVEL || mode == LOGICAL_CHANGE)
            return INT_ERROR; 
        mode = GET_BIT(mode, 0);
     }
        
    // First: Choose interrupt sense 
    MCUCR |= mode;

    // Then: Enable interrupt to start listening.
    switch (interrupt) {
        case INT0:
            SET_BIT(GICR,6);
            break;
        case INT1:
           SET_BIT(GICR,7);
            break;
        case INT2:
           SET_BIT(GICR,5);
            break;
        
        default:
            break;
    }
    return INT_OK;
}

/*
     Disable external interrupt.
     for INT0, set 6th bit of GICR register to 0
     for INT1, set 7th bit of GICR register to 0
     for INT2, set 5th bit of GICR register to 0
*/
EN_INT_Error_t INT_disable(uint8_t interrupt) {
        switch (interrupt) {
        case INT0:
            CLEAR_BIT(GICR,6);
            break;
        case INT1:
           CLEAR_BIT(GICR,7);
            break;
        case INT2:
           CLEAR_BIT(GICR,5);
            break;
        
        default:
            break;
    }
    return INT_OK;
}