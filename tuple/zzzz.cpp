#include <iostream>
#include <cstring>
#define MAX 350

using namespace std;

int t, n, m, k;

int arr[MAX][MAX]; 
int cost[MAX][MAX];
int vitality[MAX][MAX];

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

bool check[MAX][MAX];
bool temp[MAX][MAX];
bool die[MAX][MAX];
bool good[MAX][MAX];
bool flag = false;

int search(int ystart, int xstart, int yend, int xend, int k){

	int cnt = 0;

	while (cnt < k) {

		cnt++;

		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if (arr[i][j] != 0 && check[i][j] == false) cost[i][j] = cost[i][j] + 1; // cost + 1

				if (arr[i][j] == 0)
					temp[i][j] = true;
				else temp[i][j] = false; // false 면 절대 못바꿈 

			}
		}

		for (int i = ystart; i < yend; i++) {
			for (int j = xstart; j < xend; j++) {
				if (good[i][j] == true && die[i][j] == false) { // 활성화 되어 있고, 안죽었다  
					vitality[i][j]++;

					for (int dir = 0; dir < 4; dir++) {
						int y = i + dy[dir];
						int x = j + dx[dir];

						if (arr[y][x] >= 0 && check[y][x] == false && temp[y][x] == true) {
							if (flag == false) {
								ystart = ystart - 1;
								xstart = xstart - 1;
								yend = yend + 1;
								xend = xend + 1;
								
								if (ystart < 0) ystart = 0;
								if (xstart < 0) xstart = 0;
								if (yend > 350) yend = 350;
								if (xend > 350) xend = 350;
								flag = true;

							}
							if (arr[y][x] < arr[i][j]) {
								arr[y][x] = arr[i][j];
							}
						}	check[i][j] = true;
					}


					if (vitality[i][j] == arr[i][j]) {
						die[i][j] = true;
						good[i][j] = false; //비활성화 시킴
					}
				}
			}
		}

		flag = false;

		for (int i = ystart; i < yend; i++) {
			for (int j = xstart; j < xend; j++) {

				if (cost[i][j] == arr[i][j] && arr[i][j] != 0 && check[i][j] == false) {
					//다 자랐고, 0 이 아니다. check[i][j] 는 false 
					good[i][j] = true; //활성화

				}
			}
		}
	}


	int num = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			//cout << arr[i][j] << " ";
			if (arr[i][j]) {
				if (!die[i][j] || good[i][j] == true) {
					num++;
				}
			}
		}//cout << endl;
	}
	return num;
}

int main(){

    cin>>t;

    for (int tc = 1; tc <= t; tc++) {
		cin >> n >> m >> k;
		int ystart = (MAX - n) / 2;
		int xstart = (MAX - m) / 2;
		int yend = ystart + n;
		int xend = xstart + m;
		int result = 0;
		for (int i = ystart; i < yend; i++) {
			for (int j = xstart; j < xend; j++) {
				cin >> arr[i][j]; // 입력
				
				// if (arr[i][j] != 0) check[i][j] = true;
			}
		}

		result = search(ystart, xstart, yend, xend, k);

		cout << "#" << tc << " " << result << endl;

		memset(arr, 0, sizeof(arr));
		memset(die, 0, sizeof(die));
		memset(good, 0, sizeof(good));
		memset(check, 0, sizeof(check));
		memset(cost, 0, sizeof(cost));
		memset(vitality, 0, sizeof(vitality));
     memset(temp, 0, sizeof(temp));
    }
    return 0;
}


  
// #include <iostream>
// #include <cstring>
// #define MAX 350

// using namespace std;

// int t, n, m, k;

// int arr[MAX][MAX]; //입력
// int cost[MAX][MAX]; //
// int vitality[MAX][MAX];

// int dy[4] = { 0, 0, 1, -1 };
// int dx[4] = { 1, -1, 0, 0 };

