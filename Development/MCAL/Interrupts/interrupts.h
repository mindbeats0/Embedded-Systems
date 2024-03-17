
#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include "../../Utilities/bit_manipulation.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/types.h"

typedef enum EN_INT_Error_t {
     INT_OK, INT_ERROR
} EN_INT_Error_t ;

/* External Interrupts */
#define INT0 0
#define INT1 1
#define INT2 2

/* interrupts sense modes */
#define LOW_LEVEL 0x00
#define LOGICAL_CHANGE 0x01
#define FALLING_EDGE 0x02
#define RISING_EDGE 0x03 


/*****************************************************/
/* External Interrupt Vectors                        */ 
/*****************************************************/ 
//External Interrupt Request 0
#define EXT_INT_0  __vector_1
//External Interrupt Request 1
#define EXT_INT_1  __vector_2
//External Interrupt Request 2
#define EXT_INT_2  __vector_3

/*****************************************************/
/* Enable and Disable global interrupts                  */ 
/*****************************************************/ 
// Set Global Interrupts, Set the I-bit in status register to 1 
#define sei() __asm__ __volatile__("sei" ::: "memory")
//Clear Global Interrupts, Set the I-bit in status register to 0
#define cli() __asm__ __volatile__("cli" ::: "memory")

/* ISR definition */
#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)


/* interrupts functions prototypes */
EN_INT_Error_t GLOBAL_INT_enable();
EN_INT_Error_t GLOBAL_INT_disable();
EN_INT_Error_t INT_enable(uint8_t interrupt, uint8_t mode);
EN_INT_Error_t INT_disable(uint8_t interrupt);

#endif
