#include <stdio.h>
#include <stdlib.h>



/*
puntA: es el puntero y solo son dir mem
*puntA: es a lo que apunta el puntero(variables,arreglos,etc) y son los valores de dichos apuntados

Lo que modifica a punt cambia a donde apunta
Lo que modifica a *punt cambia el valor de donde esta apuntando el puntero

Al cambiar la asignacion del puntero a otra dir mem, se modificara el valor del puntero siendo este igual al valor de la dir mem asignada

Siendo x una variable:
punt=&x; -> asigna direccion de memoria de x
*punt=3; -> a donde apunta A le asigno el valor 3
*punt=x; -> a donde apunta A le asigno el valor de x
punt1=punt2 -> asigna al puntero 1 la  dir mem del puntero 2

Siendo A un arreglo
punt=A;     -> LOS ARREGLOS SON PUNTEROS entonces la asignacion se hace asi
            -> sinonimo de punt=&x;
            -> el puntero queda apuntando al primer indice del arreglo -> puntero en A[0]

punt=&A[i]; -> asigna el puntero a la dir mem del indice i del arreglo A

punt[3]=7;  -> Los punteros son como un arreglo dentro de otro arreglo
            -> punt[3] es el elemento corrido 3 veces de donde apunta actualmente el puntero
            -> punt[0] seria a donde apunta actualmente el puntero
            -> No cambia a donde apunta el puntero
            -> Asigna al indice 3 del "arreglo puntero" el valor 7

*(punt+3)=9; -> No cambia a donde apunta el puntero
             -> a donde apunta el puntero + 3 posiciones, le asigno el valor 9

punt--;     -> punt-- mueve el puntero a la izquierda y punt ++ mueve a derecha

*x=11;  -> asigna valor 11 al primer elemento del arreglo

*(A+3)=7 ; -> A la posicion inicial del puntero en el arreglo + 3 lugares hacia derecha (A[0]+3 = A[3]) le asigno el valor 7

Hay que prestar mucha atencion a que imprime el printf. Estos ejercicios estan hechos para que imprima el arreglo siempre pero a la hora de hacer pruebas con printf pueden pasar cosas raras

//1-7: Punteros y Variables --> usar metodo de dibujar las variables y los punteros y representar las asignaciones con flechas
//8-13: Punteros y Arrays --> usar mismo metodo pero dibujando los arreglos en vez de las variables
//13-19: Punteros y Funciones --> salen por intuicion
*/


void suma_dos(int *x, int *y, int *z);
void datos15(int *x, float *y, char *c);
void datos16(int *x, float *y, char *c);
void datos17(int x, float y, char c);
int datos18(int x, float y, char c);
char datos19(int *x, float *y, char *c);



