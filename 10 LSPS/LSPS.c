#include "LSPS.h"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


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


// LSPS - recursivo - insertar ordenadamente
nodoS* LSPSagregarOrdenadamentePorNumeroRecursivo(nodoS* lista, nodoS* aInsertar)
{
    if(lista == NULL)
    {
        lista = aInsertar;
    }
    else
    {
        if(lista->dato.numero > aInsertar->dato.numero)
        {
            aInsertar-> siguiente = lista;
            lista = aInsertar;
        }
        else
        {
            lista-> siguiente = LSPSagregarOrdenadamentePorNumero(lista-> siguiente, aInsertar);
        }
    }
    return lista;
}


// LSPS - recursivo - mostrar posiciones pares
nodoS* LSPSlistaDePosParRecursivo(nodoS* lista, nodoS* listaPar)
{
    if(lista)
    {
        lista = lista-> siguiente;

        if(lista)
        {
            nodoS* aux = LSPScrearNodo(lista->dato);
            listaPar = LSPSagregarUnoFinal(listaPar,aux);
            LSPSlistaDePosParRecursivo(lista-> siguiente,listaPar);
        }
    }
    return listaPar;
}

// LSPS - borrar mayores a numero
nodoS* LSPSborrarMayoresA(nodoS* lista, int dato)
{

    if(lista)
    {
        nodoS* aux=lista;
        int i=1;
        while(aux)
        {
            if(aux->dato.numero > dato)
            {
                printf("%i ",i);
                lista=LSPSborrarPorPos(lista,i);
                i--;
            }
            aux=aux->siguiente;
            i++;
        }
    }
    else
    {
        printf("\nLa lista esta vacia...\n");
    }
    return lista;
}


// LSPS - borrar nodo recursivo
nodoS* LSPSborrarNodoPorNumeroRecursivo(nodoS* lista, int dato)
{
    if(lista)
    {
        if(lista->dato.numero == dato)
        {
            nodoS* aBorrar = lista;
            lista = lista-> siguiente;
            free(aBorrar);
        }
        else
        {
            lista->siguiente = LSPSborrarNodoPorNumeroRecursivo(lista-> siguiente, dato);
        }
    }
    return lista;
}

// LSPS - borrar nodo por posicion con validacion
nodoS* LSPSborrarPorPos(nodoS* lista, int posAborrar)
{
    if(lista)
    {
        int cantMax=LSPScontarNodos(lista);
        while(posAborrar>cantMax || posAborrar<=0)
        {
            printf("\nPos invalida, ingrese otra\n");
            scanf("%i",&posAborrar);
        }

        if(posAborrar==1)
        {
            nodoS* aux=lista;
            lista=lista->siguiente;
            free(aux);
        }
        else
        {
            nodoS* anterior=lista;
            nodoS* seguidora=lista->siguiente;

            int posActual=2;
            while(posActual != posAborrar)
            {
                anterior=seguidora;
                seguidora=seguidora->siguiente;
                posActual++;
            }
            nodoS* aux=seguidora;
            anterior->siguiente=seguidora->siguiente;
            free(aux);
        }
    }
    else
    {
        printf("\nLa lista esta vacia...\n");
    }
    return lista;
}


// LSPS - arreglo struc - pasar de lista a arreglo
int LSPSlistaAArreglo(nodoS* lista, Struc arreglo[], int dim)
{
    int validos = 0;
    if(lista)
    {
        Struc aux;
        while(lista && validos < dim)
        {
            aux = lista->dato;
            arreglo[validos] = aux;
            validos++;
            lista = lista->siguiente;

            if(validos==dim)
            {
                printf("\nValidos = dim... No se seguira cargando\n");
            }
        }
    }
    else
    {
        printf("\nLa lista esta vacia...\n");
    }
    return validos;
}


// LSPS - recursivo - agregar nodo al final
nodoS* LSPSagregarUnoFinalRecursivo(nodoS* lista, nodoS* nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        lista-> siguiente = LSPSagregarUnoFinalRecursivo(lista-> siguiente, nuevoNodo);
    }
    return lista;
}



