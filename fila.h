


/*Funções a serem implementadas em fila

- CreateQueue - Cria descritor para a fila
– DELETE(Fila) - Faz a fila ficar vazia.
– EMPTY (Fila) - Retorna true se a Fila estiver vazia; caso contrário, retorna false.
– ENQUEUE (x, Fila) - Insere o item x no fim da fila.
– DEQUEUE (Fila, x) - Retorna o item x no início da fila, retirando-o da fila.
– LENGHT (Fila) - Retorna o tamanho da fila
– ShowQueue - Imprime a fila
*/
typedef struct desc_queue{
struct nodo *head;
struct nodo *tail;
int tamanho;
}desc_queue;


desc_queue * createQueue ();
desc_queue * deleteQueue (desc_queue * fqueue);
int emptyQueue (desc_queue * fqueue);
desc_queue * enqueue (desc_queue * fqueue, nodo * fnodo);
nodo * dequeue (desc_queue * fqueue);
int lenghtQueue (desc_queue * fqueue);
void showQueue (desc_queue * fqueue);