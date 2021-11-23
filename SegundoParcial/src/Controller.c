/*
 * Controller.c
 *
 *  Created on: 20 nov 2021
 *      Author: Matii
 */

#include "Controller.h"
/**
 * @brief Busca el archivo y si no lo encuentra lo crea en blanco
 * 
 * @param path nombre del archivo
 * @param pArcadeList Lista de arcades
 * @return int [-1] si no encuentra el archivo [1] 
 */
int controller_loadFromText(char* path , LinkedList* pArcadeList)
{
    int retorno =-1;
    FILE* f = fopen(path,"r");
    if (f!=NULL)
    {
        parser_ArcadesFromText(f,pArcadeList);
        retorno=1;
    }
    else
    {
        f = fopen(path,"w");
        puts("No se encontro el archivo, creamos uno en blanco");
    }

    fclose(f);


    return retorno;
}

int controller_loadJuegos(char* path , LinkedList* pJuegosList)
{
    int retorno =-1;
    FILE* f = fopen(path,"r");
    if (f!=NULL)
    {
    	
        parser_JuegosFromText(f,pJuegosList);
        retorno=1;
    }

    fclose(f);


    return retorno;
}

/**
 * @brief 
 * 
 * @param path 
 * @param pArcadeList Lista de arcades 
 * @return int 
 */
int controller_saveAsText(char* path , LinkedList* pArcadeList)
{
    FILE* f = fopen(path,"w");
    Arcades* pAux;
    if(f!=NULL)
    {
        fprintf(f,"id,nacionalidad,tipo_sonido,cant_jug,fichas_max,salon,game\n");
        ll_sort(pArcadeList,arcades_OrdenarPorId,1);
        for(int i=0; i<pArcadeList->size; i++)
        {
            pAux = ll_get(pArcadeList,i);
            fprintf(f,"%d,%s,%s,%d,%d,%s,%s\n",pAux->id,pAux->nacionalidad,pAux->tipoSonido,pAux->cantJugadores,pAux->capacidadFichas,pAux->salon,pAux->juego);
        }
        fclose(f);
    }
    return 1;
}
/**
 * @brief Da de alta un arcade
 * 
 * @param pArcadeList Lista de arcades 
 * @return int [-1]Si no logro dar de alta el arcade [0]Si se dio el alta correctamente
 */
int controller_addArcade(LinkedList* pArcadeList)
{
    Arcades* pArcade;
    int retorno=-1;
    int auxId= arcades_MaxId(pArcadeList);
    char auxNacionalidad[LEN_CHAR];
    char auxTipoSonido[LEN_CHAR];
    int auxCantJugadores;
    int auxCapacidadFichas;
    char auxSalon[LEN_CHAR];
    char auxJuego[LEN_CHAR];

    pArcade=arcades_new();
    if(pArcade!=NULL)
    {
        if( arcades_getNacionalidad(pArcade,auxNacionalidad)==1 &&
            arcades_getTipoSonido(pArcade,auxTipoSonido)==1 &&
            arcades_getCantJugadores(pArcade,&auxCantJugadores)==1 &&
            arcades_getCapacidadFichas(pArcade,&auxCapacidadFichas)==1 &&
            arcades_getSalon(pArcade,auxSalon)==1 &&
            arcades_getJuego(pArcade,auxJuego)==1)
        {
            pArcade->id= auxId+1;
            if(ll_add(pArcadeList,pArcade)!=-1)
            {
                retorno=0;
                controller_saveAsText("arcades.csv",pArcadeList);
            }
        }
    }
    return retorno;

}
/**
 * @brief Lista los aracdes ordenados por nombre del juego
 * 
 * @param pArcadeList Lista de arcades 
 * @return int [-1] si noz
 */
int controller_ListArcade(LinkedList* pArcadeList)
{
    Arcades* pAux;

    int retorno=-1;

    if (pArcadeList !=NULL)
    {
        ll_sort(pArcadeList,arcades_ordenPorJuego,1);
        puts("id,nacionalidad,tipo_sonido,cant_jug,fichas_max,salon,game\n");
        for (int i = 1; i < pArcadeList->size; i++)
        {
            pAux= ll_get(pArcadeList,i);
            printf("%d,%s,%s,%d,%d,%s,%s\n",pAux->id,pAux->nacionalidad,pAux->tipoSonido,pAux->cantJugadores,pAux->capacidadFichas,pAux->salon,pAux->juego);

        }
        retorno=0;
    }

    return retorno;
}
/**
 * @brief 
 * 
 * @param pArcadeList Lista de arcades 
 * @return int 
 */
