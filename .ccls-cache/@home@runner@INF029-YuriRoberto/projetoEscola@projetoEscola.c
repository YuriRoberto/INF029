#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct date {
  int day;
  int month;
  int year;
} Date;

typedef struct studentData {
  int registration;
  char name[50];
  char gender;
  Date birthDay;
  char individualRegistration[15];
  int currentMatters;
} Student;

typedef struct teacherData {
  int registration;
  char name[50];
  char gender;
  Date birthDay;
  char individualRegistration[15];
} Teacher;

typedef struct matterData {
  int code;
  char name[50];
  char semester;
  int registrationTeacher;
  int indexStudentsInMatter;
  int students[45];
} Matter;

int menu() {
  printf("Digite a opção:\n");
  printf("0  - Sair\n");
  printf("1  - Cadastrar Aluno\n");
  printf("2  - Cadastrar Professor\n");
  printf("3  - Cadastrar Disciplina\n");
  printf("4  - Listar Alunos\n");
  printf("5  - Listar Professores\n");
  printf("6  - Listar Disciplinas\n");
  printf("7  - Listar Alunos por sexo\n");
  printf("8  - Listar Professores por sexo\n");
  printf("9  - Listar Alunos por ordem de nome\n");
  printf("10 - Listar Professores por ordem de nome\n");
  printf("11 - Inserir aluno em Disciplina\n");
  printf("12 - Listar alunos de uma Disciplina\n");
  printf("13 - Excluir aluno\n");
  printf("14 - Excluir professor\n");
  printf("15 - Atualizar cadastro de aluno\n");
  printf("16 - Atualizar cadastro de professor\n");
  printf("17 - Exibir aniversarintes do mes\n");
  printf("18 - Buscar nomes\n");
  printf("19 - Listar alunos que tem menos que 3 disciplinas matriculadas\n");
  int opcao;
  scanf("%d", &opcao);
  if (opcao == 0) {
    printf("Opção 0 selecionada. Saindo do loop.\n");
  }

  return opcao;
}

int menuUpdate() {
  printf("Digite a opção:\n");
  printf("1  - Atualizar matricula\n");
  printf("2  - Atualizar nome\n");
  printf("3  - Atualizar sexo\n");
  printf("4  - Atualizar data de nascimento\n");
  printf("5  - Atualizar CPF\n");
  int opcao;
  scanf("%d", &opcao);
  return opcao;
}

const char *findTeacherByRegistration(Teacher listTeacher[], int tam,
                                      int registration) {
  for (int i = 0; i < tam; i++) {
    if (listTeacher[i].registration == registration) {
      return listTeacher[i].name;
    }
  }
  return "Professor não encontrado";
}

const char *findStudentByRegistration(Student listStudent[], int tam,
                                      int registration) {
  for (int i = 0; i < tam; i++) {
    if (listStudent[i].registration == registration) {
      return listStudent[i].name;
    }
  }
  return "Aluno não encontrado";
}

void registerStudent(Student student[], int index) {
  printf("Digite a matricula:\n");
  scanf("%d", &student[index].registration);
  printf("Digite o nome do aluno:\n");
  scanf("%s", student[index].name);
  printf("Digite o sexo do aluno:\n");
  scanf(" %c", &student[index].gender);
  // Limpar o buffer de entrada
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;

  printf("Digite o dia de nascimento do aluno:\n");
  scanf("%d", &student[index].birthDay.day);
  printf("Digite o mes de nascimento do aluno:\n");
  scanf("%d", &student[index].birthDay.month);
  printf("Digite o ano de nascimento do aluno:\n");
  scanf("%d", &student[index].birthDay.year);
  printf("Digite o CPF do aluno:\n");
  scanf("%s", student[index].individualRegistration);
  return;
}

