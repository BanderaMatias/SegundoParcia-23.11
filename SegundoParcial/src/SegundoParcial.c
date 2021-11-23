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

    LinkedList* listaArcades = ll_newLinkedList();


    controller_loadFromText("arcades.csv", listaArcades);
    

    do{
        puts("Menu:\n1. ALTA DE ARCADE.\n2. MODIFICAR ARCADE.\n3. ELIMINAR ARCADE \n4. IMPRIMIR ARCADES\n5. LISTAR JUEGOS\n6. LISTAR MULTIJUGADORES\n7. DUPLICAR FICHAS\n8. Salir");
		pedirStringEntero(&option,"\nSelecionar -->", "No es una opcion valida",0,8, 3);

        switch(option)
        {
            case 1:{
				controller_addArcade(listaArcades);
                break;
            }
            case 2:{
                controller_editArcade(listaArcades);
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
                controller_ListJuegos("juegos.txt",listaArcades);
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
                
                break;
            }
           
        }

        system("pause");
        system("cls");
    }while(option != 8);


    return 0;
}
