#include "ABB.h"



//arbol - pasar arbol a archivo
void arbolAArchivo(nodoArbol* arbol,FILE* archivo)
{
    if(arbol)
    {
        fwrite(&(arbol->dato), sizeof(Struc), 1, archivo);
        arbolAArchivo(arbol-> izq,archivo);
        arbolAArchivo(arbol-> der,archivo);
    }
}


//arbol - pasar archivo a arbol
nodoArbol* archivoAArbol(nodoArbol* arbol, FILE* archivo)
{
    if(archivo)
    {
        Struc dato;
        nodoArbol* aux = arbolInic();

        while(fread(&dato,sizeof(Struc),1,archivo)>0)
        {
            aux = arbolNodoCrear(dato);
            arbol = arbolAgregarUnoOrdenandoPorNumero(arbol,aux);
        }
    }
    else
    {
        printf("\nerror archivo : archivoAArbol...\n");
    }
    return arbol;
}


//arbol - pasar de arbol a lista insertando al principio
nodoS* arbolALSPS(nodoArbol* arbol, nodoS* lista)
{
    if(arbol)
    {
        lista = LSPSagregarUnoPpio(lista, LSPScrearNodo(arbol-> dato));
        lista = arbolALSPS(arbol-> izq, lista);
        lista = arbolALSPS(arbol-> der, lista);
    }
    return lista;
}


//arbol - borrar nodo de arbol por numero
nodoArbol* arbolBorrarNodoPorNumero(nodoArbol* arbol, int numero)
{
    if(arbol)
    {
        if(numero > arbol-> dato.numero)  // en caso de que el legajo a buscar sea mayor que la raiz busca hacia la derecha
        {
            arbol-> der = arbolBorrarNodoPorNumero(arbol-> der, numero);
        }
        else if(numero < arbol-> dato.numero)   // en caso de que el legajo a buscar sea menor que la raiz busca hacia la izquierda
        {
            arbol-> izq = arbolBorrarNodoPorNumero(arbol-> izq, numero);
        }
        else if(numero == arbol-> dato.numero)   // una vez que encontramos el legajo
        {
            if(arbol-> izq)  // si el nodo que encontramos tiene un hijo a la izquierda y/o derecha
            {
                arbol-> dato = (arbolNodoMasDer(arbol-> izq)) -> dato; // el nodo a borrar ahora va ser el nodo mas grande del lado izquierdo (el mayor de los menores)

                arbol-> izq = arbolBorrarNodoPorNumero(arbol-> izq, arbol-> dato.numero); // ahora lo que hace es buscar el nodo que subimos en la linea anterior y lo borramos del arbol
            }
            else if(arbol-> der)    // si el nodo que encontramos tiene un hijo a la derecha
            {
                arbol-> dato = (arbolNodoMasIzq(arbol-> der))-> dato; // el nodo a borrar ahora va ser el nodo mas pequeno del lado derecho (el menor de los mayores)

                arbol-> der = arbolBorrarNodoPorNumero(arbol-> der, arbol-> dato.numero); // ahora lo que hace es buscar el nodo que subimos en la linea anterior y lo borramos del arbol
            }
            else   // En caso de que el nodo sea Hoja
            {
                free(arbol);
                arbol = NULL;
            }
        }
    }
    return arbol;
}


nodoArbol* arbolBorrarNodoPorNumero2(nodoArbol* arbol, int numero)
{
    if(arbol!=NULL)  // cond corte y sol triv implicita: no hace nada y retorna arbol, que va a ser NULL)
    {
        if(numero > arbol->dato.numero)
        {
            arbol->der = arbolBorrarNodoPorNumero2(arbol->der, numero); // si el dato buscado es mayor, busca por la dcha
        }
        else if (numero < arbol->dato.numero)
        {
            arbol->izq = arbolBorrarNodoPorNumero2(arbol->izq, numero); //si el dato buscado es menor, busca por la izq
        }
        else if (numero == arbol->dato.numero)   // si lo encontró (si no es < ni > ni llego al final es pq lo encontró)
        {
            if(arbolNodoEsHoja(arbol))
            {
                free(arbol);// puede ser q la hoja a borrar fuera el nodo q buscaba originariamente, o q fuera el nodo que "subi" y ahora necesito borrarlo para q no quede duplicado
                arbol = NULL; //como estamos en funcion recursiva, el otro llamado espera 1 nodo y si solo hago el free habra error
            }
            else if(arbolNodoEsGrado1(arbol))
            {
                nodoArbol* aux;
                if (arbol->der)
                {
                    aux = arbol;
                    arbol = arbol->der;
                    free(aux);
                }
                else        //if(arbol->izq)
                {
                    aux = arbol;
                    arbol = arbol->izq;
                    free(aux);
                }
            }
            else              // tiene 2 hijos
            {
                nodoArbol* masDer = arbolNodoMasDer(arbol->izq);
                arbol->dato = masDer->dato;  //al nodo a borrar le asigno como nuevo dato el del nodo mas derecho de la rama izquierda (el mas grande de los menores)
                arbol->izq = arbolBorrarNodoPorNumero2(arbol->izq, arbol->dato.numero); //y ahora busco y borro del lado izq el nodo que "subí"
            }
        }
    }
    return arbol;
}


