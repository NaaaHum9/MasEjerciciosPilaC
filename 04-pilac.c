#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100
#define TRUE 1
#define FALSE 0

/**
 * 4. Write a program that accepts a string and reverse it using a stack. &gt;
Expected Output:
Input a string: w3resource
Reversed string using a stack is: ecruoser3w
*/

typedef struct {
    char items[TAM];
    int tope;
} Stack;

typedef Stack* STACK;

STACK initStack();
int isEmpty(STACK S);
bool isFull(STACK S);
void push(STACK S, char value);
char pop(STACK S);
void liberarMem(STACK S);
void invertirCadena(STACK S, char* cadena);

int main() {
    STACK S;
    S = initStack();
    char cadena[TAM];

    printf("Ingrese una cadena: ");
    fgets(cadena, TAM, stdin);

    invertirCadena(S, cadena);

    printf("Cadena invertida: %s\n", cadena);

    liberarMem(S);
}

STACK initStack() {
    STACK S;
    S = (STACK) malloc(sizeof(Stack));
    if (S == NULL) {
        exit(0);
    }
    S->tope = -1;
    return S;
}

int isEmpty(STACK S) {
    if (S->tope == -1) {
        return TRUE;
    }
    return FALSE;
}

bool isFull(STACK S) {
    return S->tope == TAM - 1;
}

void push(STACK S, char value) {
    if (isFull(S)) {
        exit(0);
    }
    (S->tope)++;
    S->items[S->tope] = value;
}

char pop(STACK S) {
    char aux;
    if (isEmpty(S)) {
        exit(0);
    }
    aux = S->items[S->tope];
    (S->tope)--;
    return aux;
}

void liberarMem(STACK S) {
    free(S);
}

void invertirCadena(STACK S, char* cadena) {
    int longitud = strlen(cadena);
    if (cadena[longitud - 1] == '\n') {
        cadena[longitud - 1] = '\0';  // Eliminar el carácter de nueva línea
        longitud--;
    }

    for (int i = 0; i < longitud; i++) {
        push(S, cadena[i]);
    }

    for (int i = 0; i < longitud; i++) {
        cadena[i] = pop(S);
    }
}
