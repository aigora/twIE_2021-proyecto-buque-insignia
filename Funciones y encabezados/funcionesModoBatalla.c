#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "estructuras.h"
#include "funcionesSecundarias.h"
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
    int i = 0;
    //declaraciones y asignaciones de variables
    mainStruct principal;
    principal.contadorStats[0] = (estadisticas){0,0,0,0};
    principal.contadorStats[1] = (estadisticas){0,0,0,0};
    for (i = 0; i < 2; i++)
    {
        strcpy(principal.flechas[i].ataque, "----");
        strcpy(principal.flechas[i].defensa, "----");
        strcpy(principal.flechas[i].velocidad, "----");
        strcpy(principal.flechas[i].precision, "----");
    }
    principal.randVar = 0;
    principal.dificultad = calculoDificultad();
    principal.randseed = -1;
    principal.variacionHabilidad[0] = 0;
    principal.variacionHabilidad[1] = 0;
    principal.exit = 40;//valor aleatorio para ejecutar la función, pero sin arriesgarse a que sea 1 o 0
    principal.exit2 = 40;
    principal.objCountCPU[0] = 2;
    principal.objCountCPU[1] = 2;
    principal.objCountCPU[2] = 2;
    principal.objCountCPU[3] = 2;
    principal.objCountUSER[0] = 2;
    principal.objCountUSER[1] = 2;
    principal.objCountUSER[2] = 2;
    principal.objCountUSER[3] = 2;
    for (i = 0; i < 2; i++)
    {
        principal.contadorStats[i].ataque = 0;
        principal.contadorStats[i].defensa = 0;
        principal.contadorStats[i].velocidad = 0;
        principal.contadorStats[i].vida = 0;
    }


    ///DEBUG
//    printf("\nDificultad: %f\t", principal.dificultad);
//    enter();
//    enter();
    ///DEBUG

    ///Leer y abrir fichero
    FILE *abrirEstadisticas;
    abrirEstadisticas = fopen("estadisticas.csv", "w");
    if (abrirEstadisticas == NULL)
    {
        printf("Error al abrir el fichero.\n");
        return -1;
    }
    principal.cerrar = fclose(abrirEstadisticas);
    if (principal.cerrar == EOF)
    {
        printf("Error al cerrar el fichero.\n");
        return -1;
    }

    abrirEstadisticas = fopen("estadisticas.csv", "r");
    if (abrirEstadisticas == NULL)
    {
        printf("Error al abrir el fichero.\n");
        return -1;
    }
//    else
//        printf("Fichero abierto correctamente.\n");

    fscanf(abrirEstadisticas, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i",
           &principal.usercpu[0].precision, &principal.usercpu[0].ataque, &principal.usercpu[0].defensa, &principal.usercpu[0].velocidad, &principal.usercpu[0].vida,
           &principal.usercpu[1].precision, &principal.usercpu[1].ataque, &principal.usercpu[1].defensa, &principal.usercpu[1].velocidad, &principal.usercpu[1].vida);

    principal.cerrar = fclose(abrirEstadisticas);
    if (principal.cerrar == EOF)
    {
        printf("Error al cerrar el fichero.\n");
        return -1;
    }
//    if (principal.cerrar == 0)
//    printf("Fichero cerrado correctamente.\n");
    ///Fin de lectura del fichero

    clearscr();
    printf("La lancha ha sido destruida. %cQue comience la batalla!\n", 173);
    enter();
    clearscr();

    while (principal.exit != 0 && principal.exit != 1)
        principal = funcionamientoPrincipal(principal);
    return principal.exit;
}

