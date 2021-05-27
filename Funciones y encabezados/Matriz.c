#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Matriz.h"
#include "funcionesModoBatalla.h"
#include "estructuras.h"
#include "funcionesSecundarias.h"


int Matriz(int sonar, puntuacion *puntos)
{

    int tusbarcdestr = 0;
    int susbarcdestr = 0;
    int contarCoordenadasUSER = 0, contarCoordenadasCPU = 0, victoria = 0, modoBatallaActivado = 0;
    int misBarcos[10][10] = {0};
    int cpuBarcos[10][10] = {0};
    int misbarcosrellenos [10][10] = {0};
    int susbarcosrellenos [10][10] = {0};

    rellenarTodosLosBarcos(misBarcos);
    //imprimirMatrizdeBarcos(misBarcos, 10, 10);

    rellenarTodosLosBarcos(cpuBarcos);
    imprimirMatrizdeBarcos(cpuBarcos, 10, 10);


    while(tusbarcdestr<9 && susbarcdestr<9)
    {
        printf("\n\nTU TURNO: la situacion actual es: \n");
        imprimirMatrizdeBarcos(misbarcosrellenos, 10, 10);

            printf("Introduzca la columna de la casilla que desea atacar: (A-J):");
            char letra;
            scanf(" %c", &letra);
            int columna = traducirletra(letra);

            printf("Introduzca la fila de la casilla que desea atacar: (0-9):");
            int numero;
            scanf("%d", &numero);

            if(misbarcosrellenos[numero][columna]>0)
            {
            while(1==1)
            {
                printf("La casilla ya esta seleccionada. Elige otra\n");
                printf("Introduzca la columna de la casilla que desea atacar: (A-J):");
                scanf(" %c", &letra);
                columna = traducirletra(letra);
                printf("Introduzca la fila de la casilla que desea atacar: (0-9):");
                scanf("%d", &numero);
                if(misbarcosrellenos[numero][columna]==0)
                { break;}
            }
            }

        contarCoordenadasUSER = tucoordenada(columna, numero, sonar, misbarcosrellenos, cpuBarcos, &tusbarcdestr, puntos);
        if (contarCoordenadasUSER == 2 && modoBatallaActivado == 0)
        {
            contarCoordenadasUSER--;
            modoBatallaActivado = 1;
            victoria = modoBatalla(puntos);
        }
        printf("Barcos destruidos por ti: %d\n", tusbarcdestr);

        printf("\n\nCPU TURNO.\n");
        //int z = 9;
        int y = random(10);
        while(y>9){y = random(10);}
        int x = random(10);
        while(x>9){x = random(10);}
        while (susbarcosrellenos[x][y]>0){
            y = random(10);
            while(y>9){y = random(10);}
            x = random(10);
            while(x>9){x = random(10);}
        }

        contarCoordenadasCPU = sucoordenada(x, y, susbarcosrellenos, misBarcos, &susbarcdestr);
        if (contarCoordenadasCPU == 2 && modoBatallaActivado == 0)
        {
            contarCoordenadasCPU--;
            modoBatallaActivado = 1;
            victoria = modoBatalla(puntos);
        }
        printf("Barcos destruidos por CPU: %d\n", susbarcdestr);
    }
    ganador(tusbarcdestr,susbarcdestr, puntos);
    printf("Estos han sido tus resultados\n");
    imprimirMatrizdeBarcos(misbarcosrellenos, 10, 10);
    printf("Estos han sido sus resultados\n");
    imprimirMatrizdeBarcos(susbarcosrellenos, 10, 10);
    enter();
    return 0;
}

