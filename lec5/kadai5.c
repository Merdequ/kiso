/*
ローマ数字をアラビア数字に変換する
右(小さい桁)から処理

 */


#include <stdio.h>
#include <string.h>

int symbol2num(char);
int roman2num(char*);

int main() {
  // Examples
  printf("XIV = %d\n", roman2num("XIV")); //14
  printf("CDXCV = %d\n", roman2num("CDXCV")); //495
  printf("MCMXLV = %d\n", roman2num("MCMXLV")); //1945
  printf("MMMCMXCIX = %d\n", roman2num("MMMCMXCIX")); //3999
  return 0;
}

int symbol2num(char c){
  switch(c){
  case 'I':
    return 1;
  case 'V':
    return 5;
  case 'X':
    return 10;
  case 'L':
    return 50;
  case 'C':
    return 100;
  case 'D':
    return 500;
  case 'M':
    return 1000;
  }
}

int roman2num(char*s){
  // I : 1, V : 5, X : 10, L : 50, C : 100, D : 500, M : 1000
  int sum = 0, largest = 1, symbsign;
  for (int i = strlen(s) - 1; i >= 0; i--){
    if (symbol2num(s[i]) < largest){
      symbsign = -1;
    }
    else {
      symbsign = 1;
      largest = symbol2num(s[i]);
    }
    // 右にすでに出た記号より小さい記号の場合は減算

    //printf("%c %d\n", s[i], symbol2num(s[i]) * symbsign);
    sum += symbsign * symbol2num(s[i]);
  }
  return sum;
}
