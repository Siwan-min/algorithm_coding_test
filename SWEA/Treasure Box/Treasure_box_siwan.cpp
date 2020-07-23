#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char ch[35];
char cv1[8]; // 0~n/4 
char cv2[8]; // n/4 ~ n/4*2;
char cv3[8]; // n/4*2 ~n/4*3
char cv4[8]; // n/4*2 ~ n

int result[40] = { 0, };
int tc, n, k;

int main() {
	cin >> tc;

	for (int t = 1; t <= tc; t++) {

		cin >> n >> k;
		cin >> ch;

		// for(int i = 0; i<n; i++){
		//   cout<<ch[i];
		// }

		// cout<<endl;
		int index = 0;
		for (int r = 0; r < n / 4; r++) {
			int temp = ch[n - 1];

			for (int i = n - 1; i > 0; i--) {
				ch[i] = ch[i - 1];
			}
			ch[0] = temp;
			//cout<<ch<<endl;

			memset(cv1, NULL, sizeof(cv1));
			for (int i = 0; i < n / 4; i++) {
				cv1[i] = ch[i];
				//cout<<cv1[i];
			}//cout<<endl;
			//cout<<cv1<<endl;

			memset(cv2, NULL, sizeof(cv2));
			for (int i = n / 4; i < (n / 4) * 2; i++) {
				cv2[i - n / 4] = ch[i];
				//cout<<cv2[i-n/4];
			}//cout<<endl;
		   // cout<<cv2<<endl;

			memset(cv3, NULL, sizeof(cv3));
			for (int i = (n / 4) * 2; i < (n / 4) * 3; i++) {
				cv3[i - (n / 4) * 2] = ch[i];
				// cout<<cv3[i-(n/4)*2];
			}//cout<<endl;
		   // cout<<cv3<<endl;

			memset(cv4, NULL, sizeof(cv4));
			for (int i = (n / 4) * 3; i < n; i++) {
				cv4[i - (n / 4) * 3] = ch[i];
				//cout<<cv4[i-(n/4)*3];
			}//cout<<endl;
			//cout<<cv4<<endl;
			result[index] = (int)strtol(cv1, NULL, 16); index++;
			result[index] = (int)strtol(cv2, NULL, 16); index++;
			result[index] = (int)strtol(cv3, NULL, 16); index++;
			result[index] = (int)strtol(cv4, NULL, 16); index++;


			// cout<<cv1<<cv2<<cv3<<cv4<<endl;
			// cout<<cv1<<endl;
			// cout<<cv2<<endl;
			// cout<<cv3<<endl;
			// cout<<cv4<<endl;

			// //10진수로 변환
			//   int nDec = (int)strtol(cv1, NULL, 16);
	
			//   //10진수 출력
			//   cout << nDec << endl;

		}
		sort(result, result + 30, greater<int>());
		int descResult[100] = { 0, };
		int inx = 0;
		for (int i = 0; i < n; i++) {
			if (result[i] != result[i + 1]) {
				descResult[inx] = result[i];
				inx++;
			}
		}

		// for(int i = 0; i<n; i++){
		//   cout<<descResult[i]<<endl;
		// }
		cout <<"#"<<t<<" "<< descResult[k - 1] << endl;
		memset(descResult, 0, sizeof(descResult));
		memset(result, 0, sizeof(result));
		memset(ch, NULL, sizeof(ch));

	}

	return 0;
}

/*
1
12 10
1B3B3B81F75E

2
12 10
1B3B3B81F75E
16 2
F53586D76286B2D8
*/

/*
int main(){
char ch[100] = "FF";

	//10진수로 변환
	int nDec = (int)strtol(ch, NULL, 16); 

	//10진수 출력
	cout << nDec << endl;

	//대문자 출력
	//cout.setf(ios::uppercase);

	//16진수 출력
	cout << hex << nDec <<endl;
}
*/
