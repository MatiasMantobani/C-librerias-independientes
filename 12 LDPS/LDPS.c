#include "LDPS.h"

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


// LDPS - borrar el nodo del medio de la lista
nodoD* LDPSborrarNodoDelMedio(nodoD* lista)
{
    if(lista)
    {
        int i = LDPScontarNodos(lista);
        int posicionCentral = i/2 + 1;  //redondeando hacia arriba
        lista = LDPSborrarPorPos(lista,posicionCentral);
    }
    else
    {
        printf("La lista esta vacia...\n");
    }
    return lista;
}


// LDPS - borrar nodo por posicion con validacion
nodoD* LDPSborrarPorPos(nodoD* lista, int posAborrar)
{
    if(lista)
    {
        int cantMax=LDPScontarNodos(lista);

        while(posAborrar>cantMax || posAborrar<=0)
        {
            printf("\nPos invalida, ingrese otra\n");
            scanf("%i",&posAborrar);
        }

        nodoD* aux = lista;

        if(posAborrar==1)
        {
            lista=lista->siguiente;
            free(aux);
        }
        else
        {
            int posActual=2;
            while(posActual != posAborrar)  //te deja el puntero uno antes del aBorrar
            {
                aux = aux->siguiente;
                posActual++;
            }
            nodoD* ante = aux;
            aux = aux->siguiente;
            ante->siguiente = aux->siguiente;
            free(aux);
        }
    }
    else
    {
        printf("\nLa lista esta vacia...\n");
    }
    return lista;
}




//LDPS - contar nodos de lista
int LDPScontarNodos(nodoD* lista)
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


// LDPS - es capicua - 1 si y 0 no
int LDPScapicuaPorNumero(nodoD* principio, nodoD* fin)
{
    int flag = 1;
    if(principio && fin && (principio != fin))
    {
        if(principio-> dato.numero == fin-> dato.numero)
        {
            flag = LDPScapicuaPorNumero(principio-> siguiente, fin-> anterior);
        }
        else
        {
            flag = 0;
        }
    }
    return flag;
}

// LDPS - pasar de lista a arreglo por palabra
int LDPSlistaAArregloPorPalabra(nodoD* lista, char palabra[], Struc A[], int dimension)
{
    int validos = 0;
    Struc aux;
    while(lista)
    {
        if(validos>=dimension)
        {
            printf("\nvalidos = dim... Se dejara de cargar en el arreglo\n");
            break;
        }
        if(strcmpi(lista->dato.palabra, palabra) == 0)
        {
            aux = lista-> dato;
            A[validos] = aux;
            validos++;
        }
        lista = lista-> siguiente;
    }
    return validos;
}

// LDPS - contar por palabra
int LDPScontarPorPalabra(nodoD* lista, char dato[])
{
    int contador = 0;
    while(lista)
    {
        if(strcmpi(lista->dato.palabra, dato) == 0)
        {
            contador++;
        }
        lista = lista-> siguiente;
    }
    return contador;
}

// LDPS - retornar struc de mayor numero
Struc LDPSstrucMayorNumero(nodoD* lista)
{
    Struc aux;
    if(lista == NULL)
    {
        printf("\nLa lista esta vacia... Se devuelve basura\n");
        aux.numero = 0;
        aux.letra = '-';
        strcpy(aux.palabra,"-");
    }
    else
    {
        aux = lista->dato;
        while(lista)
        {
            if(lista-> dato.numero > aux.numero)
            {
                aux = lista-> dato;
            }
            lista=lista->siguiente;
        }
    }
    return aux;
}


