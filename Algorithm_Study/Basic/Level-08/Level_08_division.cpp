#include <stdio.h>

int result[30];
int n;
int cnt; //맨 마지막에 갯수 카운트
void getResult(int mySum, int index){
  
  if(mySum==n){
    
    printf("%d",result[0]);
    for(int i=1; i<index; i++){
      printf("+%d", result[i]);
    }
    printf("\n");
    cnt++;
  }
  else {
    int myNumber;
    
    if(index==0)
    myNumber = n-1;
    
    else myNumber = n- mySum;
    
    for(int i=myNumber; i>=1; i--){
      result[index] = i;
     
      if(index>0&&result[index-1]<result[index]) continue; //숫자를 못 넣음
      
      getResult(mySum+i, index+1);
    }
  }
}

int main() {

  scanf("%d", &n);
  
  getResult(0, 0);
  
  printf("%d", cnt);

  return 0;
}

/*
(1) 조합이 같은 식은 출력 될 수 없다.
    >>중복체크 index는 index의 이하의 숫자를 출력하면 된다. 
(2) n보다 작은 자연수들의 합이다.
    >>
(3) 입력: n 은 2이상 20이하의 자연수다.
    >>변수 n, 배열 result[30]을 만들어준다
(4) 출력: 첫째 줄부터 모든 방법을 하나씩 출력한다
      -(1) 사항을 고려한다.
    출력: 큰 숫자가 앞으로 오게해서 출력한다.
    출력: 숫자와 더하기 사이에는 공백이 없다.
    출력: 마지막 줄에는 나누어진 자연수의 개수를 출력한다.
    >>출력때마다 cnt 를 해준다. 

*/