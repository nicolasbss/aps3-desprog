#include <stdio.h>

#include "dna.h"

void load_string(FILE *file, int *p, char *s, int t) {
  if (fscanf(file, "%d", p) != 1) {
    fprintf(stderr, "erro ao ler tamanho do teste %d\n", t);
  }

  char c;
  do {
    c = getc(file);
  } while (c != '\n');

  if (!fgets(s, *p + 1, file)) {
    fprintf(stderr, "erro ao ler string do teste %d\n", t);
  }
}

int mlcs_w(char a[], int n, char b[], int m, int length[MAX_SIZE + 1][MAX_SIZE + 1]) {
  //checa se essa posição da matriz já foi calculada
  if (length[n][m] != -1) {
    return length[n][m];
  }
  //condição da base da recursão
  if (m == 0 || n == 0) {
    length[n][m] = 0;
    return length[n][m];
  }
  //condição do passo da recursão
  if (a[n - 1] == b[m - 1]) {
    length[n][m] = mlcs_w(a, n - 1, b, m - 1, length) + 1;
  } else {
    length[n - 1][m] = mlcs_w(a, n - 1, b, m, length);
    length[n][m - 1] = mlcs_w(a, n, b, m - 1, length);

    if (length[n - 1][m] > length[n][m - 1]) {
      length[n][m] = length[n - 1][m];
    } else {
      length[n][m] = length[n][m - 1];
    }
  }

  return length[n][m];
}

int mlcs(char a[], int n, char b[], int m) {
  //inicializa a matriz
  int length[MAX_SIZE + 1][MAX_SIZE + 1];
  //preenche a matriz com -1
  for (int j = 0; j <= n; j++) {
    for (int i = 0; i <= m; i++) {
      length[j][i] = -1;
    }
  }
  length[0][0] = 0;
  mlcs_w(a, n, b, m, length);
  return length[n][m];
}

int dlcs(char a[], int n, char b[], int m) {
  int length[MAX_SIZE + 1][MAX_SIZE + 1];

//loop iterativo para percorrer todos os indices
  for (int j = 0; j <= n; j++) {
    for (int i = 0; i <= m; i++) {
      //caso 1
      if (j == 0 || i == 0) {
        length[j][i] = 0;
        //caso 2
      } else if (a[j - 1] == b[i - 1]) {
        length[j][i] = length[j - 1][i - 1] + 1;
        //caso 3: verifica qual é maior
      } else {
        if (length[j - 1][i] >= length[j][i - 1]) {
          length[j][i] = length[j - 1][i];
        } else {
          length[j][i] = length[j][i - 1];
        }
      }
    }
  }

  return length[n][m];
}
