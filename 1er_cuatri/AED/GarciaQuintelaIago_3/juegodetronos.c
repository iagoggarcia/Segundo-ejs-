#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "juegodetronos.h"
#include "lista.h"
#include "abb.h"

#define NAME_LENGTH 20

void anhadirPersonaje(TLISTA *lista) {
    TIPOELEMENTOABB *personaje;
    char tipoPersonaje;
    unsigned short real;
    char parent[NAME_LENGTH];

    // Pregunto el nombre
    printf("Nombre: ");
    scanf(" %s", personaje->name);


    // Pido el tipo de personaje y hago un switch para guardar el tipo en función de la opción elegida como entrada
    do {
        printf("Tipo de personaje: (1: persona, 2: gigante, 3: lobo, 4: dragon, 5: criatura)");
        scanf (" %c", &tipoPersonaje);
        switch (tipoPersonaje) {
        case '1':
            strcpy("persona", personaje->character_type);        
            break;
        case '2':
            strcpy("gigante", personaje->character_type);
            break;
        case '3':
            strcpy("lobo", personaje->character_type);
            break;
        case '4':
            strcpy("dragon", personaje->character_type);
            break;
        case '5':
            strcpy("criatura", personaje->character_type);
        }
    } while (tipoPersonaje != '1' && tipoPersonaje != '2' && tipoPersonaje != '3' && tipoPersonaje != '4' && tipoPersonaje != '5');

    // Pregunto la casa
    printf("Casa (- si desconocido): ");
    scanf(" %s", &personaje->house);

    // Pregunto si es de la realeza
    do {
        printf("Realeza (0/1): ");
        scanf("%hu", &real);

        if (real != 0 && real != 1) {
            printf("Error, el valor debe ser 0 o 1: ");
        }
        
    } while (real != 0 && real != 1);
    personaje->royal = real;


    // Pido los padres
    crearLista(&personaje->parents);
    TIPOELEMENTOLISTA pariente;

    do {
        printf("Padre/s: ");
        scanf(" %s", parent);

        if ((strcmp(parent, "fin") < 0) || (strcmp(parent, "fin") > 0)) {
            strcpy(pariente.name, parent);
            insertarElementoLista(&personaje->parents, finLista(personaje->parents), pariente);
        }

    } while ((strcmp(parent, "fin") < 0) || (strcmp(parent, "fin") > 0));
}