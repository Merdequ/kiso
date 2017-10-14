#include <stdio.h>
#include <math.h>
int gcd(int, int);

int main(void){
  int r;
  int a = 8733;
  int b = 64681;
  r = gcd(a,b);
  printf("gcd(%d, %d) = %d\n", a, b, r);
}

int gcd(a,b) {
  int temp;
  while(b != 0){
    temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}
