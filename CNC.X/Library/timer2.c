#include "header.h"

void open_timer2(void){	// Timer2
//TMR2: 16-bit timer count register
	TMR2=0;		//O registo inicia a 0x0000

//T2CON: Type A Time Base Register
	T2CONbits.TON=0;	// 0-Stops the timer
						// 1-Starts the timer

	T2CONbits.TSIDL=0;	// 0-Continue timer operation in Idle mode
						// 1-Discontinue timer operation when device enters Idle mode

	T2CONbits.TGATE=0;	// 0-Gated time accumulation disabled
						// 1-Gated time accumulation enabled

        //Set on set_rpm(int, int)
	//T2CONbits.TCKPS=3;	// 0- 1:1 prescale value
						// 1- 1:8 prescale value
						// 2- 1:64 prescale value
						// 3- 1:256 prescale value

	T2CONbits.TCS=0;	// 0-Internal clock (FOSC/4)
						// 1-External clock from pin T1CK

//PR2: 16-bit period register associated with the timer
        //Set on set_rpm(int, int)
	//PR2=300;	//Ciclos correspondente ao tempo de 1 segundo para XT_PLL4

//Timer Interrupts configuration
	_T2IF=0;	// 0-Interrupt request has not occurred
				// 1-Interrupt request has occurred

	_T2IE=1;	// 0-Interrupt request not enabled
				// 1-Interrupt request enabled

	_T2IP=3;	// Timer2 Interrutp Priority bits (0-7)

//OSCCON: Oscillator Control Register ? Oscillator System VERSION 1
	_LPOSCEN=0;		// 0-LP oscillator is disabled
					// 1-LP oscillator is enabled
}

void __attribute__((__interrupt__,auto_psv)) _T2Interrupt(void){
    _T2IF=0;

    if(x_count < 2*x_increment){
        CLOCK_X;
        x_count++;
    }
    else{
        x_done = 1;
        DISABLE_X_AXIS;
        DISABLE_CLOCK_X;
    }

    if(exiting_stops && x_count == EXIT_THRESHOLD){
        DISABLE_X_AXIS;
        DISABLE_CLOCK_X;
        x_exited = 1;
        
//        if(ON_BEGINNING_OF_X_AXIS == 0){
//            exit_x_counter++;
//            if(exit_x_counter == EXIT_THRESHOLD){
//                DISABLE_X_AXIS;
//                DISABLE_CLOCK_X;
//                x_exited = 1;
//                //if(DEBUG) printf("Exited x stop\n");
//            }
//        }
//        else exit_x_counter = 0;
    }
    else if((ON_BEGINNING_OF_X_AXIS||ON_END_OF_X_AXIS) && (/*reseting ||*/ executing)){
        x_interrupted++;
        if(x_interrupted >= DIGITAL_FILTER_COUNTER){
            DISABLE_X_AXIS;
            DISABLE_CLOCK_X;
        }
        //if(DEBUG) printf("X ON STOPS!\n");
        //if(executing) printf("err!");
    }
    else if(!(ON_BEGINNING_OF_X_AXIS||ON_END_OF_X_AXIS) && (/*reseting ||*/ executing)){
        x_interrupted = 0;
    }
}

void set_um_per_sec_x(float um_per_sec, int n_microsteps){
    //***Calculo do PR2:***//
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
    //valor de PR2 pelos UM_PER_TURN e divide-se pela velocidade um_per_sec que
    //se quer configurar.
    //Um ajuste ao prescaler e necessario caso o PR2_buffer exceda o limite de
    //16 bits ~ 65500
    int presc = 1;
    long PR2_buffer = (float) FCY*UM_PER_TURN/(2.*n_microsteps*200*um_per_sec*presc)-1;
    if (PR2_buffer > 65500){
        presc = 8;
        PR2_buffer = (float) FCY*UM_PER_TURN/(2.*n_microsteps*200*um_per_sec*presc)-1;
        if (PR2_buffer > 65500){
            presc = 64;
            PR2_buffer = (float) FCY*UM_PER_TURN/(2.*n_microsteps*200*um_per_sec*presc)-1;
            if (PR2_buffer > 65500){
                presc = 256;
                PR2_buffer = (float) FCY*UM_PER_TURN/(2.*n_microsteps*200*um_per_sec*presc)-1;
            }
            else
                PR2 = PR2_buffer;
        }
        else
            PR2 = PR2_buffer;
    }
    else
        PR2 = PR2_buffer;
    switch(presc){
        case 1:
            T2CONbits.TCKPS=0;
            break;
        case 8:
            T2CONbits.TCKPS=1;
            break;
        case 64:
            T2CONbits.TCKPS=2;
            break;
        case 256:
            T2CONbits.TCKPS=3;
            break;
        default:
            T2CONbits.TCKPS=3;
    }
}