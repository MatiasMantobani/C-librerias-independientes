#include "archivosStruc.h"


// archivo struc - pasar todo arreglo a archivo
void arregloToArchivo(char fileName[],Struc A[],int validos)
{
    FILE *arch=fopen(fileName,"ab");

    if(arch)
    {
        Struc aux;

        for(int i=0; i<validos; i++)
        {
            aux=A[i];
            fwrite(&aux, sizeof(Struc), 1, arch);
        }
        fclose(arch);
    }
    else
    {
        printf("\nError al abrir el archivo\n");
    }
}


// archivo struc - pasar de archivo a arreglo por numero
int archivoToArregloPorNumero(char fileName[], Struc A[], int dimension, int dato)
{
    FILE *arch=fopen(fileName,"rb");
    int validos=-1;

    if(arch)
    {
        if(dimension < archivoContarRegistros(fileName))
        {
            printf("\nError: dimension < cant. Se cargaran los que entren\n");
        }
        Struc aux;
        validos=0;
        while(validos<dimension && fread(&aux,sizeof(Struc),1,arch) > 0)
        {

            if(aux.numero == dato)
            {
                A[validos]=aux;
                validos++;
            }
        }
        fclose(arch);
    }
    else
    {
        printf("\nError al abrir el archivo\n");
    }
    return validos;
}


// archivo struc - pasar de archivo a arreglo
int archivoToArreglo(char fileName[], Struc A[], int dimension)
{
    FILE *arch=fopen(fileName,"rb");
    int validos=-1;

    if(arch)
    {
        if(dimension < archivoContarRegistros(fileName))
        {
            printf("\nError: dimension < cant. Se cargaran los que entren\n");
        }

        Struc aux;
        validos=0;
        while(validos<dimension && fread(&aux,sizeof(Struc),1,arch) > 0)
        {
            A[validos]=aux;
            validos++;
        }
        fclose(arch);
    }
    else
    {
        printf("\nError al abrir el archivo\n");
    }
    return validos;
}


// archivo struc - modificar por indice solo campo numero de struc
void archivoModificarPorPosCampoNumeroAMano(char fileName[], int dato)
{
    FILE *arch=fopen(fileName,"r+b");
    if(arch)
    {
        while(dato<1 || dato>archivoContarRegistros(fileName))
        {
            printf("\nError: indice inexistente, ingrese nuevamente\n");
            scanf("%i",&dato);
        }
        Struc aux;

        fseek(arch,sizeof(Struc)*(dato-1),SEEK_SET);   //llego a pos
        fread(&aux,sizeof(Struc),1,arch);   //copio todo en aux
        printf("\nNumero: %i\n", aux.numero);    //muestro campo aux
        fseek(arch,-sizeof(Struc),SEEK_CUR);   //vuelvo uno atras
        scanf("%d",&aux.numero);             //escribo en campo a modificar de aux
        fwrite(&aux, sizeof(Struc), 1, arch);   //escribo archivo con aux

        fclose(arch);
    }
    else
    {
        printf("\nError al abrir el archivo\n");
    }
}


// archivo struc - modificar por indice toda struc auto
void archivoModificarPorPosAuto(char fileName[], int dato)
{
    FILE *arch=fopen(fileName,"r+b");
    if(arch)
    {
        while(dato<1 || dato>archivoContarRegistros(fileName))
        {
            printf("\nError: indice inexistente, ingrese nuevamente\n");
            scanf("%i",&dato);
        }
        Struc aux = strucCargarAuto();
        fseek(arch,sizeof(Struc)*(dato-1),SEEK_SET);
        fwrite(&aux, sizeof(Struc), 1, arch);
        fclose(arch);
    }
    else
    {
        printf("\nError al abrir el archivo\n");
    }
}


// archivo struc - mostrar por indice
void archivoMostrarPorPos(char fileName[],int dato)
{
    FILE *arch=fopen(fileName,"rb");
    if(arch)
    {
        while(dato<1 || dato>archivoContarRegistros(fileName))
        {
            printf("\nError: indice inexistente, ingrese nuevamente\n");
            scanf("%i",&dato);
        }
        Struc aux;
        fseek(arch,sizeof(Struc)*(dato-1),SEEK_SET);
        fread(&aux,sizeof(Struc),1,arch);
        strucMostrar(aux);
        fclose(arch);
    }
    else
    {
        printf("\nError al abrir el archivo\n");
    }
}


// archivo struc - modificar por numero solo el campo numero
void archivoModificarPorNumeroCampoNumero(char archivo[], int dato)
{
    FILE *arch = fopen(archivo,"r+b");
    if(arch)
    {
        Struc aux;
        int flag=0;
        while(flag==0 && fread(&aux,sizeof(Struc),1,arch) > 0)
        {
            if(aux.numero == dato)
            {
                fseek(arch,-sizeof(Struc),SEEK_CUR);       //vuelvo uno hacia atras
                fread(&aux,sizeof(Struc),1,arch);   //asigno a aux para no perder otros campos
                printf("\nNumero: %i\n", aux.numero);    //muestro aux

                flag=1;
            }
        }
        if(flag == 1)
        {
            fseek(arch,-sizeof(Struc),SEEK_CUR);   //vuelvo uno hacia atras
            scanf("%i",&aux.numero);             //modifico campo en aux
            fwrite(&aux, sizeof(Struc), 1, arch);   //escribo todo el aux en el archivo
        }
        else
        {
            printf("\nNo se encontro el valor a modificar\n");
        }
        fclose(arch);
    }
    else
    {
        printf("\nError al abrir el archivo\n");
    }
}


