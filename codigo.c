#include<stdio.h>
#include<string.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include<time.h>

typedef struct{
	char nombre[100];
	float puntos;
}jugadores;
typedef struct{
	char azul[100];
	char rojo[100];
	float puntosrojo;
	float puntosazul;
	float puntotal;
}jugadores2;

void menu();
void partida1jugador();
void partida2jugadores();
void muerte_rojo(jugadores2 v[],clock_t comienzo);
void muerte_azul(jugadores2 v[],clock_t comienzo);
void puntuaciones2();
void calculodepuntos(jugadores v[],clock_t comienzo);
void calculodepuntos2(jugadores2 v[],clock_t comienzo);

int main(){
	setlocale(LC_ALL, "");
	int opcion,opcion2;
	int i=0;
	FILE *f;
	jugadores v[1000];
	
	printf("\tTe damos la bienvenida a púrpura, un scape room en el que no te faltará entretenimiento!!\n");
	
	do{
		menu();
		scanf("%d",&opcion);
		fflush(stdin);
	
		switch (opcion){
			case 1:
				
				do{
					printf("¿Cuantos jugadores desean jugar?¿1 o 2?\n");
					scanf("%d",&opcion);
					system("cls");
					 
					if(opcion==1){
						partida1jugador();
					
					}
					else if(opcion==2){
						partida2jugadores();
					}
					else if(opcion!=1 && opcion!=2){
						system("cls");
						printf("Te has equivocado de número, introdúzcalo de nuevo\n");
					
					}
					
				}while(opcion!=1 && opcion!=2);
				
				
				
				
				break;
			case 2:
				system("cls");
				printf("\n\n\t\tDesea ver las puntuaciones del modo un jugador (1) o dos jugadores (2) o volver al menú (3)\n");
				scanf("%d",&opcion2);
				system("cls");
				do{
					switch(opcion2){
						case 1:
							f=fopen("ranking.txt","r");
							if(f==NULL){
								printf("Error en la apertura del fichero\n");
								exit(-1);
							}
							while(fscanf(f,"%s %f",&v[i].nombre,&v[i].puntos)!=EOF){
								printf("%s   %f\n",v[i].nombre,v[i].puntos);
								i++;
							}
							fclose(f);
						break;
						case 2:
							puntuaciones2;
						break;
						case 3:
						break;
						default:
							system("cls");
							printf("Introduce una opción válida\n");
						break;
					}
				}while(opcion2<1 || opcion2>3);
				break;
			case 3:

				printf("Has abandonado el juego\n");
				return 0;
			default:
				system("cls");
				printf("Te has equivocado de caracter\n");
		}
	}while(opcion!=3);
	return 0;
}
void menu(){
	printf("\n\t\t\t MENÚ DE OPCIONES\n");
	printf("\t\t\t------------------\n");
	printf("\t1. Comenzar a jugar\n");
	printf("\t2. Ver las puntuaciones del juego\n");
	printf("\t3. Salir del juego\n");

}						
void partida1jugador(){
	setlocale(LC_ALL, "");
	int opcion_llave,opcion_ordenador,opcion,i,k,opcion_cama,opcion_fiera;
	char cadena[] = "purple";
	char rep[100], temporal[100];
	char pal;
	int longitud, j, inicial, acierto = 0, temp = 0, oportunidades = 5;
	int repetir = 0, win = 0;
	int tener_llave = 0;
	jugadores v[1000];
	int opcion_2;
	clock_t comienzo;
	int opcion_destino;
	int y = 0;
	FILE *f;
	jugadores aux;

	printf("Introduzca el nombre del usuario\n");
	scanf("%s",v[0].nombre);
	v[0].puntos=0;
	
	comienzo=clock();
	do{					
		printf("Despiertas. \nTratas con torpeza levantarte del duro suelo mientras haces el esfuerzo de recordar como has llegado donde sea que estes. \nParedes blancas, techo blanco, suelo blanco, todo blanco; a excepción de una puerta negra. \nRevisando entre tus pertenencias encuentras una llave plateada.");
		printf("\n¿ te arriegas a abrir la puerta ?");
		printf("\n1. SI");
		printf("\n2. NO\n:");
		scanf("%d", &opcion);
		system("cls");
		switch(opcion){
			case 1: 
				printf("Abres la puerta.\n\n");	
				v[0].puntos+=100;
			break;
			case 2: 
				printf("Aun así, la curiosidad te puede.\nAbres la puerta.\n\n");	
				v[0].puntos+=50;
			break;
			default: 
				system("cls");
				printf("Introduce una respuesta válida:\n");	
			break;
		}
	}while((opcion != 1) && (opcion != 2));						
	do{
		printf("\nEl lugar en el que te encuentras te incomoda.");
		printf("\nUn amplio salón de colores suaves con los muebles ordenados.");
		printf("\nEl paraíso de cualquier minimalista de no ser por el gran retrato que cubre la pared.");
		printf("\nEl rostro te resulta familiar.");
		printf("\nEres tú.");						
		printf("\nTe acercas a la puerta para salir del salón, pero está cerrada.");
		printf("\nExploras la habitación en busqueda de la llave mientras el cuadro vigila tus pasos con su mirada.");
		printf("\nTienes que salir de ahí");
		printf("\n¿ Qué haces ?.");
		printf("\n1. Apuñalar el cuadro");						
		printf("\n2. Mover el cuadro");
		printf("\n3. Tapar los ojos del cuadro\n:");
		scanf("%d", &opcion);
		system("cls");
		switch(opcion){
			case 1:
				printf("Te acercas a tu versión pintada y con brusquedad introduces la filosa llave de la habitación blanca.\nUn rugoso corte produce un ruido resquebradijo que resuena en el salón. \nLa pintura sangra.\nY tu junto a ella. \nCaes de rodillas, miras por última vez el cuadro, que aún roto te mira sonriendo. ");
				printf("\nHas perdido");
				calculodepuntos(v,comienzo);
				exit (-1); 
			break;
											
			case 2:
				printf("Te acercas a tu versión pintada y con cuidado tratas de moverla. \nEl cuadro es más ligero de lo que parecería. \nConsigues levantarlo y apoyarlo bocabajo. \nUn chasquido se escucha de fondo. \nLa puerta ahora está abierta. \nSales del hermoso salón.\n");
				v[0].puntos+=100;
			break;
											
			case 3:
				printf("Te acercas a tu versión pintada. \nTu propia mirada indaga en tu ser. \nEs como verse en un espejo. \nTapas esos ojos que tanto te intimidan. \nUn chasquido se escucha de fondo. \nLa puerta ahora está abierta. \nSales del hermoso salón.\n");
				v[0].puntos+=100;
			break;
											
			default: 
				system("cls");
				printf("Introduce una respuesta válida: ");	
				v[0].puntos=v[0].puntos-10;
			break;
		}
	}while(opcion != 2 && opcion != 3);
	printf("\n\n");
	printf("\nUn pasillo frente a tí.");
	printf("\nLa luz titilante alumbra el fondo del pasillo donde se encuentra un ascensor.");
	printf("\nCaminas lento fijandote en las puertas de las habitaciones.");
	printf("\n130	131		132		133		134		135		136		137		138		139");						
	printf("\nLlegas al ascensor, pero requiere introducir el número del piso en el que te encuentras.");
	printf("\nNúmero del piso:");
	scanf("%d", &opcion);
	system("cls");
	if(opcion == 13){
		v[0].puntos+=100;
		do{										
			printf("\nAparece el ascensor.");
			printf("\nEntras en la angosta cabina.");
			printf("\nRevisas el numero de pisos, del -2 al 13");
			printf("\nSelecciona el piso al que te quieres dirigir: ");
			scanf("%d", &opcion);
			system("cls");
			if(opcion<-2 || opcion>13){
				printf("Introduce una opción válida\n");
			}
		}while(opcion<-2 || opcion>13);
		printf("\nEl ascensor empieza a bajar, pero a medio camino se detiene.");
		printf("\nNo señala el piso en el que se encuentra.");
		printf("\nVuelves a estar en un pasillo, a diferencia del anterior que las puertas se enumeran por letras.");
		printf("\nEntras en la única puerta que está abierta.");	
	}else{
		v[0].puntos+=20;	
		printf("\nEl código era incorrecto.");
		printf("\nForcejeas las puertas del ascensor y tras mucho esfuerzo consigues abrirlas.");
		printf("\nBajas por los cables de sujección, con cuidado de no caer.");
		printf("\nEncuentras una abertura y pasas atraves de ella.");
		printf("\nVuelves a estar en un pasillo, a diferencia del anterior que las puertas se enumeran por letras.");
		printf("\nEntras en la única puerta que está abierta.");
										
	}
	do{
		printf("\n\n\nNo ves nada.");
		printf("\nNo sabes donde has entrado.");
		printf("\nNi un ápice de luz que te diese una pista de como avanzar.");
		printf("\nTanteando la pared encuentras un interruptor.");
		printf("\nLa luz te ciega brevemente.");
		printf("\nEn frente de tí, cinco personas se encuentran inmóviles y tras ellas una puerta.");
		printf("\nInspecccionas las figuras que se encuentran ante tí.");
		printf("\nSon esculturas de cera, aunque demacradas por el paso del tiempo.");						
		printf("\nUn rey, un caballero, un clérigo, un campesino y un esclavo.");
		printf("\nTodas te extienden una mano y en ella un objeto.");
		printf("\n1. Tomas la corona del rey");
		printf("\n2. Tomas la espada del caballero");
		printf("\n3. Tomas el libro del clérigo");
		printf("\n4. Tomas el rastrillo del campesino");	
		printf("\n5. Tomas las cadenas del esclavo\n");	
		scanf("%d",&opcion);
		system("cls");								
		switch(opcion){
			case 1:
				printf("La corona entre tus manos reluce. \nEscuchas un crujido. \nLa estatua del caballero cobra vida y blandiendo su espada te atraviesa. \nNo deberías haber tomado la corona.");
				printf("\nHas perdido");
				calculodepuntos(v,comienzo);
				exit (-1);
			break;											
			case 2:
				printf("La espada no cede. \nEscuchas un crujido. \nLa estatua del caballero cobra vida y blandiendo su espada te atraviesa. \nNo deberías haber tomado la espada.");
				printf("\nHas perdido");
				calculodepuntos(v, comienzo);
				exit (-1);
			break;
			case 3:
				printf("El libro que sostenía la estatua es real. \nLo abres. \nVacío. \nHojas en blanco. \nUn fuerte golpe se escucha. \nLa puerta está abierta. \nAvanzas sin saber que será de ti.");
				v[0].puntos+=100;
			break;										
			case 4:
				printf("El rastrillo pesa más de lo que parecía. \nUn fuerte golpe se escucha. \nLa puerta está abierta. \nAvanzas sin saber que será de ti.");
				v[0].puntos+=100;
			break;
			case 5:
				printf("Las cadenas ceden. \nEl esclavo ahora tiene una sonrisa en el rostro.\nUn fuerte golpe se escucha. \nLa puerta está abierta. \nAvanzas sin saber que será de ti.");
				v[0].puntos+=100;
			break;
			default: 
				system("cls");
				printf("introduce una respuesta válida:\n");
				v[0].puntos=v[0].puntos-10;	
			break;	
		}
	}while((opcion< 1) || (opcion > 5));
	do{
		printf("\nUna espesa niebla te nubla la vista.");
		printf("\nCaminas sin rumbo.");
		printf("\nHallas un claro bajo un cielo gris.");
		printf("\nFrente a tí se encuentra una pequeña edificación.");
		printf("\nEs una horca.");
		printf("\nEn ella, una inscripción vacía de 6 espacios y un teclado interactivo.");
		printf("\nSe trata de un macabro juego del ahorcado.");
		printf("\n¿ Qué haces ?");
		printf("\n1. Jugar");						
		printf("\n2. Rendirte\n:");
		scanf("%d",&opcion);							
		switch(opcion){
			case 1:
				longitud = 0;
				inicial = 0;
				j = 0;
				rep[0] = ' ';
				rep[1] = '\0';
				do{
					system("cls");
					temp=0;
													
					if(inicial == 0) {
						for(i=0;i<strlen(cadena);i++) {
							if(cadena[i] == ' ') {
								temporal[i] = ' ';
								longitud++;
							}
							else{
								temporal[i] = '_';       
								longitud++;
							}
						}
					}
					inicial = 1;
					temporal[longitud] = '\0';
					for(i=0;i<strlen(rep);i++){
						if(rep[i] == pal) {
							repetir = 1;
							break;
						}
						else {
							repetir = 0;
						}
					}
												
					if(repetir == 0) {
						for(i=0;i<strlen(cadena);i++) {
							if(cadena[i] == pal) {
								temporal[i] = pal;
								acierto++;
								temp=1;
							}
						}
					}
													
					if(repetir == 0) {
						if(temp == 0) {
							oportunidades = oportunidades - 1;
						}
					}else {
						printf("Ya has introducido esta letra");
						printf("\n\n");
					}
					printf("\n");
					for(i=0;i<strlen(temporal);i++) {
						printf(" %c ",temporal[i]);
					}
					printf("\n");
					if(strcmp(cadena,temporal) == 0) {
						win = 1;
						break;
					}
					printf("\nLetras Acertadas: %d \n",acierto);
					printf("Oportunidades Restantes: %d \n",oportunidades);
					rep[j] = pal;
					j++;
					if (oportunidades==0){
						break;
					}
					printf("Introduzca una letra:");
					scanf("\n%c",&pal);
				}while(oportunidades != 0);
				if(win){
					v[0].puntos+=1000;
					printf("\n\nLa niebla se despeja. \nFrente a tí el patíbulo se derrumba, permitiendo ver que tras él se encontraba un puerta abierta. \nPasa a través de ella.");
				}else{
					printf("\n\nHas agotado tus intentos. \n La cuerda del patíbulo cobra vida y se lanza a tu garganta. \nEs inútil resistirse, fallaste en el ahorcado.");
					printf("\n Has perdido.");
					calculodepuntos(v,comienzo);
					exit (-1);
				}
				printf("\n\n");
			break;
			case 2:
				printf("\nTe subes al patíbulo. \nLa cuerda huele a putrefacto. \nPero eso ya no será una preocupación. \nAjustas la cuerda al grosor de tu cuello. \nDos pasos y una ligera caída. \nTe has rendido.");
				exit (-1);
			break;	
											
			default: 
				system("cls");
				printf("introduce una respuesta válida:\n");
				v[0].puntos=v[0].puntos-10;		
			break;
		}
									 
	}while((opcion != 1) && (opcion != 5));
	do{
		printf("\nUna habitación acogedora.");
		printf("\nFrente a tí un espejo en el que se refleja la habitación.");
		printf("\nLo mismo si sales por el espejo, sales de la habitación.");
		printf("\nEL espejo está cerrado por un candado.\n");
		printf("\nBuscas una llave.");
		printf("\n1. Revisas la estantería");
		printf("\n2. Revisas el armario");
		printf("\n3. Revisas el escritorio");
		printf("\n4. Dejar de buscar\n:");
		scanf("%d",&opcion);								
		switch(opcion){
			case 1:
				do{
					printf("\n1. Revisar estante 1");
					printf("\n2. Revisar estante 2");
					printf("\n3. Revisar estante 3");
					printf("\n4. Dejar de buscar en la estantería\n:");
					scanf("%d",&opcion_llave);
					system("cls");
					switch(opcion_llave){
						case 1:		
							printf("Estante vacío.");
							v[0].puntos=v[0].puntos-5;	
						break;
						case 2:		
							printf("Estante vacío.");
							v[0].puntos=v[0].puntos-5;		
						break;
						case 3:		
							printf("Estante vacío.");
							v[0].puntos=v[0].puntos-5;		
						break;	
						case 4:
						break;
						default: 
							system("cls");
							printf("Introduce una respuesta válida: ");	
							v[0].puntos=v[0].puntos-10;	
						break;
					}
				}while(opcion_llave != 4);
			break;
			case 2:
				do{
					printf("\n1. Revisar armario izquierdo");
					printf("\n2. Revisar armario derecho");
					printf("\n3. Dejar de buscar en el armario\n:");
					scanf("%d",&opcion_llave);
					system("cls");
					switch(opcion_llave){
						case 1:		
							printf("Se encuentra vacío.");	
							v[0].puntos=v[0].puntos-5;	
						break;
						case 2:		
							printf("Se encuentra vacío.");
							v[0].puntos=v[0].puntos-5;		
						break;
						case 3:		
						break;	
						default: 
							system("cls");
							printf("Introduce una respuesta válida: ");	
							v[0].puntos=v[0].puntos-10;	
						break;
					}
				}while(opcion_llave != 3);
			break;
			case 3:
				do{
					printf("\n1. Revisar cajón del escritorio");
					printf("\n2. Dejar de buscar en el escritorio\n:");
					scanf("%d",&opcion_llave);
					system("cls");
					switch(opcion_llave){
						case 1:		
							printf("Hay una llave.");	
							tener_llave++; 	
							v[0].puntos+=300;	
						break;
						case 2:
						break;
						default: 
							system("cls");
							printf("Introduce una respuesta válida:\n");	
							v[0].puntos=v[0].puntos-10;	
						break;
					}
				}while(opcion_llave != 2 && opcion_llave != 1);
			break;	
			default:
				system("cls"); 
				printf("Introduce una respuesta válida:\n");	
				v[0].puntos=v[0].puntos-10;	
			break;
		} 
	}while(opcion != 4 && opcion_llave!=1);
	if(tener_llave != 0){
		printf("Abres el candado. \nPasas a través del espejo, sin saber que te espera más adelante. \n\n");
	}else{
		printf("No encuentras la llave. \nVes la desesperación en tu reflejo. \nPasarás hasta el último de tus días en esa habitación.");
		printf("\nHas perdido.");
		calculodepuntos(v,comienzo);
		exit (-1);
	}
	do{
		printf("\nEntras en una habitación.");
		printf("\nUn rugido te avisa que no te acerques.");
		printf("\nUna bestia tumbada en su propia sangre impide que llegues a la puerta abierta del otro lado de la habitación.");
		printf("\nTrata de moverse, pero más sangre brota de su estómago abierto.");
		printf("\n¿Qué haces?.");
		printf("\n1.Ignoras a la fiera");
		printf("\n2.Socorres a la fiera");
		printf("\n3.Matas a la fiera\n:");
		scanf("%d",&opcion_fiera);
		system("cls");
		switch(opcion_fiera){
			case 1:		
				printf("Pasas a su lado sin prestar caso a la fiera.\nEn sus jadeos se escapan sus últimos alientos de vida.");
				printf("\nLlegas a la puerta, pero un zarpazo te impide avanzar.\nTratas de escapar, pero la bestia herida te lo impide.");	
				printf("\nSerás su última cena.");
				printf("\nHas perdido.");
				calculodepuntos(v, comienzo);
				exit (-1);
			break;
			case 2:		
				printf("Te acercas para ayudar a la fiera.\nEn sus jadeos se escapan sus últimos alientos de vida.");
				printf("\nUsando tu camiseta como vendas consigues detener su sangrado.\nLa fiera te agradece la ayuda mediante un zarpazo.");	
				printf("\nTratas de escapar, pero la bestia herida te lo impide.\nSerás su cena.");
				printf("\nHas perdido.");
				calculodepuntos(v,comienzo);
				exit (-1);
			break;
			case 3:		
				printf("Te acercas con cuidado a la fiera.\nEn sus jadeos se escapan sus últimos alientos de vida.");
				printf("\nEmpuñas la llave de la habitacion blanca y con firmeza la hundes en el cráneo de la bestia.");	
				printf("\nAcabas con su sufrimiento.\nQue en paz descanse.");
				printf("\nAtraviesas la puerta.");
				v[0].puntos+=333;	
			break;
			default: 
				system("cls");
				printf("Introduce una respuesta válida:\n"); 
				v[0].puntos=v[0].puntos-10;	
			break;
		}
	}while((opcion_fiera < 1)||(opcion_fiera > 3));

	do{
		printf("\nOtro pasillo.");
		printf("\nNo señala el piso en el que te encuentras.");
		printf("\nHas atravesado por tantas habitaciones y no hallas ninguna pista ni de donde estás ni de como escapar.");
		printf("\nTendrás que buscar una solución diferente.");
		printf("\nUna puerta abierta.");
		printf("\nEntras y revisas la nueva habitación.");
		printf("\nUna cama.");
		printf("\n1.Descansar en la cama");
		printf("\n2.Revisar la cama\n");
		scanf("%d",&opcion_cama);
		switch(opcion_cama){
			system("cls");
			case 1:		
				printf("\nDespués de tantas locuras tomas un más que merecido descanso.");
				printf("\nCierras los ojos.");
				printf("\nY no los vuelves a abrir.");
				printf("\nHas perdido.");
				calculodepuntos( v, comienzo);
				exit (-1);
			break;
		case 2:
			v[0].puntos+=170;			
		break;
		default: 
			system("cls");
			printf("introduce una respuesta válida: "); 
			v[0].puntos=v[0].puntos-10;	
		break;
		}
	}while((opcion_cama != 1) && (opcion_cama != 2));
	
	
	printf("\nTan normal que resulta extraño.");
	printf("\nInspeccionas la cama.");
	printf("\nAl moverla descubres una rejilla del conducto de ventilación.");
	printf("\nEs lo suficientemente grande como para que puedas pasar por ella.");
	printf("\nUn gas morado empieza a salir por la rejilla.");
	printf("\nSin pensarlo, aguantas la respiración.");
	printf("\nQuitas la rejilla y comienzas a atravesar el conducto.");
	printf("\nGateas por el laberinto metálico mientras evitas inhalar el gas.");
	printf("\nDecide el camino.");
	do{
		do{
			printf("\n1.Seguir recto");
			printf("\n2.Girar a la izquierda");
			printf("\n3.Girar a la derecha\n:");
			scanf("%d", &opcion_destino);
			system("cls");
			switch(opcion_destino){
				case 1:		y++;	break;
				case 2:		y++;	break;
				case 3:		y++;	break;
				default: 
					system("cls");
					printf("Introduce una respuesta válida:\n"); 
					v[0].puntos=v[0].puntos-25;	
				break;
			}
		}while((opcion_destino != 1) && (opcion_destino != 2) && (opcion_destino != 3));
	}while(y != 5);
	do{
		printf("\nCaes por una rejilla.");
		printf("\nAlzas la vista.");
		printf("\nUna sala de monitores.");
		printf("\nTe acercas al ordenador principal.");
		printf("\nEstá apagado.");
		printf("\n1.Encender el ordenador");
		printf("\n2.Ignorar el ordenador\n");
		scanf("%d",&opcion_ordenador);
		switch(opcion_ordenador){
		case 1:		
			printf("Varios archivos.");
			printf("\nEn ellos están los datos de todas las habitaciones por las que has pasado y de aquellas en las que por suerte no has entrado.");
			printf("\nLas pruebas, las decisiones, los posibles resultados ...");
			printf("\nEntre todos los documentos destaca el experimento 74.");
			printf("\nTras un fallo en los controles de dicho experimento, tanto los sujetos como los experimentadores fallecieron.");
			printf("\nTú eras uno de los sujetos del experimento.");
			printf("\nPero el centro de P.U.R.P.L.E siguió en funcionamiento.");
		break;
		case 2:
			system("cls");	
		break;
		default: 
			system("cls");
			printf("Introduce una respuesta válida:\n"); 
			v[0].puntos=v[0].puntos-15;	
		break;
	}
	}while((opcion_ordenador != 1) && (opcion_ordenador != 2));
	do{
		printf("\n\nEn la habitación hay una mesa con un mapa.");
		printf("\nLa salida está delante de tí.");
		printf("\nLa verdadera salida está delante de tí.");
		printf("\nUna puerta negra.");
		printf("\nEn tu mano la llave de la habitación blanca");
		printf("\n¿ te arriegas a abrir la puerta ?");
		printf("\n1. SI");
		printf("\n2. NO\n");
		scanf("%d", &opcion_2);
		system("cls");
		switch(opcion_2){
			case 1: 	
				printf("Abres la puerta.\nHas ganado.");		
				v[0].puntos+=1500;	
			break;
			case 2: 	
				printf("De igual forma abres la puerta.\nHas ganado.");	
				v[0].puntos=v[0].puntos+50;	
			break;
			default: 	
				printf("Introduce una respuesta válida:\n");	
			break;
		}
	}while((opcion_2 != 1) && (opcion_2 != 2));		
	v[0].puntos=v[0].puntos-0.4*(clock()-comienzo)/(double)CLOCKS_PER_SEC;
	f=fopen("ranking.txt","r");
	if(f==NULL){
		printf("Error en la apertura del fichero\n");
		exit(-1);
	}
	while(fscanf(f,"%s %f",&v[i].nombre,&v[i].puntos)!=EOF){
		i++;
	}
	fclose(f);
	f=fopen("ranking.txt","w");
	for(j=0;j<i-2;j++){
		for(k=j+1;k<i;k++){
			if(v[j].puntos < v[k].puntos){
				aux= v[j];
				v[j] = v[k];
				v[k] = aux;
			}
		}
	}
	for(j=0;j<i;j++){
		fprintf(f,"%s %f\n",v[0].nombre,v[0].puntos);
	}
}
void partida2jugadores(){
	system("cls");
	int rojo_boton_1;
	int azul_boton_1;
	jugadores2 v[1000];
	clock_t comienzo;
	int azul_palanca_agua;
	int azul_palanca_agua_2;
	int azul_activar_palanca;
		int rojo_palanca_gas;
	int rojo_palanca_gas_2;
	int rojo_activar_palanca;
	int palanca_2 = 0;
	int palanca = 0;
	
	
	printf("Introduzca el nombre del jugador rojo\n");
	scanf("%s",v[0].rojo);
	printf("Introduce el nombre del jugador azul\n");
	scanf("%s",v[0].azul);
	v[0].puntosazul=0;
	v[0].puntosrojo=0;
	system("cls");
	comienzo=clock();
	printf("\n\nSe escucha una voz robótica");
	printf("\n- Intento número 69.");
	printf("\n- Ambos sujetos despiertan.");
	printf("\n- Reaccionan igual a los anteriores pacientes.");
	printf("\n- Elevados niveles de adrenalina generada por sus cuerpos a causa de la inesperada situación.");
	printf("\n- El experimento toma comienzo.");

	do{
		printf("\n- JUGADOR ROJO aprieta el botón rojo que se encuentra en frente de tí.");
		printf("\n1. Apretar botón");
		printf("\n2. No apretar botón\n:");
		scanf("%d", &rojo_boton_1);
		system("cls");
		switch(rojo_boton_1){
			case 1: 
				v[0].puntosrojo+=100;
			break;
			case 2: 
				printf("\n- Por favor JUGADOR ROJO apriete el botón:");
			break;
			default:
				system("cls");	
				printf("Introduce una respuesta válida:\n"); 
				v[0].puntosrojo=v[0].puntosrojo-10;
			break;
		}
	}while((rojo_boton_1 != 1));

	do{
		printf("- JUGADOR AZUL aprieta el botón azul que se encuentra en frente de tí.");
		printf("\n1. Apretar botón");
		printf("\n2. No apretar botón\n:");
		scanf("%d", &azul_boton_1);
		system("cls");
		switch(azul_boton_1){
			case 1:
				v[0].puntosazul+=100; 
			break;
			case 2: 
				printf("\n- Por favor JUGADOR AZUL apriete el botón:");
			break;
			default:	
				
				printf("introduce una respuesta válida:\n "); 
				system("cls");
				v[0].puntosazul=v[0].puntosazul-10;
			break;
		}
	}while((azul_boton_1 != 1));

	
	printf("\n- Ambos sujetos han pasado la prueba básica.");
	printf("\n- Avanzan a la habitación principal.");
	printf("\nUn gran salón, dividido en 2 por una gran mampara.");
	printf("\nEn cada lado, un individuo.");
	printf("\nNinguno de los 2 sabe que hace allí.");
	printf("nUna puerta roja y otra azul.");
	printf("\n- Tendrán que colaborar para poder superar principal\n\n");

	printf("\nUn leve pitido resuena en las habitaciones");
	printf("\nLa habitación del JUGADOR ROJO comienza a llenarse de agua");
	printf("\nEl JUGADOR AZUL revisa su habitación alguna forma de ayudar al JUGADOR ROJO");
	do{
		printf("\n1. Revisas la estantería");
		printf("\n2. Revisas las paredes");	
		printf("\n3. Dejar de buscar\n");
		scanf("%d", &azul_palanca_agua);
		system("cls");
		switch(azul_palanca_agua){
			case 1:
				do{
					printf("1. Revisar estante 1");
					printf("\n2. Revisar estante 2");
					printf("\n3. Dejar de buscar en la estantería\n");
					scanf("%d", &azul_palanca_agua_2);
					system("cls");
					switch(azul_palanca_agua_2){
						case 1:	
							printf("Hay un libro de astronomía.");	
							printf("\nVuelves a revisar estanterías:\n:");
							v[0].puntosazul=v[0].puntosazul-5;
						break;
						case 2:	
							printf("No hay nada.");	
							printf("\nVuelves a revisar estanterías:\n");
							v[0].puntosazul=v[0].puntosazul-5;
						break;
						case 3: break;
						default:	
							system("cls");
							printf("introduce una respuesta válida:\n"); 
							v[0].puntosazul=v[0].puntosazul-10; 
						break;
					}
					
				}while(azul_palanca_agua_2 != 3);
				break;
			case 2:
				do{
					printf("1. Revisar pared norte");
					printf("\n2. Revisar pared sur");
					printf("\n3. Revisar pared izquierda");
					printf("\n4. Revisar mampara");
					printf("\n5. Dejar de buscar en las paredes\n");
					scanf("%d", &azul_palanca_agua_2);
					system("cls");
					switch(azul_palanca_agua_2){
						case 1:	
							printf("Un poster del sistema solar.");	
							printf("\nVuelves a revisar paredes:\n");	
							 v[0].puntosazul=v[0].puntosazul-5;
						break;
						case 2:	
							printf("No hay nada.");	
							printf("\nVuelves a revisar paredes:\n"); 
							v[0].puntosazul=v[0].puntosazul-5;	
						break;
						case 3:	
							printf("Hay una palanca. ¿La accionas?");
							printf("\n1. Accionar la palanca");
							printf("\n2. No accionar la palanca\n");
							do{
								scanf("%d", &azul_activar_palanca);
								system("cls");
								switch(azul_activar_palanca){
									case 1: 
										printf("Palanca activada"); 
										palanca=1; 
									
										v[0].puntosazul+=100;
									break;
									case 2: 
										printf("Activa la palanca\n");
										v[0].puntosazul=v[0].puntosazul-20;	
									break;
									default:	
										system("cls");
										printf("introduce una respuesta válida:\n"); 
										v[0].puntosazul=v[0].puntosazul-10;
									break;
								}
							}while(azul_activar_palanca!=1);
						break;
						case 4:	
							printf("El JUGADOR ROJO se está ahogando.");	
							printf("\nVuelves a revisar paredes:\n");
							v[0].puntosazul=v[0].puntosazul-5;
						break;
						case 5: break;
						default:
							system("cls");	
							printf("introduce una respuesta válida:\n");	 
							v[0].puntosazul=v[0].puntosazul-10;
						break;
					}
				}while(azul_palanca_agua_2 != 5||palanca!=1);
			break;
			case 3: break;
			default:
				system("cls");	
				printf("Introduce una respuesta válida:\n"); 
				v[0].puntosazul=v[0].puntosazul-10;
			break; 
		}
	}while(azul_palanca_agua!= 3);
	if(palanca == 1){
		printf("El nivel del agua comienza a disminuir en la habitación del JUGADOR ROJO.");
		printf("\nEl JUGADOR ROJO ha sobrevivido.");
	}else{
		printf("El agua llena por completo la habitación del JUGADOR ROJO.");
		printf("\nEl JUGADOR ROJO sumergido bajo el agua no se mueve.");
		printf("\nJUGADOR ROJO ha perdido.");
		muerte_rojo(v,comienzo);
	}

	printf("\n\n\nNuevamente resuena el molesto pitido.");
	printf("\nEn la habitación del JUGADOR AZUL comienza a enfriarse.");
	printf("\nLos conductos de ventilación empiezan a emitir un gas morado.");
	printf("\nEl JUGADOR ROJO revisa su habitación alguna forma de ayudar al JUGADOR AZUL.");
	do{
		printf("\n1. Revisas el armario");
		printf("\n2. Revisas las paredes");	
		printf("\n3. Dejar de buscar\n:");
		scanf("%d", &rojo_palanca_gas);
		switch(rojo_palanca_gas){
			case 1:
				printf("1. Revisar armario 1");
				printf("\n2. Revisar armario 2");
				printf("\n3. Dejar de buscar en el armario\n:");
				do{
					scanf("%d", &rojo_palanca_gas_2);
					switch(rojo_palanca_gas_2){
						case 1:	
							printf("No hay nada.");	
							printf("\nVuelves a revisar en el armario:\n");
							v[0].puntosrojo=v[0].puntosrojo-5;

						break;
						case 2:	
							printf("Unas toallas. Mojadas");	
							printf("\nVuelves a revisar en el armario:\n");
							v[0].puntosrojo=v[0].puntosrojo-5;
						break;
						case 3: break;
						default:
							system("cls");	
							printf("introduce una respuesta válida:\n ");  
							v[0].puntosrojo=v[0].puntosrojo-10;
						break;
					}
					
				}while(rojo_palanca_gas_2 != 3);
				break;
			case 2:
				do{
					printf("1. Revisar pared norte");
					printf("\n2. Revisar pared derecha");
					printf("\n3. Revisar pared sur");
					printf("\n4. Revisar mampara");
					printf("\n5. Dejar de buscar en las paredes\n");
					scanf("%d", &rojo_palanca_gas_2);
					system("cls");
					switch(rojo_palanca_gas_2){
						case 1:
							printf("No hay nada.");	
							printf("\nVuelves a revisar paredes:\n");
							v[0].puntosrojo=v[0].puntosrojo-5;
						break;
						case 2:	
							printf("Unas fotos colgadas pero empapadas.");	
							printf("\nVuelves a revisar paredes:\n"); 
							v[0].puntosrojo=v[0].puntosrojo-5;
						break;
						case 3:	

							do{
								printf("Hay 3 palancas.");
								printf("\nGris, negra y blanca.");
								printf("\n1. Accionar la palanca gris");
								printf("\n2. Accionar la palanca blanca");
								printf("\n3. Accionar la palanca negra");
								printf("\n4. Dejar las palancas\n");
								scanf("%d", &rojo_activar_palanca);
								switch(rojo_activar_palanca){
									case 1: 
										printf("Palanca activada"); 
										palanca_2++; 
										printf("\nVuelves a revisar la pared:");
										v[0].puntosrojo+=33;
									break;
									case 2: 
										printf("Palanca activada"); 
										palanca_2++; 
										printf("\nVuelves a revisar la pared:");
										v[0].puntosrojo+=33;
									break;
									case 3: 
										printf("Palanca activada"); 
										palanca_2++; 
										printf("\nVuelves a revisar la pared:");
										v[0].puntosrojo+=34;
									break;
									case 4: 
										printf("Vuelves a revisar entre todas las paredes:");	
									break;
									default:	
										system("cls");
										printf("introduce una respuesta válida: "); 
										v[0].puntosrojo=v[0].puntosrojo-10;
									break;
								}
							}while((rojo_activar_palanca != 4));
						break;
						case 4:	
							printf("El JUGADOR AZUL está desmayado en el suelo.");	
							printf("\nVuelves a revisar paredes:\n");	
							v[0].puntosrojo=v[0].puntosrojo-5;
						break;
						case 5: break;
						default:	
							system("cls");
							printf("introduce una respuesta válida:\n ");	 
							v[0].puntosrojo=v[0].puntosrojo-10;
						break;
					}
				}while(rojo_palanca_gas_2 != 5);
			break;
			case 3: break;
			default:	
				system("cls");
				printf("introduce una respuesta válida: "); 
			break; 
		}
	}while(rojo_palanca_gas!= 3);
	
	if(palanca_2 == 3){
		printf("La temperatura se reestablece en la habitación del JUGADOR AZUL.");
		printf("\nEl JUGADOR AZUL ha sobrevivido.");
	}else{
		printf("Una niebla morada nubla la habitación del JUGADOR AZUL.");
		printf("\nEl JUGADOR AZUL no da señales de vida.");
		printf("\nJUGADOR AZUL ha perdido.");
		muerte_azul(v,comienzo);
	}
	//
	//	FINAL MODO MULTIJUGADOR
	//
	int opcion_arma;
	int opcion_arma_2;
	printf("\nLas puertas por fin se abren.");
	printf("\nSois libres.");
	printf("\nCruzais cada uno vuestra respectiva puerta.");
	printf("\nUna habitación enteramente blanca en común para ambos.");
	printf("\nYa no os separa una mampara.");
	printf("Una puerta negra al fondo y, en medio, una mesa con 2 cajas.");
	printf("\n- Ambos sujetos han salido de la habitación.");
	printf("\n- Última prueba del experimento.");
	printf("\n- JUGADORES abran su respectiva caja.");
	printf("\nUna pistola.");
	printf("\n- Disparen a su compañero.");
	printf("\nAmbos enfundais las armas.");
	printf("\n1.JUGADOR ROJO dispara");
	printf("\n2.JUGADOR AZUL dispara");
	printf("\n3.JUGADOR ROJO no dispara");
	printf("\n4.JUGADOR AZUL no dispara");
	printf("\n5.Ninguno dispara\n");
	do{
		scanf("%d", &opcion_arma);
		switch(opcion_arma){
			case 1: 
				printf("\nEl cuerpo del JUGADOR AZUL se desploma en el suelo."); 
				printf("\n- JUGADOR ROJO tiene permitido abandonar el experimento."); 
				printf("\nJUGADOR ROJO ha ganado.");
				v[0].puntosrojo=1500;
				calculodepuntos2(v,comienzo);
				exit(-1);
			break;
			case 2: 
				printf("\nEl cuerpo del JUGADOR ROJO se desploma en el suelo."); 
				printf("\n- JUGADOR AZUL tiene permitido abandonar el experimento."); 
				printf("\nJUGADOR AZUL ha ganado.");
				v[0].puntosazul+=1500;
				calculodepuntos2(v, comienzo);
				exit(-1);
			break;
			case 3: 
				printf("\nEl JUGADOR ROJO guarda el arma en la caja.");
				printf("\n¿Qué hace JUGADOR AZUL?.");
				printf("\n1.Disparar");
				printf("\n2.No disparar");
				printf("\n:");
				scanf("%d", &opcion_arma_2);
				system("cls");
				if(opcion_arma_2 == 1){
					printf("\nEl cuerpo del JUGADOR ROJO se desploma en el suelo."); 
					printf("\n- JUGADOR AZUL tiene permitido abandonar el experimento."); 
					printf("\nJUGADOR AZUL ha ganado.");
					v[0].puntosazul+=1500;
					calculodepuntos2( v,comienzo);
				}else{
					printf("\nAmbos jugadores coinciden en la misma idea."); 
					printf("\nDisparan a la puerta."); 
					printf("\nLa salida se muestra en frente.");
					printf("\nEscapan."); 
					printf("\nJUGADOR ROJO y JUGADOR AZUL han ganado.");
					v[0].puntosrojo=1500;
					v[0].puntosazul+=1500;
					calculodepuntos2( v, comienzo);
				}
				exit (-1);
			break;
			case 4: 
				printf("\nEl JUGADOR AZUL guarda el arma en la caja.");
				printf("\n¿Qué hace JUGADOR ROJO?.");
				printf("\n1.Disparar");
				printf("\n2.No disparar\n:");
				scanf("%d", &opcion_arma_2);
				system("cls");
				if(opcion_arma_2 == 1){
					printf("\nEl cuerpo del JUGADOR AZUL se desploma en el suelo."); 
					printf("\n- JUGADOR ROJO tiene permitido abandonar el experimento."); 
					printf("\nJUGADOR ROJO ha ganado.");
					v[0].puntosrojo=1500;
					calculodepuntos2( v, comienzo);
				}else{
					printf("\nAmbos jugadores coinciden en la misma idea."); 
					printf("\nDisparan a la puerta."); 
					printf("\nLa salida se muestra en frente.");
					printf("\nEscapan."); 
					printf("\nJUGADOR ROJO y JUGADOR AZUL han ganado.");
					v[0].puntosrojo=1500;
					v[0].puntosazul+=1500;
					calculodepuntos2(v,comienzo);
				}
				exit (-1);
				break;
			case 5: 
				printf("\nAmbos jugadores coinciden en la misma idea."); 
				printf("\nDisparan a la puerta."); 
				printf("\nLa salida se muestra en frente.");
				printf("\nEscapan."); 
				printf("\nJUGADOR ROJO y JUGADOR AZUL han ganado.");
				v[0].puntosrojo=1500;
				v[0].puntosazul+=1500;
				calculodepuntos2( v, comienzo);
				exit (-1);
			break;
		}
	}while((opcion_arma < 1)||(opcion_arma > 5));
	
}
void calculodepuntos2(jugadores2 v[],clock_t comienzo){
	jugadores2 aux;
	v[0].puntotal=0;
	int i=1,j,k;
	FILE *f;
	v[0].puntosazul=v[0].puntosazul-0.4*(clock()-comienzo)/(double)CLOCKS_PER_SEC ;
	v[0].puntosrojo=v[0].puntosrojo-0.4*(clock()-comienzo)/(double)CLOCKS_PER_SEC ;	
	v[0].puntotal=v[0].puntosazul+v[0].puntosrojo;

	f=fopen("r2jugadores.txt","r");
	if(f==NULL){
		printf("Error en la apertura del fichero\n");
		exit(-1);
	}
	while(fscanf(f,"%s %s %f",v[i].rojo,v[i].azul,v[i].puntotal)!=EOF){

		i++;
	}
	fclose(f);
	f=fopen("r2jugadores","w");
	for(j=0;j<i-1;j++){
		for(k=j+1;k<i;k++){
			if(v[j].puntotal < v[k].puntotal) {
				aux= v[j];
				v[j] = v[k];
				v[k] = aux;
			}
		}
	}
	for(j=0;j<i;j++){
		fprintf(f,"%s %s %f\n",v[0].rojo,v[0].azul,v[0].puntotal);
	}
}
void puntuaciones2(){
	FILE *f;
	jugadores2 a[1000];
	int i=0;
	f=fopen("r2jugadores.txt","r");
	if(f==NULL){
		printf("Error en la apertura del fichero\n");
		exit(-1);
	}
	while(fscanf(f,"%s %s %f",&a[i].rojo,&a[i].azul,&a[i].puntotal)!=EOF){
		printf("%s %s %f\n",a[i].rojo ,a[i].azul,a[i].puntotal);
		i++;
	}
	fclose(f);
}
void muerte_rojo(jugadores2 v[],clock_t comienzo){
	
	printf("\n\n- El experimento ha fallado.");
	printf("\n- Intento número 69 concluido.");
	printf("\n- Preparando escenario para la siguiente práctica experimental.");
	printf("\n- Eliminando al JUGADOR AZUL.");
	printf("\nUna descarga elécrica atraviesa el cuerpo del JUGADOR AZUL");
	printf("\nJUGADOR AZUL ha perdido, también.");
	calculodepuntos2(v, comienzo);
	exit(-1);
}
void muerte_azul(jugadores2 v[],clock_t comienzo){
	printf("\n\n- El experimento ha fallado.");
	printf("\n- Intento número 69 concluido.");
	printf("\n- Preparando escenario para la siguiente práctica experimental.");
	printf("\n- Eliminando al JUGADOR ROJO.");
	printf("\nUna descarga elécrica atraviesa el cuerpo del JUGADOR ROJO");
	printf("\nJUGADOR ROJO ha perdido, también.");	
	calculodepuntos2(v,comienzo);
	exit(-1);
}

