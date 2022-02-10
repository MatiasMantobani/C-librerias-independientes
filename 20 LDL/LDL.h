#ifndef LDL_H_INCLUDED
#define LDL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



/// inicio borrar proyecto C

typedef struct  //reemplazar por lib struc
{
    int numero;
    char letra;
    char palabra[30];
} Struc;


typedef struct nodoS    //reemplazar por lib LSPS
{
    Struc dato;
    struct nodoS* siguiente;
} nodoS;

/// fin borrar proyecto C


typedef struct LDLcelda
{
    Struc datoCelda;
    nodoS* listaCelda;
    struct LDLcelda* siguiente;
}LDLcelda;


typedef struct
{
    Struc datoCelda;
    Struc datoLista;
} strucArchivo;


//encabezados no repetidos
LDLcelda* LDLarchivoALDL(char archivo[], LDLcelda* LDL);
void LDLaArchivo(char archivo[], LDLcelda* LDL);
void LDLarchivoMostrar(char archivo[]);

void LDLmostrar(LDLcelda* lista);
void LDLmostrarCelda(LDLcelda* celda);

LDLcelda* LDLagregarAlPpio(LDLcelda* lista, LDLcelda* nuevoNodo);
LDLcelda* LDLcrearCelda(Struc datoCelda);
LDLcelda* LDLbuscarNodoCelda(LDLcelda* LDL, Struc datoCelda);
LDLcelda* LDLalta(LDLcelda* LDL, Struc datoCelda, Struc datoLista);
LDLcelda* LDLagregarRandom(LDLcelda* LDL, int cant);
LDLcelda* LDLinic();


/// inicio borrar proyecto C
nodoS* LSPSagregarUnoFinal2(nodoS* lista, nodoS* nuevoNodo);
nodoS* LSPSagregarUnoPpio(nodoS* lista, nodoS* nuevoNodo);
void LSPSmostrar(nodoS* lista);
nodoS* LSPScrearNodo(Struc dato);
nodoS* LSPSinic();

//struc
void strucMostrar(Struc dato);
Struc strucCargarAuto();
char charRandom();
/// fin borrar proyecto C



void pruebaLDL();

#endif // LDL_H_INCLUDED
