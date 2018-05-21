#define FCY 29491000L
#define BAUD_RATE 115200
#define OUTPUT 0
#define INPUT 1

#define UM_PER_TURN 5000
#define MAX_UM_PER_SEC 5000

#define ENABLE_X_AXIS LATBbits.LATB0 = 0
#define DISABLE_X_AXIS LATBbits.LATB0 = 1
#define ENABLE_CLOCK_X T2CONbits.TON=1
#define DISABLE_CLOCK_X T2CONbits.TON=0
#define CLOCK_X_ENABLED T2CONbits.TON
#define CLOCK_X LATEbits.LATE0=!LATEbits.LATE0
#define X_FRONT LATEbits.LATE1 = 1
#define X_BACK LATEbits.LATE1 = 0
#define ON_END_OF_X_AXIS !PORTBbits.RB4
#define ON_BEGINNING_OF_X_AXIS !PORTBbits.RB3

#define ENABLE_Y_AXIS LATBbits.LATB1 = 0
#define DISABLE_Y_AXIS LATBbits.LATB1 = 1
#define ENABLE_CLOCK_Y T3CONbits.TON=1
#define DISABLE_CLOCK_Y T3CONbits.TON=0
#define CLOCK_Y_ENABLED T3CONbits.TON
#define CLOCK_Y LATEbits.LATE2=!LATEbits.LATE2
#define Y_LEFT LATEbits.LATE3 = 0
#define Y_RIGHT LATEbits.LATE3 = 1
#define ON_END_OF_Y_AXIS !PORTBbits.RB7
#define ON_BEGINNING_OF_Y_AXIS !PORTBbits.RB8

#define ENABLE_Z_AXIS LATBbits.LATB2 = 0
#define DISABLE_Z_AXIS LATBbits.LATB2 = 1
#define ENABLE_CLOCK_Z T4CONbits.TON=1
#define DISABLE_CLOCK_Z T4CONbits.TON=0
#define CLOCK_Z_ENABLED T4CONbits.TON
#define CLOCK_Z LATEbits.LATE4=!LATEbits.LATE4
#define Z_UP LATEbits.LATE5 = 1
#define Z_DOWN LATEbits.LATE5 = 0
#define ON_END_OF_Z_AXIS !PORTBbits.RB5
#define ON_BEGINNING_OF_Z_AXIS !PORTBbits.RB6

#define EXIT_THRESHOLD 4000
#define DIGITAL_FILTER_COUNTER 10