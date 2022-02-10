#ifndef LDF_H_INCLUDED
#define LDF_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


/// inicio borrar en proyecto C

typedef struct
{
    int numero;
    char letra;
    char palabra[30];
} Struc;


typedef struct nodoD    //reemplazar con #include "LDPS"
{
    Struc dato;
    struct nodoD* anterior;
    struct nodoD* siguiente;
} nodoD;


typedef struct Fila     //reemplazar por 13 Filas LDPS
{
    nodoD* inicio;
    nodoD* fin;
} Fila;

/// fin borrar en proyecto C

typedef struct LDF
{
    Struc datoCelda;
    Fila filaCelda;
    struct LDF* siguiente;
} LDFcelda;


typedef struct
{
    Struc datoCelda;
    Struc datoFila;
} LDFarchivo;



LDFcelda* LDFarchivoALDF(char archivo[], LDFcelda* LDF);
void LDFarchivoMostrar(char archivo[]);
void LDFaArchivo(char archivo[], LDFcelda* LDF);

void LDFmostrarCelda(LDFcelda* celda);
void LDFmostrar(LDFcelda* lista);

LDFcelda* LDFagregarAlPpio(LDFcelda* lista, LDFcelda* nuevoNodo);
LDFcelda* LDFcrearCelda(Struc datoCelda);
LDFcelda* LDFbuscarNodoCelda(LDFcelda* LDF, Struc datoCelda);
LDFcelda* LDFalta(LDFcelda* LDF, Struc datoCelda, Struc datoFila);
LDFcelda* LDFagregarRandom(LDFcelda* LDF, int cant);

LDFcelda* LDFinic();

void pruebaLDF();

/// inicio borrar en proyecto C


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
/// fin borrar en proyecto C

#endif // LDF_H_INCLUDED