int main()
{
    ///Punteros enteros
    int *punt;
    int *punt2;



    ///Variables enteras
    int x;
    int y;



    //1
    x=7;
    y=5;
    punt=&x;    //punt -->x
    *punt=4;    //*punt=4=x
    printf("1--> %d, %d\n",x,y); //4,5



    //2
    x=7;
    y=5;
    punt=&x;    //punt-->x
    x=4;        //x=4=*punt
    printf("2--> %d, %d\n",*punt,y); //4,5



    //3
    x=7;
    y=5;
    punt=&x;    //punt-->x
    x=4;        //x=4=*punt
    punt=&y;    //punt-->y
    printf("3--> %d, %d\n",*punt,x); // 5,4



    //4
    x=7;
    y=5;
    punt=&x;
    *punt=3;
    punt=&y;
    *punt=x;
    x=9;
    printf("4--> %d, %d\n",*punt,x); //3,9



    //5
    x=7;
    y=5;
    punt=&x;
    *punt=3;
    punt2=&y;
    *punt2=x;
    x=9;
    printf("5--> %d, %d\n",*punt2,x); // 3,9



    //6
    x=7;
    y=5;
    punt=&x;
    *punt=3;
    punt2=&y;
    *punt2=x;
    x=9;
    printf("6--> %d, %d\n",*punt2, *punt); //3,9



    //7
    x=7;
    y=5;
    punt=&x;
    *punt=3;
    punt2=&y;
    *punt2=x;
    x=9;
    punt2=punt;
    printf("7--> %d, %d\n",*punt2, y); // 9,3



    ///Arreglos enteros
    int i;
    int A[5]={1,2,3,4,5};



    //8
    printf("\n");
    punt=A;     //los arreglos(x en este caso) son punteros por definicion entonces la asignacion se hace asi y el puntero apunta al primer indice(0) del arreglo
    *punt=9;
    for(i=0;i<5;i++)
    printf("%d ",A[i]); //9,2,3,4,5



    //9
    printf("\n");
    punt=&A[0];
    *punt=9;
    punt[3]=7;
    for(i=0;i<5;i++)
    printf("%d ",A[i]); //9,2,3,7,5



    //10
    printf("\n");
    punt=A;
    *A=11;
    *(punt+3)=9 ;
    for(i=0;i<5;i++)
    printf("%d ",A[i]); //11,2,3,9,5



    //11
    printf("\n");
    punt=A;
    *(punt+2)=9;
    *(A+3)=7 ;  //x = puntero en inicio array
    punt[1]=11 ;
    for(i=0;i<5;i++)
    printf("%d ",*(punt+i)); //11,11,9,7,5



    //12
    printf("\n");
    punt=A+4;
    *(punt-2)=9;    //esto no corre el puntero, solo asigna a los que  estan a la izquierda o derecha
    punt--;     //-- izq y ++ derecha
    *(punt)=7 ;
    punt[1]=11 ;
    for(i=0;i<5;i++)
    printf("%d ",*(A+i)); //11,11,9,7,11



    //13
    printf("\n");
    punt=&A[0]+3;   //puntero en pos inicial + 3 -> punt=x+3 -> puntero en A[3]
    *(punt-2)=9;    //asigno SIN MOVER EL PUNTERO -> A[1]=9
    punt--;         //muevo el puntero 1 pos a la izq -> punt=x+2 -> puntero en A[2]
    *(punt)=7 ;     //asigno sin mover puntero -> A[2]=7
    punt[1]=11 ;    //asigno sin mover el puntero -> asigno a 1 pos a la derecha el 11 -> A[3]=11
    punt=A;         //vuelve a asignar el puntero al inicio del arreglo
    for(i=0;i<5;i++)
    printf("%d ",punt[i]); //11,9,7,11,11



    ///Funciones
    int z;


    //14
    x=3;
    y=10;
    z=15;
    suma_dos (&x, &y, &z);
    printf("\n14--> %d, %d, %d",x, y, z); //5,12,17



    int a=9;
    float b=44.6;
    char c='a';



    //15
    datos15 (&a, &b, &c);
    printf("\n15--> %d, %.2f, %c",a, b, c);   //8, 4.20, g          ea ;)



    //16
    datos16 (&a, &b, &c);
    printf("\n16--> %d, %.2f, %c",a, b, c);   //12 , 6.80 , i



//    17
    datos17 (a, b, c);  //no se pasaron como puntero, todo cambio en la funcion no se reflejara en las variables de main
    printf("\n17--> %d, %.2f, %c",a, b, c);    //12 , 6.80 , i



    //18
    x=datos18 (a, b, c);
    printf("\n18--> %d, %.2f, %c",a, b, c);   //12 , 6.80 , i



    //19
    c=datos19 (&a, &b, &c);
    printf("\n19--> %d, %.2f, %c",a, b, c);   //24, 45.01, h



    return 0;
}



//19
char datos19(int *x, float *y, char *c)
{
//printf("primera: %d %f %c\n",x, y, c);
    *x=24;
    *y=45.01;
    *c='t';
    return 'h' ;
}



//18
int datos18(int x, float y, char c)
{
//printf("primero: %d %f %c\n",x, y, c);
    x=20;
    y=33.17;
    c='w';
    return x;
}



//17
void datos17(int x, float y, char c)
{
//printf("primero: %d %.2f %c\n",x, y, c);  //si no prototipas te da cualquier cosa
    x=18;
    y=11.1;
    c='V';
}



//16
void datos16(int *x, float *y, char *c)
{

//printf("primero: %d %f %c\n",x, y, c);
    *x=12;
    *y=6.8;
    *c='i';
}



//15
void datos15(int *x, float *y, char *c)
{
    *x=8;
    *y=4.2;
    *c='g';
}



//14
void suma_dos(int *x, int *y, int *z)   //manera correcta de pasar, recibir y modificar por puntero
{
    *x=*x+2;
    *y=*y+2;
    *z=*z+2;
}

