#include "header.h"

void delay_ms(unsigned int delay){   //delay in miliseconds
 unsigned int cycles;
 for(;delay;delay--)
    for(cycles=FCY/4000;cycles;cycles--);
}

void delay_100us(unsigned int delay){   //delay in 100 useconds
 unsigned int cycles;
 for(;delay;delay--)
    for(cycles=FCY/40000;cycles;cycles--);
}

void delay_10us(unsigned int delay){   //delay in 10 useconds (approximately)
 unsigned int cycles;
 for(;delay;delay--)
    for(cycles=FCY/400000;cycles;cycles--);
}
