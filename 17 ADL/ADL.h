#ifndef ADL_H_INCLUDED
#define ADL_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

///----------------inicio borrar en proyecto C

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


typedef struct nodoArbol
{
     Struc dato;
     struct nodoArbol* izq;
     struct nodoArbol* der;
}nodoArbol;

///----------------fin borrar en proyecto C

typedef struct
{
    Struc datoCelda;
    Struc datoLista;
} strucArchivo;


typedef struct
{
    Struc datoCelda;    //no debe ser el mismo tipo de dato que la lista, aca ambos son Struc pero solo para demostrar
    nodoS* listaCelda;
} ADLCelda;


int arbolToADL(nodoArbol* arbol, ADLCelda arreglo[], int dimension, int validos);
void ADLaArchivoPorCeldaPorPalabra(char archivo[], ADLCelda arreglo[], int validos, char palabra[]);
void ADLaArchivo(char archivoAAbrir[], ADLCelda arreglo[], int validos);
int ADLarchivoAADL(char archivoAAbrir[], ADLCelda arreglo[], int dimension, int validos);

void ADLarchivoStrucCompuestaMostrar(char archivo[]);
void ADLarchivoStrucCompuestaCargarVariosAuto(char archivo[], int cant, int *i);
void ADLarchivoStrucCompuestaCargarUnoAuto(char archivo[], int *i);

void ADLcontar(ADLCelda arreglo[], int validos);

int ADLbuscarEnDatosLista(ADLCelda arreglo[], int validos, char palabra[]);
int ADLbuscarEnDatosCelda(ADLCelda arreglo[], int validos, int pos, char palabra[]);
int ADLagregarListaACelda(ADLCelda arreglo[], int dimension, int validos, Struc datoCelda, nodoS* lista);


int ADLagregarCelda(ADLCelda arreglo[], int validos, Struc datoCelda);
int ADLposCelda(ADLCelda arreglo[], int validos, Struc datoCelda);
int ADLalta(ADLCelda arreglo[], int validos, int dimension, Struc datoCelda, Struc datoLista);
int ADLagregarRandom(ADLCelda arreglo[],int dimension, int validos, int cant);

void ADLmostrar(ADLCelda arreglo[],int validos);
void ADLinic(ADLCelda arreglo[], int dim);
void pruebaADL();


///----------------inicio borrar en proyecto C
//arboles
void arbolMostrarPreOrder(nodoArbol* arbol);
int _print_t(nodoArbol *tree, int is_left, int offset, int depth, char s[20][255]);
void arbolDibujar(nodoArbol *tree);
nodoArbol* arbolAgregarVariosOrdenandoPorNumero(nodoArbol* arbol, int cant);
nodoArbol* arbolAgregarUnoOrdenandoPorNumero(nodoArbol* arbol, nodoArbol* nuevoNodo);
nodoArbol* arbolNodoCrear(Struc dato);
nodoArbol* arbolInic();


//LSPS
int LSPScontarNodos(nodoS* lista);
nodoS* LSPSbuscarPorPalabra(nodoS* lista, char dato[30]);
nodoS* LSPSagregarVariosPpioAuto(nodoS* lista, int cant);
nodoS* LSPSagregarUnoPpio(nodoS* lista, nodoS* nuevoNodo);
void LSPSmostrar(nodoS* lista);
nodoS* LSPScrearNodo(Struc dato);
nodoS* LSPSinic();

//struc
void strucMostrar(Struc dato);
Struc strucCargarAuto2(int *i);
Struc strucCargarAMano();
Struc strucCargarAuto();
char charRandom();
///----------------fin borrar en proyecto C


#endif // ADL_H_INCLUDED
