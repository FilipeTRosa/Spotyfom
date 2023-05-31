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
	//preparando variaveis para o sistema
	desc_Playlist * acervo = criaLista();
	musica * novaMusica = NULL;
	nodo * nodoOriginal = criaNodo();
	nodo * nodoPlaylistAleatoria = NULL;
	desc_queue * queue = createQueue();
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
		//imprimeLista(acervo);
	
	//Menu principal e variaveis dos menus filhos
	int menuPrincipal=0,menuPlaylist=0;
	int quantMusicas = 0, contadorItensFila = 0;
	do
	{
		printf("\nMenu Principal:\n");
		printf("[1] - Execucao.\n");
		printf("[2] - Playlist.\n");
		printf("[3] - Busca.\n");
		printf("[4] - Impressão.\n");
		printf("[5] - Relatorios,\n");
		printf("[6] - Sair.\n");
		setbuf(stdin,NULL);
		scanf("%d", &menuPrincipal);

		switch (menuPrincipal)
		{
		case 1:
			/* Execução */
			break;
		case 2:
			/* Playlist */
			do
			{
				printf("\nEscolha o tipo de playlis para criar. \n");
				printf("[1] - Aleatoria.\n");
				printf("[2] - Selecionar as musicas.\n");
				printf("[3] - Voltar ao menu principal.\n");
				setbuf(stdin,NULL);
				scanf("%d", &menuPlaylist);

				switch (menuPlaylist)
				{
				case 1:
					/* Aleatoria */
					printf("Quantidade de musicas disponiveis %d:\n", tamanhoAcervo);
					printf("\nDigite a quantidade de musicas para a sua Playlist.\n");
					setbuf(stdin, NULL);
					scanf("%d", &quantMusicas);
					//fazer um if para testar se 
					//valor informado é < que tamanhoAcervo
						while (contadorItensFila < quantMusicas)
						{
							/* buscar na LDE pela posição e
							inserir na fila */
							nodoOriginal = buscaNodo(acervo, rand()%tamanhoAcervo);
							nodoPlaylistAleatoria = copiaNodo(nodoOriginal);
							queue = enqueue(queue, nodoPlaylistAleatoria);
							contadorItensFila++;
						}
						printf("\n\n\n\n FILAAAAAA \n\n\n\n");
						showQueue(queue);

					break;
				case 2:
					/* Escolher musicas*/
					/* Montar menu com os tipos de escolhas*/
					break;
				default:
					break;
				}
			} while (menuPlaylist != 3);
			
			break;
		case 3:
			/* Busca */

			break;
		case 4:
			/* Impressão */
			break;
		case 5:
			/* Relatórios */
			break;
			
		default:
			break;
		}

	} while (menuPrincipal != 6);// Fim menu Principal
	
	return 0;
}

void quebraFrase(char *frase,int n, desc_Playlist * acervo, musica * novaMusica){
	//com a frase em mãos é só dividir a frase e adicionar nas structs musica
	char titulo [256], artista [256], letra[256];
	
	//nodo * novoNodo = NULL;

	//printf("\n\n===================================\n");
	//printf("artista é: %s \n",strtok(frase,";"));
	strcpy(artista,strtok(frase,";"));
	//printf("codigo é: %s \n",strtok(NULL,";"));
	int codigo = atoi(strtok(NULL,";"));
	//printf("titulo é: %s \n",strtok(NULL,";"));
	strcpy(titulo,strtok(NULL,";"));
	//printf("letra é: %s \n",strtok(NULL,";")); 
	strcpy(letra,strtok(NULL,";"));
	novaMusica = criaMusica(artista,codigo,titulo,letra);
	//printf("===================================\n");
	
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