void registerTeacher(Teacher teacher[], int index) {
  printf("Digite a matricula:\n");
  scanf("%d", &teacher[index].registration);
  printf("Digite o nome do professor:\n");
  scanf("%s", teacher[index].name);
  printf("Digite o sexo do professor:\n");
  scanf(" %c", &teacher[index].gender);
  // Limpar o buffer de entrada
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;

  printf("Digite o dia de nascimento do professor:\n");
  scanf("%d", &teacher[index].birthDay.day);
  printf("Digite o mes de nascimento do professor:\n");
  scanf("%d", &teacher[index].birthDay.month);
  printf("Digite o ano de nascimento do professor:\n");
  scanf("%d", &teacher[index].birthDay.year);
  printf("Digite o CPF do professor:\n");
  scanf("%s", teacher[index].individualRegistration);
  return;
}

void registerMatter(Matter matter[], int indexMatter) {
  printf("Digite o codigo da materia:\n");
  scanf("%d", &matter[indexMatter].code);
  printf("Digite o nome da materia:\n");
  scanf("%s", matter[indexMatter].name);
  printf("Digite o semestre:\n");
  scanf(" %c", &matter[indexMatter].semester);
  printf("Digite a matricula do professor da disciplina:\n");
  scanf("%d", &matter[indexMatter].registrationTeacher);
  matter[indexMatter].indexStudentsInMatter = 0;
  // implementar busca de professor baseada na matricula inserida pelo usuario
  // implementar busca de aluno baseada na matricula inserida pelo usuario
  // implementar loop em caso de mais de um aluno a ser adicionado na disciplina
  return;
}

void printStudent(Student listStudent[], int tam) {
  for (int i = 0; i < tam; i++) {
    printf("Aluno %d:\n", i + 1);
    printf("Matricula: %d\n", listStudent[i].registration);
    printf("Nome: %s\n", listStudent[i].name);
    printf("Sexo: %c\n", listStudent[i].gender);
    printf("Data de nascimento: %d/%d/%d\n", listStudent[i].birthDay.day,
           listStudent[i].birthDay.month, listStudent[i].birthDay.year);
    printf("CPF: %s\n", listStudent[i].individualRegistration);
    printf("\n");
  }
}

void printTeacher(Teacher listTeacher[], int tam) {
  for (int i = 0; i < tam; i++) {
    printf("Professor %d:\n", i + 1);
    printf("Matricula: %d\n", listTeacher[i].registration);
    printf("Nome: %s\n", listTeacher[i].name);
    printf("Sexo: %c\n", listTeacher[i].gender);
    printf("Data de nascimento: %d/%d/%d\n", listTeacher[i].birthDay.day,
           listTeacher[i].birthDay.month, listTeacher[i].birthDay.year);
    printf("CPF: %s\n", listTeacher[i].individualRegistration);
    printf("\n");
  }
}

void printMatter(Matter listMatter[], int tam, Teacher listTeacher[],
                 int indexTeacher) {
  for (int i = 0; i < tam; i++) {
    printf("Materia %d:\n", i + 1);
    printf("Codigo: %d\n", listMatter[i].code);
    printf("Nome: %s\n", listMatter[i].name);
    printf("Semestre: %c\n", listMatter[i].semester);
    const char *nameTeacher = findTeacherByRegistration(
        listTeacher, indexTeacher, listMatter[i].registrationTeacher);
    printf("Professor: %s\n", nameTeacher);
    printf("\n");
  }
}

void printStudentByGender(Student listStudent[], int tam, char genderFilter) {
  for (int i = 0; i < tam; i++) {
    if (listStudent[i].gender == genderFilter) {
      printf("Aluno %d:\n", i + 1);
      printf("Matricula: %d\n", listStudent[i].registration);
      printf("Nome: %s\n", listStudent[i].name);
      printf("Sexo: %c\n", listStudent[i].gender);
      printf("Data de nascimento: %d/%d/%d\n", listStudent[i].birthDay.day,
             listStudent[i].birthDay.month, listStudent[i].birthDay.year);
      printf("CPF: %s\n", listStudent[i].individualRegistration);
      printf("\n");
    }
  }
}

void printTeacherByGender(Teacher listTeacher[], int tam, char genderFilter) {
  for (int i = 0; i < tam; i++) {
    if (listTeacher[i].gender == genderFilter) {
      printf("Professor %d:\n", i + 1);
      printf("Matricula: %d\n", listTeacher[i].registration);
      printf("Nome: %s\n", listTeacher[i].name);
      printf("Sexo: %c\n", listTeacher[i].gender);
      printf("Data de nascimento: %d/%d/%d\n", listTeacher[i].birthDay.day,
             listTeacher[i].birthDay.month, listTeacher[i].birthDay.year);
      printf("CPF: %s\n", listTeacher[i].individualRegistration);
      printf("\n");
    }
  }
}

