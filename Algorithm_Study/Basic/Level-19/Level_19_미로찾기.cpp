#include <iostream>
#include <queue>

using namespace std;


struct p{
  
  int y;
  int x;
  
};

int n, m;
int arr[1003][1003];
int cost[1003][1003];

bool visited[1003][1003];

queue <p> Queue;

int dy[4] = { -1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};


void gerResult(int y, int x){
  
  Queue.push({y, x});
  visited[y][x] = true;
  
  while(!Queue.empty()){
    
    p front = Queue.front();
    Queue.pop();
    
    int curY = front.y;
    int curX = front.x;
    
    for(int i = 0; i < 4; i++){
      int yy = curY + dy[i];
      int xx = curX + dx[i];
      
      if(yy >= 0 && yy < n && xx >= 0 && xx < m && !visited[yy][xx] && arr[yy][xx] == 0){
        visited[yy][xx] = true;
        cost[yy][xx] = cost[curY][curX] + 1;
        
        Queue.push({yy, xx});
      }
    }
  }
}


int main(){
  cin>>n>>m;
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>arr[i][j];
    }
  }
  
  gerResult(n-1, 0);
  cout<<cost[0][m-1];
  return 0;
}