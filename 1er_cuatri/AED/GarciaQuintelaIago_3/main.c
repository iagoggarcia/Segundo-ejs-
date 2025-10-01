#include <stdlib.h>
#include <stdio.h>
#include "juegodetronos.h"

int main (int argc, char *argv[]) {
    char opcion;
    TLISTA lista;
    crearLista(&lista);

    do {
        printf("--------MENÚ--------\n");
        printf("a) Añadir personaje\n");
        printf("l) Listado alfabético de personajes\n");
        printf("e) Eliminar personaje\n");        
        printf("s) Salir\n");
        printf("--------------------\n");
        printf("Introduce la opción: ");
        scanf(" %c", &opcion);
        switch (opcion) {
        case 'A': case 'a':
            anhadirPersonaje(&lista);
            break;
        case 'L': case 'l':
            
            break;
        case 'E': case 'e':
            
            break;
        case 'S': case 's':
            
            break;    
        default:
            break;
        }
    } while (opcion != 's' && opcion != 'S');
}