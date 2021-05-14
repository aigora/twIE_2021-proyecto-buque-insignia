#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Matriz.h"
#include "funcionesModoBatalla.h"
#include "estructuras.h"
#include "funcionesTexto.h"

int Matriz(int x)
{
    int mbarcos = 0;
    int sbarcos = 0;
    int contarCoordenadasUSER = 0, contarCoordenadasCPU = 0, victoria = 0, modoBatallaActivado = 0;
    int misBarcos[10][10] = {0};
    int cpuBarcos[10][10] = {0};
    int misbarcosrellenos [10][10] = {0};
    int susbarcosrellenos [10][10] = {0};

    rellenarTodosLosBarcos(misBarcos);
    //imprimirMatrizdeBarcos(misBarcos, 10, 10);

    rellenarTodosLosBarcos(cpuBarcos);
    //imprimirMatrizdeBarcos(cpuBarcos, 10, 10);


    while(mbarcos<21 && sbarcos<21)
    {
        printf("\n\nTU TURNO: la situacion actual es: \n");
        imprimirMatrizdeBarcos(misbarcosrellenos, 10, 10);

        scan:
            printf("Introduzca la columna de la casilla que desea atacar: (A-J):");
            char letra;
            scanf(" %c", &letra);
            int columna = traducirletra(letra);

            printf("Introduzca la fila de la casilla que desea atacar: (0-9):");
            int numero;
            scanf("%d", &numero);

            if (misbarcosrellenos[numero][columna]>0){
                printf("La casilla ya esta seleccionada. Elige otra\n");
                goto scan;
            }

        contarCoordenadasUSER = tucoordenada(columna, numero, misbarcosrellenos, cpuBarcos);
        if (contarCoordenadasUSER == 2 && modoBatallaActivado == 0)
        {
            contarCoordenadasUSER--;
            modoBatallaActivado = 1;
            victoria = modoBatalla();
            enter();
            enter();
        }
        mbarcos = mbarcos + contarCoordenadasUSER;
        printf("Casillas de barcos acertadas por ti: %d\n", mbarcos);

        printf("\n\nCPU TURNO.\n");
        int y = rand() %10;
        int x = rand() %10;
        while (susbarcosrellenos[x][y]>0){
            y = rand() %10;
            x = rand() %10;
        }

        contarCoordenadasCPU = sucoordenada(x, y, susbarcosrellenos, misBarcos);
        if (contarCoordenadasCPU == 2 && modoBatallaActivado == 0)
        {
            contarCoordenadasCPU--;
            modoBatallaActivado = 1;
            victoria = modoBatalla();
            enter();
            enter();
        }
        sbarcos = sbarcos + contarCoordenadasCPU;
        printf("Casillas de barcos acertadas por CPU: %d\n", sbarcos);
    }
    ganador(mbarcos,sbarcos);
    printf("Estos han sido tus resultados\n");
    imprimirMatrizdeBarcos(misbarcosrellenos, 10, 10);
    printf("Estos han sido sus resultados\n");
    imprimirMatrizdeBarcos(susbarcosrellenos, 10, 10);
    return 0;
}

void imprimirMatrizdeBarcos(int matrizBarcos[][10], int fila, int column) {
    printf("- A B C D E F G H I J\n");
    for (int x=0; x<fila; x++) {
        printf("%d ", x);
        for(int y=0; y<column; y++) {
            if (matrizBarcos[x][y] == 1){
                printf("# ");
            } else if (matrizBarcos[x][y] == 2){
                printf(". ");
            } else if (matrizBarcos[x][y] == 3){
                printf("@ ");
            } else {
                printf("? ");
            }
        }
        printf("\n");
    }
}


void rellenarBarco(int tam, int fila, int columna, int direccion, int esEspecial, int matrizBarcos[][10]) {
    int tipoBarco = 1;
    if (esEspecial == 1) {
        tipoBarco = 3;
    }

    //Rellenamos el barco
    for(int i=0; i<tam;i++){
        if (direccion == 0){
            matrizBarcos[fila][columna+i] = tipoBarco;
        } else {
            matrizBarcos[fila+i][columna] = tipoBarco;
        }
    }

    //Rellenamos las casillas adyacentes
    if (direccion == 0) {
        for(int i=-1; i<2; i++){
            for(int j=-1; j<tam+1; j++){
                int selecfila = fila + i;
                int seleccolumna = columna + j;

                if (selecfila <0 || selecfila > 9 || seleccolumna <0 || seleccolumna >9
                    || matrizBarcos[selecfila][seleccolumna] == 1 || matrizBarcos[selecfila][seleccolumna] == 3) {
                    continue;
                } else {
                    matrizBarcos[selecfila][seleccolumna] = 2;
                }
            }
        }
    } else {
        for(int i=-1; i<tam+1; i++){
            for(int j=-1; j<2; j++){
                int selecfila = fila + i;
                int seleccolumna = columna + j;

                if (selecfila <0 || selecfila > 9 || seleccolumna <0 || seleccolumna >9
                    || matrizBarcos[selecfila][seleccolumna] == 1 || matrizBarcos[selecfila][seleccolumna] == 3) {
                    continue;
                } else {
                    matrizBarcos[selecfila][seleccolumna] = 2;
                }
            }
        }
    }
}


