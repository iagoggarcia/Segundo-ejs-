#include <stdio.h>
#include <stdlib.h>
#include "FuncionesExpresion.h"
#include "recorridos.h"

int main(int argc, char *argv[]) {
    char expresion[20];
    abin arbolFinal;

    printf("Introduce la expresión matemática: \n");
    scanf("%s", expresion);

    arbolFinal = arbolExpresion(expresion);

    printf("Recorrido preorden (prefijo): \n");
    preorden(arbolFinal);

    printf("\nRecorrido postorden (postfijo): \n");
    postorden(arbolFinal);


    destruir(&arbolFinal);
    return EXIT_SUCCESS;
}