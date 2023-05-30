#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musicas.h"
#include "pilha.h"

/* funcoes da pilha/stack */


desc_Stack * createStack (){
    desc_Stack * stack = (desc_Stack *) malloc (sizeof(desc_Stack));

    stack->first_stack = NULL;
    stack->last_stack = NULL;
    stack->length = 0;

    return stack;
}

int empty (desc_Stack * fstack){
    if (fstack->length == 0)
    {
        return 1;
    }else
    {
        return 0;
    }
}

desc_Stack * pushStack (desc_Stack * fstack, nodo * fnodo){

    if(empty(fstack)){//pilha vazia
        fstack->first_stack = fnodo;
        fstack->last_stack = fnodo;
        fstack->length ++;
        return fstack;
    }else{
        nodo * aux = fstack->first_stack;
        fnodo->prox = aux;
        fstack->first_stack = fnodo;
        fstack->length++;
        return fstack;
    }

}
desc_Stack * popStack (desc_Stack * fstack){
   
    if (empty(fstack))
    {
        printf("Lista vazia");
        return fstack;     
    }else
    {
        nodo * aux = fstack->first_stack;
        fstack->first_stack = aux->prox;
        fstack->length--;
        return fstack;
    }
    
}
nodo * topStack (desc_Stack * fstack){
    return fstack->first_stack;    
}

void makenullStack (desc_Stack * fstack){
    fstack->first_stack = NULL;
    fstack->length = 0;
}

int lengthStack (desc_Stack * fstack){
    return fstack->length;
}
void printStack(desc_Stack * fstack){
    nodo * aux = fstack->first_stack;
    while (aux != NULL)
    {   
        printf("\n*----------*\n");
        imprimeNodo(aux);
        aux = aux->prox;
    }
        printf("\n*----------*\n");
    
}
