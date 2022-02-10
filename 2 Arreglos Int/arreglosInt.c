#include "arreglosInt.h"


// arreglo con puntero - cargar
int dinamicoCargarRandoms(int** arreglo, int cant)
{
    *arreglo = (int*)malloc(sizeof(int)*cant);
    for (int i=0; i<cant; i++)
    {
        (*arreglo)[i]=i;
    }
    return cant;
}


// recursion - arreglo int - buscar valor en arreglo int
int arregloIntBuscarRecursionExplicita(int A[], int validos, int i, int valor)
{
    int rta=0; // supongo que el elemento no esta
    if(i<validos)
    {
        if(A[i]==valor)
        {
            rta=1;
        }
        else
        {
            rta = arregloIntBuscarRecursionExplicita(A, validos, i+1, valor);
        }
    }
    return rta;
}


// recursion - arreglo int - retornar posicion del menor del arreglo
int arregloIntPosMenorRecursionImplicita(int Arr[],int Validos,int i,int PosMenor)
{
    if(i<Validos)
    {
        if(Arr[i]<Arr[PosMenor])
        {
            PosMenor=i;

        }
        PosMenor=arregloIntPosMenorRecursionImplicita(Arr,Validos,i+1,PosMenor);

    }
    return PosMenor;
}


// recursion - arreglo int - menor valor
int arregloIntMenorRecursionExplicita(int arr[], int validos, int i)
{
    int menor;
    if (i==validos-1)   //llego al final menos 1
    {
        menor=arr[i];   //digo que el menor es el ultimo
    }
    else
    {
        menor = arregloIntMenorRecursionExplicita(arr, validos, i+1);
        if(menor>arr[i])     //voy comparando
            menor=arr[i];
    }
    return menor;
}


// recursion - arreglo int - buscar menor valor - implicita
int arregloIntMenorRecursionImplicita(int A[], int validos, int i, int menor)
{
    //las variables que queres mantener a lo largo de las mutiples llamadas las declaras en los parametros formales
    if(i<validos)       //mientras no llegue al final del arreglo
    {
        if(A[i]<menor)      //comparo en cada llamada de ida
        {
            menor=A[i];
        }
        menor = arregloIntMenorRecursionImplicita(A,validos,i+1,menor);   //recordar hacer la asignacion a rta
    }
    return menor;
}



// recursion - sumar arreglo implicita
int arregloIntSumarRecursionImplicita(int A[],int validos,int i)
{
    int rta=0;
    if(i<validos)
    {
        rta=A[i]+arregloIntSumarRecursionImplicita(A,validos,i+1);
    }
    return rta;
}


// recursion - sumar arreglo explicita
int arregloIntSumarRecursionExplicita(int A[],int validos,int i)
{
    int rta=0;
    if(i==validos)
    {
        rta=0;
    }
    else
    {
        rta=A[i]+arregloIntSumarRecursionExplicita(A,validos,i+1);
    }
    return rta;
}


// recursion - arreglo int - es capicua - implicita
int arregloIntCapicuaRecursionImplicita(int A[],int validos,int i)
{
    int rta=0;
    if(i<=validos)
    {
        if(A[i]==A[validos-1])
        {
            rta = arregloIntCapicuaRecursionImplicita(A,validos-1,i+1);
            rta = 1;
        }

    }
    return rta;
}


// recursion - arreglo int - es capicua - explicita
int arregloIntCapicuaRecursionExplicita(int A[],int validos,int i)
{
    int rta=0;
    if(i<validos-1)
    {
        if(A[i]==A[validos-1])
        {
            rta=arregloIntCapicuaRecursionExplicita(A,validos-1,i+1);
            rta=1;
        }
    }
    else
    {
        rta=0;
    }
    return rta;
}




// recursion - arreglo int - mostrar - implicita
void arregloIntMostrarRecursionImplicita(int A[],int validos,int i)
{
    if(i<validos)
    {
        printf("%i ",A[i]);     //de ida (se muestra normal)
        arregloIntMostrarRecursionImplicita(A,validos,i+1);
//        printf("%i ",A[i]);   //de vuelta (se muestra invertido)
    }
}


// recursion - arreglo int - mostrar - explicita
void arregloIntMostrarRecursionExplicita(int A[],int validos,int i)
{
    if(i==validos)
    {
        printf("\n");
    }
    else
    {
        printf("%i ",A[i]);     //a.
        arregloIntMostrarRecursionExplicita(A,validos,i+1);
    }
}


