#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesTexto.h"
#include "estructuras.h"
#include "funcionesModoBatalla.h"

int main()
{
    int result;
    result = calculoDificultad();
    printf("%f", result);
    return 0;
}