void rellenarTodosLosBarcos(int matrizBarcos[][10]){

    //Introducir barco de 4
    while (1 == 1){

        int direccion = rand() %2;
        int fila = rand() % 9;
        int columna = rand() %9;
        int resultado = comprobarCabeBarco(4, fila, columna, direccion, matrizBarcos);
        if (resultado == 1) {
            rellenarBarco(4, fila, columna, direccion, 0, matrizBarcos);
            break;
        }
    }

    for (int i=0; i<3; i++) {
        while (1==1){
            int direccion = rand() %2;
            int fila = rand() % 9;
            int columna = rand() %9;
            int resultado = comprobarCabeBarco(3, fila, columna, direccion, matrizBarcos);
            if (resultado == 1) {
                rellenarBarco(3, fila, columna, direccion, 0, matrizBarcos);
                break;
            }
        }
    }

    for (int i=0; i<3; i++) {
        while (1==1){
            int direccion = rand() %2;
            int fila = rand() % 9;
            int columna = rand() %9;
            int resultado = comprobarCabeBarco(2, fila, columna, direccion, matrizBarcos);
            if (resultado == 1) {
                rellenarBarco(2, fila, columna, direccion, 0, matrizBarcos);
                break;
            }
        }
    }

    while (1==1){
        int direccion = rand() %2;
        int fila = rand() % 9;
        int columna = rand() %9;
        int resultado = comprobarCabeBarco(1, fila, columna, direccion, matrizBarcos);
        if (resultado == 1) {
            rellenarBarco(1, fila, columna, direccion, 0, matrizBarcos);
            break;
        }
    }

    while (1==1){
        int direccion = rand() %2;
        int fila = rand() % 9;
        int columna = rand() %9;
        int resultado = comprobarCabeBarco(1, fila, columna, direccion, matrizBarcos);
        if (resultado == 1) {
            rellenarBarco(1, fila, columna, direccion, 1, matrizBarcos);
            break;
        }
    }

    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++) {
            if (matrizBarcos[i][j] == 0) {
                matrizBarcos[i][j] = 2;
            }
        }
    }
}

int comprobarCabeBarco(int tam, int fila, int columna, int direccion, int matrizBarcos[][10]) {
    //Comprobar si parametros dentro de la matriz
    if (direccion == 0){
        if (columna + tam > 10){
            return 0;
        }
        if (fila > 9){
            return 0;
        }
    } else {
        if (fila + tam > 10){
            return 0;
        }
        if (columna > 9){
            return 0;
        }
    }

    //Miramos si cabe el barco
    for(int i=0; i<tam;i++){
        if (direccion == 0){
            if (matrizBarcos[fila][columna+i] == 1 || matrizBarcos[fila][columna+i] == 2) {
                return 0;
            }
        } else {
            if (matrizBarcos[fila+i][columna] == 1 || matrizBarcos[fila+i][columna] == 2) {
                return 0;
            }
        }
    }

    //Miramos las casillas adyacentes
    if (direccion == 0) {
        for(int i=-1; i<2; i++){
            for(int j=-1; j<tam+1; j++){
                int selecfila = fila + i;
                int seleccolumna = columna + j;

                if (selecfila <0 || selecfila > 9 || seleccolumna <0 || seleccolumna >9) {
                    //Estamos fuera de la matriz
                    continue;
                }
                if (matrizBarcos[selecfila][seleccolumna] == 1) {
                    return 0;
                }
            }
        }
    } else {
        for(int i=-1; i<tam+1; i++){
            for(int j=-1; j<2; j++){
                int selecfila = fila + i;
                int seleccolumna = columna + j;

                if (selecfila <0 || selecfila > 9 || seleccolumna <0 || seleccolumna >9) {
                    //Estamos fuera de la matriz
                    continue;
                }
                if (matrizBarcos[selecfila][seleccolumna] == 1) {
                    return 0;
                }
            }
        }
    }

    //All OK
    return 1;
}

int sucoordenada(int fi, int co, int SuMatriz[][10], int TuMatriz[][10])
{
    SuMatriz[fi][co] = TuMatriz[fi][co];
    if(SuMatriz[fi][co] == 1){
        printf("Te han dado a un barco, este es su resultado:\n");
        imprimirMatrizdeBarcos(SuMatriz, 10, 10);
        return 1;
    }
    else if (SuMatriz[fi][co] == 2){
        printf("No te han dado ningun barco, este es su resultado:\n");
        imprimirMatrizdeBarcos(SuMatriz, 10, 10);
        return 0;
    }
    else if(SuMatriz[fi][co] == 3) {
        printf("Te han dado al barco especial, este es su resultado:\n");
        imprimirMatrizdeBarcos(SuMatriz, 10, 10);
        //Entramos aqui en el modo batalla especial entre barcos.
        return 2;
    }
}

int tucoordenada(int columna, int fila, int tuMatriz[][10], int suMatriz[][10])
{

    tuMatriz[fila][columna] = suMatriz[fila][columna];

    if(tuMatriz[fila][columna] == 1){
        printf("Has dado a un barco\n");
        return 1;
    }
    else if (tuMatriz[fila][columna] == 2){
        printf("No has dado a ningun barco\n");
        return 0;
    }
    else if(tuMatriz[fila][columna] == 3) {
        printf("Has dado al barco especial\n");
        //Entramos aqui en el modo batalla especial entre barcos.
        return 2;
    }
}

int traducirletra(char letra){
    switch(letra)
    {
        case 'A':
            return 0;
            break;
        case 'B':
            return 1;
            break;
        case 'C':
            return 2;
            break;
        case 'D':
            return 3;
            break;
        case 'E':
            return 4;
            break;
        case 'F':
            return 5;
            break;
        case 'G':
            return 6;
            break;
        case 'H':
            return 7;
            break;
        case 'I':
            return 8;
            break;
        case 'J':
            return 9;
            break;
        default:
            return -1;
            break;
    }
}

void ganador(int tu, int cpu)
{
    printf ("Se acabo la partida.\n");
    if(tu<cpu)
    {
        printf("El ganador es la cpu.\n");
    }
    else
        {printf("El ganador has sido tu.\n");}
    printf("Tu has acertado %d barcos y la cpu ha acertado %d barcos.\n", tu, cpu);
}










