#include <stdio.h>
int main(){
int n;
int arr[1000][3];

scanf("%d", &n);
int max = 0;
for(int i = 0; i<n; i++){
  for(int j = 0; j<3; j++){
    scanf("%d", &arr[i][j]);
  }
  int a = arr[i][0];
  int b = arr[i][1];
  int c = arr[i][2];
  
  int money;
  if(a==b && b==c){
    money = 10000 + a*1000;
    if(money > max){
      max = money;
    }
  }
  else if(a==b && b!=c){
    money = 1000 + a*100;
    if(money > max){
      max = money;
    }
  }
  else if(b==c && c!=a){
    money = 1000 + b*100;
    if(money > max){
      max = money;
    }
  }
  else if(c==a && a!=b){
    money = 1000 + b*100;
    if(money > max){
      max = money;
    }
  }
  else if((a>b&&b>c) || a>c && c>b){
    money = a*100;
    if(money> max){
      max = money;
    }
  }
  else if((b>a&&a>c) || b>c && c>a){
    money = b*100;
    if(money> max){
      max = money;
    }
  }
  else if((c>b&&b>a) || c>a && a>b){
    money = c*100;
    if(money> max){
      max = money;
    }
  }
}

printf("%d", max);

return 0;
}
