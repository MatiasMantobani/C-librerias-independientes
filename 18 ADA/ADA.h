#ifndef ADA_H_INCLUDED
#define ADA_H_INCLUDED


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


typedef struct nodoArbol
{
     Struc dato;
     struct nodoArbol* izq;
     struct nodoArbol* der;
}nodoArbol;

/// fin borrar en proyecto C

typedef struct
{
    Struc datoCelda;
    nodoArbol* arbolCelda;
} ADAcelda;


typedef struct
{
    Struc datoCelda;
    Struc datoArbol;
} ADAarchivo;


void ADAaArchivoPorNumeroCelda(char archivo[], ADAcelda arreglo[], int validos, int dato);
int ADAarchivoAADA(char archivo[], ADAcelda arreglo[], int dimension, int validos);
void ADAarchivoMostrar(char archivo[]);
FILE* arbolAArchivo(nodoArbol* arbol, FILE* arch, ADAarchivo nuevoRegistro);
void ADAaArchivo(char archivo[], ADAcelda arreglo[], int validos);

int ADAagregarCelda(ADAcelda arreglo[], int validos, Struc datoCelda);
int ADAposCelda(ADAcelda arreglo[], int validos, Struc datoCelda);
int ADAalta(ADAcelda arreglo[], int dimension, int validos, Struc datoCelda, Struc datoArbol);
int ADAagregarRandom(ADAcelda arreglo[],int dimension, int validos,int cant);

void ADAmostrar(ADAcelda arreglo[], int validos);
void ADAinic(ADAcelda arreglo[], int dim);

void pruebaADA();

/// inicio borrar en proyecto C

//arboles

void arbolMostrarPreOrder(nodoArbol* arbol);
int _print_t(nodoArbol *tree, int is_left, int offset, int depth, char s[20][255]);
void arbolDibujar(nodoArbol *tree);
nodoArbol* arbolAgregarVariosOrdenandoPorNumero(nodoArbol* arbol, int cant);
nodoArbol* arbolAgregarUnoOrdenandoPorNumero(nodoArbol* arbol, nodoArbol* nuevoNodo);
nodoArbol* arbolNodoCrear(Struc dato);
nodoArbol* arbolInic();


//struc
void strucMostrar(Struc dato);
Struc strucCargarAuto2(int *i);
Struc strucCargarAMano();
Struc strucCargarAuto();
char charRandom();

/// fin borrar en proyecto C


#endif // ADA_H_INCLUDED
