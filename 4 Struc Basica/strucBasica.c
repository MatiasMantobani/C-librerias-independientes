#include "strucBasica.h"


void strucCargarVarias2(int cant, int *contador)
{
    Struc dato;

    for (int i=0; i<cant; i++)
    {
        dato = strucCargarAuto2(contador);
        strucMostrar(dato);
    }
}


void strucCargarVarias(int cant)
{
    Struc dato;
    for (int i=0; i<cant; i++)
    {
        dato = strucCargarAuto();
        strucMostrar(dato);
    }
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


void pruebaStrucBasica()
{
    printf("\nstruc basica : ok\n");
}


///inicio borrar en proyecto C

// char - letra random
char charRandom()
{
    char letras[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int cantLetras  = sizeof(letras)/sizeof(char);
    return letras[rand()%cantLetras];
}

///fin borrar en proyecto C









