#include <stdio.h>
#include <math.h>
int main(void) {
  int i =0;
  for (i = 0; i < 1000; i++){
    if (pow(i,3) >= 158340421){
      printf(" %d^3 = %d\n",i,(int)pow(i,3));
      return 0;
    }
  }
}
