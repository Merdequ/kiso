/*
再帰を用いて a^p mod m を計算
*/

#include <stdio.h>
//#include <math.h>

int mod_apm(int,int,int);

int main(void){
  int v;
  v = mod_apm(541, 1234, 1299709);
  printf("mod_apm(541, 1234, 1299709) = %d\n", v);
  return 0;
}

int mod_apm(int a, int p, int m){
  if(p == 0){
    return 1;
  }
  else{
    return (a * mod_apm(a, p-1, m)) % m;
  }
}
