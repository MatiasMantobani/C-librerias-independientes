#include <stdio.h>
#include <stdlib.h>

int main()
{

    //declarar aqui variables de uso compartido entre los case


    char control= 's';
    int opcion= 0;
    while (control== 's')
    {
        printf("\nElija el ejercicio:\n");
        printf(" 1 - Ejercicio n 1\n");
        printf(" 2 - Ejercicio n 2\n");
        printf(" 3 - Ejercicio n 3\n");
        printf(" 4 - Ejercicio n 4\n");
        printf(" 5 - Ejercicio n 5\n");
        printf(" 6 - Ejercicio n 6\n");
        printf(" 7 - Ejercicio n 7\n");
        printf(" 8 - Ejercicio n 8\n");
        printf(" 9 - Ejercicio n 9\n");
        printf("10 - Ejercicio n 10\n");
        printf("\nIngrese nro ejercicio: ");

        fflush(stdin);
        scanf("%i", &opcion);
        system("cls");

        switch (opcion)
        {
        case 1:
            ;
            printf("\nEjercicio 1\n");

            system("Pause");
            system("cls");
            break;

        case 2:
            ;


            system("Pause");
            system("cls");
            break;

        case 3:
            ;


            system("Pause");
            system("cls");
            break;

        case 4:
            ;


            system("Pause");
            system("cls");
            break;

        case 5:
            ;


            system("Pause");
            system("cls");
            break;

        case 6:
            ;


            system("Pause");
            system("cls");
            break;

        case 7:
            ;


            system("Pause");
            system("cls");
            break;

        case 8:
            ;


            system("Pause");
            system("cls");
            break;

        case 9:
            ;


            system("Pause");
            system("cls");
            break;

        case 10:
            ;


            system("Pause");
            system("cls");
            break;

        default:
            printf("Elegiste una opcion incorrecta\n");
        }

        printf("\nVolver al menu? (s/n)\n");
        fflush(stdin);
        scanf("%c", &control);
        system("cls");

    }

    return 0;
}
