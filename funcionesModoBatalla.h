#ifndef HEADER_D572DA23AE0E45D7
#define HEADER_D572DA23AE0E45D7

float calculoDificultad(void);
int ataque(estadisticas atacante, estadisticas defensor);
void imprimeVida(int vidaUSER, int vidaCPU, int diferenciaUser, int diferenciaCPU, int opcion);
int cpuHabilidad(void);
int accionHabilidades(estadisticas usuario, estadisticas oponente, float dificultad, int obj[4], int selector);
int efectoHabilidad (int stat, float factor, float dificultad, float minuendo);
int modoBatalla(void);

#endif // header guard

