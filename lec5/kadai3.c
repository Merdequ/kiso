/*
ポインタ
文字列を逆順にする関数を作る
 */

#include <stdio.h>
#include <string.h>

void reverse(char *s);
int main() {
  char s[]="hello";
  reverse(s);
  printf("%s\n",s);// 出力䛿"olleh"
  return 0;
}

void reverse(char *s){
  char temp;
  int i, j;
  for(i = 0, j = strlen(s) - 1; i < j; i++, j--){
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}
