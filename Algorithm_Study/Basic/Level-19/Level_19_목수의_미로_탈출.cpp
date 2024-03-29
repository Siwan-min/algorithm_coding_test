#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 1050
using namespace std;

struct p {
  int y;
  int x;
};

int n, m;
int Map[MAX][MAX];
bool check[MAX][MAX];
int c1[MAX][MAX], c2[MAX][MAX];
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};
int result;

void getResult(int y, int x, int cost[MAX][MAX]){
  queue <p> Queue;
  
  Queue.push({y, x});
  check[x][y] = true;
  
  while(!Queue.empty()){
    p front = Queue.front();
    Queue.pop();
    
    
    int curY = front.y;
    int curX = front.x;
    
    for(int k = 0; k<4; k++){
      int yy = curY + dy[k];
      int xx = curX + dx[k];
      
      if( 0 <= yy && yy < n && 0 <= xx && xx < m && !check[yy][xx]){
        check[yy][xx]=true;
        cost[yy][xx] = cost[curY][curX] + 1;
        
        if(Map[yy][xx]==0)
          Queue.push({yy, xx});
      }
    }
  }
}

int main(){
  scanf("%d %d", &n, &m);
  
  for(int i = 0; i<n; i++){
    for(int j = 0 ; j<m; j++){
      scanf("%d", &Map[i][j]);
    }
  }
  
  getResult(n-1, 0, c1);
  
  memset(check, 0, sizeof(check));
  
  getResult(0, m-1, c2);
  
  result = 987923424;
  
  for(int i = 0; i<n; i++){
    for(int j = 0; j<m; j++){
      if(Map[i][j] && c1[i][j]>0 && c2[i][j]>0)
      result = min(result, c1[i][j] + c2[i][j]);
    }
  }
  printf("%d", result);
  return 0;
}