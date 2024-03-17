
#ifndef TESTMODE

#include "Application/application.h"
int main(){
    APP_init();
    while(1){
        APP_start();
    }
}
#endif

#ifdef TESTMODE

#include "Test/test.h"

int main(){

    LED_init(LED_PASS_PORT, LED_PASS_PIN); 
    LED_init(LED_FAIL_PORT, LED_FAIL_PIN); 
    uint8_t passed = TRUE;

    //test DIO Driver:
    if(DIO_init_test() == DIO_ERROR) passed=FALSE;
    if(DIO_write_test() == DIO_ERROR) passed=FALSE;
    if(DIO_read_test() == DIO_ERROR) passed=FALSE;
    if(DIO_toggle_test() == DIO_ERROR) passed=FALSE;

    //test INT Driver:
    if(GLOBAL_INT_enable_test() == DIO_ERROR) passed=FALSE;
    if(GLOBAL_INT_disable_test()) passed=FALSE;
    if(INT_disable_test() == DIO_ERROR) passed=FALSE;
    if(INT_enable_test() == DIO_ERROR) passed=FALSE;

    //test Button Driver:
    if(BUTTON_init_test() == DIO_ERROR) passed=FALSE;
    if(BUTTON_read_test() == DIO_ERROR) passed=FALSE;

    //test LED Driver:
    if(LED_init_test() == DIO_ERROR) passed=FALSE;
    if(LED_on_test() == DIO_ERROR) passed=FALSE;
    if(LED_off_test() == DIO_ERROR) passed=FALSE;
    if(LED_toggle_test() == DIO_ERROR) passed=FALSE;

    while(1) {
        if(passed) LED_on(LED_PASS_PORT, LED_PASS_PIN); 
        else LED_on(LED_FAIL_PORT, LED_FAIL_PIN); 
    }
}
#endif