//(Student *)a e (Student *)b são castings dos ponteiros a e b para ponteiros de
// tipo Student. Isso é necessário porque os ponteiros a e b são do tipo const
// void *, e precisamos convertê-los de volta ao tipo Student * para acessar o
// campo name.

// Retorna um valor negativo se a < b e um positivo se a > b e 0 se forem iguais
// Como 4º parametro na func qsort() ele precisa de um ponteiro para uma função
// de comparação que determina a ordem dos elementos, por isso a criação desta
// func abaixo
int compareStudentsByName(const void *a, const void *b) {
  return strcmp(((Student *)a)->name, ((Student *)b)->name);
}

void printStudentsSortedByName(Student listStudent[], int tam) {
  // Primeiro, ordenamos o array de alunos com base em seus nomes
  qsort(listStudent, tam, sizeof(Student), compareStudentsByName);

  // Agora, podemos imprimir os alunos ordenados por nome
  printf("Alunos ordenados por nome:\n");
  printStudent(listStudent, tam);
}

int compareTeachersByName(const void *a, const void *b) {
  return strcmp(((Teacher *)a)->name, ((Teacher *)b)->name);
}

void printTeachersSortedByName(Teacher listTeacher[], int tam) {
  qsort(listTeacher, tam, sizeof(Teacher), compareTeachersByName);
  printf("Professores ordenados por nome:\n");
  printTeacher(listTeacher, tam);
}

void insertStudentInMatter(Matter listMatter[], int indexMatter,
                           Student listStudent[], int indexStudent) {
  int codeMatter;
  printf("Digite o codigo da materia:\n");
  scanf("%d", &codeMatter);
  int registrationStudent;
  printf("Digite a matricula do aluno:\n");
  scanf("%d", &registrationStudent);
  // Percorrer todas as materias
  for (int i = 0; i < indexMatter; i++) {
    // Responder que a matéria nao existe
    if (i == indexMatter - 1 && listMatter[i].code != codeMatter) {
      printf("Disciplina não encontrada.\n");
      return;
    }
    // Achar a materia
    if (codeMatter == listMatter[i].code) {
      // Responder se a materia estiver lotada
      if (listMatter[i].indexStudentsInMatter >= 45) {
        printf("A disciplina já atingiu o limite de alunos.\n");
        return;
      }
      // Verificar se o aluno ja esta matriculado na materia
      for (int j = 0; j < listMatter[i].indexStudentsInMatter; j++) {
        if (registrationStudent == listMatter[i].students[j]) {
          printf("Aluno ja matriculado na disciplina.\n");
          return;
        }
      }
      // Adicionar aluno a disciplina
      int temporaryIndexStudentsInMatter = listMatter[i].indexStudentsInMatter;
      listMatter[i].students[temporaryIndexStudentsInMatter] =
          registrationStudent;
      listMatter[i].indexStudentsInMatter++;
      // Printar o aluno adicionado
      const char *nameStudent = findStudentByRegistration(
          listStudent, indexStudent, registrationStudent);
      if (nameStudent != NULL) {
        printf("Aluno %s adicionado na disciplina %s.\n", nameStudent,
               listMatter[i].name);
        for (int j = 0; j > indexStudent; j++) {
          if (nameStudent == listStudent[j].name) {
            listStudent[j].currentMatters++;
          }
          break;
        }
        return;
      }
    }
  }
}

void printMatterAndYoursStudents(Matter listMatter[], int indexMatter,
                                 Student listStudent[], int indexStudent) {
  int codeMatter;
  printf("Digite o codigo da materia:\n");
  scanf("%d", &codeMatter);
  // Percorrer todas as materias
  for (int i = 0; i < indexMatter; i++) {
    // Achar a materia
    if (codeMatter == listMatter[i].code) {
      printf("Materia: %s \n", listMatter[i].name);
      int temporaryIndexStudentsInMatter = listMatter[i].indexStudentsInMatter;
      // Printar todos os alunos
      printf("Alunos:\n");
      for (int j = 0; j < temporaryIndexStudentsInMatter; j++) {
        const char *nameStudent = findStudentByRegistration(
            listStudent, indexStudent, listMatter[i].students[j]);
        printf("%s\n", nameStudent);
      }
      return;
    }
  }
  printf("Disciplina nao encontrada:\n");
  return;
}

