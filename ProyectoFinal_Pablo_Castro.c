//Programa para pedir alcohol
#include<stdlib.h>
#define SEPARADOR "========================================="
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<math.h>
#include<time.h>

int registro();
int menu();
int sesion();
int sistema();
int pedido();
int intento2();
int establecimientos();
int eleven();
int alianza();
int oxxo();
int tiempo();
 int aux, costo, suma;
            
int main(){
	menu();
	system("pause");
	return 0;
}

int menu(){
int iniciarsesion=0;
char continuar[1];
do{
	printf("\n 1.Iniciar sesion.");
    printf("\n 2.Registrarse");
    printf ("\nOpcion: ");
    scanf("%i",&iniciarsesion);
    system("cls");
	switch(iniciarsesion){
	case 1:
	sesion();
	break;
	case 2:
	registro();
	system ("cls");
       printf ("\n\n                             =================== Registro exitoso :) ===================   \n"); 
       system("pause");
       printf ("\n\n\n .....excepto la de Apagado, mi tío.\n ");
        system ("cls");
	menu();
	break;
	}	

}while (strcmp(continuar, "hshsjshshsj")!=0);
return 0;
}

int sesion(){
FILE *archivo;
 char cadena[80];
 int contadorDeCadenas=0;
 char seg[]=":";
 char *segmento;
 char *segmento2;
 char usuario[50];
 char password[50];
 char compa[50];
		archivo = fopen("registros.txt","r");
 		printf("\nUsuario:");
 		scanf("%s",usuario);
 		printf("\nPassword:");
		scanf("%s",password);
 		if (archivo != NULL){
 			while (feof(archivo) == 0){
 				fgets(cadena,80, archivo);
 				segmento=strtok(cadena,seg);
 				segmento2=strtok(NULL,seg);
 				if(strcmp(usuario,segmento)==0){
					 if(strcmp(password,segmento2)==0){
							printf("\nSesion iniciada.\n");
        	              	system("pause");
							system ("cls");
							sistema();
							  }
							  
						  }
					
		               }
            }
            printf ("\n\nUsuario o Password incorrectos.\n");
            menu();
            system("pause");
            system("cls");
             sesion();
         
return 0;
}

int registro(){
	 int edad=0;
	 char respuestadatos[2];   
	char correo[50], contra[20], confirmcontra[20], nickname[20],nombre[10],app[15],apm[15], numtarjeta[20];
	FILE *archivo;
	archivo = fopen("registros.txt","r");
	
            do{
              	printf("\nIngresa tu nombre: ");
                scanf("%s",nombre);
                printf("\nIngresa tu apellido paterno: ");
                scanf("%s",app);
                printf ("\nIngresa tu apellido materno: ");
                scanf("%s", apm);
                printf ("\nIngresa tu nombre de usuario: ");
                scanf ("%s" ,nickname);
                printf("\nIngresa tu correo electrónico: ");
                scanf ("%s", correo);
                printf("\nIngresa una contraseña:");
                scanf("%s",contra);  
				setbuf(stdin, NULL);        
                printf("\nConfirma tu contraseña:");
                scanf("%s",confirmcontra);
                setbuf(stdin, NULL); 
                while(strcmp(contra,confirmcontra)!=0){
                	printf("\nlas contraseñas no coinciden,vuelve a confirmar la contraseña.");
                	printf("\nConfirma tu contraseña:");
                	scanf("%s",confirmcontra);
    
				}
                printf("\nIngresa tu edad: ");
                scanf("%i",&edad);
                setbuf(stdin,NULL);
                if(archivo,edad<18){
                    printf("\nEres menor de edad, NO PUEDES REGISTRARTE");
                    return 1;
                }
                printf("\nIngresa tu numero de tarjeta. Esto únicamente se utilizará cómo método de pago: ");
                scanf("%s",numtarjeta);
                setbuf(stdin,NULL);
            
            system("cls");
            
            printf ("                                         \n\n                                                              Sus datos han sido capturados. ");
            
            printf("\n\nNombre: %s", nombre);
            printf("\n\nApellidos: %s %s", app, apm);
            printf("\n\nCorreo: %s", correo);
            printf ("\n\nUsuario: %s", nickname);
            printf("\n\nContraseña: %s", contra);
            printf("\n\nEdad: %i", edad);
            printf("\n\nNúmero de tarjeta: %s", numtarjeta);
            printf ("\n\n\n ¿Son correctos?: ");
            scanf ("\n%s", respuestadatos);
            setbuf(stdin,NULL);
        }
		while (strcmp (respuestadatos, "no")==0);
			archivo= fopen("registros.txt","a");
			fprintf(archivo,"%s:",nickname);
			fprintf (archivo,"%s:", contra);
            fprintf (archivo,"%s:", nombre);
            fprintf(archivo,"s:",app);
            fprintf (archivo,"%s:", apm);
            fprintf (archivo,"%s:", correo);
            fprintf(archivo,"%s:",numtarjeta);
            fprintf(archivo,"\n");
            fclose(archivo);  
			
			return 0; 
}


