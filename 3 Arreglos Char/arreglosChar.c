#include "arreglosChar.h"


void arregloCharFunciones()
{
    int dimension1=30;
    char string1[dimension1];
    arregloCharCargarPalabraAuto(string1,dimension1);
    printf("\nstring1: %s\n",string1);


    int dimension2=30;
    char string2[dimension2];
    arregloCharCargarPalabraAuto(string2,dimension2);
    printf("\nstring2: %s\n",string2);


    int dimension3=30;
    char string3[dimension3];
    arregloCharCargarPalabraAuto(string3,dimension3);
    printf("\nstring3: %s\n",string3);


    int dimension4=30;
    char string4[dimension4];
    arregloCharCargarPalabraAuto(string4,dimension4);
    printf("\nstring4: %s\n",string4);


    int intX;


    printf("\nstrlen:\n");
    printf("\nPalabra: %s\n",string1);
    intX = strlen(string1);
    printf("Largo: %i\n",intX);
    /*
   Conocer la longitud de una cadena, devuelve un valor entero que es la cantidad de caracteres
   */


    intX= strcmp(string1,string2);
    printf("\nstrcmp: %i",intX);
    /*
    Compara elemento a elemento 2 strings mediante codigo ASCII
    Diferencia mayusculas
    Si da -1 el de la izq tiene menor ASCII
    Si da 0 todos los elementos son iguales
    Si da 1 el de la derecha tiene menor ASCII
    No te dice cual es la palabra mas corta, sino el indice que tuvo el menor ascii primero
    */


    intX = strcmpi(string1,string2);
    printf("\nstrcmpi: %i\n",intX);
    /*
    Igual que strcmp pero:
        No diferencia entre minuscula y mayusculas
        Sigue respetando que el valor "apunta" hacia la con menor ASCII
        Retorna numeros enteros indicando la diferencia de ASCII
    */


    strcpy(string1,string2);
    printf("\nstrcpy: %s\n",string1);
    /*
    Copia una string a otra
    Primer parametro es la cadena de destino y segundo la de origen
    Para hacer printf de strings usar tipo de dato "%s"
    No es sensible a la dimension de destino, la agrandara de ser necesario
    */


    strcat(string3,string4);
    printf("\nstrcat: %s\n",string3);
    /*
    Unir o concatenar dos o más strings, copia el contenido de la segunda cadena al final de la primera.
    No es sensible a la dimension de destino
    */


    puts(string4);


    intX=strlen(string4);
    for(int i=0;i<intX;i++){
        string4[i]=toupper(string4[i]); //asigno a misma string
        string2[i]=tolower(string4[i]); // asigno a otra (no borra basura que contenga la otra)
    }
    printf("\ntoupper: %s\n", string4);
    printf("\ntolower: %s\n", string2);
    /*
    Transforman el case de cada letra
    Hace letra por letra, necesito loop para toda la palabra
    */


    printf("\nIngrese string a buscar en: %s ",string4);
    char buscado[30];
    gets(buscado);
    char *busqueda = strstr(string4,buscado);
    printf("\nstrstr: %s\n", busqueda);
    /*
    Permite saber si una cadena está contenida dentro de otra.
    Devuelve un puntero al comienzo de la cadena buscada, si es que la encuentra
    Lo que se muestra es la palabra desde la semejanza en adelante
    Devuelve “NULL” si no lo encuentra
    Se busca en la string de la izquierda lo de la derecha
    Sensible a las mayusculas
    */
}


// arreglo char - cargar letras randoms ordenadas
int arregloCharCargarLetrasAutoOrdenadas(char A[],int dimension, int cant)
{
    if(cant>dimension)
    {
        printf("Error - Cant > dimension - no se cargara el arreglo\n");
        return 0;
    }
    else
    {
        int i ;
        for(i= 0; i<cant; i++)
        {
            arregloCharInsertar(A,i,charRandom());
        }
        return i;
    }
}


// arreglo char - insertar en arreglo ordenado
void arregloCharInsertar(char C[], int validos,char dato)
{
    int ult=validos-1;
    while(ult>=0 && dato<C[ult]){
        C[ult+1]=C[ult];
        ult--;
    }
    C[ult+1]=dato;
//    return validos+1;   //para usarse igualando a validos
}


