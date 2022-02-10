#ifndef ARCHIVOSSTRUC_H_INCLUDED
#define ARCHIVOSSTRUC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// ---------------------- Borrar al pasar a proyecto C
typedef struct {
int numero;
char letra;
char palabra[30];
}Struc;

void arregloStrucMostrar(Struc A[],int validos);
Struc strucCargarAMano();
Struc strucCargarAuto();
void strucMostrar(Struc dato);
char charRandom();
// ----------------------


int archivoContarRegistros(char fileName[]);

void archivoModificarPorNumeroAuto(char archivo[], int dato);
void archivoModificarPorNumeroCampoNumero(char archivo[], int dato);
void archivoModificarPorPosAuto(char fileName[], int dato);
void archivoModificarPorPosCampoNumeroAMano(char fileName[], int dato);

int archivoToArreglo(char fileName[], Struc A[], int dimension);
int archivoToArregloPorNumero(char fileName[], Struc A[], int dimension, int dato);
void arregloToArchivo(char fileName[],Struc A[],int validos);

void archivoMostrarPorPos(char fileName[],int dato);
void archivoMostrarPorNumero(char fileName[], int dato);
int archivoMostrarPorPalabra(char fileName[], char dato[]);
void archivoMostrar(char archivo[]);

void archivoCargarUnoAuto(char archivo[]);
void archivoCargarUnoAMano(char archivo[]);
void archivoCargarVariosAuto(char nombreArchivo[], int cant);

void pruebaArchivosStruc();


#endif // ARCHIVOSSTRUC_H_INCLUDED
