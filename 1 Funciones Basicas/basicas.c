#include "basicas.h"



// recursion - potencia con base y exp - implicita
int potenciaRecursionImplicita(int base,int exp)
{
    int rta=1;      //sol trivial
    if(exp>0)       //cond corte
    {
        rta=base*potenciaRecursionImplicita(base,exp-1);     //recursion + acerc
    }
    return rta;
}


// recursion - potencia con base y exp - explicita
int potenciaRecursionExplicita(int base, int exp)
{
    int rta;
    if(exp==0)      //cond corte
    {
        rta=1;      //sol trivial
    }
    else
    {
        rta=base*potenciaRecursionExplicita(base,exp-1);    //recursion + acercamiento
    }
    return rta;
}


// recursion - factorial - implicita
int factorialRecursionImplicita(int num)
{
    int rta=1;  //sol trivial
    if(num>0)       //cond corte
    {
        rta=num*factorialRecursionImplicita(num-1);     //recursion + acercamiento
    }
    return rta;
}



// recursion - factorial - implicita
int factorialRecursionExplicita(int num)
{
    int rta;
    if(num==0)      //cond corte
    {
        rta=1;      //sol trivial
    }
    else
    {
        rta=num*factorialRecursionExplicita(num-1);     //recursion + cond corte
    }
    return rta;
}


// int - factorial de un numero
int intFactorial(int num)
{
    int rta=1;
    for (int i=num; i>=1; i--)
    {
        rta*=i;
    }
    return rta;
}


// int - imprime calculo de la base con su potencia
int intPotencia(int base,int exp)
{
    int rta;
    rta=pow(base,exp);
    return rta;
}

// int - imprime divisores del num
void intDivisores(int num)
{
    int counter=1;
    printf("\nLos divisores de %i son:\n",num);
    while(counter<=num){
        if(num%counter ==0){
            printf("%i\n",counter);
    }
    counter++;
    }
}

// int - mayor de 3 parametros int
void intMayorDe3(int num1, int num2, int num3)
{
   if(num1>num2 && num1> num3){
        printf("\nEl mayor es: %i",num1);
   }else if(num2>num1 && num2> num3){
        printf("\nEl mayor es: %i",num2);
   } else {
    printf("\nEl mayor es: %i",num3);
   }
}


// int - es par - devuelve 1 si es par
int intEsPar(int num)
{
    int rta=0;
    if(num%2 == 0){
        rta=1;
    }
    return rta;
}




// int - intercambiar 2 valores por puntero
void intIntercambiar(int *a,int *b)
{
    //pivoteo
    int aux=*a;
    *a=*b;
    *b=aux;
}


// int - validar edad (vive) - 1 para edad valida o 0 para invalida
int validarEdad(int edad)
{
    int rta=1;
    if(edad<=0 || edad>130)
    {
        rta=0;
    }
    return rta;
}



// int - random entre MIN y MAX
int intRandomEntreMinYMax(int min, int max)
{
    return rand() % (max + 1 - min) + min; //incluye al min y max
}



// int - random del 0 al 9
int intRandom0A9()
{
    return rand() % 10;
}


// int - random del 0 al 99
int intRandom0A99()
{
    return rand() % 100;
}


// int - random del 0 al 999
int intRandom0A999()
{
    return rand() % 1000;
}





// int - cambio de signo
int intCambiarSigno(int num)
{
    return num *= -1;
}



// float - random decimal - 0<x<1
float floatRandomDecimal()
{
    float decimal = (float)(rand() % 100) / 100;
    return decimal;
}



// float - random entero + decimal - 0<x<100
float floatRandomEnteroYDecimal()
{
    int entero = rand() % 100;
    float decimal = (float)(rand() % 100) / 100;
    float total = (float)entero+decimal;
    return total;
}




// char - letra random
char charRandom()
{
    char letras[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int cantLetras  = sizeof(letras)/sizeof(char);
    return letras[rand()%cantLetras];
}



void pruebaBasicas()
{
    printf("\nbasicas : ok\n");
}
