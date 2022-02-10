#ifndef MATRICESCHAR_H_INCLUDED
#define MATRICESCHAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void pruebaMatricesChar();
int matrizCharCargarMano(int fil,int col, char A[fil][col]);
int matrizCharCargarRand(int fil, int col, char A[fil][col], int cant);
void matrizCharMostrar(int fil,int col,char A[fil][col],int validos);
int matrizCharBuscar(int fil,int col,char A[fil][col],int validos,char dato[]);
int matrizCharOrdenarSeleccionAux(int fil, int col, char A[fil][col], int validos,int pos);
void matrizCharOrdenarSeleccion(int fil,int col,char A[fil][col],int validos);
void matrizCharOrdenarInsercionAux(int fil, int col, char A[fil][col],int validos, char dato[]);
void matrizCharOrdenarInsercion(int fil,int col,char A[fil][col],int validos);
int matrizCharInsertarEnOrden(int fil, int col, char A[fil][col],int validos, char dato[]);


#endif // MATRICESCHAR_H_INCLUDED
