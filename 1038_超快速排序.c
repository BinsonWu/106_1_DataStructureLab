/*
 ============================================================================
 Name        : 39_超快速排序.c
 Author      : Binson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

long long int count;

void merge(int A[], int p, int q, int r) {
	int i, j, k;
  int n1 = q - p + 1;
  int n2 = r - q;

  int* L = (int*) malloc((n1 + 1) * sizeof(int));
  int* R = (int*) malloc((n2 + 1) * sizeof(int));

  for ( i = 1; i <= n1; i++) {
    L[i] = A[p + i - 1];
  }

  for ( i = 1; i <= n2; i++) {
    R[i] = A[q + i];
  }


  for (k = p, i = 1, j = 1; (k <= r) && (i <= n1) && (j <= n2); k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    }
    else {
      A[k] = R[j];
      j++;
      count += (n1 - i + 1); // Important formula
    }
  }

  for (; i <= n1; i++) {
    A[k++] = L[i];
  }

  for (; j <= n2; j++) {
    A[k++] = R[j];
  }
}

void merge_sort(int A[], int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;
    merge_sort(A, p, q);
    merge_sort(A, q + 1, r);
    merge(A, p, q, r);
  }
}

int main() {
	count = 0;
  int n;
  int input[502000] = {0};
  while (scanf("%d", &n) == 1) {
    if (n == 0) {
      break;
    }
    int i;
    for ( i = 0; i < n; i++) {
      // Index range : 1 ~ n;
      scanf("%d", &input[i + 1]);
    }

    merge_sort(input, 1, n);

    printf("%lld\n",count);

    count = 0;
  }

  return 0;
}

