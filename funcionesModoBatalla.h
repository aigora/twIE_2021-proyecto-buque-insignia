#ifndef HEADER_D572DA23AE0E45D7
#define HEADER_D572DA23AE0E45D7
#include "estructuras.h"

float calculoDificultad(void);
int ataque(estadisticas atacante, estadisticas defensor, int randseed);
void imprimeVida(int vidaUSER, int vidaCPU, int diferenciaUser, int diferenciaCPU, int opcion);
int cpuHabilidad(int contador[4]);
int accionHabilidades(estadisticas usuario, estadisticas oponente, float dificultad, int obj[4], int selector);
int efectoHabilidad (int stat, float factor, float dificultad, float sumando);
int modoBatalla();
void printStats (int stat, int variacion, char beneficiario);
void printArrows (cambiosEstadisticas *flechas, estadisticas *stat);
void clearscr(void);

#endif // header guard

