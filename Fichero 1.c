#include <stdio.h>
#include "funcionesTexto.h"

int main()
{
    char caracter, volver[6];
    int condicion, dificultad, respuestas;
    start:
        condicion = inicioPrograma();
        switch (condicion) {
        case 1:
            printf("Has seleccionado personalizar barco.\n");
            scanf("%s", volver);
            if (volver == "atras")
                goto start;
            break;

        case 2:
            printf("has seleccionado menu principal, ¿quieres volver a atras?\n");
            scanf("%i",&respuestas);
            if (respuestas == 1) {
                respuestas = 0;
                goto start;
            }
            else {
                printf(" ¡vamos a jugar entonces! \n");
                printf(" elige el nivel de dificultad: 1 (facil), 2 (medio), 3 (dificil).\n");
                scanf("%i",&dificultad);
            }
            break;

        case 3:
            printf("has seleccionado puntuacion, ¿quieres volver a atras?\n");
            scanf("%i",&respuestas);
            if (respuestas == 1)
                {
                respuestas = 0;
                goto start;
                }
            break;
        default:
            error();
            goto start;
            break;
        }
    return 0;
}
