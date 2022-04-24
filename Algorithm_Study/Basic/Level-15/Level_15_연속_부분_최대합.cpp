#include <stdio.h>
int n;
int data[100005];

int getResult(int start, int end){
  if(start == end) return data[start];
  
  int mid=(start + end )/2;
  
  int lm = getResult(start, mid);
  int rm = getResult(mid+1, end);
  
  int lsm = data[mid], lss = data[mid];
  int rsm = data[mid+1], rss = data[mid+1];
  
  for(int i = mid-1; i>=start; i--){
    lss +=data[i];
    if(lsm<lss) lsm=lss;
  }
  
  for(int i = mid+2; i<=end; i++){
    rss+=data[i];
    if(rsm<rss) rsm=rss;
  }
  int mm=lsm+rsm;
  if(lm>=mm && lm>=rm) return lm;
  else if(rm>=mm && rm>=lm) return rm;
  else return mm;
}
int main(){
  scanf("%d", &n);
  for(int i = 0; i<n; i++) scanf("%d", &data[i]);
  printf("%d", getResult(0, n-1));
  return 0;
}