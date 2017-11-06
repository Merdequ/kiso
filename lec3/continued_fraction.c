/*
連分数によって平方根を計算する
*/

#include<stdio.h>

#define MAX_DEPTH 10 //深さいくつまで計算するか

double sqrt_cf(double);
double K(double,int);

int main() {
  double z = 2;
  double s = sqrt_cf(z);
  printf("%f\n", s);
  return 0;
}

double sqrt_cf(double z) {
  return 1.0 + K(z,0);
}

double K(double z,int depth) {
  if(depth < MAX_DEPTH){
    return (z - 1) / (2.0 + K(z, depth + 1));
  }
  else{
    return 0;
  }
}
