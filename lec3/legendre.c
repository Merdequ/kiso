/*
legendre多項式を計算する
 */


#include <stdio.h>
//#include <math.h>

#define MAX_N 10000
double result[MAX_N];// グローバル変数 計算結果
int flag[MAX_N];// グローバル変数 計算済みであるかどうか

double legendre(int, double);
double legendre2(int, double, int);

int main(void){
   double v = legendre(16, 0.5);
   printf("%f\n", v);
   v = legendre(32, 0.7);
   printf("%f\n", v);
   //まずは再起を使って愚直に実装した。
   //P_128(0.5)を計算させてみると、確かに計算が終わる気配がなかった
   //nを1ずつ増やしていってどれくらいで計算が終了するか調べてみると、
   //n = 40 くらいまでは数秒で計算が終了したが、n = 45では
   //(だいたい)15秒くらいかかっていた。
   //この実装だと、legendre関数を呼び出す回数がフィボナッチ数列の
   //オーダーで増えており、指数時間かかるので
   //n = 128 は1億年待っても終わらない
   //同じ計算を何度もしないように、以前の計算結果を配列で保存しておけばよさそう。

   printf("\n実装変更\n");
   int depth = 0; //再帰の深さ
   for(int i = 0; i <= 128; i++){
     v = legendre2(i, 0.5, depth);
     printf("p_%d(0.5) = %f\n", i, v);
   }
   return 0;
}

double legendre(int n, double x){
  if(n == 0){
    return 1;
  }
  else if(n == 1){
    return x;
  }
  else{
    return ((2 * n - 1) * x * legendre(n - 1, x) - (n - 1) * legendre(n - 2, x))/n;
  }
}

double legendre2(int n, double x, int depth){
  if(depth == 0){//再帰呼び出しでなければ配列flagを0で埋める
    for(int i = 0; i < MAX_N; i++){
      flag[i] = 0;
    }
  }
  if(n == 0){
    return 1;
  }
  else if(n == 1){
    return x;
  }
  else{
    double present, previous, pprevious; //p_n(x), p_(n-1)(x), p_(n-2)(x)
    //計算済みであれば結果を読み出し、そうでなければ計算する
    previous = flag[n - 1] ? result[n - 1] : legendre2(n - 1, x, depth + 1);
    pprevious = flag[n - 2] ? result[n - 2] : legendre2(n - 2, x, depth + 1);
    present = ((2 * n - 1) * x * previous - (n - 1) * pprevious)/n;
    //計算済みのフラグを立て、結果を配列に入れる
    flag[n] = 1;
    result[n] = present;
    return present;
  }
}
//この実装であれば計算時間はnのオーダーで済むのでメモリの許す限り計算できそう
//本当は引数2つ(nとxのみ)で呼び出せる関数にしたかったので、
//depthのデフォルト値を0に設定すれば行けると思ったのだが、
//どうもC言語ではデフォルト引数を設定できないらしく、いいやり方が思いつかなかった。
