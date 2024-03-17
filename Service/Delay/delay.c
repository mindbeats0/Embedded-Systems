#include "delay.h"

extern volatile uint8_t exit_mode;

// Delay in milliseconds
void delay_ms(double delay) {

    /*
        F_CPU = 1Mhz
        Timer0
        counter_steps=256
        prescaler=1024
        
        1 pulse duration = 1.024 ms      (T_1024_micro)
        1 overflow duration = 262.144 ms (TIMER0_CNT * T_1024_micro)

        For delay=5000 ms -> We need 3.81 overflows
        So: N = 4
            extra counts: (N-overflows) = 0.19
            Discard extra counts by setting init_value = TIMER0_CNT * (N-overflows)
    */

    double overflows = delay/(TIMER0_CNT * T_1024_micro);
    unsigned int N = (int)overflows + 1;

    Timer_start(TIMER0, PRESCALER1024, TIMER0_CNT * (N-overflows));
    while(N--){
        while(TIMER0_OVFLAG == 0 && !exit_mode);
        CLEAR_TIMER0_OVFLAG;
    }
    Timer_stop(TIMER0);
}