void arregloIntDinamico(int cuantos)
{
    //El problema era como crear arreglos en tiempo de ejecucion

    // SI - malloc
    printf("\nmalloc():\n");
    int *puntArr = (int*)malloc(sizeof(int)*cuantos);
    for (int i=0; i<cuantos; i++)
    {
        puntArr[i]=i;
    }
    arregloIntMostrar(puntArr,cuantos);


    //realloc - redefino dimension del arreglo
    printf("\nrealloc():\n");
    int otraCantidad=20;
    puntArr=realloc(puntArr,sizeof(int)*otraCantidad);
    for (int i=0; i<otraCantidad; i++)
    {
        puntArr[i]=i;
    }
    arregloIntMostrar(puntArr,otraCantidad);


    // SI - primero declarar con dimension y luego definir
    printf("\nsin malloc(): \n");
    int A[cuantos];
    for (int i=0; i<cuantos; i++)
    {
        A[i]=i;
    }
    arregloIntMostrar(A,cuantos);


    // NO - no se puede declarar y definir con variable en dimension --> Error: "variable-sized object may not be initialized"
//    int B[cuantos]={1,2,3};


    /*
    La dimension seria un numero desconocido en tiempo de codeo que entraria como parametro a la funcion de crear un arreglo de forma dinamica
    */
}


// arreglo int - intercalar arreglos
int arregloIntMerge(int A[],int validosA,int B[],int validosB,int C[])
{
    int a=0;
    int b=0;
    int c=0;

    for (int i=0; i<validosA; i++)  //recorro A
    {
        C[c]=A[a];
        c++;
        a++;
    }

    for (int i=0; i<validosB; i++)  //recorro B
    {
        C[c]=B[b];
        c++;
        b++;
    }
    return c;
}


int arregloIntInsertarEnOrden(int A[], int validos, int dato)
{
    int i;

    for(i=validos-1; i>=0 && dato < A[i]; i--)  //menor a la izq
    {
        A[i+1]=A[i];
    }
    A[i+1]=dato;

    return validos+1;
}


// arreglo int - ordenar por insercion - parte ordenada / desordenada
void arregloIntOrdenarInsercion(int A[],int validos)
{
    for(int i=0; i<validos-1; i++)
    {
        arregloIntOrdenarInsercionAux(A,i+1,A[i+1]);
    }
}


// arreglo int - insertar en arreglo ya ordenado manteniendo el orden
void arregloIntOrdenarInsercionAux(int A[],int pos, int dato)
{
    int i;
    for(i=pos-1; i>=0 && dato < A[i]; i--)
    {
        A[i+1]=A[i];
    }
    A[i+1]=dato;
    /*
    Parecida a arregloIntInsertarEnOrden pero con retorno y sin repetir busqueda en parte ordenada
    */
}


// arreglo int - ordenar por seleccion
void arregloIntOrdenarSeleccion (int A[], int validos)
{
    int aux;
    int posMenor;
    for(int i=0; i<validos-1; i++)
    {
        posMenor=arregloIntOrdenarSeleccionAux(A,validos,i);
        //pivoteo
        aux=A[i];
        A[i]=A[posMenor];
        A[posMenor]=aux;
    }
}


// arreglo int - ordenar por seleccion aux
int arregloIntOrdenarSeleccionAux(int A[], int validos, int pos)
{
    int menor=A[pos];
    for(int i=pos; i<validos; i++)
    {
        if(A[i]<menor)
        {
            menor=A[i];
            pos=i;
        }
    }
    return pos;
    /*
    Parecida a pos menor pero con un parametro mas para no repetir busqueda en parte ordenada
    */
}


// arreglo int - hallar pos menor
int arregloIntMenorPos(int A[], int validos)
{
    int menor=A[0];
    int posMenor=0;

    for(int i=1; i<validos; i++)
    {
        if(A[i]<menor)  //primer menor hallado
        {
            menor=A[i];
            posMenor=i;
        }
    }
//    return menor;
    return posMenor;
}


// arreglo int - armar numero decimal con valores de arreglo
long int armarNumero(int A[],int validos)
{
    long int numArmado=0;
    int pot=1;
    int mult;
    for (int i=validos-1; i>=0; i--)
    {
        mult=A[i]*pot;
        numArmado+=mult;
//        printf("valor: %i Pot: %9i mult: %9i Sum: %i \n",A[i],pot,mult,numArmado);
        pot*=10;
    }
    return numArmado;
    /*
    numeroArmado+=A[i]*(pow(10,validos-1-i)); //pow() no sirve para esto por un tema de redondeo en numeros grandes
    A partir de la decima potencia no entra en long int y hay errores -> overflow
    */
}


// arreglo int - eliminar valor por indice
int arregloIntBorrarPorIndice(int A[], int validos, int indiceBorrar)
{
    while(indiceBorrar<0 || indiceBorrar>validos-1)
    {
        printf("Index incorrecto, ingrese denuevo\n");
        scanf("%i",&indiceBorrar);
    }

    int i;
    for (i=indiceBorrar; i<validos-1; i++)
    {
        A[i]=A[i+1];
    }
    return validos-1;
}


