
#include "arvore.h"

p_no criar_arvore(int x, p_no esq, p_no dir) {
 p_no r = malloc(sizeof(No));
 r->dado = x;
 r->esq = esq;
 r->dir = dir;
 return r;
 }