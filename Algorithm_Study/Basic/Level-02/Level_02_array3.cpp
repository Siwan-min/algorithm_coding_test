#include <stdio.h>

int arr[100][100];

int main()
{
  int n;
  scanf("%d", &n);
  int num = 1;
  int k = 0;
  int x, y = 0;
  while(k!=n){
    x = k;
    while(y != k+1 && x >= 0&&x<100 &&y>=0 && y<100){
      arr[y][x] = num;
      x--;
      y++;
      num++;
    }
    k++;
    y = 0;
  }
  for(int i = 0; i<n; i++){
    for(int j=0; j<n; j++){
      if(arr[i][j]==0)continue;
      printf("%d ", arr[i][j]);
    }printf("\n");
  }
  return 0;
}
