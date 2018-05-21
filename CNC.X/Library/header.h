#include <p30f4011.h>
//#include <ctype.h>
#include <stdio.h>			//biblioteca standart IO do C
#include <libpic30.h>		//definicoes extra para as bibliotecas do C30
//#include "uart.h"			//biblioteca com as funcoes para usar a UART (porta serie)
#include <string.h>
#include <math.h>
#include "user_defines.h"

//
//config_pins.c
//
void config_pins(void);

//
//delay.c
//
void delay_ms(unsigned int);
void delay_100us(unsigned int);
void delay_10us(unsigned int);

//
//interface.c
//
extern int n_microsteps;
extern int max_um_per_sec_milling;
extern int max_um_per_sec_translating;
void interface(void);

//
//main.c
//
int main(void);
extern int DEBUG;

//
//plot_manager.c
//
extern long int x_origin;
extern long int y_origin;
extern long int z_origin;

extern long int x_absolute;
extern long int y_absolute;
extern long int z_absolute;
extern long int next_x_absolute;
extern long int next_y_absolute;
extern long int next_z_absolute;

extern long int x_to_origin;
extern long int y_to_origin;
extern long int z_to_origin;
extern long int next_x_to_origin;
extern long int next_y_to_origin;
extern long int next_z_to_origin;

extern long int differential_vector[3];
extern long int x_count;
extern long int y_count;
extern long int z_count;
extern long int x_increment;
extern long int y_increment;
extern long int z_increment;
extern int x_done;
extern int y_done;
extern int z_done;
extern int x_exited;
extern int y_exited;
extern int z_exited;
extern int x_interrupted;
extern int y_interrupted;
extern int z_interrupted;
extern int exit_x_counter;
extern int exit_y_counter;
extern int exit_z_counter;
extern int reseting;
extern int exiting_stops;
extern int executing;
void execute(void);
void reset_position(void);

//
//timer2.c
//
void open_timer2(void);
void __attribute__((__interrupt__,auto_psv)) _T2Interrupt(void);
void set_um_per_sec_x(float, int);

//
//timer3.c
//
void open_timer3(void);
void __attribute__((__interrupt__,auto_psv)) _T3Interrupt(void);
void set_um_per_sec_y(float, int);

//
//timer4.c
//
void open_timer4(void);
void __attribute__((__interrupt__,auto_psv)) _T4Interrupt(void);
void set_um_per_sec_z(float, int);

//
// uart.c
//
extern char RXbuffer[];
extern int str_pos;
extern int LOCALECHO;
void uart_config(void);
void purge_RXbuffer(void);
void __attribute__((__interrupt__,auto_psv)) _U2RXInterrupt(void);

//
//utils.c
//
int isnumber(char[]);
float mod(float);
float max_of_three(float, float, float);
