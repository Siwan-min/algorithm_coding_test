#include <stdio.h>
 
const int MAX = 500005;
struct stack{
  int data[MAX];
  int capacity;
  int len;
  
  void create(int y){
    capacity = y;
    len = 0;
  }
  void push(int y){
    // 스택 오버플로우
    if(len>=capacity){
      printf("Overflow\n");
    }else{
      // 정상 push
      data[len++] = y;
    }
  }
  
  void pop(){
    if(len<=0){
      // 스택 언더플로우
      printf("Underflow\n");
    }else{
      // 정상 pop
      data[len-1] = NULL;
      len--;
    }
  }
  
  int top(){
    if(len<=0){
      // 널값이거나, 없을 때.
      return -1;
    }else{
      // 정상 top
      return data[len-1];
    }
  }
  
  void test(){
    for(int i=0; i<len; i++){
      printf("%d ",data[i]);
    }
    printf("\n");
  }
  
};
 
int main() {
  
  //초기 변수 설정
  int n;
  scanf("%d",&n);
  int arr[n];
  for(int i=0; i<n; i++){
    scanf("%d",&arr[i]);
  }
  
  stack s;
  s.create(n); //스택 정상 작동.
  
  int result[n];
  
  for(int i=0; i<n; i++){
    if(i==0){
      s.push(i);
      //result[i] = arr[s.top()];
      result[i] = s.top();
      continue;
    }
    
    // ********************************************************
    //새로 추가되는 값이 더 큰 경우 ***************************
    // ********************************************************
    if(arr[s.top()]<arr[i]){
      //s.pop();
      //s.push(i);
      //result[i] = 0;
      
      while(1){
        s.pop();
        if(arr[s.top()]>arr[i] || s.top()==-1){
          break;
        }
      }
      if(s.top() == -1){
        result[i] = 0;
      }else{
        //result[i] = arr[s.top()];
        
        result[i] = s.top()+1;
      }
      s.push(i);
      
      //s.test();
      
    }else if(arr[s.top()]==arr[i]){
      //새로 추가되는 값이 top과 같은 경우
      result[i] = s.top();
    }else if(arr[s.top()]>arr[i]){
      //새로 추가되는 값이 top 보다 작은 경우
      s.push(i);
      //result[i] = arr[s.top()];
      result[i] = s.top();
      //s.test();
    }
  }
  
  
  // 화면 출력 테스트
  for(int i=0; i<n; i++){
    printf("%d ",result[i]);
  }
  
 
  
  return 0;
}
 