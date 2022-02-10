#ifndef PILASINT_H_INCLUDED
#define PILASINT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Pilita struct Pila* //enmascaramiento (no implementado)

struct Pila
{
    int *valores;
    int postope;
};

void pilaIntOrdenarPorInsercion(struct Pila pila);
void pilaIntResetear(struct Pila pila);
void pilaIntMostrar2(struct Pila pila);

void pilaIntIntercalar(struct Pila* pila1,struct Pila* pila2);
void pilaIntUnir(struct Pila* pila1,struct Pila* pila2);
int pilaIntCapicua(struct Pila* pila);
void pilaIntBorrarPorNumero(struct Pila* pila, int dato);
int pilaIntExiste(struct Pila* pila, int dato);
void pilaIntInsertarOrdenadamente(struct Pila* pila, int dato);
void pilaIntOrdenarPorSeleccion(struct Pila* pila);
int pilaIntDesvincularMenor(struct Pila* pila);
int pilaIntMenor(struct Pila* pila);
int pilaIntSumar(struct Pila* pila);

void pilaIntIguales(struct Pila* A,struct Pila* B);
void pilaIntEliminarPorNumero(struct Pila* pila, int dato);
int pilaIntContarElementos(struct Pila* pila);
void pilaIntBaseATope(struct Pila* pila);
void pilaIntTopeABase(struct Pila* pila);
void pilaIntInvertir(struct Pila* pila);
void pilaIntPasarMenores(struct Pila* pila1, struct Pila* pila2, int dato);
void pilaIntCopiar(struct Pila* pila, struct Pila* pila2);
void pilaIntApilarVarios(struct Pila* pila, int cant);

int pilaIntVacia(struct Pila* pila);
void pilaIntLeer (struct Pila* pila);
int pilaIntTope(struct Pila* pila);
int pilaIntDesapilar(struct Pila* pila);
void pilaIntMostrar(struct Pila* pila);
void pilaIntApilar(struct Pila* pila, int dato);
void pilaIntInic(struct Pila* pila);

void pruebaPilasInt();

#endif // PILASINT_H_INCLUDED
