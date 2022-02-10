#include "arreglosStruc.h"


// arreglo struc - mostrar recursivamente
void arregloStrucMostrarRecursivamente(Struc A[], int validos, int i)
{
    if(validos == 0){
//        printf("\n");
    }else{
        strucMostrar(A[i]);
        arregloStrucMostrarRecursivamente(A, validos-1, i+1);
    }
}


// arreglo struc - eliminar de arreglo por indice
int arregloStrucBorrarPorIndice(Struc A[], int validos, int dato)
{
    while(dato<0 || dato>validos-1){
        printf("Index incorrecto, ingrese denuevo\n");
        scanf("%i",&dato);
    }


    int i;
    for (i=dato;i<validos-1;i++){
        A[i]=A[i+1];
    }
    return validos-1;
}


// arreglo struc - insertar en orden
int arregloStrucInsertarEnOrdenPorNumero(Struc A[],int validos, int dimension, Struc dato)
{
    if(validos == dimension)
    {
        printf("\nDimension insuficiente para agregar\n");
    }
    else
    {
        int i;
        for(i=validos-1;i>=0 && A[i].numero > dato.numero ;i--)
    {
        A[i+1]=A[i];
    }
        A[i+1]=dato;
    }
    return validos+1;
   }


// arreglo struc - ordenar por insercion - parte ordenada / desordenada
void arregloStrucOrdenarInsercion(Struc A[],int validos)
{
    for(int i=0; i<validos-1; i++)
    {
        arregloStrucOrdenarInsercionAuxPorNumero(A,i+1,A[i+1]);   //para ordenar por numero
//        arregloStrucOrdenarInsercionAuxPorPalabra(A,i+1,A[i+1]);    //por palabra
    }
}


// arreglo struc - insertar ordenadamente por palabra
void arregloStrucOrdenarInsercionAuxPorPalabra(Struc A[], int pos, Struc dato)
{
    int i;
    for(i=pos-1; i>=0 && strcmpi(A[i].palabra,dato.palabra) > 0; i--)  //menor a la izq
    {
        A[i+1]=A[i];
    }
    A[i+1]=dato;
}


// arreglo struc - insertar ordenadamente por numero
void arregloStrucOrdenarInsercionAuxPorNumero(Struc A[], int pos, Struc dato)
{
    int i;
    for(i=pos-1; i>=0 && dato.numero<A[i].numero; i--)  //menor a la izq  //cambiar chequeo para hacerla de char
    {
        A[i+1]=A[i];
    }
    A[i+1]=dato;
}


// arreglo struc - ordenar por seleccion
void arregloStrucOrdenarSeleccion(Struc A[], int validos)
{
    Struc aux;
    int posMenor;
    for(int i=0;i<validos-1;i++){
        posMenor=arregloStrucOrdenarSeleccionAuxPorNumero(A,validos,i);   //ordenado por numero
//        posMenor=arregloStrucOrdenarSeleccionAuxPorLetra(A,validos,i);    //ordenado por letra
//        posMenor=arregloStrucOrdenarSeleccionAuxPorPalabra(A,validos,i);    //ordenado por palabra
        //pivoteo
        aux=A[i];
        A[i]=A[posMenor];
        A[posMenor]=aux;
    }
}


// arreglo struc - ordenar por seleccion aux - ordenado por palabra
int arregloStrucOrdenarSeleccionAuxPorPalabra(Struc A[], int validos, int pos)
{
    char menor[30];
    strcpy(menor,A[pos].palabra);
    for(int i=pos; i<validos; i++)
    {
        if(strcmpi(A[i].palabra,menor) < 0)
        {
            strcpy(menor,A[i].palabra);
            pos=i;
        }
    }
    return pos;
}


// arreglo struc - ordenar por seleccion aux - ordenado por numero
int arregloStrucOrdenarSeleccionAuxPorNumero(Struc A[], int validos, int pos)
{
    int menor=A[pos].numero;
    for(int i=pos;i<validos;i++){

        if(A[i].numero<menor){
            menor=A[i].numero;
            pos=i;
        }
    }
    return pos;
}


