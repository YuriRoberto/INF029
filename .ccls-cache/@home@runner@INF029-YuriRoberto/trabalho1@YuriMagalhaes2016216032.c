// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do
//  trabalho

//  ----- Dados do Aluno -----
//  Nome: Yuri Roberto Carvalho Magalhães
//  email: yurirobertocm@gmail.com
//  Matrícula: 2016216032
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include "YuriMagalhaes2016216032.h" // Substitua pelo seu arquivo de header renomeado
#include <stdio.h>
#include <stdlib.h>
/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y) {
  int soma;
  soma = x + y;
  return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x) { // função utilizada para testes
  int i, fat = 1;

  for (i = x; i > 1; i--)
    fat = fat * i;

  return fat;
}

int teste(int a) {
  int val;
  if (a == 2)
    val = 3;
  else
    val = 4;

  return val;
}

// DataQuebrada quebraData(char data[]) {
//   DataQuebrada dq;
//   char sDia[3];
//   char sMes[3];
//   char sAno[5];
//   int i;

//   for (i = 0; data[i] != '/'; i++) {
//     sDia[i] = data[i];
//   }
//   if (i == 1 || i == 2) { // testa se tem 1 ou dois digitos
//     sDia[i] = '\0';       // coloca o barra zero no final
//   } else {
//     dq.valido = 0;
//     return dq;
//   }

//   int j = i + 1; // anda 1 cada para pular a barra
//   i = 0;

//   for (; data[j] != '/'; j++) {
//     sMes[i] = data[j];
//     i++;
//   }

//   if (i == 1 || i == 2) { // testa se tem 1 ou dois digitos
//     sMes[i] = '\0';       // coloca o barra zero no final
//   } else {
//     dq.valido = 0;
//     return dq;
//   }

//   j = j + 1; // anda 1 cada para pular a barra
//   i = 0;

//   for (; data[j] != '\0'; j++) {
//     sAno[i] = data[j];
//     i++;
//   }

//   if (i == 2 || i == 4) { // testa se tem 2 ou 4 digitos
//     sAno[i] = '\0';       // coloca o barra zero no final
//   } else {
//     dq.valido = 0;
//     return dq;
//   }

//   dq.iDia = atoi(sDia);
//   dq.iMes = atoi(sMes);
//   dq.iAno = atoi(sAno);

//   dq.valido = 1;

//   return dq;
// }
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia,
mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa
podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)
    pode utilizar strlen para pegar o tamanho da string
 */

int isValidDate(char data[]) {
  int day, month, year;
  char separator1, separator2;
  int result = sscanf(data, "%d/%d/%d%c%d", &day, &month, &year, &separator1,
                      &separator2);

  if ((result == 3 || result == 4) &&
      (separator1 == '/' || separator2 == '/') && year >= 0) {
    if (year >= 1500 && year <= 2024) {
      if (month >= 1 && month <= 12) {
        int daysInMonth[] = {
            0,
            31,
            28 + ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)),
            31,
            30,
            31,
            30,
            31,
            31,
            30,
            31,
            30,
            31};
        if (day >= 1 && day <= daysInMonth[month]) {
          return 1; // A data é válida
        }
      }
    }
  }
  return 0; // A data não é válida
}

