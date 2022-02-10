#include "LDF.h"



// LDA - pasar de archivo a LDA
LDFcelda* LDFarchivoALDF(char archivo[], LDFcelda* LDF)
{
    FILE *arch = fopen(archivo, "r");
    LDFarchivo registroArchivo;

    Struc datoCelda;
    Struc datoFila;

    if(arch)
    {
        while(fread(&registroArchivo, sizeof(LDFarchivo), 1, arch) > 0)
        {
            datoCelda = registroArchivo.datoCelda;
            datoFila = registroArchivo.datoFila;
            LDF = LDFalta(LDF, datoCelda, datoFila);
        }
        fclose(arch);
    }
    else
    {
        printf("\nerror en archivo : LDFarchivoALDF\n");
    }
    return LDF;
}


// LDF - archivo - mostrar
void LDFarchivoMostrar(char archivo[])
{
    FILE* arch = fopen(archivo, "r");

    LDFarchivo registroArchivo;

    if(arch)
    {
        while(fread(&registroArchivo, sizeof(LDFarchivo), 1, arch) > 0)
        {
            printf("\n            Mostrando Celda Archivo :\n");
            strucMostrar(registroArchivo.datoCelda);
            printf("\n            Mostrando Fila Archivo :\n");
            strucMostrar(registroArchivo.datoFila);

        }
        fclose(arch);
    }
}


// LDF - de LDF a archivo
void LDFaArchivo(char archivo[], LDFcelda* LDF)
{
    FILE* arch = fopen(archivo, "w");

    LDFarchivo registroArchivo;
    LDFcelda* seguidoraCelda = LDF;

    if(arch)
    {
        while(seguidoraCelda)
        {
            registroArchivo.datoCelda = seguidoraCelda->datoCelda;
            while(seguidoraCelda->filaCelda.fin)
            {
                registroArchivo.datoFila = seguidoraCelda->filaCelda.fin->dato;
                fwrite(&registroArchivo, sizeof(LDFarchivo), 1, arch);
                seguidoraCelda->filaCelda.fin = seguidoraCelda->filaCelda.fin->anterior;
            }

            seguidoraCelda = seguidoraCelda->siguiente;
        }
        fclose(arch);
    }
    else
    {
        printf("\nerror archivo : LDAaArchivo\n");
    }
}


// LDA - mostrar
void LDFmostrar(LDFcelda* lista)
{
    if(lista)
    {
        LDFcelda* seguidora = lista;

        while(seguidora)
        {
            LDFmostrarCelda(seguidora);
            seguidora = seguidora-> siguiente; // me muevo hacia el siguiente nodo en la lista
        }
    }
    else
    {
        printf("\nLa lista esta vacia...\n");
    }
}


// LDF - mostrar celda
void LDFmostrarCelda(LDFcelda* celda)
{
    printf("\n                          Mostrando Celda :\n");
    strucMostrar(celda->datoCelda);

    printf("\n                          Mostrando Fila :\n");
    filaMostrar(&celda->filaCelda);
}



// LDF - agregar una celda al principio de LDL
LDFcelda* LDFagregarAlPpio(LDFcelda* lista, LDFcelda* nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo-> siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}



// LDF - crear una celda LDF
LDFcelda* LDFcrearCelda(Struc datoCelda)
{
    LDFcelda* aux = (LDFcelda*) malloc(sizeof(LDFcelda));
    aux-> datoCelda = datoCelda;
    filaInic(&aux->filaCelda);
    aux-> siguiente = NULL;

    return aux;
}



// LDF - buscar y devolver celda de lista por numero de datoCelda
LDFcelda* LDFbuscarNodoCelda(LDFcelda* LDF, Struc datoCelda)
{
    LDFcelda* seg = LDF;
    LDFcelda* rta = NULL;
    int flag = 0;

    while(seg && flag == 0)
    {
        if(seg->datoCelda.numero == datoCelda.numero)   //puede haber mas de un chequeo aca  (&&)
        {
            rta = seg;
            flag = 1;
        }
        seg = seg->siguiente;
    }
    return rta;
}


// LDF - alta - funcion agregar uno
LDFcelda* LDFalta(LDFcelda* LDF, Struc datoCelda, Struc datoFila)
{
    LDFcelda* rta = LDFbuscarNodoCelda(LDF, datoCelda);

    if(rta == NULL) //no existe dato de celda en lista de celdas
    {
        LDFcelda* nuevaCelda = LDFcrearCelda(datoCelda);
        LDF = LDFagregarAlPpio(LDF, nuevaCelda); // la agrego al ppio de la lista de celdas
        rta = LDF;// como el nodo lo agrege al principio directamente igualo rta a la lista, si lo agrego al final o en orden deberia encontrar nuevamente el nodo que agregamos para poder agregar la nota en la lista de notas
    }
    filaAgregarUno(&rta->filaCelda,datoFila);

    return LDF;
}



// LDF - agregar datos randoms a funcion alta
LDFcelda* LDFagregarRandom(LDFcelda* LDF, int cant)
{
    Struc datoCelda;
    Struc datoFila;

    for (int i=0; i<cant; i++)
    {
        datoCelda = strucCargarAuto();
        datoFila = strucCargarAuto();
        LDF = LDFalta(LDF, datoCelda, datoFila);
    }
    return LDF;
}


// LDF - inicializar
LDFcelda* LDFinic()
{
    return NULL;
}


// LDF - prueba Lista De Filas
void pruebaLDF()
{
    printf("\nPrueba LDF : ok\n");
}



/// inicio borrar en proyecto C


//Fila


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


// LDPS


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


//Strucs


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

/// fin borrar en proyecto C