// archivo struc - modificar por numero
void archivoModificarPorNumeroAuto(char archivo[], int dato)
{
    FILE *arch = fopen(archivo,"r+b");
    if(arch)
    {
        Struc aux;
        int flag=0;
        while(flag==0 && fread(&aux,sizeof(Struc),1,arch) > 0)
        {
            if(aux.numero == dato)
            {
                flag=1;
            }
        }
        if(flag == 1)
        {
            fseek(arch,-sizeof(Struc),SEEK_CUR);   //vuelvo uno hacia atras
            aux = strucCargarAuto();
            fwrite(&aux, sizeof(Struc), 1, arch);
        }
        else
        {
            printf("\nNo se encontro el valor a modificar\n");
        }
        fclose(arch);
    }
    else
    {
        printf("\nError al abrir el archivo\n");
    }
}


// archivo struc - mostrar por palabra
int archivoMostrarPorPalabra(char fileName[], char dato[])
{
    FILE *arch=fopen(fileName,"rb");
    int counter = 0;
    if(arch)
    {

        Struc aux;
        while(fread(&aux,sizeof(Struc),1,arch)>0)
        {
            if(strcmpi(dato, aux.palabra) == 0)
            {
                strucMostrar(aux);
                counter++;
            }
        }
        fclose(arch);
    }
    else
    {
        printf("\nError al abrir el archivo\n");
    }
    return counter;
}


// archivo struc - mostrar por numero
void archivoMostrarPorNumero(char fileName[], int dato)
{
    FILE *arch=fopen(fileName,"rb");
    if(arch)
    {
        Struc aux;
        while(fread(&aux,sizeof(Struc),1,arch)>0)
        {
            if(aux.numero == dato)
            {
                strucMostrar(aux);
            }
        }
        fclose(arch);
    }
    else
    {
        printf("\nError al abrir el archivo\n");
    }
}


// archivo struc - contar registros de archivo
int archivoContarRegistros(char fileName[])
{
    int cant=0;
    FILE *arch=fopen(fileName,"rb");
    if(arch)
    {
        fseek(arch,0,SEEK_END);                 // puntero archivo al final
        cant = ftell(arch)/sizeof(Struc);       // cant bytes desde puntero / tamaño bytes structura

        fclose(arch);
    }
    else
    {
        printf("\nError al abrir el archivo\n");
    }
    return cant;
}


// archivo struc - mostrar
void archivoMostrar(char archivo[])
{
    FILE *arch = fopen(archivo,"rb");

    if(arch)
    {
        Struc aux;
        while(fread(&aux,sizeof(Struc),1,arch) >0)
        {
            strucMostrar(aux);
        }
        fclose(arch);
    }
    else
    {
        printf("\nError al abrir el archivo\n");
    }
}


// archivo struc - cargar varios auto
void archivoCargarVariosAuto(char nombreArchivo[], int cant)
{
    for(int i=0; i<cant; i++)
    {
        archivoCargarUnoAuto(nombreArchivo); //1.1
    }
}


// archivo struc - cargar 1 manual
void archivoCargarUnoAMano(char archivo[])
{
    FILE *arch = fopen(archivo,"ab");
    if(arch)
    {
        Struc aux = strucCargarAMano();
        fwrite(&aux, sizeof(Struc), 1, arch);

        fclose(arch);
    }
    else
    {
        printf("\nError al abrir el archivo\n");
    }
}


// archivo struc - cargar 1 auto
void archivoCargarUnoAuto(char archivo[])
{
    FILE *arch = fopen(archivo,"ab");
    if(arch)
    {
        Struc aux=strucCargarAuto();
        fwrite(&aux, sizeof(Struc), 1, arch);

        fclose(arch);
    }
    else
    {
        printf("\nError al abrir el archivo\n");
    }
}


void pruebaArchivosStruc()
{
    printf("\narchivos struc : ok\n");
}


///---------------------REPETIDAS: borrar al pasar a proyecto C---------------------------------------------
// arreglo struc - mostrar arreglo struc
void arregloStrucMostrar(Struc A[],int validos)
{
    if(validos == 0)
    {
        printf("\nArreglo vacio!\n");
    }
    else
    {
        for (int i=0; i<validos; i++)
        {
           strucMostrar(A[i]);
        }
    }
}


// struc - mostrar
void strucMostrar(Struc dato)
{
    printf("\nNumero %i\n",dato.numero);
    printf("Letra: %c\n",dato.letra);
    printf("Palabra: %s\n",dato.palabra);
}



// struc - cargar automatico
Struc strucCargarAuto()
{
    Struc aux;

    aux.numero=rand() % 10;   //num
    aux.letra = charRandom();  //letra

    char nombres[26][20]={"Hoplita Pesado","El negro","Alvaro","Guada","Isla remota","Junior","Cleo","Dylan","Beto","Fran","Karen","La Sheni","Manicho","Naricitas","Osvaldo","Zulu hip hop","Quesito","Rastaman","Sushi","Tutan kamon","Uvita","Vino","Waka waka","Xilofon","YIFY","Pancito Relleno"};
    char nombre[30];
    strcpy(nombre,nombres[rand()%26]);  //rand() --> nombre
    strcpy(aux.palabra,nombre);        //nombre --> A[]

    return aux;
}



// struc - cargar a mano
Struc strucCargarAMano()
{
    Struc aux;

    printf("\nIngrese el numero ");
    scanf("%i",&aux.numero);

    printf("\nIngrese la letra ");
    fflush(stdin);
    aux.letra=getchar();

    printf("\nIngrese la palabra ");
    fflush(stdin);
    gets(aux.palabra);

    return aux;
}



// char - letra random
char charRandom()
{
    char letras[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int cantLetras  = sizeof(letras)/sizeof(char);
    return letras[rand()%cantLetras];
}


///------------------------------------------------
