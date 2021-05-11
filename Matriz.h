#include <Matriz.h>

void imprimirMatrizdeBarcos(int MatBarcos[][10], int fila, int column);
void rellenarBarco(int tam, int esEspecial, int MatrizBarcos[][10]);
void rellenarTodosLosBarcos(int MatrizBarcos[][10]);
void ganador(int tu, int cpu);
int tucoordenada(char letra, int numero, int tuMatriz[][10], int suMatriz[][10]);
int sucoordenada(int fi, int co, int SuMatriz[][10], int TuMatriz[][10]);
