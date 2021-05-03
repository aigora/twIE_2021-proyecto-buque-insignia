#include <stdio.h>
#include "funcionesTexto.h"
#define LONG_PUNTUACION_CSV 8

int inicioPrograma(int x) {
    printf("Bienvenido a la pagina de inicio de Proyecto Buque Insignia.\nEscribe 'atras' en cualquier momento para volver a la pagina anterior.\n\n");
    printf("%cQue quieres hacer? Selecciona entre:\n(1) Personalizar barco\n(2) Jugar\n(3) Puntuacion\n", 168);
    scanf(" %i", &x);
    return x;
}

void error(void) {
    printf("Caracter v%clido. Vuelve a intentarlo.\n", 160);
}

int jugar(void) {
    int radioSonar;
    char x[8];
    printf("�Vamos a jugar! \n");
    printf("Elige el nivel de dificultad:\nEscribe 'facil', 'medio' o 'dificil'.\n");
    scanf(" %s", x);
    switch (x[0]) {
    case 'f':
        radioSonar = 3;
        break;
    case 'm':
        radioSonar = 2;
        break;
    case 'd':
        radioSonar = 0;
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
    /// Leer y cerrar fichero
    FILE *abrirPuntuacion;
    int cerrar, leerPuntuacion[LONG_PUNTUACION_CSV];
    abrirPuntuacion = fopen("puntuacionTotal.csv", "r");
    if (abrirPuntuacion == NULL) {
        printf("Error al abrir el fichero.\n");
        return -1;
    }
    else
        printf("Fichero abierto correctamente.\n");

    leerPuntuacion = fscanf(abrirPuntuacion, "%i, %i, %i, %i, %i, %i, %i\n", &leerPuntuacion[1], &leerPuntuacion[2],
                &leerPuntuacion[3], &leerPuntuacion[4], &leerPuntuacion[5], &leerPuntuacion[6], &leerPuntuacion[7]);

    cerrar = fclose(abrirPuntuacion);
    if (cerrar == EOF) {
        printf("Error al cerrar el fichero.\n");
        return -1;
    }
    if (cerrar == 0)
        printf("Fichero cerrado correctamente.\n");
    /// Fin de lectura del fichero

    switch (dato)
    {
    case 'n':
        return leerPuntuacion[1];
        break;
    case 'p':
        return leerPuntuacion[2];
        break;
    case 'm':
        return leerPuntuacion[3];
        break;
    case 'd':
        return leerPuntuacion[4];
        break;
    case 'o':
        return leerPuntuacion[5];
        break;
    case 'h':
        return leerPuntuacion[6];
        break;
    case 'v':
        return leerPuntuacion[7];
        break;
    }
}
