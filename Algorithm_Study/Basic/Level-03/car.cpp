#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  
  int z, cnt;
  for(int i = 0; i<5; i++){ 
    scanf("%d", &z);
    if(z%10 == n) cnt++;
  }
  
  printf("%d", cnt);
  return 0;
}