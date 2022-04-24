#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100005;

bool check[MAX];

int main(){
  int myQueue[MAX] = {0, }, front = 0, rear=0;
  int n, k;
  
  cin>>n>>k;
  
  check[k] = true;
  myQueue[rear++] = k;
  
  while(front < rear){
    int current = myQueue[front++];
    
    //내가 현재 current 마을에 있다.
    //current*2 current/3
    if(current*2 <=n && check[current*2]==false){
      check[current*2] = true;
      myQueue[rear++] = current*2;
    }
    if(current/3 >= 1 && check[current/3] == false){
      check[current/3] = true;
      myQueue[rear++] = current/3;
    }
  }
  int cnt=0;
  for(int i=1; i<=n; i++){
    if(check[i]==false)
    cnt++;
  }
  cout<<cnt;
  return 0;
}