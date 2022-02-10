#include "archivosInt.h"


// archivo int - invertir - recursion implicita
void archivoIntInvertirRecursionImplicita(FILE * FP,int cantidad,int i)
{
    int ppio,fin;

    if(i<cantidad) // cond de corte implícita
    {
            fseek(FP,sizeof(int)*(cantidad-1),0);
            fread(&fin,sizeof(int),1,FP);

            fseek(FP,sizeof(int)*i,0);
            fread(&ppio,sizeof(int),1,FP);

            fseek(FP,sizeof(int)*i,0);
            fwrite(&fin,sizeof(int),1,FP);

            fseek(FP,sizeof(int)*(cantidad-1),0);
            fwrite(&ppio,sizeof(int),1,FP);

            archivoIntInvertirRecursionImplicita(FP, cantidad-1, i+1);
    }
}


// archivo int - buscar menor valor - recursion explicita
int archivoIntMenorRecursionExplicita(FILE *arch)
{
    int valor;
    int menor;
    if(fread(&valor,sizeof(int),1,arch)==0)     //llegue al final   //en cada llamada queda guardado un valor
    {
        fseek(arch,-1*sizeof(int),SEEK_END);     //vuelvo un lugar
        fread(&menor,sizeof(int),1,arch);       //asigno el utimo valor a menor
    }
    else
    {
        menor = archivoIntMenorRecursionExplicita(arch);     //se iguala a menor porque es lo que queda esperando un numero en el camino de vuelta   //lo que retorna de cada llamada recursiva
        if(valor<menor)
        {
            menor = valor;
        }
    }
    return menor;
}


// archivo int - mostrar invertidamente - recursivo implicito
void archivoIntMostrarRecursionImplicita (FILE * arch)
{
    int valor;
    if(fread(&valor, sizeof(int),1,arch)>0)
    {
        printf("%d ", valor);       //de ida
        archivoIntMostrarRecursionImplicita (arch);
//        printf("%d ", valor);     //de vuelta
    }
}


// archivo int - mostrar - recursivo explicita
void archivoIntMostrarRecursionExplicita(FILE* archivo)
{
    int aux;

    if(fread(&aux, sizeof(int),1,archivo) == 0 )   // cond corte explicita: llegué al final del archivo
    {
        printf("\n"); // (solucion trivial)
    }
    else
    {
        printf("%d ", aux);           // y muestro el elemento cuando vuelve de la recursion..
        archivoIntMostrarRecursionExplicita (archivo);    // llamada recursiva
    }
}


// archivo int - contar registros
int archivoIntContarRegistros(char fileName[])
{
    int cant=0;
    FILE *arch=fopen(fileName,"rb");
    if(arch)
    {
        fseek(arch,0,SEEK_END);             // puntero archivo al final
        cant = ftell(arch)/sizeof(int);     // cant bytes desde puntero / tamaño bytes structura

        fclose(arch);
    }
    else
    {
        printf("\nError al abrir el archivo\n");
    }
    return cant;
}


// archivo int - mostrar
void archivoIntMostrar(char archivo[])
{
    FILE *arch = fopen(archivo,"rb");

    if(arch)
    {
        int aux;
        while(fread(&aux,sizeof(int),1,arch) >0)
        {
            printf("%i ",aux);
        }
        fclose(arch);
        printf("\n");
    }
    else
    {
        printf("\nError al abrir el archivo\n");
    }
}

// archivo int - cargar varios auto
void archivoIntCargarVariosAuto(char archivo[], int cant)
{
    for(int i=0; i<cant; i++)
    {
        FILE *arch = fopen(archivo,"ab");
        if(arch)
        {
            int aux = rand() % 10;
            fwrite(&aux, sizeof(int), 1, arch);
            fclose(arch);
        }
        else
        {
            printf("\nError al abrir el archivo\n");
        }
    }
}


void pruebaArchivosInt()
{
    printf("\narchivos int : ok\n");
}
