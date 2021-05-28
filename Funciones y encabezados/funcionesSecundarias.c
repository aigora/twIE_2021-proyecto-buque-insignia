#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesSecundarias.h"
#include "Matriz.h"
#include "estructuras.h"
#define LONG_PUNTUACION_CSV 6
#define LONG_BUFFER 100
#define MAXPUNTOS 50000

int inicioPrograma(void)
{
    int x = 0;
    clearscr();
    printf("Bienvenido/a a la p%cgina de inicio de Proyecto Buque Insignia.\n\n", 160);
    printf("%cQu%c quieres hacer? Selecciona entre:\n(0) Salir + cr%cditos\n(1) Jugar\n(2) Puntuaci%cn\n", 168, 130, 130, 162);
    //printf("(3) Modo Batalla (Debug)\n");
    scanf(" %i", &x);
    return x;
}

void error(void)
{
    printf("Caracter v%clido. Vuelve a intentarlo.\n", 160);
}

int jugar(puntuacion *puntos)
{
    puntos->totalPartidas++;
    int radioSonar = 0;
    char x[8];
    printf("¡Vamos a jugar! \n");
    printf("Elige el nivel de dificultad:\nEscribe 'facil', 'medio' o 'dificil'.\n");
    scanf(" %s", x);
    switch (x[0]) {
    case 'f':
        radioSonar = 3;
        clearscr();
        printf("Cargando. Espera...\n");
        Matriz(radioSonar, puntos);
        break;
    case 'm':
        radioSonar = 2;
        clearscr();
        printf("Cargando. Espera...\n");
        Matriz(radioSonar, puntos);
        break;
    case 'd':
        radioSonar = 0;
        clearscr();
        printf("Cargando. Espera...\n");
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
    int cerrar, leerPuntuacion[LONG_PUNTUACION_CSV], solucion = 0, i = 0, lineasTotales = 0, lineas = 0, confirm = 0;
    char nombre[4], buff[LONG_BUFFER], scanResult, data[LONG_BUFFER];
    abrirPuntuacion = fopen("puntuacionTotal.csv", "r");
    if (comprobarAperturaFichero(abrirPuntuacion) == -1)
    {
        abrirPuntuacion = fopen("puntuacionTotal.csv", "w");
        if (comprobarAperturaFichero(abrirPuntuacion) == -1)
            return -1;
        cerrar = fclose(abrirPuntuacion);
        if (comprobarCierreFichero(cerrar) == -1)
            return -1;
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

    sscanf(data, "%[^,],%i,%i,%i,%i,%i,%i", nombre, &leerPuntuacion[0], &leerPuntuacion[1], &leerPuntuacion[2], &leerPuntuacion[3],
                       &leerPuntuacion[4], &leerPuntuacion[5]);

    cerrar = fclose(abrirPuntuacion);
    if (comprobarCierreFichero(cerrar) == -1)
        return -1;
//    if (cerrar == 0)
//        printf("Fichero cerrado correctamente.\n");
    /// Fin de lectura del fichero

    switch (dato)
    {
    case 'n'://total partidas
        solucion = leerPuntuacion[0];
        break;
    case 'p'://puntuacion total
        solucion = leerPuntuacion[1];
        break;
    case 'd'://total daño recibido
        solucion = leerPuntuacion[4];
        break;
    case 'o'://total daño ocasionado
        solucion = leerPuntuacion[3];
        break;
    case 'h'://total barcos hundidos
        solucion = leerPuntuacion[2];
        break;
    case 'v'://victorias
        solucion = leerPuntuacion[5];
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
        printf("Pulsa ENTER para continuar...");
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
    printf("\n\n\n\n\n\n\n\n");
    printf("\033[2J");
//    for (int i = 0; i < 200; i++)
//        printf("\n");
}

int generarDesbloqueables(login registro)
{
    FILE *abrirDesbloq;
    int i = 0, j = 0, k = 0, calcsEcDif[17], cerrar, c = calculoConstanteEcDif(MAXPUNTOS);
    desbloqueables datos[17];
    char todosLosNombres[2000];

    for (i = 0; i < 17; i++)
    {
        calcsEcDif[i] = calculoEcDif(i, c);
        datos[i].puntosNecesarios = calcsEcDif[i];
    }

    int todasLasEstadisticasYObjetos[17][10] =
    {
        { 90, 60, 55, 60, 60,0,1,0,1,calcsEcDif[0]},
        { 90, 65, 60, 60, 70,1,0,1,0,calcsEcDif[1]},
        { 90, 70, 65, 50, 80,1,2,1,1,calcsEcDif[2]},
        { 90, 73, 70, 55, 90,2,2,2,1,calcsEcDif[3]},
        { 90, 75, 70, 60,100,3,3,3,2,calcsEcDif[4]},
        { 95, 80, 70, 65,100,2,3,3,2,calcsEcDif[5]},
        { 95, 80, 75, 65,100,2,2,3,4,calcsEcDif[6]},
        { 95, 85, 75, 70,100,4,2,2,3,calcsEcDif[7]},
        { 95, 85, 80, 70,100,3,4,3,3,calcsEcDif[8]},
        { 95, 90, 80, 80,100,4,3,4,3,calcsEcDif[9]},
        { 95, 90, 80, 90,100,4,4,3,4,calcsEcDif[10]},
        { 95, 90, 85, 75,100,4,4,4,4,calcsEcDif[11]},
        { 95, 95, 85, 85,100,4,4,4,4,calcsEcDif[12]},
        { 95, 95, 90, 90,100,4,4,4,4,calcsEcDif[13]},
        {100, 95, 90, 85,100,4,4,4,4,calcsEcDif[14]},
        {100, 95,100, 95,100,4,4,4,4,calcsEcDif[15]},
        {100,100,100,100,100,4,4,4,4,calcsEcDif[16]},
    };
    for (i = 0; i < 17; i++)
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
    if (comprobarAperturaFichero(abrirDesbloq) == -1)
        return -1;
    for (i = 0; i < 17; i++)
        fprintf(abrirDesbloq, "%s,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i\n", datos[i].nombre,
                datos[i].stats.precision, datos[i].stats.ataque, datos[i].stats.defensa, datos[i].stats.velocidad, datos[i].stats.vida,
                datos[i].objetos[0], datos[i].objetos[1], datos[i].objetos[2], datos[i].objetos[3], datos[i].puntosNecesarios);
    cerrar = fclose(abrirDesbloq);
    if (comprobarCierreFichero(cerrar) == -1)
        return -1;
    return 0;
}

int guardarPuntuaciones(puntuacion *puntos)
{
    int cerrar;
    FILE *pf;
    pf = fopen("puntuacionTotal.csv", "a");
    if (comprobarAperturaFichero(pf) == -1)
        return -1;

    fprintf(pf, "%s,%i,%i,%i,%i,%i,%i\n", puntos->nombre, puntos->totalPartidas, puntos->puntuacionTot, puntos->barcosHundidos, puntos->totalDamageOcasionado,
            puntos->totalDamageRecibido, puntos->victorias);

    printf("Puntos: %s,%i,%i,%i,%i,%i,%i\n", puntos->nombre, puntos->totalPartidas, puntos->puntuacionTot, puntos->barcosHundidos, puntos->totalDamageOcasionado,
            puntos->totalDamageRecibido, puntos->victorias);
    enter();

    cerrar = fclose(pf);
    if (comprobarCierreFichero(cerrar) == -1)
        return -1;
    return 0;
}

int verPuntuacion(void)
{
    int cerrar, datos[6], i, confirm, exit = 0, escape;
    char users[2000][20], userbuffer[2000], userinput[20], stringBuffer[6000], allUsers[2000][50], allPasses[2000][50];
    FILE *pf, *pflog;
    escape = 0;
    for (i = 0; i < 2000; i++)
        strcpy(allUsers[i], " ");
    while (escape != 1)
    {
        pf = fopen("puntuacionTotal.csv", "r");
        pflog = fopen("registro.csv", "r");
        if (comprobarAperturaFichero(pf) == -1)
            return -1;
        if (comprobarAperturaFichero(pflog) == -1)
            return -1;
        i = 0;
        while (fgets(stringBuffer, 6000, pflog) != NULL && i < 2000)
        {
            sscanf(stringBuffer, "%[^,],%[^\n]", allUsers[i], allPasses[i]);
            i++;
        }
        cerrar = fclose(pflog);
        if (comprobarCierreFichero(cerrar) == -1)
            return 0;
        clearscr();
        printf("Introduce el nombre del usuario del que deseas ver las puntuaciones.\nUsuarios registrados:\n");

        for (i = 0; i < 2000; i++)
        {
            if (strcmp(allUsers[i], " ") != 0)
                printf("- %s\n", allUsers[i]);
        }

        scanf(" %s", userinput);
        i = 0;
        confirm = 1;
        while (fgets(userbuffer, 2000, pf) != NULL)
        {
            sscanf(userbuffer, "%[^,],%i,%i,%i,%i,%i,%i\n", users[i], &datos[0], &datos[1], &datos[2], &datos[3], &datos[4], &datos[5]);
            confirm = strcmp(users[i], userinput);
            if (confirm == 0 && exit == 0)
            {
                clearscr();
                printf("Leyenda:\nPJ -> Partidas jugadas\nPG -> Partidas ganadas\nTH -> Total de barcos hundidos\nDO -> Da%co ocasionado en el Modo de Batalla\n\
DR -> Da%co recibido en el Modo de Batalla\nPT -> Puntuaci%cn total\n\nFicha de puntuaciones para el usuario %s:\nPJ\tPG\tTH\tDO\tDR\tPT\n", 164, 164, 162, userinput);
                exit++;
            }
            if (confirm == 0)
            {
                printf("%i\t%i\t%i\t%i\t%i\t%i\n", datos[0], datos[5], datos[2], datos[3], datos[4], datos[1]);
            }
            i++;
        }
        if (exit == 0)
        {
            printf("El usuario indicado no está registrado o no ha jugado ninguna partida.\n");
            clearscr();
            enter();
        }
        else
        {
            cerrar = fclose(pf);
            if (comprobarCierreFichero(cerrar) == -1)
                return -1;
            enter();
            clearscr();
            escape = 1;
        }
    }
    return 0;
}

login sesion(void)
{
    login info;
    int log, flag = 1, cerrar, i = 0, j = 0, check = 2, exit = 0, checkcount;
    char stringBuffer[6000], allUsers[2000][20], allPasses[2000][20];
    stringBuffer[0] = '\0';

    for (i = 0; i < 2000; i++)
        strcpy(allUsers[i], " ");

    FILE *pf, *pflog, *abrirPuntuacion;

    while (flag != -1)
    {
        flag = 0;
        while (flag != -2)
        {
            pflog = fopen("registro.csv", "r");
            if (pflog == NULL)
            {
                cerrar = fclose(pflog);
                pflog = fopen("registro.csv", "w");
                cerrar = fclose(pflog);
                if (comprobarCierreFichero(cerrar) == -1)
                    return info;
            }
            else
            {
                i = 0;
                while (fgets(stringBuffer, 6000, pflog) != NULL && i < 2000)
                {
                    sscanf(stringBuffer, "%[^,],%[^\n]", allUsers[i], allPasses[i]);
                    i++;
                }
                j = i;
                cerrar = fclose(pflog);
                if (comprobarCierreFichero(cerrar) == -1)
                    return info;
                flag = -2;
            }
        }
        flag = -1;
    }

    while (exit != 1)
    {
        clearscr();
        printf("Selecciona una opci%cn:\n\n(1)Iniciar sesi%cn.\n(2)Registrarse.\n\n", 162, 162);
        printf("Los usuarios registrados son los siguientes:\n\n");
        i = 0;
        while (strcmp(allUsers[i], " ") != 0 && i < 2000)
        {
            printf("- %s\n", allUsers[i]);
            i++;
        }
        scanf(" %i", &log);
        switch (log)
        {
        case 1:
            clearscr();
            printf("Introduce tu nombre de usuario.\n");
            scanf("%s", info.user);
            checkcount = 0;
            for (i = 0; i < j; i++)
            {
                check = strcmp(allUsers[i], info.user);
                if (check == 0)
                {
                    strcpy(info.checkpass, allPasses[i]);
                    checkcount++;
                }
            }
            if (checkcount == 0)
            {
                printf("El usuario indicado no está registrado.\n");
                enter();
            }
            else
            {
                printf("Introduce tu contrase%ca.\n", 164);
                i = 0;
                scanf(" %s", info.pass);
                printf("\n");

                if (strcmp(info.pass, info.checkpass) == 0)
                {
                    printf("%cBienvenido, %s!", 173, info.user);
                    return info;
                }
                else
                {
                    printf("Contrase%ca incorrecta. Vuelve a intentarlo.\n", 164);
                    enter();
                }
            }
            break;
        case 2:
            clearscr();
            flag = 0;
            while (flag != -1)
            {
                printf("Introduce un nombre de usuario.\n");
                scanf(" %s", info.user);
                checkcount = 0;
                for (i = 0; i < 2000; i++)
                {
                    check = strcmp(allUsers[i], info.user);
                    if (check == 0)
                        checkcount++;
                }
                if (checkcount != 0)
                {
                    printf("El usuario ya está registrado.\n");
                    enter();
                }
                else
                {
                    printf("Introduce una contrase%ca.\n", 164);
                    scanf(" %s", info.pass);
                    printf("Introduce de nuevo la contrase%ca.\n", 164);
                    scanf(" %s", info.checkpass);
                    if (strcmp(info.checkpass, info.pass) != 0)
                    {
                        printf("Las contrase%cas no coinciden. Vuelve a intentarlo.\n", 164);
                        enter();
                    }
                    else
                    {
                        clearscr();
                        pf = fopen("puntuacionTotal.csv", "r");
                        if (pf == NULL)
                        {
                            info.checkpass[0] = 0;
                            //cerrar = fclose(pf);
                            pf = fopen("puntuacionTotal.csv", "w");
                            cerrar = fclose(pf);
                            if (comprobarCierreFichero(cerrar) == -1)
                                return info;
                        }

                        pflog = fopen("registro.csv", "a");
                        abrirPuntuacion = fopen("puntuacionTotal.csv", "a");
                        if (comprobarAperturaFichero(abrirPuntuacion) == -1)
                            return info;
                        if (comprobarAperturaFichero(pflog) == -1)
                            return info;

                        fprintf(pflog, "%s,%s\n", info.user, info.pass);
                        fprintf(abrirPuntuacion, "%s,%i,%i,%i,%i,%i,%i\n", info.user, 0, 0, 0, 0, 0, 0);//crea una línea para las puntuaciones del nuevo jugador
                        cerrar = fclose(pflog);
                        if (comprobarCierreFichero(cerrar) == -1)
                            return info;
                        cerrar = fclose(abrirPuntuacion);
                        if (comprobarCierreFichero(cerrar) == -1)
                            return info;
                        printf("Usuario guardado.\n¡Bienvenido/a, %s!\n\n", info.user);
                        return info;
                    }
                }
            }
        }
    }
    return info;
}

int calculoEcDif(int nivel, int k)
{//recordar que la ecuación diferencial es y' = 2y -> integral(y' / 2y)dx = integral dx -> ln(y) / 2 = x + C -> y = x^2 + 2Cx + K (ignorada)
    int x;
    x = nivel*nivel + 2*k*nivel;
    return x;
}

int calculoConstanteEcDif(int maxPuntos)
{   //recordar que la ecuación diferencial es y' = 2y -> integral(y' / 2y)dx = integral dx -> ln(y) / 2 = x + C
    //Luego, despejar C según el valor inicial maxPuntos, y el máximo de la variable x, x = 16 distintos rangos disponibles
    int x = (maxPuntos - 16*16) / (16*2);
    return x;
}

int comprobarAperturaFichero(FILE *puntero)
{
    if (puntero == NULL)
    {
        printf("Error al abrir el fichero.");
        enter();
        return -1;
    }
    else
        return 0;
}

int comprobarCierreFichero(int cerrar)
{
    if (cerrar == EOF)
    {
        printf("Error al cerrar el fichero.");
        enter();
        return -1;
    }
    else
        return 0;
}

int sumando(void)
{
    int s, i = 1;
    if (random1(i) > 0.5)
        s= random1(i + 1) * 10;
    else
        s = -random1(i + 1) * 10;
    //printf("Sumando: %i\n", s);
    return s;
}

int leerFicheros(login registro, puntuacion *puntos)
{
    char buff[20000], usuarios[2000][200], contrasenas[2000][200], nombresPuntuacion[2000][200], buf;
    int  i = 0, k = 0, sum[4], flag = 0, lineas = 0;
    puntuacion puntosvec[2000];
    desbloqueables bufer[2000];

    int cerrar;
    FILE *pflog, *abrirDesbloq;

    abrirDesbloq = fopen("desbloqueables.csv", "r");
    if (abrirDesbloq == NULL)
    {
        flag = 1;
        fclose(abrirDesbloq);
    }
    else
        fclose(abrirDesbloq);
    if (flag == 1)
    {
        flag = generarDesbloqueables(registro);
    }

    pflog = fopen("registro.csv", "r");
    if (comprobarAperturaFichero(pflog) == -1)
        return 0;

    while (fgets(buff, 2000, pflog) != NULL)
    {
        sscanf(buff, "%[^,],%[^\n]\n", usuarios[i], contrasenas[i]);
        if (strcmp(usuarios[i], registro.user) == 0)
            strcpy(puntos->nombre, usuarios[i]);
        i++;
    }
    cerrar = fclose(pflog);
    if (comprobarCierreFichero(cerrar) == -1)
        return 0;

    FILE *pf;
    i = 0;
//    pf = fopen("puntuacionTotal.csv", "r");
//    while (fscanf(pf, "%c", &buf) != EOF)
//    {
//        if (buf == '\n')
//            lineas++;
//        i++;
//    }
//    //printf("\nLineas: %i\n", lineas);
//    cerrar = fclose(pf);
    if (comprobarCierreFichero(cerrar) == -1)
        return 0;

    pf = fopen("puntuacionTotal.csv", "r");
    if (comprobarAperturaFichero(pf) == -1)
        return 0;

    i = 0;
    while (fgets(buff, 2000, pf) != NULL)
    {
        sscanf(buff, "%[^,],%i,%i,%i,%i,%i,%i\n", nombresPuntuacion[i], &puntosvec[i].totalPartidas, &puntosvec[i].puntuacionTot, &puntosvec[i].totalDamageRecibido,
               &puntosvec[i].totalDamageOcasionado, &puntosvec[i].barcosHundidos, &puntosvec[i].victorias);
        if (strcmp(puntos->nombre, nombresPuntuacion[i]) == 0 && i == lineas + 1)
        {
            puntos->totalPartidas = puntosvec[i].totalPartidas;
            puntos->puntuacionTot = puntosvec[i].puntuacionTot;
            puntos->totalDamageRecibido = puntosvec[i].totalDamageRecibido;
            puntos->totalDamageOcasionado = puntosvec[i].totalDamageOcasionado;
            puntos->barcosHundidos = puntosvec[i].barcosHundidos;
            puntos->victorias = puntosvec[i].victorias;
        }
        i++;
    }
//    printf("\nPuntero -> %s,%i,%i,%i,%i,%i,%i\n", puntos->nombre, puntos->totalPartidas, puntos->puntuacionTot, puntos->totalDamageRecibido, puntos->totalDamageOcasionado,
//           puntos->barcosHundidos, puntos->victorias);
    cerrar = fclose(pf);
    if (comprobarCierreFichero(cerrar) == -1)
        return -1;

    ///
    abrirDesbloq = fopen("desbloqueables.csv", "r");
    if (comprobarAperturaFichero(abrirDesbloq) == -1)
        return -1;
    else
    {
        FILE *abrirEstadisticas;
        abrirEstadisticas = fopen("estadisticas.csv", "w");
        if (comprobarAperturaFichero(abrirEstadisticas) == -1)
            return -1;
        i = 0;

        strcpy(buff, " ");
        printf("\nCargando. Espera...");
        while (fgets(buff, 20000, abrirDesbloq) != NULL)//solo copiar datos en estadisticas desde desbloqueables
        {
            for (k = 0; k < 4; k++)
                sum[k] = sumando();
            sscanf(buff, "%[^,],%i,%i,%i,%i,%i,%i,%i,%i,%i,%i",
                   bufer[i].nombre, &bufer[i].stats.precision, &bufer[i].stats.ataque, &bufer[i].stats.defensa, &bufer[i].stats.velocidad, &bufer[i].stats.vida,
                   &bufer[i].objetos[0], &bufer[i].objetos[1], &bufer[i].objetos[2], &bufer[i].objetos[3], &bufer[i].puntosNecesarios);
//            printf("\n%s,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i\n",
//                   bufer[i].nombre, bufer[i].stats.precision, bufer[i].stats.ataque, bufer[i].stats.defensa, bufer[i].stats.velocidad, bufer[i].stats.vida,
//                   bufer[i].objetos[0], bufer[i].objetos[1], bufer[i].objetos[2], bufer[i].objetos[3], bufer[i].puntosNecesarios);

            //
            if (bufer[i].puntosNecesarios <= puntos->puntuacionTot)
                {
                    fprintf(abrirEstadisticas, "%i,%i,%i,%i,%i,%i,%i,%i,%i\n%i,%i,%i,%i,%i,%i,%i,%i,%i\n",
                            bufer[i].stats.precision, bufer[i].stats.ataque, bufer[i].stats.defensa, bufer[i].stats.velocidad, bufer[i].stats.vida,
                            bufer[i].objetos[0], bufer[i].objetos[1], bufer[i].objetos[2], bufer[i].objetos[3],
                            bufer[i].stats.precision + sum[0], bufer[i].stats.ataque + sum[1], bufer[i].stats.defensa + sum[2],
                            bufer[i].stats.velocidad + sum[3], bufer[i].stats.vida,
                            bufer[i].objetos[0], bufer[i].objetos[1], bufer[i].objetos[2], bufer[i].objetos[3]);

                    strcpy(puntos->rango, bufer[i].nombre);
//                    printf("\nBufer escritura en estadisticas.csv:\n%i,%i,%i,%i,%i,%i,%i,%i,%i\n%i,%i,%i,%i,%i,%i,%i,%i,%i\n",
//                            bufer[i].stats.precision, bufer[i].stats.ataque, bufer[i].stats.defensa, bufer[i].stats.velocidad, bufer[i].stats.vida,
//                            bufer[i].objetos[0], bufer[i].objetos[1], bufer[i].objetos[2], bufer[i].objetos[3],
//                            bufer[i].stats.precision + sum[0], bufer[i].stats.ataque + sum[1], bufer[i].stats.defensa + sum[2],
//                            bufer[i].stats.velocidad + sum[3], bufer[i].stats.vida,
//                            bufer[i].objetos[0], bufer[i].objetos[1], bufer[i].objetos[2], bufer[i].objetos[3]);
                }
            //
        }

        cerrar = fclose(abrirEstadisticas);
        if (comprobarCierreFichero(cerrar) == -1)
            return 0;
        ///
    return 0;
    }
}
