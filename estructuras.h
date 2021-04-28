#ifndef HEADER_ECC246FBACE936A4
#define HEADER_ECC246FBACE936A4

typedef struct
{
    int numeroAcciones, totalDamageRecibido, totalDamageOcasionado, puntuacion, victoria, barcosHundidos;
} puntuacion;

typedef struct
{
    float precision, ataque, defensa, velocidad;
    int efectividad;
} estadisticas;

typedef struct
{
    int totalGanadas, totalPerdidas, totalAcciones, totalPartidas;
} puntuacionGlobal;


#endif // header guard

