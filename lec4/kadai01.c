#include <stdio.h>
#include <stdlib.h>
#include <math.h> //log powを使うのに必要

/*
  調和級数 \sum_{i=1}^{n}(1 / i)
*/
double harmonic(int n) {
  int i;
  double sum = 0; //宣言が必要
  for (i = 1;i <= n;i++) {
    sum += 1 / (double)i; //double型にキャスト
  }

  return sum;
}

int main() {
  double sum = 0;
  int i;
  int upto = 5;
  double log_val; //double型で宣言
  double harmonic_val;
  int N;

  for (i = 0;i <= upto;i++) {
    N = (int) pow(10, i);
    log_val = log(N + 1);
    harmonic_val = harmonic(N);
    printf("%f, %f\n", log_val, harmonic_val);
  }

  return 0;
}