mainStruct funcionamientoPrincipal(mainStruct principal)
{
    estadisticas *pUser, *pCPU;
    pUser = &principal.usercpu[0];
    pCPU = &principal.usercpu[1];
    principal.pflechas = &principal.flechas[0];
    principal.pcontador = &principal.contadorStats[0];
    principal.randseed++;
    clearscr();
    imprimeVida(pUser, pCPU, 0, 0, 0);

    if (principal.usercpu[1].vida <= 0)
    {
        printf("Has ganado. Tienes ahora %i turnos adicionales.", TURNOS_ADICIONALES);
        enter();
        principal.exit = 1;
        return principal;
    }
    if (principal.usercpu[0].vida <= 0)
    {
        printf("Has perdido. La CPU tiene ahora %i turnos adicionales.", TURNOS_ADICIONALES);
        enter();
        principal.exit = 0;
        return principal;
    }

    ///DEBUG: Imprimir estadísticas completas
    printf("\tAtk\tDef\tSpd\tAcc\tHP\nUSR\t%i\t%i\t%i\t%i\t%i\nCPU\t%i\t%i\t%i\t%i\t%i\n",
           principal.usercpu[0].ataque, principal.usercpu[0].defensa, principal.usercpu[0].velocidad, principal.usercpu[0].precision, principal.usercpu[0].vida,
           principal.usercpu[1].ataque, principal.usercpu[1].defensa, principal.usercpu[1].velocidad, principal.usercpu[1].precision, principal.usercpu[1].vida);
    ///DEBUG: Imprimir estadísticas completas

    ///Imprimir cambios en estadísticas

    printArrows(principal.pflechas, principal.pcontador);
    printf("\n\t\tAtq\tDef\tVel\tPre\nTus estad.:\t%s\t%s\t%s\t%s\nEstad. CPU:\t%s\t%s\t%s\t%s\n",
           principal.flechas[0].ataque, principal.flechas[0].defensa, principal.flechas[0].velocidad, principal.flechas[0].precision,
           principal.flechas[1].ataque, principal.flechas[1].defensa, principal.flechas[1].velocidad, principal.flechas[1].precision);
    ///Imprimir cambios en estadísticas

    principal.exit2 = 1;
    while (principal.exit2 != 0 && principal.exit != 0 && principal.exit != 1)
        principal = eleccionInicial(principal);
    return principal;
}

mainStruct eleccionInicial(mainStruct principal)
{
    principal.randseed++;
    printf("\nSelecciona una opción:\n(1) Atacar\n(2) Usar Objetos\n");
    scanf(" %i", &principal.seleccion.user);
    clearscr();

    principal.seleccion.aleatorio = random1(principal.randseed);
    //printf("\nSeleccion aleatorio: %f\n", principal.seleccion.aleatorio);
    if (principal.seleccion.aleatorio > 0.5)
        principal.seleccion.cpu = 1; //ataque
    else
        principal.seleccion.cpu = 2; //habilidad

    principal = accionesGeneral(principal);
    principal.exit2 = 0;
    return principal;
}

