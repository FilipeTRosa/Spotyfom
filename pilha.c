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

desc_Stack * criarPlayListPessoal(desc_Playlist * facervo, int opcaoMenu){
    desc_Stack * novaPlaylist = createStack();
    nodo * fnodo = facervo->primeiramusica;
    nodo * nodoLimpo = NULL;
    int posicaoMusica = 0, menuInsercao = 0, codigo = 0;
    switch (opcaoMenu)
    {
    case 1:
        /* playlist pela posicao */
        do
        {
            printf("Digite a posição da musica que deseja incluir na playlist.\n");
            setbuf(stdin, NULL);
            scanf("%d", &posicaoMusica);
            fnodo = buscaNodo(facervo, posicaoMusica);
            if(fnodo == NULL){
                printf("Posicao inexistente no acervo.\n");
            }else{
                nodoLimpo = copiaNodo(fnodo);
                novaPlaylist = pushStack(novaPlaylist, nodoLimpo);
            }
            printf("\nDeseja incluir mais uma musica?\n");
            printf("Digite [1] para SIM ou [2] para NAO!\n");
            setbuf(stdin, NULL);
            scanf("%d", &menuInsercao);
            
        } while (menuInsercao != 2);
        break;
    
    case 2:
        /*Playlist pessoal por nome*/
       
        break;
    case 3:
        /*Playlist pessoal por codigo*/
         do
        {
            printf("Digite o codigo da musica que deseja incluir na playlist.\n");
            setbuf(stdin, NULL);
            scanf("%d", &codigo);
            fnodo = buscaNodoPorCodigo(facervo, codigo);
            if (fnodo == NULL)
            {
                printf("Codigo inexistente no acervo!\n");
            }else{
                nodoLimpo = copiaNodo(fnodo);
                novaPlaylist = pushStack(novaPlaylist, nodoLimpo);
            }
            printf("\nDeseja incluir mais uma musica?\n");
            printf("Digite [1] para SIM ou [2] para NAO!\n");
            setbuf(stdin, NULL);
            scanf("%d", &menuInsercao);
            
        } while (menuInsercao != 2);
        break;
    case 4:
        /*Play list pessoal por Artista*/
        break;    
    default:
        break;
    }

    return novaPlaylist;
}

void executarPlaylistStack(desc_Stack * fstack){

    nodo * fnodo = fstack->first_stack;
    while (fnodo!= NULL)
    {
        if(fnodo != NULL)
            executarMusica(fnodo);
    
        fnodo = fnodo ->prox;
    }
    

}

