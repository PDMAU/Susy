typedef struct No {
 int dado;
 struct No *esq, *dir; /* *pai */
 } No;

 typedef No * p_no;

 p_no criar_arvore(int x, p_no esq, p_no dir);

 p_no procurar_no(p_no raiz, int x);
