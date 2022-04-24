#include <stdio.h>
#define SIZE 105
int n, m, len;
int data[SIZE];
struct stack {
  void push(int x){
    if(len>=n) printf("Overflow\n");
    else data[len++] = x;
  }
  void pop(){
    if(len<=0) printf("Underflow\n");
    else data[--len] = 0;
  }
  void top(){
    if(len<=0) printf("NULL\n");
    else printf("%d\n", data[len-1]);
  }
}s;

int main(){
  scanf("%d %d", &n, &m);
  
  for(int i = 0; i<m; i++){
    int a;
    scanf("%d", &a);
    if(a==1){
      int b;
      scanf("%d",&b);
      s.push(b);
    }
    else if(a==2) s.pop();
    else s.top();
  }
  return 0;
}