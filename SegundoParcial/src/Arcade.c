/*
 * Arcade.c
 *
 *  Created on: 16 oct 2021
 *      Author: Matii
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Arcade.h"



Arcades*  arcades_new(void)
{
    Arcades* pArcades = malloc(sizeof(Arcades));

	return pArcades;
}

Arcades* arcades_newParametros(char* idStr,char* nacionalidad,char* tipoSonido,char* cantJugadores,char* capacidadFichas,char* salon,char* juego)
{
	Arcades* pAux;

	if (idStr != NULL && esNumerica(idStr)==1 && nacionalidad != NULL && tipoSonido != NULL && cantJugadores != NULL && esNumerica(cantJugadores)==1 && capacidadFichas !=NULL && esNumerica(capacidadFichas)==1 && salon!=NULL && juego!=NULL)
	{
        pAux= arcades_new();

        if(pAux!=NULL)
        {
            arcades_setId(pAux,idStr);
			arcades_setNacionalidad(pAux,nacionalidad);
            arcades_setTipoSonido(pAux,tipoSonido);
            arcades_setCantJugadores(pAux,cantJugadores);
            arcades_setCapacidadFichas(pAux,capacidadFichas);
            arcades_setSalon(pAux,salon);
            arcades_setJuego(pAux,juego);
        }
	}
	return pAux;
}

int find_ArcadesById(LinkedList* listArcades, int id)
{
    Arcades* pArcades;

    int retorno =-1;

    if (listArcades!=NULL && id > 0)
    {
        for (int i = 0; i < ll_len(listArcades); i++)
        {
            pArcades= ll_get(listArcades,i);

            if(pArcades->id==id)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;

}

void arcades_delete(LinkedList* listArcades, int id)
{
	int borrarID;
	Arcades* pAux;
	int respuesta;

	if (listArcades!=NULL)
	{
		borrarID=find_ArcadesById(listArcades,id);
		if (borrarID!=-1)
		{
			pAux= ll_get(listArcades,borrarID);

			printf("%d,%s,%s,%d,%d,%s,%s\n",pAux->id,pAux->nacionalidad,pAux->tipoSonido,pAux->cantJugadores,pAux->capacidadFichas,pAux->salon,pAux->juego);

			pedirStringEntero(&respuesta,"\nEsta seguro que desea Eliminar este Arcade?(1-SI/2-NO)","\nEl valso ingresado es incalido, intente nuevamente: ",1,2,3);
			
			if (respuesta==1)
			{
				free(pAux);

				ll_remove(listArcades,borrarID);
			}
			else
			{
				puts("El Arcade no a sido eliminado");
			}
			
		}
	}
}

void arcades_modify(LinkedList* listArcades, int id,LinkedList* pArrayListJuegos)
{
	int modificarID;
	Arcades* auxArcades;
	int auxCantidad;
	int auxJuego;

	if (listArcades!=NULL)
	{
		modificarID=find_ArcadesById(listArcades,id);
		auxArcades= ll_get(listArcades,modificarID);

		if (modificarID!=-1 && auxArcades!=NULL)
		{
			pedirStringEntero(&auxCantidad,"\nDesea modificar la cantidad de jugadores?(1-SI/2-NO)","\nEl valor ingresado no es valido, intente nuevamente: ",1,2,3);
			if (auxCantidad==1)
			{
				arcades_getCantJugadores(auxArcades,&auxArcades->cantJugadores);
			}
			
            pedirStringEntero(&auxJuego,"\nDesea modificar el juego del arcade?(1-SI/2-NO)","\nEl valor ingresado no es valido, intente nuevamente: ",1,2,3);
            if (auxJuego==1)
			{
				if(pArrayListJuegos!=NULL)
				{
					for (int i = 0; i < pArrayListJuegos->size; i++)
					{
						printf("\n%s",(char*)ll_get(pArrayListJuegos,i));
					}
					
				}
				else
				{
					puts("Aun no se creo el archivo de juegos, puede hacerlo en la opcion 5 del menu principal");
				}
            	arcades_getJuego(auxArcades,auxArcades->juego);
			}
			
		}

	}
}



int arcades_setId(Arcades* this,char* id)
{
	int retorno = -1;
	int auxId;

	auxId = atoi(id);

	if(this != NULL && auxId >= 0)
	{
		this->id = auxId;//me guarda en el id de this el id que le paso por parametros
		retorno = 1;
	}
	return retorno;
}

int arcades_getId(Arcades* this,int* id)
{
	int retorno = -1;

	pedirStringEntero(id,"\nIngrese el ID del arcade:","\nEl ID ingresado no es valido, ingreselo nuevamente: ",0,INT_MAX,3);

	if(this != NULL && id != NULL)
	{
		this->id= *id;//me guarda en el puntero a id lo que hay en this id
		retorno = 1;
	}
	return retorno;
}

int arcades_setNacionalidad(Arcades* this,char* nacionalidad)
{
	int retorno = -1;

	if(this != NULL && nacionalidad != NULL)
	{

			strncpy(this->nacionalidad, nacionalidad, LEN_CHAR);
			retorno = 1;

	}
	return retorno;
}
int arcades_getNacionalidad(Arcades* this,char* nacionalidad)
{
	int retorno = -1;
	int auxChar;
	pedirStringTexto(nacionalidad,LEN_CHAR,"\nIngrese la nacionalidad de arcade:","\nEl nacionalidad ingresado es invalido, ingreselo nuevamente: ",3);

	if(this != NULL && nacionalidad != NULL)
	{
		if(nacionalidad[0]>= 'a' && nacionalidad[0]<='z')
		{
			auxChar=nacionalidad[0];
			nacionalidad[0]=auxChar-32;
		}
		strncpy(this->nacionalidad,nacionalidad, LEN_CHAR);
		retorno = 1;
	}
	return retorno;
}

int arcades_setTipoSonido(Arcades* this,char* tipoSonido)
{
	int retorno = -1;

	if(this != NULL && tipoSonido != NULL)
	{

			strncpy(this->tipoSonido, tipoSonido, LEN_CHAR);
			retorno = 1;

	}
	return retorno;
}
int arcades_getTipoSonido(Arcades* this,char* tipoSonido)
{
	int retorno = -1;
	int auxSonido;
	pedirStringEntero(&auxSonido,"\nSeleccione el tipo de sonido (1:MONO-2:ESTEREO):","\nOpcion no valida, ingreselo nuevamente: ",1,2,3);
	

	if(this != NULL && tipoSonido != NULL)
	{
		if(auxSonido==1)
		{
			strncpy(this->tipoSonido,"MONO", LEN_CHAR);			
		}
		else if (auxSonido==2)
		{
			strncpy(this->tipoSonido,"ESTEREO", LEN_CHAR);	
		}
		
		retorno = 1;
	}
	return retorno;
}

int arcades_setCantJugadores(Arcades* this,char* cantJugadores)
{
	int retorno = -1;
	int auxCantJugadores;

	auxCantJugadores = atoi(cantJugadores);

	if(this != NULL && auxCantJugadores >= 1)
	{
		this->cantJugadores = auxCantJugadores;
		retorno = 1;
	}
	return retorno;
}
int arcades_getCantJugadores(Arcades* this,int* cantJugadores)
{
	int retorno = -1;

	pedirStringEntero(cantJugadores,"\nIngrese la cantidad de jugadores del arcade(1-4):","\nLa cantidad de jugadores  ingresada no es valido, ingreselo nuevamente: ",1,4,3);

	if(this != NULL && cantJugadores != NULL)
	{
		this->cantJugadores= *cantJugadores;
		retorno = 1;
	}
	return retorno;
}

int arcades_setCapacidadFichas(Arcades* this,char* capacidadFichas)
{
	int retorno = -1;
	int auxCapacidadFichas;

    auxCapacidadFichas = atoi(capacidadFichas);

	if(this != NULL && auxCapacidadFichas >= 1)
	{
		this->capacidadFichas = auxCapacidadFichas;
		retorno = 1;
	}
	return retorno;
}

int arcades_getCapacidadFichas(Arcades* this,int* capacidadFichas)
{
	int retorno = -1;

	pedirStringEntero(capacidadFichas,"\nIngrese la capacidad de fichas del arcade(1-10000):","\nLa capacidad de fichas ingresada no es valido, ingreselo nuevamente: ",1,10000,3);

	if(this != NULL && capacidadFichas != NULL)
	{
		this->capacidadFichas= *capacidadFichas;
		retorno = 1;
	}
	return retorno;
}

int arcades_setSalon(Arcades* this,char* salon)
{
	int retorno = -1;

	if(this != NULL && salon != NULL)
	{

			strncpy(this->salon, salon, LEN_CHAR);
			retorno = 1;

	}
	return retorno;
}
int arcades_getSalon(Arcades* this,char* salon)
{
	int retorno = -1;
	int auxChar;
	pedirStringTexto(salon,LEN_CHAR,"\nIngrese la salon de arcade:","\nEl salon ingresado es invalido, ingreselo nuevamente: ",3);

	if(this != NULL && salon != NULL)
	{
		if(salon[0]>= 'a' && salon[0]<='z')
		{
			auxChar=salon[0];
			salon[0]=auxChar-32;
		}
		strncpy(this->salon,salon, LEN_CHAR);
		retorno = 1;
	}
	return retorno;
}

int arcades_setJuego(Arcades* this,char* juego)
{
	int retorno = -1;

	if(this != NULL && juego != NULL)
	{

			strncpy(this->juego, juego, LEN_CHAR);
			retorno = 1;

	}
	return retorno;
}
int arcades_getJuego(Arcades* this,char* juego)
{
	int retorno = -1;
	int auxChar;
	pedirStringTexto(juego,LEN_CHAR,"\nIngrese la juego de arcade:","\nEl juego ingresado es invalido, ingreselo nuevamente: ",3);

	if(this != NULL && juego != NULL)
	{
		if(juego[0]>= 'a' && juego[0]<='z')
		{
			auxChar=juego[0];
			juego[0]=auxChar-32;
		}
		strncpy(this->juego,juego, LEN_CHAR);
		retorno = 1;
	}
	return retorno;
}

int arcades_MaxId(LinkedList* this)
{
	Arcades* pAux;	
	int maxId =-1;

	if (this !=NULL)
	{
		maxId =0;
		for (int i = 0; i < this->size; i++)
		{
			pAux= ll_get(this,i);

			if (maxId < pAux->id)
			{
				maxId = pAux->id;
			}
			
		}
		
	}
	return maxId;
}

int arcades_ordenPorJuego(void* pArcadeA,void* pArcadeB)
{
	int retorno;
	Arcades* Arcade1 = (Arcades*)pArcadeA;
	Arcades* Arcade2 = (Arcades*)pArcadeB;


	if (strcmp(Arcade1->juego, Arcade2->juego)>0)
	{
		retorno =1;
	}
	else if(strcmp(Arcade1->juego, Arcade2->juego)<0)
	{
		retorno = -1;
	}
	else
	{
		retorno=0;
	}

	return retorno;

}

int arcades_FiltrarMultiplayer(void* a)
{
    int retorno=0;

    if (((Arcades*) a)->cantJugadores>=2)
    {
        retorno=1;
    }
    
    return retorno;
}
int arcades_DuplicarFichas(void* a)
{
	int aux;
	aux=((Arcades*)a)->capacidadFichas*2;
	((Arcades*)a)->capacidadFichas=aux;

	return 1;
}

int arcades_OrdenarPorId(void* pArcadeA,void* pArcadeB)
{
	if(((Arcades*)pArcadeA)->id > ((Arcades*)pArcadeB)->id)
{
 return 1;
}
if(((Arcades*)pArcadeA)->id < ((Arcades*)pArcadeB)->id)
{
 return -1;
}
return 0;
}

