#include <stdio.h>
#include <string.h>
bool check[30];
char data[30], myStack[30];

int len, cnt, cur, top;

int main(){
  scanf("%s", data);
  len = strlen(data);
  char alpha = 'a';
  while(1){
    if(myStack[0]==0 || myStack[top-1] != data[cur]){
      myStack[top] = alpha;
      alpha++;
      top++;
    }
    else{
      if(myStack[top-1]==data[cur]){
        myStack[top-1] = 0;
        check[cnt] = true;
        top--;
        cur++;
        
        if(cur>=len) break;
      }
    }
    cnt++;
    
    if(alpha>data[cur]&&myStack[top-1]!=data[cur]){
      printf("impossible");
      return 0;
    }
  }
  for(int i = 0; i<=cnt; i++){
    if(check[i]==true) printf("pop\n");
    else printf("push\n");
  }
  return 0;
}