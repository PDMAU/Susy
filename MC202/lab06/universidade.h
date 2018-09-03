#ifndef UNIVERSIDADE_H
#define UNIVERSIDADE_H
#define MAX_NOME 30
#define MAX_CODIGO 6
#define MAX_DISCIPLINAS 5

typedef struct {
    char nome[MAX_NOME];
    char sobrenome[MAX_NOME];
    double salario;
    char disciplina[MAX_CODIGO];
} Professor;
typedef Professor * p_professor;

typedef struct {
    char nome[MAX_NOME];
    char sobrenome[MAX_NOME];
    int qtd_disciplinas;
    char disciplinas[MAX_DISCIPLINAS][MAX_CODIGO];
    double notas[MAX_DISCIPLINAS];
} Aluno;
typedef Aluno * p_aluno;

/*
    Cria um registro professor dinamicamente.

    Entrada: nome: nome do professor
             sobrenome: sobrenome do professor
             salario: sal�rio do professor
             disciplina: disciplina lecionada pelo professor

    Sa�da: retorna um ponteiro para registro professor alocado
*/
p_professor criarProfessor(char nome[], char sobrenome[], double salario, char disciplina[]);

/*
    Libera a mem�ria alocada para registro professor.

    Entrada: professor: ponteiro para registro professor
*/
void destruirProfessor(p_professor professor);

/*
    Cria um registro aluno dinamicamente, inicialmente sem disciplinas
    matriculadas.

    Entrada: nome: nome do aluno
             sobrenome: sobrenome do aluno

    Saida: retorna um ponteiro para registro aluno alocado
*/
p_aluno criarAluno(char nome[], char sobrenome[]);

/*
    Adiciona uma disciplina � lista de disciplinas de um aluno.

    Entrada: aluno: ponteiro para registro aluno
             disciplina: c�digo da disciplina
             nota: nota correspondente
*/
void adicionarDisciplina(p_aluno aluno, char disciplina[], double nota);

/*
   Libera a mem�ria alocada para registro aluno.

   Entrada: aluno: ponteiro para registro aluno
*/
void destruirAluno(p_aluno aluno);

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
void obterNotasExtremas(p_aluno alunos[], int qtd_alunos, char disciplina[], double *nota_min, double *nota_max);

/*
    Calcula o reajuste salarial do professor e atualiza registro.

    Entrada: professor: ponteiro para registro professor
             media_notas: m�dia entre as notas m�xima e m�nima dos alunos de
             uma determinada disciplina
*/
void reajusteSalario(p_professor professor, double media_notas);

/*
    Imprime o nome e sobrenome do professor e seu sal�rio.

    Entrada: professor: ponteiro para registro professor
*/
void imprimirProfessor(p_professor professor);

#endif /* UNIVERSIDADE_H */

