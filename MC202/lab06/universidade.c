/*
Nome: Maurilio dos Santos Gonçalves 
RA:203648
*/
#include "universidade.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MIN_NOTA 10
#define MAX_NOTA 0

/*
    Cria um registro professor dinamicamente.

    Entrada: nome: nome do professor
             sobrenome: sobrenome do professor
             salario: sal�rio do professor
             disciplina: disciplina lecionada pelo professor

    Sa�da: retorna um ponteiro para registro professor alocado
*/
p_professor criarProfessor(char nome[], char sobrenome[], double salario, char disciplina[]) {
    p_professor professor = malloc(sizeof(Professor));
    if(professor == NULL){
        exit(1);
    }
    strcpy(professor->nome, nome);
    strcpy(professor->sobrenome, sobrenome);
    strcpy(professor->disciplina, disciplina);
    professor->salario = salario;
    return professor;
}

/*
    Libera a mem�ria alocada para registro professor.

    Entrada: professor: ponteiro para registro professor
*/
void destruirProfessor(p_professor professor) {
    free(professor);
}

/*
    Cria um registro aluno dinamicamente, inicialmente sem disciplinas
    matriculadas.

    Entrada: nome: nome do aluno
             sobrenome: sobrenome do aluno

    Saida: retorna um ponteiro para registro aluno alocado
*/
p_aluno criarAluno(char nome[], char sobrenome[]) {
    p_aluno aluno = malloc(sizeof(Aluno));
    if(aluno == NULL){
        exit(1);
    }
    strcpy(aluno->nome, nome);
    strcpy(aluno->sobrenome, sobrenome);
    (aluno->qtd_disciplinas) = 0;
    return aluno;
}

/*
    Adiciona uma disciplina � lista de disciplinas de um aluno.

    Entrada: aluno: ponteiro para registro aluno
             disciplina: c�digo da disciplina
             nota: nota correspondente
*/
void adicionarDisciplina(p_aluno aluno, char disciplina[], double nota) {
    strcpy(aluno->disciplinas[aluno->qtd_disciplinas],disciplina);
    aluno->notas[aluno->qtd_disciplinas] = nota;
    (aluno->qtd_disciplinas)++;
}

/*
   Libera a mem�ria alocada para registro aluno.

   Entrada: aluno: ponteiro para registro aluno
*/
void destruirAluno(p_aluno aluno) {
    free(aluno);
}

/*
    Obt�m a nota m�xima e a nota m�nima entre todos os alunos matriculados em
    uma disciplina espec�fica.

    Entrada: alunos: vetor com os dados dos alunos
             disciplina: c�digo da disciplina
             qtd_alunos: quantidade de alunos no vetor

    Sa�da: devolve por par�metro as notas m�xima e m�nima dos alunos
           nota_min: menor nota entre uma turma de alunos
           nota_max: maior nota entre uma turma de alunos

*/
void obterNotasExtremas(p_aluno alunos[], int qtd_alunos, char disciplina[], double *nota_min, double *nota_max) {
    int i,j;
    double nota;

    double aux_min = MIN_NOTA;
    double aux_max = MAX_NOTA;
    for(i=0; i < qtd_alunos; i++) {
        for(j=0; j < alunos[i]->qtd_disciplinas; j++) {
            if(strcmp(alunos[i]->disciplinas[j],disciplina) == 0) {
                nota = alunos[i]->notas[j];
                if(aux_max < nota) {
                aux_max = nota;
                }if(nota < aux_min) {
                    aux_min = nota;
                }
            }
        }
    }
    *nota_min = aux_min;
    *nota_max = aux_max;

}

/*
    Calcula o reajuste salarial do professor e atualiza registro.

    Entrada: professor: ponteiro para registro professor
             media_notas: m�dia entre as notas m�xima e m�nima dos alunos de
             uma determinada disciplina
*/
void reajusteSalario(p_professor professor, double media_notas) {
    if(media_notas == 10) {
        professor->salario += professor->salario*0.15;
    } else if(media_notas >=9) {
        professor->salario += professor->salario*0.10;
    } else if(media_notas >= 8.5) {
        professor->salario += professor->salario*0.05;
    }

}

/*
    Imprime o nome e sobrenome do professor e seu sal�rio.

    Entrada: professor: ponteiro para registro professor
*/
void imprimirProfessor(p_professor professor) {
    printf("%s %s %.2f\n", professor->nome, professor->sobrenome, professor->salario);
}

int retornaUm() {
    return 1;
}

