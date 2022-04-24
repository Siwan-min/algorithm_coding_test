#include <stdio.h>
#define MAX_SIZE 100000

int a[MAX_SIZE];
int founded = 0;

int search (int start, int end, int target){
  if(start>end) return -1;
  
  int mid = (start + end)/2;
  
  if(a[mid] == target) return mid;
  else if (a[mid] > target)
    return search(start, mid-1, target);
  else 
    return search(mid+1, end, target);
  
}

int main(){
  
  int n, num, target;
  scanf("%d %d", &n, &num );
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  
  for(int i = 0; i < num; i++){
    scanf("%d", &target);
  
    int result = search(0, n-1, target);
    if(result != -1) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}