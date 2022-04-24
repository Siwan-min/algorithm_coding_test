#include <stdio.h>

int main(){
  int data[9];
  for(int i=0; i<9; i++){
    scanf("%d\n", &data[i]);
  }
  int myMax = data[0];
  int i = 1;
  int k = 0;
  for(i; i<9; i++){
    if(data[i]>myMax){
    myMax = data[i];
    k=i;
    }
  }
  printf("%d\n%d",myMax, k+1);
}
