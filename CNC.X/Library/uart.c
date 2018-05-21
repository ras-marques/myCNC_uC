#include "header.h"

char RXbuffer[80];	//Buffer usado para armazenar caracteres da porta serie.
int str_pos = 0; 	//Posicao no RXbuffer.
int LOCALECHO = 0;

void purge_RXbuffer(){			//Funcao para limpar o RXbuffer.
	int i=0;
	for(i=0;i<80;i++){RXbuffer[i] = '\0';}	//Inicializa cada posicao no RXbuffer.
	str_pos = 0;    			//Inicializa a posicao no buffer.
}

void uart_config(void) {
    /**********************************
      SerialPort configuration
    **********************************/
    U2MODEbits.UARTEN = 0;	// Bit15 TX, RX DISABLED, ENABLE at end of func
    U2MODEbits.USIDL = 0;	// Bit13 Continue in Idle
    U2MODEbits.WAKE = 0;	// Bit7 No Wake up (since we don't sleep here)
    U2MODEbits.LPBACK = 0;	// Bit6 No Loop Back
    U2MODEbits.ABAUD = 0;	// Bit5 No Autobaud (would require sending '55')
    U2MODEbits.PDSEL = 0;	// Bits1,2 8bit, No Parity
    U2MODEbits.STSEL = 0;	// Bit0 One Stop Bit

    // Load a value into Baud Rate Generator.  Example is for 115200.
    //U2BRG = (FCY*1000/(16*BAUD_RATE))-1;
    U2BRG = 15;

    IFS1bits.U2RXIF = 0;	// Clear the Receive Interrupt Flag
    IEC1bits.U2RXIE = 1;	// Enable Receive Interrupts

    U2MODEbits.UARTEN = 1;	// And turn the peripheral on

    __C30_UART = 2; //Define a porta serie 2 como predefinida para as funcoes da stdio.h.

    /**********************************
      End of serialPort configuration
    **********************************/
    printf("\n\nSystem starting...\n");
}

/* This is UART2 receive ISR */
void __attribute__((__interrupt__,auto_psv)) _U2RXInterrupt(void){
    IFS1bits.U2RXIF = 0;	//Reinicializa a flag do interrupt Rx2
    while(U2STAbits.URXDA){ //Enquanto tiver caracteres prontos a ser lidos não sai do ciclo
        LATBbits.LATB3++;               //Alterna o estado de um pino que pode ser um LED
        RXbuffer[str_pos] = U2RXREG;    //Armazena no RXbuffer o ultimo caracter recebido.
        if(RXbuffer[str_pos] == 8){
            RXbuffer[str_pos] = '\0';
            if(str_pos > 0){
                if(LOCALECHO == 1) putchar(127); //Echoes a Backspace
                str_pos--;
                RXbuffer[str_pos] = '\0';
            }
        }
        else{
            if(LOCALECHO == 1) putchar(RXbuffer[str_pos]); //Local Echo
            str_pos++;  //Incrementa a posicão no buffer para armazenar o caracter seguinte.
        }
        if(str_pos >= 80){str_pos = 0;} //Ao chegar a ultima posicao, volta a primeira.
    }
}
