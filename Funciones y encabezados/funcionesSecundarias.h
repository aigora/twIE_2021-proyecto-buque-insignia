#ifndef HEADER_D89ED7624FCA316B
#define HEADER_D89ED7624FCA316B
#include "estructuras.h"

int inicioPrograma(void);
void error(void);
int jugar(puntuacion *puntos);
int puntuaciones(char dato);
int random(int randseed);
float random1(int randseed);
int enter(void);
void clearscr(void);
int generarDesbloqueables(login registro);
int guardarPuntuaciones(puntuacion *puntos);
int verPuntuacion(void);
login sesion(void);
int calculoConstanteEcDif(int maxPuntos);
int calculoEcDif(int nivel, int k);
int comprobarCierreFichero(int cerrar);
int comprobarAperturaFichero(FILE *puntero);
int sumando(void);
int leerFicheros(login registro, puntuacion *puntos);

#endif // header guard

