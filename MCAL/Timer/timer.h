
#ifndef TIMER_H
#define TIMER_H

#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"

typedef enum EN_TIMER_Error_t {
     TIMER_OK, TIMER_ERROR
} EN_TIMER_Error_t ;

#define TIMER0 0
#define TIMER0_CNT 256

#define NOPRESCALER 0x01
#define PRESCALER8 0x02
#define PRESCALER64 0x03
#define PRESCALER256 0x04
#define PRESCALER1024 0x05 

#define TIMER0_OVFLAG GET_BIT(TIFR,0)

//To clear (TOV0) overflow flag, write a 1 to that bit, not 0.
#define CLEAR_TIMER0_OVFLAG SET_BIT(TIFR,0)


// all driver function prototypes
EN_TIMER_Error_t Timer_start(uint8_t timer, uint8_t mode, uint8_t init_value);
EN_TIMER_Error_t Timer_stop(uint8_t timer);
EN_TIMER_Error_t Timer_getState(uint8_t timer, uint8_t *value);

#endif
