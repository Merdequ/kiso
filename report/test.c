#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define BUFSIZE 256
#define DELIMITER '\t'

typedef struct matrix{
  int row;
  int col;
  double **comp;
} Matrix;

Matrix get_matrix(char *filename);
double data(const Matrix *m, int row, int col);
void get_max_eigen(const Matrix *m, double *eigenvalue, Matrix *eigenvector); 

int main(){
  ;
}

Matrix get_matrix(char *filename){
  FILE *fp;
  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "error: cannot open %s.\n", filename);
    return NULL;
  }
  int row = 0, col = 0;

  char buf[BUFSIZE];
  // 行列のサイズを取得(最大の列数を採用)
  for (row = 0; fgets(buf, sizeof(buf)), fp); row++){
    int temp = 1;
    char *p = &buf[0];
    while(*p != '\0'){
      if(*p == DELIMITER){
        temp++;
      }
    }
    if (col < temp){
      col = temp;
    }
  }

  assert( 0 < row && 0 < col);

  // 行列作成
  comp = calloc(sizeof(double), col * row);
}

double data(const Matrix *m, int row, int col){
  assert( 0 <= row && row < m->row);
  assert( 0 <= col && col < m->col);
  return m->comp[row][col];
}


void get_max_eigen(const Matrix *m, double *eigenvalue, Matrix *eigenvector){
  ;
}
