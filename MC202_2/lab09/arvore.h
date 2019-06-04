enum Cor{
    VERMELHO,
    PRETO
};

typedef struct No{
    int chave;
    enum Cor cor;
    struct No *esq, *dir;
} No;
typedef No *p_no;

int ehVermelho(p_no x);
int ehPreto(p_no x);
p_no rotaciona_para_esquerda(p_no raiz);
p_no rotaciona_para_direita(p_no raiz);
void sobe_vermelho(p_no raiz);
p_no inserir_rec(p_no raiz, int chave);
p_no inserir(p_no raiz, int chave);