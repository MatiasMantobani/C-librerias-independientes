#include "pilasLSPS.h"


// pila - LSPS - de lista a pila (recordar que el primero de lista entra primero y queda en el fondo de la pila)
void LSPSpasarAPilaLSPS(nodoS** pila, nodoS* lista)
{
    if(lista)
    {
        while(lista)
        {
            pilasLSPSapilar(pila, lista->dato);
            lista = lista-> siguiente;
        }
    }
    else
    {
        printf("\nla lista esta vacia...\n");
    }
}


// pila - LSPS - de pila a lista sin perder pila original ni orden
nodoS* pilasLSPSpasarALista(nodoS* lista, nodoS** pila)
{
    nodoS* aux;
    Struc dato;

    nodoS* auxPila;   //pila aux para no perder la pila original al desapilar
    pilasLSPSinic(&auxPila);

    while(!pilasLSPSvacia(pila)) //de pila a : lista y pila aux
    {
        //aca puede ir un if() para elegir cuales pasar
        dato = pilasLSPSdesapilar(pila);
        aux = LSPScrearNodo(dato);
        lista = LSPSagregarUnoPpio(lista, aux);

        pilasLSPSapilar(&auxPila,dato);
    }
    while(!pilasLSPSvacia(&auxPila)) //de pila aux a pila
    {
        pilasLSPSapilar(pila, pilasLSPSdesapilar(&auxPila));
    }
    return lista;
}


// pila - LSPS - cargar uno a pila a mano
void pilasLSPSleer(nodoS** pila)
{
    Struc dato = strucCargarAMano();
    pilasLSPSapilar(pila,dato);
}


// pila - LSPS - pila vacia
int pilasLSPSvacia(nodoS** pila)
{
    int rta=1;
    if(*pila)
    {
        rta=0;
    }
    return rta;
}


// pila - LSPS - mostrar valor de tope
Struc pilasLSPStope(nodoS** pila)
{
    Struc valorTope=LSPSretornarPrimerStruc(*pila);
    return valorTope;
}


// pila - LSPS - desapilar uno
Struc pilasLSPSdesapilar(nodoS** pila)
{
    Struc dato = LSPSretornarPrimerStruc(*pila);
    *pila=LSPSborrarPrimero(*pila);
    return dato;
}


// pila - LSPS - mostrar
void pilasLSPSmostrar(nodoS** pila)
{
    LSPSmostrar(*pila);
}


// pila - LSPS - apilar varios
void pilasLSPSapilarVarios(nodoS** pila,int cant)
{
    Struc dato;
    for (int i=0; i<cant; i++)
    {
        dato = strucCargarAuto();
        pilasLSPSapilar(pila,dato);

    }
}


// pila - LSPS - apilar uno
void pilasLSPSapilar(nodoS** pila, Struc dato)
{
    nodoS* nuevoNodo=LSPScrearNodo(dato);
    *pila=LSPSagregarUnoPpio(*pila, nuevoNodo);
}


// pila - LSPS - inicializar pila
void pilasLSPSinic(nodoS** pila)
{
    *pila=LSPSinic(*pila);
}


// pilas - prueba
void pruebaPilasLSPS()
{
    printf("\npilas - LSPS : ok\n");
}


/// ------------inicio borrar al pasar a proyecto C----------------------------------
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


// LSPS - retornar primer struc
Struc LSPSretornarPrimerStruc(nodoS* lista)
{
    Struc dato;
    if(lista)
    {
        dato=lista->dato;
    }
    else
    {
        dato.numero = 0;
        dato.letra = '-';
        strcpy(dato.palabra,"-");
        printf("\nLa pila esta vacia... el valor devuelto es basura\n");
    }
    return dato;
}


// LSPS - eliminar primer nodo
nodoS* LSPSborrarPrimero(nodoS* lista)
{
    if(lista)   //la lista tiene elementos
    {
        nodoS* aBorrar = lista;
        lista = lista->siguiente;
        free(aBorrar);
    }
    else
    {
        printf("La lista esta vacia...\n");
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

    char nombres[26][20]= {"Hoplita Pesado","El negro","Alvaro","Guada","Isla remota","Junior","Cleo","Dylan","Beto","Fran","Karen","La Sheni","Manicho","Naricitas","Osvaldo","Zulu hip hop","Quesito","Rastaman","Sushi","Tutan kamon","Uvita","Vino","Waka waka","Xilofon","YIFY","Pancito Relleno"};
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
/// ------------fin borrar al pasar a proyecto C-------------------------------------
