#include <stdio.h>

int main() {
  int num;
  int k;
  int arr[100];
  scanf("%d",&num);
  do{
    arr[k]=num%2;
    num=num/2;
    if(num==0)
      break;
    k++;
    }while(1);
    for(k; k>=0; k--){
      printf("%d", arr[k]);
    }
  return 0;
}
