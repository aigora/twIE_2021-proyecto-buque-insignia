//#include <stdio.h>
//
//int main()
//{
//    char caracter;
//    int condicion;
//    start:
//        printf("introduce una letra:\n");
//        scanf(" %c",&caracter);
//        printf("la letra es %c. ¿Quieres volver a introducir un caracter?", caracter);
//        scanf(" %i",&condicion);
//        if (condicion == 1)
//        {
//            caracter = 0;
//            goto start;
//        }
//    return 0;
//}



#include <stdio.h>
void volveratras(int decision);

int main()
{
    char caracter;
    int inicio, respuestas, dificultad, decision;
    start:
        printf("inicio del juego.\n");
        printf(" ¿A donde quieres ir? Selecciona entre personalizar barco (1), menu principal (2) y puntuacion (3). \n");
        scanf(" %i",&inicio);
            switch (inicio)
            {
            case 1:
                printf("has seleccionado personalizar barco, ¿quieres volver a atras?\n");
                scanf("%i",&respuestas);
                if (respuestas == 1)
                    {
                    respuestas = 0;
                    goto start;
                    }
                break;

            case 2:
                printf("has seleccionado menu principal, ¿quieres volver a atras?\n");
                scanf("%i",&respuestas);
                if (respuestas == 1)
                    {
                    respuestas = 0;
                    goto start;
                    }
                else
                    {
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

    return 0;
}

void volveratras(int decision)
    {
        printf("¿quieres volver a atras?\n");
        scanf("%i",&decision);
        if (decision == 1)
            {
             decision = 0;
             goto start;
            }
    }
