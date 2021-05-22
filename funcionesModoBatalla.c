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

int modoBatalla()
{
    puntuacion puntosBatalla;
    float dificultad;
    int cerrar, seleccion, cpudamage, userdamage, opcionVida, calculoCPU, randseed = -1, variacionHabilidadCPU = 0, variacionHabilidadUSER = 0;
    char benefCPU, benefUSER;
    int objCountUSER[4] = {1,1,1,1};
    int objCountCPU[4] = {1,1,1,1};
    float var = 0;
    dificultad = calculoDificultad();
    estadisticas cpu, user, contadorUser, contadorCPU, *pcontadorUser, *pcontadorCPU;
    contadorCPU.ataque = 0;
    contadorCPU.defensa = 0;
    contadorCPU.velocidad = 0;
    contadorCPU.precision = 0;
    contadorUser.ataque = 0;
    contadorUser.defensa = 0;
    contadorUser.velocidad = 0;
    contadorUser.precision = 0;
    pcontadorCPU = &contadorCPU;
    pcontadorUser = &contadorUser;
    cambiosEstadisticas cUser, cCPU, *pcUser, *pcCPU;
    strcpy(cUser.ataque, "----");
    strcpy(cUser.defensa, "----");
    strcpy(cUser.velocidad, "----");
    strcpy(cUser.precision, "----");
    strcpy(cCPU.ataque, "----");
    strcpy(cCPU.defensa, "----");
    strcpy(cCPU.velocidad, "----");
    strcpy(cCPU.precision, "----");
    pcUser = &cUser;
    pcCPU = &cCPU;

    ///DEBUG
    printf("\nDificultad: %f\n", dificultad);
    enter();
    ///DEBUG

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

    system("cls");
    printf("La lancha ha sido destruida. %cQue comience la batalla!\n", 173);
    enter();

    attack:

        }
}

int accionesModoBatalla()
{
    randseed++;
    system("cls");
    imprimeVida(user.vida, cpu.vida, 0, 0, 0);

    ///DEBUG: Imprimir estadísticas completas
    printf("\tAtk\tDef\tSpd\tAcc\tHP\nUSR\t%i\t%i\t%i\t%i\t%i\nCPU\t%i\t%i\t%i\t%i\t%i\n", user.ataque, user.defensa, user.velocidad, user.precision, user.vida,
               cpu.ataque, cpu.defensa, cpu.velocidad, cpu.precision, cpu.vida);
    ///DEBUG

    //Imprimir cambios en estadísticas
    printArrows(pcUser, pcontadorUser);
    printArrows(pcCPU, pcontadorCPU);
    printf("\n\tAtq\tDef\tVel\tPre\nT%c:\t%s\t%s\t%s\t%s\nCPU:\t%s\t%s\t%s\t%s\n", 163,
           cUser.ataque, cUser.defensa, cUser.velocidad, cUser.precision,
           cCPU.ataque, cCPU.defensa, cCPU.velocidad, cCPU.precision);

    printf("\nSelecciona una opci%cn:\n(1) Atacar\n(2) Usar Objetos\n", 162);
    scanf(" %i", &seleccion);
    system("cls");
    switch (seleccion)//Uso un bucle switch porque puede que añada opciones en el futuro
    {
    case 1:
        puntosBatalla.numeroAcciones++;
        cpudamage = ataque(user, cpu, randseed);
        userdamage = ataque(cpu, user, randseed+1);
        damage();

            }
            imprimeVida(user.vida, cpu.vida, userdamage, cpudamage, opcionVida);
            seleccion = 0;
            goto attack;

    case 2:
        habilidad();
        //stat: 1 -> precisión, 2 -> velocidad, 3 -> ataque, 4 -> defensa
        //variacion: 1 -> sube, -1 -> baja, 0 -> no cambia
        //beneficiario: u -> usuario, c -> CPU
        if (calculoCPU == 4)
                calculoCPU -= 2;
        if (seleccion == 4)
                seleccion -= 2;

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
}

int damage()
{
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
    return 0;
}

