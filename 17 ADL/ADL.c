#include "ADL.h"


// ADL - de ADL a archivo por celda
void ADLaArchivoPorCeldaPorPalabra(char archivo[], ADLCelda arreglo[], int validos, char palabra[])
{
    FILE *arch = fopen(archivo, "a");
    strucArchivo nuevoRegistro;
    int i = 0;
    int flag = 0;

    if(arch)
    {
        while(flag == 0 && i < validos)
        {
            if(strcmpi(arreglo[i].datoCelda.palabra, palabra) == 0)
            {
                if(arreglo[i].listaCelda)
                {
                    nodoS* seguidora = arreglo[i].listaCelda;
                    while(seguidora)
                    {
                        nuevoRegistro.datoCelda = arreglo[i].datoCelda;
                        nuevoRegistro.datoLista = seguidora->dato;
                        fwrite(&nuevoRegistro, sizeof(strucArchivo), 1, arch);
                        seguidora = seguidora->siguiente;
                    }
                }
                flag = 1;
            }
            i++;
        }
        if(flag == 0)
        {
            printf("\nNo se encontro la palabra\n");
        }
        fclose(arch);
    }
    else
    {
        printf("El archivo en NULL");
    }
}


// ADL - pasar arbol a ADL
int arbolToADL(nodoArbol* arbol, ADLCelda arreglo[], int dimension, int validos)
{
    if(arbol)
    {
        validos = ADLalta(arreglo, dimension, validos, arbol->dato, arbol->dato);   //se repite la data por como estan hechas las estructuras y paja cambiar - el orden de alta,validos, validos le da un comportamiento preOrder
        validos = arbolToADL(arbol->izq, arreglo, dimension, validos);
        validos = arbolToADL(arbol->der, arreglo, dimension, validos);
    }
    return validos;
}


int ADLbuscarEnDatosCelda(ADLCelda arreglo[], int validos, int pos, char palabra[])
{
    if(validos == 0)
    {
        if(strcmpi(arreglo[validos].datoCelda.palabra, palabra) == 0)
        {
            pos = validos;
        }
        pos = pos + 0;
    }
    else
    {
        if(strcmpi(arreglo[validos].datoCelda.palabra, palabra) == 0)
        {
            pos = validos;
        }
        pos = ADLbuscarEnDatosCelda(arreglo, validos-1, pos, palabra);
    }
    return pos;
}


// ADL - contar cant de elementos lista por celda
void ADLcontar(ADLCelda arreglo[], int validos)
{
    for (int i=0; i<validos; i++)
    {
        printf("\n            Mostrando Celda %i :\n",i);
        strucMostrar(arreglo[i].datoCelda);
        printf("\nCant elementos de esta celda : %i\n",LSPScontarNodos(arreglo[i].listaCelda));
    }
}


// ADL - buscar por palabra
int ADLbuscarEnDatosLista(ADLCelda arreglo[], int validos, char palabra[])
{
    int rta = 0;
    nodoS* aux;
    for (int i=0; i < validos && rta == 0; i++)
    {
        aux = LSPSbuscarPorPalabra(arreglo[i].listaCelda,palabra);

        if(aux)
        {
            rta = 1;
            printf("\nPalabra en celda : %i\n",i);
        }
    }
    return rta;
}


// ADL - inicializar ADL
void ADLinic(ADLCelda arreglo[], int dim)
{
    for(int i= 0; i<dim; i++)
    {
        arreglo[i].datoCelda.numero = 0;
        arreglo[i].datoCelda.letra = '-';
        strcpy(arreglo[i].datoCelda.palabra, "vacio");

        arreglo[i].listaCelda = LSPSinic();
    }
}


