/*
ポインタを受け取って中身の数字を増やす関数
 */

#include <stdio.h>

void increment(int*);
int main() {
  int a =10;
  increment(&a);
  printf("%d\n",a);//出力䛿11
  return 0;
}

void increment(int *n){
  (*n)++;
}
