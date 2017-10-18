#include <stdio.h>
#include <string.h> //strlenに必要

int main() {
  char s[] = "12934875628476528734692734697263475629101234100";
  int count[10]; //長さ10で宣言
  int len = strlen(s); // 文字列sの長さ
  int i, n;


  for (n = 0; n <= 9;n++) { //配列初期化が必要  
    count[n] = 0;
  }
  
  for (i = 0;i < len;i++) {   
    count[s[i] - '0'] = count[s[i] - '0'] + 1;
  }

  int is_even;
  for (n = 0;n <= 9;n++) {
    is_even = count[n] % 2;
    if(is_even == 0) { //比較演算は ==
      printf("%d is even\n", n);
    } else {
      //printf("%d is odd %d %d\n", n,count[n],count[n] % 2);
      printf("%d is odd\n", n);
    }
  }
  
  return 0;
}
