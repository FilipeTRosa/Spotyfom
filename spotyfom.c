#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musicas.h"
#include "pilha.h"
#include "fila.h"

void quebraFrase(char *frase,int n,desc_Playlist * acervo, musica * novaMusica);

int main(){
	
	FILE *arquivoEntrada;
	arquivoEntrada = fopen("musicas.txt","r");
	if(arquivoEntrada ==NULL){
		printf("não foi possivel abrir o arquivo\n");
		exit(-1);
	}
	int tamanhoAcervo;
	fscanf(arquivoEntrada,"%d",&tamanhoAcervo);
	printf("tamanho do acervo sera %d\n",tamanhoAcervo);
	//aloca a struct musica com o tamanho do acervo
	char caractere;
	char frase[256];
	int  n=0;
	//prepara a lista para o acervo
	desc_Playlist * acervo = criaLista();
	musica * novaMusica = NULL;
	//vai percorrer o arquivo e alocar cada musica no acervo
	while((caractere = fgetc(arquivoEntrada))!= EOF){
		if(caractere != '\n'){ //caractere diferente de \n guarda em frase
			frase[n]=caractere;
			n++;
		}
		else{//encontrou \n
			if(n > 0){
				frase[n]='\0';
				quebraFrase(frase,n,acervo, novaMusica);
			}
			n=0;
			frase[n]='\0';
		}
	}
	
	return 0;
}

void quebraFrase(char *frase,int n, desc_Playlist * acervo, musica * novaMusica){
	//com a frase em mãos é só dividir a frase e adicionar nas structs musica
	char titulo [256], artista [256], letra[256];
	
	//nodo * novoNodo = NULL;

	printf("\n\n===================================\n");
	printf("artista é: %s \n",strtok(frase,";"));
	strcpy(artista,strtok(frase,";"));
	printf("codigo é: %s \n",strtok(NULL,";"));
	int codigo = atoi(strtok(NULL,";"));
	printf("titulo é: %s \n",strtok(NULL,";"));
	strcpy(titulo,strtok(NULL,";"));
	printf("letra é: %s \n",strtok(NULL,";")); 
	strcpy(letra,strtok(NULL,";"));
	printf("===================================\n");
	novaMusica = criaMusica(artista,codigo,titulo,letra);
	//novoNodo = criaNodo();
	//novoNodo->info = novaMusica;
	insereLDE(acervo, novaMusica, 0);

	return;
}


/* exemplo de como inserir do acervo na lista criando uma copia da musica do acervo
 * 
insernaLista(struct musica *Acervo,int indice,struct descLista *lista){
	struct musicaLista *nova = criaMusicaLista(Acervo[indice]->artista,Acervo[indice]->titulo,Acervo[indice]->codigo,Acervo[indice]->letra);
	struct nodo* novo = criaNodoLista(lista,nova);
	insereLista(lista,novo);
}
*/