#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "funcionesTexto.h"
#define NECESARIO_R 25
#define FACTOR_R 0.75
#define LONG_PUNTUACION_CSV 7

float calculoDificultad(void)
{
    float factor;
    float r = 0.1;
    int totalPartidas = puntuaciones('n');
    int totalVictorias = puntuaciones('v');

    if (totalPartidas < NECESARIO_R)                //Esto se hace para que cuando se hayan jugado pocas partidas no se vuelva muy dificil el juego, aumentando progresivamente
        r = totalPartidas / 10;                     //hasta que se hayan jugado ciertas partidas. Es entonces cuando la dificultad global aumenta segun el ratio de
    else                                            //partidas ganadas y partidas jugadas
        r = FACTOR_R;
    factor = 1 + r * totalVictorias / totalPartidas;
    return factor;
}

int ataque(estadisticas atacante, estadisticas defensor)
{
    int total = 0;
    float n = random1(), totalf;
    if (n*atacante.precision <= 0.25)
        printf("El ataque falló.\n");
    else {
        totalf = atacante.ataque / defensor.defensa * 50;
        total = (int)totalf;
    }
    return total;
}

void imprimeVida(int vida)
{
    int i = 0;
    char healthbar[11] = "          ", any;
    for (i = 0; i < vida/10; i++)
        healthbar[i] = 254;
    printf("\n%i%c %s\n\n\n", vida, 37, healthbar);
    scanf(" %[\n]", &any);
}

int cpuHabilidad(void)
{
    if (random() > 0 && random() <= 25)
        return 1;
    if (random() > 25 && random() <= 50)
        return 2;
    if (random() > 50 && random() <= 75)
        return 3;
    if (random() > 75 && random() <= 100)
        return 4;
}