void removeStudentByRegistration(Student listStudent[], int *indexStudent,
                                 int registration) {
  int found = 0;
  int removedIndex = -1;
  for (int i = 0; i < *indexStudent; i++) {
    if (listStudent[i].registration == registration) {
      found = 1;
      removedIndex = i;
      break;
    }
  }

  if (found) {
    for (int i = removedIndex; i < (*indexStudent - 1); i++) {
      listStudent[i] = listStudent[i + 1];
    }
    (*indexStudent)--;
    printf("Aluno removido com sucesso!\n");
  } else {
    printf("Aluno não encontrado.\n");
  }
}

void removeTeacherByRegistration(Teacher listTeacher[], int *indexTeacher,
                                 int registration) {
  int found = 0;
  int removedIndex = -1;
  for (int i = 0; i < *indexTeacher; i++) {
    if (listTeacher[i].registration == registration) {
      found = 1;
      removedIndex = i;
      break;
    }
  }

  if (found) {
    for (int i = removedIndex; i < (*indexTeacher - 1); i++) {
      listTeacher[i] = listTeacher[i + 1];
    }
    (*indexTeacher)--;
    printf("Professor removido com sucesso!\n");
  } else {
    printf("Professor não encontrado.\n");
  }
}

void removeStudentFromAllMatters(Matter listMatter[], int indexMatter,
                                 int studentRegistration) {
  for (int i = 0; i < indexMatter; i++) {
    int found = 0;
    // Variável para indicar se o aluno foi encontrado na disciplina
    // Procurar o aluno no array de matrículas da disciplina
    for (int j = 0; j < listMatter[i].indexStudentsInMatter; j++) {
      if (listMatter[i].students[j] == studentRegistration) {
        found = 1;
        // Remover o aluno movendo os elementos à direita dele para a esquerda
        for (int k = j; k < (listMatter[i].indexStudentsInMatter - 1); k++) {
          listMatter[i].students[k] = listMatter[i].students[k + 1];
        }
        // Decrementar o índice de alunos na disciplina
        listMatter[i].indexStudentsInMatter--;
        break;
      }
    }
    if (found) {
      printf("Aluno removido da disciplina '%s'.\n", listMatter[i].name);
    }
  }
}

void removeTeacherFromAllMatters(Matter listMatter[], int indexMatter,
                                 int teacherRegistration) {
  int found = 0;
  for (int i = 0; i < indexMatter; i++) {
    if (listMatter[i].registrationTeacher == teacherRegistration) {
      found = 1;
      listMatter[i].registrationTeacher = 0;
      break;
    }
  }
  if (found) {
    printf("Professor removido da disciplina.\n");
  }
}

void updateStudentByRegistration(Student listStudent[], int indexStudent,
                                 int registration) {
  int found = 0;
  int updatedIndex = -1;
  for (int i = 0; i < indexStudent; i++) {
    if (listStudent[i].registration == registration) {
      found = 1;
      updatedIndex = i;
      break;
    }
  }

  if (found) {
    int opcao = menuUpdate();
    if (opcao == 1) {
      printf("Digite a matricula.\n");
      scanf("%d", &listStudent[updatedIndex].registration);
    }
    if (opcao == 2) {
      printf("Digite o nome.\n");
      scanf("%s", listStudent[updatedIndex].name);
    }
    if (opcao == 3) {
      printf("Digite o sexo.\n");
      scanf(" %c", &listStudent[updatedIndex].gender);
      int c;
      while ((c = getchar()) != '\n' && c != EOF)
        ;
    }
    if (opcao == 4) {
      printf("Digite o dia de nascimento:\n");
      scanf("%d", &listStudent[updatedIndex].birthDay.day);
      printf("Digite o mes de nascimento:\n");
      scanf("%d", &listStudent[updatedIndex].birthDay.month);
      printf("Digite o ano de nascimento:\n");
      scanf("%d", &listStudent[updatedIndex].birthDay.year);
    }
    if (opcao == 5) {
      printf("Digite o CPF.\n");
      scanf("%s", listStudent[updatedIndex].individualRegistration);
    }
    printf("Aluno atualizado com sucesso!\n");
  } else {
    printf("Aluno não encontrado.\n");
  }
}

