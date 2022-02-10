#ifndef LDPS_H_INCLUDED
#define LDPS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <time.h>


/// ------------inicio borrar al pasar a proyecto C----------------------------------
typedef struct  //reemplazar con #include "strucBasica"
{
    int numero;
    char letra;
    char palabra[30];
} Struc;
/// ------------fin borrar al pasar a proyecto C-------------------------------------


typedef struct nodoD
{
    Struc dato;
    struct nodoD* anterior;
    struct nodoD* siguiente;
} nodoD;


int LDPSlistaAArregloPorPalabra(nodoD* lista, char palabra[], Struc A[], int dimension);

nodoD* LDPSborrarNodoDelMedio(nodoD* lista); // no anda en 2 nodos
nodoD* LDPSborrarPorPos(nodoD* lista, int posAborrar);
nodoD* LDPSborrarLista(nodoD* lista);
nodoD* LDPSborrarPorPalabra(nodoD* lista, char dato[]);
nodoD* LDPSborrarPorNumero(nodoD* lista, int num);
nodoD* LDPSborrarPrimerNodo(nodoD* lista);

int LDPSlistaVacia(nodoD* lista);
int LDPScontarNodos(nodoD* lista);
int LDPScapicuaPorNumero(nodoD* principio, nodoD* fin);
int LDPScontarPorPalabra(nodoD* lista, char dato[]);
Struc LDPSstrucMayorNumero(nodoD* lista);
nodoD* LDPSBuscarPorNumero(nodoD* lista, int dato);
int LDPSretornarPrimerNumero(nodoD* lista);
nodoD* LDPSultimo(nodoD* lista);

nodoD* LDPSagregarVariosOrdenadamentePorNumeroAuto(nodoD* lista, int cant);
nodoD* LDPSagregarVariosFinalAuto(nodoD* lista, int cant);
nodoD* LDPSagregarVariosPpioAuto(nodoD* lista, int cant);
nodoD* LDPSagregarUnoOrdenadamentePorNumero(nodoD* lista, nodoD* nuevoNodo);
nodoD* LDPSagregarUnoFinal(nodoD* lista, nodoD* nuevoNodo);
nodoD* LDPSagregarUnoPpio2(nodoD* lista, nodoD* nuevoNodo);
nodoD* LDPSagregarUnoPpio(nodoD* lista, nodoD* nuevoNodo);

void LDPSmostrar(nodoD* lista);
nodoD* LDPScrearNodo(Struc dato);
nodoD* LDPSinic();

void pruebaLDPS();


/// ------------inicio borrar al pasar a proyecto C----------------------------------
void arregloStrucMostrar(Struc A[],int validos);
void strucMostrar(Struc dato);
Struc strucCargarAMano();
Struc strucCargarAuto();
char charRandom();
/// ------------fin borrar al pasar a proyecto C-------------------------------------

#endif // LDPS_H_INCLUDED
