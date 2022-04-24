#include <stdio.h>
#include <string.h>



int main() {
char input[1003], q[1003];
// scanf(" %[^\n]s", input);
 
// scanf(" %[^\n]s", q);
   
  fgets(input,1003,stdin);
  fgets(q,1003,stdin);
int sum = 0, flag = 0; 
for(int i = 0 ; i < strlen(input)-strlen(q); i++){
  sum = 0;
  for(int j = 0 ; j < strlen(q); j++){
    if(input[i+j] != q[j]){
      break;
    }
    else{
      sum++;
    }
  }
   
  if(sum == strlen(q)){
    flag = 1;
    break;
  }
}
//  printf("%d %d\n", strlen(q), sum);

  if(flag == 1) printf("YES\n");
  else printf("NO\n");
  return 0;
}