#include <stdio.h>

int main(){
  int n;
  scanf("%d", &n);
  
  bool flag = false;
  for(int i = 2; i<n; i++){
    if(n%i==0){
      flag = true;
    }
  }
  if(flag == true) printf("NO");
  else
  printf("YES");
  return 0;
}
