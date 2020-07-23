/*
1. 문제 파악:
(1) N 개의 구슬을 떨어트릴 수 있다. 
(2) 벽돌 제거 범위 (벽돌 값 - 1)
(3) 벽돌이 최대한 많이 깨졌을때 남은 벽돌의 개수를 구하여라
	(벽돌 개수가 최소일때 값을 구하라)

2. 문제 해결 방안:
(1) temp 배열을 만든다.
	-벽돌이 깨지면서 배열의 값이 바뀌기 때문에 임시 배열을 만들고 다시 복원하기 위해서
(2) 열의 개수 m 중 k(구슬의 개수)만큼 고르는 조합을 구한다. 
	-재귀 호출을 하여 조합을 구한다. 
	-조합이 만들어지면 답을 구하는 함수를 호출한다.
(3) 완전 탐색 시뮬레이션으로 벽돌을 부신다.
	-연쇄적으로 벽돌이 깨지는 경우가 있으므로 큐를 활용한다. 
(4) 벽돌을 정렬한다. 
	-큐를 활용하여 0이 아닌 값을 큐에 넣고 맨 밑에서부터 0인 곳데 하나씩 값을 넣어준다.
(5) 모든 조합의 경우를 다 해볼때 까지 (3), (4) 과정을 반복 하면서 
한 가지 조합이 끝날때 마다 남은 벽돌의 갯수를 카운트 해준다. 
	-반복문을 활용하여 temp[i][j]에 벽돌이 있으면 cnt++
	-원래 배열과 같은 값을 갖도록 북원한다. 
*/

#include <iostream> 
#include <queue>
#include <cstring>
#define MAX 20
using namespace std;

struct p {
	int y;
	int x;
	int value; // 터지는 범위를 지정하기 위함 
};

int T;
int k, n, m; //k: 구슬의 개수, n: 행의 개수, m: 열의 개수
int arr[MAX][MAX]; //원래의 맵을 받는 변수 
int temp[MAX][MAX]; 
int _min = 999999;

int sival[MAX]; // m 열에서 필요한 개수만큼 0 부터 차례로 조합의 값을 저장한다. 
/*
10개 중 3개를 고르는 경우
ex) 조합이 0 1 3 일 경우
sival[0] --> 0
sival[1] --> 1
sival[2] --> 3
*/

queue <p> Q; // 좌표 정보를 담기 위한 용도
queue <int> haha; //배열을 정렬 해주는 용도 

void sorting() {

	for (int j = 0; j < m; j++) {
		int jhola = n - 1; //밑에서 부터 탐색!
		for (int i = n - 1; i >= 0; i--) {
			if (temp[i][j]) { //만약 값이 있으면 그 값을 큐 "haha"에 push 해준다.  
				haha.push(temp[i][j]);
				temp[i][j] = 0; //0 초기화
			}
		}
		while (!haha.empty()) {
			if (temp[jhola][j] == 0) { // 밑에서부터 0인 자리에 haha 큐 값을 하나씩 넣어준다. 
				temp[jhola][j] = haha.front();
				haha.pop();
			}
			jhola--;
		}
	}
}

void getResult() {

	while (!Q.empty()) {

		p front = Q.front();

		int y = front.y;
		int x = front.x;
		int r = front.value;

		Q.pop();

		int range = r - 1;

		temp[y][x] = 0;

		if (range > 0) {
			int down_y = y + range; // y 기준으로 밑으로 터지는 범위
			int up_y = y - range; // y 기준으로 위로 터지는 범위
			int right_x = x + range; // x 기준으로 오른쪽으로 터지는 범위
			int left_x = x - range; // x 기준으로 왼쪽으로 터지는 범위 

			
			if (down_y >= n) down_y = n - 1; // 맵의 범위 밖을 벗어나면 0으로 업데이트 해준다.  
			if (up_y < 0) up_y = 0;
			if (right_x >= m) right_x = m - 1;
			if (left_x < 0) left_x = 0;
			//밑으로 탐색
			for (int i = y; i <= down_y; i++) { 

				if (temp[i][x] > 0) {
					Q.push({ i, x, temp[i][x] });
					temp[i][x] = 0;
				}
			}
			//위로 탐색
			for (int i = up_y; i <= y; i++) {

				if (temp[i][x] > 0) {
					Q.push({ i, x, temp[i][x] });
					temp[i][x] = 0;
				}
			}
			//오른쪽 탐색
			for (int i = x; i <= right_x; i++) {

				if (temp[y][i] > 0) {
					Q.push({ y, i, temp[y][i] });
					temp[y][i] = 0;
				}
			}
			//왼쪽 탐색
			for (int i = left_x; i <= x; i++) {

				if (temp[y][i] > 0) {
					Q.push({ y, i, temp[y][i] });
					temp[y][i] = 0;
				}
			}
		}
	}
}

void getComb(int x) {

	if (x >= k) {

		for (int index = 0; index < k; index++) {

			for (int i = 0; i < n; i++) {
				if (temp[i][sival[index]] != 0) {
					Q.push({ i, sival[index], temp[i][sival[index]] }); // 값이 있는 곳의 좌표와 그 배열의 그 좌표가 가지는 값을 push 해준다.
					getResult(); //답 구하러 ㄱㄱ ! 
					sorting(); // 배열에 있는 값을 밑으로 다 정렬 해준다. 
					break; // 가장 맨 위에 있는 값 하나만 필요 하므로 break! 
				}
			}
		}
	}
	else {

		for (int i = 0; i < m; i++) {

			sival[x] = i; // m열의 조합을 배열에 저장
			getComb(x + 1);
			sival[x] = 0; //재귀 함수에서 빠져 나오면 배열[x] 값을 초기화 
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (temp[i][j]) cnt++; //남아 있는 벽돌의 수를 카운트! 

			if (temp[i][j] != arr[i][j]) { 
				temp[i][j] = arr[i][j]; //템프 배열을 다시 되돌린다. 
			}
		}
	}
	if (_min > cnt) _min = cnt;
}

int main() {

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		cin >> k >> m >> n;
		int idx = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
				temp[i][j] = arr[i][j]; //템프 배열에 복사 
			}
		}

		getComb(0); // 조합 찾으러 ㄱㄱ ! 

		cout << "#" << tc << " " << _min << endl;
		memset(temp, 0, sizeof(temp));
		memset(arr, 0, sizeof(arr));
		_min = 999999;
	}
	return 0;
}
