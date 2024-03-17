#include "../../ECUAL/LED/led.h"

#define TEST_PORT PORT_A
#define TEST_PIN PIN7

EN_LED_Error_t LED_init_test() { 
    return LED_init(TEST_PORT, TEST_PIN);
}
EN_LED_Error_t LED_on_test() {
    return LED_on(TEST_PORT, TEST_PIN);
}
EN_LED_Error_t LED_off_test() {
     return LED_off(TEST_PORT, TEST_PIN);
}
EN_LED_Error_t LED_toggle_test() {
    return LED_toggle(TEST_PORT, TEST_PIN);
}