// arreglo struc - ordenar por seleccion aux - ordenado por letra
int arregloStrucOrdenarSeleccionAuxPorLetra(Struc A[], int validos, int pos)
{
    char menor=A[pos].letra;

    for(int i=pos;i<validos;i++){

        if(A[i].letra<menor){
            menor=A[i].letra;
            pos=i;
        }
    }
    return pos;
}


//arreglo struc - copiar a otro arreglo por letra
int arregloStrucPasarPorLetra(Struc A[],int validos, char letra,Struc B[],int dimensionB)
{
    int i = 0;
    int j = 0;
    while(j<dimensionB && i<validos)
    {
        if(A[i].letra==letra)
        {
            B[j]=A[i];
            j++;
        }
        i++;
    }
    if(j == dimensionB)
    {
        printf("\nWarning: Cant = Dimension. No se seguira cargando\n");
        system("pause");
    }
    return j;
}


// arreglo struc - contar por letra
int arregloStrucContarPorLetra(Struc A[], int validos, char dato)
{
    int cant=0;
    for (int i=0; i<validos; i++)
    {
        if(A[i].letra==dato)
        {
            cant++;
        }
    }
    return cant;
}


// arreglo struc - mostrar datos por id
void arregloStrucMostrarPorId(Struc A[], int validos, int dato)
{
    int flag=0;
    for(int i=0; i<validos; i++)
    {
        if(dato==A[i].numero)
        {
            flag=1;
            strucMostrar(A[i]);
        }
    }
    if (flag==0)
        {
            printf("\nNo se encontro nada con el dato %i\n",dato);
        }
}


// arreglo struc - mostrar por genero
void arregloStrucMostrarPorLetra(Struc A[], int validos, char dato)
{
    int flag=0;
    for(int i=0; i<validos; i++)
    {
        if(dato==A[i].letra)
        {
            flag=1;
            strucMostrar(A[i]);
        }
    }
    if (flag==0)
        {
            printf("\nNo se encontro nada con el dato %i\n",dato);
        }
}


// arreglo struc - mostrar arreglo struc
void arregloStrucMostrar(Struc A[],int validos)
{
    if(validos == 0)
    {
        printf("\narreglo vacio...\n");
    }
    else
    {
        for (int i=0; i<validos; i++)
        {
           strucMostrar(A[i]);
        }
    }
}


// arreglo struc - cargar auto
int arregloStrucCargarAuto(Struc A[],int dimension,int cant)
{
    int i;
    if(cant>dimension)
    {
        printf("\nError - Cant > dimension - no se cargara el arreglo\n");
    }
    else
    {
        for (i=0;i<dimension && i<cant;i++)
        {
            A[i]=strucCargarAuto();
        }
    }
    return i;
}


// arreglo struc - cargar a mano
int arregloStrucCargarAMano(Struc A[], int dimension)
{
    int validos=0;
    char letra='s';
    printf("\nCargando arreglo struc a mano... Ingrese valores\n");

    while(validos<dimension && letra=='s')     //no sacar chequeo dimension
    {
        A[validos]=strucCargarAMano();

        validos++;
        printf("Seguir? (s/n) ");
        fflush(stdin);
        letra=getchar();
        //---                                   //avisos cant>dim en cargar a mano
        if(validos==dimension)
        {
            if(letra=='s'){
                printf("Error: Cant > dimension . No se seguira cargando\n");
                system("pause");
                break;
            }else{
                break;
            }
        }
        //---
    }
    return validos;
}


void pruebaArreglosStruc()
{
    printf("\narreglos struc : ok\n");
}

///inicio borrar en proyecto C

// struc - mostrar
void strucMostrar(Struc dato)
{
    printf("\nNumero %i\n",dato.numero);
    printf("Letra: %c\n",dato.letra);
    printf("Palabra: %s\n",dato.palabra);
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


// char - letra random
char charRandom()
{
    char letras[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int cantLetras  = sizeof(letras)/sizeof(char);
    return letras[rand()%cantLetras];
}

///fin borrar en proyecto C