// LSPS - recursivo - cant de palabras
int LSPScontarPalabrasRecursivo(nodoS* lista, char dato[30])
{
    int rta = 0;
    if(lista)
    {
        if(strcmpi(lista->dato.palabra,dato) == 0)
        {
            rta = 1 + LSPScontarPalabrasRecursivo(lista-> siguiente,dato);
        }
        else
        {
            rta = LSPScontarPalabrasRecursivo(lista-> siguiente,dato);
        }
    }
    return rta;
}


// LSPS - retornar mayor numero
int LSPSBuscarMayorPorNumero(nodoS* lista)
{
    int max;
    if(lista)
    {
        max = lista->dato.numero;

        while(lista)
        {
            if(lista->dato.numero > max)
            {
                max = lista->dato.numero;
            }
            lista = lista-> siguiente;
        }
    }
    else
    {
        printf("La lista esta vacia...\n");
    }
    return max;
}


// LSPS - recursivo - invertir
nodoS* LSPSinvertirRecursivo(nodoS* lista)
{
    if(lista)
    {
        nodoS* aux=lista;

        lista=LSPSinvertirRecursivo(lista->siguiente);

        aux->siguiente=NULL;

        lista=LSPSagregarUnoFinal(lista,aux);
    }
    return lista;
}


// LSPS - recursivo - sumar numeros
int LSPSsumarNumerosRecursivo(nodoS* lista)
{
    int rta;

    if(lista==NULL)
    {
        rta=0;
    }
    else
    {
        rta = lista->dato.numero + LSPSsumarNumerosRecursivo(lista->siguiente);
    }
    return rta;
}


// LSPS - mostrar - recursivo
void LSPSmostrarRecursivo(nodoS* lista)
{
    if(lista)
    {
        strucMostrar(lista->dato);        LSPSmostrarRecursivo(lista->siguiente);
//        strucMostrar(lista->dato);
    }
}

// LSPS - lista a archivo
FILE* LSPSlistaAArchivo(FILE* archivo, nodoS* lista)
{
    if(lista && archivo)
    {
        Struc aux;
        while(lista)
        {
            //aca podria ir condicion para pasar
            aux = lista->dato;
            fwrite(&aux, sizeof(Struc), 1, archivo);

            lista=lista->siguiente;
        }
    }
    else
    {
        printf("Falta lista o archivo...\n");
    }
    return archivo;
}


// LSPS - archivo a lista ordenadamente
nodoS* LSPSArchivoAListaOrdenadamente(FILE* archivo, nodoS* lista)
{
    Struc dato;
    nodoS* nuevoNodo;

    if(archivo)
    {
        while(fread(&dato, sizeof(Struc), 1, archivo) > 0)
        {
            //aca podria ir condicion para pasar
            nuevoNodo = LSPScrearNodo(dato);
            lista = LSPSagregarOrdenadamentePorNumero(lista,nuevoNodo);
        }
    }
    return lista;
}


// LSPS - archivo a lista
nodoS* LSPSArchivoALista(FILE* archivo, nodoS* lista)
{
    Struc dato;
    nodoS* nuevoNodo;

    if(archivo)
    {
        while(fread(&dato, sizeof(Struc), 1, archivo) > 0)
        {
            //aca podria ir condicion para pasar
            nuevoNodo = LSPScrearNodo(dato);
            lista = LSPSagregarUnoPpio(lista,nuevoNodo);
        }
    }
    return lista;
}


