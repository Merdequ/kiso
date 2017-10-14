#include <stdio.h>
int IsPrime(int);

int main(void){
  int i;
  for(i=1; i<=1000; i++){
    if(IsPrime(i)){
      printf("%d is prime\n",i);
    }
  }
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
