#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesSecundarias.h"
#include "Matriz.h"
#include "estructuras.h"
#define LONG_PUNTUACION_CSV 7
#define LONG_BUFFER 100
#define NUMERO_DESBLOQ 17

int inicioPrograma(void)
{
    int x = 0;
    printf("Bienvenido a la pagina de inicio de Proyecto Buque Insignia.\nEscribe 'atras' en cualquier momento para volver a la pagina anterior.\n\n");
    printf("%cQue quieres hacer? Selecciona entre:\n(1) Personalizar barco\n(2) Jugar\n(3) Puntuacion\n", 168);
    //printf("\nEXPERIMENTAL\n(4) Modo Batalla\n");//Provisional
    scanf(" %i", &x);
    return x;
}

void error(void)
{
    printf("Caracter v%clido. Vuelve a intentarlo.\n", 160);
}

int jugar(puntuacion *puntos)
{
    int radioSonar;
    char x[8];
    printf("¡Vamos a jugar! \n");
    printf("Elige el nivel de dificultad:\nEscribe 'facil', 'medio' o 'dificil'.\n");
    scanf(" %s", x);
    switch (x[0]) {
    case 'f':
        radioSonar = 3;
        Matriz(radioSonar, puntos);
        break;
    case 'm':
        radioSonar = 2;
        Matriz(radioSonar, puntos);
        break;
    case 'd':
        radioSonar = 0;
        Matriz(radioSonar, puntos);
        break;
    case 'a':
        radioSonar = 555;
        break;
    }
    if (radioSonar != 555)
        printf("El radio del sonar esta establecido a %i.", radioSonar);
    return radioSonar;
}

int puntuaciones(char dato)
{
    /// Leer fichero
    FILE *abrirPuntuacion;
    int cerrar, leerPuntuacion[LONG_PUNTUACION_CSV], solucion, i = 0, lineasTotales = 0, lineas = 0, confirm = 0;
    char nombre[4], buff[LONG_BUFFER], scanResult, data[LONG_BUFFER];
    abrirPuntuacion = fopen("puntuacionTotal.csv", "w");
    if (abrirPuntuacion == NULL)
    {
        printf("Error al abrir el fichero.\n");
        return -1;
    }
    cerrar = fclose(abrirPuntuacion);
    if (cerrar == EOF)
    {
        printf("Error al cerrar el fichero.\n");
        return -1;
    }

    abrirPuntuacion = fopen("puntuacionTotal.csv", "r");
    if (abrirPuntuacion == NULL) {
        printf("Error al abrir el fichero.\n");
        return -1;
    }
//    else
//        printf("Fichero abierto correctamente.\n");

    while (fscanf(abrirPuntuacion, "%c", &scanResult) != EOF)
    {
        if (scanResult == '\n')
            lineasTotales++;
    }

    fseek(abrirPuntuacion, SEEK_CUR, 0); //Mueve la posición del fichero al principio

    while (fgets(buff, LONG_BUFFER, abrirPuntuacion) != NULL)
    {
        for (i = 0; i < LONG_BUFFER; i++)
        {
            if (buff[i] == '\n')
                lineas++;
            if (lineas == lineasTotales && confirm == 0)
            {
                strcpy(data, buff);
                confirm++;
            }
        }
    }

    sscanf(data, "%[^,],%i,%i,%i,%i,%i,%i,%i", nombre, &leerPuntuacion[0], &leerPuntuacion[1], &leerPuntuacion[2], &leerPuntuacion[3],
                       &leerPuntuacion[4], &leerPuntuacion[5], &leerPuntuacion[6]);

    cerrar = fclose(abrirPuntuacion);
    if (cerrar == EOF) {
        printf("Error al cerrar el fichero.\n");
        return -1;
    }
//    if (cerrar == 0)
//        printf("Fichero cerrado correctamente.\n");
    /// Fin de lectura del fichero

    switch (dato)
    {
    case 'n':
        solucion = leerPuntuacion[1];
        break;
    case 'p':
        solucion = leerPuntuacion[2];
        break;
    case 'm':
        solucion = leerPuntuacion[3];
        break;
    case 'd':
        solucion = leerPuntuacion[4];
        break;
    case 'o':
        solucion = leerPuntuacion[5];
        break;
    case 'h':
        solucion = leerPuntuacion[6];
        break;
    case 'v':
        solucion = leerPuntuacion[7];
        break;
    }
    return solucion;
}

