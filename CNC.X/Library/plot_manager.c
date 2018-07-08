#include "header.h"

long int x_origin;
long int y_origin;
long int z_origin;

long int x_absolute;
long int y_absolute;
long int z_absolute;
long int next_x_absolute;
long int next_y_absolute;
long int next_z_absolute;

long int x_to_origin;
long int y_to_origin;
long int z_to_origin;
long int next_x_to_origin;
long int next_y_to_origin;
long int next_z_to_origin;

long int differential_vector[3];
long int x_count;
long int y_count;
long int z_count;
long int x_increment;
long int y_increment;
long int z_increment;
long int z_drop;
int x_done;
int y_done;
int z_done;
int x_exited;
int y_exited;
int z_exited;
int x_interrupted;
int y_interrupted;
int z_interrupted;
int exit_x_counter;
int exit_y_counter;
int exit_z_counter;
int reseting;
int exiting_stops;
int executing;
int probing;

long int x_start_probe;
long int y_start_probe;
long int z_start_probe;
long int x_end_probe;
long int y_end_probe;
long int z_end_probe;
int gridsize;

void reset_position(){
    reseting = 1;
    exiting_stops = 0;
    executing = 0;
    probing = 0;
    int n;
    set_um_per_sec_x(max_um_per_sec_translating, n_microsteps);
    set_um_per_sec_y(max_um_per_sec_translating, n_microsteps);
    set_um_per_sec_z(max_um_per_sec_translating, n_microsteps);
    x_exited = 0;
    y_exited = 0;
    z_exited = 0;
    x_increment = 1000000000;   //Plenty increments to buffer the reset
    y_increment = 1000000000;   //Plenty increments to buffer the reset
    z_increment = 1000000000;   //Plenty increments to buffer the reset
    X_BACK;
    Y_LEFT;
    Z_UP;
    ENABLE_Z_AXIS;
    ENABLE_CLOCK_Z;
    
    int on_ref_origin = 0;
    while(1){
        if(ON_BEGINNING_OF_X_AXIS && CLOCK_X_ENABLED){
            DISABLE_X_AXIS;
            DISABLE_CLOCK_X;
            if(DEBUG) printf("X_DISABLED_ON_BEGINNING\n");
        }
        /*if(ON_END_OF_X_AXIS && CLOCK_X_ENABLED){
            DISABLE_X_AXIS;
            DISABLE_CLOCK_X;
            if(DEBUG) printf("X_DISABLED_ON_END\n");
        }*/
        if(ON_BEGINNING_OF_Y_AXIS && CLOCK_Y_ENABLED){
            DISABLE_Y_AXIS;
            DISABLE_CLOCK_Y;
            if(DEBUG) printf("Y_DISABLED_ON_BEGINNING\n");
        }
        /*if(ON_END_OF_Y_AXIS && CLOCK_Y_ENABLED){
            DISABLE_Y_AXIS;
            DISABLE_CLOCK_Y;
            if(DEBUG) printf("Y_DISABLED_ON_END\n");
        }*/
        if(ON_BEGINNING_OF_Z_AXIS && CLOCK_Z_ENABLED){
            DISABLE_Z_AXIS;
            DISABLE_CLOCK_Z;
            
            ENABLE_X_AXIS;
            ENABLE_CLOCK_X;
            ENABLE_Y_AXIS;
            ENABLE_CLOCK_Y;
            if(DEBUG) printf("Z_DISABLED_ON_BEGINNING\n");
        }
        /*if(ON_END_OF_Z_AXIS && CLOCK_Z_ENABLED){
            DISABLE_Z_AXIS;
            DISABLE_CLOCK_Z;
            if(DEBUG) printf("Z_DISABLED_ON_END\n");
        }*/
        if((ON_BEGINNING_OF_X_AXIS) &&
           (ON_BEGINNING_OF_Y_AXIS) &&
           (ON_BEGINNING_OF_Z_AXIS)){
            on_ref_origin = 1;
            DISABLE_X_AXIS;
            DISABLE_CLOCK_X;
            DISABLE_Y_AXIS;
            DISABLE_CLOCK_Y;
            DISABLE_Z_AXIS;
            DISABLE_CLOCK_Z;
            if(DEBUG) printf("ON_RESET\n");
            break;
        }

        if(RXbuffer[str_pos-1]==13){        //Quando detecta um return:
            if(strncmp(RXbuffer,"stop",4) == 0 && str_pos == 5){
                DISABLE_X_AXIS;
                DISABLE_CLOCK_X;
                DISABLE_Y_AXIS;
                DISABLE_CLOCK_Y;
                DISABLE_Z_AXIS;
                DISABLE_CLOCK_Z;
                break;
            }
            else{
                if(DEBUG) printf("'");
                for(n = 0; RXbuffer[n] != 13; n++){
                    if(DEBUG) printf("%c",RXbuffer[n]);
                }
                if(DEBUG) printf("' command not found, only 'stop' is available at the moment\n");
                if(DEBUG) printf("New command: ");
            }
            purge_RXbuffer();               //Limpa o RX_buffer();
        }
    }

    if(on_ref_origin == 1){
        reseting = 0;
        executing = 0;
        if(DEBUG) printf("Machine back to origin. Exiting stops.\n");
        delay_ms(200);
        exit_x_counter = 0;
        exit_y_counter = 0;
        exit_z_counter = 0;
        exiting_stops = 1;
        X_FRONT;
        Y_RIGHT;
        Z_DOWN;
        x_count = 0;
        y_count = 0;
        z_count = 0;
        x_increment = 1000000000;   //Plenty increments to exit stops
        y_increment = 1000000000;   //Plenty increments to exit stops
        z_increment = 1000000000;   //Plenty increments to exit stops
        ENABLE_X_AXIS;
        ENABLE_CLOCK_X;
        ENABLE_Y_AXIS;
        ENABLE_CLOCK_Y;
        ENABLE_Z_AXIS;
        ENABLE_CLOCK_Z;
        while(1){
            if(DEBUG){
                printf("EXITED:\t");
                if(ON_BEGINNING_OF_X_AXIS == 0) printf("X-YES\t");
                else printf("X-NO\t");
                if(ON_BEGINNING_OF_Y_AXIS == 0) printf("Y-YES\t");
                else printf("Y-NO\t");
                if(ON_BEGINNING_OF_Z_AXIS == 0) printf("Z-YES\n");
                else printf("Z-NO\n");
            }
            if(x_exited == 1 &&
               y_exited == 1 &&
               z_exited == 1){
                DISABLE_X_AXIS;
                DISABLE_CLOCK_X;
                DISABLE_Y_AXIS;
                DISABLE_CLOCK_Y;
                DISABLE_Z_AXIS;
                DISABLE_CLOCK_Z;
                x_exited = 0;
                y_exited = 0;
                z_exited = 0;
                break;
            }
        }
        x_origin = 0;
        y_origin = 0;
        z_origin = 0;
        
        x_absolute = 0;
        y_absolute = 0;
        z_absolute = 0;
        next_x_absolute = 0;
        next_y_absolute = 0;
        next_z_absolute = 0;

        x_to_origin = 0;
        y_to_origin = 0;
        z_to_origin = 0;
        next_x_to_origin = 0;
        next_y_to_origin = 0;
        next_z_to_origin = 0;
        
        if(DEBUG) printf("Machine is back to the origin.\n");
        printf("done!");
    }
    else if(DEBUG) printf("Reset procedure interrupted\n\n");
}

