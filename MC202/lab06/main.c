#include <stdio.h>
#include <stdlib.h>
#include "universidade.h"
#include <string.h>

int main() {
    p_professor* professores;
    p_aluno* alunos;
    int numeroProfessores,numeroAlunos,numeroDisciplinas, i,j;
    double salario, nota, maiorNota, menorNota;
    char nome[MAX_NOME], sobrenome[MAX_NOME], disciplina[MAX_CODIGO];
    scanf("%d", &numeroProfessores);
    professores = malloc(sizeof(Professor)*numeroProfessores);
    for(i=0; i<numeroProfessores; i++) {
        scanf("%s %s %lf %s", nome, sobrenome, &salario, disciplina);
        professores[i] = criarProfessor(nome, sobrenome, salario, disciplina);
    }
    scanf("%d", &numeroAlunos);
    alunos = malloc(sizeof(Aluno)*numeroAlunos);
    for(i=0; i<numeroAlunos; i++) {
        scanf("%s %s", nome, sobrenome);
        alunos[i] = criarAluno(nome, sobrenome);
        scanf("%d", &numeroDisciplinas);
        for(j=0; j < numeroDisciplinas; j++) {
            scanf("%s %lf", disciplina, &nota);
            adicionarDisciplina(alunos[i], disciplina, nota);
        }
    }
    for(i=0; i<numeroProfessores; i++) {
        strcpy(disciplina, professores[i]->disciplina);
        obterNotasExtremas(alunos,numeroAlunos,disciplina, &menorNota, &maiorNota);
        printf("Maior: %lf Menor:%lf \n", maiorNota, menorNota);
        reajusteSalario(professores[i],(maiorNota+menorNota)/2.0);
        imprimirProfessor(professores[i]);
    }
    return 0;
}