int random(int randseed)
{
    int i;
    float res[1000];
    for (i = 0; i < 1000; i++)
        res[i] = rand();
    return res[randseed];
}

float random1(int randseed)
{
    int i;
    float res[1000];
    for (i = 0; i < 1000; i++)
        res[i] = random(randseed) % 1000 * 0.001;
    return res[randseed];
}

int enter(void)
{
    char ch = 0, ch2 = 0;
    while (ch != '\n')
    {
        ch = getchar();
        ch2 = getchar();
    }
    if (ch != '\n' && ch2 != '\n')
    {
        printf("Pulsa ENTER para continuar...");
        return 0;
    }
    return 1;
}

void clearscr()
{
    printf("\033[2J");
//    for (int i = 0; i < 200; i++)
//        printf("\n");
}

int generarDesbloqueables(void)
{
    FILE *abrirDesbloq;
    int i = 0, j = 0, k = 0, cerrar;
    desbloqueables datos[NUMERO_DESBLOQ];
    datos[0].block = '·';
    for (i = 1; i < NUMERO_DESBLOQ; i++)
        datos[i].block = '!';
    char todosLosNombres[2000];
    int todasLasEstadisticasYObjetos[NUMERO_DESBLOQ][9] =
    {
        { 90, 60, 55, 60, 60,0,1,0,1},
        { 90, 65, 60, 60, 70,1,0,1,0},
        { 90, 70, 65, 50, 80,1,2,1,1},
        { 90, 73, 70, 55, 90,2,2,2,1},
        { 90, 75, 70, 60,100,3,3,3,2},
        { 95, 80, 70, 65,100,2,3,3,2},
        { 95, 80, 75, 65,100,2,2,3,4},
        { 95, 85, 75, 70,100,4,2,2,3},
        { 95, 85, 80, 70,100,3,4,3,3},
        { 95, 90, 80, 80,100,4,3,4,3},
        { 95, 90, 80, 90,100,4,4,3,4},
        { 95, 90, 85, 75,100,4,4,4,4},
        { 95, 95, 85, 85,100,4,4,4,4},
        { 95, 95, 90, 90,100,4,4,4,4},
        {100, 95, 90, 85,100,4,4,4,4},
        {100, 95,100, 95,100,4,4,4,4},
        {100,100,100,100,100,4,4,4,4},
    };
    for (i = 0; i < NUMERO_DESBLOQ; i++)
    {
        datos[i].stats.precision = todasLasEstadisticasYObjetos[i][0];
        datos[i].stats.ataque    = todasLasEstadisticasYObjetos[i][1];
        datos[i].stats.defensa   = todasLasEstadisticasYObjetos[i][2];
        datos[i].stats.velocidad = todasLasEstadisticasYObjetos[i][3];
        datos[i].stats.vida      = todasLasEstadisticasYObjetos[i][4];
        for (j = 5; j < 9; j++)
        {
            k = j - 5;
            datos[i].objetos[k] = todasLasEstadisticasYObjetos[i][j];
        }
    }
    strcpy(todosLosNombres, "Soldado,Cabo,Cabo Primero,Sargento,Brigada,Subteniente,Suboficial Mayor,Alférez,Capitán,\
Comandante,Teniente Coronel,Coronel,General de Brigada,General de División,Almirante,Almirante General,Capitán General");
    sscanf(todosLosNombres, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]",
           datos[0].nombre, datos[1].nombre, datos[2].nombre, datos[3].nombre, datos[4].nombre, datos[5].nombre, datos[6].nombre,
           datos[7].nombre, datos[8].nombre, datos[9].nombre, datos[10].nombre, datos[11].nombre, datos[12].nombre, datos[13].nombre,
           datos[14].nombre, datos[15].nombre, datos[16].nombre);

    abrirDesbloq = fopen("desbloqueables.csv", "w");
    if (abrirDesbloq == NULL)
    {
        printf("Error al abrir el fichero.\n");
        return -1;
    }
    for (i = 0; i < NUMERO_DESBLOQ; i++)
        fprintf(abrirDesbloq, "%c,%s,%i,%i,%i,%i,%i,%i,%i,%i,%i\n", datos[i].block, datos[i].nombre,
                datos[i].stats.precision, datos[i].stats.ataque, datos[i].stats.defensa, datos[i].stats.velocidad, datos[i].stats.vida,
                datos[i].objetos[0], datos[i].objetos[1], datos[i].objetos[2], datos[i].objetos[3]);
    cerrar = fclose(abrirDesbloq);
    if (cerrar == EOF)
    {
        printf("Error al cerrar el fichero.\n");
        return -1;
    }
    return 0;
}

