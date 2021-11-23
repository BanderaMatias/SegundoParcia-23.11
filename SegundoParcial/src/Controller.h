/*
 * Controller.h
 *
 *  Created on: 20 nov 2021
 *      Author: Matii
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "LinkedList.h"
#include "Arcade.h"
#include "parser.h"
#include "pedirDatos.h"

int controller_loadFromText(char* path , LinkedList* pArrayListArcade);
int controller_loadFromBinary(char* path , LinkedList* pArrayListArcade);
int controller_addArcade(LinkedList* pArrayListArcade);
int controller_editArcade(LinkedList* pArrayListArcade);
int controller_removeArcade(LinkedList* pArrayListArcade);
int controller_ListArcade(LinkedList* pArrayListArcade);
int controller_sortArcade(LinkedList* pArrayListArcade);

int controller_ListJuegos(char* path,LinkedList* pArcadeList);
int controller_ListMultijugador(char* path,LinkedList* pArrayListArcade);
int controller_DuplicarFichas(LinkedList* pArrayListArcade);

int controller_saveAsText(char* path , LinkedList* pArrayListArcade);
int controller_saveAsBinary(char* path , LinkedList* pArrayListArcade);

int controller_loadJuegos(char* path , LinkedList* pArcadeList);



#endif /* CONTROLLER_H_ */
