#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define MAX 110

int m, n, h;
int arr[MAX][MAX][MAX];

int dz[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 0, 0, 1};
int dx[6] = {0, 0, 0, -1, 1, 0};
int tday = 1;

bool visited[MAX][MAX][MAX];
bool flag = false;

struct p{
  int z;
  int y;
  int x;
};
queue <p> Queue;
void BFS(){
  
  while(!Queue.empty()){
    p front = Queue.front();
    int curZ = front.z;
    int curY = front.y;
    int curX = front.x;
    Queue.pop();
    
    for(int i = 0; i<6; i++){
      int zz = curZ + dz[i];
      int yy = curY + dy[i];
      int xx = curX + dx[i];
     
      
      if(yy>=0 && yy<n 
      && xx>=0 && xx<m
      && zz>=0 && zz<h
      && !visited[zz][yy][xx] 
      && arr[curZ][curY][curX]){
        if(arr[zz][yy][xx]==0){
          arr[zz][yy][xx]=arr[curZ][curY][curX]+1;
          if(arr[zz][yy][xx]>tday){
            tday = arr[zz][yy][xx];
          }
          Queue.push({zz, yy, xx});
        }
        visited[zz][yy][xx] = true;
      }
    }
  }
}

int main() {
cin>>m>>n>>h;

for(int i = 0; i<h; i++){
  for(int j = 0; j<n; j++){
    for(int k = 0; k<m; k++){
      cin>>arr[i][j][k];
      if(arr[i][j][k]==1)
      Queue.push({i,j,k});
    }
  }
}

BFS();

for(int i = 0; i<h; i++){
  for(int j = 0; j<n; j++){
    for(int k = 0; k<m; k++){
    if(arr[i][j][k]==0){
    flag = true;
    break;
      }
    }
  }
}

if(flag == true) cout<<"-1";
else cout<<tday-1;
  return 0;
}
/*
h: 높이, m: 가로, n: 세로
 
1: 익은 토마토
0: 익지 않은 토토마토
-1: 빈칸 
 
*/
 
/*
4 3 2
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
-1 -1 -1 -1
1 1 1 -1

5 3 2
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 1 0 0
0 0 0 0 0

5 3 1
0 -1 0 0 0
-1 -1 0 1 1
0 0 0 1 1
*/