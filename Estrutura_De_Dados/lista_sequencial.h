#define MAX 100

struct sistema
{
    int n;
    char titulo[20];
    char texto[1200];
};

typedef struct lista Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int tamanho_lista (Lista* li);
int lista_cheia (Lista* li);
int lista_vazia (Lista* li);
int insere_lista_final (Lista* li, struct sistema sus);
int insere_lista_inicio (Lista* li, struct sistema sus);
int insere_lista_ordenada (Lista* li, struct sistema sus);
int remove_lista_final (Lista* li);
int remove_inicio (Lista* li);
int remove_meio (Lista* li, int num);
int consulta_lista (Lista* li, int num, struct sistema *sus);