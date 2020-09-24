#include <stdio.h>
#include <iso646.h>

void main (void){
unsigned char ip[4];
unsigned char mascarared[4];
unsigned char repeticion=0;

	printf("Hola Nidia\n");
	printf("Mi Ip: 8.12.0.60\n");
	printf("Mi MAC: D8-CB-8A-D5-80-33");
	
    do{
		printf("\n======================================================");
		repeticion=0;
		printf("\n\nIngresar IP: \n");
		scanf("%d.%d.%d.%d",&ip[0],&ip[1],&ip[2],&ip[3]);
		printf("-----------------------------------------\n");
		printf("La ip ( %d.%d.%d.%d ) es:  ",ip[0],ip[1],ip[2],ip[3]);
		
			if (ip[0] & 128){					
				if(ip[0] & 64){					
					if(ip[0] & 32){
						if (ip[0] & 16){
							printf("CLASE E");
							mascarared[0]=100;
							mascarared[1]=0;
							mascarared[2]=0;
							mascarared[3]=0;
						}else{
							printf("CLASE D");
							mascarared[0]=100;
							mascarared[1]=0;
							mascarared[2]=0;
							mascarared[3]=0;
						}
					}else{
						printf("CLASE C");
						mascarared[0]=255;
						mascarared[1]=255;
						mascarared[2]=255;
						mascarared[3]=0;
						//------------------------------------------Encontrar su tipo
						if (ip[3] | 0){
							if ((ip[3] | 0)==255){
								printf("\nTipo: Broadcast");
							}else{
								printf("\nTipo: Host");
						
							}
						}else{
							printf("\nTipo: Red");
						}
					}	
				}else{
					printf("CLASE B");
					mascarared[0]=255;
					mascarared[1]=255;
					mascarared[2]=0;
					mascarared[3]=0;
					//------------------------------------------Encontrar su tipo
					if ((ip[3] | 0)||(ip[2] | 0)){
						if (((ip[3] | 0)==255)&&((ip[2] | 0)==255)){
							printf("\nTipo: Broadcast");
						}else{
							printf("\nTipo: Host");
					
						}
					}else{
						printf("\nTipo: Red");
					}
				}
			}else{
				printf("CLASE A");
				mascarared[0]=255;
				mascarared[1]=0;
				mascarared[2]=0;
				mascarared[3]=0;
				//------------------------------------------Encontrar su tipo
				if ((ip[3] | 0)||(ip[2] | 0)||(ip[1] | 0)){
						if (((ip[3] | 0)==255)&&((ip[2] | 0)==255)&&((ip[1] | 0)==255)){
							printf("\nTipo: Broadcast");
						}else{
							printf("\nTipo: Host");
				
						}
					}else{
						printf("\nTipo: Red");
					}
			}
/**---------------------------------------------------------------Obtenemos los demas valores que son solicitados para la red*/
		if (mascarared[0]!=100){
			printf("\nMascara de red: %d.%d.%d.%d",mascarared[0],mascarared[1],mascarared[2],mascarared[3]);
			printf("\nRango de Host: %d.%d.%d.%d",(ip[0]),(ip[1]),(ip[2]),1);
			printf(" --> %d.%d.%d.%d",(ip[0]),(ip[1]),(ip[2]),254);
			printf("\nIp Madre: %d.%d.%d.%d",(ip[0]&mascarared[0]),(ip[1]&mascarared[1]),(ip[2]&mascarared[2]),(ip[3]&mascarared[3]));
			mascarared[0]=~mascarared[0];
			mascarared[1]=~mascarared[1];
			mascarared[2]=~mascarared[2];
			mascarared[3]=~mascarared[3];
			printf("\nIp Difusion: %d.%d.%d.%d",(ip[0]|(mascarared[0])),(ip[1]|(mascarared[1])),(ip[2]|(mascarared[2])),(ip[3]|(mascarared[3])));
		
		}	
		
/**-----------------------------------------------------------------Preguntamos al usuario si quiere repetir el proceso*/		
		printf("\n-----------------------------------------");
		printf("\nDesea Ingresar otra IP? (1/si)(2/no): ");
		scanf("%d",&repeticion);
		system ("cls");
    }while(repeticion!=2);
    printf("\nFIN DEL PROGRAMA");
}
