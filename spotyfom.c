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
	nodo * nodo = NULL;
	desc_queue * queue = createQueue();
	desc_Stack * stack = NULL;
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
	int menuPrincipal=0,menuImpressao = 0, menuPlaylist=0, menuExec = 0, menuPessoal = 0, menuPlaylistPessoal =0;
	int quantMusicasAleatorias = 0, contadorItensFila = 0;
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
			do
			{
				printf("Escolha qual playlist deseja executar.\n");
				printf("[1] - Tocar todas as musicas.\n");
				printf("[2] - Executar PLaylist Aleatoria.\n");
				printf("[3] - Executar Playlist Pessoal.\n");
				printf("[4] - Sair / VOltar ao menu principal.\n");
				setbuf(stdin,NULL);
				scanf("%d", &menuExec);


				switch (menuExec)
				{
				case 1:
					/* Executar acervo completo */
					executarPlaylistLDE(acervo,tamanhoAcervo);
					break;
				case 2:
					/*Executar playlist aleatoria*/
					executarPlaylistQueue(queue, lenghtQueue(queue));
					break;
				case 3:
					/*Executar playlist pessoal*/
					executarPlaylistStack(stack);
					break;
				default:
					break;
				}
			} while (menuExec != 4);
			
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
					scanf("%d", &quantMusicasAleatorias);
					//fazer um if para testar se 
					//valor informado é < que tamanhoAcervo
					
						while (contadorItensFila < quantMusicasAleatorias)
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
					do
					{
						printf("Criar playlist escolhendo as musicas.\n");
						printf("[1] - Escolher musicas por Posicao.\n");
						printf("[2] - Escolher musicas por Nome.\n");
						printf("[3] - Escolher musicas por Codigo.\n");
						printf("[4] - Escolher musicas por Artista.\n");
						printf("[5] - Sair / Voltar ao menu anterior.\n");
						setbuf(stdin, NULL);
						scanf("%d", &menuPlaylistPessoal);
						
						if (menuPlaylistPessoal < 5)
						{	//chama funcao de criar playlist por escolha
							//switch está dentro da funcao criarPlayListPessoal
							stack = criarPlayListPessoal(acervo, menuPlaylistPessoal);
						}
					}while (menuPlaylistPessoal != 5);									
					break;
				default:
					break;
				}
			} while (menuPlaylist != 3);
			/*fim do modulo de criar playlists*/
			break;
		case 3:
			/* Busca */

			/*Fim do modulo de Busca*/
			break;
		case 4:
			/* Impressão */
			printf("Qual playlist deseja imprimir?\n");
			printf("[1] - Imprimir Acervo Completo.\n");
			printf("[2] - Inprimir Playlist Aleatória.\n");
			printf("[3] - Imprimir Playlist Pessoal.\n");
			printf("[4] - Sair / Voltar ao menu anterior.\n");
			setbuf(stdin, NULL);
			scanf("%d", &menuImpressao);

			switch (menuImpressao)
			{
			case 1:
				imprimeLista(acervo);
				break;
			case 2:
				showQueue(queue);
				break;
			case 3:
				printStack(stack);
				break;
			default:
				break;
			}
			/* Fim do modulo de Impressão*/
			break;
		case 5:
			/* Relatórios */
			/* Fim do modulo de Relatórios*/
			break;
			
		default:
			break;
		}

	} while (menuPrincipal != 6);// Fim menu Principal
	
	liberaPlaylist(acervo);
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