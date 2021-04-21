#include <stdio.h>
#include <string.h>
#include "funcionesTexto.h"
#include "estructuras.h"

int main()
{
    char volver[6];
    const char atras[6] = "atras", condjugar[6] = "jugar";
    int condicion, dificultad;
    start:
        condicion = inicioPrograma(condicion);
        switch (condicion) {
        case 1:
            printf("Has seleccionado personalizar barco.\n");
            scanf("%s", volver);
            if (strcmp(volver, atras) == 0) {
                strcpy(volver, "00000");
                goto start;
            }
            break;

        case 2:
            printf("Has seleccionado Jugar.\n");
            dificultad = jugar();
            if (dificultad == 555)
                goto start;
            //fopen();
            break;

        case 3:
            printf("Has seleccionado Puntuacion.\n");
            scanf("%s", volver);
            if (strcmp(volver, atras) == 0) {
                strcpy(volver, "00000");
                goto start;
            }
            //abrir otro archivo con la puntuación
            break;

        default:
            error();
            goto end;
            break;
        }

    end:
        return 0;
}
