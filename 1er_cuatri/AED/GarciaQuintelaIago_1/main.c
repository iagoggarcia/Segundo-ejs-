/* Practica 1: Prueba de manejo de Arboles Binarios  */
#include <stdlib.h>
#include <stdio.h>

#include "abin.h"
#include "recorridos.h"
#include "funcionesArboles.h"

int main(int argc, char** argv) {
    abin Arbol, aux = NULL;
    tipoelem inf;

    crear(&Arbol);
    printf("Árbol creado\n");

    insizq(&Arbol, 'J'); // creo la raíz

    insder(&Arbol, 'M'); // inserto hijo por la derecha de la raíz

    aux = der(Arbol);
    insder(&aux, 'W'); // inserto hijo por la derecha del nodo M

    insizq(&Arbol, 'F'); // inserto hijo por la izquierda de la raíz

    insizq(&aux, 'K'); // inserto hijo por la izquierda del nodo M

    aux = izq(Arbol);
    insizq(&aux, 'D'); // inserto hijo por la izquierda del nodo F

    aux = izq(izq(Arbol));
    insizq(&aux, 'B'); // inserto hijo por la izquierda del nodo D
    
    insder(&aux, 'E'); // inserto hijo por la derecha del nodo D

    aux = izq(Arbol);
    insder(&aux, 'G'); // inserto hijo por la derecha del nodo F

    aux = der(izq(Arbol));
    insder(&aux, 'H'); // inserto hijo por la derecha del nodo G

    printf("Altura de árbol: %d\n", AlturaArbol(Arbol)); // muestro la altura del árbol, debe ser 4

    printf("Inorden no recursivo (usa pilas): ");
    inordenNR(Arbol); // muestro el recorrido inorden no recursivo

    /*
    aux = izq(Arbol); // me sitúo en el nodo F
    supder(&aux); // elimino el subárbol derecho de F (nodos G y H)
    printf("Árbol derecho de F eliminado\n");
    */

    printf("\nIntroduce el nodo a buscar para eliminar su subárbol derecho: "); // pido el nodo del que se quiere eliminar el subárbol derecho
    scanf(" %c", &inf);
    aux = NULL;
    buscar(Arbol, inf, &aux); // lo busco con la función creada
    if (aux == NULL) {
        printf("Nodo %c no encontrado en el árbol\n", inf); // si no lo encuentra, muestro mensaje de error y salgo
        destruir(&Arbol); // destruyo el árbol antes de salir
        return EXIT_FAILURE;
    }
    else {
        supder(&aux); // si lo encuentro, elimino su subárbol derecho
        printf("Subárbol derecho del nodo %c eliminado\n", inf);
    }

    printf("Recorrido InOrden (IRD): ");
    inorden(Arbol); // vuelvo a mostrar el recorrido inorden, ahora sin los nodos G y H
    
    printf("\nAltura de arbol: %d\n", AlturaArbol(Arbol)); //vuelvo a mostrar la altura del árbol, todavía debe ser 4
    printf("N nodos: %d\n", NumeroNodos(Arbol)); // muestro el número de nodos del árbol, debe ser 8

    destruir(&Arbol);

    return (EXIT_SUCCESS);
}