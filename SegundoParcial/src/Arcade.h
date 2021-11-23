/*
 * Arcade.h
 *
 *  Created on: 16 oct 2021
 *      Author: Matii
 */

#ifndef ARCADE_H_
#define ARCADE_H_

#include "pedirDatos.h"
#include "LinkedList.h"

#define LEN_CHAR 64
#define LEN_INT 16

struct
{
 int id;
 char nacionalidad[LEN_CHAR];
 char tipoSonido[LEN_CHAR];
 int cantJugadores;
 int capacidadFichas;
 char salon[LEN_CHAR];
 char juego[LEN_CHAR];
}typedef Arcades;

Arcades*  arcades_new(void);
Arcades* arcades_newParametros(char* idStr,char* nacionalidad,char* tipoSonido,char* cantJugadores,char* capacidadFichas,char* salon,char* juego);

int find_ArcadesById(LinkedList* listArcades, int id);
void arcades_delete(LinkedList* listArcades, int id);
void arcades_modify(LinkedList* listArcades, int id,LinkedList* pArrayListJuegos);

int arcades_setId(Arcades* this,char* id);
int arcades_getId(Arcades* this,int* id);

int arcades_setNacionalidad(Arcades* this,char* nacionalidad);
int arcades_getNacionalidad(Arcades* this,char* nacionalidad);

int arcades_setTipoSonido(Arcades* this,char* tipoSonido);
int arcades_getTipoSonido(Arcades* this,char* tipoSonido);

int arcades_setCantJugadores(Arcades* this,char* cantJugadores);
int arcades_getCantJugadores(Arcades* this,int* cantJugadores);

int arcades_setCapacidadFichas(Arcades* this,char* capacidadFichas);
int arcades_getCapacidadFichas(Arcades* this,int* capacidadFichas);

int arcades_setSalon(Arcades* this,char* salon);
int arcades_getSalon(Arcades* this,char* salon);

int arcades_setJuego(Arcades* this,char* juego);
int arcades_getJuego(Arcades* this,char* juego);

int arcades_MaxId(LinkedList* this);
int arcades_ordenPorJuego(void* pArcadeA,void* pArcadeB);
int arcades_FiltrarMultiplayer(void* a);
int arcades_DuplicarFichas(void* a);
int arcades_OrdenarPorId(void* pArcadeA,void* pArcadeB);

#endif /* ARCADE_H_ */
