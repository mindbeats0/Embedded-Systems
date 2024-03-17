#ifndef TEST_H
#define TEST_H

#include "../MCAL/DIO/dio.h"
#include "../MCAL/Interrupts/interrupts.h"
#include "../ECUAL/LED/led.h"
#include "../ECUAL/Button/button.h"

#define LED_FAIL_PORT  LED_8_PORT
#define LED_FAIL_PIN   LED_8_PIN
#define LED_PASS_PORT  LED_9_PORT
#define LED_PASS_PIN   LED_9_PIN

// DIO Test Module:
EN_DIO_Error_t DIO_init_test();
EN_DIO_Error_t DIO_write_test();
EN_DIO_Error_t DIO_read_test();
EN_DIO_Error_t DIO_toggle_test();

// Interrupts Test Module:
EN_INT_Error_t GLOBAL_INT_enable_test();
EN_INT_Error_t GLOBAL_INT_disable_test();
EN_INT_Error_t INT_disable_test();
EN_INT_Error_t INT_enable_test();


// Button Test Module:
EN_buttonError_t BUTTON_read_test();
EN_buttonError_t BUTTON_init_test();

// LED Test Module:
EN_LED_Error_t LED_init_test();
EN_LED_Error_t LED_on_test();
EN_LED_Error_t LED_off_test();
EN_LED_Error_t LED_toggle_test(); 

#endif