int sistema(){
	 char opcion=' ';
		printf ("\n\n           ================================= Bienvenido a Express Suol Fresh ===============================   ");  
		printf("\n\nOpciones disponibles: ");
				printf ("\n\n     A. Pedir bebida.\n     B.Ver todos los establecimientos.\n      C.Ver pedidos. \n     D.Cerrar sesión.\n");                
				scanf ("%s",&opcion);
				system ("cls");
			    switch (opcion){
			    	case ('a'):
			    		pedido();
			    		break;
			    	case ('A'):
			    		pedido();
			    		break;
			    	
			    	case ('b'):
			    		establecimientos();
			    		break;
			    	case ('B'):
			    		establecimientos();
			    		break;
			    		
			    	case ('c'):
			    	case ('C'):
			    	
			    	case ('d'):
			    		closeSesion();
			    		break;
			    	case ('D'):
			    	 	closeSesion();
			    	 	break;
			    	default:
			    		printf ("\n Opcion invalida Intentelo otra vez\n");
			    		intento2();
			    		break;
				}
				return 1;
	
	return 0;
}

int pedido(){
	char algomas[2];
    int opcion1;
    char algo[10];
	int imprimenombre(char gusto[]);
        FILE *archivo;
        char cadena[200];
        int contadorDeCadenas=0;
        char seg[]=":";
        char *segmento;
        char gusto[20]=" ";
        char minus='\0';
        
	    int i;
        archivo = fopen("bares2.txt","r");
        printf("\n\n BUSQUE LO QUE NECESITE Y ORDENE\n Al finalizar nuestro sistema le mostrara los establecimientos donde tiene su producto. \n");
        printf("\n LISTA DE RESTARUANTES PARTCIPANTES SELECCIONE DONDE ESTA LO QUE BUSCA  \n \n");
	printf(" 1)Alianza");
	printf(" 2)Oxxo");
	printf(" 3)7Eleven");
        printf("\n Ofrecemos:\nVino, Vodka, Brandy, Sake, Whisky, Cerveza, Tequila, Pulque, Ron, Fourloko, Kosako, Ginebra, Caña, Micheladas, Licor, Cocteles, Mezcal, Champan  \n:");
		for(i=0; gusto[i] != '\0'; ++i){
		gusto[i]= tolower(gusto[i]);
        if (archivo != NULL){
            while (feof(archivo) == 0) 
            {
                    fgets(cadena,200, archivo);
                    segmento=strtok(cadena,seg);
                    while((segmento=strtok(NULL,seg)) !=NULL){
                       	
        	             if(strcmp(gusto,segmento)==0){
        	             	printf("\n%s",segmento=strtok(cadena,seg),segmento=strtok(NULL,seg));
						 }
		               }
            }
        }
	}
	fclose(archivo);
		
	printf("\n \nTeclee el numero que corresponde al establecimiento donde se encuetra su producto.\n   Donde la quiere comprar:   ");
   scanf ("%d",&opcion1);
	system ("cls");
	switch (opcion1){
		case (1):
			alianza();
			break;
		case (2):
		 	oxxo();
		 	break;
		case (3):
			   eleven(); 		
				break;
		default :
			pedido();
			break;
	}	
	
system("cls");
      printf("\nEl COSTO TOTAL DE LA OPERACION ES: %d",costo);
	printf("\n CONFIRMA SU COMPRA? si o no \n");
	scanf ("%s",&algomas);
	  if(strcmp(algomas,"si")==0){
	  	tiempo();	
	  }
      if(strcmp(algomas,"no")==0){
      	sistema();
	  }
	tiempo();
system("pause");
return 0;
}

