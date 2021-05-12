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

int modoBatalla(void)
{
    float dificultad;
    int cerrar, seleccion, cpudamage, userdamage, opcionVida, calculoCPU = cpuHabilidad(), randseed = -1;
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

                    enter();
                    switch (calculoCPU)
                    {
                    case 1:
                        printf("T%c: ", 163);
                        user.precision = accionHabilidades(cpu, user, dificultad, objCountCPU, calculoCPU);
                        break;
                    case 2:
                        printf("T%c: ", 163);
                        user.velocidad = accionHabilidades(cpu, user, dificultad, objCountCPU, calculoCPU);
                        break;
                    case 3:
                        printf("CPU: ");
                        cpu.ataque = accionHabilidades(cpu, user, dificultad, objCountCPU, calculoCPU);
                        break;
                    case 4:
                        printf("CPU: ");
                        cpu.velocidad = accionHabilidades(cpu, user, dificultad, objCountCPU, calculoCPU);
                        break;
                    }
                    enter();
                    switch (seleccion)
                    {
                    case 1:
                        printf("CPU: ");
                        cpu.precision = accionHabilidades(user, cpu, dificultad, objCountUSER, seleccion);
                        break;
                    case 2:
                        printf("CPU: ");
                        cpu.velocidad = accionHabilidades(user, cpu, dificultad, objCountUSER, seleccion);
                        break;
                    case 3:
                        printf("T%c: ", 163);
                        user.ataque = accionHabilidades(user, cpu, dificultad, objCountUSER, seleccion);
                        break;
                    case 4:
                        printf("T%c: ", 163);
                        user.velocidad = accionHabilidades(user, cpu, dificultad, objCountUSER, seleccion);
                        break;
                    }
                enter();
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
    factor = 1 + r * totalVictorias / totalPartidas;
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
