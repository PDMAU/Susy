#include "universidade.h"
#include <string.h>

/*
    Cria um registro professor dinamicamente.

    Entrada: nome: nome do professor
             sobrenome: sobrenome do professor
             salario: sal�rio do professor
             disciplina: disciplina lecionada pelo professor

    Sa�da: retorna um ponteiro para registro professor alocado
*/
p_professor criarProfessor(char nome[], char sobrenome[], double salario, char disciplina[]){
    p_professor professor = malloc(sizeof(Professor));
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
void destruirProfessor(p_professor professor){
    free(p_professor);
}

/*
    Cria um registro aluno dinamicamente, inicialmente sem disciplinas
    matriculadas.

    Entrada: nome: nome do aluno
             sobrenome: sobrenome do aluno

    Saida: retorna um ponteiro para registro aluno alocado
*/
p_aluno criarAluno(char nome[], char sobrenome[]){
    p_aluno aluno = malloc(sizeof(aluno));
    strcpy(aluno->nome, nome);
    strcpy(aluno->sobrenome, sobrenome); 
    return aluno;    
}

/*
    Adiciona uma disciplina � lista de disciplinas de um aluno.

    Entrada: aluno: ponteiro para registro aluno
             disciplina: c�digo da disciplina
             nota: nota correspondente
*/
void adicionarDisciplina(p_aluno aluno, char disciplina[], double nota){
    strcpy(aluno->disciplinas[aluno->qtd_disciplinas],disciplina);
    aluno->notas[aluno->qtd_disciplinas] = nota;
    (aluno->qtd_disciplinas)++;
}

/*
   Libera a mem�ria alocada para registro aluno.

   Entrada: aluno: ponteiro para registro aluno
*/
void destruirAluno(p_aluno aluno){
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
double pegarNotaDoAlunoNaDisclina(p_aluno aluno, char disciplina[]){
    int i;
    for(i=0; i < aluno->qtd_disciplinas; i++){
        if(strcmp(p_aluno->disciplina[i],disciplina) == 0)
            return aluno->notas[i];
    }
}
void obterNotasExtremas(p_aluno alunos[], int qtd_alunos, char disciplina[], double *nota_min, double *nota_max){
    int i;
    double nota;
    if(qtd_alunos>1){
        nota_min = malloc(sizeof(double));
        nota_max = malloc(sizeof(double));
        *nota_min = pegarNotaDoAlunoNaDisclina(alunos[0], disciplina); 
        *nota_max = pegarNotaDoAlunoNaDisclina(alunos[0], disciplina);        
        for(i=1; i < qtd_alunos; i++){            
            nota = pegarNotaDoAlunoNaDisclina(alunos[i], disciplina);
            if(nota > *nota_max){
                *nota_max = nota;
            }else if(nota < *nota_min){
                *nota_min = nota;
            }

        }
    }
}

/*
    Calcula o reajuste salarial do professor e atualiza registro.

    Entrada: professor: ponteiro para registro professor
             media_notas: m�dia entre as notas m�xima e m�nima dos alunos de
             uma determinada disciplina
*/
void reajusteSalario(p_professor professor, double media_notas){
    if(media_notas == 10){
        professor->salario += professor->salario*0.15;
    }else if(media_notas =>9){
        professor->salario += professor->salario*0.10;
    }else if(media_notas => 8.5){
        professor->salario += professor->salario*0.05;
    }
    
}

/*
    Imprime o nome e sobrenome do professor e seu sal�rio.

    Entrada: professor: ponteiro para registro professor
*/
void imprimirProfessor(p_professor professor){
    printf("%s %s %f", professor->nome, professor->sobrenome, professor->salario);
}

