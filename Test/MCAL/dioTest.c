#include "../../MCAL/DIO/dio.h"

#define TEST_PORT PORT_A
#define TEST_PIN PIN7

EN_DIO_Error_t DIO_init_test() {
    return DIO_init(TEST_PORT,TEST_PIN,HIGH);
}
EN_DIO_Error_t DIO_write_test() {
    return DIO_write(TEST_PORT,TEST_PIN,HIGH);
}
EN_DIO_Error_t DIO_read_test() {
    uint8_t value = 2;
    EN_DIO_Error_t error =  DIO_read(TEST_PORT,TEST_PIN, &value);
     if(value >= 2)return DIO_ERROR;
     return error;
}
EN_DIO_Error_t DIO_toggle_test() {
    return DIO_toggle(TEST_PORT,TEST_PIN);
}