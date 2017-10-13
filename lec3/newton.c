#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ERROR 0.00001

double f(double);
double dfdx(double);
double newton(double);
int main() {
  double x0 =1.0;
  double solution = newton(x0);
  printf("solution is %f\n", solution);
  return 0;
}

//x を引数として受け取り、f(x) = exp(x) + x を返す
double f(double x){
  return exp(x) + x;
}

//x を引数として受け取り、f'(x) = exp(x) + 1
double dfdx(double x){
  return exp(x) + 1;
}

double newton(double x){
  //printf("newton!!!\n");

  //x_n と x_(n+1) の差が ERROR 未満であれば x_(n+1)を返す
  if (fabs(f(x) / dfdx(x)) < ERROR) {
    // printf("%f\n", fabs(f(x) / dfdx(x)));
    return x - f(x) / dfdx(x);
  }
  //ERROR 以上の差があるとき、x_(n+1) の値を渡して再帰
  else{
    return newton(x - f(x) / dfdx(x));
  }
}