// arreglo char - chequear capicu
int arregloCharCapicua(char C[], int validos)
{
    int i=0;
    int j=validos-1;
    while(i<validos/2)
    {
        if(C[i]!=C[j])
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}


// arreglo char - invertir
void arregloCharInvertir(char C[],int validos)
{
    int i=0;
    int j=validos-1;
    char aux='@';

    while(i<validos/2)
    {
        aux=C[i];
        C[i]=C[j];
        C[j]=aux;
        i++;
        j--;
    }
}


// arreglo char - encontrar mayor o menor
char arregloCharMayor(char C[], int validos)
{
    char mayor=C[0];

    for(int i=1; i<validos; i++)
    {
        if(C[i]>mayor)              //cambiar a C[i]<menor para que devuelva el menor
        {
            mayor=C[i];
        }
    }
    return mayor;
/*
Compara codigo ASCII -> pueden pasar cosas raras como que los espacios son "menores" a las letras
*/
}


// arreglo char - encontrar mayor o menor
char arregloCharMenor(char C[], int validos)
{
    char menor=C[0];

    for(int i=1; i<validos; i++)
    {
        if(C[i]<menor)              //cambiar a C[i]>menor para que devuelva el mayor
        {
            menor=C[i];
        }
    }
    return menor;
/*
Compara codigo ASCII -> pueden pasar cosas raras como que los espacios son "menores" a las letras
*/
}


// arreglo char - buscar caracter y pos del buscado
int arregloCharBuscar(char C[],int validos,char dato)
{
    int pos=-1;
    int i = 0;
    while(i<validos && pos==-1)//pos primer match
    {
        if(dato==C[i])
        {
            pos=i;
        }
        i++;
    }
    return pos;
}


// arreglos char - cargar letras auto
int arregloCharCargarPalabraAuto(char A[],int dimension)
{
        char nombres[26][20]={"Hilberto Hil","El negro","Alvaro","Guada","Isla remota","Junior","Cleo","Dylan","Beto","Fran","Karen","La Sheni","Manicho","Naricitas","Osvaldo","Zulu hip hop","Quesito","Rastaman","Sushi","Tutan kamon","Uvita","Vino","Waka waka","Xilofon","YIFY","Pancito Relleno"};
        char nombre[30];

        strcpy(nombre,nombres[rand()%26]);  //nombre rand a nombre


        if(strlen(nombre) > dimension){
            printf("\nError: nombre>dimension. No se cargara el arreglo");
            return 0;
        }else{
            strcpy(A,nombre);                   //nombre a arreglo
        }
         return strlen(nombre);
}


// arreglos char - cargar letras auto
int arregloCharCargarLetrasAuto(char A[],int dimension, int cant)
{
    int i;
    if(cant>dimension)
    {
        printf("\nError - Cant > dimension - no se cargara el arreglo\n");
    }
    else
    {
        for(i=0; i<cant; i++)
        {
            A[i]=charRandom();
        }
    }
        return i;
}


// arreglo char - cargar por palabra a mano
int arregloCharCargarPalabraAMano(char A[],int dimension)
{

    printf("\nIngrese palabra a cargar en el arreglo\n");
    char palabra[100];
    fflush(stdin);
    gets(palabra);
    int validos = strlen(palabra);

    while(validos>dimension)
    {
        printf("\nLa palabra es muy larga, ingrese otra\n");
        fflush(stdin);
        gets(palabra);
        validos = strlen(palabra);
    }
    strcpy(A,palabra);
    return validos;
}


// arreglos char - mostrar
void arregloCharMostrar(char C[],int validos)
{
    if(validos==0)
    {
        printf("Arreglo vacio!\n");
    }
    else
    {
        printf("\n");
        for(int i=0; i<validos; i++)
        {
            printf("%c ",C[i]);
        }
        printf("\n");
    }
/*
Toda esta funcion puede ser reemplazada por puts()
*/
}


// arreglos char - cargar por letras a mano
int arregloCharCargarLetrasAMano(char A[],int dimension)
{
    printf("Ingrese cada letra apretando enter y al finalizar ingrese 0\n");
    char letra='@';
    int validos=0;

    for(int i=0; i<dimension && letra != '0'; i++)
    {
        fflush(stdin);
        letra=getchar();

        if(letra!='0')
        {
            A[i]=letra;
            validos++;

            if(i+1==dimension)  //---   aviso cant = dim
            {
                printf("\nAlerta: Dimension maxima alcanzada. Se dejara de cargar\n");
                system("pause");
            }
        }
    }
    return validos;
}


void pruebaArreglosChar()
{
    printf("\narreglos char : ok\n");
}


///inicio borrar en proyecto C

// char - letra random
char charRandom()
{
    char letras[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int cantLetras  = sizeof(letras)/sizeof(char);
    return letras[rand()%cantLetras];
}

///fin borrar en proyecto C
