#include <stdio.h>
/*#include <math.h>*/
int main(void) {
  int x,y,z;
  for (x = 1; x < 1000; x++){
    for(y = x; y < 1000; y++){
      for (z = 1; z < 1000; z++){
	if (x*x + y*y == z*z){
	  printf("%d^2 + %d^2  = %d^2\n",x,y,z);
	}
      }
    }
  }
}
