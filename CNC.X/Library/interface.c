#include "header.h"

int n_microsteps = 8;
int max_um_per_sec_milling = 1000; // Nao implementado
int max_um_per_sec_translating = 5000;

void interface(){
    long int int_buffer;
    char buffer1[20],buffer2[20],buffer3[20];
    int n;

    if(RXbuffer[str_pos-1]==13){        //Quando detecta um return:
            if(strncmp(RXbuffer,"help",4) == 0 && str_pos == 5){
                purge_RXbuffer();               //Limpa o RX_buffer();
                printf("\n-Use 'debug' to toggle debug notifications\n");
                printf("-Use 'localecho' to toggle local echo (for console input)\n");
                printf("-Use 'microsteps' to change the number of microsteps in\n");
                printf("each step to match the switch configuration of the drivers\n");
                printf("-Use 'millingspeed' to configure the speed at which the\n");
                printf("machine moves in micrometers per second when milling\n");
                printf("-Use 'tranlatingspeed' to configure the speed at which the\n");
                printf("machine moves in micrometers per second when not milling\n");
                printf("-Use 'set_xy_origin' to set the origin of the xy axes to the current xy position\n");
                printf("-Use 'set_z_origin' to set the origin of the z axis to the current z position\n");
                printf("-Use 'next_xyz_to_origin' to set the next relative point\n");
                printf("-Use 'next_xyz_absolute' to set the next absolute point\n");
                //printf("-Use 'diff' to set the next differential point\n");
                //printf("-Use 'exe' to execute the next differential point\n\n");
                printf("-Use 'exe' to execute the next point\n");
                printf("-Use 'exeprobe' to probe a conductive surface\n\n");
                printf("-Use 'readback_rel' to print the next relative point\n");
                printf("-Use 'readback_abs' to print the next absolute point\n");
                printf("-Use 'reset' to return the tip to the origin of the referential\n");
                printf("-Use 'sync_position' to probe for present position and origin\n");
                
                printf("New command: ");
            }
            else if(strncmp(RXbuffer,"microsteps",10) == 0 && str_pos == 11){
                purge_RXbuffer();               //Limpa o RX_buffer();
                if(DEBUG) printf("Enter the number of microsteps. The available options are 1, 2, 8 and 16.\n");
                while(1){
                    if(RXbuffer[str_pos-1]==13){
                        sscanf(RXbuffer,"%s",buffer1);
                        if(DEBUG) printf("You entered '%s'",buffer1);
                        if(isnumber(buffer1)){
                            sscanf(buffer1,"%ld",&int_buffer);
                            if(int_buffer == 1 || int_buffer == 2 || int_buffer == 8 || int_buffer == 16){
                                n_microsteps = int_buffer;
                                if(DEBUG) printf(" microsteps.\n\n");
                            }
                            else if(DEBUG) printf(", but that is not a valid option.\n\n");
                        }
                        else if(DEBUG) printf(", but that is not a valid option.\n\n");
                        purge_RXbuffer();               //Limpa o RX_buffer();
                        if(DEBUG) printf("New command: ");
                        break;
                    }
                }
            }
            // Nao esta implementado, so o translating speed e q esta, fica do lado do PC a tarefa de mudar a velocidade
            // entre milling e translating sem milling
            else if(strncmp(RXbuffer,"millingspeed",12) == 0 && str_pos == 13){
                purge_RXbuffer();               //Limpa o RX_buffer();
                if(DEBUG) printf("Enter the milling speed in micrometers per second.\n");
                if(DEBUG) printf("Less than 1000 um/s is advised.\n");
                while(1){
                    if(RXbuffer[str_pos-1]==13){
                        sscanf(RXbuffer,"%s",buffer1);
                        if(DEBUG) printf("You entered '%s'",buffer1);
                        if(isnumber(buffer1)){
                            sscanf(buffer1,"%ld",&int_buffer);
                            if(int_buffer > 0){
                                max_um_per_sec_milling = int_buffer;
                                if(DEBUG) printf(" micrometers per second.\n\n");
                            }
                            else if(DEBUG) printf(", but that is not a valid option.\n\n");
                        }
                        else if(DEBUG) printf(", but that is not a valid option.\n\n");
                        purge_RXbuffer();               //Limpa o RX_buffer();
                        if(DEBUG) printf("New command: ");
                        break;
                    }
                }
            }
            else if(strncmp(RXbuffer,"translatingspeed",16) == 0 && str_pos == 17){
                purge_RXbuffer();               //Limpa o RX_buffer();
                if(DEBUG) printf("Enter the translating speed in micrometers per second.\n");
                if(DEBUG) printf("Less than 5000 um/s is advised.\n");
                while(1){
                    if(RXbuffer[str_pos-1]==13){
                        sscanf(RXbuffer,"%s",buffer1);
                        if(DEBUG) printf("You entered '%s'",buffer1);
                        if(isnumber(buffer1)){
                            sscanf(buffer1,"%ld",&int_buffer);
                            if(int_buffer > 0){
                                max_um_per_sec_translating = int_buffer;
                                if(DEBUG) printf(" micrometers per second.\n\n");
                            }
                            else if(DEBUG) printf(", but that is not a valid option.\n\n");
                        }
                        else if(DEBUG) printf(", but that is not a valid option.\n\n");
                        purge_RXbuffer();               //Limpa o RX_buffer();
                        if(DEBUG) printf("New command: ");
                        break;
                    }
                }
            }
            else if(strncmp(RXbuffer,"set_xy_origin",13) == 0 && str_pos == 14){
                x_origin = x_absolute;
                y_origin = y_absolute;
                if(DEBUG) printf("Origin set to (%ld,%ld,%ld)\n", x_origin,y_origin,z_origin);
                if(DEBUG) printf("\nNew command: ");
            }
            else if(strncmp(RXbuffer,"set_z_origin",12) == 0 && str_pos == 13){
                z_origin = z_absolute;
                if(DEBUG) printf("Origin set to (%ld,%ld,%ld)\n", x_origin,y_origin,z_origin);
                if(DEBUG) printf("\nNew command: ");
            }
            else if(strncmp(RXbuffer,"show_origin",11) == 0 && str_pos == 12){
                printf("Origin set to (%ld,%ld,%ld)\n", x_origin,y_origin,z_origin);
                if(DEBUG) printf("\nNew command: ");
            }
            else if(strncmp(RXbuffer,"next_xyz_to_origin",18) == 0 && str_pos == 19){
                purge_RXbuffer();               //Limpa o RX_buffer();
                if(DEBUG) printf("Insert the next relative point to the origin in micrometers, in the format (x,y,z)\n");

                while(1){
                    if(RXbuffer[str_pos-1]==13){
                        sscanf(RXbuffer,"(%s,%s,%s)",buffer1,buffer2,buffer3);
                        if(isnumber(buffer1) != 1) printf("%s is not a number\n",buffer1);
                        if(isnumber(buffer2) != 1) printf("%s is not a number\n",buffer2);
                        if(isnumber(buffer3) != 1) printf("%s is not a number\n",buffer3);
                        if(isnumber(buffer1) == 1 && isnumber(buffer2) == 1 && isnumber(buffer3) == 1){
                            sscanf(buffer1,"%ld",&next_x_to_origin);
                            sscanf(buffer2,"%ld",&next_y_to_origin);
                            sscanf(buffer3,"%ld",&next_z_to_origin);
                            if(DEBUG) printf("\n\nThe values read were (%ld,%ld,%ld)\n\n",
                                    next_x_to_origin,
                                    next_y_to_origin,
                                    next_z_to_origin);
                            next_x_absolute = next_x_to_origin + x_origin;
                            next_y_absolute = next_y_to_origin + y_origin;
                            next_z_absolute = next_z_to_origin + z_origin;
                        }
                        purge_RXbuffer();
                        if(DEBUG) printf("\nNew command: ");
                        break;
                    }
                }
            }
            else if(strncmp(RXbuffer,"next_xyz_absolute",17) == 0 && str_pos == 18){
                purge_RXbuffer();               //Limpa o RX_buffer();
                if(DEBUG) printf("Insert the next absolute point in micrometers, in the format (x,y,z)\n");

                while(1){
                    if(RXbuffer[str_pos-1]==13){
                        sscanf(RXbuffer,"(%s,%s,%s)",buffer1,buffer2,buffer3);
                        if(isnumber(buffer1) != 1) printf("%s is not a number\n",buffer1);
                        if(isnumber(buffer2) != 1) printf("%s is not a number\n",buffer2);
                        if(isnumber(buffer3) != 1) printf("%s is not a number\n",buffer3);
                        if(isnumber(buffer1) == 1 && isnumber(buffer2) == 1 && isnumber(buffer3) == 1){
                            sscanf(buffer1,"%ld",&next_x_absolute);
                            sscanf(buffer2,"%ld",&next_y_absolute);
                            sscanf(buffer3,"%ld",&next_z_absolute);
                            if(DEBUG) printf("\n\nThe values read were (%ld,%ld,%ld)\n\n",
                                    next_x_absolute,
                                    next_y_absolute,
                                    next_z_absolute);
                        }
                        purge_RXbuffer();
                        if(DEBUG) printf("\nNew command: ");
                        break;
                    }
                }
            }
            else if(strncmp(RXbuffer,"exe",3) == 0 && str_pos == 4){
                purge_RXbuffer();               //Limpa o RX_buffer();
                differential_vector[0] = next_x_absolute - x_absolute;
                differential_vector[1] = next_y_absolute - y_absolute;
                differential_vector[2] = next_z_absolute - z_absolute;
                execute();
                differential_vector[0] = 0;
                differential_vector[1] = 0;
                differential_vector[2] = 0;
                x_to_origin = next_x_to_origin;
                y_to_origin = next_y_to_origin;
                z_to_origin = next_z_to_origin;
                x_absolute = next_x_absolute;
                y_absolute = next_y_absolute;
                z_absolute = next_z_absolute;
                if(DEBUG) printf("\nNew command: ");
            }
            else if(strncmp(RXbuffer,"exeprobe",8) == 0 && str_pos == 9){
                purge_RXbuffer();               //Limpa o RX_buffer();
                probe();
                z_to_origin = z_to_origin - z_drop;
                z_absolute = z_absolute - z_drop;
                printf("%ld!",z_absolute);
                if(DEBUG) printf("\nNew command: ");
            }
            else if(strncmp(RXbuffer,"readback_rel",12) == 0 && str_pos == 13){
                purge_RXbuffer();
                printf("%ld,%ld,%ld!",next_x_to_origin,next_y_to_origin,next_z_to_origin);
                if(DEBUG) printf("\nNew command: ");
            }
            else if(strncmp(RXbuffer,"readback_abs",12) == 0 && str_pos == 13){
                purge_RXbuffer();
                printf("%ld,%ld,%ld!",next_x_absolute,next_y_absolute,next_z_absolute);
                if(DEBUG) printf("\nNew command: ");
            }
            else if(strncmp(RXbuffer,"debug",5) == 0 && str_pos == 6){
                if(DEBUG == 0){
                    DEBUG = 1;
                    printf("DEBUG ENABLED!\n");
                }
                else{
                    DEBUG = 0;
                    printf("DEBUG DISABLED!\n");
                }
                purge_RXbuffer();
            }
            else if(strncmp(RXbuffer,"localecho",9) == 0 && str_pos == 10){
                if(LOCALECHO == 0){
                    LOCALECHO = 1;
                    printf("LOCAL ECHO ENABLED!\n");
                }
                else{
                    LOCALECHO = 0;
                    printf("LOCAL ECHO DISABLED!\n");
                }
                purge_RXbuffer();
            }
            else if(strncmp(RXbuffer,"reset",5) == 0 && str_pos == 6){
                purge_RXbuffer();
                if(DEBUG) printf("Starting reset procedure\nEnter 'stop' to interrupt\n\n");
                reset_position();
                if(DEBUG) printf("\nNew command: ");
            }
            else if(strncmp(RXbuffer,"sync_position",13) == 0 && str_pos == 14){
                purge_RXbuffer();
                printf("%ld,%ld,%ld,%ld,%ld,%ld!",x_absolute,y_absolute,z_absolute,x_origin,y_origin,z_origin);
                if(DEBUG) printf("\nNew command: ");
            }
            else if(strncmp(RXbuffer,"ledon",5) == 0 && str_pos == 6){
                LATDbits.LATD3 = 1;
                purge_RXbuffer();
            }
            else if(strncmp(RXbuffer,"ledoff",6) == 0 && str_pos == 7){
                LATDbits.LATD3 = 0;
                purge_RXbuffer();
            }
            else{
                if(DEBUG) printf("'");
                for(n = 0; RXbuffer[n] != 13; n++) if(DEBUG) printf("%c",RXbuffer[n]);
                if(DEBUG) printf("' command not found.\n\n");
                if(DEBUG) printf("New command: ");
            }

            purge_RXbuffer();               //Limpa o RX_buffer();
            //sscanf(RXbuffer,"%*s\t%ld",&differential_vectors[0][0]);
            //printf("diff = %ld\n",differential_vectors[0][0]);
        }
}
