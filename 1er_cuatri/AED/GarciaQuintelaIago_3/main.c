#include <stdlib.h>
#include <stdio.h>
#include "juegodetronos.h"
#include "abb.h"

int main (int argc, char *argv[]) {
    char opcion;
    TLISTA lista;
    TABB arbol;
    crearLista(&lista);
    crearAbb(&arbol);

    do {
        printf("\n--------MENÚ--------\n");
        printf("a) Añadir personaje\n");
        printf("l) Listado alfabético de personajes\n");
        printf("e) Eliminar personaje\n");        
        printf("s) Salir\n");
        printf("--------------------\n");
        printf("Introduce la opción: ");
        scanf(" %c", &opcion);
        switch (opcion) {
        case 'A': case 'a':
            anhadirPersonaje(&arbol);
            break;
        case 'L': case 'l':
            listadoPersonajes(arbol);
            break;
        case 'E': case 'e':
            eliminarPersonaje(&arbol);
            break;
        case 'S': case 's':
            
            break;    
        default:
            break;
        }
    } while (opcion != 's' && opcion != 'S');
}