void updateTeacherByRegistration(Teacher listTeacher[], int indexTeacher,
                                 int registration) {
  int found = 0;
  int updatedIndex = -1;
  for (int i = 0; i < indexTeacher; i++) {
    if (listTeacher[i].registration == registration) {
      found = 1;
      updatedIndex = i;
      break;
    }
  }

  if (found) {
    int opcao = menuUpdate();
    if (opcao == 1) {
      printf("Digite a matricula.\n");
      scanf("%d", &listTeacher[updatedIndex].registration);
    }
    if (opcao == 2) {
      printf("Digite o nome.\n");
      scanf("%s", listTeacher[updatedIndex].name);
    }
    if (opcao == 3) {
      printf("Digite o sexo.\n");
      scanf(" %c", &listTeacher[updatedIndex].gender);
      int c;
      while ((c = getchar()) != '\n' && c != EOF)
        ;
    }
    if (opcao == 4) {
      printf("Digite o dia de nascimento:\n");
      scanf("%d", &listTeacher[updatedIndex].birthDay.day);
      printf("Digite o mes de nascimento:\n");
      scanf("%d", &listTeacher[updatedIndex].birthDay.month);
      printf("Digite o ano de nascimento:\n");
      scanf("%d", &listTeacher[updatedIndex].birthDay.year);
    }
    if (opcao == 5) {
      printf("Digite o CPF.\n");
      scanf("%s", listTeacher[updatedIndex].individualRegistration);
    }
    printf("Professor atualizado com sucesso!\n");
  } else {
    printf("Professor não encontrado.\n");
  }
}

void searchBirhMonth(Teacher listTeacher[], int indexTeacher,
                     Student listStudent[], int indexStudent, int birthMonth) {
  printf("Professores que fazem aniversario.\n");
  for (int i = 0; i < indexTeacher; i++) {
    if (listTeacher[i].birthDay.month == birthMonth) {
      printf("%s \n", listTeacher[i].name);
    }
  }
  printf("Alunos que fazem aniversario.\n");
  for (int i = 0; i < indexStudent; i++) {
    if (listStudent[i].birthDay.month == birthMonth) {
      printf("%s \n", listStudent[i].name);
    }
  }
}

void printMatterFullClass(Matter listMatter[], int tam, Teacher listTeacher[],
                          int indexTeacher) {
  for (int i = 0; i < tam; i++) {
    if (listMatter[i].indexStudentsInMatter >= 40) {
      printf("Materia %d:\n", i + 1);
      printf("Codigo: %d\n", listMatter[i].code);
      printf("Nome: %s\n", listMatter[i].name);
      printf("Semestre: %c\n", listMatter[i].semester);
      const char *nameTeacher = findTeacherByRegistration(
          listTeacher, indexTeacher, listMatter[i].registrationTeacher);
      printf("Professor: %s\n", nameTeacher);
      printf("\n");
    }
  }
}

void searchByName(Student listStudent[], int numStudents, Teacher listTeacher[],
                  int numTeachers, const char *searchString) {
  int found =
      0; // Variável para indicar se alguma correspondência foi encontrada

  // Procurar nos alunos
  printf("Alunos com '%s' no nome:\n", searchString);
  for (int i = 0; i < numStudents; i++) {
    if (strstr(listStudent[i].name, searchString) != NULL) {
      printf("Matricula: %d, Nome: %s\n", listStudent[i].registration,
             listStudent[i].name);
      found = 1;
    }
  }

  // Procurar nos professores
  printf("\nProfessores com '%s' no nome:\n", searchString);
  for (int i = 0; i < numTeachers; i++) {
    if (strstr(listTeacher[i].name, searchString) != NULL) {
      printf("Matricula: %d, Nome: %s\n", listTeacher[i].registration,
             listTeacher[i].name);
      found = 1;
    }
  }

  if (!found) {
    printf("Nenhum aluno ou professor encontrado com '%s' no nome.\n",
           searchString);
  }
}

