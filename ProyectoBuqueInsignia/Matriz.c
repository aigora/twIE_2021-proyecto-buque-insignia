#include <stdio.h>
#include <stdlib.h>
#include <Matriz.h>

int Matriz(int x) {
    int misBarcos[10][10] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};
    int cpuBarcos[10][10] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};

    rellenarTodosLosBarcos(misBarcos);
    rellenarTodosLosBarcos(cpuBarcos);

    imprimirMatrizdeBarcos(misBarcos, 10, 10);
    return 0;
}
void imprimirMatrizdeBarcos(int MatBarcos[][10], int fila, int column) {
    printf("- A B C D E F G H I J\n");
    for (int x=0; x<fila; x++) {
        printf("%d ", x);
        for(int y=0; y<column; y++) {
            printf("%d ", MatBarcos[x][y]);
        }
        printf("\n");
    }
}
