#ifndef ARREGLOSINT_H_INCLUDED
#define ARREGLOSINT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dinamicoCargarRandoms(int** arreglo, int cant);

void arregloIntDinamico(int cuantos);
void arregloIntOrdenarInsercionAux(int A[],int pos, int dato);
int arregloIntInsertarEnOrden(int A[], int validos, int dato);
int arregloIntMerge(int A[],int validosA,int B[],int validosB,int C[]);
void arregloIntOrdenarInsercion(int A[],int validos);
int arregloIntOrdenarSeleccionAux(int A[], int validosA, int pos);
void arregloIntOrdenarSeleccion (int A[], int validos);
long int armarNumero(int A[],int validos);
int arregloIntBorrarPorIndice(int A[], int validos, int indiceBorrar);
int arregloIntEsCapicua(int A[], int validos);
void arregloIntInvertir(int A[],int validos);
int arregloIntMenorValor(int A[], int validos);
int arregloIntPosMenor(int A[], int validosA, int pos);
int arregloIntMenorPos(int A[], int validos);
int arregloIntMayorValor(int A[], int validos);
int arregloIntMayorPos(int A[], int validos);
float arregloIntPromedio(int A[],int validos);
int ArregloIntSumar(int A[],int validos);
int arregloIntCargarRandEntreMinYMax(int A[],int dimension,int cant, int min, int max);
void arregloIntMostrar(int A[],int validos);
int arregloIntCargarRandOrdenados(int A[],int dimension,int cant);
int arregloIntCargarRand(int A[],int dimension,int cant);
int arregloIntCargarAMano(int A[], int dimension);
void arregloIntInicializar(int A[], int dimension);
void pruebaArreglosInt();

//recursion
void arregloIntMostrarRecursionImplicita(int A[],int validos,int i);
void arregloIntMostrarRecursionExplicita(int A[],int validos,int i);
int arregloIntPosMenorRecursionImplicita(int Arr[],int Validos,int i,int PosMenor);
int arregloIntBuscarRecursionExplicita(int A[], int validos, int i, int valor);
int arregloIntSumarRecursionExplicita(int A[],int validos,int i);
int arregloIntSumarRecursionImplicita(int A[],int validos,int i);
int arregloIntMenorRecursionImplicita(int A[], int validos, int i, int menor);
int arregloIntMenorRecursionExplicita(int arr[], int validos, int i);
int arregloIntCapicuaRecursionExplicita(int A[],int validos,int i);
int arregloIntCapicuaRecursionImplicita(int A[],int validos,int i);




#endif // ARREGLOSINT_H_INCLUDED
