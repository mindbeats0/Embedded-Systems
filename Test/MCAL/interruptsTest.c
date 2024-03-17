#include "../../MCAL/Interrupts/interrupts.h"

EN_INT_Error_t GLOBAL_INT_enable_test() {
    return GLOBAL_INT_enable();
}
EN_INT_Error_t GLOBAL_INT_disable_test() {
    return GLOBAL_INT_disable();
}
EN_INT_Error_t INT_disable_test() {
    return INT_disable(INT0);
}
EN_INT_Error_t INT_enable_test() {
    EN_INT_Error_t error;
    error = INT_enable(INT0, RISING_EDGE); //must be OK
    if(error != INT_OK) return INT_ERROR;

    error = INT_enable(INT2, LOW_LEVEL); //must be Error
    if(error != INT_ERROR) return INT_ERROR;

    error = INT_enable(INT2, LOGICAL_CHANGE);//must be Error
    if(error != INT_ERROR) return INT_ERROR;

    error = INT_enable(INT1, LOGICAL_CHANGE);//must be OK
    if(error != INT_OK) return INT_ERROR;

    return INT_OK;    
}