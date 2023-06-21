
typedef struct musica{
    char titulo[256];
    char artista[256];
    char letra[256];
    int codigo;
    int execucoes;
}musica;

/*typedef struct codMusica
{
    int valor;
}codMusica;
*/

static int codigoMusica = 0;//Aumenta para cada musica criada independente da TAD que cria.

typedef struct nodo{
    struct nodo *prox;
    struct nodo *ant;
    struct musica *info;
}nodo;

typedef struct desc_Playlist{
     struct desc_Playlist * prox;
     struct desc_Playlist * ant;
     nodo * primeiramusica;
     nodo * ultimamusica;
    int tamanho;
}desc_Playlist;


/*– CriaLista
– Insere
– Remove
– Consulta
– Imprime */

desc_Playlist * criaLista (void); //ok
musica * criaMusica (char * fartista, int fcodigo, char * ftitulo, char * fletra); //ok
nodo * criaNodo(void); //ok
void insereLDE (desc_Playlist* lista,musica * fmusica, int posicao);
nodo * removeLDE (desc_Playlist* lista, int posicao);
void imprimeLista(desc_Playlist* lista);
void imprimeNodo(nodo * fnodo);
void limpar_buffer();
nodo * buscaNodoPorPosicao(desc_Playlist * lista, int posicao);
void liberaPlaylist(desc_Playlist * lista);
void setMusica(desc_Playlist * lista);
nodo * copiaNodo(nodo * nodoOriginal);
void executarMusica(nodo * fnodo);
void executarPlaylistLDE(desc_Playlist * flistaLDE, int tamanho);
nodo * buscaNodoPorCodigo(desc_Playlist * lista, int codigo);
desc_Playlist * buscaNodoPorTitulo (desc_Playlist * flista, char * ftitulo);
desc_Playlist * resetaListaLDE (desc_Playlist * flista);
desc_Playlist * buscaNodoPorArtista (desc_Playlist * flista, char * fartista);