#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"

int Matriz(int x) {
    int mbarcos = 0;
    int sbarcos = 0;
    int misBarcos[10][10] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};
    int cpuBarcos[10][10] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};
    int misbarcosrellenos [10][10] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};
    int susbarcosrellenos [10][10] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};

    rellenarTodosLosBarcos(misBarcos);
    rellenarTodosLosBarcos(cpuBarcos);

    while(mbarcos <21||sbarcos<21)
    {
        printf("Introduzca la coordenada de la casilla que desea atacar: (letra en mayusculas seguido de su numero)\n");
        imprimirMatrizdeBarcos(misbarcosrellenos, 10, 10);
        scanf("%c %i", &l, &n);
        mbarcos+=tucoordenada(char letra, int numero, int x, int misbarcosrellenos[][10], int cpuBarcos[][10]);
        printf("Ahora le toca a tu rival.\n");
        y = rand() %10;
        x = rand() %10;
        sbarcos+=sucoordenada(int x, int y, int susbarcosrellenos, int misBarcos[][10]);
    }
    ganador(mbarcos,sbarcos);
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
    SuMatriz[fi][co] = 1;
    if(SuMatriz[fi][co] == TuMatriz[fi][co])
    {
        printf("Te han dado a un barco, este es su resultado:\n");
        imprimirMatrizdeBarcos(SuMatriz, 10, 10);
        return 1;
    }
    else{
    if(TuMatriz[fi][co]=3)
    {
        SuMatriz[fi][co] = 3;
        Printf("Te han dañado al barco especial, este es su resultado:\n");
        imprimirMatrizdeBarcos(SuMatriz, 10, 10);
        return 1;
        //Entramos aqui en el modo batalla especial entre barcos.
    }
        Printf("No te han dañado ningun barco, este es su resultado:\n");
        SuMatriz[fi][co] = 2;
        imprimirMatrizdeBarcos(SuMatriz, 10, 10);
        return 0;
    }

}


int tucoordenada(char letra, int numero, int tuMatriz[][10], int suMatriz[][10])
{
    switch(letra)
    {
    case 'A':
        y = 0;
        break;
    case 'B':
        y = 1;
        break;
    case 'C':
        y = 2;
        break;
    case 'D':
        y = 3;
        break;
    case 'E':
        y = 4;
        break;
    case 'F':
        y = 5;
        break;
    case 'G':
        y = 6;
        break;
    case 'H':
        y = 7;
        break;
    case 'I':
        y = 8;
        break;
    case 'J':
        y = 9;
        break;
    default:
        printf("Vuelva a introducir la coordenada.\n");
        break;
    }
    tuMatriz[numero][y] = 1;
    if(tuMatriz[numero][y] == suMatriz[numero][y])
    {
        printf("Has dado a un barco, este es tu resulatdo:\n");
        imprimirMatrizdeBarcos(tuMatriz, 10, 10);
        return 1;
    }
    else{
    if(suMatriz[numero][y]=3)
    {
        tuMatriz[numero][y] = 3;
        Printf("Has dañado al barco especial, este es tu resultado:\n");
        imprimirMatrizdeBarcos(tuMatriz, 10, 10);
        return 1;
        //Entramos aqui en el modo batalla especial entre barcos.
    }
        Printf("No has dañado ningun barco, este es tu resultado:\n");
        tuMatriz[numero][y] = 2;
        imprimirMatrizdeBarcos(tuMatriz, 10, 10);
        return 0;
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
    printf("El ganador has sido tu.\n");
}