// arreglo int - chequear capicua - 1 si es capicua
int arregloIntEsCapicua(int A[], int validos)
{
    int i=0;
    int j=validos-1;
    while(i<validos/2)
    {
        if(A[i]!=A[j])
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}


// arreglo int - invertir
void arregloIntInvertir(int A[],int validos)
{
    int i=0;
    int j=validos-1;
    int aux=0;

    while(i<validos/2)
    {
        //pivoteo
        aux=A[i];
        A[i]=A[j];
        A[j]=aux;
        //achico bordes
        i++;
        j--;
    }
}


// arreglo int - hallar valor menor
int arregloIntMenorValor(int A[], int validos)
{
    int menor=A[0];


    for(int i=1; i<validos; i++)
    {
        if(A[i]<menor)  //primer mayor hallado
        {
            menor=A[i];

        }
    }
    return menor;
}


// arreglo int - retornar valor mayor del arreglo
int arregloIntMayorValor(int A[], int validos)
{
    int mayor=A[0];

    for(int i=1; i<validos; i++)
    {
        if(A[i]>mayor)  //primer mayor hallado
        {
            mayor=A[i];

        }
    }
    return mayor;
}


// arreglo int - retornar pos mayor del arreglo
int arregloIntMayorPos(int A[], int validos)
{
    int mayor=A[0];
    int posMayor=0;

    for(int i=1; i<validos; i++)
    {
        if(A[i]>mayor)  //primer mayor hallado
        {
            mayor=A[i];
            posMayor=i;
        }
    }
//    return mayor;
    return posMayor;
}


// arreglo int - promedio
float arregloIntPromedio(int A[],int validos)
{
    int suma=ArregloIntSumar(A,validos);
    float promedio=(float)suma/(float)validos;
    return promedio;
}


// arreglo int - sumar elementos
int ArregloIntSumar(int A[],int validos)
{
    int suma=0;
    for(int i =0; i<validos; i++)
    {
        suma += A[i];
    }
    return suma;
}


// arreglo int - mostrar
void arregloIntMostrar(int A[],int validos)
{
    if(validos==0)
    {
        printf("\nArreglo vacio!\n");
    }
    else
    {
        printf("\n");
        for(int i=0; i<validos; i++)
        {
            printf("%i ",A[i]);
        }
        printf("\n");
    }
}


// arreglo int - cargar auto entre min y max
int arregloIntCargarRandEntreMinYMax(int A[],int dimension,int cant, int min, int max)
{
    if(cant>dimension)
    {
        printf("\nError - Cant > dimension - no se cargara el arreglo\n");
        return 0;
    }
    else
    {
        int i;
        for(i = 0; i<cant && i<dimension ; i++)
        {
            A[i]=rand() % (max + 1 - min) + min;
        }
        return i;
    }
}


// arreglo int - cargar auto randoms ordenados de menor a mayor
int arregloIntCargarRandOrdenados(int A[],int dimension,int cant)
{
    if(cant>dimension)
    {
        printf("\nError - Cant > dimension - no se cargara el arreglo\n");
        return 0;
    }
    else
    {
        int i;
        int num;
        for(i = 0; i<cant && i<dimension ; i++)
        {
            num = rand() % 10;
            arregloIntOrdenarInsercionAux(A,i,num);
        }
        return i;
    }
}


// arreglo int - cargar auto entre 0 y 9
int arregloIntCargarRand(int A[],int dimension,int cant)
{
    int i;
    if(cant>dimension)
    {
        printf("\nError - Cant > dimension - no se cargara el arreglo\n");
    }
    else
    {
        for(i=0; i<cant && i<dimension ; i++)
        {
            A[i]=rand() % 10;
        }
    }
    return i;
}


// arreglo int - cargar a mano
int arregloIntCargarAMano(int A[], int dimension)
{
    int validos=0;
    char letra='s';
    printf("\nCargando arreglo int a mano... Ingrese valores\n");

    while(validos<dimension && letra=='s')     //no sacar chequeo dimension
    {
        printf("Valor? ");
        scanf("%i",&A[validos]);
        validos++;
        printf("Seguir? (s/n) ");
        fflush(stdin);
        letra=getchar();

        if(validos==dimension)  //aviso cant>dim
        {
            if(letra=='s')
            {
                printf("Error: Cant > dimension . No se seguira cargando\n");
                system("pause");
            }
        }
    }
    return validos;
}


//arreglo int - inicializar en -999999 todos los esapcios de la dimension
void arregloIntInicializar(int A[], int dimension)
{
    for(int i = 0; i<dimension; i++)
    {
        A[i]=-999999;
    }
}


void pruebaArreglosInt()
{
    printf("\narreglos int : ok\n");
}
