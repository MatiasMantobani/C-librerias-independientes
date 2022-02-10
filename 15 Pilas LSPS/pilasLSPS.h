#ifndef PILASLSPS_H_INCLUDED
#define PILASLSPS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define Pila nodoS* // enmascaramiento (no implementado)


/// ------------inicio borrar al pasar a proyecto C----------------------------------
typedef struct  //reemplazar con #include "strucBasica"
{
    int numero;
    char letra;
    char palabra[30];
} Struc;


typedef struct nodoS    //reemplazar por #include "LSPS.h"
{
    Struc dato;
    struct nodoS* siguiente;
} nodoS;
/// ------------fin borrar al pasar a proyecto C-------------------------------------

void LSPSpasarAPilaLSPS(nodoS** pila, nodoS* lista);
nodoS* pilasLSPSpasarALista(nodoS* lista, nodoS** pila);
void pilasLSPSleer(nodoS** pila);
int pilasLSPSvacia(nodoS** pila);
Struc pilasLSPStope(nodoS** pila);
Struc pilasLSPSdesapilar(nodoS** pila);
void pilasLSPSmostrar(nodoS** pila);
void pilasLSPSapilarVarios(nodoS** pila,int cant);
void pilasLSPSapilar(nodoS** pila, Struc dato);
void pilasLSPSinic(nodoS** pila);
void pruebaPilasLSPS();
/// ------------inicio borrar al pasar a proyecto C----------------------------------

nodoS* LSPSagregarVariosPpioAuto(nodoS* lista, int cant);
Struc LSPSretornarPrimerStruc(nodoS* lista);
nodoS* LSPSborrarPrimero(nodoS* lista);
void LSPSmostrar(nodoS* lista);
nodoS* LSPSagregarUnoPpio(nodoS* lista, nodoS* nuevoNodo);
nodoS* LSPScrearNodo(Struc dato);
nodoS* LSPSinic();
void strucMostrar(Struc dato);
Struc strucCargarAuto();
Struc strucCargarAMano();
char charRandom();
/// ------------fin borrar al pasar a proyecto C-------------------------------------




#endif // PILASLSPS_H_INCLUDED
