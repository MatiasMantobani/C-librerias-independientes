#include "pilasInt.h"


// pila struc - ordenar por insercion
void pilaIntOrdenarPorInsercion(struct Pila pila)
{
    struct Pila aux;
    pilaIntInic(&aux);

    if (!pilaIntVacia(&pila))
        pilaIntApilar(&aux, pilaIntDesapilar(&pila));
    while(!pilaIntVacia(&pila))
    {
        pilaIntInsertarOrdenadamente(&aux, pilaIntDesapilar(&pila));
    }
    while(!pilaIntVacia(&aux))
    {
        pilaIntApilar(&pila,pilaIntDesapilar(&aux));
    }
}


// pila struc - cambiar pila a valores 0 - sin puntero
void pilaIntResetear(struct Pila pila)
{
    int cant = 0;
    while(!pilaIntVacia(&pila))
    {
        pilaIntDesapilar(&pila);
        cant++;
    }

    for (int i=0; i<cant; i++)
    {
        pilaIntApilar(&pila,0);
    }
}


// pila struc - mostrar - sin puntero
void pilaIntMostrar2(struct Pila pila)
{
    struct Pila aux;
    pilaIntInic(&aux);

    while(!pilaIntVacia(&pila))  //para mostrar en orden correcto
    {
        pilaIntApilar(&aux,pilaIntDesapilar(&pila));
    }

    printf("\n");

    while(!pilaIntVacia(&aux))
    {
        printf("%i  ",pilaIntDesapilar(&aux));
    }
    printf("\n");
}


// pila struc - intercalar las 2 pilas
void pilaIntIntercalar(struct Pila* pila1,struct Pila* pila2)
{
    struct Pila aux;
    pilaIntInic(&aux);

    while(!pilaIntVacia(pila1) && !pilaIntVacia(pila2))
    {
        pilaIntApilar(&aux,pilaIntDesapilar(pila1));
        pilaIntApilar(&aux,pilaIntDesapilar(pila2));
    }

    while(!pilaIntVacia(pila1))
    {
        pilaIntApilar(&aux,pilaIntDesapilar(pila1));
    }

    while(!pilaIntVacia(pila2))
    {
        pilaIntApilar(&aux,pilaIntDesapilar(pila2));
    }

    while(!pilaIntVacia(&aux))
    {
        pilaIntApilar(pila1,pilaIntDesapilar(&aux));
    }
}


// pila struc - unir 2 pilas en 1
void pilaIntUnir(struct Pila* pila1,struct Pila* pila2)
{
    while(!pilaIntVacia(pila2))
    {
        pilaIntApilar(pila1,pilaIntDesapilar(pila2));
    }
}


// pila struc - chequear capicua con retorno 1 y 0
int pilaIntCapicua(struct Pila* pila)
{
    int rta = 1;
    struct Pila aux1;
    pilaIntInic(&aux1);

    struct Pila aux2;
    pilaIntInic(&aux2);

    struct Pila aux3;
    pilaIntInic(&aux3);

    int valor;

    //separo en 2 pilas los valores de DADA
    while(!pilaIntVacia(pila))
    {
        valor = pilaIntDesapilar(pila);
        pilaIntApilar(&aux1,valor);
        pilaIntApilar(&aux2,valor);
        pilaIntApilar(&aux3,valor);
    }

    //vuelvo a pasar a aux3 valores originales, para que quede la original y vuelvo a pasar a pila para no perder pila original
    while(!pilaIntVacia(&aux2))
    {
        valor = pilaIntDesapilar(&aux2);
        pilaIntApilar(&aux3,valor);
        pilaIntApilar(pila,valor);

    }

    //comparo valores de DADA con AUX para chequear si es capicua
    while( (!pilaIntVacia(&aux1)) && (!pilaIntVacia(&aux3)) && rta == 1)
    {
        if( pilaIntTope(&aux1) != pilaIntTope(&aux3) )
        {
            rta = 0;
        }
        pilaIntDesapilar(&aux1);
        pilaIntDesapilar(&aux3);
    }
    return rta;
}


// pila struc - borrar por numero
void pilaIntBorrarPorNumero(struct Pila* pila, int dato)
{
    struct Pila aux;
    pilaIntInic(&aux);

    int flag=0;
    while(!pilaIntVacia(pila) && flag==0)
    {
        if(pilaIntTope(pila) == dato)
        {
            flag = 1;
            pilaIntDesapilar(pila);
        }
        else
        {
            pilaIntApilar(&aux,pilaIntDesapilar(pila));
        }
    }
    while(!pilaIntVacia(&aux))
    {
        pilaIntApilar(pila,pilaIntDesapilar(&aux));
    }
}


// pila struc - buscar con retorno 1 o 0
int pilaIntExiste(struct Pila* pila, int dato)
{
    struct Pila aux;
    pilaIntInic(&aux);

    int flag=0;
    while(!pilaIntVacia(pila) && flag==0)
    {
        if(pilaIntTope(pila) == dato)
        {
            flag = 1;
        }
        else
        {
            pilaIntApilar(&aux,pilaIntDesapilar(pila));
        }
    }
    while(!pilaIntVacia(&aux))
    {
        pilaIntApilar(pila,pilaIntDesapilar(&aux));
    }
    return flag;
}


