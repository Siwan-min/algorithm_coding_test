/*
1. ���� �ľ�:
(1) N ���� ������ ����Ʈ�� �� �ִ�. 
(2) ���� ���� ���� (���� �� - 1)
(3) ������ �ִ��� ���� �������� ���� ������ ������ ���Ͽ���
	(���� ������ �ּ��϶� ���� ���϶�)

2. ���� �ذ� ���:
(1) temp �迭�� �����.
	-������ �����鼭 �迭�� ���� �ٲ�� ������ �ӽ� �迭�� ����� �ٽ� �����ϱ� ���ؼ�
(2) ���� ���� m �� k(������ ����)��ŭ ���� ������ ���Ѵ�. 
	-��� ȣ���� �Ͽ� ������ ���Ѵ�. 
	-������ ��������� ���� ���ϴ� �Լ��� ȣ���Ѵ�.
(3) ���� Ž�� �ùķ��̼����� ������ �νŴ�.
	-���������� ������ ������ ��찡 �����Ƿ� ť�� Ȱ���Ѵ�. 
(4) ������ �����Ѵ�. 
	-ť�� Ȱ���Ͽ� 0�� �ƴ� ���� ť�� �ְ� �� �ؿ������� 0�� ���� �ϳ��� ���� �־��ش�.
(5) ��� ������ ��츦 �� �غ��� ���� (3), (4) ������ �ݺ� �ϸ鼭 
�� ���� ������ ������ ���� ���� ������ ������ ī��Ʈ ���ش�. 
	-�ݺ����� Ȱ���Ͽ� temp[i][j]�� ������ ������ cnt++
	-���� �迭�� ���� ���� ������ �Ͽ��Ѵ�. 
*/

#include <iostream> 
#include <queue>
#include <cstring>
#define MAX 20
using namespace std;

struct p {
	int y;
	int x;
	int value; // ������ ������ �����ϱ� ���� 
};

int T;
int k, n, m; //k: ������ ����, n: ���� ����, m: ���� ����
int arr[MAX][MAX]; //������ ���� �޴� ���� 
int temp[MAX][MAX]; 
int _min = 999999;

int sival[MAX]; // m ������ �ʿ��� ������ŭ 0 ���� ���ʷ� ������ ���� �����Ѵ�. 
/*
10�� �� 3���� ���� ���
ex) ������ 0 1 3 �� ���
sival[0] --> 0
sival[1] --> 1
sival[2] --> 3
*/

queue <p> Q; // ��ǥ ������ ��� ���� �뵵
queue <int> haha; //�迭�� ���� ���ִ� �뵵 

void sorting() {

	for (int j = 0; j < m; j++) {
		int jhola = n - 1; //�ؿ��� ���� Ž��!
		for (int i = n - 1; i >= 0; i--) {
			if (temp[i][j]) { //���� ���� ������ �� ���� ť "haha"�� push ���ش�.  
				haha.push(temp[i][j]);
				temp[i][j] = 0; //0 �ʱ�ȭ
			}
		}
		while (!haha.empty()) {
			if (temp[jhola][j] == 0) { // �ؿ������� 0�� �ڸ��� haha ť ���� �ϳ��� �־��ش�. 
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
			int down_y = y + range; // y �������� ������ ������ ����
			int up_y = y - range; // y �������� ���� ������ ����
			int right_x = x + range; // x �������� ���������� ������ ����
			int left_x = x - range; // x �������� �������� ������ ���� 

			
			if (down_y >= n) down_y = n - 1; // ���� ���� ���� ����� 0���� ������Ʈ ���ش�.  
			if (up_y < 0) up_y = 0;
			if (right_x >= m) right_x = m - 1;
			if (left_x < 0) left_x = 0;
			//������ Ž��
			for (int i = y; i <= down_y; i++) { 

				if (temp[i][x] > 0) {
					Q.push({ i, x, temp[i][x] });
					temp[i][x] = 0;
				}
			}
			//���� Ž��
			for (int i = up_y; i <= y; i++) {

				if (temp[i][x] > 0) {
					Q.push({ i, x, temp[i][x] });
					temp[i][x] = 0;
				}
			}
			//������ Ž��
			for (int i = x; i <= right_x; i++) {

				if (temp[y][i] > 0) {
					Q.push({ y, i, temp[y][i] });
					temp[y][i] = 0;
				}
			}
			//���� Ž��
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
					Q.push({ i, sival[index], temp[i][sival[index]] }); // ���� �ִ� ���� ��ǥ�� �� �迭�� �� ��ǥ�� ������ ���� push ���ش�.
					getResult(); //�� ���Ϸ� ���� ! 
					sorting(); // �迭�� �ִ� ���� ������ �� ���� ���ش�. 
					break; // ���� �� ���� �ִ� �� �ϳ��� �ʿ� �ϹǷ� break! 
				}
			}
		}
	}
	else {

		for (int i = 0; i < m; i++) {

			sival[x] = i; // m���� ������ �迭�� ����
			getComb(x + 1);
			sival[x] = 0; //��� �Լ����� ���� ������ �迭[x] ���� �ʱ�ȭ 
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (temp[i][j]) cnt++; //���� �ִ� ������ ���� ī��Ʈ! 

			if (temp[i][j] != arr[i][j]) { 
				temp[i][j] = arr[i][j]; //���� �迭�� �ٽ� �ǵ�����. 
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
				temp[i][j] = arr[i][j]; //���� �迭�� ���� 
			}
		}

		getComb(0); // ���� ã���� ���� ! 

		cout << "#" << tc << " " << _min << endl;
		memset(temp, 0, sizeof(temp));
		memset(arr, 0, sizeof(arr));
		_min = 999999;
	}
	return 0;
}