void printStudentLowMatter(Student listStudent[], int tam) {
  for (int i = 0; i < tam; i++) {
    if (listStudent[i].currentMatters < 3) {
      printf("Aluno %d:\n", i + 1);
      printf("Matricula: %d\n", listStudent[i].registration);
      printf("Nome: %s\n", listStudent[i].name);
      printf("Sexo: %c\n", listStudent[i].gender);
      printf("Data de nascimento: %d/%d/%d\n", listStudent[i].birthDay.day,
             listStudent[i].birthDay.month, listStudent[i].birthDay.year);
      printf("CPF: %s\n", listStudent[i].individualRegistration);
      printf("\n");
    }
  }
}

int compareStudentsByBirthDate(const void *a, const void *b) {
  const Student *studentA = (const Student *)a;
  const Student *studentB = (const Student *)b;

  // Primeiro, compare anos de nascimento
  if (studentA->birthDay.year < studentB->birthDay.year) {
    return -1;
  } else if (studentA->birthDay.year > studentB->birthDay.year) {
    return 1;
  } else {
    // Se os anos de nascimento forem iguais, compare meses de nascimento
    if (studentA->birthDay.month < studentB->birthDay.month) {
      return -1;
    } else if (studentA->birthDay.month > studentB->birthDay.month) {
      return 1;
    } else {
      // Se os meses de nascimento forem iguais, compare dias de nascimento
      if (studentA->birthDay.day < studentB->birthDay.day) {
        return -1;
      } else if (studentA->birthDay.day > studentB->birthDay.day) {
        return 1;
      } else {
        // Se todas as datas de nascimento forem iguais, retorne 0
        return 0;
      }
    }
  }
}

void printStudentsByBirthDate(Student listStudent[], int numStudents) {
  // Primeiro, ordene o vetor de alunos por data de nascimento
  qsort(listStudent, numStudents, sizeof(Student), compareStudentsByBirthDate);

  // Agora, imprima a lista ordenada
  printf("Alunos ordenados por data de nascimento:\n");
  for (int i = 0; i < numStudents; i++) {
    printf("Matricula: %d, Nome: %s, Data de Nascimento: %d/%d/%d\n",
           listStudent[i].registration, listStudent[i].name,
           listStudent[i].birthDay.day, listStudent[i].birthDay.month,
           listStudent[i].birthDay.year);
  }
}

void printTeachersByBirthDate(Teacher listTeacher[], int numTeachers) {
  qsort(listTeacher, numTeachers, sizeof(Teacher), compareStudentsByBirthDate);
  printf("Alunos ordenados por data de nascimento:\n");
  for (int i = 0; i < numTeachers; i++) {
    printf("Matricula: %d, Nome: %s, Data de Nascimento: %d/%d/%d\n",
           listTeacher[i].registration, listTeacher[i].name,
           listTeacher[i].birthDay.day, listTeacher[i].birthDay.month,
           listTeacher[i].birthDay.year);
  }
}

