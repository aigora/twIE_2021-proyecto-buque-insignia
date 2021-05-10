#include <stdio.h>
#include <stdlib.h>
#include <Matriz.h>

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
        scanf("%c %i", &l, &n)
        mbarcos+=tucoordenada(char letra, int numero, int misbarcosrellenos[][10], int cpuBarcos[][10]);
        printf("Ahora le toca a tu rival.\n")
        y = rand() %10;
        x = rand() %10;
        sbarcos+=sucoordenada(int x, int y, int susbarcosrellenos, int misBarcos[][10]))
    }
    printf ("Se acabo la partida.\n")
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

void rellenarBarco(int tam, int esEspecial, int MatrizBarcos[][10]) {
    //Miramos si es Horizontal (0) o Vertical (1)
    int direccion = rand() % 2;
    //printf("Direccion del barco vale %d\n", direccion);

    if (direccion == 0) {
        int x=0;
        int y=0;
         switch (size) {
            case 4:
                x = rand() %10;
                y = rand() %7;
                //printf("El barco de 4 Horizontal comienza en (%d,%d)\n", x, y);
                //En la matriz (1) significa barco, (2) agua, (3) barco especial y (0) casilla aun no rellenada.
                 if(x=0&&y=6)
                {
                    Matrizbarcos[x][y-1] = 2;
                    Matrizbarcos[x+1][y-1]=2;
                    for(int i=0; i<4;i++){
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x+1][y]=2;
                        y++
                    }
                }

                if(x=9&&y=6)
                {
                    Matrizbarcos[x][y-1] = 2;
                    Matrizbarcos[x-1][y-1]=2;
                    for(int i=0; i<4;i++){
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x-1][y]=2;
                    y++
                    }
                }

                if(x=9)
                {
                    Matrizbarcos[x][y-1] = 2;
                    Matrizbarcos[x-1][y-1]=2;
                    for(int i=0; i<4;i++){
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x-1][y] = 2;
                        y++
                    }
                    Matrizbarcos[x][y+1] = 2;
                    Matrizbarcos[x-1][y+1] = 2;
                }


                if(x=0&&y=0)
                {
                    for(int i=0; i<4; i++) {
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x+1][y] = 2;
                        y+=1;
                    }
                    Matrizbarcos[x][y+1] = 2;
                    Matrizbarcos[x+1][y+1] = 2;
                }

                if(y=6)
                {
                    Matrizbarcos[x][y-1] = 2;
                    Matrizbarcos[x+1][y-1]=2;
                    Matrizbarcos[x-1][y-1]=2;
                    for(int i=0; i<4; i++) {
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x+1][y]=2;
                        Matrizbarcos[x-1][y]=2;
                        y+=1;
                    }
                }

                if(x=9&&y=0)
                {
                    for(int i=0; i<4; i++) {
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x-1][y] = 2;
                        y+=1;
                    }
                    Matrizbarcos[x][y+1] = 2;
                    Matrizbarcos[x-1][y+1] = 2;
                }

                if(x=0)
                {
                    Matrizbarcos[x][y-1] = 2;
                    Matrizbarcos[x+1][y-1]=2;
                    for(int i=0; i<4; i++) {
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x+1][y] = 2;
                        y+=1;
                    }
                    Matrizbarcos[x][y+1] = 2;
                    Matrizbarcos[x+1][y+1] = 2;
                }

                if(y=0)
                {
                    for(int i=0; i<4; i++) {
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x-1][y] = 2;
                        Matrizbarcos[x+1][y] = 2;
                        y+=1;
                    }
                    Matrizbarcos[x][y+1] = 2;
                    Matrizbarcos[x-1][y+1] = 2;
                    Matrizbarcos[x+1][y+1] = 2;
                }

                Matrizbarcos[x][y-1] = 2;
                Matrizbarcos[x+1][y-1]=2;
                Matrizbarcos[x-1][y-1]=2;
                for(int i=0; i<4; i++) {
                    Matrizbarcos[x][y] = 1;
                    Matrizbarcos[x+1][y]=2;
                    Matrizbarcos[x-1][y]=2;
                    y+=1;
                }
                Matrizbarcos[x][y+1] = 2;
                Matrizbarcos[x+1][y+1]=2;
                Matrizbarcos[x-1][y+1]=2;
                //printf("El barco de 4 Horizontal comienza en (%d,%d)\n", x, y);

                break;
            case 3:
                Alt:
                x = rand() %10;
                y = rand() %8;

                if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                    goto Alt;
                }

                 if(x=0&&y=7)
                {
                    if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x+1][y-1]=1) {
                        goto Alt;}
                    Matrizbarcos[x][y-1] = 2;
                    Matrizbarcos[x+1][y-1]=2;
                    for(int i=0; i<3;i++){
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Alt;
                        }
                        if(MatrizBarcos[x+1][y]=1)
                            { goto Alt;}
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x+1][y]=2;
                        y++
                    }
                }

                if(x=9&&y=7)
                {
                    if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x-1][y-1]=1) {
                        goto Alt;}
                    Matrizbarcos[x][y-1] = 2;
                    Matrizbarcos[x-1][y-1]=2;
                    for(int i=0; i<3;i++){
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Alt;
                        }
                        if(MatrizBarcos[x-1][y]=1)
                            { goto Alt;}
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x-1][y]=2;
                    y++
                    }
                }

                if(x=9)
                {
                    if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x-1][y-1]=1) {
                        goto Alt;}
                    Matrizbarcos[x][y-1] = 2;
                    Matrizbarcos[x-1][y-1]=2;
                    for(int i=0; i<3;i++){
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Alt;
                        }
                        if(MatrizBarcos[x-1][y]=1)
                        {
                            goto Alt;
                        }
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x-1][y] = 2;
                        y++
                    }
                    if(MatrizBarcos[x][y+1]=1||MatrizBarcos[x-1][y+1]=1)
                    {
                        goto Alt;
                    }
                    Matrizbarcos[x][y+1] = 2;
                    Matrizbarcos[x-1][y+1] = 2;
                }


                if(x=0&&y=0)
                {
                    for(int i=0; i<3; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Alt;
                            }
                        if(MatrizBarcos[x+1][y]=1)
                        {
                            goto Alt;
                        }
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x+1][y] = 2;
                        y+=1;
                    }
                    if(MatrizBarcos[x][y+1]=1||MatrizBarcos[x+1][y+1]=1)
                    {
                        goto Alt;
                    }
                    Matrizbarcos[x][y+1] = 2;
                    Matrizbarcos[x+1][y+1] = 2;
                }

                if(y=7)
                {
                    if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x+1][y-1]=1) {
                        goto Alt;}
                    if(MatrizBarcos[x-1][y-1]=1)
                    {
                        goto Alt;
                    }
                    Matrizbarcos[x][y-1] = 2;
                    Matrizbarcos[x+1][y-1]=2;
                    Matrizbarcos[x-1][y-1]=2;
                    for(int i=0; i<3; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Alt;
                        }
                        if(MatrizBarcos[x-1][y]=1||MatrizBarcos[x+1][y]=1)
                            { goto Alt;}
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x+1][y]=2;
                        Matrizbarcos[x-1][y]=2;
                        y+=1;
                    }
                }

                if(x=9&&y=0)
                {
                    for(int i=0; i<3; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Alt;
                        }
                        if(MatrizBarcos[x-1][y]=1)
                        {
                            goto Alt;
                        }
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x-1][y] = 2;
                        y+=1;
                    }
                    if(MatrizBarcos[x][y+1]=1||MatrizBarcos[x-1][y+1]=1)
                    {
                        goto Alt;
                    }
                    Matrizbarcos[x][y+1] = 2;
                    Matrizbarcos[x-1][y+1] = 2;
                }

                if(x=0)
                {
                    if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x+1][y-1]=1) {
                        goto Alt;}
                    Matrizbarcos[x][y-1] = 2;
                    Matrizbarcos[x+1][y-1]=2;
                    for(int i=0; i<3; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Alt;
                        }
                        if(MatrizBarcos[x+1][y]=1)
                        {
                            goto Alt;
                        }
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x+1][y] = 2;
                        y+=1;
                    }
                    if(MatrizBarcos[x][y+1]=1||MatrizBarcos[x+1][y+1]=1)
                    {
                        goto Alt;
                    }
                    Matrizbarcos[x][y+1] = 2;
                    Matrizbarcos[x+1][y+1] = 2;
                }

                if(y=0)
                {
                    for(int i=0; i<3; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Alt;
                        }
                        if(MatrizBarcos[x-1][y]=1||MatrizBarcos[x+1][y]=1)
                        {
                            goto Alt;
                        }
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x-1][y] = 2;
                        Matrizbarcos[x+1][y] = 2;
                        y+=1;
                    }
                    if(MatrizBarcos[x][y+1]=1||MatrizBarcos[x+1][y+1]=1) {
                        goto Alt;}
                    if(MatrizBarcos[x-1][y+1]=1)
                    {
                        goto Alt;
                    }
                    Matrizbarcos[x][y+1] = 2;
                    Matrizbarcos[x-1][y+1] = 2;
                    Matrizbarcos[x+1][y+1] = 2;
                }

                if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x+1][y-1]=1) {
                    goto Alt;}
                if(MatrizBarcos[x-1][y-1]=1)
                {
                    goto Alt;
                }
                Matrizbarcos[x][y-1] = 2;
                Matrizbarcos[x+1][y-1]=2;
                Matrizbarcos[x-1][y-1]=2;
                for(int i=0; i<3; i++) {
                    if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                        goto Alt;
                    }
                    if(MatrizBarcos[x-1][y]=1||MatrizBarcos[x+1][y]=1)
                        { goto Alt;}
                    Matrizbarcos[x][y] = 1;
                    Matrizbarcos[x+1][y]=2;
                    Matrizbarcos[x-1][y]=2;
                    y+=1;
                }
                if(MatrizBarcos[x][y+1]=1||MatrizBarcos[x+1][y+1]=1) {
                    goto Alt;}
                if(MatrizBarcos[x-1][y+1]=1)
                    {
                        goto Alt;
                    }
                Matrizbarcos[x][y+1] = 2;
                Matrizbarcos[x+1][y+1]=2;
                Matrizbarcos[x-1][y+1]=2;
                 //printf("El barco de 3 Horizontal comienza en (%d,%d)\n", x, y);
                break;
            case 2:
                Alto:
                x = rand() %10;
                y = rand() %9;

                if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                    goto Alto;
                }

                 if(x=0&&y=8)
                {
                    if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x+1][y-1]=1) {
                        goto Alto;}
                    Matrizbarcos[x][y-1] = 2;
                    Matrizbarcos[x+1][y-1]=2;
                    for(int i=0; i<2;i++){
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Alto;
                        }
                        if(MatrizBarcos[x+1][y]=1)
                            { goto Alto;}
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x+1][y]=2;
                        y++
                    }
                }

                if(x=9&&y=8)
                {
                    if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x-1][y-1]=1) {
                        goto Alto;}
                    Matrizbarcos[x][y-1] = 2;
                    Matrizbarcos[x-1][y-1]=2;
                    for(int i=0; i<2;i++){
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Alto;
                        }
                        if(MatrizBarcos[x-1][y]=1)
                            { goto Alto;}
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x-1][y]=2;
                    y++
                    }
                }

                if(x=9)
                {
                    if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x-1][y-1]=1) {
                        goto Alto;}
                    Matrizbarcos[x][y-1] = 2;
                    Matrizbarcos[x-1][y-1]=2;
                    for(int i=0; i<2;i++){
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Alto;
                        }
                        if(MatrizBarcos[x-1][y]=1)
                        {
                            goto Alto;
                        }
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x-1][y] = 2;
                        y++
                    }
                    if(MatrizBarcos[x][y+1]=1||MatrizBarcos[x-1][y+1]=1)
                    {
                        goto Alto;
                    }
                    Matrizbarcos[x][y+1] = 2;
                    Matrizbarcos[x-1][y+1] = 2;
                }


                if(x=0&&y=0)
                {
                    for(int i=0; i<2; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Alto;
                            }
                        if(MatrizBarcos[x+1][y]=1)
                        {
                            goto Alto;
                        }
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x+1][y] = 2;
                        y+=1;
                    }
                    if(MatrizBarcos[x][y+1]=1||MatrizBarcos[x+1][y+1]=1)
                    {
                        goto Alto;
                    }
                    Matrizbarcos[x][y+1] = 2;
                    Matrizbarcos[x+1][y+1] = 2;
                }

                if(y=8)
                {
                    if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x+1][y-1]=1) {
                        goto Alto;}
                    if(MatrizBarcos[x-1][y-1]=1)
                    {
                        goto Alto;
                    }
                    Matrizbarcos[x][y-1] = 2;
                    Matrizbarcos[x+1][y-1]=2;
                    Matrizbarcos[x-1][y-1]=2;
                    for(int i=0; i<2; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Alto;
                        }
                        if(MatrizBarcos[x-1][y]=1||MatrizBarcos[x+1][y]=1)
                            { goto Alto;}
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x+1][y]=2;
                        Matrizbarcos[x-1][y]=2;
                        y+=1;
                    }
                }

                if(x=9&&y=0)
                {
                    for(int i=0; i<2; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Alto;
                        }
                        if(MatrizBarcos[x-1][y]=1)
                        {
                            goto Alto;
                        }
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x-1][y] = 2;
                        y+=1;
                    }
                    if(MatrizBarcos[x][y+1]=1||MatrizBarcos[x-1][y+1]=1)
                    {
                        goto Alto;
                    }
                    Matrizbarcos[x][y+1] = 2;
                    Matrizbarcos[x-1][y+1] = 2;
                }

                if(x=0)
                {
                    if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x+1][y-1]=1) {
                        goto Alto;}
                    Matrizbarcos[x][y-1] = 2;
                    Matrizbarcos[x+1][y-1]=2;
                    for(int i=0; i<2; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Alto;
                        }
                        if(MatrizBarcos[x+1][y]=1)
                        {
                            goto Alto;
                        }
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x+1][y] = 2;
                        y+=1;
                    }
                    if(MatrizBarcos[x][y+1]=1||MatrizBarcos[x+1][y+1]=1)
                    {
                        goto Alto;
                    }
                    Matrizbarcos[x][y+1] = 2;
                    Matrizbarcos[x+1][y+1] = 2;
                }

                if(y=0)
                {
                    for(int i=0; i<2; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Alto;
                        }
                        if(MatrizBarcos[x-1][y]=1||MatrizBarcos[x+1][y]=1)
                        {
                            goto Alto;
                        }
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x-1][y] = 2;
                        Matrizbarcos[x+1][y] = 2;
                        y+=1;
                    }
                    if(MatrizBarcos[x][y+1]=1||MatrizBarcos[x+1][y+1]=1) {
                        goto Alto;}
                    if(MatrizBarcos[x-1][y+1]=1)
                    {
                        goto Alto;
                    }
                    Matrizbarcos[x][y+1] = 2;
                    Matrizbarcos[x-1][y+1] = 2;
                    Matrizbarcos[x+1][y+1] = 2;
                }

                if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x+1][y-1]=1) {
                    goto Alto;}
                if(MatrizBarcos[x-1][y-1]=1)
                {
                    goto Alto;
                }
                Matrizbarcos[x][y-1] = 2;
                Matrizbarcos[x+1][y-1]=2;
                Matrizbarcos[x-1][y-1]=2;
                for(int i=0; i<2; i++) {
                    if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                        goto Alto;
                    }
                    if(MatrizBarcos[x-1][y]=1||MatrizBarcos[x+1][y]=1)
                        { goto Alto;}
                    Matrizbarcos[x][y] = 1;
                    Matrizbarcos[x+1][y]=2;
                    Matrizbarcos[x-1][y]=2;
                    y+=1;
                }
                if(MatrizBarcos[x][y+1]=1||MatrizBarcos[x+1][y+1]=1) {
                    goto Alto;}
                if(MatrizBarcos[x-1][y+1]=1)
                    {
                        goto Alto;
                    }
                Matrizbarcos[x][y+1] = 2;
                Matrizbarcos[x+1][y+1]=2;
                Matrizbarcos[x-1][y+1]=2;
                // printf("El barco de 2 Horizontal comienza en (%d,%d)\n", x, y);
                break;
            case 1:
                Altor:
                x = rand() %10;
                y = rand() %10;

                if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                    goto Altor;
                }

                if(x=0&&y=0)
                {
                    if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                        goto Altor;
                        }
                    if(MatrizBarcos[x+1][y]=1)
                    {
                    goto Altor;
                    }
                    Matrizbarcos[x][y] = 1;
                    Matrizbarcos[x+1][y] = 2;
                    if(MatrizBarcos[x][y+1]=1||MatrizBarcos[x+1][y+1]=1)
                    {
                    goto Altor;
                    }
                    Matrizbarcos[x][y+1] = 2;
                    Matrizbarcos[x+1][y+1] = 2;
                }

                if(x=0&&y=9)
                {
                    if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x+1][y-1]=1) {
                        goto Altor;}
                    Matrizbarcos[x][y-1] = 2;
                    Matrizbarcos[x+1][y-1]=2;
                    if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                        goto Altor;
                    }
                    if(MatrizBarcos[x+1][y]=1)
                        { goto Altor;}
                    Matrizbarcos[x][y] = 1;
                    Matrizbarcos[x+1][y]=2;
                }

                if(x=9&&y=9)
                {
                    if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x-1][y-1]=1) {
                        goto Altor;}
                    Matrizbarcos[x][y-1] = 2;
                    Matrizbarcos[x-1][y-1]=2;
                    if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                        goto Altor;
                    }
                    if(MatrizBarcos[x-1][y]=1)
                        { goto Altor;}
                    Matrizbarcos[x][y] = 1;
                    Matrizbarcos[x-1][y]=2;
                }

                if(x=9&&y=0)
                {
                    if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                        goto Altor;
                        }
                    if(MatrizBarcos[x-1][y]=1)
                    {
                        goto Altor;
                    }
                    Matrizbarcos[x][y] = 1;
                    Matrizbarcos[x-1][y] = 2;
                    if(MatrizBarcos[x][y+1]=1||MatrizBarcos[x-1][y+1]=1)
                    {
                        goto Altor;
                    }
                    Matrizbarcos[x][y+1] = 2;
                    Matrizbarcos[x-1][y+1] = 2;
                }


                if(y=9)
                {
                    if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x+1][y-1]=1) {
                        goto Altor;}
                    if(MatrizBarcos[x-1][y-1]=1)
                    {
                    goto Altor;
                    }
                    Matrizbarcos[x][y-1] = 2;
                    Matrizbarcos[x+1][y-1]=2;
                    Matrizbarcos[x-1][y-1]=2;
                    if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                        goto Altor;
                    }
                    if(MatrizBarcos[x-1][y]=1||MatrizBarcos[x+1][y]=1)
                        { goto Altor;}
                    Matrizbarcos[x][y] = 1;
                    Matrizbarcos[x+1][y]=2;
                    Matrizbarcos[x-1][y]=2;
                }

                if(x=0)
                {
                    if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x-1][y-1]=1) {
                        goto Altor;}
                    Matrizbarcos[x][y-1] = 2;
                    Matrizbarcos[x-1][y-1]=2;
                    if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                        goto Altor;
                    }
                    if(MatrizBarcos[x-1][y]=1)
                    {
                        goto Altor;
                    }
                    Matrizbarcos[x][y] = 1;
                    Matrizbarcos[x-1][y] = 2;
                    if(MatrizBarcos[x][y+1]=1||MatrizBarcos[x-1][y+1]=1)
                    {
                        goto Altor;
                    }
                    Matrizbarcos[x][y+1] = 2;
                    Matrizbarcos[x-1][y+1] = 2;
                }

                if(y=0)
                {
                    if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                        goto Altor;
                    }
                    if(MatrizBarcos[x-1][y]=1||MatrizBarcos[x+1][y]=1)
                    {
                        goto Altor;
                    }
                    Matrizbarcos[x][y] = 1;
                    Matrizbarcos[x-1][y] = 2;
                    Matrizbarcos[x+1][y] = 2;
                    if(MatrizBarcos[x][y+1]=1||MatrizBarcos[x+1][y+1]=1) {
                        goto Altor;}
                    if(MatrizBarcos[x-1][y+1]=1)
                    {
                        goto Altor;
                    }
                    Matrizbarcos[x][y+1] = 2;
                    Matrizbarcos[x-1][y+1] = 2;
                    Matrizbarcos[x+1][y+1] = 2;
                }

                if(x=9)
                {
                    if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x-1][y-1]=1) {
                        goto Altor;}
                    Matrizbarcos[x][y-1] = 2;
                    Matrizbarcos[x-1][y-1]=2;
                    if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                        goto Altor;
                    }
                    if(MatrizBarcos[x-1][y]=1)
                    {
                        goto Altor;
                    }
                    Matrizbarcos[x][y] = 1;
                    Matrizbarcos[x-1][y] = 2;
                    if(MatrizBarcos[x][y+1]=1||MatrizBarcos[x-1][y+1]=1)
                    {
                        goto Altor;
                    }
                    Matrizbarcos[x][y+1] = 2;
                    Matrizbarcos[x-1][y+1] = 2;
                }


                if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x+1][y-1]=1) {
                    goto Altor;}
                if(MatrizBarcos[x-1][y-1]=1)
                {
                    goto Altor;
                }
                Matrizbarcos[x][y-1] = 2;
                Matrizbarcos[x+1][y-1]=2;
                Matrizbarcos[x-1][y-1]=2;
                if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                    goto Altor;
                }
                if(MatrizBarcos[x-1][y]=1||MatrizBarcos[x+1][y]=1)
                    { goto Altor;}
                Matrizbarcos[x][y] = 1;
                Matrizbarcos[x+1][y]=2;
                Matrizbarcos[x-1][y]=2;
                if(MatrizBarcos[x][y+1]=1||MatrizBarcos[x+1][y+1]=1) {
                    goto Altor;}
                if(MatrizBarcos[x-1][y+1]=1)
                {
                    goto Altor;
                }
                Matrizbarcos[x][y+1] = 2;
                Matrizbarcos[x+1][y+1]=2;
                Matrizbarcos[x-1][y+1]=2;


                if(esEspecial=1)
                {
                    Matrizbarcos[x][y] = 3;
                }

                // printf("El barco de 1 Horizontal comienza en (%d,%d)\n", x, y);
                break;
            default:
                printf("El tamano del barco es incorrecto\n");
                break;
        }
    } else {
        //El barco esta colocado vertical
        int x=0;
        int y=0;
        switch (size) {
            case 4:
                y = rand() %10;
                x = rand() %7;
                if(x=0&&y=0)
                {
                    for(int i=0; i<3; i++) {
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x][y+1] = 2;
                        x+=1;
                    }
                    Matrizbarcos[x+1][y+1] = 2;
                    Matrizbarcos[x+1][y] = 2;
                }

                if(x=0)
                {
                    for(int i=0; i<3; i++) {
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x][y-1] = 2;
                        Matrizbarcos[x][y+1] = 2;
                        x+=1;
                    }
                    Matrizbarcos[x+1][y-1] = 2;
                    Matrizbarcos[x+1][y+1] = 2;
                    Matrizbarcos[x+1][y] = 2;
                }


                if(y=0)
                {
                    Matrizbarcos[x-1][y+1] = 2;
                    Matrizbarcos[x-1][y]=2;
                    for(int i=0; i<3; i++) {
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x][y+1] = 2;
                        x+=1;
                    }
                    Matrizbarcos[x+1][y+1] = 2;
                    Matrizbarcos[x+1][y] = 2;
                }

                 if(x=0&&y=9)
                {
                    for(int i=0; i<3; i++) {
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x][y-1]=2;
                        x+=1;
                    }
                    Matrizbarcos[x+1][y] = 2;
                    Matrizbarcos[x+1][y-1]=2;
                }

                if(x=7&&y=9)
                {
                    Matrizbarcos[x-1][y] = 2;
                    Matrizbarcos[x-1][y-1]=2;
                    for(int i=0; i<3; i++) {
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x][y-1]=2;
                        x+=1;
                    }
                }

                if(x=7&&y=0)
                {
                    Matrizbarcos[x-1][y] = 2;
                    Matrizbarcos[x-1][y+1] = 2;
                    for(int i=0; i<3; i++) {
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x][y+1] = 2;
                        x+=1;
                    }
                }

                if(y=9)
                {
                    Matrizbarcos[x-1][y] = 2;
                    Matrizbarcos[x-1][y-1]=2;
                    for(int i=0; i<3; i++) {
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x][y-1]=2;
                        x+=1;
                    }
                    Matrizbarcos[x+1][y] = 2;
                    Matrizbarcos[x+1][y-1]=2;
                }

                if(x=7)
                {
                    Matrizbarcos[x-1][y] = 2;
                    Matrizbarcos[x-1][y-1]=2;
                    Matrizbarcos[x-1][y+1]=2;
                    for(int i=0; i<3; i++) {
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x][y-1]=2;
                        MatrizBarcos[x][y+1]=2;
                        x+=1;
                    }
                }

                Matrizbarcos[x-1][y] = 2;
                Matrizbarcos[x-1][y-1]=2;
                Matrizbarcos[x-1][y+1]=2;
                for(int i=0; i<3; i++) {
                    Matrizbarcos[x][y] = 1;
                    Matrizbarcos[x][y+1]=2;
                    Matrizbarcos[x][y-1]=2;
                    x+=1;
                }
                Matrizbarcos[x+1][y] = 2;
                Matrizbarcos[x+1][y-1]=2;
                Matrizbarcos[x+1][y+1]=2;

                //printf("El barco de 4 Vertical comienza en (%d,%d)\n", x, y);
                break;
            case 3:
                Ale:
                y = rand() %10;
                x = rand() %8;
                if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                    goto Ale;
                }

                if(x=0&&y=0)
                {
                    for(int i=0; i<3; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Ale;
                        }
                        if(MatrizBarcos[x][y+1]=1)
                        {
                            goto Ale;
                        }
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x][y+1] = 2;
                        x+=1;
                    }
                    if(MatrizBarcos[x+1][y+1]=1||MatrizBarcos[x+1][y]=1)
                    {
                        goto Ale;
                    }
                    Matrizbarcos[x+1][y+1] = 2;
                    Matrizbarcos[x+1][y] = 2;
                }

                if(x=0)
                {
                    for(int i=0; i<3; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Ale;
                        }
                        if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x][y+1]=1)
                        {
                            goto Ale;
                        }
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x][y-1] = 2;
                        Matrizbarcos[x][y+1] = 2;
                        x+=1;
                    }
                    if(MatrizBarcos[x+1][y+1]=1||MatrizBarcos[x+1][y]=1) {
                        goto Ale;}
                    if(MatrizBarcos[x+1][y-1]=1)
                    {
                        goto Ale;
                    }
                    Matrizbarcos[x+1][y-1] = 2;
                    Matrizbarcos[x+1][y+1] = 2;
                    Matrizbarcos[x+1][y] = 2;
                }


                if(y=0)
                {
                    if(MatrizBarcos[x-1][y]=1||MatrizBarcos[x-1][y+1]=1) {
                        goto Ale;}
                    Matrizbarcos[x-1][y+1] = 2;
                    Matrizbarcos[x-1][y]=2;
                    for(int i=0; i<3; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Ale;
                        }
                        if(MatrizBarcos[x][y+1]=1)
                        {
                            goto Ale;
                        }
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x][y+1] = 2;
                        x+=1;
                    }
                    if(MatrizBarcos[x+1][y+1]=1||MatrizBarcos[x+1][y]=1)
                    {
                        goto Ale;
                    }
                    Matrizbarcos[x+1][y+1] = 2;
                    Matrizbarcos[x+1][y] = 2;
                }

                 if(x=0&&y=9)
                {
                    for(int i=0; i<3; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Ale;}
                        if(MatrizBarcos[x][y-1]=1)
                            { goto Ale;}
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x][y-1]=2;
                        x+=1;
                    }
                    if(MatrizBarcos[x+1][y]=1||MatrizBarcos[x+1][y-1]=1) {
                        goto Ale;
                    }
                    Matrizbarcos[x+1][y] = 2;
                    Matrizbarcos[x+1][y-1]=2;
                }

                if(x=7&&y=9)
                {
                    if(MatrizBarcos[x-1][y]=1||MatrizBarcos[x-1][y-1]=1) {
                        goto Ale;}
                    Matrizbarcos[x-1][y] = 2;
                    Matrizbarcos[x-1][y-1]=2;
                    for(int i=0; i<3; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Ale;
                        }
                        if(MatrizBarcos[x][y-1]=1)
                            { goto Ale;}
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x][y-1]=2;
                        x+=1;
                    }
                }

                if(x=7&&y=0)
                {
                    if(MatrizBarcos[x-1][y+1]=1||MatrizBarcos[x-1][y]=1) {
                        goto Ale;
                        }
                    Matrizbarcos[x-1][y] = 2;
                    Matrizbarcos[x-1][y+1] = 2;
                    for(int i=0; i<3; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Ale;
                        }
                        if(MatrizBarcos[x][y+1]=1)
                        {
                            goto Ale;
                        }
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x][y+1] = 2;
                        x+=1;
                    }
                }

                if(y=9)
                {
                    if(MatrizBarcos[x-1][y]=1||MatrizBarcos[x-1][y-1]=1) {
                        goto Ale;}
                    Matrizbarcos[x-1][y] = 2;
                    Matrizbarcos[x-1][y-1]=2;
                    for(int i=0; i<3; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Ale;
                        }
                        if(MatrizBarcos[x][y-1]=1)
                            { goto Ale;}
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x][y-1]=2;
                        x+=1;
                    }
                    if(MatrizBarcos[x+1][y]=1||MatrizBarcos[x+1][y-1]=1) {
                        goto Ale;}
                    Matrizbarcos[x+1][y] = 2;
                    Matrizbarcos[x+1][y-1]=2;
                }

                if(x=7)
                {
                    if(MatrizBarcos[x-1][y]=1||MatrizBarcos[x-1][y-1]=1) {
                        goto Ale;}
                    if(MatrizBarcos[x-1][y+1]=1)
                            { goto Ale;}
                    Matrizbarcos[x-1][y] = 2;
                    Matrizbarcos[x-1][y-1]=2;
                    Matrizbarcos[x-1][y+1]=2;
                    for(int i=0; i<3; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Ale;
                        }
                        if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x][y+1]=1)
                            { goto Ale;}
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x][y-1]=2;
                        MatrizBarcos[x][y+1]=2;
                        x+=1;
                    }
                }


                if(MatrizBarcos[x-1][y]=1||MatrizBarcos[x-1][y+1]=1) {
                    goto Ale;}
                if(MatrizBarcos[x-1][y-1]=1)
                    {
                    goto Ale;
                    }
                Matrizbarcos[x-1][y] = 2;
                Matrizbarcos[x-1][y-1]=2;
                Matrizbarcos[x-1][y+1]=2;
                for(int i=0; i<3; i++) {
                    if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                        goto Ale;
                    }
                    if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x][y+1]=1)
                        { goto Ale;}
                    Matrizbarcos[x][y] = 1;
                    Matrizbarcos[x][y+1]=2;
                    Matrizbarcos[x][y-1]=2;
                    x+=1;
                }
                if(MatrizBarcos[x+1][y]=1||MatrizBarcos[x+1][y+1]=1) {
                    goto Ale;}
                if(MatrizBarcos[x+1][y-1]=1)
                {
                    goto Ale;
                }
                Matrizbarcos[x+1][y] = 2;
                Matrizbarcos[x+1][y-1]=2;
                Matrizbarcos[x+1][y+1]=2;

                //printf("El barco de 3 Vertical comienza en (%d,%d)\n", x, y);
                break;
            case 2:
                y = rand() %10;
                x = rand() %9;
                Alea:
                if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                    goto Alea;
                }

                if(x=0&&y=0)
                {
                    for(int i=0; i<2; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Alea;
                        }
                        if(MatrizBarcos[x][y+1]=1)
                        {
                            goto Alea;
                        }
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x][y+1] = 2;
                        x+=1;
                    }
                    if(MatrizBarcos[x+1][y+1]=1||MatrizBarcos[x+1][y]=1)
                    {
                        goto Alea;
                    }
                    Matrizbarcos[x+1][y+1] = 2;
                    Matrizbarcos[x+1][y] = 2;
                }

                if(x=0)
                {
                    for(int i=0; i<2; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Alea;
                        }
                        if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x][y+1]=1)
                        {
                            goto Alea;
                        }
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x][y-1] = 2;
                        Matrizbarcos[x][y+1] = 2;
                        x+=1;
                    }
                    if(MatrizBarcos[x+1][y+1]=1||MatrizBarcos[x+1][y]=1) {
                        goto Alea;}
                    if(MatrizBarcos[x+1][y-1]=1)
                    {
                        goto Alea;
                    }
                    Matrizbarcos[x+1][y-1] = 2;
                    Matrizbarcos[x+1][y+1] = 2;
                    Matrizbarcos[x+1][y] = 2;
                }


                if(y=0)
                {
                    if(MatrizBarcos[x-1][y]=1||MatrizBarcos[x-1][y+1]=1) {
                        goto Alea;}
                    Matrizbarcos[x-1][y+1] = 2;
                    Matrizbarcos[x-1][y]=2;
                    for(int i=0; i<2; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Alea;
                        }
                        if(MatrizBarcos[x][y+1]=1)
                        {
                            goto Alea;
                        }
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x][y+1] = 2;
                        x+=1;
                    }
                    if(MatrizBarcos[x+1][y+1]=1||MatrizBarcos[x+1][y]=1)
                    {
                        goto Alea;
                    }
                    Matrizbarcos[x+1][y+1] = 2;
                    Matrizbarcos[x+1][y] = 2;
                }

                 if(x=0&&y=9)
                {
                    for(int i=0; i<2; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Alea;}
                        if(MatrizBarcos[x][y-1]=1)
                            { goto Alea;}
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x][y-1]=2;
                        x+=1;
                    }
                    if(MatrizBarcos[x+1][y]=1||MatrizBarcos[x+1][y-1]=1) {
                        goto Alea;
                    }
                    Matrizbarcos[x+1][y] = 2;
                    Matrizbarcos[x+1][y-1]=2;
                }

                if(x=8&&y=9)
                {
                    if(MatrizBarcos[x-1][y]=1||MatrizBarcos[x-1][y-1]=1) {
                        goto Alea;}
                    Matrizbarcos[x-1][y] = 2;
                    Matrizbarcos[x-1][y-1]=2;
                    for(int i=0; i<2; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Alea;
                        }
                        if(MatrizBarcos[x][y-1]=1)
                            { goto Alea;}
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x][y-1]=2;
                        x+=1;
                    }
                }

                if(x=8&&y=0)
                {
                    if(MatrizBarcos[x-1][y+1]=1||MatrizBarcos[x-1][y]=1) {
                        goto Alea;
                        }
                    Matrizbarcos[x-1][y] = 2;
                    Matrizbarcos[x-1][y+1] = 2;
                    for(int i=0; i<2; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Alea;
                        }
                        if(MatrizBarcos[x][y+1]=1)
                        {
                            goto Alea;
                        }
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x][y+1] = 2;
                        x+=1;
                    }
                }

                if(y=9)
                {
                    if(MatrizBarcos[x-1][y]=1||MatrizBarcos[x-1][y-1]=1) {
                        goto Alea;}
                    Matrizbarcos[x-1][y] = 2;
                    Matrizbarcos[x-1][y-1]=2;
                    for(int i=0; i<2; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Alea;
                        }
                        if(MatrizBarcos[x][y-1]=1)
                            { goto Alea;}
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x][y-1]=2;
                        x+=1;
                    }
                    if(MatrizBarcos[x+1][y]=1||MatrizBarcos[x+1][y-1]=1) {
                        goto Alea;}
                    Matrizbarcos[x+1][y] = 2;
                    Matrizbarcos[x+1][y-1]=2;
                }

                if(x=8)
                {
                    if(MatrizBarcos[x-1][y]=1||MatrizBarcos[x-1][y-1]=1) {
                        goto Alea;}
                    if(MatrizBarcos[x-1][y+1]=1)
                            { goto Alea;}
                    Matrizbarcos[x-1][y] = 2;
                    Matrizbarcos[x-1][y-1]=2;
                    Matrizbarcos[x-1][y+1]=2;
                    for(int i=0; i<2; i++) {
                        if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                            goto Alea;
                        }
                        if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x][y+1]=1)
                            { goto Alea;}
                        Matrizbarcos[x][y] = 1;
                        Matrizbarcos[x][y-1]=2;
                        MatrizBarcos[x][y+1]=2;
                        x+=1;
                    }
                }


                if(MatrizBarcos[x-1][y]=1||MatrizBarcos[x-1][y+1]=1) {
                    goto Alea;}
                if(MatrizBarcos[x-1][y-1]=1)
                    {
                    goto Alea;
                    }
                Matrizbarcos[x-1][y] = 2;
                Matrizbarcos[x-1][y-1]=2;
                Matrizbarcos[x-1][y+1]=2;
                for(int i=0; i<2; i++) {
                    if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                        goto Alea;
                    }
                    if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x][y+1]=1)
                        { goto Alea;}
                    Matrizbarcos[x][y] = 1;
                    Matrizbarcos[x][y+1]=2;
                    Matrizbarcos[x][y-1]=2;
                    x+=1;
                }
                if(MatrizBarcos[x+1][y]=1||MatrizBarcos[x+1][y+1]=1) {
                    goto Alea;}
                if(MatrizBarcos[x+1][y-1]=1)
                {
                    goto Alea;
                }
                Matrizbarcos[x+1][y] = 2;
                Matrizbarcos[x+1][y-1]=2;
                Matrizbarcos[x+1][y+1]=2;
                //printf("El barco de 2 Vertical comienza en (%d,%d)\n", x, y);
                break;
            case 1:
                y = rand() %10;
                x = rand() %10;
                Aleat:
                if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                    goto Aleat;
                }

                if(x=0&&y=0)
                {
                    if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                        goto Aleat;
                        }
                    if(MatrizBarcos[x+1][y]=1)
                    {
                    goto Aleat;
                    }
                    Matrizbarcos[x][y] = 1;
                    Matrizbarcos[x+1][y] = 2;
                    if(MatrizBarcos[x][y+1]=1||MatrizBarcos[x+1][y+1]=1)
                    {
                    goto Aleat;
                    }
                    Matrizbarcos[x][y+1] = 2;
                    Matrizbarcos[x+1][y+1] = 2;
                }

                if(x=0&&y=9)
                {
                    if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x+1][y-1]=1) {
                        goto Aleat;}
                    Matrizbarcos[x][y-1] = 2;
                    Matrizbarcos[x+1][y-1]=2;
                    if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                        goto Aleat;
                    }
                    if(MatrizBarcos[x+1][y]=1)
                        { goto Aleat;}
                    Matrizbarcos[x][y] = 1;
                    Matrizbarcos[x+1][y]=2;
                }

                if(x=9&&y=9)
                {
                    if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x-1][y-1]=1) {
                        goto Aleat;}
                    Matrizbarcos[x][y-1] = 2;
                    Matrizbarcos[x-1][y-1]=2;
                    if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                        goto Aleat;
                    }
                    if(MatrizBarcos[x-1][y]=1)
                        { goto Aleat;}
                    Matrizbarcos[x][y] = 1;
                    Matrizbarcos[x-1][y]=2;
                }

                if(x=9&&y=0)
                {
                    if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                        goto Aleat;
                        }
                    if(MatrizBarcos[x-1][y]=1)
                    {
                        goto Aleat;
                    }
                    Matrizbarcos[x][y] = 1;
                    Matrizbarcos[x-1][y] = 2;
                    if(MatrizBarcos[x][y+1]=1||MatrizBarcos[x-1][y+1]=1)
                    {
                        goto Aleat;
                    }
                    Matrizbarcos[x][y+1] = 2;
                    Matrizbarcos[x-1][y+1] = 2;
                }


                if(y=9)
                {
                    if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x+1][y-1]=1) {
                        goto Aleat;}
                    if(MatrizBarcos[x-1][y-1]=1)
                    {
                    goto Aleat;
                    }
                    Matrizbarcos[x][y-1] = 2;
                    Matrizbarcos[x+1][y-1]=2;
                    Matrizbarcos[x-1][y-1]=2;
                    if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                        goto Aleat;
                    }
                    if(MatrizBarcos[x-1][y]=1||MatrizBarcos[x+1][y]=1)
                        { goto Aleat;}
                    Matrizbarcos[x][y] = 1;
                    Matrizbarcos[x+1][y]=2;
                    Matrizbarcos[x-1][y]=2;
                }

                if(x=0)
                {
                    if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x-1][y-1]=1) {
                        goto Aleat;}
                    Matrizbarcos[x][y-1] = 2;
                    Matrizbarcos[x-1][y-1]=2;
                    if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                        goto Aleat;
                    }
                    if(MatrizBarcos[x-1][y]=1)
                    {
                        goto Aleat;
                    }
                    Matrizbarcos[x][y] = 1;
                    Matrizbarcos[x-1][y] = 2;
                    if(MatrizBarcos[x][y+1]=1||MatrizBarcos[x-1][y+1]=1)
                    {
                        goto Aleat;
                    }
                    Matrizbarcos[x][y+1] = 2;
                    Matrizbarcos[x-1][y+1] = 2;
                }

                if(y=0)
                {
                    if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                        goto Aleat;
                    }
                    if(MatrizBarcos[x-1][y]=1||MatrizBarcos[x+1][y]=1)
                    {
                        goto Aleat;
                    }
                    Matrizbarcos[x][y] = 1;
                    Matrizbarcos[x-1][y] = 2;
                    Matrizbarcos[x+1][y] = 2;
                    if(MatrizBarcos[x][y+1]=1||MatrizBarcos[x+1][y+1]=1) {
                        goto Aleat;}
                    if(MatrizBarcos[x-1][y+1]=1)
                    {
                        goto Aleat;
                    }
                    Matrizbarcos[x][y+1] = 2;
                    Matrizbarcos[x-1][y+1] = 2;
                    Matrizbarcos[x+1][y+1] = 2;
                }

                if(x=9)
                {
                    if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x-1][y-1]=1) {
                        goto Aleat;}
                    Matrizbarcos[x][y-1] = 2;
                    Matrizbarcos[x-1][y-1]=2;
                    if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                        goto Aleat;
                    }
                    if(MatrizBarcos[x-1][y]=1)
                    {
                        goto Aleat;
                    }
                    Matrizbarcos[x][y] = 1;
                    Matrizbarcos[x-1][y] = 2;
                    if(MatrizBarcos[x][y+1]=1||MatrizBarcos[x-1][y+1]=1)
                    {
                        goto Aleat;
                    }
                    Matrizbarcos[x][y+1] = 2;
                    Matrizbarcos[x-1][y+1] = 2;
                }


                if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x+1][y-1]=1) {
                    goto Aleat;}
                if(MatrizBarcos[x-1][y-1]=1)
                {
                    goto Aleat;
                }
                Matrizbarcos[x][y-1] = 2;
                Matrizbarcos[x+1][y-1]=2;
                Matrizbarcos[x-1][y-1]=2;
                if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                    goto Aleat;
                }
                if(MatrizBarcos[x-1][y]=1||MatrizBarcos[x+1][y]=1)
                    { goto Aleat;}
                Matrizbarcos[x][y] = 1;
                Matrizbarcos[x+1][y]=2;
                Matrizbarcos[x-1][y]=2;
                if(MatrizBarcos[x][y+1]=1||MatrizBarcos[x+1][y+1]=1) {
                    goto Aleat;}
                if(MatrizBarcos[x-1][y+1]=1)
                {
                    goto Aleat;
                }
                Matrizbarcos[x][y+1] = 2;
                Matrizbarcos[x+1][y+1]=2;
                Matrizbarcos[x-1][y+1]=2;

                if(esEspecial=1)
                {
                    Matrizbarcos[x][y] = 3;
                }
                //printf("El barco de 1 Vertical comienza en (%d,%d)\n", x, y);
                break;
            default:
                printf("El tamano del barco es incorrecto\n");
                break;
        }

    }

}

