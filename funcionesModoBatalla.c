#include <stdio.h>
#include "estructuras.h"
#define NECESARIO_R 25
#define FACTOR_R 0.75

float calculoDificultad(void) //AVISO: PROVISIONAL
{
    int cerrar;
    float factor;
    float r = 0.1;
    puntuacionGlobal global;

/// Leer y cerrar fichero
    FILE *leerPuntuacion;
    leerPuntuacion = fopen("puntuacion.csv", "r");
    if (leerPuntuacion == NULL)
        printf("Error al abrir el fichero.\n");
    else
        printf("Fichero abierto correctamente.\n");
    cerrar = fclose(leerPuntuacion);
    if (cerrar == EOF)
        printf("Error al cerrar el fichero.\n");
    if (cerrar == 0)
        printf("Fichero cerrado correctamente.\n");
/// Fin de lectura del fichero

    if (global.totalPartidas < NECESARIO_R)      //esto se hace para que cuando se hayan jugado pocas partidas no se vuelva muy dificil el juego, aumentando progresivamente
        r = global.totalPartidas/10;             //hasta que se hayan jugado ciertas partidas. Es entonces cuando la dificultad global aumenta segun el ratio de
    else                                         //partidas ganadas y partidas jugadas
        r = FACTOR_R;
    factor = 1 + r*global.totalGanadas / global.totalPartidas;
    return factor;
}
