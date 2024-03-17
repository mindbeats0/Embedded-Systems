#include "application.h"
#include "../Service/Delay/delay.h"

EN_trafficState_t trafficState;
EN_trafficMode_t  trafficMode;
volatile uint8_t exit_mode;

static inline void pedestrian_mode_on() {
    trafficMode = PEDESTRIAN;
    LED_on(PED_MODE_PORT, PED_MODE_PIN);
}
static inline void pedestrian_mode_off() {
    trafficMode = NORMAL;
    LED_off(PED_MODE_PORT, PED_MODE_PIN);
}
static inline void goto_next_state() {
    trafficState = (trafficState+1)%4; 
}
void APP_init() {
    LED_init(LED_1_PORT, LED_1_PIN);
    LED_init(LED_2_PORT, LED_2_PIN);
    LED_init(LED_3_PORT, LED_3_PIN);
    LED_init(LED_4_PORT, LED_4_PIN);
    LED_init(LED_5_PORT, LED_5_PIN);
    LED_init(LED_6_PORT, LED_6_PIN);
    LED_init(LED_7_PORT, LED_7_PIN);

    BUTTON_init(EXTERNAL_INT_BUTTON_PORT, EXTERNAL_INT_BUTTON_PIN);  

    trafficState = GREEN;
    trafficMode = NORMAL;
    exit_mode = FALSE;
}

/*
    1. State Description
        The flow of the application depends on 3 variables:
        'trafficState': {GREEN, YELLOW_STOP, RED, YELLOW_GO},
        'trafficMode': {NORMAL,PEDESTRIAN} 
        and 'exit_mode': {FALSE, TRUE}.

        According to 'trafficState' {Green, Yellow, Red}, the corresponding led is turned on, 
        the application waits for 5 seconds, then the led is turned off.
        afterwards the 'trafficState' moves to the next state.

    2. Application Flow 
        Initially:
            'trafficMode' is normal and 'exit_mode' is false.
            'trafficState' moves sequentially from state to the next and 
            returns to the beginning, when it finishes the 4 states, to start again the cycle.

        When the button is pressed:
            an interrupt resquest occurs, the ISR function changes the state variables.
            It sets 'trafficState' to RED again if it was already Red
            or to YELLOW_STOP if it was in any of the 3 other states.
            then it sets 'trafficMode' to PREDESTRIAN and 'exit_mode' to FALSE.

            When the application resumes its flow with the new state, 
            it first quits the delay function if it was waiting inside it, 
            and it exits APP_start() function without moving to the next state 
            as the ISR has already set the right state.

            Then, the application flows normally from YELLOW_STOP to RED 
            while having 'trafficMode' set to PREDESTRIAN to avoid further interrupts.
            after finishing RED state, 'trafficMode' is set to NORMAL again to begin 
            listening for any incoming interrupts.
*/
void APP_start() {
    switch (trafficState) {
        case GREEN:
            LED_on(TRAFFIC_GREEN_PORT, TRAFFIC_GREEN_PIN);
            LED_on(PED_RED_PORT, PED_RED_PIN);
            delay_ms(5000);
            LED_off(TRAFFIC_GREEN_PORT, TRAFFIC_GREEN_PIN);
            LED_off(PED_RED_PORT, PED_RED_PIN);
            break;

         case YELLOW_STOP:
         case YELLOW_GO:
            for(int i=0;i<10;i++) {
              LED_toggle(TRAFFIC_YELLOW_PORT, TRAFFIC_YELLOW_PIN);
              LED_toggle(PED_YELLOW_PORT, PED_YELLOW_PIN);
              delay_ms(500);
            }    
            break;

          case RED:
            LED_on(TRAFFIC_RED_PORT, TRAFFIC_RED_PIN);
            LED_on(PED_GREEN_PORT, PED_GREEN_PIN);
            delay_ms(5000);
            LED_off(TRAFFIC_RED_PORT, TRAFFIC_RED_PIN);
            LED_off(PED_GREEN_PORT, PED_GREEN_PIN);
        default:
            break;
    }   
    

    if(!exit_mode) { 
         // Turn off pedestrian mode when red traffic is finished
        if( trafficMode == PEDESTRIAN && trafficState == RED)
            pedestrian_mode_off();
        goto_next_state();
    }
    
    exit_mode = FALSE;
}


/*
    Handle External Interrupt when the button is pressed.

    1. Check if the application in already in trafficMode, return.
    2. Change 'trafficState':
        if trafficState is RED do nothing,
        else change it to YELLOW_STOP.
    3. Set 'trafficMode' to PEDESTRIAN.
    4. Set 'exit_mode' to TRUE to exit current interation.
*/
ISR(EXT_INT_0) {
    if(trafficMode == PEDESTRIAN)  
      return;
    if(trafficState != RED) 
        trafficState = YELLOW_STOP;
    pedestrian_mode_on();
    exit_mode = TRUE; 
}