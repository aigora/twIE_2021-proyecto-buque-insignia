#include <stdio.h>
#include "funcionesTexto.h"

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
    printf("¡Vamos a jugar! \n");
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
