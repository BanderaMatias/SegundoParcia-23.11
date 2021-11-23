/*
 ============================================================================
 Name        : SegundoParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Arcade.h"
#include "pedirDatos.h"

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    int flagJuegos=0;
    int respuesta;

    LinkedList* listaArcades = ll_newLinkedList();
    LinkedList* listaJuegos = ll_newLinkedList();


    controller_loadFromText("arcades.csv", listaArcades);
    controller_loadJuegos("juegos.txt", listaJuegos);
    

    do{
        puts("Menu:\n1. ALTA DE ARCADE.\n2. MODIFICAR ARCADE.\n3. ELIMINAR ARCADE \n4. IMPRIMIR ARCADES\n5. LISTAR JUEGOS\n6. LISTAR MULTIJUGADORES\n7. DUPLICAR FICHAS\n8. Salir");
		pedirStringEntero(&option,"\nSelecionar -->", "No es una opcion valida",0,8, 3);

        switch(option)
        {
            case 1:{
                if (controller_addArcade(listaArcades)==-1)
                {
                    puts("No se pudo crear el arcade");
                }
                break;
            }
            case 2:{
                controller_editArcade(listaArcades,listaJuegos);
                break;
            }
            case 3:{
				controller_removeArcade(listaArcades);
                break;
            }
            case 4:{
                controller_ListArcade(listaArcades);
                break;
            }
            case 5:{
                if (controller_ListJuegos("juegos.txt",listaArcades)==1)
                {
                    flagJuegos=1;
                }
                
                
                break;
            }
            case 6:{
                controller_ListMultijugador("Multijugadores.csv",listaArcades);

                break;
            }
            case 7:{
                controller_DuplicarFichas(listaArcades);

                break;
            }
            case 8:{
                if (flagJuegos==0)
                {
                 pedirStringEntero(&respuesta,"\nNo listo los Juegos, si a agregado un juego nuevo debe listarlos en la opcion 5 del menu.\n¿Desea continuar?(1-SI/2-NO)","\nValor invalido, ingreselo nuevamente: ",1,2,3);
                }
                if (respuesta==2)
                {
                    option=0;
                    respuesta=0;
                }               
                break;
            }
           
        }

        system("pause");
        system("cls");
    }while(option != 8);


    return 0;
}
