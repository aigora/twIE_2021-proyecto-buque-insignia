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
int generarDesbloqueables(void);
void guardarPuntuaciones(puntuacion *puntos);
void verPuntuacion(void);
login sesion(void);

#endif // header guard