// LDPS - borrar por palabra
nodoD* LDPSborrarPorPalabra(nodoD* lista, char dato[])
{
    if(lista)
    {
        if(strcmp(lista-> dato.palabra, dato) == 0)
        {
            nodoD* aBorrar = lista;
            lista = lista-> siguiente;
            if(lista)
            {
                lista-> anterior = NULL;
            }
            free(aBorrar);
        }
        else
        {
            nodoD* seguidora = lista-> siguiente;
            while(seguidora && strcmp(seguidora-> dato.palabra, dato) != 0)
            {
                seguidora = seguidora-> siguiente;
            }
            if(seguidora)
            {
                nodoD* ante = seguidora-> anterior;
                ante-> siguiente = seguidora-> siguiente;
                if(seguidora-> siguiente)
                {
                    nodoD* sig = seguidora-> siguiente;
                    sig-> anterior = ante;
                }
                free(seguidora);
            }
            else
            {
                printf("\nEl elemento que deseas borrar no existe en la lista\n");
            }
        }
    }
    else
    {
        printf("La lista esta vacia...\n");
    }
    return lista;
}


// LDPS - borrar lista completa
nodoD* LDPSborrarLista(nodoD* lista)
{
    if(lista)
    {
        nodoD* aBorrar;
        while(lista)
        {
            aBorrar=lista;
            lista=lista->siguiente;
            free(aBorrar);
        }
	printf("Se borro la lista...\n");
    }
    else
    {
        printf("La lista esta vacia...\n");
    }
    return lista;
}


