#include "LDA.h"



//


// LDA - buscar por palabra en arbol de cada celda
void LDAbuscarPalabraEnArboles(LDAcelda* LDA, char dato[])
{
    nodoArbol* rta = NULL;

    if(LDA) //si hay lda
    {
        LDAcelda* seguidora = LDA; //seguridad para lda

        while(seguidora)    //porque es lista //aca puede ir flag para frenar la iteracion entre celdas al encontrar
        {
            if(seguidora->arbolCelda)    //si en cada celda de la lista hay un arbol (se saca si se quiere buscar en los datos de la celda o se cambia por algun dato de la celda)
            {
                rta = arbolBuscarPorPalabra(seguidora->arbolCelda, dato);   //aca van las funciones de arboles

                if(rta) //si lo encontro
                {
                    printf("\nEncontrado...\n");
                    LDAmostrarCelda(seguidora);
                }
            }
            seguidora = seguidora->siguiente;   //avanzo sobre las celdas
        }
    }
}


// LDA - pasar de archivo a LDA
LDAcelda* LDAarchivoALDA(char archivo[], LDAcelda* LDA)
{
    FILE *arch = fopen(archivo, "r");
    LDAarchivo registroArchivo;

    Struc datoCelda;
    Struc datoArbol;

    if(arch)
    {
        while(fread(&registroArchivo, sizeof(LDAarchivo), 1, arch) > 0)
        {
            datoCelda = registroArchivo.datoCelda;
            datoArbol = registroArchivo.datoArbol;
            LDA = LDAalta(LDA, datoCelda, datoArbol);
        }
        fclose(arch);
    }
    else
    {
        printf("\nerror en archivo : LDAarchivoALDA\n");
    }
    return LDA;
}


// LDA - archivo - mostrar
void LDAarchivoMostrar(char archivo[])
{
    FILE* arch = fopen(archivo, "r");

    LDAarchivo registroArchivo;

    if(arch)
    {
        while(fread(&registroArchivo, sizeof(LDAarchivo), 1, arch) > 0)
        {
            printf("\n            Mostrando Celda Archivo :\n");
            strucMostrar(registroArchivo.datoCelda);
            printf("\n            Mostrando Arbol Archivo :\n");
            strucMostrar(registroArchivo.datoArbol);
        }
        fclose(arch);
    }
}



//LDA - arbol - pasar arbol a archivo
FILE* arbolAArchivo(nodoArbol* arbol, FILE* arch, LDAarchivo registroArchivo)
{
    if(arbol)
    {
        registroArchivo.datoArbol = arbol->dato;

        fwrite(&registroArchivo, sizeof(LDAarchivo), 1, arch);
        arbolAArchivo(arbol-> izq, arch, registroArchivo);
        arbolAArchivo(arbol-> der, arch, registroArchivo);
    }
    return arch;
}


