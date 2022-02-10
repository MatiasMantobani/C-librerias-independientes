#ifndef ARREGLOSSTRUC_H_INCLUDED
#define ARREGLOSSTRUC_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


///inicio borrar en proyecto C

typedef struct {
int numero;
char letra;
char palabra[30];
}Struc;

char charRandom();
Struc strucCargarAMano();
Struc strucCargarAuto();
void strucMostrar(Struc dato);

///fin borrar en proyecto C

void arregloStrucMostrarRecursivamente(Struc A[], int validos, int i);

void pruebaArreglosStruc();
int arregloStrucCargarAMano(Struc A[], int dimension);
int arregloStrucCargarAuto(Struc A[],int dimension,int cant);

void arregloStrucMostrar(Struc A[],int validos);
void arregloStrucMostrarPorLetra(Struc A[], int validos, char dato);
void arregloStrucMostrarPorId(Struc A[], int validos, int dato);

int arregloStrucContarPorLetra(Struc A[], int validos, char dato);
int arregloStrucPasarPorLetra(Struc A[],int validos, char letra,Struc B[],int dimensionB);

int arregloStrucOrdenarSeleccionAuxPorLetra(Struc A[], int validos, int pos);
int arregloStrucOrdenarSeleccionAuxPorNumero(Struc A[], int validos, int pos);
int arregloStrucOrdenarSeleccionAuxPorPalabra(Struc A[], int validos, int pos);
void arregloStrucOrdenarSeleccion(Struc A[], int validos);

void arregloStrucOrdenarInsercionAuxPorNumero(Struc A[], int pos, Struc dato);
void arregloStrucOrdenarInsercionAuxPorPalabra(Struc A[], int pos, Struc dato);
void arregloStrucOrdenarInsercion(Struc A[],int validos);
int arregloStrucInsertarEnOrdenPorNumero(Struc A[],int validos, int dimension, Struc dato);

int arregloStrucBorrarPorIndice(Struc A[], int validos, int dato);




#endif // ARREGLOSSTRUC_H_INCLUDED
