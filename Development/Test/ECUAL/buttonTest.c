#include "../../ECUAL/Button/button.h"
#include "../../Utilities/types.h"

#define TEST_PORT PORT_A
#define TEST_PIN PIN7

EN_buttonError_t BUTTON_init_test() {
    return BUTTON_init(TEST_PORT, TEST_PIN);
}
EN_buttonError_t BUTTON_read_test() {
    uint8_t value = 2;
    EN_buttonError_t error = BUTTON_read(TEST_PORT, TEST_PIN, &value);
    if(value >= 2)return BUTTON_ERROR;
    return error;
}