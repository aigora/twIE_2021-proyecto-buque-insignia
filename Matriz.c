#include <stdio.h>
#include <stdlib.h>
#include <Matriz.h>

int Matriz(int x) {
    int misBarcos[10][10] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};
    int cpuBarcos[10][10] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};
    int misbarcosrellenos [10][10];
    int misbarcosrellenos [10][10];

    rellenarTodosLosBarcos(misBarcos);
    rellenarTodosLosBarcos(cpuBarcos);

    printf("Tus barcos rellenados son los siguientes:\n");
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

void rellenarBarco(int tam, int esEspecial, int MatrizBarcos[][10]) {

    int i=0;
    //Miramos si es Horizontal (0) o Vertical (1)
    int direccion = rand() % 2;
    //printf("Direccion del barco vale %d\n", direccion);

    if (direccion == 0) {
        int x=0;
        int y=0;
         switch (size) {
            case 4:
                x = rand() %7;
                y = rand() %10;
                //printf("El barco de 4 Horizontal comienza en (%d,%d)\n", x, y);
                //En la matriz (1) significa barco, (2) agua y (0) casilla aun no rellenada.
                if(x=0&&y=0)
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
                Matrizbarcos[x-1][y-1]=2;
                for(int i=0; i<4; i++) {
                Matrizbarcos[x][y] = 1;
                Matrizbarcos[x-1][y] = 2;
                y+=1;
                }
                Matrizbarcos[x][y+1] = 2;
                Matrizbarcos[x-1][y+1] = 2;
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
                x = rand() %8;
                y = rand() %10;
                if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                goto Alt;
                }

                if(x=0&&y=0)
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
                if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x-1][y-1]=1) {
                goto Alt;}
                Matrizbarcos[x][y-1] = 2;
                Matrizbarcos[x-1][y-1]=2;
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
                }
                 //printf("El barco de 3 Horizontal comienza en (%d,%d)\n", x, y);
                break;
            case 2:
                x = rand() %9;
                y = rand() %10;
                Alto:
                x = rand() %8;
                y = rand() %10;
                if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                goto Alto;
                }

                if(x=0&&y=0)
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
                if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x-1][y-1]=1) {
                goto Alto;}
                Matrizbarcos[x][y-1] = 2;
                Matrizbarcos[x-1][y-1]=2;
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
                }
                // printf("El barco de 2 Horizontal comienza en (%d,%d)\n", x, y);
                break;
            case 1:
                x = rand() %10;
                y = rand() %10;
                Altor:
                x = rand() %8;
                y = rand() %10;
                if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                goto Altor;
                }

                if(x=0&&y=0)
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
                y = rand() %7;
                x = rand() %10;
                if(x=0&&y=0)
                {
                for(int i=0; i<4; i++) {
                Matrizbarcos[x][y] = 1;
                Matrizbarcos[x][y+1] = 2;
                x+=1;
                }
                Matrizbarcos[x+1][y] = 2;
                Matrizbarcos[x+1][y+1] = 2;
                }
                if(x=0)
                {
                for(int i=0; i<4; i++) {
                Matrizbarcos[x][y] = 1;
                Matrizbarcos[x][y-1] = 2;
                Matrizbarcos[x][y+1] = 2;
                x+=1;
                }
                Matrizbarcos[x+1][y] = 2;
                Matrizbarcos[x+1][y+1] = 2;
                Matrizbarcos[x+1][y-1] = 2;
                }

                if(y=0)
                {
                Matrizbarcos[x-1][y] = 2;
                Matrizbarcos[x-1][y+1]=2;
                for(int i=0; i<4; i++) {
                Matrizbarcos[x][y] = 1;
                Matrizbarcos[x][y+1] = 2;
                x+=1;
                }
                Matrizbarcos[x+1][y] = 2;
                Matrizbarcos[x+1][y+1] = 2;
                }

                Matrizbarcos[x-1][y] = 2;
                Matrizbarcos[x-1][y+1]=2;
                Matrizbarcos[x-1][y-1]=2;
                for(int i=0; i<4; i++) {
                Matrizbarcos[x][y] = 1;
                Matrizbarcos[x][y+1]=2;
                Matrizbarcos[x][y-1]=2;
                x+=1;
                }
                Matrizbarcos[x+1][y+1] = 2;
                Matrizbarcos[x+1][y]=2;
                Matrizbarcos[x-1][y-1]=2;
                //printf("El barco de 4 Vertical comienza en (%d,%d)\n", x, y);
                break;
            case 3:
                Ale:
                y = rand() %8;
                x = rand() %10;
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
                }
                //printf("El barco de 3 Vertical comienza en (%d,%d)\n", x, y);
                break;
            case 2:
                y = rand() %9;
                x = rand() %10;
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
                }
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
                if(MatrizBarcos[x][y+1]=1)
                {
                goto Aleat;
                }
                Matrizbarcos[x][y] = 1;
                Matrizbarcos[x][y+1] = 2;
                if(MatrizBarcos[x+1][y+1]=1||MatrizBarcos[x+1][y]=1)
                {
                goto Aleat;
                }
                Matrizbarcos[x+1][y+1] = 2;
                Matrizbarcos[x+1][y] = 2;
                }

                if(x=0)
                {
                if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                    goto Aleat;
                    }
                if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x][y+1]=1)
                {
                goto Aleat;
                }
                Matrizbarcos[x][y] = 1;
                Matrizbarcos[x][y-1] = 2;
                Matrizbarcos[x][y+1] = 2;
                if(MatrizBarcos[x+1][y+1]=1||MatrizBarcos[x+1][y]=1) {
                goto Aleat;}
                if(MatrizBarcos[x+1][y-1]=1)
                {
                goto Aleat;
                }
                Matrizbarcos[x+1][y-1] = 2;
                Matrizbarcos[x+1][y+1] = 2;
                Matrizbarcos[x+1][y] = 2;
                }


                if(y=0)
                {
                if(MatrizBarcos[x-1][y]=1||MatrizBarcos[x-1][y+1]=1) {
                goto Aleat;}
                Matrizbarcos[x-1][y+1] = 2;
                Matrizbarcos[x-1][y]=2;
                if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                    goto Aleat;
                    }
                 if(MatrizBarcos[x][y+1]=1)
                {
                goto Aleat;
                }
                Matrizbarcos[x][y] = 1;
                Matrizbarcos[x][y+1] = 2;
                 if(MatrizBarcos[x+1][y+1]=1||MatrizBarcos[x+1][y]=1)
                {
                goto Aleat;
                }
                Matrizbarcos[x+1][y+1] = 2;
                Matrizbarcos[x+1][y] = 2;
                }

                if(MatrizBarcos[x-1][y]=1||MatrizBarcos[x-1][y+1]=1) {
                goto Aleat;}
                if(MatrizBarcos[x-1][y-1]=1)
                {
                goto Aleat;
                }
                Matrizbarcos[x-1][y] = 2;
                Matrizbarcos[x-1][y-1]=2;
                Matrizbarcos[x-1][y+1]=2;
                if(MatrizBarcos[x][y]=1||MatrizBarcos[x][y]=2) {
                goto Aleat;
                }
                if(MatrizBarcos[x][y-1]=1||MatrizBarcos[x][y+1]=1)
                { goto Aleat;}
                Matrizbarcos[x][y] = 1;
                Matrizbarcos[x][y+1]=2;
                Matrizbarcos[x][y-1]=2;
                if(MatrizBarcos[x+1][y]=1||MatrizBarcos[x+1][y+1]=1) {
                goto Aleat;}
                if(MatrizBarcos[x+1][y-1]=1)
                {
                goto Aleat;
                }
                Matrizbarcos[x+1][y] = 2;
                Matrizbarcos[x+1][y-1]=2;
                Matrizbarcos[x+1][y+1]=2;
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

    for (int x=0; x<fila; x++) {
        for(int y=0; y<column; y++) {
            if(MatrizBarcos[x][y]=0)
            {
                MatrizBarcos[x][y]=2;
            }
        }
}

