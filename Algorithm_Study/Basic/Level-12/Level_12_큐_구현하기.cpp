#include <stdio.h>
#define MAX 105
int Q[MAX];
int n, m;


struct Queue {
  
  int rear=0, front=0;
  
  void push(int x){
    if(rear>=n) {
      printf("Overflow\n");
      return ;
    }
    else{
      Q[rear++] = x;
    }
  }
  void pop( ){
    if(rear==front) {
      printf("Underflow\n");
    }
    else{ Q[front] = 0;
    front++;
    }
  }
  
  void Front(){
    if(rear-front<=0){
        printf("NULL\n");
    }
    else printf("%d\n", Q[front]);
  }
  
} ;

int main() {
  //n: 배열 크기
  Queue q;
  scanf("%d %d", &n, &m);
  
  for(int i = 0; i<m; i++){
    int a, b;
    scanf("%d", &a);
    
    if(a==1){
      scanf("%d", &b);
      q.push(b);
    }
    else if(a==2){
      q.pop();
    }
    
    else if(a==3){
      q.Front();
    }
  }
  

  return 0;
}