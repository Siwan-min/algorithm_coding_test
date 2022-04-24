#include <iostream>
#include <cstring>
#include <cstdio>
#define MAX 130

using namespace std;

int Map[MAX][MAX];
int t;

bool visited[MAX][MAX];

const int toWEST = 1;// 동에서 서
const int toEAST = 2; // 서에서 동
const int toNORTH = 3; // 남에서 북
const int toSHOUTH = 4; // 북에서 남

int getResult(int dir, int n, int y, int x) {
	int  cnt = 0;
	int sy = y, sx = x;
	int ey = y, ex = x;


	int k = dir;

	while (1) {
		//   if (Map[sy][sx] == -1) {
					// 	break;
					// }
			  //이동


		if (dir == toWEST) sx = sx - 1;
		else if (dir == toEAST) sx = sx + 1;
		else if (dir == toNORTH) sy = sy - 1;
		else if (dir == toSHOUTH) sy = sy + 1;
		//범위 밖
		if (y == sy && x == sx) {
			return cnt;
			break;

		}
		//	else {

		if (Map[sy][sx] == -1) {
			return cnt;
			break;
		}

		else if (Map[sy][sx] >= 1 && Map[sy][sx] <= 5) {

			if (dir == toWEST) {
				if (Map[sy][sx] == 3 || Map[sy][sx] == 4 || Map[sy][sx] == 5) {
					dir = toEAST;
					cnt++;
				}
				else if (Map[sy][sx] == 1) {
					dir = toNORTH;
					cnt++;
				}
				else if (Map[sy][sx] == 2) {
					dir = toSHOUTH;
					cnt++;
				}
			}
			else if (dir == toEAST) {
				if (Map[sy][sx] == 1 || Map[sy][sx] == 2 || Map[sy][sx] == 5) {
					dir = toWEST;
					cnt++;
				}
				else if (Map[sy][sx] == 4) {
					dir = toNORTH;
					cnt++;
				}
				else if (Map[sy][sx] == 3) {
					dir = toSHOUTH;
					cnt++;
				}
			}
			else if (dir == toNORTH) {
				if (Map[sy][sx] == 1 || Map[sy][sx] == 4 || Map[sy][sx] == 5) {
					dir = toSHOUTH;
					cnt++;
				}
				else if (Map[sy][sx] == 2) {
					dir = toEAST;
					cnt++;
				}
				else if (Map[sy][sx] == 3) {
					dir = toWEST;
					cnt++;
				}
			}
			else if (dir == toSHOUTH) {
				if (Map[sy][sx] == 2 || Map[sy][sx] == 3 || Map[sy][sx] == 5) {
					dir = toNORTH;
					cnt++;
				}
				else if (Map[sy][sx] == 4) {
					dir = toWEST;
					cnt++;
				}
				else if (Map[sy][sx] == 1) {
					dir = toEAST;
					cnt++;
				}
			}
		}
		else if (Map[sy][sx] >= 6 && Map[sy][sx] <= 10) { //워프
			bool flag = false;

			// if(visited[sy][sx]==false){
			//   //cnt+=2;
			//   visited[sy][sx]=true;
			// }
			int warp = Map[sy][sx];
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (Map[i][j] == Map[sy][sx] && (sy != i || sx != j)) {
						sy = i;
						sx = j;

						//   visited[i][j]=true;
						flag = true;
						break;
					}
				}
				if (flag == true) break;
			}
		}
		//	}


	} //cout<<cnt;
	return cnt;
}

void search(int t, int n) {

	int value;
	int y, x;
	int max = 0;


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
            if (Map[i][j] == 0)
            { //출발점
                for (int k = 1; k <= 4; k++) {
					int value = getResult(k, n, i, j);
					//	memset(visited, 0, sizeof(visited));
					if (max < value) {
						max = value;
					}
				}//cout<<" ";
            }
        }
	}
	cout << "#" << t << " " << max << endl;
	memset(Map, 0, sizeof(Map));
}

void input(int t) {
	int n = 0;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		for (int p = 0; p <= n + 1; p++) {
			for (int q = 0; q <= n + 1; q++) {
				Map[p][q] = 5;
			}
		}
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				cin >> Map[j][k];
			}

		}
		search(i, n);
	}

}

int main() {

	cin >> t;
	input(t);

	return 0;
}