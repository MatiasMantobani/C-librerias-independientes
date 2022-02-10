#ifndef LSPS_H_INCLUDED
#define LSPS_H_INCLUDED


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


typedef struct nodoS
{
    Struc dato;
    struct nodoS* siguiente;
} nodoS;


// arreglo struc
int LSPSlistaAArreglo(nodoS* lista, Struc arreglo[], int dim);

// recursivo
nodoS* LSPSagregarOrdenadamentePorNumeroRecursivo(nodoS* lista, nodoS* aInsertar);
nodoS* LSPSlistaDePosParRecursivo(nodoS* lista, nodoS* listaPar);
nodoS* LSPSborrarNodoPorNumeroRecursivo(nodoS* lista, int dato);
int LSPScontarPalabrasRecursivo(nodoS* lista, char dato[30]);
nodoS* LSPSagregarUnoFinalRecursivo(nodoS* lista, nodoS* nuevoNodo);
nodoS* LSPSinvertirRecursivo(nodoS* lista);
int LSPSsumarNumerosRecursivo(nodoS* lista);
void LSPSmostrarRecursivo(nodoS* lista);

nodoS* LSPSArchivoAListaOrdenadamente(FILE* archivo, nodoS* lista);
FILE* LSPSlistaAArchivo(FILE* archivo, nodoS* lista);
nodoS* LSPSArchivoALista(FILE * archivo, nodoS* lista);

nodoS* LSPSborrarPrimero(nodoS* lista);
nodoS* LSPSborrarUltimo(nodoS* lista);
nodoS* LSPSborrarLista(nodoS* lista);
nodoS* LSPSborrarPorPos(nodoS* lista, int posAborrar);
nodoS* LSPSborrarPorPalabra(nodoS* lista, char nombreBorrar[30]);
nodoS* LSPSborrarPorNumero(nodoS* lista, int dato);
nodoS* LSPSborrarMayoresA(nodoS* lista, int dato);

nodoS* LSPSIntercalar(nodoS* lista1, nodoS* lista2);
int LSPSCompararPorNumero(nodoS* A, nodoS* B);
Struc LSPSretornarPrimerStruc(nodoS* lista);
nodoS* LSPSinvertir(nodoS* lista);
int LSPScontarNodos(nodoS* lista);

int LSPSBuscarMayorPorNumero(nodoS* lista);
nodoS* LSPSbuscarPorPalabra(nodoS* lista, char dato[30]);
nodoS* LSPSBuscarPorNumero(nodoS* lista, int dato);

void LSPSMostrarNodoPorNumero(nodoS* lista, int numero);

nodoS* LSPSagregarOrdenadamentePorNumero(nodoS* lista, nodoS* nuevoNodo);
nodoS* LSPSagregarVariosOrdenadamenteAuto(nodoS* lista, int cant);
nodoS* LSPSagregarVariosOrdenadamenteSemi(nodoS* lista);

nodoS* LSPSagregarVariosFinalAuto(nodoS* lista, int cant);
nodoS* LSPSagregarVariosFinalSemi(nodoS* lista);
nodoS* LSPSagregarUnoFinal2(nodoS* lista, nodoS* nuevoNodo);
nodoS* LSPSagregarUnoFinal(nodoS* lista, nodoS* nuevoNodo);
nodoS* LSPSultimo(nodoS* lista);

nodoS* LSPSagregarVariosPpioAuto(nodoS* lista, int cant);
nodoS* LSPSagregarVariosPpioSemi(nodoS* lista);
nodoS* LSPSagregarUnoPpio(nodoS* lista, nodoS* nuevoNodo);

void LSPSmostrar(nodoS* lista);
nodoS* LSPScrearNodo(Struc dato);
nodoS* LSPSinic();

void pruebaLSPS();


/// ------------inicio borrar al pasar a proyecto C----------------------------------
void strucMostrar(Struc dato);
char charRandom();
Struc strucCargarAuto();
Struc strucCargarAMano();
void archivoMostrar(char archivo[]);
int archivoContarRegistros(char fileName[]);
void arregloStrucMostrar(Struc A[],int validos);

/// ------------fin borrar al pasar a proyecto C----------------------------------

#endif // LSPS_H_INCLUDED