// LDA - de LDA a archivo
void LDAaArchivo(char archivo[], LDAcelda* LDA)
{
    FILE* arch = fopen(archivo, "a");
    LDAarchivo registroArchivo;
    LDAcelda* seguidoraCelda = LDA;

    if(arch)
    {
        while(seguidoraCelda)
        {
            registroArchivo.datoCelda = seguidoraCelda->datoCelda;
            arch = arbolAArchivo(seguidoraCelda->arbolCelda, arch, registroArchivo);

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
void LDAmostrar(LDAcelda* lista)
{
    if(lista)
    {
        LDAcelda* seguidora = lista;

        while(seguidora)
        {
            LDAmostrarCelda(seguidora);
            seguidora = seguidora-> siguiente; // me muevo hacia el siguiente nodo en la lista
        }
    }
    else
    {
        printf("\nLa lista esta vacia...\n");
    }
}


// LDL - mostrar celda
void LDAmostrarCelda(LDAcelda* celda)
{
    printf("\n                          Mostrando Celda :\n");
    strucMostrar(celda->datoCelda);

    printf("\n                          Mostrando Arbol :\n");
//    arbolDibujar(celda->arbolCelda);
    arbolMostrarPreOrder(celda->arbolCelda);
}


// LDL - agregar datos randoms a funcion alta
LDAcelda* LDAagregarRandom(LDAcelda* LDA, int cant)
{
    Struc datoCelda;
    Struc datoLista;

    for (int i=0; i<cant; i++)
    {
        datoCelda = strucCargarAuto();
        datoLista = strucCargarAuto();
        LDA = LDAalta(LDA, datoCelda, datoLista);
    }
    return LDA;
}


// LDL - alta - funcion agregar uno
LDAcelda* LDAalta(LDAcelda* LDA, Struc datoCelda, Struc datoLista)
{


    LDAcelda* rta = LDAbuscarNodoCelda(LDA, datoCelda);

    if(rta == NULL) //no existe dato de celda en lista de celdas
    {
        LDAcelda* nuevaCelda = LDAcrearCelda(datoCelda);
        LDA = LDLagregarAlPpio(LDA, nuevaCelda); // la agrego al ppio de la lista de celdas
        rta = LDA;// como el nodo lo agrege al principio directamente igualo rta a la lista, si lo agrego al final o en orden deberia encontrar nuevamente el nodo que agregamos para poder agregar la nota en la lista de notas
    }
    nodoArbol* aux = arbolNodoCrear(datoLista);
    rta->arbolCelda = arbolAgregarUnoOrdenandoPorNumero(rta->arbolCelda, aux);

    return LDA;
}


// LDL - buscar y devolver celda de lista por numero de datoCelda
LDAcelda* LDAbuscarNodoCelda(LDAcelda* LDL, Struc datoCelda)
{
    LDAcelda* seg = LDL;
    LDAcelda* rta = NULL;
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


// LDA - agregar una celda al principio de LDL
LDAcelda* LDLagregarAlPpio(LDAcelda* lista, LDAcelda* nuevoNodo)
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

// LDA - crear una celda LDL
LDAcelda* LDAcrearCelda(Struc datoCelda)
{
    LDAcelda* aux = (LDAcelda*) malloc(sizeof(LDAcelda));
    aux-> datoCelda = datoCelda;
    aux-> arbolCelda = arbolInic();
    aux-> siguiente = NULL;

    return aux;
}


// LDA - inicializar
LDAcelda* LDAinic()
{
    return NULL;
}


// LDA - prueba Lista De Arboles
void pruebaLDA()
{
    printf("\nPrueba LDA : ok\n");
}


/// inicio borrar en proyecto C

//arbol - buscar por palabra - para arbol ordenado por numero
nodoArbol* arbolBuscarPorPalabra(nodoArbol* arbol, char palabra[])
{
    nodoArbol* rta = NULL;
    if(arbol)   //si esta primero (en la pos actual de la celda)
    {
        if(strcmpi(palabra, arbol-> dato.palabra) == 0)
        {
            rta = arbol;
        }
        else    //si no esta primero
        {
            rta = arbolBuscarPorPalabra(arbol-> izq, palabra);
            if(rta == NULL)  // en caso de que lo haya encontrado en el lado izquierdo me ahorro recorrer el lado derecho
            {
                rta = arbolBuscarPorPalabra(arbol-> der, palabra);
            }
        }
    }
    return rta;
}


//arbol - mostrar en preOrder (raiz, izq, der)
void arbolMostrarPreOrder(nodoArbol* arbol)
{
    if(arbol)
    {
        strucMostrar(arbol-> dato);
        arbolMostrarPreOrder(arbol-> izq);
        arbolMostrarPreOrder(arbol-> der);
    }
}


//arbol - dibujar
void arbolDibujar(nodoArbol *tree)
{
    int cantFilas=10;        //20 filas para 30 nodos   //alto destinado al dibujo, si dibujo > alto destinado : error
    char s[cantFilas][255];
    //creo una matriz de char para hacer mi "dibujo"
    for (int i = 0; i < cantFilas; i++)
        sprintf(s[i], "%60s", "");      // || "%20s" --> 6 nodos  || "%60s" --> 10 nodos || "%200s" -->30 nodos

    _print_t(tree, 0, 0, 0, s);

    //Imprimo matris
    for (int i = 0; i < cantFilas; i++)
        printf("%s\n", s[i]);
}


//arbol - dibujar arbol aux
int _print_t(nodoArbol *tree, int is_left, int offset, int depth, char s[20][255])
{
    char b[20];
    int width = 5;  //es el ancho del nodo que dibujo

    if (!tree) return 0;

    sprintf(b, "(%3d)", tree->dato.numero);    //paso valor int con 3 espacios decimales

    int left  = _print_t(tree->izq,  1, offset,                depth + 1, s);
    int right = _print_t(tree->der, 0, offset + left + width, depth + 1, s);

    //dibujo nodo
#ifdef COMPACT
    for (int i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    //dibujo lineas
    if (depth && is_left)
    {

        for (int i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';

    }
    else if (depth && !is_left)
    {

        for (int i = 0; i < left + width; i++)
            s[depth - 1][offset - width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';
    }
#else
    for (int i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left)
    {

        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';

    }
    else if (depth && !is_left)
    {

        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }
#endif

    return left + width + right;
}


//arbol - insertar 1 nodo al arbol ordenando por campo numero
nodoArbol* arbolAgregarUnoOrdenandoPorNumero(nodoArbol* arbol, nodoArbol* nuevoNodo)
{
    if(arbol == NULL)
    {
        arbol = nuevoNodo;
    }
    else
    {
        if(nuevoNodo->dato.numero <= arbol-> dato.numero)
        {
            arbol-> izq = arbolAgregarUnoOrdenandoPorNumero(arbol-> izq, nuevoNodo);
        }
        else
        {
            arbol-> der = arbolAgregarUnoOrdenandoPorNumero(arbol-> der, nuevoNodo);
        }
    }
    return arbol;
}


//arbol - crear 1 nodo
nodoArbol* arbolNodoCrear(Struc dato)
{
    nodoArbol* aux = (nodoArbol*)malloc(sizeof(nodoArbol));
    aux-> dato = dato;
    aux-> izq = NULL;
    aux-> der = NULL;

    return aux;
}


// arbol - inicializar puntero arbol
nodoArbol* arbolInic()
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

/// fin borrar en proyecto C