// bool check[MAX][MAX];
// bool sibal[MAX][MAX];
// bool die[MAX][MAX]; //죽은거
// bool good[MAX][MAX]; //활성화
// bool flag = false;

// int search(int ystart, int xstart, int yend, int xend, int k) {

// 	int cnt = 0;

// 	while (cnt < k) {

// 		cnt++;

// 		for (int i = 0; i < MAX; i++) {
// 			for (int j = 0; j < MAX; j++) {
// 				if (arr[i][j] != 0 && check[i][j] == false) cost[i][j] = cost[i][j] + 1; // cost + 1

// 				if (arr[i][j] == 0)
// 					sibal[i][j] = true;
// 				else sibal[i][j] = false; // false 면 절대 못바꿈 

// 			}
// 		}

// 		for (int i = ystart; i < yend; i++) {
// 			for (int j = xstart; j < xend; j++) {
// 				if (good[i][j] == true && die[i][j] == false) { // 활성화 되어 있고, 안죽었다  
// 					vitality[i][j]++;

// 					for (int dir = 0; dir < 4; dir++) {
// 						int y = i + dy[dir];
// 						int x = j + dx[dir];

// 						if (arr[y][x] >= 0 && check[y][x] == false && sibal[y][x] == true) {
// 							if (flag == false) {
// 								ystart = ystart - 1;
// 								xstart = xstart - 1;
// 								yend = yend + 1;
// 								xend = xend + 1;

// 								if (ystart < 0) ystart = 0;
// 								if (xstart < 0) xstart = 0;
// 								if (yend > 350) yend = 350;
// 								if (xend > 350) xend = 350;
// 								flag = true;

// 							}
// 							if (arr[y][x] < arr[i][j]) {
// 								arr[y][x] = arr[i][j];
// 							}
// 						}	check[i][j] = true;
// 					}


// 					if (vitality[i][j] == arr[i][j]) {
// 						die[i][j] = true;
// 						good[i][j] = false; //비활성화 시킴
// 					}
// 				}
// 			}
// 		}

// 		flag = false;

// 		for (int i = ystart; i < yend; i++) {
// 			for (int j = xstart; j < xend; j++) {

// 				if (cost[i][j] == arr[i][j] && arr[i][j] != 0 && check[i][j] == false) {
// 					//다 자랐고, 0 이 아니다. check[i][j] 는 false 
// 					good[i][j] = true; //활성화

// 				}
// 			}
// 		}
// 	}


// 	int num = 0;
// 	for (int i = 0; i < MAX; i++) {
// 		for (int j = 0; j < MAX; j++) {
// 			//cout << arr[i][j] << " ";
// 			if (arr[i][j]) {
// 				if (!die[i][j] || good[i][j] == true) {
// 					num++;
// 				}
// 			}
// 		}//cout << endl;
// 	}
// 	return num;
// }

// int main() {

// 	cin >> t;

// 	for (int tc = 1; tc <= t; tc++) {
// 		cin >> n >> m >> k;
// 		int ystart = (MAX - n) / 2;
// 		int xstart = (MAX - m) / 2;
// 		int yend = ystart + n;
// 		int xend = xstart + m;
// 		int result = 0;
// 		for (int i = ystart; i < yend; i++) {
// 			for (int j = xstart; j < xend; j++) {
// 				cin >> arr[i][j]; // 입력
				
// 				// if (arr[i][j] != 0) check[i][j] = true;
// 			}
// 		}

// 		result = search(ystart, xstart, yend, xend, k);

// 		cout << "#" << tc << " " << result << endl;

// 		memset(arr, 0, sizeof(arr));
// 		memset(die, 0, sizeof(die));
// 		memset(good, 0, sizeof(good));
// 		memset(check, 0, sizeof(check));
// 		memset(cost, 0, sizeof(cost));
// 		memset(vitality, 0, sizeof(vitality));
// 		memset(sibal, 0, sizeof(sibal));
// 	}
// 	//system("pause");
// 	return 0;
// }


/*

1
2 2 10
1 1
0 2
*/