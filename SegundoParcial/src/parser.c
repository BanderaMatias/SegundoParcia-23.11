
#include "parser.h"
#include <string.h>

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListArcades LinkedList*
 * \return int
 *
 */
int parser_ArcadesFromText(FILE* pFile , LinkedList* pArrayListArcades)
{
    Arcades* pEaux;

    int retorno=-1;

    char id[LEN_INT];
    char nacionalidad[LEN_CHAR];
    char tipoSonido[LEN_CHAR];
    char cantidadJugadores[LEN_INT];
    char capacidadFichas[LEN_INT]; 
    char salon[LEN_CHAR];
    char juego[LEN_CHAR];

    if (pFile!=NULL)
    {   
        //Llega
        do       
        {
            pEaux = arcades_new();
            

            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nacionalidad,tipoSonido,cantidadJugadores,capacidadFichas,salon,juego)==7)
            {          
                pEaux = arcades_newParametros(id,nacionalidad,tipoSonido,cantidadJugadores,capacidadFichas,salon,juego);
                
                ll_add(pArrayListArcades,pEaux);
                
            }
        }while(feof(pFile)==0);  
        ll_remove(pArrayListArcades,0);
    }


    return retorno;
}

int parser_JuegosFromText(FILE* pFile , LinkedList* pArrayListJuegos)
{
    char* pAux;

    int retorno=-1;

    char juego[LEN_CHAR];

    if (pFile!=NULL)
    {   
        //Llega
        do       
        {
            pAux = malloc(LEN_CHAR);
            
            
            if(fscanf(pFile,"%s\n",juego)==1)
            {          
                strncpy(pAux,juego,LEN_CHAR);
                
                ll_add(pArrayListJuegos,pAux);
                
            }
            
        }while(feof(pFile)==0);  
    }


    return retorno;
}