int habilidad()
{
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
        return 0;
    }

        calculoCPU = cpuHabilidad(objCountCPU);
        switch (calculoCPU)
        {
        case 0:
            printf("\nA la CPU no le quedan objetos.\n");
            enter();
        case 1:
            user.precision = efectoHabilidad(user.precision, MULT1, dificultad, 0);
            objCountCPU[0]--;
            variacionHabilidadCPU = -1;
            benefCPU = 'u';
            pcontadorUser->precision--;
            break;
        case 2:
            user.velocidad = efectoHabilidad(user.velocidad, MULT1, dificultad, 0);
            objCountCPU[1]--;
            variacionHabilidadCPU = -1;
            benefCPU = 'u';
            pcontadorUser->velocidad--;
            break;
        case 3:
            cpu.ataque = efectoHabilidad(cpu.ataque, MULT2, dificultad, 0.25);
            objCountCPU[2]--;
            variacionHabilidadCPU = 1;
            benefCPU = 'c';
            pcontadorCPU->ataque++;
            break;
        case 4:
            cpu.velocidad = efectoHabilidad(cpu.velocidad, MULT2, dificultad, 0.25);
            objCountCPU[3]--;
            variacionHabilidadCPU = 1;
            benefCPU = 'c';
            pcontadorCPU->velocidad++;
            break;
        }

        switch (seleccion)
        {
        case 1:
            cpu.precision = efectoHabilidad(cpu.precision, MULT1, dificultad, 0);
            objCountUSER[0]--;
            variacionHabilidadUSER = -1;
            benefUSER = 'c';
            pcontadorCPU->precision--;
            break;
        case 2:
            cpu.velocidad = efectoHabilidad(cpu.velocidad, MULT1, dificultad, 0);
            objCountUSER[1]--;
            variacionHabilidadUSER = -1;
            benefUSER = 'c';
            pcontadorCPU->velocidad--;
            break;
        case 3:
            user.ataque = efectoHabilidad(user.ataque, MULT2, dificultad, 0.25);
            objCountUSER[2]--;
            variacionHabilidadUSER = 1;
            benefUSER = 'u';
            pcontadorUser->ataque++;
            break;
        case 4:
            user.velocidad = efectoHabilidad(user.velocidad, MULT2, dificultad, 0.25);
            objCountUSER[3]--;
            variacionHabilidadUSER = 1;
            benefUSER = 'u';
            pcontadorUser->velocidad++;
            break;
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
    printf("\n%f\n", resn);
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

int cpuHabilidad(int contador[4])
{
    int result = random1()*100;

    printf("\nRandom: %i\n", result);
    if (contador[0] == 0 && contador[1] == 0 && contador[2] == 0 && contador[3] == 0)
        result = 0;
    if (result > 0 && result <= 25 && contador[0] > 0)
        result = 1;
    if (result > 25 && result <= 50 && contador[1] > 0)
        result = 2;
    if (result > 50 && result <= 75 && contador[2] > 0)
        result = 3;
    if (result > 75 && result <= 100 && contador[3] > 0)
        result = 4;
    return result;
}

void printStats (int stat, int variacion, char beneficiario)
{
    //stat: 1 -> precisión, 2 -> velocidad, 3 -> ataque, 4 -> defensa
    //variacion: 1 -> sube, -1 -> baja, 0 -> no cambia
    //beneficiario: u -> usuario, c -> CPU
    switch (stat)
    {
    case 1:
        printf("La precisi%cn ", 162);
        break;
    case 2:
        printf("La velocidad ");
        break;
    case 3:
        printf("El ataque ");
        break;
    case 4:
        printf("La defensa ");
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

void printArrows (cambiosEstadisticas *flechas, estadisticas *stat)
{
    int i = 0;
    if (stat->ataque > 0)
    {
        for (i = 0; i < stat->ataque; i++)
            flechas->ataque[i] = 24;
    }
    else if (stat->ataque < 0)
        for (i = 0; i < stat->ataque; i++)
            flechas->ataque[i] = 25;
    else if (stat->ataque == 0)
        strcpy(flechas->ataque, "----");

    if (stat->defensa > 0)
    {
        for (i = 0; i < stat->defensa; i++)
            flechas->defensa[i] = 24;
    }
    else if (stat->defensa < 0)
        for (i = 0; i < stat->defensa; i++)
            flechas->defensa[i] = 25;
    else if (stat->defensa == 0)
        strcpy(flechas->defensa, "----");

    if (stat->velocidad > 0)
    {
        for (i = 0; i < stat->velocidad; i++)
            flechas->velocidad[i] = 24;
    }
    else if (stat->velocidad < 0)
        for (i = 0; i < stat->velocidad; i++)
            flechas->velocidad[i] = 25;
    else if (stat->velocidad == 0)
        strcpy(flechas->velocidad, "----");

    if (stat->precision > 0)
    {
        for (i = 0; i < stat->precision; i++)
            flechas->precision[i] = 24;
    }
    else if (stat->precision < 0)
        for (i = 0; i < stat->precision; i++)
            flechas->precision[i] = 25;
    else if (stat->precision == 0)
        strcpy(flechas->precision, "----");
}
