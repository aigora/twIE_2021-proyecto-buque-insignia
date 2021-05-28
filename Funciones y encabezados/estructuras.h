#ifndef HEADER_ECC246FBACE936A4
#define HEADER_ECC246FBACE936A4

typedef struct
{
    int totalDamageRecibido, totalDamageOcasionado, puntuacionTot, victorias, barcosHundidos, totalPartidas;
    char nombre[20], rango[50];
} puntuacion;

typedef struct
{
    int precision, ataque, defensa, velocidad, vida;
} estadisticas;

typedef struct
{
    char ataque[5], defensa[5], velocidad[5], precision[5];
} cambiosEstadisticas;

typedef struct
{
    int cpu, user;
    float aleatorio;
} eleccion;

typedef struct
{
    estadisticas usercpu[2], contadorStats[2], *pcontador;
    cambiosEstadisticas flechas[2], *pflechas;
    puntuacion puntosBatalla;
    eleccion seleccion, seleccionHabilidad;
    int randseed, mainFunction, cerrar, select, cpudamage, userdamage, opcionVida, calculoCPU, variacionHabilidad[2], objCountUSER[4], objCountCPU[4];
    int exit, exit2;
    float dificultad, randVar;
    char benefCPU, benefUSER;
} mainStruct;

typedef struct
{
    char nombre[200];
    estadisticas stats;
    int objetos[4], puntosNecesarios;
} desbloqueables;

typedef struct
{
    char user[20], pass[100], checkpass[100];
} login;

#endif // header guard

