#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcionesTexto.h"
#include "estructuras.h"
#include "funcionesModoBatalla.h"

int main()
{
    float dificultad;
    int cerrar, intro;
    int seleccion, cpudamage, userdamage;
    dificultad = calculoDificultad();
    estadisticas cpu, user;

    /// Leer y abrir fichero
    FILE *abrirEstadisticas;          //Lo hago con ficheros porque en el futuro quiero añadir un sistema de mejoras según las partidas jugadas, o un sistema de recompensas
    abrirEstadisticas = fopen("estadisticas.csv", "r");
    if (abrirEstadisticas == NULL) {
        printf("Error al abrir el fichero.\n");
        return -1;
    }
    else
        printf("Fichero abierto correctamente.\n");

    fscanf(abrirEstadisticas, "%i, %i, %i, %i, %i, %i, %i, %i, %i, %i", &user.precision, &user.ataque,
                &user.defensa, &user.velocidad, &user.vida, &cpu.precision, &cpu.ataque, &cpu.defensa, &cpu.velocidad, &cpu.vida);

    cerrar = fclose(abrirEstadisticas);
    if (cerrar == EOF) {
        printf("Error al cerrar el fichero.\n");
        return -1;
    }
    if (cerrar == 0)
    printf("Fichero cerrado correctamente.\n");
    /// Fin de lectura del fichero

    printf("La lancha ha sido destruida. ¡Que comience la batalla!\n");
    enter();
    while (cpu.vida != 0 || user.vida != 0)
    {
    attack:
        system("cls");
        printf("Selecciona una opci%cn:\n(1) Atacar\n(2) Usar Objetos\n", 162);
        scanf(" %i", &seleccion);
        switch (seleccion)              //Uso un bucle switch porque puede que añada opciones en el futuro
        {
        case 1:
            damage:
                if (user.velocidad > cpu.velocidad) {
                    cpudamage = ataque(user, cpu);
                    userdamage = ataque(cpu, user);
                    cpu.vida -= cpudamage;
                    printf("La vida del enemigo ha disminuido en %i puntos.\nVida CPU: ", cpudamage);
                    imprimeVida(cpu.vida);
                    user.vida -= userdamage;
                    enter();
                    printf("Tu vida ha disminuido en %i puntos.\nTu vida: ", userdamage);
                    imprimeVida(user.vida);
                    seleccion = 0;
                    goto attack;
                }
                if (cpu.velocidad > user.velocidad) {
                    cpudamage = ataque(user, cpu);
                    userdamage = ataque(cpu, user);
                    user.vida -= userdamage;
                    printf("Tu vida ha disminuido en %i puntos.\nTu vida:\t\t", userdamage);
                    imprimeVida(user.vida);
                    cpu.vida -= cpudamage;
                    enter();
                    printf("La vida del enemigo ha disminuido en %i puntos.\nVida CPU:\t\t", cpudamage);
                    imprimeVida(cpu.vida);
                    seleccion = 0;
                    goto attack;
                }
                if (cpu.velocidad == user.velocidad) {
                    if (random() > 50)
                        user.velocidad += 1;
                    else
                        cpu.velocidad += 1;
                    goto damage;
                }

        case 2:
            system("cls");
            printf("Escoge un objeto para usarlo:\n\
(1) Bola de Humo\t\t\tBajar precisi%cn del enemigo\n\
(2) Ancla\t\t\t\tBajar velocidad de enemigo\n\
(3) P%clvora Premium\t\t\tAumenta tu ataque\n\
(4) Motor Auxiliar\t\t\tAumenta tu velocidad\n", 162, 162);
            scanf(" %i", &seleccion);
            switch (seleccion)
            {
            case 1:
                cpu.precision = cpu.precision * 0.75 * dificultad;
                break;
            case 2:
                cpu.velocidad = cpu.velocidad * 0.75 * dificultad;
                break;
            case 3:
                user.ataque = user.ataque * 1.25 * (2 - dificultad);
                break;
            case 4:
                user.velocidad = user.velocidad * 1.25 * (2 - dificultad);
                break;
            }
            switch (cpuHabilidad())
            {
            case 1:
                user.precision = user.precision * 0.75 * (2 - dificultad);
                break;
            case 2:
                user.velocidad = user.velocidad * 0.75 * (2 - dificultad);
                break;
            case 3:
                cpu.ataque = cpu.ataque * 1.25 * dificultad;
                break;
            case 4:
                cpu.velocidad = cpu.velocidad * 1.25 * dificultad;
                break;
            }
        goto attack;
        }
    }
    if (cpu.vida != 0 && user.vida == 0)
        return 0;
    if (cpu.vida == 0 && user.vida != 0)
        return 1;
}
