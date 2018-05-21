#include "header.h"

void open_timer3(void){	// Timer2
//TMR3: 16-bit timer count register
	TMR3=0;		//O registo inicia a 0x0000

//T3CON: Type A Time Base Register
	T3CONbits.TON=0;	// 0-Stops the timer
						// 1-Starts the timer

	T3CONbits.TSIDL=0;	// 0-Continue timer operation in Idle mode
						// 1-Discontinue timer operation when device enters Idle mode

	T3CONbits.TGATE=0;	// 0-Gated time accumulation disabled
						// 1-Gated time accumulation enabled

        //Set on set_rpm(int, int)
	//T3CONbits.TCKPS=3;	// 0- 1:1 prescale value
						// 1- 1:8 prescale value
						// 2- 1:64 prescale value
						// 3- 1:256 prescale value

	T3CONbits.TCS=0;	// 0-Internal clock (FOSC/4)
						// 1-External clock from pin T1CK

//PR3: 16-bit period register associated with the timer
        //Set on set_rpm(int, int)
	//PR2=300;	//Ciclos correspondente ao tempo de 1 segundo para XT_PLL4

//Timer Interrupts configuration
	_T3IF=0;	// 0-Interrupt request has not occurred
				// 1-Interrupt request has occurred

	_T3IE=1;	// 0-Interrupt request not enabled
				// 1-Interrupt request enabled

	_T3IP=4;	// Timer2 Interrutp Priority bits (0-7)

//OSCCON: Oscillator Control Register ? Oscillator System VERSION 1
	_LPOSCEN=0;		// 0-LP oscillator is disabled
					// 1-LP oscillator is enabled
}

void __attribute__((__interrupt__,auto_psv)) _T3Interrupt(void){
    _T3IF=0;

    if(y_count < 2*y_increment){
        CLOCK_Y;
        y_count++;
    }
    else{
        y_done = 1;
        DISABLE_Y_AXIS;
        DISABLE_CLOCK_Y;
    }

    if(exiting_stops && y_count == EXIT_THRESHOLD){
        DISABLE_Y_AXIS;
        DISABLE_CLOCK_Y;
        y_exited = 1;
        
//        if(ON_BEGINNING_OF_Y_AXIS == 0){
//            exit_y_counter++;
//            if(exit_y_counter == EXIT_THRESHOLD){
//                DISABLE_Y_AXIS;
//                DISABLE_CLOCK_Y;
//                y_exited = 1;
//                //if(DEBUG) printf("Exited y stop\n");
//            }
//        }
//        else exit_y_counter = 0;
    }
    else if((ON_BEGINNING_OF_Y_AXIS||ON_END_OF_Y_AXIS) && (/*reseting || */executing)){
        y_interrupted++;
        if(y_interrupted >= DIGITAL_FILTER_COUNTER){
            DISABLE_Y_AXIS;
            DISABLE_CLOCK_Y;
        }
        //if(DEBUG) printf("Y ON STOPS!\n");
        //if(executing) printf("err!");
    }
    else if(!(ON_BEGINNING_OF_Y_AXIS||ON_END_OF_Y_AXIS) && (/*reseting ||*/ executing)){
        y_interrupted = 0;
    }
}

void set_um_per_sec_y(float um_per_sec, int n_microsteps){
    //***Calculo do PR3:***//
    //Cada periodo completo de uma excitacao corresponde a um step no driver.
    //Cada vez que ha uma interrupcao, o flanco da excitacao muda, pelo que
    //o periodo da interrupcao corresponde a metade do periodo da excitacao,
    //por isso se devide FCY por 2.
    //Se forem usados microsteps, um step do motor corresponde ao numero de
    //microsteps que se estao a usar no driver, por isso se divide pelo numero
    //de microsteps configurados
    //Uma rotacao completa corresponde a 200 steps do motor, por isso se divide
    //por 200.
    //Uma volta inteira corresponde a 5 mm de avanco, pelo que se multiplica o
    //valor de PR3 pelos UM_PER_TURN e divide-se pela velocidade um_per_sec que
    //se quer configurar.
    //Um ajuste ao prescaler e necessario caso o PR3_buffer exceda o limite de
    //16 bits ~ 65500
    int presc = 1;
    long int PR3_buffer = (float) FCY*UM_PER_TURN/(2.*n_microsteps*200*um_per_sec*presc)-1;
    //printf("%ld\n",PR3_buffer);
    if (PR3_buffer > 65500){
        presc = 8;
        PR3_buffer = (float) FCY*UM_PER_TURN/(2.*n_microsteps*200*um_per_sec*presc)-1;
        if (PR3_buffer > 65500){
            presc = 64;
            PR3_buffer = (float) FCY*UM_PER_TURN/(2.*n_microsteps*200*um_per_sec*presc)-1;
            if (PR3_buffer > 65500){
                presc = 256;
                PR3_buffer = (float) FCY*UM_PER_TURN/(2.*n_microsteps*200*um_per_sec*presc)-1;
            }
            else
                PR3 = PR3_buffer;
        }
        else
            PR3 = PR3_buffer;
    }
    else
        PR3 = PR3_buffer;
    switch(presc){
        case 1:
            T3CONbits.TCKPS=0;
            break;
        case 8:
            T3CONbits.TCKPS=1;
            break;
        case 64:
            T3CONbits.TCKPS=2;
            break;
        case 256:
            T3CONbits.TCKPS=3;
            break;
        default:
            T3CONbits.TCKPS=3;
    }
}