int q1(char data[]) {
  int datavalida = 1;
  datavalida = isValidDate(data);

  // quebrar a string data em strings sDia, sMes, sAno
  // DataQuebrada dataQuebrada = quebraData(data);
  // if (dataQuebrada.valido == 0) return 0;

  printf("%s\n", data);

  if (datavalida)
    return 1;
  else
    return 0;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal.
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis
 valores abaixo 1 -> cálculo de diferença realizado com sucesso 2 -> datainicial
 inválida 3 -> datafinal inválida 4 -> datainicial > datafinal Caso o cálculo
 esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos
 com os valores correspondentes.
 */
// DiasMesesAnos q2(char datainicial[], char datafinal[]) {

//   // calcule os dados e armazene nas três variáveis a seguir
//   DiasMesesAnos dma;

//   if (q1(datainicial) == 0) {
//     dma.retorno = 2;
//     return dma;
//   } else if (q1(datafinal) == 0) {
//     dma.retorno = 3;
//     return dma;
//   } else {
//     // verifique se a data final não é menor que a data inicial

//     // calcule a distancia entre as datas

//     // se tudo der certo
//     dma.retorno = 1;
//     return dma;
//   }
// }

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa
 Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar
 diferenças entre maiúsculos e minúsculos. Se isCaseSensitive != 1, a pesquisa
 não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */

int validateCharOcurrence(char *texto, char s, int isCaseSensitive) {
  int count = 0;

  while (*texto != '\0') {
    char currentChar = *texto;
    if (isCaseSensitive == 1) {
      if (currentChar == s) {
        count++;
      }
    } else {
      if (tolower(currentChar) == tolower(s)) {
        count++;
      }
    }
    texto++;
  }

  return count;
}

int q3(char *texto, char c, int isCaseSensitive) {
  int qtdOcorrencias = -1;
  qtdOcorrencias = validateCharOcurrence(*texto, c, isCaseSensitive);
  return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros
 (posicoes) que irá guardar as posições de início e fim de cada ocorrência da
 palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída
 correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do
 vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve
 ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a
 segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente.
 Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como
 há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da
 seguinte forma: posicoes[0] = 13; posicoes[1] = 16; Observe que o índice da
 posição no texto deve começar ser contado a partir de 1. O retorno da função,
 n, nesse caso seria 1;

 */

int validateStringOcurrence(char *strTexto, char *strBusca, int posicoes[30]) {
  int count = 0;
  int textLength = 0;
  int buscaLength = 0;

  while (strTexto[textLength] != '\0') {
    textLength++;
  }

  while (strBusca[buscaLength] != '\0') {
    buscaLength++;
  }

  if (buscaLength == 0) {
    return 0; // Se a string de busca estiver vazia, não há o que procurar.
  }

  for (int i = 0; i <= textLength - buscaLength; i++) {
    int match = 1;

    for (int j = 0; j < buscaLength; j++) {
      if (strTexto[i + j] != strBusca[j]) {
        match = 0;
        break;
      }
    }

    if (match == 1) {
      if (count < 30) {
        posicoes[count] = i;
        count++;
      } else {
        break; // Limitar o número máximo de ocorrências a 30
      }
    }
  }

  return count;
}

int q4(char *strTexto, char *strBusca, int posicoes[30]) {
  int qtdOcorrencias = -1;
  qtdOcorrencias = validateStringOcurrence(strTexto, strBusca, posicoes);
  return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int revertNumber(int numero) {
  int inverso = 0;
  int temPrimeiroDigito = 0; // Variável para controlar o primeiro dígito

  while (numero != 0) {
    int digito = numero % 10;
    if (digito != 0 || temPrimeiroDigito) {
      inverso = inverso * 10 + digito;
      temPrimeiroDigito = 1;
    }
    numero /= 10;
  }

  return inverso;
}

int q5(int num) {
  int revertNum = revertNumber(num);
  return revertNum;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int validateNumberOccurrence(int numeroBase, int numeroBusca) {
  int contador = 0;

  while (numeroBase > 0) {
    int digito = numeroBase % 10;
    if (digito == numeroBusca) {
      contador++;
    }
    numeroBase /= 10;
  }

  return contador;
}

int q6(int numerobase, int numerobusca) {
  int qtdOcorrencias = validateNumberOccurrence(numerobase, numerobusca);
  return qtdOcorrencias;
}

void imprimirTabuleiro(char tabuleiro[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%c ", tabuleiro[i][j]);
    }
    printf("\n");
  }
}

int verificarVitoria(char tabuleiro[3][3], char jogador) {
  for (int i = 0; i < 3; i++) {
    if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador &&
        tabuleiro[i][2] == jogador)
      return 1; // Linhas
    if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador &&
        tabuleiro[2][i] == jogador)
      return 1; // Colunas
  }
  if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador &&
      tabuleiro[2][2] == jogador)
    return 1; // Diagonal principal
  if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador &&
      tabuleiro[2][0] == jogador)
    return 1; // Diagonal secundária
  return 0;   // Nenhum jogador venceu
}

int verificarEmpate(char tabuleiro[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (tabuleiro[i][j] == ' ')
        return 0; // O tabuleiro ainda não está cheio
    }
  }
  return 1; // O tabuleiro está cheio (empate)
}