//arbol - borrar todo el arbol
nodoArbol* arbolBorrar(nodoArbol* arbol)
{
    if(arbol)
    {
        if(arbolNodoEsHoja(arbol))
        {
            nodoArbol* aux = arbol;
            free(aux);
            arbol = NULL; // como la otra vuelta recursiva espera a un arbol, si solo lo libero estaria rompiedo la funcion, por eso debo devolver un NULL
        }
        else
        {
            arbol-> izq = arbolBorrar(arbol-> izq);
            arbol-> der = arbolBorrar(arbol-> der);
            if(arbolNodoEsHoja(arbol))  // tengo que comparar una vez mas ya que, a la vuelta de la ultima iteracion recursiva, quedara la raiz sola, convirtiendose en una hoja
            {
                nodoArbol* aux = arbol;
                free(aux);
                arbol = NULL;
            }
        }
    }
    return arbol;
}

//arbol - nodo/arbol es grado 1 - con retorno 1 o 0
int arbolNodoEsGrado1(nodoArbol * arbol)
{
    int rta=0;
    if(arbol)
    {
        if( (arbol->izq==NULL && arbol->der!=NULL) || (arbol->izq!=NULL && arbol->der==NULL) )
        {
            rta=1;
        }
    }
    return rta;
}



//arboles - altura del arbol
int arbolAltura(nodoArbol* arbol)
{
    int rta = 0;
    if(arbol)
    {
        rta = 1 + arbolMayor(arbolAltura(arbol-> izq), arbolAltura(arbol-> der));    // sumamos 1 ya que tenemos que tener en cuenta la raiz, despues a eso le sumamos la cant de niveles del lado mas alto
    }
    return rta;
}


// arboles - altura del arbol aux
int arbolMayor(int izq, int der)
{
    int rta = 0;
    if(izq > der)
    {
        rta = izq;
    }
    else
    {
        rta = der;
    }
    return rta; // devuelve la altura del lado izquierdo o del derecho
}


//arbol - nodo mas a la izquierda
nodoArbol* arbolNodoMasIzq(nodoArbol* arbol)
{
    if(arbol-> izq)
    {
        arbol = arbolNodoMasIzq(arbol-> izq);
    }
    return arbol;
}


//arbol - nodo mas a la derecha
nodoArbol* arbolNodoMasDer(nodoArbol* arbol)
{
    if(arbol-> der)
    {
        arbol = arbolNodoMasDer(arbol-> der);
    }
    return arbol; // si el arbol esta vacio retorna NULL
}


//arbol - contar cant de hojas
int arbolContarHojas(nodoArbol* arbol)
{
    int rta = 0;
    if(arbol)
    {
        if(arbolNodoEsHoja(arbol))
        {
            rta = 1 + arbolContarHojas(arbol-> izq) + arbolContarHojas(arbol-> der);
        }
        else
        {
            rta = arbolContarHojas(arbol-> izq) + arbolContarHojas(arbol-> der);
        }
    }
    return rta;
}


//arbol - chequear si nodo es hoja con retorno 1 o 0 (aux de contar cant de hojas) -
int arbolNodoEsHoja(nodoArbol* arbol)
{
    int rta=0;
    if(arbol-> izq == NULL && arbol-> der == NULL)
    {
        rta = 1;
    }
    return rta;
}


//arbol - contar cant de nodos - flashera
int arbolContarNodos2(nodoArbol* arbol)
{
    return (arbol) ? 1 + arbolContarNodos2(arbol-> izq) + arbolContarNodos2(arbol-> der) : 0;
}


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


//arbol - sumar numeros y devolver suma - flashera
int arbolSumarNumeros3(nodoArbol* arbol)
{
    return (arbol) ? arbol->dato.numero + arbolSumarNumeros3(arbol->izq) + arbolSumarNumeros3(arbol->der) : 0;
}


