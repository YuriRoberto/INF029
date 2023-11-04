#include <stdio.h>
#include <stdlib.h>

int menu() {
  printf("Digite a opção:\n");
  printf("1  - Inserir elemento\n");
  printf("2  - Listar tamanho da estrutura auxiliar e os elementos\n");
  printf("3  - Listar números ordenados para cada estrutura auxiliar\n");
  printf("4  - Listar todos os números de forma ordenada\n");
  printf("5  - Excluir elemento\n");
  printf("6  - Aumentar tamanho de estrutura auxiliar\n");
  printf("7  - Sair\n");
  int opcao;
  scanf("%d", &opcao);
  if (opcao == 7) {
    printf("Opção 7 selecionada. Saindo do loop.\n");
  }

  return opcao;
}

struct Auxiliar {
  int tamanho;
  int *numeros;
};

struct EstruturaPrincipal {
  struct Auxiliar *auxiliares[10];
};

void inicializarEstruturaPrincipal(struct EstruturaPrincipal *estrutura) {
  for (int i = 0; i < 10; i++) {
    estrutura->auxiliares[i] =
        (struct Auxiliar *)malloc(sizeof(struct Auxiliar));
  }
}

void mallocEstruturaAuxiliar(struct EstruturaPrincipal *estrutura, int indice,
                             int tam) {
  if (estrutura->auxiliares[indice]->tamanho == 0) {
    estrutura->auxiliares[indice]->tamanho = tam;
  } else {
    estrutura->auxiliares[indice]->tamanho =
        estrutura->auxiliares[indice]->tamanho + tam;
  }
  estrutura->auxiliares[indice]->numeros =
      (int *)malloc(sizeof(int) * estrutura->auxiliares[indice]->tamanho);
  printf("Estrutura do indice %d com tamanho %d \n", indice, estrutura->auxiliares[indice]->tamanho);
}

int adicionarElemento(struct EstruturaPrincipal *estrutura, int indice, int elemento) {
    if (indice < 0 || indice >= 10) {
        // Verifique se o índice está dentro do intervalo válido
        return -1; // Índice inválido
    }

    // if (estrutura->auxiliares[indice]->tamanho >= 10) {
    //     return 0; // Estrutura auxiliar está cheia
    // }

    for (int i = 0; i < estrutura->auxiliares[indice]->tamanho; i++) {
      if (estrutura->auxiliares[indice]->numeros[i] == 0 || estrutura->auxiliares[indice]->numeros[i] == NULL) {
       estrutura->auxiliares[indice]->numeros[i] = elemento;
        return 1;
      }
    }
    return 0;
}

int compararInteiros(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void listarTodosNumerosOrdenadosPorEstrutura(struct EstruturaPrincipal *estrutura) {
    for (int i = 0; i < 10; i++) {
        if (estrutura->auxiliares[i]->tamanho > 0) {
            // Ordenar os números usando a função qsort
            qsort(estrutura->auxiliares[i]->numeros, estrutura->auxiliares[i]->tamanho, sizeof(int), compararInteiros);

            printf("Números ordenados na estrutura auxiliar %d:\n", i);
            for (int j = 0; j < estrutura->auxiliares[i]->tamanho; j++) {
                printf("%d ", estrutura->auxiliares[i]->numeros[j]);
            }
            printf("\n");
        }
    }
}


void printAllNumbers(struct EstruturaPrincipal *estrutura) {
  for (int i = 0; i < 10; i++) {
    if (estrutura->auxiliares[i]->tamanho > 0) {
      printf("Estrutura auxiliar %d:\n", i);
      for (int j = 0 ; j < estrutura->auxiliares[i]->tamanho; j++) {
        printf("%d \n", estrutura->auxiliares[i]->numeros[j]);
      } 
    }
  }
}

void excluirElemento(struct EstruturaPrincipal *estrutura, int indice, int elemento) {
  for (int i = 0; i < estrutura->auxiliares[indice]->tamanho; i++){
    if (estrutura->auxiliares[indice]->numeros[i] == elemento) {
      estrutura->auxiliares[indice]->numeros[i] = 0;
    }
  }
}

void listarTodosNumerosOrdenados(struct EstruturaPrincipal *estrutura) {
    int totalNumeros = 0;
    int *todosNumeros = NULL;

    for (int i = 0; i < 10; i++) {
        if (estrutura->auxiliares[i]->tamanho > 0) {
            totalNumeros += estrutura->auxiliares[i]->tamanho;
            todosNumeros = (int *)realloc(todosNumeros, totalNumeros * sizeof(int));
            for (int j = 0; j < estrutura->auxiliares[i]->tamanho; j++) {
                todosNumeros[totalNumeros - estrutura->auxiliares[i]->tamanho + j] = estrutura->auxiliares[i]->numeros[j];
            }
        }
    }

    // Ordenar todos os números
    qsort(todosNumeros, totalNumeros, sizeof(int), compararInteiros);

    printf("Números ordenados em todas as estruturas auxiliares:\n");
    for (int i = 0; i < totalNumeros; i++) {
        printf("%d ", todosNumeros[i]);
    }
    printf("\n");

    free(todosNumeros);
}

int main() {
  int start = 1;
  struct EstruturaPrincipal estrutura;
  inicializarEstruturaPrincipal(&estrutura);

  while (start) {
    int opcao = menu();
    if (opcao == 1) {
      int indice;
      printf("Qual o indice?\n");
      scanf("%d", &indice);
      int elemento;
      printf("Qual o elemento?\n");
      scanf("%d", &elemento);
      int resultado = adicionarElemento(&estrutura, indice, elemento);

      if (resultado == -1) {
          printf("Índice inválido.\n");
      } else if (resultado == 0) {
          printf("Estrutura auxiliar está cheia.\n");
      } else {
          printf("Elemento adicionado com sucesso.\n");
      }
    }
    if (opcao == 2) {
      printAllNumbers(&estrutura);
    }
    if (opcao == 3) {
        listarTodosNumerosOrdenadosPorEstrutura(&estrutura);
    }
    if (opcao == 4) {
      listarTodosNumerosOrdenados(&estrutura);
    }
    if (opcao == 5) {
      int elemento, indice;
      printf("Qual o indice?\n");
      scanf("%d", &indice);
      printf("Qual o elemento?\n");
      scanf("%d", &elemento);
      excluirElemento(&estrutura, indice, elemento);
    }
    if (opcao == 6) {
      int indice, tam;
      printf("Qual o indice?\n");
      scanf("%d", &indice);
      printf("Qual o tamanho?\n");
      scanf("%d", &tam);
      mallocEstruturaAuxiliar(&estrutura, indice, tam);
    }
    if (opcao == 7) {
      break;
    }
  }
  
  // Libere a memória alocada
  // for (int i = 0; i < 10; i++) {
  //     free(estrutura.auxiliares[i]);
  // }
  return 0;
}