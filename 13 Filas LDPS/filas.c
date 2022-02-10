#include "filas.h"


//fila - LDPS - pasar de lista a fila por palabra
Fila listaAFilaPorPalabra(nodoD* lista, char palabra[], Fila* fila)
{
    if(lista)
    {
        while(lista)
        {
            if(strcmpi(lista-> dato.palabra, palabra) == 0)
            {
                filaAgregarUno(fila, lista->dato);
            }
            lista = lista-> siguiente;
        }
    }
    else
    {
        printf("\nla lista esta vacia...\n");
    }
    return *fila;
}


//fila - LDPS - dice si la fila esta vacia
int filaVacia(Fila* fila)
{
    int rta = LDPSlistaVacia(fila-> inicio);
    return rta;
}


//fila - LDPS - retornar primer numero
int filaPrimero(Fila* fila)
{
    int rta = -99999;
    if(fila-> inicio)
    {
        rta = LDPSretornarPrimerNumero(fila-> inicio);
    }
    return rta;
}


//fila - LDPS - retornar primer numero y borrar primer nodo
int filaExtraer(Fila* fila)
{
    int rta = LDPSretornarPrimerNumero(fila->inicio);
    fila-> inicio = LDPSborrarPrimerNodo(fila-> inicio);

    if(fila-> inicio == NULL)
    {
        fila-> fin = LDPSinic();
    }

    return rta;
}


//fila - LDPS - agregar uno a mano a fila
void filaLeer(Fila* fila)
{
    Struc dato = strucCargarAMano();

    filaAgregarUno(fila, dato);
}


//fila - LDPS - agregar varios a fila automaticamente
void filaAgregarVariosAuto(Fila* fila, int cant)
{
    Struc dato;
    for (int i=0; i<cant; i++)
    {
        dato = strucCargarAuto();
        filaAgregarUno(fila, dato);
    }
}


// fila - LDPS - mostrar
void filaMostrar(Fila* fila)
{
    LDPSmostrar(fila-> inicio);
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


// fila - LDPS - inicializar
void filaInic(Fila* fila)
{
    fila-> inicio = LDPSinic();
    fila-> fin = LDPSinic();
}

// fila - prueba
void pruebaFilasLSPS()
{
    printf("\nfilas - LSPS : ok\n");
}


/// -----inicio borrar al pasar a proyecto C-----------------------------------------



// LDPS - agregar varios al final auto
nodoD* LDPSagregarVariosFinalAuto(nodoD* lista, int cant)
{
    Struc dato;
    nodoD* nuevoNodo;

    for (int i=0; i<cant; i++)
    {
        dato = strucCargarAuto();
        nuevoNodo = LDPScrearNodo(dato);
        lista = LDPSagregarUnoFinal(lista, nuevoNodo);
    }
    return lista;
}


// LDPS - lista vacia
int LDPSlistaVacia(nodoD* lista)
{
    int rta=0;
    if(lista == NULL)
    {
        rta = 1;
    }
    return rta;
}


// LDPS - retornar primer numero de lista
int LDPSretornarPrimerNumero(nodoD* lista)
{
    int rta = 0;
    if(lista)
    {
        rta = lista-> dato.numero;
    }
    else
    {
        printf("\nla lista esta vacia... Se retorna 0\n");
    }
    return rta;
}


// LDPS - borrar primer nodo
nodoD* LDPSborrarPrimerNodo(nodoD* lista)
{
    if(lista)
    {
        nodoD* aBorrar = lista;
        lista = lista-> siguiente; // lista ahora apunta al siguiente nodo
        if(lista != NULL)
        {
            lista-> anterior = NULL; // nueva linea
        }
        free(aBorrar);
    }else
    {
        printf("\nla lista esta vacia...\n");
    }

    return lista;
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

    char nombres[26][20]={"Hoplita Pesado","Elasti-cop","Avalancha","Guada","Isla remota","Junior San","Cleo","Dylan","Beto","Fran","Karen","Lullabies","Manicho","Naricitas","Osvaldo","Zulu hip hop","Quesito","Rastaman","Sushi","Tutan kamon","Uvita","Vino","Waka waka","Xilofon","YIFY","Pancito Relleno"};
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
/// ------------fin borrar al pasar a proyecto C-------------------------------------
