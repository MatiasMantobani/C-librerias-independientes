#include "matricesInt.h"


// matriz int - buscar mayor o menor por fila
int matrizIntMaxDeFila(int fil, int col,int A[fil][col],int dato)
{

    while(dato<1 || dato>fil)
    {
        printf("\nFila inexistente, ingrese denuevo\n");
        scanf("%i",&dato);
    }

    int max=A[dato-1][0];
//    int posMax=1;
    for (int j=0;j<col;j++){
        if(A[dato-1][j]>max){
            max=A[dato-1][j];
//            posMax=j+1;
        }
    }
    return max;
}


// matriz int - valor del mayor
int matrizIntMax(int fil, int col,int A[fil][col])
{
    int max=A[0][0];

//    int posFil=1;
//    int posCol=1;

    for(int i=0; i<fil; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(A[i][j]>max)         //cambiar por A[i][j]<max para que retorne el minimo
            {
                max=A[i][j];
//                posFil=i+1;
//                posCol=j+1;
            }
        }
    }
    return max;
}


// matriz int - buscar - retorna 1 si lo encuentra
int matrizIntBuscar(int fil, int col, int A[fil][col],int dato)
{
    for(int i=0; i<fil; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(dato==A[i][j])
            {
                return 1;
            }
        }
    }
    return 0;
}


// matriz int - promedio
float matrizIntPromedio(int fil, int col, int A[fil][col])
{
   int suma=matrizIntSumar(fil,col,A);
   int rango=fil*col;
   float promedio=(float)suma/(float)rango;
   return promedio;
}


// matriz int - sumar elementos
int matrizIntSumar(int fil, int col, int A[fil][col])
{
    int suma=0;
    for(int i=0; i<fil; i++)
    {
        for(int j=0; j<col; j++)
        {
            suma+=A[i][j];
        }
    }
    return suma;
}


// matriz int - mostrar
void matrizIntMostrar(int fil,int col,int A[fil][col])
{
    if(fil == 0 || col == 0)
    {
        printf("\nMatriz vacia!\n");
    }
    else
    {
        printf("\n");
        for(int i=0; i<fil; i++)
        {
            for(int j=0; j<col; j++)
            {
                printf("%2i  ",A[i][j]);    // El 2 de "%2i" te agrega espacios para que se vea lindo
            }
            printf("\n"); //separa filas
        }
    }
}


// matriz int - cargar con randoms
void matrizIntCargarRand(int fil, int col, int A[fil][col])
{
    for(int i=0; i<fil; i++)
    {
        for(int j=0; j<col; j++)
        {
            A[i][j]=rand()%10;
        }
    }
}


// matriz int - cargar a mano
void matrizIntCargarMano(int fil, int col, int A[fil][col])
{
    for(int i=0; i<fil; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("Cargar valor en A[%i][%i] ",i,j);
            scanf("%i",&A[i][j]);

        }
        if(i+1==fil)    //---   aviso cant = dim
        {
            printf("\nDimension maxima alcanzada. Se dejara de dcargar\n");
            system("pause");
        }
    }
/*
Es i<fil y j<col y no <= porque empieza a contar desde 0 el loop
Se deben cargar enteras
*/
}


void pruebaMatrices()
{
    printf("\nmatrices int : ok\n");
}