// pila struc - insertar ordenadamente valor por parametro
void pilaIntInsertarOrdenadamente(struct Pila* pila, int dato)
{
    struct Pila aux;
    pilaIntInic(&aux);

    //SE ABRE EL SANGUCHITO
    while(!pilaIntVacia(pila) && pilaIntTope(pila) < dato)
    {
        pilaIntApilar(&aux,pilaIntDesapilar(pila));
    }

    //SE AGREGA EL RELLENO
    pilaIntApilar(pila,dato);

    //SE CIERRA EL SANGUCHITO
    while(!pilaIntVacia(&aux))
    {
        pilaIntApilar(pila,pilaIntDesapilar(&aux));
    }
}


// pila struc - ordenar pila
void pilaIntOrdenarPorSeleccion(struct Pila* pila)
{
    struct Pila aux;
    pilaIntInic(&aux);

    while(!pilaIntVacia(pila))
    {
        pilaIntApilar(&aux,pilaIntDesvincularMenor(pila));    //cambiar a desvincular mayor para orden inverso
    }
    while(!pilaIntVacia(&aux))
    {
        pilaIntApilar(pila,pilaIntDesapilar(&aux));
    }
}


// pila struc - devolver menor elemento y desvincularlo de la pila
int pilaIntDesvincularMenor(struct Pila* pila)
{
    struct Pila aux;
    pilaIntInic(&aux);

    int menor = pilaIntDesapilar(pila);  //primer menor arbitrario

    while(!pilaIntVacia(pila))
    {
        int valor = pilaIntDesapilar(pila);

        if(valor < menor)   //cambiar desigualdad para desvincular mayor
        {
            pilaIntApilar(&aux,menor);
            menor = valor;
        }
        else
        {
            pilaIntApilar(&aux,valor);
        }
    }
    while(!pilaIntVacia(&aux))   //rearmo pila
    {
        pilaIntApilar(pila,pilaIntDesapilar(&aux));
    }
    return menor;
}


// pila struc - devolver menor elemento
int pilaIntMenor(struct Pila* pila)
{
    struct Pila aux;
    pilaIntInic(&aux);

    int menor = pilaIntDesapilar(pila);  //valor menor inicial
    pilaIntApilar(&aux,menor);

    while(!pilaIntVacia(pila))
    {
        int valor = pilaIntDesapilar(pila);

        if(valor < menor)   //cambiar desigualdad para devolver mayor
        {
            menor = valor;
        }
        pilaIntApilar(&aux,valor);
    }
    while(!pilaIntVacia(&aux))
    {
        pilaIntApilar(pila,pilaIntDesapilar(&aux));
    }
    return menor;
}


// pila struc - devovler suma de valores de pila
int pilaIntSumar(struct Pila* pila)
{
    int suma = 0;
    struct Pila aux;
    pilaIntInic(&aux);

    while(!pilaIntVacia(pila))
    {
        int valor = pilaIntDesapilar(pila);
        suma += valor;
        pilaIntApilar(&aux,valor);
    }
    while(!pilaIntVacia(&aux))
    {
        pilaIntApilar(pila,pilaIntDesapilar(&aux));
    }
    return suma;
}


// pila struc - eliminar repetidos
void pilaIntEliminarPorNumero(struct Pila* pila, int dato)
{
    struct Pila aux;
    pilaIntInic(&aux);
    int counter=0;

    while(!pilaIntVacia(pila))
    {
        if(pilaIntTope(pila) == dato)
        {
            pilaIntDesapilar(pila);
            counter++;
        }
        else
        {
            pilaIntApilar(&aux,pilaIntDesapilar(pila));
        }
    }
    while(!pilaIntVacia(&aux))
    {
        pilaIntApilar(pila,pilaIntDesapilar(&aux));
    }
    printf("\nCant eliminados : %i\n",counter);
}


// pila struc - son completamente iguales - metodo destructivo
void pilaIntIguales(struct Pila* A,struct Pila* B)
{
    while( !pilaIntVacia(A) && !pilaIntVacia(B) && pilaIntTope(A)==pilaIntTope(B) )
    {
        pilaIntDesapilar(A);
        pilaIntDesapilar(B);
    }

    if(pilaIntVacia(A) && pilaIntVacia(B))
    {
        printf("\nLas pilas son iguales");
    }
    else
    {
        printf("\nLas pilas son diferentes");
    }

}


// pila struc - contar cantidad de elementos
int pilaIntContarElementos(struct Pila* pila)
{
    struct Pila aux;
    pilaIntInic(&aux);
    int counter=0;

    while(!pilaIntVacia(pila))
    {
        pilaIntApilar(&aux,pilaIntDesapilar(pila));
        counter++;
    }

    while(!pilaIntVacia(&aux))
    {
        pilaIntApilar(pila,pilaIntDesapilar(&aux));
    }

    return counter;
}