mainStruct accionesGeneral(mainStruct principal)
{
    estadisticas *pUser, *pCPU;
    pUser = &principal.usercpu[0];
    pCPU = &principal.usercpu[1];
    principal.seleccionHabilidad.cpu = cpuHabilidad(principal.objCountCPU);

    switch (principal.seleccion.user)
    {
    case 1:
        principal.cpudamage = ataque(pUser, pCPU, principal.randseed);
        principal.usercpu[1].vida -= principal.cpudamage;
        break;
    case 2:
        if (principal.objCountUSER[0] == 0 && principal.objCountUSER[1] == 0 && principal.objCountUSER[2] == 0 && principal.objCountUSER[3] == 0)
        {
            printf("No te quedan objetos.");
            enter();
            return principal;
            break;
        }
        //stat: 1 -> precisión, 2 -> velocidad, 3 -> ataque, 4 -> defensa
        //variacion: 1 -> sube, -1 -> baja, 0 -> no cambia
        //beneficiario: u -> usuario, c -> CPU
        clearscr();
        printf("Escoge un objeto para usarlo:\n");
        if (principal.objCountUSER[0] > 0)
            printf("(1) Bola de Humo\t\t\tBajar precisión del enemigo.\t(%i disponibles)\n", principal.objCountUSER[0]);
        if (principal.objCountUSER[1] > 0)
            printf("(2) Ancla\t\t\t\tBajar velocidad de enemigo.\t(%i disponibles)\n", principal.objCountUSER[1]);
        if (principal.objCountUSER[2] > 0)
            printf("(3) Pólvora Premium\t\t\tAumenta tu ataque.\t\t(%i disponibles)\n", principal.objCountUSER[2]);
        if (principal.objCountUSER[3] > 0)
            printf("(4) Motor Auxiliar\t\t\tAumenta tu velocidad.\t\t(%i disponibles)\n", principal.objCountUSER[3]);

        scanf(" %i", &principal.seleccionHabilidad.user);
        if (principal.objCountUSER[principal.seleccionHabilidad.user - 1] == 0)
        {
            printf("No te quedan objetos de este tipo.\n");
            enter();
            return principal;
            break;
        }

        switch (principal.seleccionHabilidad.user)
        {
        case 1:
            principal.usercpu[1].precision = efectoHabilidad(principal.usercpu[1].precision, MULT1, principal.dificultad, 0);
            principal.objCountUSER[0]--;
            principal.variacionHabilidad[0] = -1;
            principal.benefUSER = 'c';
            principal.contadorStats[1].precision--;
            break;
        case 2:
            principal.usercpu[1].velocidad = efectoHabilidad(principal.usercpu[1].velocidad, MULT1, principal.dificultad, 0);
            principal.objCountUSER[1]--;
            principal.variacionHabilidad[0] = -1;
            principal.benefUSER = 'c';
            principal.contadorStats[1].velocidad--;
            break;
        case 3:
            principal.usercpu[0].ataque = efectoHabilidad(principal.usercpu[0].ataque, MULT2, principal.dificultad, 0.25);
            principal.objCountUSER[2]--;
            principal.variacionHabilidad[0] = 1;
            principal.benefUSER = 'u';
            principal.contadorStats[0].ataque++;
            break;
        case 4:
            principal.usercpu[0].velocidad = efectoHabilidad(principal.usercpu[0].velocidad, MULT2, principal.dificultad, 0.25);
            principal.objCountUSER[3]--;
            principal.variacionHabilidad[0] = 1;
            principal.benefUSER = 'u';
            principal.contadorStats[0].velocidad++;
            break;
        }
        break;

    default:
         error();
         enter();
         return principal;
         break;
    }

    if (principal.seleccionHabilidad.cpu == 0)
    {
        principal.seleccion.cpu = 1;
        printf("A la CPU no le quedan objetos.\n");
        enter();
        printf("%cLa CPU atac%c!\n", 173, 162);
        enter();
    }

    switch (principal.seleccion.cpu)
    {
    case 1:
        principal.userdamage = ataque(pCPU, pUser, principal.randseed);
        principal.usercpu[0].vida -= principal.userdamage;
        break;
    case 2:
        //stat: 1 -> precisión, 2 -> velocidad, 3 -> ataque, 4 -> defensa
        //variacion: 1 -> sube, -1 -> baja, 0 -> no cambia
        //beneficiario: u -> usuario, c -> CPU
        switch (principal.seleccionHabilidad.cpu)
        {
        case 1:
            principal.usercpu[0].precision = efectoHabilidad(principal.usercpu[0].precision, MULT1, principal.dificultad, 0);
            principal.objCountCPU[0]--;
            principal.variacionHabilidad[1] = -1;
            principal.benefCPU = 'u';
            principal.contadorStats[0].precision--;
            break;
        case 2:
            principal.usercpu[0].velocidad = efectoHabilidad(principal.usercpu[0].velocidad, MULT1, principal.dificultad, 0);
            principal.objCountCPU[1]--;
            principal.variacionHabilidad[1] = -1;
            principal.benefCPU = 'u';
            principal.contadorStats[0].velocidad--;
            break;
        case 3:
            principal.usercpu[1].ataque = efectoHabilidad(principal.usercpu[1].ataque, MULT2, principal.dificultad, 0.25);
            principal.objCountCPU[2]--;
            principal.variacionHabilidad[1] = 1;
            principal.benefCPU = 'c';
            principal.contadorStats[1].ataque++;
            break;
        case 4:
            principal.usercpu[1].velocidad = efectoHabilidad(principal.usercpu[1].velocidad, MULT2, principal.dificultad, 0.25);
            principal.objCountCPU[3]--;
            principal.variacionHabilidad[1] = 1;
            principal.benefCPU = 'c';
            principal.contadorStats[1].velocidad++;
            break;
        }
        break;
    }

    if (principal.usercpu[1].velocidad == principal.usercpu[0].velocidad)
    {
        principal.seleccionHabilidad.aleatorio = random1(principal.randseed);
        if (principal.seleccionHabilidad.aleatorio > 0.5)
        {
        //printf("%f", principal.seleccionHabilidad.aleatorio);
            principal.usercpu[0].velocidad += 1;
        }
        else
            principal.usercpu[1].velocidad += 1;
    }
    if (principal.usercpu[1].velocidad > principal.usercpu[0].velocidad)
    {
        printf("CPU: ");
        switch (principal.seleccion.cpu)
        {
        case 1:
            if (principal.userdamage == 0)
            {
                printf("el ataque fall%c.\n", 162);
                enter();
            }
            imprimeVida(pUser, pCPU, principal.userdamage, principal.cpudamage, -1);
            enter();
            break;
        case 2:
            if (principal.seleccionHabilidad.cpu == 4)
                principal.seleccionHabilidad.cpu = 2;
            printStats(principal.seleccionHabilidad.cpu, principal.variacionHabilidad[1], principal.benefCPU);
            enter();
            break;
        }
        printf("T%c: ", 163);
        switch (principal.seleccion.user)
        {
        case 1:
            if (principal.cpudamage == 0)
            {
                printf("el ataque fall%c.\n", 162);
                enter();
            }
            imprimeVida(pUser, pCPU, principal.userdamage, principal.cpudamage, 1);
            enter();
            break;
        case 2:
            if (principal.seleccionHabilidad.user == 4)
                principal.seleccionHabilidad.user = 2;
            printStats(principal.seleccionHabilidad.user, principal.variacionHabilidad[0], principal.benefUSER);
            enter();
            break;
        }
    }

    if (principal.usercpu[1].velocidad < principal.usercpu[0].velocidad)
    {
        printf("T%c: ", 163);
        switch (principal.seleccion.user)
        {
        case 1:
            if (principal.cpudamage == 0)
            {
                printf("el ataque fall%c.\n", 162);
                enter();
            }
            imprimeVida(pUser, pCPU, principal.userdamage, principal.cpudamage, 1);
            enter();
            break;
        case 2:
            if (principal.seleccionHabilidad.user == 4)
                principal.seleccionHabilidad.user = 2;
            printStats(principal.seleccionHabilidad.user, principal.variacionHabilidad[0], principal.benefUSER);
            enter();
            break;
        }
        printf("CPU: ");
        switch (principal.seleccion.cpu)
        {
        case 1:
            if (principal.userdamage == 0)
            {
                printf("el ataque fall%c.\n", 162);
                enter();
            }
            imprimeVida(pUser, pCPU, principal.userdamage, principal.cpudamage, -1);
            enter();
            break;
        case 2:
            if (principal.seleccionHabilidad.cpu == 4)
                principal.seleccionHabilidad.cpu = 2;
            printStats(principal.seleccionHabilidad.cpu, principal.variacionHabilidad[1], principal.benefCPU);
            enter();
            break;
        }
        return principal;
    }
    return principal;
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

int ataque(estadisticas *atacante, estadisticas *defensor, int randseed)
{
    int result = 0;
    float resn = random1(randseed) * 0.01;
    //printf("\nRandom función: %f\n", resn);
    //printf("\nRandom total ataque: %f\n", resn*atacante->precision);
    if (resn*atacante->precision >= NECESARIO_PRECISION)
        result = atacante->ataque * 50 / defensor->defensa;
    return result;
}

void imprimeVida(estadisticas *pUser, estadisticas *pCPU, int diferenciaUser, int diferenciaCPU, int opcion)
{
    int i = 0;
    char healthbarCPU[101];
    char healthbarUSER[101];
    char barras[101];
    for (i = 0; i < 100; i++)
    {
        healthbarCPU[i] = ' ';
        healthbarUSER[i] = ' ';
        barras[i] = 196;
    }
    if (pUser->vida < 0)
        pUser->vida = 0;
    if (pCPU->vida < 0)
        pCPU->vida = 0;
    for (i = 0; i < pUser->vida; i++)
        healthbarUSER[i] = 254;
    for (i = 0; i < pCPU->vida; i++)
        healthbarCPU[i] = 254;
    switch (opcion)
    {
    case 1:
        printf("La vida del enemigo ha disminuido en %i puntos.\nVida CPU: %i%c\n", diferenciaCPU, pCPU->vida, 37);
        printf("%c%s%c\n%c", 218, barras, 191, 179);
        printf("%s", healthbarCPU);
        printf("%c\n%c%s%c\n", 179, 192, barras, 217);
        break;

    case -1:
        printf("Tu vida ha disminuido en %i puntos.\nTu vida: %i%c\n", diferenciaUser, pUser->vida, 37);
        printf("%c%s%c\n%c", 218, barras, 191, 179);
        printf("%s", healthbarUSER);
        printf("%c\n%c%s%c\n", 179, 192, barras, 217);
        break;

    case 0:
        printf("Tu vida: %i%c\n%c%s%c\n%c", pUser->vida, 37, 218, barras, 191, 179);
        printf("%s", healthbarUSER);
        printf("%c\n%c%s%c\n", 179, 192, barras, 217);
        printf("Vida CPU: %i%c\n%c%s%c\n%c", pCPU->vida, 37, 218, barras, 191, 179);
        printf("%s", healthbarCPU);
        printf("%c\n%c%s%c\n", 179, 192, barras, 217);
        break;
    }
    diferenciaCPU = 0;
    diferenciaUser = 0;
}

int cpuHabilidad(int contador[4])
{
    int result, restart = 1;
    while (restart != 0)
    {
        result = rand() % 1000 * 0.001 * 100;
        //printf("\nRandom: %i\n", result);
        if (contador[0] == 0 && contador[1] == 0 && contador[2] == 0 && contador[3] == 0)
        {
            result = 0;
            restart = 0;
        }
        if (result > 0 && result <= 25 && contador[0] > 0)
        {
            result = 1;
            restart = 0;
        }
        if (result > 25 && result <= 50 && contador[1] > 0)
        {
            result = 2;
            restart = 0;
        }
        if (result > 50 && result <= 75 && contador[2] > 0)
        {
            result = 3;
            restart = 0;
        }
        if (result > 75 && result <= 100 && contador[3] > 0)
        {
            result = 4;
            restart = 0;
        }
    }
    //printf("Result: %i\n", result);
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
    default:
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
    default:
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
    default:
        break;
    }
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
    int i = 0, j = 0;

    for (j = 0; j < 2; j++)
    {
        if ((stat + j)->ataque > 0)
        {
            for (i = 0; i < (stat + j)->ataque; i++)
                (flechas + j)->ataque[i] = 24;
        }
        if ((stat + j)->ataque < 0)
        {
            for (i = 0; i < -(stat + j)->ataque; i++)
                (flechas + j)->ataque[i] = 25;
        }
        //
        if ((stat + j)->precision > 0)
        {
            for (i = 0; i < (stat + j)->precision; i++)
                (flechas + j)->precision[i] = 24;
        }
        if ((stat + j)->precision < 0)
        {
            for (i = 0; i < -(stat + j)->precision; i++)
                (flechas + j)->precision[i] = 25;
        }
        //
        if ((stat + j)->defensa > 0)
        {
            for (i = 0; i < (stat + j)->defensa; i++)
                (flechas + j)->defensa[i] = 24;
        }
        if ((stat + j)->defensa < 0)
        {
            for (i = 0; i < -(stat + j)->defensa; i++)
                (flechas + j)->defensa[i] = 25;
        }
        //
        if ((stat + j)->velocidad > 0)
        {
            for (i = 0; i < (stat + j)->velocidad; i++)
                (flechas + j)->velocidad[i] = 24;
        }
        if ((stat + j)->velocidad < 0)
        {
            for (i = 0; i < -(stat + j)->velocidad; i++)
                (flechas + j)->velocidad[i] = 25;
        }
    }
}