void imprimirMatrizdeBarcos(int matrizBarcos[][10], int fila, int column) {
    printf("Estos son los caracteres que representan las casillas del juego: o (barco), ~ (agua), x (barco especial), ? (casilla no rellenada).\n");
    printf("- A B C D E F G H I J\n");
    for (int x=0; x<fila; x++) {
        printf("%d ", x);
        for(int y=0; y<column; y++) {
            if (matrizBarcos[x][y] == 1){
                printf("o ");
            } else if (matrizBarcos[x][y] == 2){
                printf("~ ");
            } else if (matrizBarcos[x][y] == 3){
                printf("x ");
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

//int x = 9 , y = 1;
    //Introducir barco de 4
    while (1 == 1){

        int direccion = random(2);
        while(direccion>1){direccion = random(2);}
        int fila = random(10);
        while(fila>9){fila = random(10);}
        int columna = random(10);
        while(columna>9){columna = random(10);}
        int resultado = comprobarCabeBarco(4, fila, columna, direccion, matrizBarcos);
        if (resultado == 1) {
            rellenarBarco(4, fila, columna, direccion, 0, matrizBarcos);
            break;
        }
    }
    //Introducir barco de 3
    for (int i=0; i<3; i++) {
        while (1==1){
            int direccion = random(2);
            while(direccion>1){direccion = random(2);}
            int fila = random(10);
            while(fila>9){fila = random(10);}
            int columna = random(10);
            while(columna>9){columna = random(10);}
            int resultado = comprobarCabeBarco(3, fila, columna, direccion, matrizBarcos);
            if (resultado == 1) {
                rellenarBarco(3, fila, columna, direccion, 0, matrizBarcos);
                break;
            }
        }
    }
    //Introducir barco de 2
    for (int i=0; i<3; i++) {
        while (1==1){
            int direccion = random(2);
            while(direccion>1){direccion = random(2);}
            int fila = random(10);
            while(fila>9){fila = random(10);}
            int columna = random(10);
            while(columna>9){columna = random(10);}
            int resultado = comprobarCabeBarco(2, fila, columna, direccion, matrizBarcos);
            if (resultado == 1) {
                rellenarBarco(2, fila, columna, direccion, 0, matrizBarcos);
                break;
            }
        }
    }
    //Introducir barco de 1
    while (1==1){
        int direccion = random(2);
        while(direccion>1){direccion = random(2);}
        int fila = random(10);
        while(fila>9){fila = random(10);}
        int columna = random(10);
        while(columna>9){columna = random(10);}
        int resultado = comprobarCabeBarco(1, fila, columna, direccion, matrizBarcos);
        if (resultado == 1) {
            rellenarBarco(1, fila, columna, direccion, 0, matrizBarcos);
            break;
        }
    }
    //Introducir barco de 1 especial
    while (1==1){
        int direccion = random(2);
        while(direccion>1){direccion = random(2);}
        int fila = random(10);
        while(fila>9){fila = random(10);}
        int columna = random(10);
        while(columna>9){columna = random(10);}
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

int sucoordenada(int fi, int co, int SuMatriz[][10], int TuMatriz[][10], int *susbarcosdestruidos)
{
    SuMatriz[fi][co] = TuMatriz[fi][co];
    if(SuMatriz[fi][co] == 1){
        printf("Te han dado a un barco, este es su resultado:\n");
        int contar = 0;
        int contarb = 1;
        for(int i=-1; i<3; i++){
                for(int j=-1; j<3; j++){
                    int filanue = fi + i;
                    int columnanue = co + j;

                    if (filanue <0 || filanue > 9 || columnanue <0 || columnanue >9) {
                        //Estamos fuera de la matriz
                        continue;
                    }
                    if (TuMatriz[filanue][columnanue] == 1) {
                        contar++;
                    }
                }
            }
        if(contar == 1)
        {
            printf("Te han destruido un barco de dimension 1.\n");
            *susbarcosdestruidos += 1;
        }
        else {
            contar = 0;
            if(TuMatriz[fi][co+1]==1||TuMatriz[fi][co-1]==1)
                {
                    for(int i=1; i<4;i++)
                    {
                        int columnanue = co + i;
                        if (fi <0 || fi > 9 || columnanue <0 || columnanue >9) {
                            //Estamos fuera de la matriz
                            continue;
                        }
                        if (SuMatriz[fi][columnanue]==1 && TuMatriz[fi][columnanue]==1)
                            {contarb+=1;
                            continue;}
                        if (TuMatriz[fi][columnanue]==2 && SuMatriz[fi][columnanue]==0)
                            {break;}
                        if (SuMatriz[fi][columnanue]==2)
                            {break;}
                        contar++;
                    }

                    for(int i=1; i<4;i++)
                    {
                        int columnanue = co - i;
                        if (fi <0 || fi > 9 || columnanue <0 || columnanue >9) {
                            //Estamos fuera de la matriz
                            continue;
                        }
                        if (SuMatriz[fi][columnanue]==1 && TuMatriz[fi][columnanue]==1)
                            {contarb+=1;
                            continue;}
                        if (TuMatriz[fi][columnanue]==2 && SuMatriz[fi][columnanue]==0)
                            {break;}
                        if (SuMatriz[fi][columnanue]==2)
                            {break;}
                        contar++;
                    }
            }else{if(TuMatriz[fi+1][co]==1||TuMatriz[fi-1][co]==1)
            {
                for(int i=1; i<4;i++)
                    {
                        int filanue = fi + i;
                        if (filanue <0 || filanue > 9 || co <0 || co >9) {
                            //Estamos fuera de la matriz
                            continue;
                        }
                        if (SuMatriz[filanue][co]==1 && TuMatriz[filanue][co]==1)
                            {contarb+=1;
                            continue;}
                        if (TuMatriz[filanue][co]==2 && SuMatriz[filanue][co]==0)
                            {break;}
                        if (SuMatriz[filanue][co]==2)
                            {break;}
                        contar++;
                    }

                for(int i=1; i<4;i++)
                    {
                        int filanue = fi - i;
                        if (filanue <0 || filanue > 9 || co <0 || co >9) {
                            //Estamos fuera de la matriz
                            continue;
                        }
                        if (SuMatriz[filanue][co]==1 && TuMatriz[filanue][co]==1)
                            {contarb+=1;
                            continue;}
                        if (TuMatriz[filanue][co]==2 && SuMatriz[filanue][co]==0)
                            {break;}
                        if (SuMatriz[filanue][co]==2)
                            {break;}
                        contar++;
                    }
            }
            }
        }
        if(contar == 0)
        {
            printf("Te han destruido un barco de dimension %i.\n", contarb);
            *susbarcosdestruidos += 1;
        }
        imprimirMatrizdeBarcos(SuMatriz, 10, 10);
        return 1;
    }
    else if (SuMatriz[fi][co] == 2){
        printf("No te han dado ningun barco, este es su resultado:\n");
        imprimirMatrizdeBarcos(SuMatriz, 10, 10);
        return 0;
    }
    else if(SuMatriz[fi][co] == 3) {
        printf("Te han dado al barco especial de dimension 1, este es su resultado:\n");
        imprimirMatrizdeBarcos(SuMatriz, 10, 10);
        //Entramos aqui en el modo batalla especial entre barcos.
        return 2;
    }
}

int tucoordenada(int columna, int fila, int son, int tuMatriz[][10], int suMatriz[][10], int *tusbarcosdestruidos, puntuacion *puntos)
{
    tuMatriz[fila][columna] = suMatriz[fila][columna];
    if(tuMatriz[fila][columna] == 1){
        int contar = 0;
        int contarb = 1;
        printf("Has dado a un barco\n");
        for(int i=-1; i<3; i++){
                for(int j=-1; j<3; j++){
                    int filanue = fila + i;
                    int columnanue = columna + j;

                    if (filanue <0 || filanue > 9 || columnanue <0 || columnanue >9) {
                        //Estamos fuera de la matriz
                        continue;
                    }
                    if (suMatriz[filanue][columnanue] == 1) {
                        contar++;
                    }
                }
            }
        if(contar == 1)
        {
            printf("Has destruido un barco de dimension 1.\n");
            puntos->barcosHundidos +=1;
            puntos->puntuacionTot += 100;
            *tusbarcosdestruidos +=1;
        }
        else {
            contar = 0;
            if(suMatriz[fila][columna+1]==1||suMatriz[fila][columna-1]==1)
                {
                    for(int i=1; i<4;i++)
                    {
                        int columnanue = columna + i;
                        if (fila <0 || fila > 9 || columnanue <0 || columnanue >9) {
                            //Estamos fuera de la matriz
                            continue;
                        }
                        if (suMatriz[fila][columnanue]==1 && tuMatriz[fila][columnanue]==1)
                            {
                            contarb++;
                            continue;}
                        if (suMatriz[fila][columnanue]==2 && tuMatriz[fila][columnanue]==0)
                            {break;}
                        if (tuMatriz[fila][columnanue]==2)
                            {break;}
                        contar++;
                    }

                    for(int i=1; i<4;i++)
                    {
                        int columnanue = columna - i;
                        if (fila <0 || fila > 9 || columnanue <0 || columnanue >9) {
                            //Estamos fuera de la matriz
                            continue;
                        }
                        if (suMatriz[fila][columnanue]==1 && tuMatriz[fila][columnanue]==1)
                            {
                            contarb++;
                            continue;}
                        if (suMatriz[fila][columnanue]==2 && tuMatriz[fila][columnanue]==0)
                            {break;}
                        if (tuMatriz[fila][columnanue]==2)
                            {break;}
                        contar++;
                    }

                }
            else{if(suMatriz[fila+1][columna]==1||suMatriz[fila-1][columna]==1)
            {
                for(int i=1;i<4;i++)
                    {
                        int filanue = fila + i;
                        if (filanue <0 || filanue > 9 || columna <0 || columna >9) {
                            //Estamos fuera de la matriz
                            continue;
                        }
                        if (suMatriz[filanue][columna]==1 && tuMatriz[filanue][columna]==1)
                            {
                            contarb++;
                            continue;}
                        if (suMatriz[filanue][columna]==2 && tuMatriz[filanue][columna]==0)
                            {break;}
                        if (tuMatriz[filanue][columna]==2)
                            {break;}
                        contar++;
                    }

                for(int i=1; i<4;i++)
                    {
                        int filanue = fila - i;
                        if (filanue <0 || filanue > 9 || columna <0 || columna >9) {
                            //Estamos fuera de la matriz
                            continue;
                        }
                        if (suMatriz[filanue][columna]==1 && tuMatriz[filanue][columna]==1)
                            {
                            contarb++;
                            continue;}
                        if (suMatriz[filanue][columna]==2 && tuMatriz[filanue][columna]==0)
                            {break;}
                        if (tuMatriz[filanue][columna]==2)
                            {break;}
                        contar++;
                    }
            }
            }
        }
        if(contar == 0)
        {
            printf("Has destruido un barco de dimension %i.\n", contarb);
            puntos->barcosHundidos += 1;
            *tusbarcosdestruidos +=1;
            switch(contarb)
            {
            case 4:
                puntos->puntuacionTot += 400;
                break;
            case 3:
                puntos->puntuacionTot += 300;
                break;
            case 2:
                puntos->puntuacionTot += 200;
                break;
            default:
                break;
            }
        }
        return 1;
    }
    else if (tuMatriz[fila][columna] == 2){
        int k = 0;
        int l = 0;
        printf("No has dado a ningun barco\n");
        switch(son)
            {
            case 3:
                for(int i=-3; i<7; i++){
                for(int j=-3; j<7; j++){
                    int filan = fila + i;
                    int columnan = columna + j;

                    if (filan <0 || filan > 9 || columnan <0 || columnan >9) {
                        //Estamos fuera de la matriz
                        continue;
                    }
                    if (suMatriz[filan][columnan] == 1&& tuMatriz[filan][columnan]==0) {
                        k++;
                    }
                }
            }
            printf("%d casillas de barco estan en un radio de 3 casillas\n", k);
                break;
            case 2:
                for(int i=-2; i<5; i++){
                for(int j=-2; j<5; j++){
                    int filanu = fila + i;
                    int columnanu = columna + j;

                    if (filanu <0 || filanu > 9 || columnanu <0 || columnanu >9) {
                        //Estamos fuera de la matriz
                        continue;
                    }
                    if (suMatriz[filanu][columnanu] == 1 && tuMatriz[filanu][columnanu]==0) {
                        l++;
                    }
                }
            }
            printf("%d casillas de barco estan en un radio de 2 casillas\n", l);
                break;
            case 0:
                break;
            }
        return 0;
    }
    else if(tuMatriz[fila][columna] == 3) {
        printf("Has destruido el barco especial de dimension 1.\n");
        puntos->barcosHundidos += 1;
        puntos->puntuacionTot += 800;
        *tusbarcosdestruidos += 1;
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

void ganador(int tu, int cpu, puntuacion *puntos)
{
    printf ("Se acabo la partida.\n");
    if(tu<cpu)
    {
        printf("El ganador es la cpu.\n");
    }
    else
        {printf("El ganador has sido tu.\n");
        puntos->victorias +=1;}
    printf("Tu has acertado %d barcos y la cpu ha acertado %d barcos.\n", tu, cpu);
}










