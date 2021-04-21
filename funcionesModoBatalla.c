#include <stdio.h>
#define NECESARIO_R 25
#define FACTOR_R 0.75

float calculoDificultad(void) //AVISO: PROVISIONAL
{
    float factor;
    float r = 0.1;
    puntuacionGlobal global; //en realidad hay que acceder a un fichero con las puntuaciones totales
    if (global.totalPartidas < NECESARIO_R)      //esto se hace para que cuando se hayan jugado pocas partidas no se vuelva muy dificil el juego, aumentando progresivamente
        r = global.totalPartidas/10;    //hasta que se hayan jugado ciertas partidas. Es entonces cuando la dificultad global aumenta segun el ratio de
    else                                //partidas ganadas y partidas jugadas
        r = FACTOR_R;
    factor = 1+r*global.totalGanadas/global.totalPartidas;
    return factor;
}
