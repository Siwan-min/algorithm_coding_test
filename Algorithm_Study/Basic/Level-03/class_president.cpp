#include <stdio.h>

int main(){
  int arr[1010][5];
  int n , result=-1, resultNumber;
  
  scanf("%d", &n);
  
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=5; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  
  for(int i = 1; i<=n; i++){
    int cnt=0;
    for(int j = 1; j<=n; j++){
      if(i==j) continue;
      
      if(arr[i][1]==arr[j][1]||
        arr[i][2]==arr[j][2]||
        arr[i][3]==arr[j][3]||
        arr[i][4]==arr[j][4]||
        arr[i][5]==arr[j][5]){
          cnt++;
        }
      if(cnt>result){
        result = cnt;
        resultNumber = i;
      }
    }
  }
  printf("%d", resultNumber);
  return 0;
}