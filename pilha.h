

/*
– CriaPilha - cria Desc_Pilha
– PUSH (x, S) - coloca um elemento no topo da pilha
– POP (s) - apaga o elemento no topo da pilha;
– TOP (s) - retorna o elemento no topo da pilha, sem retirá-lo
– EMPTY (s) - retorna verdadeiro se a pilha estiver vazia, falso caso contrário
- MAKENULL (s) - elimina todos os elementos da pilha
- LENGHT (s) - retorna o tamanho da pilha.
– Imprime
*/

typedef struct desc_Stack
{
     nodo * first_stack;
     nodo * last_stack;
    int length;

}desc_Stack;


desc_Stack * createStack ();
desc_Stack * pushStack (desc_Stack * fstack, nodo * fnodo) ;
desc_Stack * popStack (desc_Stack * fstack);
nodo * topStack (desc_Stack * fstack);
int emptyStack (desc_Stack * fstack);
void makenullStack (desc_Stack * fstack);
int lengthStack (desc_Stack * fstack);
void printStack (desc_Stack * fstack);