int establecimientos(){
	system("cls");
	int op=0;
	printf("Establecimientos participantes\n");
	printf(" 1) Alianza                    *Siempre tenemos lo que buscas*   \n");
	printf(" 2) Oxxo                       *Para todas tus reuniones*    \n");
	printf(" 3) 7 Eleven                   *Más cerca de ti*      \n");
	printf("Para ver las bebidas que ofrecen.\nSeleccione cualquiera tecleando el numero que corresponde\n");
    scanf("%i",&op);
    switch (op){
    	case (1):
    		printf("Alianza MENU\n -Vino\n -Vodka\n -Brandy\n -Sake\n -Whisky\n");
    		break;
    	case (2):
    		printf("Oxxo MUNU\n -Cerveza\n -Vodka\n -Tequila\n -Fourloko\n -Kosako\n");
    		break;
    	case (3):
    		printf("7 Eleven MENU\n -Cerveza\n -Ron\n -Ginebra\n -Kosako\n -Caña\n");
    		break;

	}
	op=0;
	printf(" Quiere ver otra otro Establecimiento \n 1) SI\n 2) NO\n");
	scanf("%i",&op);
	if(op==1){
		system("cls");
		establecimientos();
	} else{
		if(op==2){
			system("cls");
			sistema();
		}
	}
	return 0;
}

int closeSesion(){

	printf("Usted esta apunto de cerrar sesion\n");
	system("pause");
			    		system("cls");
						printf("Sesion cerrada\n GRACIAS POR SU PREFERENCIA\n");
						menu();
						system("pause");
	return 0;
}

