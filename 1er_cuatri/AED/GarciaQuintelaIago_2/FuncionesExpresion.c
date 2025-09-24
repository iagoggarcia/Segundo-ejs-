#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abin.h"
#include "pilaOperadores.h"
#include "pilaOperandos.h"

//Devuelve la prioridad del operador dentro de la pila.
//Prioridad('(')=0
int prioridadDentro(char op) {
    int prior;
    switch (op) {
        case '^': prior = 3;
            break;
        case '*': case '/': prior = 2;
            break;
        case '+': case '-': prior = 1;
            break;
        case '(': prior = 0; //nunca va a entrar en la pila, provoca vaciado
            break;
    }
    return prior;
}

//Devuelve la prioridad del operador fuera de la pila.
//Prioridad('(')=4
int prioridadFuera(char op) {
    int prior;
    switch (op) {
        case '^': prior = 3;
            break;
        case '*': case '/': prior = 2;
            break;
        case '+': case '-': prior = 1;
            break;
        case '(': prior = 4; //para que SIEMPRE entre en la pila
            break;
    }
    return prior;
}

//Devuelve 1 si c es un operador: +, -, /, *, ^, ()
unsigned esOperador(char c) {
    unsigned ope;
    switch (c) {
        case '^': case '*': case '/': case '+': case '-': case '(':
            ope = 1;
            break;
        default:
            ope = 0;
    }
    return ope;
}

//Devuelve 1 si c es un operando: mayúsculas y minúsculas
//completar para caracteres 0 a 9
unsigned esOperando(char c) {
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c>=48 && c<=57)) // añadido rango 0-9
        return 1;
    else
        return 0;
}

//Recibe una cadena de caracteres y devuelve el arbol de expresion
//DEBES ESCRIBIR ESTA FUNCIÓN
abin arbolExpresion(char *expr_infija) {
    pilaOperandos pila_operandos;
    pilaOperadores pila_operadores;
    abin arbolFinal;
    char c;

    // inicializo pilas de operandos y operadores
    crearPilaOperandos(&pila_operandos);
    crearPilaOperadores(&pila_operadores);

    // recorro cada carácter de la expresión infija
    for (int i = 0; i < strlen(expr_infija); i++) {
        c = expr_infija[i];

        if (esOperando(c)) { // si es un operando (número o variable)
            abin aux;
            crear(&aux);
            insizq(&aux, c);    // inserto el valor en el nodo
            pushOperandos(&pila_operandos, aux); // apilo el nodo en la pila de operandos
        }
        else if (esOperador(c)) { // Si es un operador (+, -, *, /)
            while (!esVaciaPilaOperadores(pila_operadores) && prioridadFuera(c) <= prioridadDentro(topeOperadores(pila_operadores))) { 
                abin aux;
                char caux;

                caux = topeOperadores(pila_operadores); // cojo el operador del tope
                popOperadores(&pila_operadores);       // desapilo

                crear(&aux);
                insizq(&aux, caux); // inserto el operador

                // creo e inserto subárboles con operandos de la pila
                abin der = topeOperandos(pila_operandos);
                insArbolder(&aux, der);
                popOperandos(&pila_operandos);

                abin izq = topeOperandos(pila_operandos);
                insArbolizq(&aux, izq);
                popOperandos(&pila_operandos);

                pushOperandos(&pila_operandos, aux);
            }

            pushOperadores(&pila_operadores, c);
        }
        else if (c == ')') { // si es paréntesis de cierre
            // repetir hasta encontrar '('
            while (topeOperadores(pila_operadores) != '(') {
                abin aux;
                char caux;
                caux = topeOperadores(pila_operadores);
                popOperadores(&pila_operadores);

                crear(&aux);
                insizq(&aux, caux);

                abin der = topeOperandos(pila_operandos);
                insArbolder(&aux, der);
                popOperandos(&pila_operandos);

                abin izq = topeOperandos(pila_operandos);
                insArbolizq(&aux, izq);
                popOperandos(&pila_operandos);

                pushOperandos(&pila_operandos, aux);
            }
            popOperadores(&pila_operadores); // desapilo '('
        }
    }

    // proceso los operadores que quedan en la pila
    while (!esVaciaPilaOperadores(pila_operadores)) {
        abin aux;
        char caux;
        caux = topeOperadores(pila_operadores);
        popOperadores(&pila_operadores);

        crear(&aux);
        insizq(&aux, caux);

        abin der = topeOperandos(pila_operandos);
        insArbolder(&aux, der);
        popOperandos(&pila_operandos);

        abin izq = topeOperandos(pila_operandos);
        insArbolizq(&aux, izq);
        popOperandos(&pila_operandos);

        pushOperandos(&pila_operandos, aux);
    }

    // destruyo pilas, obtengo y devuelvo el árbol final
    destruirPilaOperadores(&pila_operadores);

    arbolFinal = topeOperandos(pila_operandos);
    destruirPilaOperandos(&pila_operandos);

    return arbolFinal;
}


