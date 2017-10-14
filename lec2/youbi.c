#include<stdio.h>
#include<math.h>
int zeller(int,int,int);
int main() {
  int year =2018, month =1, day =1;
  int w;
  w = zeller(year, month, day);
  printf("%d/%d/%d is ",month, day, year);
  switch(w) {
  case 0: printf("Sat.\n");break;
  case 1: printf("Sun.\n");break;
  case 2: printf("Mon.\n");break;
  case 3: printf("Tue.\n");break;
  case 4: printf("Wed.\n");break;
  case 5: printf("Thurs.\n");break;
  case 6: printf("Fri.\n");break;
  }
  return 0;
}
int zeller(int year,int month,int day){
  int h,y,m,d;
  if(month <= 2){
    year -= 1;
    month += 12;
  }
  h = year /100;
  y = year % 100;
  m = month;
  d = day;
  return((y + y/4 + h/4 - 2*h + 13*(m+1)/5 + d)%7);
}