// pila struc - base a tope
void pilaIntBaseATope(struct Pila* pila)
{
    struct Pila aux;
    pilaIntInic(&aux);

    while (!pilaIntVacia(pila))
    {
        pilaIntApilar(&aux,pilaIntDesapilar(pila));
    }

    int baseActual = pilaIntDesapilar(&aux);

    while (!pilaIntVacia(&aux))
    {
        pilaIntApilar(pila,pilaIntDesapilar(&aux));
    }
    pilaIntApilar(pila,baseActual);
}


// pila struc - tope a base
void pilaIntTopeABase(struct Pila* pila)
{
    struct Pila aux;
    pilaIntInic(&aux);

    int topeActual = pilaIntDesapilar(pila);

    while (!pilaIntVacia(pila))
    {
        pilaIntApilar(&aux,pilaIntDesapilar(pila));
    }

    pilaIntApilar(pila,topeActual);

    while (!pilaIntVacia(&aux))
    {
        pilaIntApilar(pila,pilaIntDesapilar(&aux));
    }
}


// pila struc - invertir
void pilaIntInvertir(struct Pila* pila)
{
    struct Pila aux;
    pilaIntInic(&aux);

    struct Pila aux2;
    pilaIntInic(&aux2);


    while (!pilaIntVacia(pila))
    {
        pilaIntApilar(&aux,pilaIntDesapilar(pila));
    }

    while (!pilaIntVacia(&aux))
    {
        pilaIntApilar(&aux2,pilaIntDesapilar(&aux));
    }

    while (!pilaIntVacia(&aux2))
    {
        pilaIntApilar(pila,pilaIntDesapilar(&aux2));
    }
}


// pila struc - pasar menores a numero parametro
void pilaIntPasarMenores(struct Pila* pila1, struct Pila* pila2, int dato)
{
    struct Pila aux;
    pilaIntInic(&aux);

    while (!pilaIntVacia(pila1))
    {
        if(pilaIntTope(pila1) <= dato)
        {
            pilaIntApilar(pila2,pilaIntDesapilar(pila1));
        }
        else
        {
            pilaIntApilar(&aux,pilaIntDesapilar(pila1));
        }
    }
    while (!pilaIntVacia(&aux))
    {
        pilaIntApilar(pila1,pilaIntDesapilar(&aux));
    }
}


// pila struc - copiar pila
void pilaIntCopiar(struct Pila* pila, struct Pila* pila2)
{
    int aux;

    struct Pila pilaAux1;
    pilaIntInic(&pilaAux1);

    struct Pila pilaAux2;
    pilaIntInic(&pilaAux2);

    while (!pilaIntVacia(pila))
    {
        aux = pilaIntDesapilar(pila);
        pilaIntApilar(&pilaAux1,aux);
        pilaIntApilar(&pilaAux2,aux);
    }

    while (!pilaIntVacia(&pilaAux1))
    {
        pilaIntApilar(pila,pilaIntDesapilar(&pilaAux1));
        pilaIntApilar(pila2,pilaIntDesapilar(&pilaAux2));
    }
}


// pila struc - apilar varios auto
void pilaIntApilarVarios(struct Pila* pila, int cant)
{
    for (int i=0; i<cant; i++)
    {
        pilaIntApilar(pila,rand()%10);
    }
}


// pila struc - inicializar pila
void pilaIntInic(struct Pila* pila)
{
    int *aux;
    aux = (int*)malloc(50*sizeof(int));  //max 50 valores en pila
    pila->valores = aux;
    pila->postope = 0;
}


// pila struc - apilar en pila
void pilaIntApilar(struct Pila* pila, int dato)
{
    int index = (*pila).postope;
    (*pila).valores[index] = dato;
    (*pila).postope = (*pila).postope + 1;
}


// pila struc - mostrar
void pilaIntMostrar(struct Pila* pila)
{
    int i;
    printf("\nBase .............................................. Tope\n\n");
    for(i=0; i < pila->postope; i++)
        printf("| %d ", pila->valores[i]);
    printf("\n\nBase .............................................. Tope\n");
}


// pila struc - devolver tope
int pilaIntTope(struct Pila* pila)
{
    return pila->valores[pila->postope - 1];
}


// pila struc - borrar y devolver tope
int pilaIntDesapilar(struct Pila* pila)
{
    int z = pila->valores[pila->postope -1];
    pila->postope--;
    return z;
}


// pila struc - cargar a mano
void pilaIntLeer (struct Pila* pila)
{
    int aux = 0;
    if (pila->postope < 50)
    {
        printf("Ingrese un valor entero: ");
        fflush(stdin);
        scanf("%d", &aux);
        pilaIntApilar(pila, aux);
    }
    else
        printf("Error: la pila esta llena");
}


// pila struc - pila vacia
int pilaIntVacia(struct Pila* pila)
{
    return (pila->postope == 0);
}


// pilas - prueba
void pruebaPilasInt()
{
    printf("\npilasStruc : ok\n");
}
