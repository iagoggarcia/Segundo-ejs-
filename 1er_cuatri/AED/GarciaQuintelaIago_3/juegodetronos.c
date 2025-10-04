#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "juegodetronos.h"

#define NAME_LENGTH 20

void anhadirPersonaje(TABB *arbol) {
    TIPOELEMENTOABB personaje;
    char tipoPersonaje;
    unsigned short real;
    char parent[NAME_LENGTH], sibling[NAME_LENGTH], murdered[NAME_LENGTH], married[NAME_LENGTH];

    getchar();

    // Pregunto el nombre
    printf("Nombre: ");
    fgets(personaje.name, sizeof(personaje.name), stdin);
    personaje.name[strcspn(personaje.name, "\n")] = '\0';

    // Comprobación de que no existe en el árbol
    TIPOELEMENTOABB aux;
    strcpy(aux.name, personaje.name);
    if (esMiembroAbb(*arbol, aux)) {
        printf("Error, el personaje ya ha sido creado\n");
        return;
    }

    // Pido el tipo de personaje y hago un switch para guardar el tipo en función de la opción elegida como entrada
    do {
        printf("Tipo de personaje (1: persona, 2: gigante, 3: lobo, 4: dragon, 5: criatura): ");
        scanf(" %c", &tipoPersonaje);
        switch (tipoPersonaje) {
        case '1':
            strcpy(personaje.character_type, "persona");        
            break;
        case '2':
            strcpy(personaje.character_type, "gigante");
            break;
        case '3':
            strcpy(personaje.character_type, "lobo");
            break;
        case '4':
            strcpy(personaje.character_type, "dragon");
            break;
        case '5':
            strcpy(personaje.character_type, "criatura");
            break;
        }
    } while (tipoPersonaje != '1' && tipoPersonaje != '2' && tipoPersonaje != '3' && tipoPersonaje != '4' && tipoPersonaje != '5');
    
    getchar(); // limpiar buffer después del scanf del tipo de personaje

    // Pregunto la casa
    printf("Casa (- si desconocido): ");
    fgets(personaje.house, sizeof(personaje.house), stdin);
    personaje.house[strcspn(personaje.house, "\n")] = '\0'; // borro el fin de cadena del fgets

    // Pregunto si es de la realeza
    do {
        printf("Realeza (0/1): ");
        scanf("%hu", &real);
        if (real != 0 && real != 1)
            printf("Error, el valor debe ser 0 o 1\n");
    } while (real != 0 && real != 1);
    personaje.royal = real;

    getchar(); // limpio el buffer tras scanf

    // Pido los padres
    crearLista(&personaje.parents);
    TIPOELEMENTOLISTA pariente;
    do {
        printf("Padre/s (fin para parar): ");
        fgets(parent, sizeof(parent), stdin);
        parent[strcspn(parent, "\n")] = '\0';
        if (strcmp(parent, "fin") != 0) {
            strcpy(pariente.name, parent);
            insertarElementoLista(&personaje.parents, finLista(personaje.parents), pariente);
        }
    } while (strcmp(parent, "fin") != 0);

    // Pido los hermanos
    crearLista(&personaje.siblings);
    TIPOELEMENTOLISTA hermano;
    do {
        printf("Hermano/a (fin para parar): ");
        fgets(sibling, sizeof(sibling), stdin);
        sibling[strcspn(sibling, "\n")] = '\0';
        if (strcmp(sibling, "fin") != 0) {
            strcpy(hermano.name, sibling);
            insertarElementoLista(&personaje.siblings, finLista(personaje.siblings), hermano);
        }
    } while (strcmp(sibling, "fin") != 0);

    // Pido a los que mató
    crearLista(&personaje.killed);
    TIPOELEMENTOLISTA asesinado;
    do {
        printf("Mató a (fin para parar): ");
        fgets(murdered, sizeof(murdered), stdin);
        murdered[strcspn(murdered, "\n")] = '\0';
        if (strcmp(murdered, "fin") != 0) {
            strcpy(asesinado.name, murdered);
            insertarElementoLista(&personaje.killed, finLista(personaje.killed), asesinado);
        }
    } while (strcmp(murdered, "fin") != 0);

    // Pido la persona con la que está casado o comprometido
    crearLista(&personaje.marriedEngaged);
    TIPOELEMENTOLISTA casado;
    do {
        printf("Casado/a o comprometido/a con (fin para parar): ");
        fgets(married, sizeof(married), stdin);
        married[strcspn(married, "\n")] = '\0';
        if (strcmp(married, "fin") != 0) {
            strcpy(casado.name, married);
            insertarElementoLista(&personaje.marriedEngaged, finLista(personaje.marriedEngaged), casado);
        }
    } while (strcmp(married, "fin") != 0);

    // Pido la descripción
    printf("Descripción: ");
    fgets(personaje.description, sizeof(personaje.description), stdin);
    personaje.description[strcspn(personaje.description, "\n")] = '\0';

    insertarElementoAbb(arbol, personaje);
    printf("Personaje añadido\n");
}


void _imprimirLista(TLISTA lista) {
    TPOSICION pos = primeroLista(lista);
    TIPOELEMENTOLISTA e;
    while (pos != finLista(lista)) {
        recuperarElementoLista(lista, pos, &e);
        printf("%s, ", e.name);
        pos = siguienteLista(lista, pos);
    }
}

void _imprimirPersonaje(TIPOELEMENTOABB personaje) {
    printf("\nNombre: %s", personaje.name);
    printf("\nTipo de personaje: %s", personaje.character_type);
    printf("\nCasa: %s", personaje.house);
    printf("\nPadres: ");
    _imprimirLista(personaje.parents);
    printf("\nHermanos: ");
    _imprimirLista(personaje.siblings);
    printf("\nMató a: ");
    _imprimirLista(personaje.killed);
    printf("\nCasado/a o comprometido/a: ");
    _imprimirLista(personaje.marriedEngaged);
    printf("\nDescription: %s", personaje.description);
}

void listadoPersonajes(TABB arbol) {
    if (esAbbVacio(arbol)) {
        return;
    }

    listadoPersonajes(izqAbb(arbol));

    TIPOELEMENTOABB personaje;
    leerElementoAbb(arbol, &personaje);
    _imprimirPersonaje(personaje);

    listadoPersonajes(derAbb(arbol));
}


void eliminarPersonaje(TABB *arbol) {
    TIPOELEMENTOABB aux;

    printf("Nombre del personaje: ");
    scanf(" %s", aux.name);
    if (esMiembroAbb(*arbol, aux)) {
        suprimirElementoAbb(arbol, aux);
        printf("El personaje %s ha sido eliminado\n", aux.name);
    }
    else {
        printf("Error, el personaje no existe\n");
    }
}