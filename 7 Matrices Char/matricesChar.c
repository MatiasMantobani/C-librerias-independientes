#include "matricesChar.h"


// matriz char - insertar en orden
int matrizCharInsertarEnOrden(int fil, int col, char A[fil][col],int validos, char dato[])
{
    if(validos == fil)
    {
        printf("\nError: Dimension insuficiente para agregar\n");
    }
    else
    {
        int i=validos-1;
        while(i>=0 && strcmpi(A[i],dato) > 0)
        {
            strcpy(A[i+1],A[i]);
            i--;
        }
        strcpy(A[i+1],dato);
        validos++;
    }
    return validos;
}


// matriz char - Ordenar por insercion
void matrizCharOrdenarInsercion(int fil,int col,char A[fil][col],int validos)
{
   int i=1;
   while(i<validos-1)
    {
    matrizCharOrdenarInsercionAux(fil,col,A,i,A[i+1]);
    i++;
    }
}


// matriz char - ordenar por insercion - aux
void matrizCharOrdenarInsercionAux(int fil, int col, char A[fil][col],int validos, char dato[])
{
    char aux[col]; //si no hago esto se pisan los datos
    strcpy(aux, dato);

    int i=validos;
    while(i>=0 && strcmpi(A[i],aux)>0)
    {
        strcpy(A[i+1],A[i]);
        i--;
    }
    strcpy(A[i+1],aux);
}



// matriz char - ordenar por seleccion
void matrizCharOrdenarSeleccion(int fil,int col,char A[fil][col],int validos)
{
    int posMenor;
    char aux[col];
    for(int i=0; i<fil && i<validos-1; i++)
    {
        posMenor=matrizCharOrdenarSeleccionAux(fil,col,A,validos,i);
        strcpy(aux,A[i]);
        strcpy(A[i],A[posMenor]);
        strcpy(A[posMenor],aux);
    }
}


// matriz char - Ordenar por seleccion - aux
int matrizCharOrdenarSeleccionAux(int fil, int col, char A[fil][col], int validos,int pos)
{
    char menor[col];
    strcpy(menor,A[pos]);

    int posMenor=pos;
    int comp;

    for(int i=pos; i<validos && i<fil; i++)
    {
        comp=strcmp(A[i],menor);
        if(comp<0)  //cambiar para ordenar al reves
        {
            posMenor=i;
            strcpy(menor,A[i]);
        }
    }
    return posMenor;
}


// matriz char - buscar palabra
int matrizCharBuscar(int fil,int col,char A[fil][col],int validos,char dato[])
{
    int i = 0;
    int rta=0;
    int comparacion;

    while(i<fil && i<validos && rta!=1)
    {
        comparacion=strcmpi(dato,A[i]);
        if(comparacion==0)
        {
            rta = 1;
        }
        i++;
    }
    return rta;
}


// matriz char - mostrar
void matrizCharMostrar(int fil,int col,char A[fil][col],int validos)
{
    if(validos==0)
    {
        printf("\nMatriz vacia!\n");
    }
    else
    {
        printf("\n");
        for(int i=0; i<fil && i<validos; i++)
        {
            puts(A[i]);
        }
    }
}


// matriz char - cargar palabras auto
int matrizCharCargarRand(int fil, int col, char A[fil][col], int cant)
{
    int validos=0;

    if(cant > fil)
    {
        printf("\nError: cant > fil. No se cargara la matriz\n");
    }
    else
    {
        char nombres[26][20]= {"Hilberto Hil","El negro","Alvaro","Guada","Isla remota","Junior","Cleo","Dylan","Beto","Fran","Karen","La Sheni","Manicho","Naricitas","Osvaldo","Zulu hip hop","Quesito","Rastaman","Sushi","Tutan kamon","Uvita","Vino","Waka waka","Xilofon","YIFY","Pancito Relleno"};
        char nombre[30];
        while(validos < cant)
        {
            strcpy(nombre,nombres[rand()%26]);  //random() --> nombre

            if(strlen(nombre) > col)
            {
                printf("\nError: nombre > col. No se cargara la matriz\n");
                return 0;
            }
            else
            {
                strcpy(A[validos],nombre);
                validos++;
            }
        }
    }
    return validos;
}


// matriz char - cargar a mano por palabra
int matrizCharCargarMano(int fil,int col, char A[fil][col])
{
    int validos = 0;
    char control='s';
    int largoPalabra;

    while(validos<fil && control=='s')
    {
        printf("\nIngrese palabra a cargar en la matriz\n");
        char palabra[100];
        fflush(stdin);
        gets(palabra);
        largoPalabra = strlen(palabra);

        while(largoPalabra>col)  //palabra muy larga
        {
            printf("\nLa palabra es muy larga, ingrese otra\n");
            fflush(stdin);
            gets(palabra);
            largoPalabra = strlen(palabra);
        }

        strcpy(A[validos],palabra);
        validos++;

        printf("Cargar otra palabra? (s/n)");
        control=getchar();

        if(validos==fil)  //aviso cant>dim
        {
            if(control=='s')
            {
                printf("\nError: Cant > dimension . No se seguira cargando\n");
                system("pause");
            }
        }
    }
    return validos;
}


void pruebaMatricesChar()
{
    printf("\nmatrices char : ok\n");
}