// LSPS - intercalar 2 listas
nodoS* LSPSIntercalar(nodoS* lista1, nodoS* lista2)
{
    nodoS* aux;
    nodoS* listaFinal = LSPSinic();

    while(lista1 && lista2)     //si hay elementos en alguna de las listas
    {
        aux = lista1;                                       // aux apunta a lista
        lista1 = lista1-> siguiente;                        // ahora lista apunta al siguiente
        aux->siguiente=NULL;                                //desvinculo el nodo aux de la lista
        listaFinal = LSPSagregarUnoFinal(listaFinal,aux);   //agrego el aux desvinculado a la lista intercalada

        aux = lista2;
        lista2 = lista2-> siguiente;
        aux->siguiente=NULL;
        listaFinal = LSPSagregarUnoFinal(listaFinal,aux);
    }

    if(lista1)
    {
        listaFinal = LSPSagregarUnoFinal(listaFinal, lista1);
        // tener en cuenta si una de las listas todavia tiene elementos despues del while
        // Solo haria falta conectar el nodo en el quedo suspendido (y todos los nodos que le sigan) despues del while y conectarlo con la lista intercalada
    }

    if(lista2)
    {
        listaFinal = LSPSagregarUnoFinal(listaFinal, lista2);
        // tener en cuenta si una de las listas todavia tiene elementos despues del while
        // Solo haria falta conectar el nodo en el quedo suspendido (y todos los nodos que le sigan) despues del while y conectarlo con la lista intercalada
    }
    return listaFinal;
}


