#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct matrix{
  int row;
  int col;
  double **comp;
} Matrix;

Matrix *get_matrix(char *filename);
double data(const Matrix *m, int row, int col);
void get_max_eigen(const Matrix *m, double *eigenvalue, Matrix *eigenvector); 

int main(){
  ;
}

Matrix *get_matrix(char *filename){
  FILE *fp;
  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "error: cannot open %s.\n", filename);
    return;
  }
}

double data(const Matrix *m, int row, int col){
  assert( 0 <= row && row < m->row);
  assert( 0 <= col && col < m->col);
  return m->comp[row][col];
}


void get_max_eigen(const Matrix *m, double *eigenvalue, Matrix *eigenvector){
  ;
}
