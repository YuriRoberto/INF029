#include <stdio.h>
#include <stdlib.h>

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
}

int main() {
  struct EstruturaPrincipal estrutura;
  inicializarEstruturaPrincipal(&estrutura);

  // Libere a memória alocada
  // for (int i = 0; i < 10; i++) {
  //     free(estrutura.auxiliares[i]);
  // }
  return 0;
}