// LSPS - comparar 2 listas por numero(las listas tienen que ser iguales en largo tambien)
int LSPSCompararPorNumero(nodoS* A, nodoS* B)
{
    int rta=1;  //1:iguales , 0:diferentes

    if(A==NULL && B==NULL)  //si ambas estan vacias
    {
        rta=1;  //son iguales
    }
    else if(A && B)         //si ninguna esta vacias
    {
        while(A && B)       //mientras A y B sean diferentes de NULL
        {
            if(A->dato.numero != B->dato.numero)    //si son diferentes numeros
            {
                rta=0;  //son distintas
            }

            A = A->siguiente;   //avanzo en A
            B = B->siguiente;   //avanzo en B
        }


        if(A == NULL && B!=NULL)
        {
            rta=0;
        }

        if(A != NULL && B==NULL)
        {
            rta=0;
        }


    }
    else                    //otro caso (1 vacia y otra no)
    {
        rta=0;
    }
    return rta;
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


// LSPS - eliminar  nodo de la lista
nodoS* LSPSborrarUltimo(nodoS* lista)
{
    if(lista)
    {
        if(lista->siguiente)
            lista->siguiente = LSPSborrarUltimo(lista->siguiente);
        else
        {
            free(lista);
            lista = NULL;
        }
    }
    else
    {
        printf("La lista esta vacia...\n");
    }
    return lista;
}


// LSPS - borrar lista completa
nodoS* LSPSborrarLista(nodoS* lista)
{
    if(lista)
    {
        nodoS* aBorrar;
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


// LSPS - borrar nodo de lista por nombre
nodoS* LSPSborrarPorPalabra(nodoS* lista, char nombreBorrar[30])
{
    if(lista)
    {
        if(strcmpi(lista->dato.palabra,nombreBorrar)==0)
        {
            nodoS* aux=lista;
            lista=lista->siguiente;
            free(aux);
        }
        else    //si no es primero
        {

            nodoS* anterior =lista;                  //necesarios para: 1. no modificar el puntero lista! y 2. poder hacer pivoteo
            nodoS* seguidora =lista->siguiente;

            while(seguidora && strcmpi(seguidora->dato.palabra,nombreBorrar)!=0)    //llego a valor buscado
            {
                anterior=seguidora;             //hasta que no encuentro el dato muevo la pareja
                seguidora=seguidora->siguiente;
            }

            if(seguidora)                                       //si corta antes del final
            {
                anterior->siguiente=seguidora->siguiente;       //bypass
                free(seguidora);                                //libera la memoria del nodo
            }
            else                                                //si seguidora llega a null es porque no encontro el valor buscado
            {
                printf("\npalabra a borrar no encontrada...\n");
            }
        }
    }
    else
    {
        printf("La lista esta vacia...\n");
    }
    return lista;
}


// LSPS - borrar nodo de lista por int
nodoS* LSPSborrarPorNumero(nodoS* lista, int dato)
{
    if(lista)
    {
        if(lista->dato.numero==dato)
        {
            nodoS* aBorrar=lista;
            lista=lista->siguiente;
            free(aBorrar);
        }
        else    //si no es primero
        {
            nodoS* anterior =lista;                  //necesarios para: 1. no modificar el puntero lista! y 2. poder hacer pivoteo
            nodoS* seguidora =lista->siguiente;

            while(seguidora && seguidora->dato.numero != dato)    //llego a valor buscado
            {
                anterior=seguidora;             //hasta que no encuentro el dato muevo la pareja
                seguidora=seguidora->siguiente;
            }

            if(seguidora)                                       //si corta antes del final
            {
                anterior->siguiente=seguidora->siguiente;       //bypass
                free(seguidora);                                //libera la memoria del nodo
            }
            else                                                //si seguidora llega a null es porque no encontro el valor buscado
            {
                printf("\nnumero a borrar no encontrado...\n");
            }
        }
    }
    else
    {
        printf("La lista esta vacia...\n");
    }
    return lista;
}


// LSPS - invertir lista
nodoS* LSPSinvertir(nodoS* lista)
{
    nodoS* invertida = LSPSinic();

    if(lista)
    {
        nodoS* seguidora = lista;
        nodoS* aux;

        while(seguidora)
        {
            aux=LSPScrearNodo(seguidora-> dato);
            invertida=LSPSagregarUnoPpio(invertida,aux);
            seguidora = seguidora-> siguiente;
        }
    }
    else
    {
        printf("La lista esta vacia...\n");
    }
    return invertida;
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

        if(aux == NULL)
        {
            printf("\npalabra no encontrada...\n");
        }
    }
    else
    {
        printf("\nla lista esta vacia...\n");
    }
    return aux;
}


// LSPS - retornar sublista buscada por nodo por campo numero
nodoS* LSPSBuscarPorNumero(nodoS* lista, int dato)
{
    nodoS* aux = lista;

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


// LSPS - muestra un nodo de la lista por numero
void LSPSMostrarNodoPorNumero(nodoS* lista, int numero)
{
    nodoS* aux = lista;

    if(lista)
    {
        while(aux && aux-> dato.numero != numero)
        {
            aux = aux-> siguiente;
        }

        if(aux)
        {
            strucMostrar(aux-> dato);
        }
        else
        {
            printf("\nnodo inexistente\n");
        }
    }
    else
    {
        printf("La lista esta vacia...\n");
    }
}


// LSPS - cargar ordenadamente la lista semiautomatico
nodoS* LSPSagregarVariosOrdenadamenteSemi(nodoS* lista)
{
    Struc dato;
    nodoS* nuevoNodo;

    char control;
    printf("\ningresar 1 ordenado por numero? (s/n) ");
    fflush(stdin);
    control=getchar();

    while(control=='s')
    {
        dato = strucCargarAuto();
        nuevoNodo = LSPScrearNodo(dato);
        lista = LSPSagregarOrdenadamentePorNumero(lista, nuevoNodo);

        printf("\ningresar otro? ");
        fflush(stdin);
        control=getchar();
    }
    return lista;
}


// LSPS - agregar 1 en lista ordenada por numero
nodoS* LSPSagregarOrdenadamentePorNumero(nodoS* lista, nodoS* nuevoNodo)
{
    nodoS* aux=lista;
    if(aux == NULL)    //es unico
    {
        aux=nuevoNodo;
    }
    else    //uso para ver cual esta primero un campo int
    {
        if(aux->dato.numero > nuevoNodo->dato.numero)  //esta primero
        {
            aux=LSPSagregarUnoPpio(lista,nuevoNodo);
        }
        else        //no esta primero
        {

            //anterior y siguiente
            nodoS* ante=aux;
            nodoS* sig=aux->siguiente;

            //while primer cheqeuio dif null
            while(sig && sig->dato.numero < nuevoNodo->dato.numero )
            {
                ante=sig;
                sig=sig->siguiente;
            }
            //inserto nuevo nodo
            nuevoNodo->siguiente=sig;
            ante->siguiente=nuevoNodo;
        }
    }
    return aux;
}


// LSPS - cargar lista ordenada por numero automaticamente
nodoS* LSPSagregarVariosOrdenadamenteAuto(nodoS* lista, int cant)
{
    Struc dato;
    nodoS* nuevoNodo;

    for (int i=0; i<cant; i++)
    {
        dato = strucCargarAuto();
        nuevoNodo = LSPScrearNodo(dato);
        lista = LSPSagregarOrdenadamentePorNumeroRecursivo(lista, nuevoNodo);
    }
    return lista;
}


// LSPS - cargar varios nodos al final de la lista automaticamente
nodoS* LSPSagregarVariosFinalAuto(nodoS* lista, int cant)
{
    Struc dato;
    nodoS* nuevoNodo;

    for (int i=0; i<cant; i++)
    {
        dato = strucCargarAuto();
        nuevoNodo = LSPScrearNodo(dato);
        lista = LSPSagregarUnoFinal2(lista, nuevoNodo);
    }
    return lista;
}


// LSPS - cargar varios nodos al FINAL de la lista de manera semiautomatica (uno por enter)
nodoS* LSPSagregarVariosFinalSemi(nodoS* lista)
{
    Struc dato;
    nodoS* nuevoNodo;

    char control;
    printf("\ningresar 1 final? (s/n) ");
    fflush(stdin);
    control=getchar();

    while(control=='s')
    {
        dato = strucCargarAuto();
        nuevoNodo = LSPScrearNodo(dato);
        lista = LSPSagregarUnoFinal(lista, nuevoNodo);

        printf("\ningresar otro? ");
        fflush(stdin);
        control=getchar();
    }
    return lista;
}


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

// LSPS - agregar nodo al final de lista
nodoS* LSPSagregarUnoFinal(nodoS* lista, nodoS* nuevoNodo)
{

    if(lista==NULL)     //si es el unico
    {
        lista=nuevoNodo;
    }
    else
    {
        nodoS* aux=LSPSultimo(lista);
        aux->siguiente=nuevoNodo;   //rearmo
    }
    return lista;
}


// LSPS - retornar puntero a ultimo nodo
nodoS* LSPSultimo(nodoS * lista)
{
    nodoS* aux = NULL;

    if(lista)
    {
        aux = lista;
        while(aux->siguiente)
        {
            aux = aux->siguiente;
        }
    }
    else
    {
        printf("La lista esta vacia...\n");
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


// LSPS - cargar varios al principio semiauto
nodoS* LSPSagregarVariosPpioSemi(nodoS* lista)
{
    Struc dato;
    nodoS* nuevoNodo;

    char control;
    printf("\ningresar 1 ppio? (s/n) ");
    fflush(stdin);
    control=getchar();

    while(control=='s')
    {
        dato = strucCargarAuto();
        nuevoNodo = LSPScrearNodo(dato);
        lista = LSPSagregarUnoPpio(lista, nuevoNodo);

        printf("\ningresar otro? ");
        fflush(stdin);
        control=getchar();
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


// LSPS - prueba
void pruebaLSPS()
{
    printf("\nLSPS : ok\n");
}


/// ------------inicio borrar al pasar a proyecto C----------------------------------

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


// archivo struc - contar registros de archivo
int archivoContarRegistros(char fileName[])
{
    int cant=0;
    FILE *arch=fopen(fileName,"rb");
    if(arch)
    {
        fseek(arch,0,SEEK_END);                 // puntero archivo al final
        cant = ftell(arch)/sizeof(Struc);       // cant bytes desde puntero / tamaño bytes structura

        fclose(arch);
    }
    else
    {
        printf("\nError al abrir el archivo\n");
    }
    return cant;
}


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


