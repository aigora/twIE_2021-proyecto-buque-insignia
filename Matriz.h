#ifndef HEADER_C6001551DA4DAD80
#define HEADER_C6001551DA4DAD80

int Matriz(int x);
void imprimirMatrizdeBarcos(int matrizBarcos[][10], int fila, int column);
void rellenarBarco(int tam, int fila, int columna, int direccion, int esEspecial, int matrizBarcos[][10]);
void rellenarTodosLosBarcos(int matrizBarcos[][10]);
int comprobarCabeBarco(int tam, int fila, int columna, int direccion, int matrizBarcos[][10]);
int sucoordenada(int fi, int co, int SuMatriz[][10], int TuMatriz[][10]);
int tucoordenada(int columna, int fila, int son, int tuMatriz[][10], int suMatriz[][10]);
int traducirletra(char letra);
void ganador(int tu, int cpu);

#endif // header guard

