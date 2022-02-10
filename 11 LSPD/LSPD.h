#ifndef LSPD_H_INCLUDED
#define LSPD_H_INCLUDED

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
/// ------------fin borrar al pasar a proyecto C----------------------------------


typedef struct nodoS
{
    Struc dato;
    struct nodoS* siguiente;
}nodoS;


void LSPDinvertir(nodoS** lista);

void LSPDborrarIgualesANumero(nodoS** lista, int dato);
Struc LSPDborrarYretornarStrucPorNumero(nodoS** lista, int dato);
void LSPDborrarPrimerNodo (nodoS** lista);
nodoS* LSPDdesvincularYretornarPrimerNodo(nodoS ** lista);
void LSPDborrarLista(nodoS** lista);
void LSPDborrarPorNumero(nodoS** lista, int dato);

void LSPDultimo(nodoS** lista, nodoS** ultimo);
void LSPDmostrarNodoPorNumero(nodoS** lista, int dato);

void LSPDagregarVariosOrdenadamenteAuto(nodoS** lista, int cant);
void LSPDagregarUnoOrdenadamentePorNumero(nodoS** lista, nodoS* nuevoNodo);
void LSPDagregarVariosFinalAuto(nodoS** lista, int cant);
void LSPDagregarVariosPpioAuto(nodoS** lista, int cant);
void LSPDagregarUnoFinal(nodoS** lista, nodoS* nuevoNodo);
void LSPDagregarUnoPpio(nodoS** lista , nodoS* nuevoNodo);

void LSPDcrearNodo(Struc dato, nodoS** aux);
void LSPDinic(nodoS** lista);

void pruebaLSPS();


/// ------------inicio borrar al pasar a proyecto C----------------------------------
void LSPSmostrar(nodoS* lista);
Struc strucCargarAuto();
void strucMostrar(Struc dato);
/// ------------fin borrar al pasar a proyecto C----------------------------------



#endif // LSPD_H_INCLUDED
