#include "LSPD.h"

// LSPD - retornar ultimo nodo sin desvincular de lista
void LSPDultimo(nodoS** lista, nodoS** ultimo)
{
    *ultimo = *lista;
    if(*ultimo)
    {
        while((*ultimo)-> siguiente)
        {
            *ultimo = (*ultimo)-> siguiente;
        }
    }
}


// LSPD - invertir lista
void LSPDinvertir(nodoS** lista)
{
    if(*lista)
    {
        nodoS* invertida;
        LSPDinic(&invertida);
        nodoS* aux;
        nodoS* seguidora = *lista;

        while(seguidora)
        {
            LSPDcrearNodo(seguidora->dato,&aux);
            LSPDagregarUnoPpio(&invertida,aux);
            seguidora = seguidora-> siguiente;
        }
        *lista = invertida;
    }
    else
    {
        printf("La lista esta vacia...\n");
    }
}


// LSPD - borrar y retornar por numero
Struc LSPDborrarYretornarStrucPorNumero(nodoS** lista, int dato)
{
    Struc struc;
    if(*lista)
    {
        nodoS* aux;
        if((*lista)-> dato.numero == dato)
        {
            struc = (*lista)-> dato;
            aux = *lista;
            *lista = (*lista)-> siguiente;
            free(aux);
        }
        else
        {
            nodoS* anterior = *lista;
            nodoS* seguidora = (*lista)-> siguiente;
            while(seguidora && seguidora-> dato.numero != dato)
            {
                anterior = seguidora;
                seguidora = seguidora-> siguiente;
            }
            if(seguidora)
            {
                struc = seguidora-> dato;
                aux = seguidora;
                anterior-> siguiente = seguidora-> siguiente;
                free(aux);
            }
            if(seguidora == NULL)   //si no existe en lista
            {
                printf("\nNumero no encontrado... se devuelve basura\n");
                struc.numero = 0;
                struc.letra = '-';
                strcpy(struc.palabra,"-");
            }
        }
    }
    return struc;
}


// LSPD - borrar primer nodo de lista
void LSPDborrarPrimerNodo (nodoS** lista)
{
    if(*lista)
    {
        nodoS * aux=(*lista);
        (*lista)=(*lista)->siguiente;
        aux->siguiente=NULL;
        free(aux);
    }
    else
    {
        printf("La lista esta vacia...\n");
    }
}


// LSPD - desvincular primer nodo de lista y devolverlo
nodoS * LSPDdesvincularYretornarPrimerNodo(nodoS ** lista)
{
    nodoS *aux= *lista; // le asigno a aux lo que esta siendo apuntado por pLista
    if (*lista)         //si *lista es !=NULL
    {
        *lista = (*lista)->siguiente;// enlaza la lista con el segundo elemento

        aux->siguiente=NULL; // setea en NULL el siguiente del que era el primer elemento
    }
    else
    {
        printf("La lista esta vacia...\n");
    }
    return aux;
}


// LSPD - inicializar lista/nodo
void LSPDinic(nodoS** lista)    //se recibe el & desde main con **
{
    *lista = NULL;              //se modifica con * delante
}

// LSPD - crear nodo
void LSPDcrearNodo(Struc dato, nodoS** aux)
{
    *aux = (nodoS*) malloc(sizeof(nodoS));
    (*aux)->dato = dato;
    (*aux)->siguiente = NULL;
}

// LSPD - agregar uno al principio
void LSPDagregarUnoPpio(nodoS** lista, nodoS* nuevoNodo)
{
    if(*lista == NULL)
    {
        *lista = nuevoNodo; // en caso de que no haya nodos en la lista, el puntero lista guarda la direccion de memoria del nuevoNodo
    }
    else
    {
        nuevoNodo-> siguiente = *lista; // el nuevo nodo queda apuntando a lo que previamente se encontraba en primer lugar de la lista
        *lista = nuevoNodo; // el primer nodo de la lista ahora seria el nuevoNodo que agregamos recien
    }
}


// mostrar lista/sublista/nodoS
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

// LSPD - agregar uno al final
void LSPDagregarUnoFinal(nodoS** lista, nodoS* nuevoNodo)
{
    if(*lista == NULL)
    {
        *lista = nuevoNodo;
    }
    else
    {
        nodoS* aux = *lista;
        if(aux)
        {
            while(aux-> siguiente != NULL)
            {
                aux = aux-> siguiente; // itero hasta llegar al final de la lista
            }
        }
        aux-> siguiente = nuevoNodo; // hago que el nodo que apuntaba a NULL previamente ahora apunte al nuevoNodo
    }
}


// agregar varios nodos al PRINCIPIO de la lista automaticamente
void LSPDagregarVariosPpioAuto(nodoS** lista, int cant)
{
    Struc dato;
    nodoS* aux;

    for (int i=0; i<cant; i++)
    {
        dato = strucCargarAuto();
        LSPDcrearNodo(dato, &aux);
        LSPDagregarUnoPpio(lista, aux); //no va &lista ya que ya es un puntero doble
    }
}


// agregar varios nodos al PRINCIPIO de la lista automaticamente
void LSPDagregarVariosFinalAuto(nodoS** lista, int cant)
{
    Struc dato;
    nodoS* aux;

    for (int i=0; i<cant; i++)
    {
        dato = strucCargarAuto();
        LSPDcrearNodo(dato, &aux);
        LSPDagregarUnoFinal(lista, aux);
    }
}


