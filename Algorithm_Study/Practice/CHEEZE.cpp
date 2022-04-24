/*
(1) 변수 n, m에 배열의 크기를 넣어주고 배열에 정보를 넣어준다. 
(2) while을 통해서 BFS 를 반복함. 
  -한번 할때마다 테두에 위치한 치즈가 지워짐.
(3) 
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
#define MAX 110

int arr[MAX][MAX];
int n, m;
int cheeNum=9999; 
int timeCount;
int dy[4] = { -1, 0 , 0, 1 };
int dx[4] = { 0, -1, 1, 0 };

bool visited[MAX][MAX];
bool flag = false;

struct p { // 두개의 값을 넣어야 하기 때문에 구조체를 만들어 준다. 
	int y;
	int x;
};

void BFS1(int y, int x) {
	queue <p> Queue1;
	Queue1.push({ y, x }); // 큐에 y, x 좌표 숫자를 넣는다. 순서 주의!
  int cnt = 0; // 지워지는 치즈의 갯수를 센다. 
  
	while (!Queue1.empty()) {
		p front = Queue1.front();
    
		int curY = front.y;
		int curX = front.x;
		Queue1.pop(); 

		for (int k = 0; k < 4; k++) {
			int yy = curY + dy[k];
			int xx = curX + dx[k];

			if (0 <= yy && yy < n && 0 <= xx && xx < m  // 상, 하, 좌, 우의 숫자가 범위 안에 있다.
				&&arr[curY][curX]==0&&!visited[yy][xx]) { // 현재 노드는 0 (공기상태)이고, 방문한 적이 없어야 한다. 
				  
				if(arr[yy][xx]==1){ // 만약 현재 노드의 상, 하, 좌, 우 중에서 
				  arr[yy][xx] = 0;  //어떠한 노드가 1이면 0으로 해줌.
				  cnt++; //치즈가 녹았으니까 카운트 +1을 해준다. 
				}
				else if(arr[yy][xx]==0){ // 상하좌우의 노드가 0이면 
				  Queue1.push({ yy, xx }); // 상하좌우 노드도 이웃 노드로 간주하고 큐에 넣어준다. 
				}
					visited[yy][xx] = true; // 방문 했음을 표시한다. 
			}
		}
	}
	if(cheeNum>cnt && cnt != 0){ // 녹은 치즈의 숫자를 cheeNum 에 넣는다.
	  cheeNum=cnt; // 치즈가 0일 경우는 뺀다. 
	}
	if(cnt==0){ 
	  flag = true;
	  cout<<timeCount<<endl; // 시간
	  cout<<cheeNum<<endl; // 다 지워지기 전 치즈의 갯수
	  return ;
	}
	
// 	for (int i = 0; i < n; i++) {
// 			for (int j = 0; j < m; j++) {
// 				cout << arr[i][j] << " ";
// 			}cout << endl;
// 		}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	while(flag==false){
	BFS1(0, 0); // 초기 0, 0 으로 시작
	memset(visited, 0, sizeof(visited)); // 다음 번 확인을 위해서 초기화를 해야함
	timeCount++; // 한번 while 반복 문이 돌때 1시간으로 한다. 
	}
	return 0;
}
/*
 13 12
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 1 0 0 0
0 1 1 1 0 0 0 1 1 0 0 0
0 1 1 1 1 1 1 0 0 0 0 0
0 1 1 1 1 1 0 1 1 0 0 0
0 1 1 1 1 0 0 1 1 0 0 0
0 0 1 1 0 0 0 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
 */
 