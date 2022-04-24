#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100005
int _data[MAX];
int n, m;

int getStartPoint(int value){
  int start, end;
  
  if(_data[0]<value) start = 0;
  else{
    if(_data[0]>value) return -1;
    else return 0; // 같은 경우 
  }
  
  if(_data[n-1]>=value) end=n-1;
  else return -1;
  
  while(start+1<end){
    int mid = (start+end)/2;
    if(_data[mid]<value) start = mid;
    else end = mid;
  }
  if(_data[end]==value) return end;
  else return -1;
}

int getEndPoint(int value){
  int start, end;
  if(_data[0]<=value) start = 0;
  else return -1;
  
  if(_data[n-1]>value) end = n-1;
  else{
    if(_data[n-1]<value) return -1; // 값이 범위 안에 없다
    else return n-1; //값이 n-1번째에 있다.
  }
  
  while(start+1<end){
    int mid = (start+end)/2;
    if(_data[mid]<=value) start = mid;
    else end = mid;
  }
  if(_data[start]==value) return start;
  else return -1; 
}

int main(){
  cin>>n>>m;
  for(int i = 0; i<n; i++) cin>>_data[i];
  sort(_data, _data+n);
  for(int i = 0; i<m; i++){
    int front, rear;
    int a;
    cin>>a;
    
    front = getStartPoint(a);
    rear = getEndPoint(a);
    
    if(front==-1) cout<<"0"<<endl;
    else cout<<rear-front+1<<endl;
  }
  return 0; 
}