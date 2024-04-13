#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define TAM 100
#define TRUE 1
#define FALSE 0

/**
 * 3. Write a program to check a stack is full or not using an array with push
and pop operations. &gt;
Expected Output:
Stack size: 3
Original Stack: 1 2 3
Push another value and check if the stack is full or not!
Stack is full!
Stack size: 3
Original Stack: 10 20
Check the said stack is full or not!
Stack is not full!
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
void liberarMem(STACK S);
void datosStack(STACK S);
void mostrarStack(STACK S);

int main() {
    STACK S;
    S = initStack();
    int selec=0;

    printf("Tamanio de la pila: %d\n", TAM);
    do{
        printf("\nSeleccione una opcion\n");
        printf("1 - Igresar elemento \n");
        printf("2 - Mostrar elementos \n");
        printf("3 - Salir\n");
        scanf("%i", &selec);
        printf("\n");
        switch (selec){
        case 1:
            datosStack(S);
            break;
        case 2: 
            mostrarStack(S);
            break;
        }
    } while (selec != 3);
    liberarMem(S);
}

void datosStack(STACK S){
    int value;
    printf("Ingrese un valor: \n");
    scanf("%i", &value);
    push(S, value);
}

void mostrarStack(STACK S){
    int aux;
    printf("Elmentos ingresados: \n");
    if (isEmpty(S)) {
        printf("La pila está vacía.\n");
        return;
    }
    while (!isEmpty(S)) {
        aux = pop(S);
        printf("%i\n", aux);
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

void liberarMem(STACK S){
    free(S);
}