puntuacion guardarPuntuaciones(puntuacion *puntos)
{
    int cerrar;
    FILE *pf;
    pf = fopen("puntuacionTotal.csv", "a");
    if (pf == NULL)
    {
        printf("Error al abrir el archivo 'puntuacionTotal.csv'");
        enter();
    }

    fprintf(pf, "%s,%i,%i,%i,%i,%i\n", puntos->nombre, puntos->puntuacionTot, puntos->barcosHundidos, puntos->totalDamageOcasionado, puntos->totalDamageRecibido,
            puntos->victorias);

    cerrar = fclose(pf);
    if (cerrar == EOF)
    {
        printf("Error al cerrar el archivo 'puntuacionTotal.csv'");
        enter();
    }
}

void verPuntuacion(void)
{
    int cerrar;
    FILE *pf;
    pf = fopen("puntuacionTotal.csv", "r");
    if (pf == NULL)
    {
        printf("Error al abrir el archivo 'puntuacionTotal.csv'");
        enter();
    }
    ///codigo
    cerrar = fclose(pf);
    if (cerrar == EOF)
    {
        printf("Error al cerrar el archivo 'puntuacionTotal.csv'");
        enter();
    }
}

login sesion(void)
{
    login info;
    int log, flag = 1, cerrar, buffer[5], i = 0;
    char userBuffer[20], stringBuffer[5000], allUsers[2000][20], *tokens;
    stringBuffer[0] = '\0';
    FILE *pf;
    while (flag != -1)
    {
        pf = fopen("puntuacionTotal.csv", "r");
        if (pf == NULL)
        {
            cerrar = fclose(pf);
            pf = fopen("puntuacionTotal.csv", "w");
            fprintf(pf, "%s,%i,%i,%i,%i,%i\n", "NULL", 0, 0, 0, 0, 0);
            cerrar = fclose(pf);
            if (cerrar == EOF)
            {
                printf("Error al cerrar el archivo puntuacionTotal.csv");
            }
        }
        else
        {
            while (fscanf(pf, " %[^,],%i,%i,%i,%i,%i\n", userBuffer, &buffer[0], &buffer[1], &buffer[2], &buffer[3], &buffer[4]) != EOF)
            {
                strcat(userBuffer, ",");
                strcat(stringBuffer, userBuffer);
            }
        }
        printf("\nstringBuffer: %s\n", stringBuffer);
        tokens = strtok(stringBuffer, ",");
        i = 0;
        while (tokens != NULL)
        {
            strcpy(allUsers[i], tokens);
            tokens = strtok(NULL, ",");
            printf("\nallUsers[%i]: %s\n", i, allUsers[i]);
            i++;
        }

        cerrar = fclose(pf);
        if (cerrar == EOF)
        {
            printf("Error al cerrar el fichero.");
            flag = -1;
        }
        flag = -1;
    }

    printf("Selecciona una opción:\n\n(1)Iniciar sesión.\n(2)Registrarse.\n");
    scanf(" %i", &log);
    switch (log)
    {
    case 1:
        clearscr();
        printf("Introduce tu nombre de usuario.\n");//comprobar si está registrado
        scanf("%s", info.user);
        printf("Introduce tu contraseña.\n");
        scanf("%s", info.pass);
        break;
    case 2:
        clearscr();
        while (flag != -1)
        {
            printf("Introduce un nombre de usuario.\n");//comprobar si ya está registrado
            scanf("%s", info.user);
            printf("Introduce una contraseña.\n");
            scanf("%s", info.pass);
            printf("Introduce de nuevo la contraseña.\n");
            scanf("%s", info.checkpass);
            if (strcmp(info.checkpass, info.pass) != 0)
            {
                printf("Las contraseñas no coinciden. Vuelve a intentarlo.\n");
            }
            else
            {
                clearscr();
                printf("¡Bienvenido, %s!\n", info.user);
                flag = -1;
                return info;
            }
        }
    }
}
