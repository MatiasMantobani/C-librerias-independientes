#include "LDL.h"

//materia = dato celda
//alumno = dato lista


// LDL - pasar de archivo a LDL
LDLcelda* LDLarchivoALDL(char archivo[], LDLcelda* LDL)
{
    FILE *arch = fopen(archivo, "r");
    strucArchivo registroArchivo;

    Struc datoCelda;
    Struc datoLista;

    if(arch)
    {
        while(fread(&registroArchivo, sizeof(strucArchivo), 1, arch) > 0)
        {
            datoCelda = registroArchivo.datoCelda;
            datoLista = registroArchivo.datoLista;
            LDL = LDLalta(LDL, datoCelda, datoLista);
        }
        fclose(arch);
    }
    else
    {
        printf("\nerror en archivo : LDLarchivoALDL\n");
    }
    return LDL;
}


// LDL - pasar de LDL a archivo
void LDLaArchivo(char archivo[], LDLcelda* LDL)
{
    FILE* arch = fopen(archivo, "a");   //"w", "a"
    strucArchivo registroArchivo;
    LDLcelda* seguidoraCelda = LDL;

    if(arch)
    {
        while(seguidoraCelda)
        {
            while(seguidoraCelda->listaCelda)
            {
                // aca puede ir un if
                registroArchivo.datoCelda = seguidoraCelda-> datoCelda;
                registroArchivo.datoLista = seguidoraCelda->listaCelda->dato;

                fwrite(&registroArchivo, sizeof(registroArchivo), 1, arch);

                seguidoraCelda->listaCelda = seguidoraCelda->listaCelda->siguiente;
            }
            seguidoraCelda = seguidoraCelda-> siguiente;
        }
        fclose(arch);
    }
    else
    {
        printf("\nerror en archivo : LDLaArchivo\n");
    }
}


// LDL - archivo - mostrar
void LDLarchivoMostrar(char archivo[])
{
    FILE* arch = fopen(archivo, "r");

    strucArchivo registroArchivo;

    if(arch)
    {
        while(fread(&registroArchivo, sizeof(strucArchivo), 1, arch) > 0)
        {
            printf("\n            Mostrando Celda Archivo :\n");
            strucMostrar(registroArchivo.datoCelda);
            printf("\n            Mostrando lista Archivo :\n");
            strucMostrar(registroArchivo.datoLista);
        }
        fclose(arch);
    }
}



// LDL - mostrar
void LDLmostrar(LDLcelda* lista)
{
    if(lista)
    {
        LDLcelda* seguidora = lista; // copia de seguridad

        while(seguidora)
        {
            LDLmostrarCelda(seguidora);
            seguidora = seguidora-> siguiente; // me muevo hacia el siguiente nodo en la lista
        }
    }
    else
    {
        printf("\nLa lista esta vacia...\n");
    }
}

// LDL - mostrar celda
void LDLmostrarCelda(LDLcelda* celda)
{
    printf("\n                          Mostrando Celda :\n");
    strucMostrar(celda->datoCelda);

    printf("\n                          Mostrando Lista :\n");
    LSPSmostrar(celda->listaCelda);
}


// LDL - agregar una celda al principio de LDL
LDLcelda* LDLagregarAlPpio(LDLcelda* lista, LDLcelda* nuevoNodo)
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
    return lista; // Se retorna la lista ya que hay que tener en cuenta que en el caso de que el primer primer if sea verdadero debemos retornarla, en el resto de los casos aunque trabajemos sobre el
}


// LDL - crear una celda LDL
LDLcelda* LDLcrearCelda(Struc datoCelda)
{
    LDLcelda* aux = (LDLcelda*) malloc(sizeof(LDLcelda));
    aux-> datoCelda = datoCelda;
    aux-> listaCelda = NULL;
    aux-> siguiente = NULL;

    return aux;
}


// LDL - buscar y devolver celda de lista por numero de datoCelda
LDLcelda* LDLbuscarNodoCelda(LDLcelda* LDL, Struc datoCelda)
{
    LDLcelda* seg = LDL;
    LDLcelda* rta = NULL;
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


// LDL - alta - funcion agregar uno
LDLcelda* LDLalta(LDLcelda* LDL, Struc datoCelda, Struc datoLista)
{
    nodoS* aux = LSPScrearNodo(datoLista);

    LDLcelda* rta = LDLbuscarNodoCelda(LDL, datoCelda);

    if(rta == NULL) //no existe dato de celda en lista de celdas
    {
        LDLcelda* nuevaCelda = LDLcrearCelda(datoCelda);
        LDL = LDLagregarAlPpio(LDL, nuevaCelda); // la agrego al ppio de la lista de celdas
        rta = LDL;// como el nodo lo agrege al principio directamente igualo rta a la lista, si lo agrego al final o en orden deberia encontrar nuevamente el nodo que agregamos para poder agregar la nota en la lista de notas
    }
    rta->listaCelda = LSPSagregarUnoFinal2(rta->listaCelda, aux);

    return LDL;
}


// LDL - agregar datos randoms a funcion alta
LDLcelda* LDLagregarRandom(LDLcelda* LDL, int cant)
{
    Struc datoCelda;
    Struc datoLista;

    for (int i=0; i<cant; i++)
    {
        datoCelda = strucCargarAuto();
        datoLista = strucCargarAuto();
        LDL = LDLalta(LDL, datoCelda, datoLista);
    }
    return LDL;
}


// LDL - inicializar
LDLcelda* LDLinic()
{
    return NULL;
}


// LDL - prueba LDL
void pruebaLDL()
{
    printf("\nListas De Listas : ok\n");
}




/// inicio borrar proyecto C

// LSPS - agregar nodo al final de lista sin llamar a funcion LSPSultimo()
nodoS* LSPSagregarUnoFinal2(nodoS* lista, nodoS* nuevoNodo)
{

    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        nodoS* aux = lista;
        if(aux)
        {
            while(aux->siguiente)
            {
                aux = aux->siguiente;
            }
        }
        aux->siguiente=nuevoNodo;   //rearmo
    }
    return lista;
}


// LSPS - mostrar lista/sublista/nodoS
void LSPSmostrar(nodoS* lista)
{
    if(lista)
    {
        nodoS* seguidora=lista;  //seguridad para no perder puntero lista dejandolo en cualquier lado al recorrer
        while(seguidora)
        {
            strucMostrar(seguidora->dato);
            seguidora=seguidora->siguiente;
        }
    }
    else
    {
        printf("La lista esta vacia...\n");
    }
}


// LSPS - agregar 1 nodo al principio de lista
nodoS* LSPSagregarUnoPpio(nodoS* lista, nodoS* nuevoNodo)
{
    if (lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}


// LSPS - crear 1 nodo
nodoS* LSPScrearNodo(Struc dato)
{
    nodoS* aux = (nodoS*) malloc(sizeof(nodoS));

    aux->dato=dato;
    aux->siguiente=NULL;

    return aux;
}


// LSPS - inicializar lista
nodoS* LSPSinic()
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

/// fin borrar proyecto C
