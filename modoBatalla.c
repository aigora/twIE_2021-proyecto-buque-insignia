#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcionesTexto.h"
#include "estructuras.h"
#include "funcionesModoBatalla.h"
#define TURNOS_ADICIONALES 3

int main()
{
    float dificultad;
    int cerrar, seleccion, cpudamage, userdamage, opcionVida, calculoCPU = cpuHabilidad();
    int objCountUSER[4] = {1,1,1,1};
    int objCountCPU[4] = {1,1,1,1};
    puntuacion puntosBatalla;
    dificultad = calculoDificultad();
    estadisticas cpu, user;
    printf("%f", dificultad);
    enter();

    /// Leer y abrir fichero
    FILE *abrirEstadisticas;          //Lo hago con ficheros porque en el futuro quiero añadir un sistema de mejoras según las partidas jugadas, o un sistema de recompensas
    abrirEstadisticas = fopen("estadisticas.csv", "r");
    if (abrirEstadisticas == NULL) {
        printf("Error al abrir el fichero.\n");
        return -1;
    }
//    else
//        printf("Fichero abierto correctamente.\n");

    fscanf(abrirEstadisticas, "%i, %i, %i, %i, %i, %i, %i, %i, %i, %i", &user.precision, &user.ataque,
                &user.defensa, &user.velocidad, &user.vida, &cpu.precision, &cpu.ataque, &cpu.defensa, &cpu.velocidad, &cpu.vida);

    cerrar = fclose(abrirEstadisticas);
    if (cerrar == EOF) {
        printf("Error al cerrar el fichero.\n");
        return -1;
    }
//    if (cerrar == 0)
//    printf("Fichero cerrado correctamente.\n");
    /// Fin de lectura del fichero

    printf("La lancha ha sido destruida. %cQue comience la batalla!\n", 173);
    enter();

    attack:
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
            cpudamage = ataque(user, cpu);
            userdamage = ataque(cpu, user);
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
Recuerda que puedes ver el historial de puntuaciones en el menú principal.", TURNOS_ADICIONALES, );
                        return 0;
                    }
                }
                if (cpu.velocidad == user.velocidad)
                {
                    if (random() > 50)
                        user.velocidad += 1;
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
