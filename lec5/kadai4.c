/*
ポインタ
文字列中のアルファベットを大文字にする関数

 */

#include <ctype.h>
#include <string.h>
#include <stdio.h>

void uppercase(char *s);
int main() {char s[]="hello world";
  uppercase(s);
  printf("%s\n",s);// 出力䛿"HELLO WORLD"
  return 0;
}

void uppercase(char *s){
  for (int i = 0; i < strlen(s); i++){
    if (islower(s[i])){
      s[i] = toupper(s[i]);
    }
  }
}
