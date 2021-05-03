#ifndef HEADER_ECC246FBACE936A4
#define HEADER_ECC246FBACE936A4

typedef struct
{
    int numeroAcciones, totalDamageRecibido, totalDamageOcasionado, puntuacion, victoria, barcosHundidos;
} puntuacion;

typedef struct
{
    int precision, ataque, defensa, velocidad, vida;
} estadisticas;

typedef struct
{
    int totalGanadas, totalPerdidas, totalAcciones, totalPartidas;
} puntuacionGlobal;


#endif // header guard