void calculodepuntos(jugadores v[],clock_t comienzo){
	jugadores aux;
	FILE *f;
	int i=1,j,k;
	v[0].puntos=v[0].puntos-0.4*(clock()-comienzo)/(double)CLOCKS_PER_SEC;
	f=fopen("ranking.txt","r");
	if(f==NULL){
		printf("Error en la apertura del fichero\n");
		exit(-1);
	}
	while(fscanf(f,"%s %f",&v[i].nombre,&v[i].puntos)!=EOF){
		i++;
	}
	fclose(f);
	f=fopen("ranking.txt","w");
	for(j=0;j<i-2;j++){
		for(k=j+1;k<i;k++){
			if(v[j].puntos < v[k].puntos){
				aux= v[j];
				v[j] = v[k];
				v[k] = aux;
			}
		}
	}
	for(j=0;j<i;j++){
		fprintf(f,"%s %f\n",v[0].nombre,v[0].puntos);
	}
}
void puntuaciones(){
	FILE *f;
	jugadores v[1000];
	int i=0;
	f=fopen("ranking.txt","r");
	if(f==NULL){
		printf("Error en la apertura del fichero\n");
		exit(-1);
	}
	while(fscanf(f,"%s %f",&v[i].nombre,&v[i].puntos)!=EOF){
		printf("%s   %f\n",v[i].nombre,v[i].puntos);
		i++;
	}
	fclose(f);
}