// LDPS - borrar nodo de lista por numero
nodoD* LDPSborrarPorNumero(nodoD* lista, int num)
{
    if(lista)  // solo si la lista contiene algo, en caso de que este vacia saltamos este if y retornamos la lista
    {
        if(lista-> dato.numero == num)  // en caso de que el nodo a borrar este en la 1ra posicion
        {
            nodoD* aBorrar = lista; // guardamos el aBorrar igualando a lista, ya que lista apunta hacia el primer nodo
            lista = lista-> siguiente; // lista ahora apunta al segundo nodo de la lista, que seria el siguiente de la lista
            if(lista)  // en caso que la lista NO este posicionado en NULL (fin de la lista), si la lista esta posicionado en el NULL salteamos el if, ya que NULL no es un nodo y por ende no tiene un campo anterior
            {
                lista-> anterior = NULL; // el campo anterior del nodo que esta delante del nuevoNodo ahora apunta hacia el nuevoNodo
            }
            free(aBorrar); // borramos el nodo que guardamos en la variable aBorrar
        }
        else   // en caso de que el nodo a borrar se encuentre en cualquier posicion de la lista menos en la 1ra posicion
        {
            nodoD* seguidora = lista-> siguiente; // arrancamos una poscion mas adelante ya que sabemos que el primero no es el nodo a borrar, tampoco necesitamos ante

            while(seguidora && seguidora-> dato.numero != num)  // iteramos mientras seguidora no sea NULL y el numero del nodo sea desigual al del elemento que queremos borrar
            {
                seguidora = seguidora-> siguiente; // avanzamos
                // no usamos ante ya que podemos acceder atraves del campo anterior del nodo seguidora
            }

            if(seguidora)  // en caso de que seguidora contenga algo, esto quiere decir que seguidora es el nodo a borrar
            {
                nodoD* ante = seguidora-> anterior; // declaro la variable ante, que guarda el nodo que va antes del nodo seguidora (seguidora-> anterior)
                ante-> siguiente = seguidora-> siguiente; // el siguiente del nodo ante es igual al nodo que le sigue al nodo seguidora
                if(seguidora-> siguiente)  // si seguidora siguiente no es NULL
                {
                    nodoD* sig = seguidora-> siguiente; // creamos una variable extra para poder guardar al siguiente de la variable seguidora, ya que seguidora es el nodo que vamos a borrar
                    sig-> anterior = ante; // el campo anterior del nodo que creamos arriba es igual al nodo ante que creamos unas lineas mas arriba
                }
                free(seguidora); // borramos el nodo seguidora que es donde se encuentra el campo que pasamos por parametro
            }
            else   // en caso de que seguidora sea NULL, esto quiere decir que el elemento buscado no existia en la listas
            {
                printf("\nEl elemento que deseas borrar no existe en la lista\n");
            }
        }
    }
    else
    {
        printf("\nla lista esta vacia...\n");
    }
    return lista;
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


// LDPS - cargar varios ordenadamente por numero auto
nodoD* LDPSagregarVariosOrdenadamentePorNumeroAuto(nodoD* lista, int cant)
{
    Struc dato;
    nodoD* nuevoNodo;

    for (int i=0; i<cant; i++)
    {
        dato = strucCargarAuto();
        nuevoNodo = LDPScrearNodo(dato);
        lista = LDPSagregarUnoOrdenadamentePorNumero(lista, nuevoNodo);
    }
    return lista;
}


// LDPS - insertar en orden por numero
nodoD* LDPSagregarUnoOrdenadamentePorNumero(nodoD* lista, nodoD* nuevoNodo)
{
    if(lista == NULL)  // en caso de que la lista este vacia
    {
        lista = nuevoNodo; // el campo anterior del nodo seguidora (nodo a la derecha de donde quedo insertado el nuevoNodo) apunta hacia el nuevoNodo
    }
    else
    {
        if(lista-> dato.numero > nuevoNodo-> dato.numero)  // en caso de que haya que insertar el nodo en la 1ra posicion
        {
            nuevoNodo-> siguiente = lista; // nuevo nodo ahora apunta hacia el que le sigue en la lista
            if(lista-> siguiente)  // en caso que la lista NO este posicionado en NULL (fin de la lista), si la lista esta posicionado en el NULL salteamos el if, ya que NULL no es un nodo y por ende no tiene un campo anterior
            {
                lista-> anterior = nuevoNodo; // el campo anterior del nodo que esta delante del nuevoNodo ahora apunta hacia el nuevoNodo
            }
            lista = nuevoNodo; // ahora la lista apunta a el nuevoNodo
        }
        else   // en caso de que haya que insertarlo en cualquier lugar menos el primero
        {
            nodoD* ante = lista;
            nodoD* seguidora = lista-> siguiente; // arrancamos la seguidora desde el segundo nodo, ya que nosotros evaluamos si el nodo a insertar debia ir primero en la linea 156, como no cumplio esa condicion ya sabemos que el primer elemento es menor al del nuevoNodo

            while(seguidora && (seguidora-> dato.numero) < (nuevoNodo-> dato.numero))  // en caso de que seguidora no sea NULL y que el nuevoNodo sea mayor al nodo de seguidora
            {
                ante = seguidora; // avanzo hacia el siguiente
                seguidora = seguidora-> siguiente; // avanzo hacia el siguiente
            }

            ante-> siguiente = nuevoNodo; // el campo siguiente del nodo que se encuentra a la izquierda de donde vamos a insertar el nuevoNodo apunta hacia nuevoNodo
            nuevoNodo-> siguiente = seguidora; // el campo siguiente de nuevoNodo ahora apunta hacia donde quedo posicionado la variable seguidora
            nuevoNodo-> anterior = ante; // el campo anterior de nuevoNodo ahora apunta hacia donde quedo posicionado la variable ante
            if(seguidora)  // en caso que seguidora no este posicionado en NULL (fin de la lista), si la lista esta posicionado en el NULL salteamos el if
            {
                seguidora-> anterior = nuevoNodo; // el campo anterior del nodo seguidora (nodo a la derecha de donde quedo insertado el nuevoNodo) apunta hacia el nuevoNodo
            }
        }
    }
    return lista;
}


// LDPS - retornar sublista buscada por campo numero
nodoD* LDPSBuscarPorNumero(nodoD* lista, int dato)
{
    nodoD* aux = lista;

    if(lista)
    {
        while(aux && aux-> dato.numero != dato)
        {
            aux = aux-> siguiente;
        }

        if(aux == NULL)
        {
            printf("\nnumero no encontrado...\n");
        }
    }
    else
    {
        printf("\nla lista esta vacia...\n");
    }
    return aux;
}


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
        nuevoNodo-> anterior = ultimo;  // enlazamos el anterior del nuevoNodo con el ultimo nodo que habia en la lista antes de agregar el nuevoNodo (nueva linea)
        ultimo-> siguiente = nuevoNodo; // el ultimo nodo de la lista ahora apunta hacia el nuevo nodo
    }
    return lista;                       // Se retorna la lista ya que hay que tener en cuenta que en el caso de que el primer primer if sea verdadero debemos retornarla, en el resto de los casos aunque trabajemos sobre el aux los nodos de la lista van a quedar modificados
}


