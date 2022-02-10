#include "ADF.h"



// ADF - pasar archivo a ADF
int ADFarchivoAADF(char archivo[], ADFcelda arreglo[], int dimension, int validos)
{
    FILE *arch = fopen(archivo, "r");

    ADFarchivo nuevoRegistro;
    Struc datoCelda;
    Struc datoFila;

    if(arch)
    {
        while(fread(&nuevoRegistro, sizeof(ADFarchivo), 1, arch) > 0 && validos < dimension)
        {
            datoCelda = nuevoRegistro.datoCelda;
            datoFila = nuevoRegistro.datoFila;
            validos = ADFalta(arreglo, dimension,validos, datoCelda, datoFila);
        }
        fclose(arch);
    }
    else
    {
        printf("\nerror archivo : ADFarchivoAADF\n");
    }
    return validos;
}


// ADF - archivo - mostrar
void ADFarchivoMostrar(char archivo[])
{
    FILE *arch = fopen(archivo, "r");
    if(arch)
    {
        ADFarchivo registroArchivo;
        while(fread(&registroArchivo, sizeof(registroArchivo), 1, arch) > 0)
        {
            printf("\n            Mostrando Celda Archivo :\n");
            strucMostrar(registroArchivo.datoCelda);
            printf("\n            Mostrando Fila Archivo :\n");
            strucMostrar(registroArchivo.datoFila);
        }
    }
}


// ADF - de ADF a archivo
void ADFaArchivo(char archivo[], ADFcelda arreglo[], int validos)
{
    FILE *arch = fopen(archivo, "w");   //"a" : append, "w" : delete and create
    ADFarchivo nuevoRegistro;
    int i = 0;

    if(arch)
    {
        while(i < validos)  // cant de celdas
        {
            nuevoRegistro.datoCelda = arreglo[i].datoCelda;

            while(arreglo[i].filaCelda.fin)
            {

                nuevoRegistro.datoFila = arreglo[i].filaCelda.fin->dato;

                fwrite(&nuevoRegistro, sizeof(ADFarchivo), 1, arch);

                arreglo[i].filaCelda.fin = arreglo[i].filaCelda.fin->anterior;
            }
            i++;
        }
        fclose(arch);
    }
    else
    {
        printf("\narchivo no se pudo abrir...\n");
    }
}





// ADF - mostrar - se muestra el dato de la celda y el arbol de la celda
void ADFmostrar(ADFcelda arreglo[], int validos)
{
    for (int i=0; i<validos; i++)
    {
        printf("\n            Mostrando Celda %i :\n",i);
        strucMostrar(arreglo[i].datoCelda);

        printf("\n            Mostrando Fila %i :\n",i);
        filaMostrar(&arreglo[i].filaCelda);
    }
}


// ADF - agregar celda ADL
int ADFagregarCelda(ADFcelda arreglo[], int validos, Struc datoCelda)
{
    arreglo[validos].datoCelda = datoCelda;
    filaInic(&arreglo[validos].filaCelda);
    validos++;
    return validos;
}


// ADF - buscar en arreglo si el dato de la celda existe y retornar posicion (para no repetir celdas)
int ADFposCelda(ADFcelda arreglo[], int validos, Struc datoCelda)
{
    int rta = -1;
    int i = 0;
    while(i < validos && rta == -1)
    {
        if(arreglo[i].datoCelda.numero == datoCelda.numero) //criterio para celda repetida, alguno de los datos irrepetibles de datoCelda
        {
            rta = i;
        }
        i++;
    }
    return rta;
}


// ADF - alta - funcion agregar uno
int ADFalta(ADFcelda arreglo[], int dimension, int validos, Struc datoCelda, Struc datoFila)
{
    if(validos < dimension)
    {
        int pos = ADFposCelda(arreglo, validos, datoCelda);

        if(pos == -1)
        {
            validos = ADFagregarCelda(arreglo, validos, datoCelda);
            pos = validos - 1;
        }
        filaAgregarUno(&arreglo[pos].filaCelda, datoFila);
    }
    else
    {
        printf("\nerror en ADFalta : validos = dimension... Se deja de cargar en ADA\n");
    }
    return validos;
}


// ADF - agregar datos con numero 0 a 9
int ADFagregarRandom(ADFcelda arreglo[],int dimension, int validos,int cant)
{
    Struc datoCelda;
    Struc datoFila;

    for (int i=0; i<cant; i++)
    {
        datoCelda = strucCargarAuto();
        datoFila = strucCargarAuto();
        validos = ADFalta(arreglo, dimension, validos, datoCelda, datoFila);
    }
    return validos;
}



void pruebaADF()
    {
        printf("\nArreglo De Filas : ok\n");
    }

///inicio borrar proyecto C


// fila - LDPS - mostrar
void filaMostrar(Fila* fila)
{
    LDPSmostrar(fila-> inicio);
}


// fila - LDPS - inicializar
void filaInic(Fila* fila)
{
    fila-> inicio = LDPSinic();
    fila-> fin = LDPSinic();
}


// fila - LDPS - agregar uno
void filaAgregarUno(Fila* fila, Struc dato)
{
    nodoD* nuevoNodo = LDPScrearNodo(dato);

    fila-> fin = LDPSagregarUnoFinal(fila->fin, nuevoNodo);
    fila-> fin = nuevoNodo;

    if(fila-> inicio == NULL)
    {
        fila-> inicio = nuevoNodo;
    }
}


// LDPS - mostrar lista/sublista/nodoD
void LDPSmostrar(nodoD* lista)
{
    if(lista)
    {
        nodoD* aux=lista;
        while(aux)
        {
            strucMostrar(aux->dato);
            aux=aux->siguiente;
        }
    }
    else
    {
        printf("La lista esta vacia...\n");
    }
}


// LDPS - agregar 1 al final
nodoD* LDPSagregarUnoFinal(nodoD* lista, nodoD* nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodoD* ultimo = LDPSultimo(lista);
        nuevoNodo-> anterior = ultimo;
        ultimo-> siguiente = nuevoNodo;
    }
    return lista;
}


// LDPS - retornar puntero a ultimo
nodoD* LDPSultimo(nodoD* lista)
{
    nodoD* ultimo = lista;
    if(ultimo)
    {
        while(ultimo-> siguiente)
        {
            ultimo = ultimo-> siguiente;
        }
    }
    else
    {
        printf("La lista esta vacia...\n");
    }
    return ultimo;
}


// LDPS - crear nodo
nodoD* LDPScrearNodo(Struc dato)
{
    nodoD* aux = (nodoD*) malloc(sizeof(nodoD));

    aux-> dato = dato;
    aux-> anterior = NULL;
    aux-> siguiente = NULL;

    return aux;
}


// LDPS - inicializar lista
nodoD* LDPSinic()
{
    return NULL;
}


// struc - mostrar
void strucMostrar(Struc dato)
{
    printf("\nNumero : %i\n",dato.numero);
    printf("Letra : %c\n",dato.letra);
    printf("Palabra : %s\n",dato.palabra);
}


// struc - cargar automatico
Struc strucCargarAuto()
{
    Struc aux;

    aux.numero=rand() % 10;   //num
    aux.letra = charRandom();  //letra

    char nombres[26][20]= {"Hoplita Pesado","Elasti-cop","Avalancha","Guada","Isla remota","Junior San","Cleo","Dylan","Beto","Fran","Karen","Lullabies","Manicho","Naricitas","Osvaldo","Zulu hip hop","Quesito","Rastaman","Sushi","Tutan kamon","Uvita","Vino","Waka waka","Xilofon","YIFY","Pancito Relleno"};
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

///fin borrar proyecto C
