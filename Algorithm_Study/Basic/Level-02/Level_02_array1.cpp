#include <stdio.h>

int main(){
  int arr[105][105];
  int N, M;
  
  scanf("%d %d", &N, &M);
  int num =1;
  for(int i= 0; i<N; i++){
    for(int j= 0; j<M; j++){
    arr[i][j] = num;
    num++;
    printf("%d ", arr[i][j]);
  }printf("\n");
  }
  return 0;
}