// ADL - de arreglo de strucs a archivo
void ADLaArchivo(char archivoAAbrir[], ADLCelda arreglo[], int validos)
{
    FILE *arch = fopen(archivoAAbrir, "a");
    strucArchivo nuevoRegistro;
    int i = 0;

    if(arch)
    {
        while(i < validos)
        {
            while(arreglo[i].listaCelda)
            {
                // aca puede ir condicion
                nuevoRegistro.datoLista = arreglo[i].listaCelda-> dato;
                nuevoRegistro.datoCelda = arreglo[i].datoCelda;
                fwrite(&nuevoRegistro, sizeof(strucArchivo), 1, arch);
                //
                arreglo[i].listaCelda = arreglo[i].listaCelda-> siguiente;
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


// ADL - agregar en celdas 0 a 9 datos de lista
int ADLagregarRandom(ADLCelda arreglo[],int dimension, int validos, int cant)
{
    Struc datoCelda;
    Struc datoLista;

    for (int i=0; i<cant; i++)
    {
        datoCelda = strucCargarAuto();
        datoLista = strucCargarAuto();
        validos = ADLalta(arreglo, dimension, validos, datoCelda, datoLista);
    }
    return validos;
}



// ADL - pasar archivo a arreglo de listas
int ADLarchivoAADL(char archivoAAbrir[], ADLCelda arreglo[], int dimension, int validos)
{
    FILE *arch = fopen(archivoAAbrir, "r");  //abre archivo

    strucArchivo nuevoRegistro;
    Struc datoCelda;
    Struc datoLista;

    if(arch)
    {
        while(fread(&nuevoRegistro, sizeof(strucArchivo), 1, arch) > 0 && validos < dimension)
        {
            datoCelda = nuevoRegistro.datoCelda;
            datoLista = nuevoRegistro.datoLista;
            validos = ADLalta(arreglo, dimension,validos, datoCelda, datoLista);
        }
        fclose(arch);    //cierra archivo
    }
    else
    {
        printf("\narchivo no se pudo abrir...\n");
    }
    return validos;
}


// archivo struc - mostrar un archivo con 2 struc
void ADLarchivoStrucCompuestaMostrar(char archivo[])
{
    FILE *arch = fopen(archivo, "r");
    if(arch)
    {
        strucArchivo registroArchivo;
        while(fread(&registroArchivo, sizeof(registroArchivo), 1, arch) > 0)
        {
            printf("\n            Mostrando Celda Archivo :\n");
            strucMostrar(registroArchivo.datoCelda);
            printf("\n            Mostrando lista Archivo :\n");
            strucMostrar(registroArchivo.datoLista);
        }
    }
}


// archivo struc - cargar un archivo con varios registro de  2 struc
void ADLarchivoStrucCompuestaCargarVariosAuto(char archivo[], int cant, int *i)
{
    for (int j=0; j<cant; j++)
    {
        ADLarchivoStrucCompuestaCargarUnoAuto(archivo,&*i);
    }
}


// archivo struc - cargar un archivo con un registro de  2 struc
void ADLarchivoStrucCompuestaCargarUnoAuto(char archivo[], int *i)
{
    FILE *arch = fopen(archivo,"a");
    if(arch)
    {
        strucArchivo nuevoRegistro;

        nuevoRegistro.datoCelda = strucCargarAuto2(&*i);
        nuevoRegistro.datoLista = strucCargarAuto();

        fwrite(&nuevoRegistro, sizeof(nuevoRegistro), 1, arch);

        fclose(arch);
    }
    else
    {
        printf("\nError al abrir el archivo\n");
    }
}


// ADL - lista a ADL
int ADLagregarListaACelda(ADLCelda arreglo[], int dimension, int validos, Struc datoCelda, nodoS* lista)
{
    if(lista)
    {
        while(lista)
        {
            validos = ADLalta(arreglo, dimension, validos, datoCelda, lista->dato);   // el dato de la celda es siempre el mismo
            lista = lista->siguiente;
        }
    }
    else
    {
        printf("\nla lista esta vacia...\n");
    }
    return validos;
}


// ADL - mostrar - se muestra el dato de la celda y la lista de la celda
void ADLmostrar(ADLCelda arreglo[], int validos)
{
    for (int i=0; i<validos; i++)
    {
        printf("\n            Mostrando Celda %i :\n",i);
        strucMostrar(arreglo[i].datoCelda);
        printf("\n            Mostrando Lista %i :\n",i);
        LSPSmostrar(arreglo[i].listaCelda);
    }
}


// ADL - agregar celda ADL
int ADLagregarCelda(ADLCelda arreglo[], int validos, Struc datoCelda)
{
    arreglo[validos].datoCelda = datoCelda;     // el dato nuevo de celda se carga al final del arreglo en su celda creada para el y la lista
    arreglo[validos].listaCelda = LSPSinic();   // inicializo la lista de la celda agregada
    validos++;                                  // como agregamos una nueva celda en el arreglo, los validos incrementan
    return validos;
}


// ADL - buscar en arreglo si el dato de la celda existe y retornar posicion (para no repetir celdas)
int ADLposCelda(ADLCelda arreglo[], int validos, Struc datoCelda)
{
    int rta = -1;                       //si el dato de la celda no existe se devuelve -1
    int i = 0;
    while(i < validos && rta == -1)
    {
        if(arreglo[i].datoCelda.numero == datoCelda.numero)  // busca comparando los numeros de las celdas existentes con el nuevo dato de celda - los numeros del datoCelda deben ser unicos
        {
            rta = i;
        }
        i++;
    }
    return rta;
}


// ADL - alta - funcion agregar
int ADLalta(ADLCelda arreglo[], int dimension, int validos, Struc datoCelda, Struc datoLista)
{
    if(validos < dimension)
    {
        nodoS* aux = LSPScrearNodo(datoLista);                       //crear nodoS con dato de lista

        int pos = ADLposCelda(arreglo, validos, datoCelda);             // retornar posicion del dato celda en el arreglo y -1 si no existe

        if(pos == -1)                                               // el dato de la celda no esta en el arreglo
        {
            validos = ADLagregarCelda(arreglo, validos, datoCelda);    //agrego celda a arreglo con el dato
            pos = validos - 1;                                      // la celda quedo en la ultima posicion valida del arreglo
        }

        arreglo[pos].listaCelda = LSPSagregarUnoPpio(arreglo[pos].listaCelda, aux); // agrego a la lista de la celda el dato, se puede cambiar por agregar al final/principio
    }
    else
    {
        printf("\nvalidos = dimension... Se deja de cargar ADL\n");
    }
    return validos;
}


// ADL - prueba ADL
void pruebaADL()
{
    printf("\nArreglo de listas struc : ok\n");
}


///----------------inicio borrar en proyecto C

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
    int cantFilas=20;        //20 filas para 30 nodos
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


// LSPS - contar nodos de lista
int LSPScontarNodos(nodoS* lista)
{
    int contador=0;
    if(lista)
    {
        while(lista)
        {
            contador++;
            lista=lista->siguiente;
        }
    }
    else
    {
        printf("La lista esta vacia...\n");
    }
    return contador;
}




// LSPS - retornar sublista buscada por nodo por campo palabra
nodoS* LSPSbuscarPorPalabra(nodoS* lista, char dato[30])
{
    nodoS* aux = lista;
    if(aux)
    {
        while(aux && strcmpi(dato, aux->dato.palabra) != 0)
        {
            aux = aux-> siguiente;
        }
    }
    else
    {
        printf("\nla lista esta vacia...\n");
    }
    return aux;
}


// LSPS - cargar varios nodos al PRINCIPIO de la lista automaticamente
nodoS* LSPSagregarVariosPpioAuto(nodoS* lista, int cant)
{
    Struc dato;
    nodoS* nuevoNodo;

    for (int i=0; i<cant; i++)
    {
        dato = strucCargarAuto();
        nuevoNodo = LSPScrearNodo(dato);
        lista = LSPSagregarUnoPpio(lista, nuevoNodo);
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

///----------------fin borrar en proyecto C

/*

*/
