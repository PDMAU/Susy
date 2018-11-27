#include <hash.h>

int haColaboracao(p_hash tabela, char* nomeAutor1, char* nomeAutor2, int numeroArtigos){
    int i;
    p_autor autor1, autor2;
    autor1 = buscar(tabela, nomeAutor1);
    autor2 = buscar(tabela, nomeAutor2);
    
    for(i =0; i < numeroArtigos; i++){
        if(autor1->artigos[i] == autor2->artigos[i] == 1){
            return 1;
        }
    }
    
    return 0;    
}

void inserirParticipacaoEmArtigo(p_hash tabela, char* nomeAutor,int numeroArtigo){
    p_autor autor;
    autor = buscar(tabela, nomeAutor);
    autor->artigos[numeroArtigo]=1;
}