void printar_N_maiores(p_no raiz, int &n){
    if(n*== 0 || raiz == NULL)
        return;
    printar_N_maiores(raiz->dir, &n);    
    printar_N_maiores(raiz->esq, &n);
    print(raiz->chave);
    *n--;
}

void main(){}
