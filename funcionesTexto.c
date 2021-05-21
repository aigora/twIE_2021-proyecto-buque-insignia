#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesTexto.h"
#include "Matriz.h"
#include "estructuras.h"
#define LONG_PUNTUACION_CSV 7
#define LONG_BUFFER 100

int inicioPrograma(void)
{
    int x = 0;
    printf("Bienvenido a la pagina de inicio de Proyecto Buque Insignia.\nEscribe 'atras' en cualquier momento para volver a la pagina anterior.\n\n");
    printf("%cQue quieres hacer? Selecciona entre:\n(1) Personalizar barco\n(2) Jugar\n(3) Puntuacion\n", 168);
    printf("\nEXPERIMENTAL\n(4) Modo Batalla\n");//Provisional
    scanf(" %i", &x);
    return x;
}

void error(void)
{
    printf("Caracter v%clido. Vuelve a intentarlo.\n", 160);
    enter();
    enter();
}

int jugar(void)
{
    int radioSonar;
    char x[8];
    printf("¡Vamos a jugar! \n");
    printf("Elige el nivel de dificultad:\nEscribe 'facil', 'medio' o 'dificil'.\n");
    scanf(" %s", x);
    switch (x[0]) {
    case 'f':
        radioSonar = 3;
        Matriz(radioSonar);
        break;
    case 'm':
        radioSonar = 2;
        Matriz(radioSonar);
        break;
    case 'd':
        radioSonar = 0;
        Matriz(radioSonar);
        break;
    case 'a':
        radioSonar = 555;
        break;
    }
    if (radioSonar != 555)
        printf("El radio del sonar esta establecido a %i.", radioSonar);
    return radioSonar;
}

int puntuaciones(char dato)
{
    /// Leer fichero
    FILE *abrirPuntuacion;
    int cerrar, leerPuntuacion[LONG_PUNTUACION_CSV], solucion, i = 0, lineasTotales = 0, lineas = 0, confirm = 0;
    char nombre[4], buff[LONG_BUFFER], scanResult, data[LONG_BUFFER];
    abrirPuntuacion = fopen("puntuacionTotal.csv", "r");
    if (abrirPuntuacion == NULL) {
        printf("Error al abrir el fichero.\n");
        return -1;
    }
//    else
//        printf("Fichero abierto correctamente.\n");

    while (fscanf(abrirPuntuacion, "%c", &scanResult) != EOF)
    {
        if (scanResult == '\n')
            lineasTotales++;
    }

    fseek(abrirPuntuacion, SEEK_CUR, 0); //Mueve la posición del fichero al principio

    while (fgets(buff, LONG_BUFFER, abrirPuntuacion) != NULL)
    {
        for (i = 0; i < LONG_BUFFER; i++)
        {
            if (buff[i] == '\n')
                lineas++;
            if (lineas == lineasTotales && confirm == 0)
            {
                strcpy(data, buff);
                confirm++;
            }
        }
    }

    sscanf(data, "%[^,],%i,%i,%i,%i,%i,%i,%i", nombre, &leerPuntuacion[0], &leerPuntuacion[1], &leerPuntuacion[2], &leerPuntuacion[3],
                       &leerPuntuacion[4], &leerPuntuacion[5], &leerPuntuacion[6]);

    cerrar = fclose(abrirPuntuacion);
    if (cerrar == EOF) {
        printf("Error al cerrar el fichero.\n");
        enter();
        enter();
        return -1;
    }
//    if (cerrar == 0)
//        printf("Fichero cerrado correctamente.\n");
    /// Fin de lectura del fichero

    switch (dato)
    {
    case 'n':
        solucion = leerPuntuacion[1];
        break;
    case 'p':
        solucion = leerPuntuacion[2];
        break;
    case 'm':
        solucion = leerPuntuacion[3];
        break;
    case 'd':
        solucion = leerPuntuacion[4];
        break;
    case 'o':
        solucion = leerPuntuacion[5];
        break;
    case 'h':
        solucion = leerPuntuacion[6];
        break;
    case 'v':
        solucion = leerPuntuacion[7];
        break;
    }
    return solucion;
}

int random(void)
{
    srand(time(NULL));
    return rand();
}

float random1(void)
{
  return random() % 1000 * 0.001;
}

int enter(void)
{
    char ch;
    intro:
        ch = getchar();
        if (ch == '\n')
            return 1;
        else
        {
            printf("Pulsa ENTER para continuar...");
            goto intro;
        }
}


