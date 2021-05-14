#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "estructuras.h"
#include "funcionesTexto.h"
#include "funcionesModoBatalla.h"
#define NECESARIO_R 25
#define NECESARIO_PRECISION 0.25
#define FACTOR_R 0.75
#define LONG_PUNTUACION_CSV 7
#define TURNOS_ADICIONALES 3
#define MULT1 0.5
#define MULT2 1.25

int modoBatalla(void)
{
    float dificultad;
    int cerrar, seleccion, cpudamage, userdamage, opcionVida, calculoCPU = cpuHabilidad(), randseed = -1, variacionHabilidadCPU = 0, variacionHabilidadUSER = 0;
    char benefCPU, benefUSER;
    int objCountUSER[4] = {1,1,1,1};
    int objCountCPU[4] = {1,1,1,1};
    float var = 0;
    //puntuacion puntosBatalla;
    dificultad = calculoDificultad();
    estadisticas cpu, user;
    printf("%f\n", dificultad);
    enter();

    /// Leer y abrir fichero
    FILE *abrirEstadisticas;          //Lo hago con ficheros porque en el futuro quiero añadir un sistema de mejoras según las partidas jugadas, o un sistema de recompensas
    abrirEstadisticas = fopen("estadisticas.csv", "r");
    if (abrirEstadisticas == NULL) {
        printf("Error al abrir el fichero.\n");
        enter();
        enter();
        return -1;
    }
//    else
//        printf("Fichero abierto correctamente.\n");

    fscanf(abrirEstadisticas, "%i, %i, %i, %i, %i, %i, %i, %i, %i, %i", &user.precision, &user.ataque,
                &user.defensa, &user.velocidad, &user.vida, &cpu.precision, &cpu.ataque, &cpu.defensa, &cpu.velocidad, &cpu.vida);

    cerrar = fclose(abrirEstadisticas);
    if (cerrar == EOF) {
        printf("Error al cerrar el fichero.\n");
        enter();
        enter();
        return -1;
    }
//    if (cerrar == 0)
//    printf("Fichero cerrado correctamente.\n");
    /// Fin de lectura del fichero

    printf("La lancha ha sido destruida. %cQue comience la batalla!\n", 173);
    enter();

    attack:
        randseed++;
        system("cls");
        imprimeVida(user.vida, cpu.vida, 0, 0, 0);

        printf("\tAtk\tDef\tSpd\tAcc\tHP\nUSR\t%i\t%i\t%i\t%i\t%i\nCPU\t%i\t%i\t%i\t%i\t%i\n", user.ataque, user.defensa, user.velocidad, user.precision, user.vida,
               cpu.ataque, cpu.defensa, cpu.velocidad, cpu.precision, cpu.vida);

        printf("\nSelecciona una opci%cn:\n(1) Atacar\n(2) Usar Objetos\n", 162);
        scanf(" %i", &seleccion);
        system("cls");
        switch (seleccion)              //Uso un bucle switch porque puede que añada opciones en el futuro
        {
        case 1:
            cpudamage = ataque(user, cpu, randseed);
            userdamage = ataque(cpu, user, randseed+1);
            damage:
                if (user.velocidad < cpu.velocidad)
                {
                    opcionVida = -1;
                    user.vida -= userdamage;
                    if (user.vida <= 0)
                    {
                        printf("El enemigo ha ganado. Tiene ahora %i turnos adicionales.\n", TURNOS_ADICIONALES);
                        return 0;
                    }
                    cpu.vida -= cpudamage;
                    if (cpu.vida <= 0)
                    {
                        printf("%cHas ganado! Tienes ahora %i turnos adicionales.\n", 173, TURNOS_ADICIONALES);
                        return 1;
                    }
                }
                if (cpu.velocidad < user.velocidad)
                {
                    opcionVida = 1;
                    cpu.vida -= cpudamage;
                    if (cpu.vida <= 0)
                    {
                        printf("%cHas ganado! Tienes ahora %i turnos adicionales.\n", 173, TURNOS_ADICIONALES);
                        return 1;
                    }
                    user.vida -= userdamage;
                    if (user.vida <= 0)
                    {
                        printf("El enemigo ha ganado. Tiene ahora %i turnos adicionales.\nSe han añadido %i puntos a la puntuación total.\n\
Recuerda que puedes ver el historial de puntuaciones en el menú principal.", TURNOS_ADICIONALES, 0);
                        return 0;
                    }
                }
                if (cpu.velocidad == user.velocidad)
                {
                    var = random1();
                    if (var > 0) {
                        printf("%f", var);
                        user.velocidad += 1;
                    }
                    else
                        cpu.velocidad += 1;
                    goto damage;
                }
                imprimeVida(user.vida, cpu.vida, userdamage, cpudamage, opcionVida);
                seleccion = 0;
                goto attack;

        case 2:
            habilidad:
                system("cls");
                if (objCountUSER[0] == 0 && objCountUSER[1] == 0 && objCountUSER[2] == 0 && objCountUSER[3] == 0)
                {
                    printf("No te quedan objetos.");
                    enter();
                    enter();
                    goto attack;
                }
                printf("Escoge un objeto para usarlo:\n");

                if (objCountUSER[0] > 0)
                    printf("(1) Bola de Humo\t\t\tBajar precisi%cn del enemigo\n", 162);
                if (objCountUSER[1] > 0)
                    printf("(2) Ancla\t\t\t\tBajar velocidad de enemigo\n");
                if (objCountUSER[2] > 0)
                    printf("(3) P%clvora Premium\t\t\tAumenta tu ataque\n", 162);
                if (objCountUSER[3] > 0)
                    printf("(4) Motor Auxiliar\t\t\tAumenta tu velocidad\n");
                scanf(" %i", &seleccion);

                if (objCountUSER[seleccion - 1] == 0)
                {
                    printf("No te quedan objetos de este tipo.\n");
                    enter();
                    enter();
                    goto habilidad;
                }

                    switch (calculoCPU)
                    {
                    case 1:
                        user.precision = efectoHabilidad(user.precision, MULT1, dificultad, 0);
                        objCountCPU[0]--;
                        variacionHabilidadCPU = -1;
                        benefCPU = 'u';
                        break;
                    case 2:
                        user.velocidad = efectoHabilidad(user.velocidad, MULT1, dificultad, 0);
                        objCountCPU[1]--;
                        variacionHabilidadCPU = -1;
                        benefCPU = 'u';
                        break;
                    case 3:
                        cpu.ataque = efectoHabilidad(cpu.ataque, MULT2, dificultad, 0.25);
                        objCountCPU[2]--;
                        variacionHabilidadCPU = 1;
                        benefCPU = 'c';
                        break;
                    case 4:
                        cpu.velocidad = efectoHabilidad(cpu.velocidad, MULT2, dificultad, 0.25);
                        objCountCPU[3]--;
                        variacionHabilidadCPU = 1;
                        benefCPU = 'c';
                        break;
                    }

                    switch (seleccion)
                    {
                    case 1:
                        cpu.precision = efectoHabilidad(cpu.precision, MULT1, dificultad, 0);
                        objCountUSER[0]--;
                        variacionHabilidadUSER = -1;
                        benefUSER = 'c';
                        break;
                    case 2:
                        cpu.velocidad = efectoHabilidad(cpu.velocidad, MULT1, dificultad, 0);
                        objCountUSER[1]--;
                        variacionHabilidadUSER = -1;
                        benefUSER = 'c';
                        break;
                    case 3:
                        user.ataque = efectoHabilidad(user.ataque, MULT2, dificultad, 0.25);
                        objCountUSER[2]--;
                        variacionHabilidadUSER = 1;
                        benefUSER = 'u';
                        break;
                    case 4:
                        user.velocidad = efectoHabilidad(user.velocidad, MULT2, dificultad, 0.25);
                        objCountUSER[3]--;
                        variacionHabilidadUSER = 1;
                        benefUSER = 'u';
                        break;
                    }

                    if (cpu.velocidad > user.velocidad)
                    {
                        printStats(calculoCPU, variacionHabilidadCPU, benefCPU);
                        enter();
                        printStats(seleccion, variacionHabilidadUSER, benefUSER);
                        enter();
                    }
                    else
                    {
                        printStats(seleccion, variacionHabilidadUSER, benefUSER);
                        enter();
                        printStats(calculoCPU, variacionHabilidadCPU, benefCPU);
                        enter();
                    }

                goto attack;
        }
}

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
    factor = 1 + (r * totalVictorias / totalPartidas);
    return factor;
}