int intento2(){
	sistema();
	return 0;
}

 int eleven(){
   char algomas[2];
   int menu7eleven=0, unidades=0, nopedidos=0;
   int renglon;
   
				 printf("\n\n               %s 7ELEVEN %s", SEPARADOR, SEPARADOR); 
				 printf("\n\n\n    Bebidas: ");	
				 printf("\n\n      Cervezas:                                                  Ron:");
				 printf("\n1.  Modelo oscura (2 sixpack, 355ml): $192                           5.  Solera 23 años Zacapa. Gran Reserva (750ml): $1090");
			     printf("\n2.  Dos Equis Ambar(6 botellas,355ml): $102                          6. Bacardi. Carta blanca superior (980ml): $180");
			     printf("\n3.  Bohemia Oscura(6 botellas, 355ml): $111                          7. Glorias de Cuba.Blanco (940ml) $165");
				 printf("\n4.  Indio Ambar(6 botellas, 355ml):    $96");
				 printf("\n\n      Kosako:                                                    Caña: ");
				 printf("\n8.  Morado Azul()2 lts:   $75                                       11.  Tonayan (960 ml): $25"); 
				 printf("\n9.  Guarana Pink(2 lts): $78                                        12.  Bronco (1 litro): $45");
				 printf("\n10. Citricos(2 lts):      $82                                       13.  Viejo añejo(1 litro) $74");
				 printf("\n                                                                    14.  Los Reyes.Añejo (940 ml): $85");
				 printf("\n\nSelecciona el número de tu bebida:  ");
				 scanf ("%i", &menu7eleven);
				 system ("cls");
				 switch (menu7eleven){    
					 case 1:
				 		unidades=0;
						 printf ("\n1. Modelo oscura (2 sixpack, 355ml): $192");
						 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						 suma=unidades*192;
				
					 break;
					 case 2:
			
				 		unidades=0;
						 printf ("\n2.  Dos Equis Ambar(6 botellas,355ml): $102");
					 	printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						 suma=unidades*102;
						 
	
					 break;
					 case 3:
				 		unidades=0;
						 printf ("\n3.  Bohemia Oscura(6 botellas, 355ml): $111");
						 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						suma=unidades*111;
						
					 break;
					 case 4:
				 		unidades=0;
					 	printf ("\n4.  Indio Ambar(6 botellas, 355ml):    $96");  
					 	printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						suma=unidades*96;
					 break;
					 case 5:
				 		unidades=0;
				     	printf ("\n5.  Solera 23 años Zacapa. Gran Reserva (750ml): $1090");
				     	printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						suma=unidades*1090;
						
				 	 break;
					 case 6:
			
				 		unidades=0;
					 	printf ("\n6. Bacardi. Carta blanca superior (980ml): $180");
				     	printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
					 	scanf ("%i", &unidades);
					 	suma=unidades*180;
						
					 break;
					 case 7:
					 
				 		unidades=0;	
				     	printf ("\n7. Glorias de Cuba.Blanco (940ml) $165");
				     	printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
					 	scanf ("%i", &unidades);
						suma=unidades*165;
					
					 break;
					 case 8:
					 	
				 		unidades=0;
					 	printf ("\n8.   Morado Azul()2 lts: $75");
					 	printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
					 	suma=unidades*75;
					 break;
					 case 9:
				 		unidades=0;
						 printf ("\n9.  Guarana Pink(2 lts): $78");
					 	printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						suma=unidades*78;
						
					 break;
					 case 10: 
				 		unidades=0;
					 	printf ("\n10. Citricos(2 lts:  %82");
						 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
					 	scanf ("%i", &unidades);
						suma=unidades*82;
					 break;
					 case 11:	
				 		unidades=0; 
					 	printf ("11.  Tonayan (960 ml): $25");
					 	printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
					 	scanf ("%i", &unidades);
					 	suma=unidades*25;
					break;
					 case 12: 
				 		unidades=0;
					 	printf ("12.  Bronco (1 litro): $45");
						 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
					 	scanf ("%i", &unidades);
						 suma=unidades*45;
					 break;
					 case 13:
				 		unidades=0;
					 	printf ("13.  Viejo añejo(1 litro) $74");
					 	printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
					 	scanf ("%i", &unidades);
					 	suma=unidades*74;
					 break;
					 case 14:
				 		unidades=0;
					 	printf ("14.  Los Reyes.Añejo (940 ml): $85");
					 	printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
					 	scanf ("%i", &unidades);
					 	suma=unidades*85;
					 break;
				}
				
			printf ("\n\n MONTO A PAGAR = $%i",suma);
			aux=suma;
		printf ("\n\n ¿Deseas algo más? Escribe (si) para volver al menú del establecimiento. Escribe no para continual la compra (no):   ");
		scanf ("%s",&algomas);
	  if(strcmp(algomas,"si")==0){
	  	costo=costo+aux;
	  	eleven();	
	  }
      if(strcmp(algomas,"no")==0){
      	costo=costo+aux;
	printf ("\n\n El totar a pagar es: %d", costo);
	  }
	return 0;
}

