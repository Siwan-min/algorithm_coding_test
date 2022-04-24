
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 30

int n;
int arr[MAX][MAX];
vector <int> result;

int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, 1, -1, 0};

int getGroup(int y , int x){
  
  int cnt = 0;
  cnt++;
  arr[y][x] = 0;
  
  for(int k=0; k<4; k++){
    int yy = y + dy[k];
    int xx = x + dx[k];
    
    if(arr[yy][xx]) // 만약 (상, 하, 좌, 우) 이웃의 값이 1 이면 
      cnt +=getGroup(yy,xx); // cnt +1 을 하고 그 자리의 이웃을 다시 재귀 적으로 탐색
  }
  return cnt;
}

int main(){
  cin>>n;
  
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=n; j++){
      scanf("%1d", &arr[i][j]);
    }
  }
  
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=n; j++){
      
      if(arr[i][j]){
        result.push_back(getGroup(i,j));
      }
    }
  }
  
  sort(result.begin(), result.end());
  
  cout<<result.size()<<endl;
  
  for(int i = 0; i<result.size(); i++)
    cout<<result[i]<<endl;
  return 0;
}