int main(void) {
  int indexStudent = 3, indexTeacher = 3, indexMatter = 0;
  int start = 1;
  Student listStudent[40] = {
      {45, "Maria Silva", 'F', {10, 5, 2000}, "1234567890", 3},
      {15, "Teca", 'F', {15, 12, 1992}, "1234567890", 2},
      {20, "Yuri Roberto", 'M', {26, 5, 1994}, "1234567890", 2}};
  Teacher listTeacher[40] = {
      {45, "Maria SilvaT", 'F', {10, 5, 2000}, "1234567890"},
      {15, "TecaT", 'F', {15, 12, 1992}, "1234567890"},
      {20, "Yuri RobertoT", 'M', {26, 5, 1994}, "1234567890"}};
  Matter listMatter[40];
  while (start) {
    int opcao = menu();

    if (opcao == 0) {
      break;
    }
    if (opcao == 1) {
      registerStudent(listStudent, indexStudent);
      indexStudent++;
    }
    if (opcao == 2) {
      registerTeacher(listTeacher, indexTeacher);
      indexTeacher++;
    }
    if (opcao == 3) {
      registerMatter(listMatter, indexMatter);
      indexMatter++;
    }
    if (opcao == 4) {
      printf("Listando alunos:\n");
      printStudent(listStudent, indexStudent);
    }
    if (opcao == 5) {
      printTeacher(listTeacher, indexTeacher);
    }
    if (opcao == 6) {
      printMatter(listMatter, indexMatter, listTeacher, indexTeacher);
    }
    if (opcao == 7) {
      char genderFilterStudent;
      printf("Digite o sexo selecionado para a filtragem:\n");
      scanf(" %c", &genderFilterStudent);
      // Limpar o buffer de entrada
      int c;
      while ((c = getchar()) != '\n' && c != EOF)
        ;

      printStudentByGender(listStudent, indexStudent, genderFilterStudent);
    }
    if (opcao == 8) {
      char genderFilterTeacher;
      printf("Digite o sexo selecionado para a filtragem:\n");
      scanf(" %c", &genderFilterTeacher);
      // Limpar o buffer de entrada
      int c;
      while ((c = getchar()) != '\n' && c != EOF)
        ;

      printTeacherByGender(listTeacher, indexTeacher, genderFilterTeacher);
    }
    if (opcao == 9) {
      printStudentsSortedByName(listStudent, indexStudent);
    }
    if (opcao == 10) {
      printTeachersSortedByName(listTeacher, indexTeacher);
    }
    if (opcao == 11) {
      insertStudentInMatter(listMatter, indexMatter, listStudent, indexStudent);
    }
    if (opcao == 12) {
      printMatterAndYoursStudents(listMatter, indexMatter, listStudent,
                                  indexStudent);
    }
    if (opcao == 13) {
      int registrationToDelete;
      printf("Digite a matricula do aluno que deseja excluir:\n");
      scanf("%d", &registrationToDelete);
      removeStudentFromAllMatters(listMatter, indexMatter,
                                  registrationToDelete);
      removeStudentByRegistration(listStudent, &indexStudent,
                                  registrationToDelete);
    }
    if (opcao == 14) {
      int registrationToDelete;
      printf("Digite a matricula do professor que deseja excluir:\n");
      scanf("%d", &registrationToDelete);
      removeTeacherFromAllMatters(listMatter, indexMatter,
                                  registrationToDelete);
      removeTeacherByRegistration(listTeacher, &indexTeacher,
                                  registrationToDelete);
    }
    if (opcao == 15) {
      int registrationToUpdate;
      printf("Digite a matricula do aluno que deseja atualizar:\n");
      scanf("%d", &registrationToUpdate);
      updateStudentByRegistration(listStudent, indexStudent,
                                  registrationToUpdate);
    }
    if (opcao == 16) {
      int registrationToUpdate;
      printf("Digite a matricula do professor que deseja atualizar:\n");
      scanf("%d", &registrationToUpdate);
      updateTeacherByRegistration(listTeacher, indexTeacher,
                                  registrationToUpdate);
    }
    if (opcao == 17) {
      int birthMonth;
      printf("Para eu lhe informar os aniversariantes do mes, em que mes "
             "estamos?:\n");
      scanf("%d", &birthMonth);
      searchBirhMonth(listTeacher, indexTeacher, listStudent, indexStudent,
                      birthMonth);
    }
    if (opcao == 18) {
      char searchString[50];
      printf("Digite a string de busca:\n");
      scanf("%s", searchString);

      searchByName(listStudent, indexStudent, listTeacher, indexTeacher,
                   searchString);
    }
    if (opcao == 19) {
      printf("Listando alunos:\n");
      printStudentLowMatter(listStudent, indexStudent);
    }
    if (opcao == 20) {
      printf("Listando alunos por data de nascimento:\n");
      printStudentsByBirthDate(listStudent, indexStudent);
    }
    if (opcao == 21) {
      printf("Listando professores por data de nascimento:\n");
      printTeachersByBirthDate(listTeacher, indexTeacher);
    }
  }
  return 1;
}