int alianza(){
	char algomas[2];
   int menuAlianza=0, unidades=0, nopedidos=0;
   int renglon;
    printf ("\n\n               %s Alianza %s", SEPARADOR, SEPARADOR); 
				 printf("\n\n\n    Bebidas: ");	
				 printf("\n\n      Vino:                                                           Brandy:");
				 printf("\n1.  Tinto Cuatro Soles Afrutado(750ml): $78                     4. Torres 10 (700ml): $229");
			     printf("\n2.  Rosado Lobito De Mar(750ml): $72                            5. Torres 5 (700ml): $171");
			     printf("\n3.  Blanco Espumoso(750ml): $105                                6. Azteca de oro (700ml): $173");
				 printf("\n                                                                7.Don Pedro (700ml): $120 ");
				 printf("\n\n      Vodka:                                                    Sake: ");
				 printf("\n8.  Grey Goose (750ml):   $500                                 11. Hattori Hanzo(375ml): $215"); 
				 printf("\n9.  Absolut(750 ml): $200                                      12.  Nami Junmai (720ml ): $500");
				 printf("\n10. Smirnoff tamarindo(750 ml):      $220                      13.  Sho Chiku Bai(750ml): $530");
				  printf("\n");
				 printf("\n                                     Whisky:");
				 printf("\n                                     14. Chivas Regal(750ml): $535      ");
				 printf("\n                                     15. Johnnie Walker Red Label (700ml): $310    ");
				 printf("\n                                     16. Buchanan´s De Luxe (750ml): $640           ");
				 printf("\n\nSelecciona el número de tu bebida:  ");
				 scanf ("%i", &menuAlianza);
				 system("cls");
				 switch (menuAlianza){
					 case 1:
					 	suma=0;
					 	unidades=0;
					 	printf ("\n1. Tinto Cuatro Soles Afrutado(750ml): $78 ");
					 	printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
					 	scanf ("%i", &unidades);
					 	suma=unidades*78;
					 break;		 
					 case 2:
					 	unidades=0;
					 	printf ("\n2.  Rosado Lobito De Mar(750ml): $72 ");
					 	printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
					 	scanf ("%i", &unidades);
					 	suma=unidades*72;
					 break;
					 
					 case 3:
						unidades=0;
					 	printf ("\n3.  Blanco Espumoso(750ml): $105 ");
					 	printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
					 	scanf ("%i", &unidades);
					 	suma=unidades*105;
					 break;
					 case 4:
				     	unidades=0;
					 	printf ("\n4.  Torres 10 (700ml): $229");  
					 	printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
					 	scanf ("%i", &unidades);
					 	suma=unidades*229;
					 break;
					 case 5:
					 	unidades=0;
				     	printf ("\n5.   Torres 5 (700ml): $171");
				     	printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
					 	scanf ("%i", &unidades);
					 	suma=unidades*171;
				 	 break;
					 case 6:
					 	unidades=0;
					 	printf ("\n6. Azteca de oro (700ml): $173");
				     	printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
					 	scanf ("%i", &unidades);
					 	suma=unidades*173;
					 break;
					 case 7:
					 	unidades=0;
				     	printf ("\n7. Don Pedro (700ml): $120");
				     	printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
					 	scanf ("%i", &unidades);
					 	suma=unidades*120;
					 break;
					 case 8:
					 	unidades=0;
					 	printf ("\n8.   Grey Goose (750ml):   $500  ");
					 	printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
					 	scanf ("%i", &unidades);
					 	suma=unidades*500;
					 break;
					 case 9:
					 	unidades=0;
					 	printf ("\n9.  Absolut(750 ml): $200 ");
					 	printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
					 	scanf ("%i", &unidades);
					 	suma=unidades*200;
					 break;
					 case 10:
					 	 unidades=0;
						 printf ("\n10. Smirnoff tamarindo(750 ml):      $220 ");
						 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
					 	scanf ("%i", &unidades);
					 	suma=unidades*220;
					 break;
					 case 11:
						 unidades=0;
						 printf ("11.  Hattori Hanzo(375ml): $215 ");
						 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						 suma=unidades*215;
					 break;
					 case 12:
						 unidades=0;
						 printf ("12.  Nami Junmai (720ml ): $500");
						 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						 suma=unidades*500;
					 break;
					 case 13:
						 unidades=0;
						 printf ("13.  Sho Chiku Bai(750ml): $530");
						 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						 suma=unidades*530;
					 break;
					case 14:
						 unidades=0;
					 	printf ("14.  Chivas Regal(750ml): $535 ");
						 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						 suma=unidades*535;
					 break;
					 case 15:
				    	 unidades=0;
						 printf ("15.  Johnnie Walker Red Label (700ml): $310");
						 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						 suma=unidades*310;
					 break;
					 
					 case 16:
						 unidades=0;
						 printf ("16.  Buchanan´s De Luxe (750ml): $640  ");
						 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						 suma=unidades*640;
					 break;
				     }
				       
			printf ("\n\n MONTO A PAGAR = $%i",suma);
			aux=suma;
			printf ("\n\n ¿Deseas algo más? Escribe (si) para volver al menú del establecimiento. Escribe no para continuar con la compra (no):   ");
			scanf ("%s",&algomas);
	  if(strcmp(algomas,"si")==0){
	  	costo=costo+aux;
	  	alianza();	
	  }
      if(strcmp(algomas,"no")==0){
      	costo=costo+aux;
	printf ("\n\n El totar a pagar es: %d", costo);
	  }
	return 0;
}

