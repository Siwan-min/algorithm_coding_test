#include <stdio.h>
#include <string.h>
 
int main() {
 
  char arr[1005];
  fgets(arr, 1005, stdin);
  
  int arrLen = strlen(arr);
  int arrDiv = arrLen/2+1;
  int flag = 1;
  
  for(int i=0; i<arrDiv; i++){
    if(arr[i]!=arr[arrLen-1-i]){
      flag = 0;
    }
  }
  
  if(flag == 1){
    printf("YES");
  }else{
    printf("NO");
  }
  
  return 0;
}
