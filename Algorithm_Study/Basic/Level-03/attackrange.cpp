#include <stdio.h>
#include <stdlib.h>

int main() {

int arr[110][110];
int N, X, Y, R, n=0, m=0;
scanf("%d", &N); // 6 ~100 이하의 짝수인 자연수
scanf("%d %d %d", &X, &Y, &R); //R: N/2 이하의 자연수

for(int i = 1; i<=N; i++){
  for(int j = 1; j<=N; j++){
    if( i == X && j == Y){
      printf("x ");
    }
    
    else {
    n = abs(X-i);
    m = abs(Y-j);

    arr[i][j] = n + m;
   
    if(arr[i][j]>R){
      arr[i][j] = 0;
    }
   printf("%d ", arr[i][j]);
    }
  }printf("\n");
}  
  return 0;
}