void probe(){
    executing = 0;
    exiting_stops = 0;
    reseting = 0;
    probing = 1;
    
    z_count = 0;
    //A ponta deve estar a menos de 30mm (30000um) da placa para
    //avaliar a sua posicao, mais que isso leva demasiado tempo
    z_increment = (long) n_microsteps*200*30000/UM_PER_TURN;
    z_done = 0;
    z_interrupted = 0;
    set_um_per_sec_z(max_um_per_sec_translating, n_microsteps);
    Z_DOWN;
    ENABLE_Z_AXIS;
    ENABLE_CLOCK_Z;
    if (DEBUG) printf("probing\n");
    while(z_done == 0){}
    DISABLE_Z_AXIS;
    DISABLE_CLOCK_Z;
    //z_to_origin = fazer conta com z_count;
    //z_absolute = fazer conta com z_count;
    z_drop = z_count*UM_PER_TURN/(2.*n_microsteps*200);
    //printf("%ld",z_drop);
    z_count = 0;
}

void execute(){
    executing = 1;
    exiting_stops = 0;
    reseting = 0;
    probing = 0;
    int n;
    if (DEBUG) printf("executing\n");
    long long int long_long_buffer1, long_long_buffer2, long_long_buffer3;
    int max;
    double hypotenuse;

    long_long_buffer1 = differential_vector[0];
    long_long_buffer2 = differential_vector[1];
    long_long_buffer3 = differential_vector[2];
    max = max_of_three(long_long_buffer1,long_long_buffer2,long_long_buffer3);

    if(long_long_buffer1 >= 0) X_FRONT;
    else X_BACK;
    if(long_long_buffer2 >= 0) Y_RIGHT;
    else Y_LEFT;
    if(long_long_buffer3 >= 0) Z_UP;
    else Z_DOWN;

    hypotenuse = pow(long_long_buffer1*long_long_buffer1+
                     long_long_buffer2*long_long_buffer2+
                     long_long_buffer3*long_long_buffer3,0.5);

    float um_per_sec_x = (float) max_um_per_sec_translating*mod(long_long_buffer1)/hypotenuse;
    float um_per_sec_y = (float) max_um_per_sec_translating*mod(long_long_buffer2)/hypotenuse;
    float um_per_sec_z = (float) max_um_per_sec_translating*mod(long_long_buffer3)/hypotenuse;

    hypotenuse = pow(um_per_sec_x*um_per_sec_x+
                     um_per_sec_y*um_per_sec_y+
                     um_per_sec_z*um_per_sec_z,0.5);

    x_count = 0;
    y_count = 0;
    z_count = 0;
    x_increment = n_microsteps*200*mod(long_long_buffer1)/UM_PER_TURN;
    y_increment = n_microsteps*200*mod(long_long_buffer2)/UM_PER_TURN;
    z_increment = n_microsteps*200*mod(long_long_buffer3)/UM_PER_TURN;
    x_done = 0;
    y_done = 0;
    z_done = 0;
    x_interrupted = 0;
    y_interrupted = 0;
    z_interrupted = 0;

    set_um_per_sec_x(um_per_sec_x, n_microsteps);
    set_um_per_sec_y(um_per_sec_y, n_microsteps);
    set_um_per_sec_z(um_per_sec_z, n_microsteps);

    if(DEBUG) printf("Diff: (%lld,%lld,%lld) ",long_long_buffer1,long_long_buffer2,long_long_buffer3);
    if(DEBUG) printf("Increments: (%ld,%ld,%ld)\n",x_increment,y_increment,z_increment);

    if(x_increment > 0){
        ENABLE_X_AXIS;
        ENABLE_CLOCK_X;
    }
    else x_done = 1;

    if(y_increment > 0){
        ENABLE_Y_AXIS;
        ENABLE_CLOCK_Y;
    }
    else y_done = 1;

    if(z_increment > 0){
        ENABLE_Z_AXIS;
        ENABLE_CLOCK_Z;
    }
    else z_done = 1;

    while(x_done == 0 || y_done == 0 || z_done == 0){
        if(RXbuffer[str_pos-1]==13){        //Quando detecta um return:
            if(strncmp(RXbuffer,"stop",4) == 0 && str_pos == 5){
                if(DEBUG) printf("Plot aborted by user request\n");
                break;
            }
            else{
                if(DEBUG) printf("'");
                for(n = 0; RXbuffer[n] != 13; n++){
                    if(DEBUG) printf("%c",RXbuffer[n]);
                }
                if(DEBUG) printf("' command not found, only 'stop' is available at the moment\n");
                if(DEBUG) printf("Reset continuing...");
            }
            purge_RXbuffer();
        }
        if(x_interrupted >= DIGITAL_FILTER_COUNTER || y_interrupted >= DIGITAL_FILTER_COUNTER || z_interrupted >= DIGITAL_FILTER_COUNTER){
            printf("interrupt!");
            if(DEBUG){
                if(x_interrupted >= DIGITAL_FILTER_COUNTER) printf("x");
                if(y_interrupted >= DIGITAL_FILTER_COUNTER) printf("y");
                if(z_interrupted >= DIGITAL_FILTER_COUNTER) printf("z");
            }
            break;
        }
    }

    DISABLE_X_AXIS;
    DISABLE_CLOCK_X;
    DISABLE_Y_AXIS;
    DISABLE_CLOCK_Y;
    DISABLE_Z_AXIS;
    DISABLE_CLOCK_Z;
    printf("done!");
}