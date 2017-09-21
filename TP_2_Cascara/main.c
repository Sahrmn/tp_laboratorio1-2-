
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    EPersona listaPersonas[20];
    int i;

    for(i=0;i<20;i++)
    {
        listaPersonas[i].estado = 0;
    }

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                agregarPersona(listaPersonas, obtenerEspacioLibre(listaPersonas));
                break;
            case 2:
                system("cls");
                borrarPersona(listaPersonas);
                break;
            case 3:
                system("cls");
                imprimirPersonas(listaPersonas);
                printf("\n");
                system("pause");
                break;
            case 4:
                system("cls");
                imprimirGrafico(listaPersonas);
                printf("\n");
                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
//MORENO SAMANTHA
