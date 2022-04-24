#include <stdio.h>

int main() {

  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  
  int max = 0;
  
  if(max<a) max = a;
  if(max<b) max = b;
  if(max<c) max = c;
  
  printf("%d\n", max);
  return 0;
}
