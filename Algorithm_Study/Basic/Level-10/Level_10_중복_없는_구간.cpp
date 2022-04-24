#include <stdio.h>
 
const int max = 100005;
int arr[max];
int crr[max] = {false,};
int n;
int result=0;
int arrcount = 2;
 
void binary(int arr[], int s, int e){
  
  if(s>e || e==1){
    result = e;
    return;
  }
  
  int mid = (s+e)/2;
  int find=0;
  int count = 0;
  //printf("%d/////\n",mid);
  
  for(int i=0; i<=n-mid; i++){
    
    for(int j=i;j<mid+i;j++){
      
      if(crr[arr[j]]!=arrcount){
        crr[arr[j]]=arrcount;
        //printf("*%d ",arr[j]);
        count++;
        if(count==mid){
          count=0;
          find=1;
          break;
        }
        
      }else{
        count=0;
        arrcount++;
        break;
      }
     // printf("\n");
    }
    
    arrcount++;
    
    //printf("\n");
    if(find==1){
      result = mid;
      break;
    }
  }
  
  
  if(find==1){
    binary(arr, mid+1, e);
  }else{
    binary(arr, s, mid-1);
  }
  
}
 
int main() {
  
  scanf("%d",&n);
  for(int i=0; i<n; i++) scanf("%d",&arr[i]);
  
  binary(arr, 0, n);
  printf("%d",result);
  
  return 0;
}