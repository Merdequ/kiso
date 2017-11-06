#include <stdio.h>
#include <math.h>

int main(void){
  double series = pow(log(2),2);
  int n = 0;
  int nMax = 1000;
  for(n = 1; n <= nMax; n++){
    series += ( 1.0 / (pow(n,2) * pow(2,n-1)));
  }
  printf("pi = %f\n", sqrt(6 * series ));
  return 0;
}

