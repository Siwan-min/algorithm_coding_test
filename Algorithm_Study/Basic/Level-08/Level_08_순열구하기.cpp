#include <stdio.h>
int n, r;
char result[15];
bool check[15];
void getResult(int x){
  if(x>=r){
    printf("%s", result);
    printf("\n");
  }
  else{
    for(int i = 0 ; i<n; i++){
      int alpha = i + 'a';
      result[x] = alpha;
      if(check[i]==false){
        check[i]=true;
        getResult(x+1);
        check[i]=false;
      }
    }
  }
}

int main(){
  scanf("%d %d", &n, &r);
  getResult(0);
  return 0; 
}