#ifndef HEADER_ECC246FBACE936A4
#define HEADER_ECC246FBACE936A4

typedef struct
{
    int numeroAcciones, totalDamageRecibido, totalDamageOcasionado, puntuacionTot, victoria, barcosHundidos;
} puntuacion;

typedef struct
{
    int precision, ataque, defensa, velocidad, vida;
} estadisticas;

typedef struct
{
    char ataque[5], defensa[5], velocidad[5], precision[5];
} cambiosEstadisticas;

#endif // header guard

