#include <hash.h>

int haColaboracao(p_hash tabela, char* nomeAutor1, char* nomeAutor2, int numeroArtigos){
    int i;
    p_autor autor1, autor2;
    autor1 = buscar(tabela, nomeAutor1);
    autor2 = buscar(tabela, nomeAutor2);
    
    for(i =0; i < numeroArtigos; i++){
        if(autor1->artigos[i] == autor2->artigos[i] != 0){
            return 1;
        }
    }
    
    return 0;    
}

void inserirParticipacaoEmArtigo(p_autor autor,int numeroArtigo){
    autor->artigos[numeroArtigo]=1;
}
//refazer o destruir
void processarAutor(p_hash tabela, char* nome,int numeroArtigo){
    p_autor autor = buscar(tabela, nome);
    if(autor == NULL){
        autor = malloc(sizeof(Autor));
        autor->artigos = malloc(sizeof(unsigned int)* tabela->numeroArtigos);
        //inicializar esse vetor com 0 em tudo
        
        inserir(tabela, nome, autor);
    }
    inserirParticipacaoEmArtigo(autor, numeroArtigo);
    
        
    
}
