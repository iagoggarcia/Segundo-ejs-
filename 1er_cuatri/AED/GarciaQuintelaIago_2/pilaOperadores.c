#include <stdlib.h>

//Implementacion TAD pila

//CONTENIDO DE CADA ELEMENTO DE LA PILA
//MODIFICAR: PARA LA PILA DE OPERADORES: char
//MODIFICAR: PARA LA PILA DE OPERANDOS: abin
typedef char tipoelemPilaOperadores;
///////////////////////////////////////////////////////

//Definicion del tipo de datos pila
struct tipo_celda_operadores {
    tipoelemPilaOperadores elemento;
    struct tipo_celda_operadores * sig;
};

typedef struct tipo_celda_operadores * pila;
/////////////////////////////////////////////////////////

void crearPilaOperadores(pila *P) {
    *P = NULL;
}

void destruirPilaOperadores(pila *P) {
    pila aux;
    aux = *P;
    while (aux != NULL) {
        aux = aux->sig;
        free(*P);
        *P = aux;
    }
}

unsigned esVaciaPilaOperadores(pila P) {
    return P == NULL;
}

tipoelemPilaOperadores topeOperadores(pila P) {
    if (!esVaciaPilaOperadores(P)) /*si pila no vacia*/
        return P->elemento;
}

void pushOperadores(pila *P, tipoelemPilaOperadores E) {
    pila aux;
    aux = (pila) malloc(sizeof (struct tipo_celda_operadores));
    aux->elemento = E;
    aux->sig = *P;
    *P = aux;
}

void popOperadores(pila *P) {
    pila aux;
    if (!esVaciaPilaOperadores(*P)) /*si pila no vacia*/ {
        aux = *P;
        *P = (*P)->sig;
        free(aux);
    }
}