// LSPD - agregar uno ordenado por numero a lista
void LSPDagregarUnoOrdenadamentePorNumero(nodoS** lista, nodoS* nuevoNodo)
{
    if(*lista == NULL)
    {
        *lista = nuevoNodo;
    }
    else
    {
        if((*lista)-> dato.numero > nuevoNodo-> dato.numero)  // este caso seria que el dato que queremos ingresar es menor que el primer dato de la lista
        {
            nuevoNodo-> siguiente = *lista; // el nodo que ingresa ahora apunta al primer nodo de la lista
            *lista = nuevoNodo; // la lista comienza desde el nuevoNodo ya que quedo en la primera posicion de la lista
        }
        else   // se encuentra en otra posicion que no sea la primera
        {
            nodoS* anterior = *lista; // necesitamos el anterior y el siguiente, ya que una vez que borremos el nodo que esta en el medio de estos dos hay que conectarlos entre ellos
            nodoS* seguidora = (*lista)-> siguiente; // necesitamos el anterior y el siguiente, ya que una vez que borremos el nodo que esta en el medio de estos dos hay que conectarlos entre ellos

            while(seguidora != NULL && (seguidora-> dato.numero) < (nuevoNodo-> dato.numero))  // verifico que seguidora no sea NULL y que el dato de seguidora sea menor al del nuevoNodo
            {
                anterior = seguidora;             //hasta que no se cumpla la condicion del while muevo el anterior y la seguidora
                seguidora = seguidora->siguiente;
            }
            nuevoNodo-> siguiente = seguidora; // el nuevo nodo queda apuntando hacia donde quedo siguiente
            anterior-> siguiente = nuevoNodo; // el nuevo nodo es apuntado por donde quedo anterior
        }
    }
}


// LSPD - agregar varios nodos ordenados por numero a la lista de forma automatica
void LSPDagregarVariosOrdenadamenteAuto(nodoS** lista, int cant)
{
    Struc dato;
    nodoS* aux;

    for (int i=0; i<cant; i++)
    {
        dato = strucCargarAuto();
        LSPDcrearNodo(dato, &aux);
        LSPDagregarUnoOrdenadamentePorNumero(lista, aux);
    }
}


// LSPD - muestra un nodo por numero
void LSPDmostrarNodoPorNumero(nodoS** lista, int dato)
{
    nodoS* aux = *lista;

    if(*lista)
    {
        while(aux && aux->dato.numero != dato)
        {
            aux = aux-> siguiente;
        }
        if(aux)
        {
            strucMostrar(aux-> dato);
        }
        else
        {
            printf("\nnodo no encontrado...\n");
        }
    }
    else
    {
        printf("La lista esta vacia...\n");
    }
}


void LSPDborrarPorNumero(nodoS** lista, int dato)
{
    if(*lista)  // verifico que la lista no sea NULL
    {
        if((*lista)-> dato.numero == dato)  // en caso de que el dato a eliminar sea el primero en la lista
        {
            nodoS* aBorrar = *lista; // guardo la direccion de memoria del elemento a borrar
            *lista = (*lista)-> siguiente; // La lista ahora queda apuntando al siguiente nodo, haciendolo el primer elemento de la lista
            free(aBorrar); // libera el espacio de memoria del nodo que queriamos borrar
        }
        else   // en caso de que el elemento no sea el primero en la lista
        {
            nodoS* anterior = *lista; // necesitamos el anterior y el siguiente, ya que una vez que borremos el nodo que esta en el medio de estos dos hay que conectarlos entre ellos
            nodoS* seguidora = (*lista)-> siguiente; // necesitamos el anterior y el siguiente, ya que una vez que borremos el nodo que esta en el medio de estos dos hay que conectarlos entre ellos

            while(seguidora != NULL && seguidora-> dato.numero != dato)  // verifico que seguidora no sea NULL y que el dato de seguidora sea desigual al del nuevoNodo
            {
                anterior = seguidora;             //hasta que no encuentro el dato muevo la pareja
                seguidora = seguidora->siguiente;
            }

            if(seguidora != NULL)  // si luego de iterar se encuentra lo que estamos buscando lo borramos
            {
                anterior-> siguiente = seguidora-> siguiente; // hago la conceccion y ahora antes queda apuntando a lo que apuntaba siguiente, ya que siguiente lo vamos a eliminar de la lista
                free(seguidora); // el elemento que queremos borrar quedo almacenado en seguidora
            }
            else
            {
                printf("\nnumero a borrar no encontrado\n");
            }
        }
    }
    else
    {
        printf("La lista esta vacia...\n");
    }
}


//borrar lista completa
void LSPDborrarLista(nodoS** lista)
{
    if(*lista)
    {
        nodoS* aBorrar;
        while(*lista)
        {
            aBorrar=*lista;
            *lista=(*lista)->siguiente;
            free(aBorrar);
        }
        printf("Se borro la lista...\n");
    }
    else
    {
        printf("La lista esta vacia...\n");
    }
}


void pruebaLSPS()
{
    printf("\nLSPD : ok\n");
}


/// ------------inicio borrar al pasar a proyecto C----------------------------------

// struc - mostrar
void strucMostrar(Struc dato)
{
    printf("\nNumero : %i\n",dato.numero);
    printf("Letra : %c\n",dato.letra);
    printf("Palabra : %s\n",dato.palabra);
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
/// ------------fin borrar al pasar a proyecto C----------------------------------

