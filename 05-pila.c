#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define TAM 100
#define TRUE 1
#define FALSE 0

/**
 * 5. Write a program to implement two stacks in a single array and performs
push and pop operations for both stacks. &gt;
Expected Output:
Elements in Stack-1 are: 50 40 30 10
Elements in Stack-2 are: 70 60 50 40 20
*/

typedef struct{
    int items[TAM];
    int tope;
}Stack;

typedef Stack* STACK;

STACK initStack();
int isEmpty(STACK S);
bool isFull(STACK S);
void push(STACK S, int value);
int pop(STACK S);
void liberarMem(STACK S, STACK S1);
void datosStack(STACK S);
void mostrarStack(STACK S, STACK S2);
int copiaStack(STACK S, STACK S2);

int main() {
    STACK S, S2;
    S = initStack();
    S2 = initStack();

    int selec=0;

    printf("Tamanio de la pila: %d\n", TAM);
    do{
        printf("\nSeleccione una opcion\n");
        printf("1 - Igresar elemento a stack 1 \n");
        printf("2 - Igresar elemento a stack 1 \n");
        printf("3 - Mostrar elementos \n");
        printf("4 - Salir\n");
        scanf("%i", &selec);
        printf("\n");
        switch (selec){
        case 1:
            datosStack(S);
            break;
        case 2: 
            datosStack(S2);
            break;
        case 3:
            mostrarStack(S, S2);
            break;
        }
    } while (selec != 5);
    liberarMem(S, S2);
}

void datosStack(STACK S){
    int value;
    printf("Ingrese un valor: \n");
    scanf("%i", &value);
    push(S, value);
}

void datosStack(STACK S2){
    int value;
    printf("Ingrese un valor: \n");
    scanf("%i", &value);
    push(S2, value);
}

void mostrarStack(STACK S, STACK S2){
    int aux;
    printf("Elmentos ingresados: \n");
    while (isEmpty(S) == FALSE){
        aux = pop(S);
        printf("%i \n", aux);
    }
    printf("\n");
    while (isEmpty(S2) == FALSE){
        aux = pop(S2);
        printf("%i \n", aux);
    }
    
}

STACK initStack(){
    STACK S;
    S = (STACK)malloc(sizeof(Stack));
    if (S==NULL){
        exit(0);
    }
    S->tope = -1;
    return S;
}

int isEmpty(STACK S) {
    if (S->tope == -1){
        return TRUE;
    }
    return FALSE;
}

bool isFull(STACK S) {
    return S->tope == TAM - 1;
    printf("\nPila llena\n");
}

void push(STACK S, int value) {
    if (S->tope == TAM-1){
        exit(0);
    }
    (S->tope)++;
    S->items[S->tope] = value;
}

int pop(STACK S) {
    int aux;
    if (isEmpty(S) == TRUE){
        exit(0);
    }
    aux = S->items[S->tope];
    (S->tope)--;
    return aux;
}

void liberarMem(STACK S, STACK S2){
    free(S);
    free(S2);
}