int controller_editArcade(LinkedList* pArcadeList,LinkedList* pArrayListJuegos)
{
    int retorno = -1;
    if(controller_ListArcade(pArcadeList)==-1)
    {
        puts("\nNo se pudo imprimir la lista");
    }
    int modificarID;

    if(pedirStringEntero(&modificarID,"Ingrese el ID del arcade que dese modificar","El ID ingresado es invalido, ingreselo nuevamente: ",0,INT_MAX,3)==1)
    {
        arcades_modify(pArcadeList,modificarID,pArrayListJuegos);
        retorno=1;
        controller_saveAsText("arcades.csv",pArcadeList);
    }
    else
    {
        puts("No se pudo modificar el arcade");
    }
    return retorno;
}
/**
 * @brief 
 * 
 * @param pArcadeList Lista de arcades 
 * @return int 
 */
int controller_removeArcade(LinkedList* pArcadeList)
{
    int retorno = -1;
    if(controller_ListArcade(pArcadeList)==-1)
    {
        puts("\nNo se pudo imprimir la lista");
    }
    int borrarID;

    if(pedirStringEntero(&borrarID,"Ingrese el ID del arcade que dese eliminar","El ID ingresado es invalido, ingreselo nuevamente: ",0,INT_MAX,3)==1)
    {
        arcades_delete(pArcadeList,borrarID);
        retorno=1;
    }
    else
    {
        puts("No se pudo eliminar el arcade");
    }
    controller_saveAsText("arcades.csv",pArcadeList);

    return retorno;
}

/**
 * @brief 
 * 
 * @param path 
 * @param pArcadeList Lista de arcades 
 * @return int 
 */
int controller_ListJuegos(char* path,LinkedList* pArcadeList)
{
    FILE* f = fopen(path,"w");
    Arcades* pAux;
    int flagEnLista=1;
    char* juego;
    LinkedList* listaJuegos = ll_newLinkedList();

    if(f!=NULL && path!=NULL&& pArcadeList!=NULL)
    {
        
        for(int i=0; i<pArcadeList->size; i++)
        {
            pAux = ll_get(pArcadeList,i);
            for (int j = 0; j < listaJuegos->size; j++)
            {
                juego= (char*)ll_get(listaJuegos,j);

                if (strcmp(pAux->juego,juego)==0)
                {
                    flagEnLista=1;
                }
            }
            if (flagEnLista==0)
            {
                ll_add(listaJuegos,pAux->juego);
            }
            flagEnLista=0;
        }
        for (int i = 0; i < listaJuegos->size; i++)
        {
            juego=(char*)ll_get(listaJuegos,i);
            fprintf(f,"\n%s",juego);
        }
        
        fclose(f);
    }
    return 1;
}
/**
 * @brief 
 * 
 * @param path 
 * @param pArcadeList Lista de arcades 
 * @return int 
 */
int controller_ListMultijugador(char* path,LinkedList* pArcadeList)
{
    int retorno =-1;
    LinkedList* auxList;
    Arcades* pAux;

    if (path!=NULL && pArcadeList !=NULL)
    {
        auxList =ll_clone(pArcadeList);
       
        ll_filter(auxList,arcades_FiltrarMultiplayer);
        //ll_sort(auxList,arcades_OrdenarPorId,1);

        FILE* f = fopen(path,"w");
        fprintf(f,"id,nacionalidad,tipo_sonido,cant_jug,fichas_max,salon,game\n");
        
        for (int i = 0; i < auxList->size; i++)
        {
            pAux=ll_get(auxList,i);
            if (pAux !=NULL)
            {
               fprintf(f,"%d,%s,%s,%d,%d,%s,%s\n",pAux->id,pAux->nacionalidad,pAux->tipoSonido,pAux->cantJugadores,pAux->capacidadFichas,pAux->salon,pAux->juego);
            }
        }
        fclose(f);
        retorno=0;
        
    }
    return retorno;
}
/**
 * @brief 
 * 
 * @param pArcadeList Lista de arcades 
 * @return int 
 */
int controller_DuplicarFichas(LinkedList* pArcadeList)
{
    int retorno = -1;

    if (pArcadeList!=NULL)
    {
        ll_map(pArcadeList,arcades_DuplicarFichas);
        retorno=0;
    }
    return retorno;
}


