#ifndef LDA_H_INCLUDED
#define LDA_H_INCLUDED

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
} nodoArbol;

/// fin borrar en proyecto C

typedef struct LDAcelda
{
    Struc datoCelda;
    nodoArbol* arbolCelda;
    struct LDAcelda* siguiente;
} LDAcelda;


typedef struct
{
    Struc datoCelda;
    Struc datoArbol;
} LDAarchivo;


void LDAbuscarPalabraEnArboles(LDAcelda* LDA, char dato[]);
LDAcelda* LDAarchivoALDA(char archivo[], LDAcelda* LDA);
void LDAarchivoMostrar(char archivo[]);
void LDAaArchivo(char archivo[], LDAcelda* LDA);
void LDAmostrar(LDAcelda* lista);
void LDAmostrarCelda(LDAcelda* celda);

LDAcelda* LDAalta(LDAcelda* LDA, Struc datoCelda, Struc datoLista);
LDAcelda* LDLagregarAlPpio(LDAcelda* lista, LDAcelda* nuevoNodo);
LDAcelda* LDAbuscarNodoCelda(LDAcelda* LDL, Struc datoCelda);
LDAcelda* LDAcrearCelda(Struc datoCelda);
LDAcelda* LDAagregarRandom(LDAcelda* LDA, int cant);
LDAcelda* LDAinic();

void pruebaLDA();



/// inicio borrar en proyecto C

nodoArbol* arbolBuscarPorPalabra(nodoArbol* arbol, char palabra[]);
void arbolMostrarPreOrder(nodoArbol* arbol);
void arbolDibujar(nodoArbol *tree);
int _print_t(nodoArbol *tree, int is_left, int offset, int depth, char s[20][255]);
nodoArbol* arbolAgregarUnoOrdenandoPorNumero(nodoArbol* arbol, nodoArbol* nuevoNodo);
nodoArbol* arbolNodoCrear(Struc dato);
nodoArbol* arbolInic();

void strucMostrar(Struc dato);
Struc strucCargarAuto();
char charRandom();

/// fin borrar en proyecto C

#endif // LDA_H_INCLUDED
