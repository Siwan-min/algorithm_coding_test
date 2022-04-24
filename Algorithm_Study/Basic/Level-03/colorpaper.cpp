#include <stdio.h>

int main() {

  int arr[105][105]={0, };
  int n;
  int x, y, w, h;
  scanf("%d", &n);

  for(int k = 1; k <= n; k++){
    scanf("%d %d %d %d", &x, &y, &w, &h );
   
    for(int j = x; j<x+w; j++){
      for(int i = y; i<y+h; i++){
        arr[i][j] = k;
      }
    }
  }
  //printf("%d",n);
  int S = 0;
  for(int l=1; l<=n; l++){
    S = 0;
  for(int i=0;i<=101;i++){
    for(int j=0;j<=101;j++){
    // printf("%d ",arr[i][j]);
      if(arr[i][j]==l){
      S++;
      }
    }//printf("\n");
  }
  printf("%d\n", S);
  }
   
  return 0;
}