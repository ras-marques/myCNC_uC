#include "Library/header.h"

//Configuration bits
_FOSC(CSW_FSCM_OFF & XT_PLL16);
//_FOSC(CSW_FSCM_OFF & FRC);  //oscilator
//_FWDT(WDT_ON & WDTPSA_512 & WDTPSB_16);  //watchdog timer (interval of ~ 16s)
_FWDT(WDT_OFF);

int DEBUG = 0;

int main(){
    uart_config();

    config_pins();

    DISABLE_X_AXIS;
    DISABLE_Y_AXIS;
    DISABLE_Z_AXIS;

    open_timer2();
    open_timer3();
    open_timer4();

    delay_ms(400);
    printf("\nCNC system start.\n");
    printf("Enter 'help' for a list of useful commands.\n\n");
    printf("New command: ");

    LATDbits.LATD3 = 1;

    while(1){
        interface();
        delay_ms(2);
    }
}
