#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcionesSecundarias.h"
#include "estructuras.h"
#include "funcionesModoBatalla.h"

//Esquema desbloqueables.csv:
//Nombre del barco,Precisión,Ataque,Defensa,Velocidad,Vida,Obj1,Obj2,Obj3,Obj4,Puntuacion necesaria

//Esquema puntuacionTotal.csv:
//Usuario,Total partidas,Puntuacion Total,Total Daño recibido,Total Daño ocasionado,Total Barcos hundidos,Total victorias.

int start(int condicion, int victoria, char volver[6], const char atras[6], puntuacion *puntos);

int main()
{
    login registro;
    puntuacion puntuacionTotal, *puntos;
    puntos = &puntuacionTotal;
    srand(time(NULL));
    char volver[6];
    const char atras[6] = "atras";
    int condicion = 0, inicio = 1, victoria = 0;
    registro = sesion();
    if (registro.checkpass[0] == 0)
    {
        clearscr();
        printf("Se han creado los archivos. Reinicia el juego.\n");
        return 0;
    }

    strcpy(puntuacionTotal.nombre, registro.user);
    //printf("Tu nombre: %s\n", puntos->nombre);
    while (inicio != 0)
        inicio = start(condicion, victoria, volver, atras, puntos);
    return 0;
}

int start(int condicion, int victoria, char volver[6], const char atras[6], puntuacion *puntos)
{
    char buff[2000], usuarios[2000][200], contrasenas[2000][200], nombresPuntuacion[2000][200], nombresPuntuacion[2000][200], totalVictorias = 0, totalPartidas = 0;
    desbloqueables bufer[2000];
    FILE *pflog;
    pflog = fopen("registro.csv", "r");
    int i = 0, exit = 0, cerrar, puntosnecesarios;
    puntuacion puntosvec[2000];
    while (fgets(buff, 2000, pflog) != NULL)
    {
        sscanf(buff, "%[^,],%[^\n]\n", usuarios[i], contrasenas[i]);
        i++;
    }
    cerrar = fclose(pflog);
    if (cerrar == EOF)
    {
        printf("Error al cerrar el fichero.");
        return 0;
    }
    FILE *pf;
    pf = fopen("puntuacionTotal.csv", "r");
    i = 0;
    while (fgets(buff, 2000, pf) != NULL)
    {
        sscanf(buff, "%[^,],%i,%i,%i,%i,%i,%i\n", nombresPuntuacion[i], &puntosvec[i].totalPartidas, &puntosvec[i].puntuacionTot, &puntosvec[i].totalDamageRecibido,
               &puntosvec[i].totalDamageOcasionado, &puntosvec[i].barcosHundidos, &puntosvec[i].victorias);
        if (strcmp(puntos->nombre, nombresPuntuacion[i]) == 0)
        {
            puntos->totalPartidas = puntosvec[i].totalPartidas;
            puntos->puntuacionTot = puntosvec[i].puntuacionTot;
            puntos->totalDamageRecibido = puntosvec[i].totalDamageRecibido;
            puntos->totalDamageOcasionado = puntosvec[i].totalDamageOcasionado;
            puntos->barcosHundidos = puntosvec[i].barcosHundidos;
            puntos->victorias = puntosvec[i].victorias;
        }
        i++;
    }
//    printf("\nPuntero -> %s,%i,%i,%i,%i,%i,%i\n", puntos->nombre, puntos->totalPartidas, puntos->puntuacionTot, puntos->totalDamageRecibido, puntos->totalDamageOcasionado,
//           puntos->barcosHundidos, puntos->victorias);
    cerrar = fclose(pf);
    if (cerrar == EOF)
    {
        printf("Error al cerrar el fichero.\n");
        enter();
    }

    ///
    FILE *abrirDesbloq;
    int flag = 0;
    abrirDesbloq = fopen("desbloqueables.csv", "r");
    if (abrirDesbloq == NULL)
    {
        flag = 1;
        fclose(abrirDesbloq);
    }
    else
        fclose(abrirDesbloq);
    if (flag == 1)
    {
        flag = generarDesbloqueables();
    }

    abrirDesbloq = fopen("desbloqueables.csv", "r");
    if (abrirDesbloq == NULL)
    {
        flag = 1;
        fclose(abrirDesbloq);
    }
    else
    {
        FILE *abrirEstadisticas;
        abrirEstadisticas = fopen("estadisticas.csv", "w");
        if (abrirEstadisticas == NULL)
        {
            printf("Error al abrir el archivo estadisticas.csv");
            return 0;
        }
        i = 0;
        while (fgets(buff, 2000, abrirDesbloq) != NULL)
        {
            sscanf(buff, "%[^,],%i,%i,%i,%i,%i,%i,%i,%i,%i,%i", bufer[i].nombre, &bufer[i].precision, &bufer[i].ataque, &bufer[i].defensa,
                   &bufer[i].velocidad, &bufer[i].vida, &bufer[i].objetos[0], &bufer[i].objetos[1], &bufer[i].objetos[2], &bufer[i].objetos[3], &bufer[i].puntosNecesarios);
            if (bufer[i].puntosNecesarios >= puntos->puntuacionTot && bufer[i - 1].puntosNecesarios <= puntos->puntuacionTot)
            {
                fprintf(abrirEstadisticas, "%s,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i")
            }
        }
        printf("\n");
        condicion = inicioPrograma();
        switch (condicion)
        {
        case 1:
            clearscr();
            printf("Has seleccionado personalizar barco.\n");
            scanf("%s", volver);
            break;

        case 2:
            clearscr();
            printf("Has seleccionado Jugar.\n");
            exit = jugar(puntos);
            guardarPuntuaciones(puntos);
            if (exit == 555)
                return 1;
            break;

        case 3:
            printf("Has seleccionado Puntuacion. Escribe 'v' para ver la puntuacion.\n");
            scanf("%s", volver);
            if (strcmp(volver, "v") == 0)
                verPuntuacion();
            ///
            break;

        ///EXPERIMENTAL. Comentar, no borrar. Puede ser útil para debuguear.
        case 4:
            victoria = modoBatalla(puntos);
            if (victoria == 1)
                printf("Has ganado.");
            if (victoria == 0)
                printf("Has perdido.");
            return 1;
            break;
        ///EXPERIMENTAL

        default:
            clearscr();
            error();
            return 1;
            break;
        }
    }
    return 0;
}