int ataque(estadisticas atacante, estadisticas defensor, int randseed)
{
    int i = 0;
    float n[1000], resn;
    int result = 0;

    srand(time(NULL));
    for (i = 0; i < 1000; i++)
        n[i] = rand() % 1000 * 0.00001;
    resn = n[randseed];
    printf("\n%f\n", resn*atacante.precision);
    if (resn*atacante.precision <= NECESARIO_PRECISION)
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

void printStats (int stat, int variacion, char beneficiario)
{
    //stat: 1 -> precisión, 2 -> ataque, 3 -> defensa, 4 -> velocidad
    //variacion: 1 -> sube, -1 -> baja, 0 -> no cambia
    //beneficiario: u -> usuario, c -> CPU
    switch (stat)
    {
    case 1:
        printf("La precisi%cn ", 162);
        break;
    case 2:
        printf("El ataque ");
        break;
    case 3:
        printf("La defensa ");
        break;
    case 4:
        printf("La velocidad");
        break;
    }
    switch (beneficiario)
    {
    case 'u':
        printf("del usuario ");
        break;
    case 'c':
        printf("de la CPU ");
        break;
    }
    switch (variacion)
    {
    case 1:
        printf("subi%c.\n", 162);
        break;
    case -1:
        printf("baj%c.\n", 162);
        break;
    case 0:
        printf("se mantiene.\n");
        break;
    }
    enter();
}

int efectoHabilidad (int stat, float factor, float difficulty, float sumando)
{
    int result;
    float res = stat * factor * (difficulty + sumando);
    result = res;
    return result;
}
