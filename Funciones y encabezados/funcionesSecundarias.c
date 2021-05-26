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

    sscanf(data, "%[^,],%i,%i,%i,%i,%i,%i", nombre, &leerPuntuacion[0], &leerPuntuacion[1], &leerPuntuacion[2], &leerPuntuacion[3],
                       &leerPuntuacion[4], &leerPuntuacion[5]);

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
    int i = 0, j = 0, k = 0, cerrar, c = calculoConstanteEcDif(MAXPUNTOS);
    desbloqueables datos[17];
    char todosLosNombres[2000];
    int todasLasEstadisticasYObjetos[17][10] =
    {
        { 90, 60, 55, 60, 60,0,1,0,1,calculoEcDif(0, c)},
        { 90, 65, 60, 60, 70,1,0,1,0,calculoEcDif(1, c)},
        { 90, 70, 65, 50, 80,1,2,1,1,calculoEcDif(2, c)},
        { 90, 73, 70, 55, 90,2,2,2,1,calculoEcDif(3, c)},
        { 90, 75, 70, 60,100,3,3,3,2,calculoEcDif(4, c)},
        { 95, 80, 70, 65,100,2,3,3,2,calculoEcDif(5, c)},
        { 95, 80, 75, 65,100,2,2,3,4,calculoEcDif(6, c)},
        { 95, 85, 75, 70,100,4,2,2,3,calculoEcDif(7, c)},
        { 95, 85, 80, 70,100,3,4,3,3,calculoEcDif(8, c)},
        { 95, 90, 80, 80,100,4,3,4,3,calculoEcDif(9, c)},
        { 95, 90, 80, 90,100,4,4,3,4,calculoEcDif(10, c)},
        { 95, 90, 85, 75,100,4,4,4,4,calculoEcDif(11, c)},
        { 95, 95, 85, 85,100,4,4,4,4,calculoEcDif(12, c)},
        { 95, 95, 90, 90,100,4,4,4,4,calculoEcDif(13, c)},
        {100, 95, 90, 85,100,4,4,4,4,calculoEcDif(14, c)},
        {100, 95,100, 95,100,4,4,4,4,calculoEcDif(15, c)},
        {100,100,100,100,100,4,4,4,4,calculoEcDif(16, c)},
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
    if (abrirDesbloq == NULL)
    {
        printf("Error al abrir el fichero.\n");
        return -1;
    }
    for (i = 0; i < 17; i++)
        fprintf(abrirDesbloq, "%s,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i\n", datos[i].nombre,
                datos[i].stats.precision, datos[i].stats.ataque, datos[i].stats.defensa, datos[i].stats.velocidad, datos[i].stats.vida,
                datos[i].objetos[0], datos[i].objetos[1], datos[i].objetos[2], datos[i].objetos[3], datos[i].puntosNecesarios);
    cerrar = fclose(abrirDesbloq);
    if (cerrar == EOF)
    {
        printf("Error al cerrar el fichero.\n");
        return -1;
    }
    return 0;
}

void guardarPuntuaciones(puntuacion *puntos)
{
    int cerrar;
    FILE *pf;
    pf = fopen("puntuacionTotal.csv", "a");
    if (pf == NULL)
    {
        printf("Error al abrir el archivo 'puntuacionTotal.csv'");
        enter();
    }

    fprintf(pf, "%s,%i,%i,%i,%i,%i,%i\n", puntos->nombre, puntos->totalPartidas, puntos->puntuacionTot, puntos->barcosHundidos, puntos->totalDamageOcasionado, puntos->totalDamageRecibido,
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
    int cerrar, datos[6], i, confirm, exit = 0, escape;
    char users[2000][20], userbuffer[2000], userinput[20];
    FILE *pf;
    escape = 0;
    while (escape != 1)
    {
        pf = fopen("puntuacionTotal.csv", "r");
        if (pf == NULL)
        {
            printf("Error al abrir el archivo 'puntuacionTotal.csv'");
            enter();
        }
        clearscr();
        printf("Introduce el nombre del usuario del que deseas ver las puntuaciones.\n");
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
                printf("Leyenda:\nPJ -> Partidas jugadas\nPG -> Partidas ganadas\nTH -> Total de barcos hundidos\nDO -> Daño ocasionado en el Modo de Batalla\n\
DR -> Daño recibido en el Modo de Batalla\nPT -> Puntuación total\n\nFicha de puntuaciones para el usuario %s:\nPJ\tPG\tTH\tDO\tDR\tPT\n", userinput);
                exit++;
            }
            if (confirm == 0)
                printf("%i\t%i\t%i\t%i\t%i\t%i\n", datos[0], datos[5], datos[2], datos[3], datos[4], datos[1]);
            i++;
        }
        if (exit == 0)
        {
            printf("El usuario indicado no está registrado o no ha jugado ninguna partida.\n");
            enter();
        }
        else
        {
            cerrar = fclose(pf);
            if (cerrar == EOF)
            {
                printf("Error al cerrar el archivo 'puntuacionTotal.csv'");
                enter();
            }
            enter();
            escape = 1;
        }
    }
}

