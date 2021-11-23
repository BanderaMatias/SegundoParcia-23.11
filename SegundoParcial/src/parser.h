/*
 * parser.h
 *
 *  Created on: 6 nov 2021
 *      Author: Matii
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Arcade.h"


int parser_ArcadesFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_JuegosFromText(FILE* pFile , LinkedList* pArrayListArcades);
#endif /* PARSER_H_ */
