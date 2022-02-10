#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


///-------------inicio borrar en proyecto C-------------
typedef struct {
int numero;
char letra;
char palabra[30];
}Struc;


typedef struct nodoS
{
    Struc dato;
    struct nodoS* siguiente;
} nodoS;
///-------------fin borrar en proyecto C-------------

typedef struct nodoArbol
{
     Struc dato;
     struct nodoArbol* izq;
     struct nodoArbol* der;
}nodoArbol;

void arbolAArchivo(nodoArbol* arbol,FILE* archivo);
nodoArbol* archivoAArbol(nodoArbol* arbol, FILE* puntArch);
nodoS* arbolALSPS(nodoArbol* arbol, nodoS* lista);

nodoArbol* arbolBorrarNodoPorNumero2(nodoArbol* arbol, int numero);
nodoArbol* arbolBorrarNodoPorNumero(nodoArbol* arbol, int numero);
nodoArbol* arbolBorrar(nodoArbol* arbol);

int arbolNodoEsGrado1(nodoArbol * arbol);
int arbolAltura(nodoArbol* arbol);
int arbolMayor(int izq, int der);
nodoArbol* arbolNodoMasIzq(nodoArbol* arbol);
nodoArbol* arbolNodoMasDer(nodoArbol* arbol);
int arbolContarHojas(nodoArbol* arbol);
int arbolNodoEsHoja(nodoArbol* arbol);

int arbolContarNodos2(nodoArbol* arbol);
int arbolContarNodos(nodoArbol* arbol);
int arbolSumarNumeros3(nodoArbol* arbol);
int arbolSumarNumeros2(nodoArbol* arbol);
int arbolSumarNumeros(nodoArbol* arbol);

nodoArbol* arbolBuscarPorPalabra(nodoArbol* arbol, char palabra[]);
nodoArbol* arbolBuscarPorNumero(nodoArbol* arbol, int numero);

nodoArbol* arbolAgregarVariosOrdenandoPorPalabra(nodoArbol* arbol, int cant);
nodoArbol* arbolAgregarUnoOrdenandoPorPalabra(nodoArbol* arbol, nodoArbol* nuevoNodo);
nodoArbol* arbolAgregarVariosOrdenandoPorNumero(nodoArbol* arbol, int cant);
nodoArbol* arbolAgregarUnoOrdenandoPorNumero(nodoArbol* arbol, nodoArbol* nuevoNodo);

void arbolMostrarPostOrder(nodoArbol* arbol);
void arbolMostrarInOrder(nodoArbol* arbol);
void arbolMostrarPreOrder(nodoArbol* arbol);
int _print_t(nodoArbol *tree, int is_left, int offset, int depth, char s[20][255]);
void arbolDibujar(nodoArbol *tree);

nodoArbol* arbolNodoCrear(Struc dato);
nodoArbol* arbolInic();
void pruebaArbol();


///-------------inicio borrar en proyecto C-------------

void archivoMostrar(char archivo[]);

nodoS* LSPSagregarUnoPpio(nodoS* lista, nodoS* nuevoNodo);
void LSPSmostrar(nodoS* lista);
nodoS* LSPScrearNodo(Struc dato);
nodoS* LSPSinic();

void strucMostrar(Struc dato);
Struc strucCargarAMano();
Struc strucCargarAuto();
char charRandom();
///-------------fin borrar en proyecto C-------------


#endif // ABB_H_INCLUDED
