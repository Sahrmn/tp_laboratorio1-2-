#include "funciones.h"

int obtenerEspacioLibre(EPersona lista[])
{
    int i;
    for(i=0;i<20;i++)
    {
        if(lista[i].estado==0)
        {
            return i;
        }
    }
    return -1;
}

void agregarPersona(EPersona lista[], int n)
{
    printf("Ingrese el dni:\n");
    scanf("%d",&lista[n].dni);
    //printf("--> %d\n",lista[n].dni);
    printf("Ingrese el nombre:\n");
    fflush(stdin);
    gets(lista[n].nombre);
    //printf("--> %s\n",lista[n].nombre);
    printf("Ingrese la edad:\n");
    scanf("%d",&lista[n].edad);
    //printf("--> %d\n",lista[n].edad);
    lista[n].estado = 1;
}

int buscarPorDni(EPersona lista[], int dni)
{
    int i;
    for(i=0;i<20;i++)
    {
        if(lista[i].dni==dni)
        {
            return i;
        }
    }
    printf("\nDNI no encontrado\n");
    system("pause");
    return -1;
}

void borrarPersona(EPersona lista[])
{
    int doc;
    int indice;
    printf("¿Que persona desea borrar?\n");
    imprimirPersonas(lista);
    printf("Escriba el DNI de la persona que desea borrar o 0(cero) para salir:\n");
    scanf("%d",&doc);
    if(doc!=0)
    {
        indice = buscarPorDni(lista,doc);
        lista[indice].estado = 0;
        system("cls");
        if(indice!=-1)
        {
            printf("\nElemento borrado \n");
            system("pause");
        }
    }
}

void imprimirUnaPersona(EPersona p)
{
    //printf("Persona %d:\n\n",i);
    printf("DNI: %d\n",p.dni);
    printf("Nombre: %s\n",p.nombre);
    printf("Edad: %d\n",p.edad);
    printf("\n");
}


void imprimirPersonas(EPersona lista[])
{
    int i;
    int flag = 0;

    ordenarPersonas(lista);
    for(i=0; i<20;i++)
    {
        if(lista[i].estado==1)
        {
            imprimirUnaPersona(lista[i]);
            flag = 1;
        }
    }
    if(flag==0)
    {
        printf("Nada que imprimir...\n");
    }
}

void ordenarPersonas(EPersona lista[])
{
    int i;
    int j;
    EPersona aux;
    for(i=1;i<20;i++)
    {
        for(j=0;j<19;j++)
        {
            if(strncmp(lista[j].nombre,lista[i].nombre,50)>0)//burbuja
            {
                memcpy(&aux ,&lista[j],sizeof(aux));
                memcpy(&lista[j] ,&lista[i],sizeof(aux));
                memcpy(&lista[i] ,&aux,sizeof(aux));
            }
        }
    }
}

void imprimirGrafico(EPersona lista[])
{
    int i;
    int cantidades[3] = {0,0,0}; //cantidades[0]--> menores a 18,cantidades[1]--> entre 19 y 35, cantidades[2]--> mayores a 35
    int mayor = 0;
    int j;

    for(i=0;i<20;i++)
    {
        if(lista[i].estado==1)
        {
                if(lista[i].edad<18)
                {
                    cantidades[0] = cantidades[0]+1;
                }
                else
                {
                    if(lista[i].edad>18 && lista[i].edad<35)
                    {
                        cantidades[1] = cantidades[1]+1;
                    }
                    else
                    {
                        cantidades[2] = cantidades[2]+1;
                    }
                }
        }
    }
    printf("\n<18\t\t19-35\t\t>35\n");

    //printf("%d\n",cantidades[0]);
    //printf("%d\n",cantidades[1]);
    //printf("%d\n",cantidades[2]);

    for(i=0;i<3;i++) //sacar la columna mas larga
    {
        if(cantidades[i]>mayor)
        {
            mayor = cantidades[i];
        }
    }

    for(i=mayor;i>0;i--)  //la mayor cantidad de iteraciones depende de la variable mayor
    {
        for(j=0;j<3;j++) // recorre las 3 columnas
        {
            if(cantidades[j]>=i)
            {
                printf(" * \t\t");
            }
            else
            {
                printf("   \t\t");
            }
        }
        printf("\n");
    }


}

