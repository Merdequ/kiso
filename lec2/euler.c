#include <stdio.h>
#include <math.h>
int IsPrime(int);

int main(void){
  int i;
  double product = 1;
  for(i=1; i<=1000; i++){
    if(IsPrime(i)){
      product *= (1 - 1.0/pow(i,2));
    }
  }
  printf("pi = %f\n",sqrt(6/product));
}



int IsPrime(n) {
  int i;
  if(n == 1){
    return 0;
  }
  for (i=2; i<n; i++){
    if(n % i == 0){
      return 0;
    }
  }
  return 1;
}
