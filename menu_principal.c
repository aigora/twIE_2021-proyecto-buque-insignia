#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesTexto.h"
#include "estructuras.h"

int main()
{
    char volver[6];
    const char atras[6] = "atras", condjugar[6] = "jugar";
    int condicion, dificultad;
    start: {
        while (strcmp(volver, atras) != 0)
        {
            system("cls");
            condicion = inicioPrograma(condicion);
            switch (condicion) {
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

            default:
                system("cls");
                error();
                goto end;
                break;
            }
        }
    }

    modoBatalla:


    end:
        return 0;
}
