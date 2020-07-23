/*

1시간 마다 방향대로 미생물이 움직인다. 
상: 1, 하: 2, 좌: 3, 우: 4
부딪히면 미생물 수: n/2 (n이 홀수인 경우 (n-1)/2로 계산)

방향대로 이동시키는 것은 어렵지 않다. 
이 문제에서 가장 핵심적으로 해결해야 할 문제: 
(1) 동시간때에 서로 교차해서 이동 할 경우, 즉 (1, 1)에 있는 값이 (2, 1) 로 이동하고
 (2, 1)에 있는 값이 (1, 1)로 이동 할 경우 값이 겹치지 않도록 해야한다. 
(2) 여러 값이 모일 경우 방향을 어떻게 잡을 것인가. 

문제에 관한 설계: 
설계(1) Queue에 현재 맵에 있는 데이터들을 모두 push 하고 pop 하면서 Next 정보를 받고 Storge에 push 한다.
Queue가 empty 상태가 되었을 경우 Storge에 있는 데이터를 모두 맵에 다시 넣어준다.
이렇게 하면 문제(1)을 해결 할 수 있다.

설계(2) 값이 한 곳으로 모일 경우 가장 큰 값을 temp배열에 dir 값을 저장해 둔다.
그래서 Storge에 있는 값을 맵에 넣을 때 이미 어떤 값이 안에 차있다면, temp배열에 있는 값과 비교하여 
적절한 값을 맵에 넣어준다. 
이렇게 하면 문제(2)를 해결 할 수 있다.

*/

#include <iostream>
#include <queue>
#include <cstring>

#define MAX 105

using namespace std;

int T, n, m, k;

struct info{
 
  int num;
  int dir;
  
};

const int dy[5] = {0, -1, 1, 0, 0};
const int dx[5] = {0, 0, 0, -1, 1};
                    //상, 하, 좌, 우

struct p{
  
  int y;
  int x;
  int num;
  int dir;
  
};

info arr[MAX][MAX];
info temp[MAX][MAX];

queue <p> Queue; 
queue <p> Storge;

bool flag = false;

int getResult(){
  
  int cnt = 0;
  
  while(cnt<m){
    
    if(Queue.empty()){
      cnt++;
      memset(temp, 0, sizeof(temp));
      while(!Storge.empty()){
        
        p front = Storge.front();
        
        int insertY = front.y;
        int insertX = front.x;
        int insertN = front.num;
        int insertD = front.dir;
        Storge.pop();
        
        if(temp[insertY][insertX].num == 0){
          temp[insertY][insertX].num = insertN;
          temp[insertY][insertX].dir = insertD;
        }
        else{
          if(temp[insertY][insertX].num < insertN){
           temp[insertY][insertX].num = insertN;
           temp[insertY][insertX].dir = insertD;
          }
        }
      
        arr[insertY][insertX].num += insertN;
       
        if(arr[insertY][insertX].dir != 0) arr[insertY][insertX].dir = temp[insertY][insertX].dir;
        else arr[insertY][insertX].dir = insertD;
      }

      for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
       
        if(arr[i][j].num != 0) Queue.push({i, j, arr[i][j].num, arr[i][j].dir});
        }
      }
    }
    
    else{
      
      p front = Queue.front();
      
      int curY = front.y;
      int curX = front.x;
      int curN = front.num;
      int curD = front.dir;

      Queue.pop();
      
      int yy = curY + dy[curD]; 
      int xx = curX + dx[curD];
      int nn = 0;
      int dd = 0;
      
      if(yy == 0 || xx == 0 || yy == n-1 || xx == n-1 ){

        if( curN%2 == 0) nn = curN/2;
        
        else nn = (curN-1)/2;

        if(curD == 1) dd = 2;
        else if(curD == 2) dd = 1;
        else if(curD == 3) dd = 4;
        else if(curD == 4) dd = 3;
        
        Storge.push({yy, xx, nn, dd});
        
        arr[curY][curX].num = 0;
        arr[curY][curX].dir = 0;
        
      }
      
      else if( yy >= 1 && yy < n-1 && xx >= 1 && xx < n-1){
          nn = curN;
          dd = curD;
          arr[curY][curX].num = 0;
          arr[curY][curX].dir = 0;
          Storge.push({yy, xx, nn, dd});
      }
    }
    
  }
  
  int result = 0;
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      if(arr[i][j].num) result +=arr[i][j].num;
    }
  }
  return result;
}

int main(){
  
  cin>>T;
  
  for(int tc = 1; tc<=T; tc++){
    cin>>n>>m>>k;
    
    for(int i = 0; i<k; i++){
      int y, x, NumberOfMicro, dir;
      cin>>y>>x>>NumberOfMicro>>dir;
      Queue.push({y,x, NumberOfMicro, dir});
      arr[y][x].num = NumberOfMicro;
      arr[y][x].dir = dir;
    }
    
    cout<<"#"<<tc<<" "<<getResult()<<endl;  
    
    memset(arr, 0, sizeof(arr));
    
    while(!Queue.empty()){
      Queue.pop();
    }
    
  }
  
  return 0;
}


/*
1      
7 2 9   
1 1 7 1 
2 1 7 1
5 1 5 4
3 2 8 4 
4 3 14 1
3 4 3 3 
1 5 8 2 
3 5 100 1
5 5 1 1
*/