//arbol - sumar numeros y devolver suma - larga
int arbolSumarNumeros2(nodoArbol* arbol)
{
    int sumaRaiz = 0;
    int sumaIzq = 0;
    int sumaDer = 0;
    if(arbol)
    {
        sumaRaiz = arbol->dato.numero;
        sumaIzq = arbolSumarNumeros2(arbol->izq);
        sumaDer = arbolSumarNumeros2(arbol->der);
    }
    return sumaRaiz + sumaIzq + sumaDer;
}



//arbol - sumar numeros y devolver suma - corta
int arbolSumarNumeros(nodoArbol* arbol)
{
    int rta = 0;
    if(arbol)
    {
        rta = arbol->dato.numero + arbolSumarNumeros(arbol->izq) + arbolSumarNumeros(arbol->der);
    }
    return rta;
}


//arbol - buscar por palabra - para arbol ordenado por numero (como el arbol esta ordenado por numero tengo que recorrer todo el arbol, o al menos toda un lado)
nodoArbol* arbolBuscarPorPalabra(nodoArbol* arbol, char palabra[])
{
    nodoArbol* rta = NULL;
    if(arbol)
    {
        if(strcmpi(palabra, arbol-> dato.palabra) == 0)
        {
            rta = arbol;
        }
        else
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


//arbol - buscar por numero y retornar subarbol - para arbol ordenado por numero
nodoArbol* arbolBuscarPorNumero(nodoArbol* arbol, int numero)
{
    nodoArbol* rta = NULL;
    if(arbol)
    {
        if(numero == arbol-> dato.numero)
        {
            rta = arbol;
        }
        else
        {
            if(numero > arbol-> dato.numero)
            {
                rta = arbolBuscarPorNumero(arbol-> der, numero);
            }
            else
            {
                rta = arbolBuscarPorNumero(arbol-> izq, numero);
            }
        }
    }
    return rta;
}


//arbol - cargar varios nodos ordenando por numero
nodoArbol* arbolAgregarVariosOrdenandoPorPalabra(nodoArbol* arbol, int cant)
{
    Struc dato;
    nodoArbol* aux;

    for (int i=0; i<cant; i++)
    {
        dato = strucCargarAuto();
        aux = arbolNodoCrear(dato);
        arbol=arbolAgregarUnoOrdenandoPorPalabra(arbol,aux);
    }
    return arbol;
}


//arbol - insertar 1 nodo por campo palabra
nodoArbol* arbolAgregarUnoOrdenandoPorPalabra(nodoArbol* arbol, nodoArbol* nuevoNodo)
{
    if(arbol == NULL)
    {
        arbol = nuevoNodo;
    }
    else
    {
        if ( strcmpi ( nuevoNodo->dato.palabra, arbol->dato.palabra) <= 0 )
        {
            arbol-> izq = arbolAgregarUnoOrdenandoPorPalabra(arbol-> izq, nuevoNodo);
        }
        else
        {
            arbol-> der = arbolAgregarUnoOrdenandoPorPalabra(arbol-> der, nuevoNodo);
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


//arbol - mostrar en inOrder (izq,raiz,der)
void arbolMostrarInOrder(nodoArbol* arbol)
{
    if(arbol)
    {
        arbolMostrarInOrder(arbol-> izq);
        strucMostrar(arbol-> dato);
        arbolMostrarInOrder(arbol-> der);
    }
}


//arbol - mostrar en postOrder (izq,der,raiz)
void arbolMostrarPostOrder(nodoArbol* arbol)
{
    if(arbol)
    {
        arbolMostrarPostOrder(arbol-> izq);
        arbolMostrarPostOrder(arbol-> der);
        strucMostrar(arbol-> dato);
    }
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
    else
    {
//        printf("Aca no se puede escribir nada porque sino se ejecuta varias veces...\n");
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


void pruebaArbol()
{
    printf("\nABB : ok\n");
}

///-------------inicio borrar en proyecto C-------------
// archivo struc - mostrar
void archivoMostrar(char archivo[])
{
    FILE *arch = fopen(archivo,"rb");

    if(arch)
    {
        Struc aux;
        while(fread(&aux,sizeof(Struc),1,arch) >0)
        {
            strucMostrar(aux);
        }
        fclose(arch);
    }
    else
    {
        printf("\nError al abrir el archivo\n");
    }
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
///-------------fin borrar en proyecto C-------------
