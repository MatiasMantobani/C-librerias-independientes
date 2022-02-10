#include "ADA.h"


// ADA - de ADA a archivo
void ADAaArchivoPorNumeroCelda(char archivo[], ADAcelda arreglo[], int validos, int dato)
{
    FILE *arch = fopen(archivo, "a");
    ADAarchivo nuevoRegistro;

    if(arch)
    {
        int i = 0;
        while(i < validos)
        {
            if(arreglo[i].datoCelda.numero == dato)
            {
                nuevoRegistro.datoCelda = arreglo[i].datoCelda;
                arch = arbolAArchivo(arreglo[i].arbolCelda, arch, nuevoRegistro);
            }
            i++;
        }
        fclose(arch);
    }
    else
    {
        printf("\nerror archivo : ADAaArchivo\n");
    }
}




// ADA - pasar archivo a ADA
int ADAarchivoAADA(char archivo[], ADAcelda arreglo[], int dimension, int validos)
{
    FILE *arch = fopen(archivo, "r");

    ADAarchivo nuevoRegistro;
    Struc datoCelda;
    Struc datoArbol;

    if(arch)
    {
        while(fread(&nuevoRegistro, sizeof(ADAarchivo), 1, arch) > 0 && validos < dimension)
        {
            datoCelda = nuevoRegistro.datoCelda;
            datoArbol = nuevoRegistro.datoArbol;
            validos = ADAalta(arreglo, dimension,validos, datoCelda, datoArbol);
        }
        fclose(arch);
    }
    else
    {
        printf("\nerror archivo : ADAarchivoAADA\n");
    }
    return validos;
}


//arbol - pasar arbol a archivo
FILE* arbolAArchivo(nodoArbol* arbol, FILE* arch, ADAarchivo nuevoRegistro)
{
    if(arbol)
    {
        nuevoRegistro.datoArbol = arbol->dato;

        fwrite(&nuevoRegistro, sizeof(ADAarchivo), 1, arch);
        arbolAArchivo(arbol-> izq, arch, nuevoRegistro);
        arbolAArchivo(arbol-> der, arch, nuevoRegistro);
    }
    return arch;
}


// ADA - de ADA a archivo
void ADAaArchivo(char archivo[], ADAcelda arreglo[], int validos)
{
    FILE *arch = fopen(archivo, "a");
    ADAarchivo nuevoRegistro;

    if(arch)
    {
        int i = 0;
        while(i < validos)
        {
            nuevoRegistro.datoCelda = arreglo[i].datoCelda;
            arch = arbolAArchivo(arreglo[i].arbolCelda, arch, nuevoRegistro);
            i++;
        }
        fclose(arch);
    }
    else
    {
        printf("\nerror archivo : ADAaArchivo\n");
    }
}


// ADA - archivo - mostrar
void ADAarchivoMostrar(char archivo[])
{
    FILE *arch = fopen(archivo, "r");
    if(arch)
    {
        ADAarchivo registroArchivo;
        while(fread(&registroArchivo, sizeof(registroArchivo), 1, arch) > 0)
        {
            printf("\n            Mostrando Celda Archivo :\n");
            strucMostrar(registroArchivo.datoCelda);
            printf("\n            Mostrando Arbol Archivo :\n");
            strucMostrar(registroArchivo.datoArbol);
        }
    }
}


// ADA - agregar celda ADL
int ADAagregarCelda(ADAcelda arreglo[], int validos, Struc datoCelda)
{
    arreglo[validos].datoCelda = datoCelda;
    arreglo[validos].arbolCelda = arbolInic();
    validos++;
    return validos;
}


// ADA - buscar en arreglo si el dato de la celda existe y retornar posicion (para no repetir celdas)
int ADAposCelda(ADAcelda arreglo[], int validos, Struc datoCelda)
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


