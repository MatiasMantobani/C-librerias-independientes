#ifndef BASICAS_H_INCLUDED
#define BASICAS_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


// recursion
int factorialRecursionImplicita(int num);
int factorialRecursionExplicita(int num);
int potenciaRecursionImplicita(int base,int exp);
int potenciaRecursionExplicita(int base, int exp);

// int
int intFactorial(int num);
int intPotencia(int base,int exp);
void intDivisores(int num);
void intMayorDe3(int num1, int num2, int num3);
int intEsPar(int num);
void intIntercambiar(int *a,int *b);
int validarEdad(int edad);
int intRandomEntreMinYMax(int min, int max);
int intRandom0A9();
int intRandom0A99();
int intRandom0A999();
int intCambiarSigno(int num);

// float
float floatRandomDecimal();
float floatRandomEnteroYDecimal();

// char
char charRandom();

void pruebaBasicas();


#endif // BASICAS_H_INCLUDED
