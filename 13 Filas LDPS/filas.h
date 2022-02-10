#ifndef FILAS_H_INCLUDED
#define FILAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/// ------------inicio borrar al pasar a proyecto C----------------------------------
typedef struct  //reemplazar con #include "strucBasica"
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
/// ------------fin borrar al pasar a proyecto C-------------------------------------


typedef struct Fila
{
    nodoD* inicio;
    nodoD* fin;
} Fila;


Fila listaAFilaPorPalabra(nodoD* lista, char palabra[], Fila* fila);
int filaVacia(Fila* fila);
int filaPrimero(Fila* fila);
int filaExtraer(Fila* fila);
void filaLeer(Fila* fila);
void filaAgregarVariosAuto(Fila* fila, int cant);
void filaMostrar(Fila* fila);
void filaAgregarUno(Fila* fila, Struc dato);
void filaInic(Fila* fila);
void pruebaFilasLSPS();


/// ------------inicio borrar al pasar a proyecto C----------------------------------


nodoD* LDPSagregarVariosFinalAuto(nodoD* lista, int cant);
int LDPSlistaVacia(nodoD* lista);
int LDPSretornarPrimerNumero(nodoD* lista);
nodoD* LDPSborrarPrimerNodo(nodoD* lista);
nodoD* LDPSagregarUnoFinal(nodoD* lista, nodoD* nuevoNodo);
nodoD* LDPSultimo(nodoD* lista);

void LDPSmostrar(nodoD* lista);
nodoD* LDPScrearNodo(Struc dato);
nodoD* LDPSinic();

void strucMostrar(Struc dato);
Struc strucCargarAuto();
Struc strucCargarAMano();
char charRandom();
/// ------------fin borrar al pasar a proyecto C-------------------------------------



#endif // FILAS_H_INCLUDED
