#ifndef MATRICESINT_H_INCLUDED
#define MATRICESINT_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


float matrizIntPromedio(int fil, int col, int A[fil][col]); //siempre encabezar las float
void pruebaMatrices();
void matrizIntCargarMano(int fil, int col, int A[fil][col]);
void matrizIntCargarRand(int fil, int col, int A[fil][col]);
void matrizIntMostrar(int fil,int col,int A[fil][col]);
int matrizIntSumar(int fil, int col, int A[fil][col]);
float matrizIntPromedio(int fil, int col, int A[fil][col]);
int matrizIntBuscar(int fil, int col, int A[fil][col],int dato);
int matrizIntMax(int fil, int col,int A[fil][col]);
int matrizIntMaxDeFila(int fil, int col,int A[fil][col],int dato);


#endif // MATRICESINT_H_INCLUDED
