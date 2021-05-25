#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcionesSecundarias.h"
#include "estructuras.h"
#include "funcionesModoBatalla.h"

//Esquema desbloqueables.csv:
//d (desbloqueado) ó b (bloqueado),Nombre del barco,Precisión,Ataque,Defensa,Velocidad,Vida,Obj1,Obj2,Obj3,Obj4

int start(int condicion, int dificultad, int victoria, char volver[6], const char atras[6]);

int main()
{
    srand(time(NULL));
    char volver[6];
    const char atras[6] = "atras";
    int condicion = 0, dificultad = 0, inicio = 1, victoria = 0;

    while (inicio != 0)
        inicio = start(condicion, dificultad, victoria, volver, atras);

    return 0;
}

int start(int condicion, int dificultad, int victoria, char volver[6], const char atras[6])
{
    ///
    FILE *abrirDesbloq;
    int flag = 0;
    abrirDesbloq = fopen("desbloqueables.csv", "r");
    if (abrirDesbloq == NULL)
    {
        flag = 1;
        fclose(abrirDesbloq);
    }
    else
        fclose(abrirDesbloq);
    if (flag == 1)
    {
        flag = generarDesbloqueables();
    }
    ///

    clearscr();
    while (strcmp(volver, atras) != 0)
    {
        printf("\033[2J");
        printf("\n");
        condicion = inicioPrograma();
        switch (condicion)
        {
        case 1:
            printf("\033[2J");
            printf("Has seleccionado personalizar barco.\n");
            scanf("%s", volver);
            break;

        case 2:
            printf("\033[2J");
            printf("Has seleccionado Jugar.\n");
            dificultad = jugar();
            if (dificultad == 555)
                return 1;
            switch (dificultad)
            {
            case 555:
                return 1;
                break;
            case 0:
                break;
            case 1:
                break;
            case 3:
                break;
            }
            break;

        case 3:
            printf("Has seleccionado Puntuacion. Escribe 'v' para ver la puntuacion.\n");
            scanf("%s", volver);
            if (strcmp(volver, "v") == 0)
            ///
            break;

        ///EXPERIMENTAL. Comentar, no borrar. Puede ser útil para debuguear.
        case 4:
            victoria = modoBatalla();
            if (victoria == 1)
                printf("Has ganado.");
            if (victoria == 0)
                printf("Has perdido.");
            return 1;
            break;
        ///EXPERIMENTAL

        default:
            clearscr();
            error();
            return 1;
            break;
        }
    }
    return 0;
}
