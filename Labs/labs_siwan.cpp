#include <iostream>
#include <cstring>
#include <queue>

#define MAX 110

using namespace std;

int t, n, m, k, cnt, samsung;
int arr[MAX][MAX];
int cost[MAX][MAX];
int comResult[MAX];
int _min = 9999;

bool check[MAX][MAX];
bool wall[MAX][MAX];
bool com[MAX];
bool visited[MAX][MAX];
bool space[MAX][MAX];

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1 , -1, 0, 0 };

struct p {
	int y;
	int x;
};
queue <p> Queue;

void BFS() {
	samsung++;
	int _max = 0;
	bool flag = false;

	while (!Queue.empty()) {

		p front = Queue.front();
		Queue.pop();

		int curY = front.y;
		int curX = front.x;

		visited[curY][curX] = true;
		for (int i = 0; i < 4; i++) {
			int yy = curY + dy[i];
			int xx = curX + dx[i];

			if (yy >= 1 && yy <= n && xx >= 1 && xx <= n
				&& visited[yy][xx] == false
				&& wall[yy][xx] == false
				&& check[yy][xx] == false) {
				if (cost[yy][xx] == 0) {
					cost[yy][xx] = cost[curY][curX] + 1;
					if (_max < cost[yy][xx] && space[yy][xx] == true) _max = cost[yy][xx];
				}
				Queue.push({ yy, xx });
				visited[yy][xx] = true;
			}

		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			//cout<<cost[i][j]<<" ";
		}//cout<<endl;
	}
	//cout<<endl;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cost[i][j] == 0 && visited[i][j] == false && wall[i][j] == false) {
				flag = true;
				//  cout<<i<<" "<<j<<endl;
			}
		}
	}

	if (flag == true) cnt++;
	else if (flag == false) {
		if (_min > _max) _min = _max;
	}
	//flag = false;
   //cout<<cnt;
	memset(cost, 0, sizeof(cost));
	memset(visited, 0, sizeof(visited));
	memset(check, 0, sizeof(check));

}

void getCombination(int x, int diffuser) {

	if (x >= k) {
	
		// for (int i = 0; i < k; i++) {
		// 	cout<<comResult[i]<<" ";
		// }cout<<endl;
		
		for (int q = 0; q < k; q++) {

			int num;
			num = comResult[q];

			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (wall[i][j] == false) {
						if (num == arr[i][j]) {
							Queue.push({ i, j });
							check[i][j] = true;
						}
					}
				}
			}
		}
		BFS();
	}
	else {

		for (int i = 1; i < diffuser; i++) {
			int data = i;

			if (com[i] == false) {
				if (x > 0 && comResult[x - 1] > data) continue;

				comResult[x] = data;
				com[i] = true;
				getCombination(x + 1, diffuser);
				com[i] = false;
				comResult[x] = 0;

			}
		}
	}
}

int main() {

		cin >> n >> k;
		int diffuser = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 0) space[i][j] = true;
				else if (arr[i][j] == 1 && wall[i][j] == false) {
					wall[i][j] = true;
					//cost[i][j] = -1;
				}
				else if (arr[i][j] == 2 && check[i][j] == false) {
					arr[i][j] = diffuser;
					diffuser++;
					//check[i][j] = true; 
				}
			}
		}
		//cout<<diffuser;
		getCombination(0, diffuser);
		// cout<<samsung;
		if (cnt >= samsung) cout << "-1" << endl;
		else cout << _min << endl;
	
	
	return 0;
}

/*
2
4 4 2
0 1 0 2
2 0 1 0
0 0 0 1
0 0 2 0
4 4 15
0 2 2 2 
2 2 2 2 
2 2 2 2 
2 2 2 2 

*/