int q7() {
  char tabuleiro[3][3] = {
      {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; // Tabuleiro vazio
  char jogador = 'X';                                     // O jogador X começa

  printf("Bem-vindo ao Jogo da Velha!\n");

  for (int rodada = 1; rodada <= 9; rodada++) {
    printf("Rodada %d:\n", rodada);
    imprimirTabuleiro(tabuleiro);

    int linha, coluna;
    do {
      printf("Jogador %c, escolha a linha (0, 1 ou 2) e a coluna (0, 1 ou 2) "
             "para jogar: ",
             jogador);
      scanf("%d %d", &linha, &coluna);
    } while (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 ||
             tabuleiro[linha][coluna] != ' ');

    tabuleiro[linha][coluna] = jogador;

    if (verificarVitoria(tabuleiro, jogador)) {
      printf("Jogador %c venceu!\n", jogador);
      imprimirTabuleiro(tabuleiro);
      break;
    } else if (rodada == 9) {
      printf("Empate!\n");
      imprimirTabuleiro(tabuleiro);
    }

    jogador = (jogador == 'X') ? 'O' : 'X'; // Alterna entre X e O
  }

  return 0;
}

void limpa_tela() { system("clear"); }

void preenche_tabuleiro(char tabuleiro[10][10], char mascara[10][10]) {
  int linha, coluna;

  for (linha = 0; linha < 10; linha++) {
    for (coluna = 0; coluna < 10; coluna++) {
      tabuleiro[linha][coluna] = 'A';
      mascara[linha][coluna] = '*';
    }
  }
}

void exibe_tabuleiro(char tabuleiro[10][10], char mascara[10][10]) {
  int linha, coluna, i;

  printf("Tabuleiro :\n\n");

  printf("    ");
  for (i = 0; i < 10; i++) {
    printf("%d ", i + 1);
  }
  printf("\n");
  printf("    ");
  for (i = 0; i < 10; i++) {
    printf("| ");
  }
  printf("\n");

  for (linha = 0; linha < 10; linha++) {
    if (linha + 1 == 10) {
      printf("%d- ", linha + 1);
    } else {
      printf("%d - ", linha + 1);
    }
    for (coluna = 0; coluna < 10; coluna++) {
      printf("%c ", mascara[linha][coluna]);
    }
    printf("\n");
  }

  printf("\n");
  printf("Legenda:\n");
  printf("A - Agua\np - Barco pequeno\n* - Lugar desconhecido\n\n");
}

int coordenadasJaEscolhidas(char mascara[10][10], int linha, int coluna) {
  if (mascara[linha - 1][coluna - 1] == 'p' ||
      mascara[linha - 1][coluna - 1] == 'A') {
    return 1;
  } else {
    return 0;
  }
}

void posiciona_barcos(char tabuleiro[10][10]) {
  int i = 0;

  while (i < 20) {
    int linha = rand() % 10;
    int coluna = rand() % 10;

    if (tabuleiro[linha][coluna] == 'A') {
      tabuleiro[linha][coluna] = 'p';
      i++;
    } else {
      i--;
    }
  }
}

void pontuacao(char tabuleiro[10][10], int linha, int coluna, int *pontos,
               char *mensagem, char mascara[10][10]) {
  if (coordenadasJaEscolhidas(mascara, linha, coluna)) {
    *mensagem = "Coordenadas ja escolhidas";
  } else {
    switch (tabuleiro[linha - 1][coluna - 1]) {
    case 'p':
      *mensagem = "Voce acertou um barco pequeno! (+10 pts)";
      *pontos = *pontos + 10;
      break;

    case 'A':
      *mensagem = "Voce acertou a Agua!";
      break;
    }
  }
}

void menuInicial() {
  int opcao = 0;

  char nome_jogador[50];

  while (opcao < 1 || opcao > 3) {
    printf("\nBem vindo ao jogo de Batalha Naval!\n\n");
    printf("1 - Jogar\n");
    printf("2 - Sobre\n");
    printf("3 - Sair\n");
    printf("\nEscolha uma opcao e tecle ENTER\n");
    scanf("%d", &opcao);

    limpa_tela();

    switch (opcao) {
    case 1:
      printf("Jogo iniciado\n\n");
      printf("Qual seu nome ?\n");
      scanf("%s", nome_jogador);
      jogo(nome_jogador);
      break;

    case 2:
      printf("Informacoes do jogo:\n");
      printf("Jogo desenvolvido por Caio em 2020\n");
      break;

    case 3:
      printf("Ate mais\n");
      break;
    }
  }
}

void jogo(char *nome_jogador) {
  char tabuleiro[10][10], mascara[10][10];
  int linha, coluna;
  int status_jogo = 1; // 1 = Jogo rodando. 0 = Fim de jogo.
  int pontos = 0;      // Pontuação do jogador.
  int tentativas = 0;
  int opcao;
  char mensagem[] = "Bem vindo ao jogo";

  preenche_tabuleiro(tabuleiro, mascara);

  posiciona_barcos(tabuleiro);

  while (tentativas < 16) {
    limpa_tela();

    exibe_tabuleiro(tabuleiro, mascara);

    printf("%s\n", mensagem);
    printf("Pontuacao: %d\n", pontos);

    if (tentativas < 10) {
      printf("Tentativas restantes: %d\n\n", 10 - tentativas);

      printf("%s, digite uma linha e uma coluna\n", nome_jogador);
      scanf("%d %d", &linha, &coluna);

      if ((linha < 1 || coluna < 1) || (linha > 10 || coluna > 10)) {
        strcpy(mensagem, "Coordenadas invalidas");
        tentativas--;
      }

      if (coordenadasJaEscolhidas(mascara, linha, coluna)) {
        tentativas--;
      }

      pontuacao(tabuleiro, linha, coluna, &pontos, mensagem, mascara);

      mascara[linha - 1][coluna - 1] = tabuleiro[linha - 1][coluna - 1];
    }
    tentativas++;
  }

  printf("Fim de jogo, o que deseja fazer ?\n");
  printf("1 - Jogar novamente\n");
  printf("2 - Ir para o menu\n");
  printf("3 - Sair\n\n");
  printf("Escolha uma opcao e tecle Enter\n");
  scanf("%d", &opcao);

  switch (opcao) {
  case 1:
    jogo(nome_jogador);
    break;

  case 2:
    limpa_tela();
    menuInicial();
    break;

  case 3:
    break;
  }
}

int q8() {
  srand((unsigned)time(NULL));

  menuInicial();

  return 0;
}