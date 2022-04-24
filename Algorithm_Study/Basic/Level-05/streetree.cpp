#include <stdio.h>

int getGCD(int a, int b){
  while(1){
  int r = a % b;
  if(r==0) return b;
    
    a=b;
    b=r;
  }
}

int main(){
  int n;
  int arr[100005];
  scanf("%d",&n);
  
  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  
  int GCD=0;
  
  for(int i = 0; i<n-1; i++){
    int distance = arr[i+1]-arr[i];
    
    if(i==0) GCD=distance;
    
    else{
      GCD = getGCD(GCD, distance);
    }
    
  }
  int totalTreeCnt = (arr[n-1] - arr[0])/GCD +1;
    printf("%d", totalTreeCnt-n);
  return 0;
}