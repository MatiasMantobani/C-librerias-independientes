#ifndef ARREGLOSCHAR_H_INCLUDED
#define ARREGLOSCHAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>
#include <time.h>


char charRandom();  //borrar en proyecto C

void pruebaArreglosChar();

int arregloCharCargarLetrasAMano(char A[],int dimension);
void arregloCharMostrar(char C[],int validos);
int arregloCharCargarPalabraAMano(char A[],int dimension);
int arregloCharCargarLetrasAuto(char A[],int dimension, int cant);
int arregloCharCargarPalabraAuto(char A[],int dimension);
int arregloCharBuscar(char C[],int validos,char dato);
char arregloCharMenor(char C[], int validos);
char arregloCharMayor(char C[], int validos);
void arregloCharInvertir(char C[],int validos);
int arregloCharCapicua(char C[], int validos);
void arregloCharInsertar(char C[], int validos,char dato);
int arregloCharCargarLetrasAutoOrdenadas(char A[],int dimension, int cant);
void arregloCharFunciones();


#endif // ARREGLOSCHAR_H_INCLUDED
