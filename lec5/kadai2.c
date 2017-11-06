/*
行列の固有値と固有ベクトルを計算してポインタに入れる
固有値は実数とする
 */


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void eig(double[2][2],double*,double*,double*,double*);
int main() {
  double val1;
  double val2;
  double vec1[2];
  double vec2[2];
  double mat[2][2]={{1,5},{6,2}};

  eig(mat,&val1,&val2, vec1, vec2);
  printf("[%f, %f]\n", mat[0][0], mat[0][1]);
  printf("[%f, %f]\n", mat[1][0], mat[1][1]);
  printf("eigenvalue = %f, eigenvector = (%f, %f)\n", val1, vec1[0], vec1[1]);
  printf("eigenvalue = %f, eigenvector = (%f, %f)\n", val2, vec2[0], vec2[1]);
  return 0;
}

void eig(double mat[2][2],double*val1,double*val2,double*vec1,double*vec2) {
  double a, b, c, d, discri;
  a = mat[0][0];
  b = mat[0][1];
  c = mat[1][0];
  d = mat[1][1];

  discri = a * a - 2 * a * d + 4 * b * c + d * d;
  if(discri < 0){ //固有値が実数でないときの処理
    return;
  }
  *val1 = ( - sqrt(discri) + a + d) / 2;
  *val2 = (   sqrt(discri) + a + d) / 2;

  *vec1 = - (sqrt(discri) - a + d) / (2 * c);
  *(vec1 + 1) = 1;
  *vec2 = - (- sqrt(discri) - a + d) / (2 * c);
  *(vec2 + 1) = 1;
}
