#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "funcionesSecundarias.h"
#include "estructuras.h"
#include "funcionesModoBatalla.h"

//Esquema desbloqueables.csv:
//Nombre del barco,Precisión,Ataque,Defensa,Velocidad,Vida,Obj1,Obj2,Obj3,Obj4,Puntuacion necesaria

//Esquema puntuacionTotal.csv:
//Usuario,Total partidas,Puntuacion Total,Total Daño recibido,Total Daño ocasionado,Total Barcos hundidos,Total victorias.

int start(int condicion, login registro, puntuacion *puntos);

int main()
{
    srand(time(NULL));

    login registro;
    puntuacion puntuacionTotal, *puntos;
    puntos = &puntuacionTotal;
    leerFicheros(registro, puntos);

    int condicion = 0, inicio = 1;
    registro = sesion();
    if (registro.checkpass[0] == 0)
    {
        clearscr();
        printf("Se han creado los archivos. Ignora los errores y reinicia el juego.\n");
        return 0;
    }

    strcpy(puntuacionTotal.nombre, registro.user);
    //printf("Tu nombre: %s\n", puntos->nombre);

    while (inicio != 0)
        inicio = start(condicion, registro, puntos);
    return 0;
}

int start(int condicion, login registro, puntuacion *puntos)
{
    int exit = 0, victoria;
    printf("\n");
    condicion = inicioPrograma();
    switch (condicion)
    {
    case 0:
        clearscr();
        printf("Gracias por jugar a Proyecto Buque Insignia.\nhttps://github.com/aigora/twIE_2021-proyecto-buque-insignia\n@AdriTeixeHax\n@matiaspolo\n@JorgeBachiller\n");
        enter();
        printf("Cerrando el juego...");
        return 0;

    case 1:
        clearscr();
        printf("Has seleccionado Jugar.\n");
        exit = jugar(puntos);
        if (exit == 555)
            return 1;
        guardarPuntuaciones(puntos);
        break;

    case 2:
        verPuntuacion();
        break;

    ///EXPERIMENTAL. Comentar, no borrar. Puede ser útil para debuguear.
//    case 3:
//        victoria = modoBatalla(puntos);
//        if (victoria == 1)
//            printf("Has ganado.");
//        if (victoria == 0)
//            printf("Has perdido.");
//        guardarPuntuaciones(puntos);
//        return 1;
//        break;
    ///EXPERIMENTAL

    default:
        clearscr();
        error();
        return 1;
        break;
    }
    return 1;
}
