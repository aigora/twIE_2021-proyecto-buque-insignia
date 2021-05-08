#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "funcionesTexto.h"
#include "funcionesModoBatalla.h"
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
    float n = random1();
    int result;
    if (n*atacante.precision <= 0.25)
        printf("El ataque fall%c.\n", 162);
    else
        result = atacante.ataque * 50 / defensor.defensa;
    return result;
}

void imprimeVida(int vidaUSER, int vidaCPU, int diferenciaUser, int diferenciaCPU, int opcion)
{
    int i = 0;
    char healthbarCPU[101] = "                                                                                                    ";
    char healthbarUSER[101] = "                                                                                                    ";
    for (i = 0; i < vidaUSER; i++)
        healthbarUSER[i] = 254;
    for (i = 0; i < vidaCPU; i++)
        healthbarCPU[i] = 254;
    switch (opcion)
    {
    case 1:
        printf("La vida del enemigo ha disminuido en %i puntos.\nVida CPU:", diferenciaCPU);
        printf("\n%i%c %s\n\n", vidaCPU, 37, healthbarCPU);
            enter();
            enter();
        printf("Tu vida ha disminuido en %i puntos.\nTu vida:", diferenciaUser);
        printf("\n%i%c %s\n\n", vidaUSER, 37, healthbarUSER);
            enter();
        break;

    case -1:
        printf("Tu vida ha disminuido en %i puntos.\nTu vida:", diferenciaUser);
        printf("\n%i%c %s\n\n", vidaUSER, 37, healthbarUSER);
            enter();
            enter();
        printf("La vida del enemigo ha disminuido en %i puntos.\nVida CPU:", diferenciaCPU);
        printf("\n%i%c %s\n\n", vidaCPU, 37, healthbarCPU);
            enter();
        break;

    case 0:
        printf("Tu vida:\n%i%c %s\n\nVida CPU:\n%i%c %s\n\n", vidaUSER, 37, healthbarUSER, vidaCPU, 37, healthbarCPU);
        break;
    }
}

int cpuHabilidad(void)
{
    int result = random();
    if (result > 0 && result <= 25)
        result = 1;
    if (result > 25 && result <= 50)
        result = 2;
    if (result > 50 && result <= 75)
        result = 3;
    if (result > 75 && result <= 100)
        result = 4;
    return result;
}

int accionHabilidades(estadisticas usuario, estadisticas oponente, float dificultad, int obj[4], int selector)
{
    float mult1 = 0.5, mult2 = 1.25;
    int operacional;
    switch (selector)
    {
    case 1://bajar precision
        operacional = oponente.precision;
        operacional = efectoHabilidad(operacional, mult1, dificultad, 0);
        printf("la precisi%cn baj%c.\n", 162, 162);
        obj[0]--;
        break;
    case 2://bajar velocidad
        operacional = oponente.velocidad;
        operacional = efectoHabilidad(operacional, mult1, dificultad, 0);
        printf("la velocidad baj%c.\n", 162);
        obj[1]--;
        break;
    case 3://subir ataque
        operacional = usuario.ataque;
        operacional = efectoHabilidad(operacional, mult2, dificultad, 0.25);
        printf("el ataque subi%c.\n", 162);
        obj[2]--;
        break;
    case 4://subir velocidad
        operacional = usuario.velocidad;
        operacional = efectoHabilidad(operacional, mult2, dificultad, 0.25);
        printf("la velocidad subi%c.\n", 162);
        obj[3]--;
        break;
    }
    enter();
    return operacional;
}

int efectoHabilidad (int stat, float factor, float difficulty, float minuendo)
{
    int result;
    float res = stat * factor * (difficulty - minuendo);
    result = res;
    return result;
}
