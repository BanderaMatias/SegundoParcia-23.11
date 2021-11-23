/*
 * blibioteca.c
 *
 *  Created on: 7 sept 2021
 *      Author: Matii
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedirDatos.h"

int pedirStringTexto(char* pResultado,int len, char mensaje[], char mensajeError[],int reintentos){
		int retorno = 0;
	    int indexFinal;

	    for(int i=0; i<=reintentos; i++)
	    {
	        if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	        {
	            printf("%s", mensaje);
	            fflush(stdin);
	            if(fgets(pResultado,len,stdin)!=NULL)
	            {
	            	indexFinal = strlen(pResultado)-1;

					if(pResultado[indexFinal] == '\n')
					{
						pResultado[indexFinal] = '\0';
					}
	                retorno = 1;
	                break;
	            }
	            else
	                printf("%s", mensajeError);
	        }
	    }
	    return retorno;

}

int esNumerica(char cadena[])
{
    int estado= 0;
    if (cadena!=NULL && strlen(cadena)>0)
    {
        estado=0;
        for(int i=0; i<strlen(cadena);i++)
        {
            if(cadena[i]<='9' && cadena[i]>='0')
            {
                estado=1;

            }else{
            	estado=0;
            	break;
            }


        }
    }
    return estado;
}


int pedirStringEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
    int retorno = -1;
    int bufferInt;
    int i;
    char bufferCadenaAux[16];
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        for(i=0; i<=reintentos; i++)
        {
            printf("%s", mensaje);
            fflush(stdin);

            if(pedirStringTexto(bufferCadenaAux,sizeof(bufferCadenaAux),"","",1)==1)
            {

                if(esNumerica(bufferCadenaAux)==1)
                {
                    bufferInt = atoi(bufferCadenaAux);
                    if(bufferInt >= minimo && bufferInt <= maximo){
                        *pResultado = bufferInt;
                        retorno = 1;
                        break;
                    }else{
                        printf("%s", mensajeError);
                    }
                }
                else {
                    printf("%s", mensajeError);
                }
            }
            else {
                printf("%s", mensajeError);
            }
        }
    }
    return retorno;
}
int esFlotante(char cadena[])
{
	int retorno = -1;
	int index = 0;
	int contPuntos=0;

	if (cadena != NULL)
	{
		while (cadena[index] != '\0')
		{
			if (cadena[index] >= 46 && cadena[index] <= 57)
			{
		        if(cadena[index]!=47)
		        {

					retorno = 1;

					if (cadena[index] == '.')
					{
						contPuntos++;
						if (contPuntos>1)
						{
							retorno=-1;
							break;
						}

					}
		        }
		        else
		        {
		        	retorno = -1;
		        	break;
		        }
					
				
			}
			index++;
		}
		
	}
	return retorno;
}

int pedirStringFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos){
    int retorno = 0;
    float bufferFloat;
    int i;
    char bufferCadenaAux[16];
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        for(i=0; i<=reintentos; i++)
        {
            printf("%s", mensaje);
            fflush(stdin);

            if(pedirStringTexto(bufferCadenaAux,sizeof(bufferCadenaAux),"","",1)==1)
            {

                if(esFlotante(bufferCadenaAux)==1)
                {
                    bufferFloat = atof(bufferCadenaAux);
                    if(bufferFloat >= minimo && bufferFloat <= maximo){
                        *pResultado = bufferFloat;
                        retorno = 1;
                        break;
                    }else{
                        printf("%s", mensajeError);
                    }
                }
                else {
                    printf("%s", mensajeError);
                }
            }
            else {
                printf("%s", mensajeError);
            }
        }
    }
    return retorno;
}
int nombreValido(char cadena[], int tamCadena)
{
    int retorno=1;
    if (cadena!=NULL && tamCadena>0)
    {
        retorno=1;
        
        
        for(int i=0; i<tamCadena;i++)
        {
            
            if((cadena[i]<='Z' && cadena[i]>='A')||(cadena[i]<='z' && cadena[i]>='a'))
            {
                retorno=1;

            }else{
                retorno=-1;
                break;
            }   
            
           
        }
    }
    return retorno;
}
