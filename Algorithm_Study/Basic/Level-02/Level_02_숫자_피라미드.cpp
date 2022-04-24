#include <stdio.h>
int main() {
  int N, K, S;
  int arr[2000];
  scanf("%d %d", &N, &S );
  
  K=N;
  
  for(int i = 1; i<=N; i++){
    for(int j = 1; j<K; j++){
      printf(" ");
    }
    K--;
    
    if(i%2==1){
      for(int m = 2*i-1; m>=1; m--){
        if(S==10) S=1;
       
        arr[m] = S;
        S++;
      }
    }
    else if(i%2==0){
      for(int m = 1; m<=2*i-1; m++){
        if(S==10) S=1;
        arr[m] =S;
        S++;
      }
    }
    
    for(int k = 1; k<=2*i-1; k++){
      printf("%d", arr[k]);
    }printf("\n");
  }
  return 0;
}
