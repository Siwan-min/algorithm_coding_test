/*
문제 파악: 
(1) 맵에는 디저트 종류를 나타내는 정보가 들어있음 
(2) 마름모 형태의 사각형을 그리면서 이동함. 
(3) 범위를 당연히 벗어날 수는 없음. 
(4) 한 방향으로만 회전 (시계 방향) 
(5) 같은 종류의 디저트를 먹지 않음. 
결과: 규칙에 따라 이동할 때 디저트를 최대로 몇개 먹을 수 있는지 구하여라.  
--------------------------------------------------------------
문제 해결 방안: 
(1) 맵에 정보를 받는다
(2) 기저 조건
	- 현재 위치가 초기 위치의 좌측 하단에 있을 경우  
(3) visited 배열을 써서 방문 했는지 안했는지를 확인 
	-방문했던 자리면 continue 처리 
(4) dessert 배열을 만들고  map[i][j]가 갖는 값을 dessert 배열 인덱스 true 처리한다.
   - 이미 true 상태이면 continue 처리 
(5) (3), (4) 조건을
	- ny, nx 가 범위 안에 있고 visited[ny][nx], dessert[map[ny][nx]]가 false 상태일 경우 
	dessert, visited를 true 처리하고 dfs(y위치, x위치, cnt+1) 재귀 호출을 하는 방식으로 대처 가능. 
(6) cnt의 max 값을 구한다. 

>> 
방향 0 일때는 0, 1 만 가능
방향 1 일때는 1, 2 만 가능
방향 2 일때는 2, 3 만 가능 
방향 3 일때는 3 만 가능  
---------------------------------------------------------------------- 
 
*/

#include <iostream>
#include <cstring>
#include <vector>
#define MAX 110
using namespace std;

int T, n, result;
int map[30][30];
bool visited[30][30];
bool desert[MAX];
int startY, startX; //시작점 
int dy[4] = {1, 1, -1, -1}; //(우,하), (좌,하) , (좌, 상), (우, 상) 
int dx[4] = {1, -1, -1, 1};

void dfs(int y, int x, int p, int cnt){
    
    if( y == startY+1 && x == startX-1){ //기저조건  
       if(result < cnt)
       result = cnt;
       return;
    }
    for(int i = 0; i < 4; i++){
      
        if (i < p || i > p + 1 || (cnt == 1 && i == 1)) continue;
		 //첫번째 실행일 경우를 제외해야함  
		//방향 조건 
        int ny = y + dy[i];
        int nx = x + dx[i];
       
       if(ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx] && !desert[map[ny][nx]]){
          visited[ny][nx] = true;
          desert[map[ny][nx]] = true;
  
          dfs(ny, nx, i, cnt+1);
          
          visited[ny][nx] = false;
          desert[map[ny][nx]] = false;
       }
    }
    return; 
}
int main(){

    cin>>T;
    for(int tc = 1; tc<=T; tc++){
        cin>>n;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cin>>map[i][j];
            }
        }
        result = -1;
        for(int i = 0; i<n-2; i++){
            for(int j = 1; j<n-1; j++){
                startY = i, startX = j;
                visited[i][j] = true;
                desert[map[i][j]] = true;
                dfs( i, j, 0, 1);
                desert[map[i][j]] = false;
                visited[i][j] = false;
            }
        }
        cout<<"#"<<tc<<" "<<result<<endl;
    }
    return 0;
}
