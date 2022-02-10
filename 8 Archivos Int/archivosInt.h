#ifndef ARCHIVOSINT_H_INCLUDED
#define ARCHIVOSINT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int archivoIntContarRegistros(char fileName[]);
void archivoIntMostrar(char archivo[]);
void archivoIntCargarVariosAuto(char archivo[], int cant);
void pruebaArchivosInt();

//recursion
void archivoIntInvertirRecursionImplicita(FILE * FP,int cantidad,int i);
int archivoIntMenorRecursionExplicita(FILE *arch);
void archivoIntMostrarRecursionExplicita(FILE* archivo);
void archivoIntMostrarRecursionImplicita(FILE* archivo);


#endif // ARCHIVOSINT_H_INCLUDED