// ADA - alta - funcion agregar uno
int ADAalta(ADAcelda arreglo[], int dimension, int validos, Struc datoCelda, Struc datoArbol)
{
    if(validos < dimension)
    {
        nodoArbol* aux = arbolNodoCrear(datoArbol);

        int pos = ADAposCelda(arreglo, validos, datoCelda);

        if(pos == -1)
        {
            validos = ADAagregarCelda(arreglo, validos, datoCelda);
            pos = validos - 1;
        }

        arreglo[pos].arbolCelda = arbolAgregarUnoOrdenandoPorNumero(arreglo[pos].arbolCelda, aux);
    }
    else
    {
        printf("\nerror en ADAalta : validos = dimension... Se deja de cargar en ADA\n");
    }
    return validos;
}




// ADA - agregar en celdas 0 a 9 datos de arbol
int ADAagregarRandom(ADAcelda arreglo[],int dimension, int validos,int cant)
{
    Struc datoCelda;
    Struc datoArbol;

    for (int i=0; i<cant; i++)
    {
        datoCelda = strucCargarAuto();
        datoArbol = strucCargarAuto();
        validos = ADAalta(arreglo, dimension, validos, datoCelda, datoArbol);
    }
    return validos;
}


// ADA - mostrar - se muestra el dato de la celda y el arbol de la celda
void ADAmostrar(ADAcelda arreglo[], int validos)
{
    for (int i=0; i<validos; i++)
    {
        printf("\n            Mostrando Celda %i :\n",i);
        strucMostrar(arreglo[i].datoCelda);
        printf("\n            Mostrando Arbol %i :\n",i);
        arbolDibujar(arreglo[i].arbolCelda);
//        arbolMostrarPreOrder(arreglo[i].arbolCelda);
    }
}


// ADA - inicializar datos celda en 0 y arbol en NULL
void ADAinic(ADAcelda arreglo[], int dim)
{
    for(int i= 0; i<dim; i++)
    {
        arreglo[i].datoCelda.numero = 0;
        arreglo[i].datoCelda.letra = '-';
        strcpy(arreglo[i].datoCelda.palabra, "vacio");

        arreglo[i].arbolCelda = arbolInic();
    }
}


// ADA - prueba Arreglo De Arboles
void pruebaADA()
{
    printf("\nPrueba ADA : ok\n");
}

/// inicio borrar en proyecto C

//arbol - contar cant de nodos - corta
int arbolContarNodos(nodoArbol* arbol)
{
    int rta = 0;
    if(arbol)
    {
        rta = 1 + arbolContarNodos(arbol-> izq) + arbolContarNodos(arbol-> der);
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
    int cantFilas=30;        //20 filas para 30 nodos   //alto destinado al dibujo // si dibujo > alto entonces error
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


//arbol - cargar varios nodos arbol al arbol ordenando por numero
nodoArbol* arbolAgregarVariosOrdenandoPorNumero(nodoArbol* arbol, int cant)
{
    Struc dato;
    nodoArbol* aux;

    for (int i=0; i<cant; i++)
    {
        dato = strucCargarAuto();
        aux = arbolNodoCrear(dato);
        arbol=arbolAgregarUnoOrdenandoPorNumero(arbol,aux);
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


// struc - cargar automatico 2 - manejado por variable global para no repetir
Struc strucCargarAuto2(int *i)
{
    Struc aux;

    // num
    aux.numero = *i;
    // letra
    char letras[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    aux.letra = letras[*i];
    // palabra
    char palabra[26][20]= {"Primero","Segundo","Tercero","Cuarto","Quinto","Sexto","Octavo","Noveno","Decimo","Decimo","Undecimo","Duodecimo","Decimotercero","Decimocuarto","Decimoquinto","Decimosexto","Decimoséptimo","Decimoctavo","Decimonoveno","Vigésimo"};
    strcpy(aux.palabra,palabra[*i]);

    (*i)++;
    return aux;
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
/// fin borrar en proyecto C
