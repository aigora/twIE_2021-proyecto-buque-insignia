#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcionesSecundarias.h"
#include "estructuras.h"
#include "funcionesModoBatalla.h"

int main()
{
    srand(time(NULL));
    char volver[6];
    const char atras[6] = "atras";
    int condicion, dificultad;

    int victoria; //Provisional

    start:
        clearscr();
        while (strcmp(volver, atras) != 0)
        {
            printf("\033[2J");
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
                    goto start;
                switch (dificultad)
                {
                case 555:
                    goto start;
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

            ///EXPERIMENTAL. Comentar, no borrar. Puede ser �til para debuguear.
            case 4:
                victoria = modoBatalla();
                if (victoria == 1)
                    printf("Has ganado.");
                if (victoria == 0)
                    printf("Has perdido.");
                goto start;
                break;
            ///EXPERIMENTAL

            default:
                clearscr();
                error();
                goto start;
                break;
            }
        }

        return 0;
}
