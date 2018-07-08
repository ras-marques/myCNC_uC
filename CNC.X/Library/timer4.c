#include "header.h"

void open_timer4(void){	// Timer2
//TMR4: 16-bit timer count register
	TMR4=0;		//O registo inicia a 0x0000

//T4CON: Type A Time Base Register
	T4CONbits.TON=0;	// 0-Stops the timer
						// 1-Starts the timer

	T4CONbits.TSIDL=0;	// 0-Continue timer operation in Idle mode
						// 1-Discontinue timer operation when device enters Idle mode

	T4CONbits.TGATE=0;	// 0-Gated time accumulation disabled
						// 1-Gated time accumulation enabled

        //Set on set_rpm(int, int)
	//T4CONbits.TCKPS=3;	// 0- 1:1 prescale value
						// 1- 1:8 prescale value
						// 2- 1:64 prescale value
						// 3- 1:256 prescale value

	T4CONbits.TCS=0;	// 0-Internal clock (FOSC/4)
						// 1-External clock from pin T1CK

//PR4: 16-bit period register associated with the timer
        //Set on set_rpm(int, int)
	//PR4=300;	//Ciclos correspondente ao tempo de 1 segundo para XT_PLL4

//Timer Interrupts configuration
	_T4IF=0;	// 0-Interrupt request has not occurred
				// 1-Interrupt request has occurred

	_T4IE=1;	// 0-Interrupt request not enabled
				// 1-Interrupt request enabled

	_T4IP=5;	// Timer2 Interrutp Priority bits (0-7)

//OSCCON: Oscillator Control Register ? Oscillator System VERSION 1
	_LPOSCEN=0;		// 0-LP oscillator is disabled
					// 1-LP oscillator is enabled
}

void __attribute__((__interrupt__,auto_psv)) _T4Interrupt(void){
    _T4IF=0;

    if(z_count < 2*z_increment){
        CLOCK_Z;
        z_count++;
    }
    else{
        z_done = 1;
        DISABLE_Z_AXIS;
        DISABLE_CLOCK_Z;
    }
    
    if(!(z_count%2) && probing && TOOL_TOUCHING_BOARD){
        z_done = 1;
        DISABLE_Z_AXIS;
        DISABLE_CLOCK_Z;
    }

    if(exiting_stops && z_count == EXIT_THRESHOLD){
        DISABLE_Z_AXIS;
        DISABLE_CLOCK_Z;
        z_exited = 1;
//        if(ON_BEGINNING_OF_Z_AXIS == 0){
//            exit_z_counter++;
//            if(exit_z_counter == EXIT_THRESHOLD){
//                DISABLE_Z_AXIS;
//                DISABLE_CLOCK_Z;
//                z_exited = 1;
//                //if(DEBUG) printf("Exited z stop\n");
//            }
//        }
//        else exit_z_counter = 0;
    }
    else if((ON_BEGINNING_OF_Z_AXIS||ON_END_OF_Z_AXIS) && (/*reseting || */executing || probing)){
        z_interrupted++;
        if(z_interrupted >= DIGITAL_FILTER_COUNTER){
            DISABLE_Z_AXIS;
            DISABLE_CLOCK_Z;
        }
        //if(DEBUG) printf("Z ON STOPS!\n");
        //if(executing) printf("err!");
    }
    else if(!(ON_BEGINNING_OF_Z_AXIS||ON_END_OF_Z_AXIS) && (/*reseting ||*/ executing || probing)){
        z_interrupted = 0;
    }
}

void set_um_per_sec_z(float um_per_sec, int n_microsteps){
    //***Calculo do PR4:***//
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
    //valor de PR4 pelos UM_PER_TURN e divide-se pela velocidade um_per_sec que
    //se quer configurar.
    //Um ajuste ao prescaler e necessario caso o PR4_buffer exceda o limite de
    //16 bits ~ 65500
    int presc = 1;
    long int PR4_buffer = (float) FCY*UM_PER_TURN/(2.*n_microsteps*200*um_per_sec*presc)-1;
    //printf("%ld\n",PR4_buffer);
    if (PR4_buffer > 65500){
        presc = 8;
        PR4_buffer = (float) FCY*UM_PER_TURN/(2.*n_microsteps*200*um_per_sec*presc)-1;
        if (PR4_buffer > 65500){
            presc = 64;
            PR4_buffer = (float) FCY*UM_PER_TURN/(2.*n_microsteps*200*um_per_sec*presc)-1;
            if (PR4_buffer > 65500){
                presc = 256;
                PR4_buffer = (float) FCY*UM_PER_TURN/(2.*n_microsteps*200*um_per_sec*presc)-1;
            }
            else
                PR4 = PR4_buffer;
        }
        else
            PR4 = PR4_buffer;
    }
    else
        PR4 = PR4_buffer;
    switch(presc){
        case 1:
            T4CONbits.TCKPS=0;
            break;
        case 8:
            T4CONbits.TCKPS=1;
            break;
        case 64:
            T4CONbits.TCKPS=2;
            break;
        case 256:
            T4CONbits.TCKPS=3;
            break;
        default:
            T4CONbits.TCKPS=3;
    }
}
