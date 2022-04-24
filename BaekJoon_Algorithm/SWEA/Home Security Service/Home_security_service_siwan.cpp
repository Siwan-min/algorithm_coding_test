#include <iostream>
#include <cstring>
#define MAX 30
using namespace std;

int t, n, m, _max;
int arr[MAX][MAX];

struct p {     
	int homeY;
	int homeX;
};

p home[25 * 25]; 

int home_len;

int getResult(int y, int x) {

	for (int k = 1; k <= n * n; k++) { 
		int cnt = 0;
		int cost = k * k + (k - 1) * (k - 1); 

		for (int i = 0; i < home_len; i++) {

			int Y = y - home[i].homeY;
			int X = x - home[i].homeX;

			if (Y < 0) Y = Y * (-1);
			if (X < 0) X = X * (-1);

			if ((k - 1) >= (Y + X)) cnt++;
		}
		int value = cnt * m - cost; 
		if (value >= 0) {
			if (_max < cnt) {
				_max = cnt;
			}
		}
	} return _max;
}

int main() {

	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 1) { // 홈의 위치를 배열에 저장
					home[home_len].homeY = i;
					home[home_len].homeX = j;

					home_len++; //인덱스 ++ 
				}
			}
		}

		int value;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				value = getResult(i, j); 
			}
		}
		cout << "#" << tc << " " << value << endl;
		_max = 0, home_len = 0;
		memset(arr, 0, sizeof(arr));
		memset(home, 0, sizeof(home));
	}
	return 0;
}


