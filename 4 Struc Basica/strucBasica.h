#ifndef STRUCBASICA_H_INCLUDED
#define STRUCBASICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct
{
    int numero;
    char letra;
    char palabra[30];
}Struc;


void strucMostrar(Struc dato);

void strucCargarVarias2(int cant, int *contador);
void strucCargarVarias(int cant);
Struc strucCargarAuto2(int *i);
Struc strucCargarAMano();
Struc strucCargarAuto();

void pruebaStrucBasica();

char charRandom();  //borrar al pasar a proyectoC


#endif // STRUCBASICA_H_INCLUDED