void rellenarTodosLosBarcos(int MatrizBarcos[][10]){
    rellenarBarco(4, 0, MatrizBarcos[][10]);
    for (int i=0; i<3; i++) {
        rellenarBarco(3, 0, MatrizBarcos[][10]);
    }
    for (int i=0; i<3; i++) {
        rellenarBarco(2,0, MatrizBarcos[][10]);
    }
    rellenarBarco(1,0, MatrizBarcos[][10]);
    rellenarBarco(1,1, MatrizBarcos[][10]);
}

int sucoordenada(int fi, int co, int SuMatriz[][10], int TuMatriz[][10])
{
    SuMatriz[fi][co] = 1
    if(SuMatriz[fi][co] == TuMatriz[fi][co])
    {
        printf("Te han dado a un barco, este es su resultado:\n")
        imprimirMatrizdeBarcos(SuMatriz, 10, 10);
        return 1;
    }
    else{
    if(TuMatriz[fi][co]=3)
    {
        Printf("Te han dañado al barco especial, este es su resultado:\n");
        imprimirMatrizdeBarcos(SuMatriz, 10, 10);
        return 1;
        //Entramos aqui en el modo batalla especial entre barcos.
    }
        Printf("No te han dañado ningun barco, este es su resultado:\n")
        SuMatriz[fi][co] = 2
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
    tuMatriz[numero][y] = 1
    if(tuMatriz[numero][y] == suMatriz[numero][y])
    {
        printf("Has dado a un barco, este es tu resulatdo:\n");
        imprimirMatrizdeBarcos(tuMatriz, 10, 10);
        return 1;
    }
    else{
    if(suMatriz[numero][y]=3)
    {
        Printf("Has dañado al barco especial, este es tu resultado:\n");
        imprimirMatrizdeBarcos(tuMatriz, 10, 10);
        return 1;
        //Entramos aqui en el modo batalla especial entre barcos.
    }
        Printf("No has dañado ningun barco, este es tu resultado:");
        tuMatriz[numero][y] = 2
        imprimirMatrizdeBarcos(tuMatriz, 10, 10);
        return 0;
    }

}

char cambio (int MatBarcos[][10], int x, int y)
{
    for (int i=0; i<x; i++) {
        for(int j=0; j<y; j++) {
            if(MatrizBarcos[i][j]=0)
            {
                MatrizBarcos[i][j]=2;
            }
        }

    for (int i=0; i<x; i++) {
        for(int j=0; j<y; j++) {
            switch(MatBarcos[i][j])
            {
                case 1:

            }
        }
}
}
