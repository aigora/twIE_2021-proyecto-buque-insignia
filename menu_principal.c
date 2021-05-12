#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesTexto.h"
#include "estructuras.h"
#include "funcionesModoBatalla.h"

int main()
{
    char volver[6];
    const char atras[6] = "atras";
    int condicion, dificultad;

    int victoria; //Provisional

    start:
        while (strcmp(volver, atras) != 0)
        {
            system("cls");
            condicion = inicioPrograma();
            switch (condicion)
            {
            case 1:
                system("cls");
                printf("Has seleccionado personalizar barco.\n");
                scanf("%s", volver);
                break;

            case 2:
                system("cls");
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
                system("cls");
                printf("Has seleccionado Puntuacion. Escribe 'v' para ver la puntuacion.\n");
                scanf("%s", volver);
                if (strcmp(volver, "v") == 0)
                    system("\"puntuacion.csv\"");
                break;

            ///EXPERIMENTAL. Comentar, no borrar. Puede ser útil para debuguear.
            case 4:
                victoria = modoBatalla();
                if (victoria == 1)
                    printf("Has ganado.");
                if (victoria == 0)
                    printf("Has perdido.");
                enter();
                enter();
                goto start;
                break;
            ///EXPERIMENTAL

            default:
                system("cls");
                error();
                goto start;
                break;
            }
        }

        return 0;
}