int oxxo(){
	char algomas[2];
   int menuOxxo=0, unidades=0, nopedidos=0;
   int renglon;
	
	printf ("\n\n               %s Oxxo %s", SEPARADOR, SEPARADOR); 
				 printf("\n\n\n    Bebidas: ");	
				 printf("\n\n      Cervezas:                                                  Tequila:");
				 printf("\n1.   Modelo oscura (2 sixpack, 355ml): $192                       5. Gran Centenario (950ml): $950");
			     printf("\n2.  Dos Equis Ambar(6 botellas,355ml): $102                     6. Jose Cuervo Tradicional(950ml): $240");
			     printf("\n3.  Bohemia Oscura(6 botellas, 355ml): $111                     7. Jose Cuervo Especial (990ml): $195");
				 printf("\n4.  Indio Ambar(6 botellas, 355ml):    $96                      8.Cristalino Añejo (700ml): $675 ");
				printf("\n");
				 printf("\n\n      Vodka:                                                    Fourloko: ");
				 printf("\n9.   Grey Goose (750ml):   $500                                 12.  Gold (475ml): $34"); 
				 printf("\n10.  Absolut(750 ml): $200                                  	   13.  Limon y fresa(475ml ): $32");
				 printf("\n11.  Smirnoff tamarindo(750 ml):      $220                      14.  sandia(475ml): $33");
				 printf("\n                                                                15.  Blue(475ml): $35");
				 printf("\n");
				 printf("\n                                         kosako:");
				 printf("\n                                       16. Morado Azul(2lts): $75       ");
				 printf("\n                                       17. Guarana Pink(2lts): $78       ");
				 printf("\n                                       18. Citricos(2lts): $82             ");
				 printf ("\n\nSelecciona el número de tu bebida:  ");
				 scanf ("%i", &menuOxxo);
				 system ("cls");
				 switch (menuOxxo){    
					 case 1:
						 unidades=0;
						 printf ("\n1. Modelo oscura (2 sixpack, 355ml): $192");
						 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						 suma=unidades*192;
					 break;
					 case 2:
						unidades=0;
						 printf ("\n2.  Dos Equis Ambar(6 botellas,355ml): $102");
						 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						 suma=unidades*102;
					 break;
					 case 3:
						 unidades=0;
						 printf ("\n3.  Bohemia Oscura(6 botellas, 355ml): $111");
						 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						 suma=unidades*111;
					 break;
					 case 4:
						 unidades=0;	
						 printf ("\n4.  Indio Ambar(6 botellas, 355ml):    $96");  
						 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						suma=unidades*96;
						 printf ("\n\n Tu total a pagar sería = $%i", suma);
					 break;
					 case 5:
						 unidades=0;
				     	printf ("\n5.   Gran Centenario (950ml): $950");
				    	 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						suma=unidades*950;
				 	 break;
					 case 6:
						 unidades=0;
						 printf ("\n6. Jose Cuervo Tradicional(950ml): $240");
				  	 	  printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						 suma=unidades*240;
					 break;
					 case 7:
		        	     unidades=0;
				  	   printf ("\n7. Jose Cuervo Especial (990ml): $195");
				 	    printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						suma=unidades*195;
					 break;
					 case 8:
						 unidades=0;
						 printf ("\n8.   Cristalino Añejo (700ml): $675 ");
						 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						 suma=unidades*675;
					 break;
					 case 9:
						 suma=0;
						 unidades=0;
						 printf ("\n9.  Grey Goose (750ml):   $500 ");
						 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						suma=unidades*500;
					 break;	 
					 case 10:
						 unidades=0;
						 printf ("\n10. Absolut(750 ml): $200");
						 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						 suma=unidades*200;
					 break;
					 case 11:
						unidades=0;
						 printf ("11.  Smirnoff tamarindo(750 ml):      $220  ");
						 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						 suma=unidades*220;
					break;
					 case 12:
						 unidades=0;
						 printf ("12.  Gold (475ml): $34");
						 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						 suma=unidades*34;
					 break;
					 case 13:
						 unidades=0;
						 printf ("13.  Limon y fresa(475ml ): $32");
						 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						 suma=unidades*32;
					 break;
					 case 14:
					 unidades=0;
					 printf ("14.  sandia(475ml): $33");
					 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
					 scanf ("%i", &unidades);
					 suma=unidades*33;
					 break;
					 case 15:
					 unidades=0;
					 printf ("15.  Blue(475ml): $35");
					 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
					 scanf ("%i", &unidades);
					 suma=unidades*35;
					 break;
					 case 16:
						 unidades=0;
						 printf ("16.  Morado Azul(2 lts): $75");
						 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
						 suma=unidades*75;
					 break;
					 case 17:
						 unidades=0;
							 printf ("17. Guarana Pink(2lts): $78");
							 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
							 scanf ("%i", &unidades);
						 suma=unidades*78;
					 break;			 
					 case 18:
						 unidades=0;
						 printf ("18.  Citricos(2lts): $82 ");
						 printf("\n\n ¿Cuántas unidades deseas?. Esribe el número de unidades: ");
						 scanf ("%i", &unidades);
								 suma=unidades*82;
					 break;
				     }
	printf ("\n\n MONTO A PAGAR = $%i",suma);
			aux=suma;
			printf ("\n\n ¿Deseas algo más? Escribe (si) para volver al menú del establecimiento. Escribe no para continuar con la compra (no):   ");
			scanf ("%s",&algomas);
	  if(strcmp(algomas,"si")==0){
	  	costo=costo+aux;
	  	oxxo();	
	  }
      if(strcmp(algomas,"no")==0){
      	costo=costo+aux;
	printf ("\n\n El totar a pagar es: %d", costo);
	  }
	return 0;
}

int tiempo(){
	int segundos=0, contadorAlarma=5;
	segundos=costo/10;

	printf("\n Tu paquete esta de Viaje Sonora una alarma cuando llegue tu paquete, espere :):\n ");
	for(segundos=segundos; segundos>=0; segundos--)
	{
		printf("%i ", segundos);
		Sleep(100);	

	}
	printf("\a");	//Hace un sonido de alarma. Un beep.
	
	for(contadorAlarma=5; contadorAlarma>=0; contadorAlarma--)
	{
		printf("\a");
		Sleep(1000);	
	}
	system("cls");
	  printf("\n\nTu paquete ya llego!!! :D sal a recogerlo,\n Gracias por su preferencia");
	  system("pause");
	  sistema();
	return 1;

}



