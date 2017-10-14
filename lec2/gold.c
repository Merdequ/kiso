#include <stdio.h>
int IsPrime(int);

int main(void){
  int i,j;
  for(i=4; i<=1000; i+=2){
    for(j=1; j < i;j++){
      if(IsPrime(j) && IsPrime(i-j)){
	printf("%d = %d + %d\n",i, j, i-j);
	break;
      }
    }
    if(!(j < i)){
      printf("%d is a counterexample\n",i);
      return 0;
    }
  }
  return 0;
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
