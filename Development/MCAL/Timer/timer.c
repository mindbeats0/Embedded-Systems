#include "timer.h"

/*
    Start timer.
    First, set timerX initial value by assigning it to TCNTX
    Second, start timerX with the given prescaler by setting bits in TCCRX register

    for no prescaler, set TCCRX register with 0x01  
    for prescaler 8, set TCCRX register with 0x02  
    for prescaler 64, set TCCRX register with 0x03  
    for prescaler 256, set TCCRX register with 0x04  
    for prescaler 1024, set TCCRX register with 0x05   
*/
EN_TIMER_Error_t Timer_start(uint8_t timer, uint8_t mode, uint8_t init_value) {
    switch (timer) {
        case TIMER0: 
            TCNT0 = init_value;
            TCCR0 = mode; 
        break;
    }
    return TIMER_OK;
}

/*
    Stop timer.
    stop timerX by setting TCCRX register to 0x00.
*/
EN_TIMER_Error_t Timer_stop(uint8_t timer) {
    switch (timer) {
        case TIMER0:
            TCCR0 = 0x00;
        break;
    }
    return TIMER_OK;
}
