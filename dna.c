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
	if (m == 0 | n == 0) {
		length[n][m] = 0;
	}
	if (a[n-1] == b[m-1]) {
		length[n][m] = mlcs_w(a, n-1, b, m-1, length) + 1;
	}
	else {
		if (length[n-1][m] > length[n][m-1]) {
			length[n][m] = mlcs_w(a, n - 1, b, m, length);;
		} else {
			length[n][m] = mlcs_w(a, n, b, m - 1, length);
		}

	}

  return length[n][m];
}

int mlcs(char a[], int n, char b[], int m) {
  return 1;
}

int dlcs(char a[], int n, char b[], int m) {
  return 2;
}