// LDPS - retornar ultimo nodo sin borrar ni desvincular (puntero a ultimo nodo)
nodoD* LDPSultimo(nodoD* lista)
{
    nodoD* ultimo = lista; // de entrada lo igualamos a lista, ya que si la lista es NULL retornamos eso
    if(ultimo)
    {
        while(ultimo-> siguiente)  // hasta llegar al final
        {
            ultimo = ultimo-> siguiente; // me muevo hacia el siguiente nodo en la lista
        }
    }
    else
    {
        printf("La lista esta vacia...\n");
    }
    return ultimo;
}


// LDPS - cargar varios nodos al PRINCIPIO de la lista automaticamente
nodoD* LDPSagregarVariosPpioAuto(nodoD* lista, int cant)
{
    Struc dato;
    nodoD* nuevoNodo;

    for (int i=0; i<cant; i++)
    {
        dato = strucCargarAuto();
        nuevoNodo = LDPScrearNodo(dato);
        lista = LDPSagregarUnoPpio(lista, nuevoNodo);
    }
    return lista;
}


// LDPS - agregar uno principio
nodoD* LDPSagregarUnoPpio(nodoD* lista, nodoD* nuevoNodo)  // esta funcion retorna directamente el nuevoNodo apuntando hacia la lista, SOLO FUNCIONA CON PUNTERO SIMPLE!
{
    nuevoNodo-> siguiente = lista;      // en caso de que la lista tenga elementos o este vacia esta linea se va ejecutar si o si, entonces lo ponemos por fuera del ifs
    if(lista)
    {
        lista-> anterior = nuevoNodo;   // donde apuntaba el campo anterior del primer nodo de la lista (antes de que se agregara el nuevoNodo), ahora apunta hacia el nuevoNodo
    }
    return nuevoNodo;                   // cuando llamemos a la funcion en el main guardamos el resultado de esta funcion en la lista, de esa forma no hace falta que retornemos la lista dentro de la funcion
}



// LDPS - agregar 1 al principio version larga
nodoD* LDPSagregarUnoPpio2(nodoD* lista, nodoD* nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo-> siguiente = lista;  // el campo siguiente del nuevo nodo que vamos agregar apuntara a la lista sobre la que estamos trabajando
        lista-> anterior = nuevoNodo;   // donde apuntaba el campo anterior del primer nodo de la lista (antes de que se agregara el nuevoNodo), ahora apunta hacia el nuevoNodo (nueva linea)
        lista = nuevoNodo;              // la lista ahora comienza desde el nuevoNodo que agregamos
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


// LSPS - prueba
void pruebaLDPS()
{
    printf("\nLDPS : ok\n");
}


/// ------------inicio borrar al pasar a proyecto C----------------------------------

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

// arreglo struc - mostrar arreglo struc
void arregloStrucMostrar(Struc A[],int validos)
{
    if(validos == 0)
    {
        printf("\nArreglo vacio!\n");
    }
    else
    {
        for (int i=0; i<validos; i++)
        {
           strucMostrar(A[i]);
        }
    }
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

/// ------------fin borrar al pasar a proyecto C-------------------------------------
