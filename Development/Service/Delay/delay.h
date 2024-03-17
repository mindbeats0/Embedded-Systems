
#ifndef DELAY_H
#define DELAY_H

#include "../../MCAL/Timer/timer.h"

#define F_CPU 1000000

// 1 pulse duration with prescaler1024 = 1.024 ms
#define T_1024_micro 1.024 

void delay_ms(double delay);

#endif
