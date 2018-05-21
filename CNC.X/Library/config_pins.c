#include "header.h"

void config_pins(){
    //TESTS
    TRISDbits.TRISD3 = OUTPUT;

    //MOTOR CLOCK
    TRISEbits.TRISE0=OUTPUT;
    TRISEbits.TRISE2=OUTPUT;
    TRISEbits.TRISE4=OUTPUT;

    //MOTOR DIRECTION
    TRISEbits.TRISE1=OUTPUT;
    TRISEbits.TRISE3=OUTPUT;
    TRISEbits.TRISE5=OUTPUT;

    //MOTOR ENABLES
    ADPCFGbits.PCFG0 = 1;//Defines pin as digital
    ADPCFGbits.PCFG1 = 1;//Defines pin as digital
    ADPCFGbits.PCFG2 = 1;//Defines pin as digital
    TRISBbits.TRISB0=OUTPUT;
    TRISBbits.TRISB1=OUTPUT;
    TRISBbits.TRISB2=OUTPUT;

    //MICROSWITHCES
    ADPCFGbits.PCFG3 = 1;//Defines pin as digital
    ADPCFGbits.PCFG4 = 1;//Defines pin as digital
    ADPCFGbits.PCFG5 = 1;//Defines pin as digital
    ADPCFGbits.PCFG6 = 1;//Defines pin as digital
    ADPCFGbits.PCFG7 = 1;//Defines pin as digital
    ADPCFGbits.PCFG8 = 1;//Defines pin as digital
    TRISBbits.TRISB3=INPUT;
    TRISBbits.TRISB4=INPUT;
    TRISBbits.TRISB5=INPUT;
    TRISBbits.TRISB6=INPUT;
    TRISBbits.TRISB7=INPUT;
    TRISBbits.TRISB8=INPUT;
}
