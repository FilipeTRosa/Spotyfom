#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "musicas.h"
//#include <time.h>

desc_Playlist * criaLista (void){
    desc_Playlist * lista = (desc_Playlist*) malloc (sizeof(desc_Playlist));
        lista->ant = NULL;
        lista->prox = NULL;
        lista->primeiramusica = NULL;
        lista->ultimamusica = NULL;
        lista->tamanho = 0;
    return lista;
}

musica * criaMusica (char * fartista, int fcodigo, char * ftitulo, char * fletra){
    
    //alocação de memoria
    musica * novaMusica = (musica *) malloc (sizeof(musica));
        //preenchimento struct musica
        strcpy(novaMusica->titulo, ftitulo);
        strcpy(novaMusica->artista, fartista);
        strcpy(novaMusica->letra, fletra);
        novaMusica->codigo = fcodigo;
        novaMusica->execucoes = 0;
    
    //printf("Musica criada com sucesso\n");
    //printf("\n Musica criada\n\n[Titulo]: %s [Artista]: %s [Letra]: %s [COD]: %d\n\n", novaMusica->titulo, novaMusica->artista, novaMusica->letra, novaMusica->codigo);
    
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
                nodo *aux = lista->primeiramusica;
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
                nodo *aux = lista->primeiramusica;
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
        //printf("\n[Elemento] = %d\n", i);
        imprimeNodo(aux);
        aux = aux->prox;
        if (i%20 == 0)
        {   
            //printf("\n\nMusicas impressas até o momento: [ %d ] / Total: %d\n Precione ENTER para continuar.", i, lista->tamanho);
            getchar();
        }
        i++;
    }
}

void imprimeNodo(nodo * aux){
    printf("-----------------------------\n");
    printf("Titulo: [%s] \nArtista: [%s] \nLetra: [%s] \nCodigo: [%d] \nExecucoes: [%d] \n", aux->info->titulo, aux->info->artista, aux->info->letra, aux->info->codigo, aux->info->execucoes);
    printf("-----------------------------\n");
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
        nodo * aux = buscaNodoPorPosicao(lista, posicao);
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


nodo * buscaNodoPorPosicao(desc_Playlist * lista, int posicao){
    int i = 0;
    if(posicao > lista->tamanho){
        printf("Posicao invalida! \n");
        return NULL;
    }else{
            nodo * aux = lista->primeiramusica;
            i = 0;
        while(i<posicao){
            aux = aux->prox;
            i++;
        }
        return aux;
        }
    return NULL;
}

nodo * buscaNodoPorCodigo(desc_Playlist * lista, int codigo){
    nodo * fnodo = lista->primeiramusica;
    while(fnodo != NULL){
        if (fnodo->info->codigo == codigo)
        {
            return fnodo;
        }else{
            fnodo = fnodo->prox;
        }
    }
    return NULL; 
}

desc_Playlist * resetaListaLDE (desc_Playlist * flista){

    flista->ant = NULL;
    flista->prox = NULL;
    flista->primeiramusica = NULL;
    flista->ultimamusica = NULL;
    flista->tamanho = 0;

    return flista;
}

desc_Playlist * buscaNodoPorTitulo (desc_Playlist * flista, char * ftitulo){
    nodo * aux = flista->primeiramusica;
    nodo * nodoLimpo = NULL;
    desc_Playlist * listaMusicasEncontradas = criaLista();
    converterStringParaMaiuscula(ftitulo);
    while (aux != NULL)
    {
        if(strcmp(aux->info->titulo,ftitulo) == 0){
            //caso ache a musica exata vai inserir no inicio
            insereLDE(listaMusicasEncontradas, aux->info, 0);
        }else
        {
            if (strstr(aux->info->titulo, ftitulo) != NULL)
            {
                //caso ache a substring insere no fim
                insereLDE(listaMusicasEncontradas, aux->info, listaMusicasEncontradas->tamanho);
            }
        }
        aux = aux->prox;
    }
    return listaMusicasEncontradas;
}

desc_Playlist * buscaNodoPorArtista (desc_Playlist * flista, char * fartista){
    nodo * aux = flista->primeiramusica;
    nodo * nodoLimpo = NULL;
    desc_Playlist * listaMusicasEncontradasArtista = criaLista();
    converterStringParaMaiuscula(fartista);
    while (aux != NULL)
    {
        if(strcmp(aux->info->artista,fartista) == 0){
            //caso ache a musica exata vai inserir no inicio
            insereLDE(listaMusicasEncontradasArtista, aux->info, 0);
        }else
        {
            if (strstr(aux->info->artista, fartista) != NULL)
            {
                //caso ache a substring insere no fim
                insereLDE(listaMusicasEncontradasArtista, aux->info, listaMusicasEncontradasArtista->tamanho);
            }
        }
        aux = aux->prox;
    }
    return listaMusicasEncontradasArtista;
}



void setMusica (desc_Playlist * lista){
    /*musica * fmusica = criaMusica();
    int posicao;
    printf("Digite a posicao da lista que deseja alterar. \n");
    scanf("%d", &posicao);

    nodo * aux = buscaNodoPorPosicao(lista, posicao);
    if (aux == NULL)
    {
        printf("Posicao invalida\n");
        return;
    }else{
        aux->info = fmusica;
    }*/
}

void setNodo (desc_Playlist * lista,nodo * novoNodo, int posicao){

    nodo * aux = buscaNodoPorPosicao(lista, posicao);
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

nodo * copiaNodo(nodo * nodoOriginal){
    
    nodo * novoNodo = criaNodo();
    novoNodo->info = nodoOriginal->info;

    return novoNodo;
}

void executarMusica(nodo * fnodo){
    fnodo->info->execucoes++;
    printf("Executando musica: %s /-/ Codigo: [%d]\n", fnodo->info->titulo, fnodo->info->codigo);
}

void executarPlaylistLDE(desc_Playlist * flistaLDE, int tamanho){

    int cont = 0;
    nodo * fnodo = NULL;
    while (cont < tamanho)
        {
            fnodo = buscaNodoPorPosicao(flistaLDE, cont);
            if (fnodo != NULL)
            {
                executarMusica(fnodo);
            }
            cont++;
        }				
}

void converterStringParaMaiuscula(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = toupper(str[i]);
        i++;
    }
}