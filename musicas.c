#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musicas.h"

desc_Playlist * criaLista (void){
    desc_Playlist * lista = (desc_Playlist*) malloc (sizeof(desc_Playlist));
        lista->ant = NULL;
        lista->prox = NULL;
        lista->primeiramusica = NULL;
        lista->ultimamusica = NULL;
        lista->tamanho = 0;
    return lista;
}

musica * criaMusica (){
    
    //defincao de variaveis.
        char titulo [256], artista [256], letra[256];
        codigoMusica++;
    //preenchimento de variaveis.
        printf("\nDigite o titulo da musica\n");
            limpar_buffer();
            fgets(titulo, 256, stdin);
            printf("Digite o artista\n");
            void limpar_buffer();
            fgets(artista, 256, stdin);
            printf("Digite a letra da musica\n");
            void limpar_buffer();
            fgets(letra, 256, stdin);
    //alocação de memoria
    musica * novaMusica = (musica *) malloc (sizeof(musica));
        //preenchimento struct musica
        strcpy(novaMusica->titulo, titulo);
        strcpy(novaMusica->artista, artista);
        strcpy(novaMusica->letra, letra);
        novaMusica->codigo = codigoMusica;
        novaMusica->execucoes = 0;
    
    printf("Musica criada com sucesso\n");
    printf("\n Musica criada\n\n[Titulo] = %s[Artista] = %s[Letra] = %s\n\n", novaMusica->titulo, novaMusica->artista, novaMusica->letra);
    
    return novaMusica;
}

nodo * criaNodo(void){
    nodo * novoNodo = (nodo *) malloc (sizeof(nodo));
        novoNodo->ant = NULL;
        novoNodo->prox = NULL;
        novoNodo->info = NULL;
    return novoNodo;
}

void insereLDE (desc_Playlist * lista,musica * fmusica, int posicao){

    int i = 0;
    nodo *aux = lista->primeiramusica;
    nodo * fnodo = criaNodo();
    fnodo->info = fmusica;


    if (posicao > lista->tamanho) // se posicao maior que a lista
    {
        printf("posição invalida! \n");
        return;
    }else{
        if(lista->primeiramusica == NULL){// insere no começo com a lista vazia
            lista->primeiramusica = fnodo;
            lista->ultimamusica = fnodo;
            lista->tamanho++;
        }else{
            if (posicao == 0)// insere no começo quando a lista tem itens
            {
                fnodo->prox = lista->primeiramusica;
                fnodo->prox->ant = fnodo;            
                lista->primeiramusica = fnodo;
                lista->tamanho++;
                return;
            }else{
                if (posicao > 0 && posicao < lista->tamanho)// insere no meio
                {
                    while (i < posicao)
                    {
                        aux = aux->prox;
                        i++;
                    }
                        fnodo->prox = aux;
                        fnodo->ant = aux->ant;
                        aux->ant->prox = fnodo;
                        aux->ant = fnodo;
                        lista->tamanho++;
                        return;
                }
            }       
            if(posicao = lista->tamanho){ //inserir no fim
                while (aux->prox != NULL)
                {
                    aux = aux->prox;
                } 
                    lista->ultimamusica->prox = fnodo;
                    fnodo->ant = lista->ultimamusica;
                    lista->ultimamusica = fnodo;
                    lista->tamanho++;  
                    return;
            }
        }
    }   
}

void imprimeLista(desc_Playlist * lista){

    int i = 0;
    nodo * aux = lista->primeiramusica;


    while (i<lista->tamanho)
    {
        //printf("\n-*/-*/-*/-*/-*/\n");
        printf("\n[Elemento] = %d\n", i);
        imprimeNodo(aux);
        aux = aux->prox;
        i++;
    }
}

void imprimeNodo(nodo * aux){
    
    printf("[Titulo] = %s [Artista] = %s [Letra] = %s [Codigo] = %d [Execucoes] = %d ", aux->info->titulo, aux->info->artista, aux->info->letra, aux->info->codigo, aux->info->execucoes);

}

void limpar_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { }
}

nodo * removeLDE (desc_Playlist* lista, int posicao){

    if ((lista->tamanho == 0)||(posicao >= lista->tamanho)){
        printf ("A posição não existe!\n");
        return NULL;
    }else{
        nodo * aux = buscaNodo(lista, posicao);
        if(aux->prox == NULL && lista->tamanho >1){// aux = ultimo
            lista->ultimamusica = aux->ant;
            aux->ant->prox = NULL;
            aux->ant = NULL;
            lista->tamanho--;
            return aux;
        }else{
            if(aux->ant == NULL && lista->tamanho > 1){
                lista->primeiramusica = aux->prox;
                aux->prox->ant = NULL;
                aux->prox = NULL;
                lista->tamanho--;
                return aux;
            }else{
                if(lista->tamanho == 1){
                    lista->primeiramusica = NULL;
                    lista->tamanho--;
                    return aux;
                }else{
                        aux->ant->prox = aux->prox;
                        aux->prox->ant = aux->ant;
                        lista->tamanho--;
                        return aux;
                }
            }
        }
   }
        return NULL;
}


nodo * buscaNodo(desc_Playlist * lista, int posicao){
    //nodo * aux = lista->primeiramusica;
    int i = 0;
    if(posicao > lista->tamanho){
        printf("Posicao invalida! \n");
        return NULL;
    }else{
        if(posicao > (lista->tamanho / 2)){
            nodo * aux = lista->ultimamusica;
            i = lista->tamanho - 1;
            while (i<posicao)
            {
                aux = aux->ant;
                i--;
            }
            return aux;
        }else{
            nodo * aux = lista->primeiramusica;
            i = 0;
        while(i<posicao){
            aux = aux->prox;
            i++;
        }
        return aux;
        }
    }
    return NULL;
}

void setMusica (desc_Playlist * lista){
    musica * fmusica = criaMusica();
    int posicao;
    printf("Digite a posicao da lista que deseja alterar. \n");
    scanf("%d", &posicao);

    nodo * aux = buscaNodo(lista, posicao);
    if (aux == NULL)
    {
        printf("Posicao invalida\n");
        return;
    }else{
        aux->info = fmusica;
    }
}

void setNodo (desc_Playlist * lista,nodo * novoNodo, int posicao){

    nodo * aux = buscaNodo(lista, posicao);
        novoNodo->ant = aux->ant;
        novoNodo->prox = aux->prox;
        aux->ant->prox = novoNodo;
        aux->prox->ant = novoNodo;

    free(aux);
}


void liberaPlaylist(desc_Playlist * lista){
  
    if(lista == NULL){
        return;
    }else{
        nodo * aux = lista->primeiramusica;
        while(aux != NULL){
            nodo * proxNodo = aux->prox;
            free(aux->info);
            free(aux);
            aux = proxNodo;
        }

        lista->primeiramusica = NULL;
        lista->ultimamusica = NULL;
        lista->tamanho = 0;
        free(lista);
    }
}



