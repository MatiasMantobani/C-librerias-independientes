#ifndef ADF_H_INCLUDED
#define ADF_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

///inicio borrar proyecto C

typedef struct
{
    int numero;
    char letra;
    char palabra[30];
} Struc;


typedef struct nodoD
{
    Struc dato;
    struct nodoD* anterior;
    struct nodoD* siguiente;
} nodoD;


typedef struct Fila
{
    nodoD* inicio;
    nodoD* fin;
} Fila;

///fin borrar proyecto C

typedef struct
{
    Struc datoCelda;
    Fila filaCelda;
} ADFcelda;


typedef struct
{
    Struc datoCelda;
    Struc datoFila;
} ADFarchivo;


int ADFarchivoAADF(char archivo[], ADFcelda arreglo[], int dimension, int validos);
void ADFarchivoMostrar(char archivo[]);
void ADFaArchivo(char archivo[], ADFcelda arreglo[], int validos);

void ADFmostrar(ADFcelda arreglo[], int validos);
int ADFagregarCelda(ADFcelda arreglo[], int validos, Struc datoCelda);
int ADFposCelda(ADFcelda arreglo[], int validos, Struc datoCelda);
int ADFalta(ADFcelda arreglo[], int dimension, int validos, Struc datoCelda, Struc datoFila);
int ADFagregarRandom(ADFcelda arreglo[],int dimension, int validos,int cant);

void pruebaADF();

///inicio borrar proyecto C

void filaMostrar(Fila* fila);
void filaAgregarUno(Fila* fila, Struc dato);
void filaInic(Fila* fila);

void LDPSmostrar(nodoD* lista);
nodoD* LDPSultimo(nodoD* lista);
nodoD* LDPSagregarUnoFinal(nodoD* lista, nodoD* nuevoNodo);
nodoD* LDPScrearNodo(Struc dato);
nodoD* LDPSinic();

void strucMostrar(Struc dato);
Struc strucCargarAuto();
char charRandom();

///fin borrar proyecto C


#endif // ADF_H_INCLUDED