login sesion(void)
{
    login info;
    int log, flag = 1, cerrar, buffer[5], i = 0, j = 0, check = 2, exit = 0, checkcount;
    char userBuffer[20], stringBuffer[6000], allUsers[2000][20], allPasses[2000][20], *tokens, provpass[20];
    stringBuffer[0] = '\0';
    FILE *pf, *pflog;
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

        flag = 0;
        while (flag != -2)
        {
            pflog = fopen("registro.csv", "r");
            if (pflog == NULL)
            {
                cerrar = fclose(pflog);
                pflog = fopen("registro.csv", "w");
                cerrar = fclose(pflog);
                if (cerrar == EOF)
                {
                    printf("Error al cerrar el fichero registro.csv.");
                    return info;
                }
            }
            else
            {
                i = 0;
                while (fgets(stringBuffer, 6000, pflog) != NULL && i < 2000)
                {
                    sscanf(stringBuffer, "%[^,],%[^\n]", allUsers[i], allPasses[i]);
                    printf("%s,%s\n", allUsers[i], allPasses[i]);
                    i++;
                }
                j = i;
                cerrar = fclose(pflog);
                if (cerrar == EOF)
                {
                    printf("Error al cerrar el fichero registro.csv.");
                    return info;
                }
                flag = -2;
            }
        }
        cerrar = fclose(pf);
        if (cerrar == EOF)
        {
            printf("Error al cerrar el fichero.");
            return info;
        }
        flag = -1;
    }

    while (exit != 1)
    {
        clearscr();
        printf("Selecciona una opción:\n\n(1)Iniciar sesión.\n(2)Registrarse.\n");
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
                printf("Introduce tu contraseña.\n");
                i = 0;
                do
                {
                    provpass[i] = getch();
                    if (provpass[i] != '\r')
                        printf("*");
                    i++;
                }
                while(provpass[i - 1] != '\r');
                for (i = 0; i < strlen(provpass) - 1; i++)
                    info.pass[i] = provpass[i];
                printf("\n");

                if (strcmp(info.pass, info.checkpass) == 0)
                {
                    printf("¡Bienvenido, %s!", info.user);
                    enter();
                    return info;
                }
                else
                {
                    printf("Contraseña incorrecta. Vuelve a intentarlo.\n");
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
                scanf("%s", info.user);
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
                    printf("Introduce una contraseña.\n");
                    scanf("%s", info.pass);
                    printf("Introduce de nuevo la contraseña.\n");
                    scanf("%s", info.checkpass);
                    if (strcmp(info.checkpass, info.pass) != 0)
                    {
                        printf("Las contraseñas no coinciden. Vuelve a intentarlo.\n");
                        enter();
                    }
                    else
                    {
                        clearscr();
                        pflog = fopen("registro.csv", "a");
                        if (pflog == NULL)
                        {
                            printf("Error al abrir el fichero.");
                            enter();
                            return info;
                        }
                        fprintf(pflog, "%s,%s\n", info.user, info.pass);
                        cerrar = fclose(pflog);
                        if (cerrar == EOF)
                        {
                            printf("Error al cerrar el fichero.");
                            enter();
                            return info;
                        }
                        printf("Usuario guardado.\n¡Bienvenido, %s!\n", info.user);
                        enter();
                        return info;
                    }
                }
            }
        }
    }
    return info;
}

float calculoEcDif(int nivel, int k)
{//recordar que la ecuación diferencial es y' = 2y -> integral(y' / 2y)dx = integral dx -> ln(y) / 2 = x + C -> y = x^2 + 2Cx + K (ignorada)
    k = calculoConstanteEcDif(MAXPUNTOS);
    return nivel*nivel + 2*k*nivel;
}

float calculoConstanteEcDif(int maxPuntos)
{   //recordar que la ecuación diferencial es y' = 2y -> integral(y' / 2y)dx = integral dx -> ln(y) / 2 = x + C
    //Luego, despejar C según el valor inicial maxPuntos, y el máximo de la variable x, x = 16 distintos rangos disponibles
    return (maxPuntos - 16*16) / (16*2);
}
