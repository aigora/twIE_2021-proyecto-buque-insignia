#include <stdio.h>
#include "funcionesTexto.h"

char volverAtras(char x[2]) {
    printf("%cQuieres volver atras? (Escribe 'si' o 'no')\n", 168);
    scanf(" %s", x);
    return x;
}

int inicioPrograma(void) {
    int x;
    printf("Bienvenido a la pagina de inicio de Proyecto Buque Insignia. Escribe 'atras' en cualquier momento para volver a la pagina anterior.\n");
    printf("%cQue quieres hacer? Selecciona entre:\n(1) Personalizar barco\n(2) Jugar\n(3) Puntuacion\n", 168);
    scanf(" %i", &x);
    return x;
}

void error(void) {
    printf("Escribe un caracter valido.\n");
}
