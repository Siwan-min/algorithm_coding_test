#include <stdio.h>

int main(){
  int a, s=0;
  scanf("%d", &a);
  
  for(int i = 1; i<=a; i++){
    if(i%2==0)
    s = s+i;
  }
  printf("%d",s);
}
