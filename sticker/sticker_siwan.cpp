#include <bits/stdc++.h>

using namespace std;

//스티커는 왼쪽 위를 우선으로 붙이며 모두 확인결과 못 붙이면 회전시켜 확인 한다.

int sticker[101][11][11];
int notebook[41][41];
pair<int,int> num[101];
int N,M,K;

bool attach(int n, int x, int y) { //x,y 에서 시작할때 붙일 수 있는지

    if(x+num[n].first > N || y+num[n].second > M) return false;

    for(int i = x; i < x+num[n].first; i++)
        for(int j = y; j < y+num[n].second; j++) {
            if(sticker[n][i-x][j-y] == 1 && notebook[i][j] == 1) {
                return false;
            }
        }

    for(int i = x; i < x+num[n].first; i++) {
        for(int j = y; j < y+num[n].second; j++) {
            if(notebook[i][j] == 0)
                notebook[i][j] = sticker[n][i-x][j-y];
        }
    }

    return true;
}


void rotatefunc(int n) { //n번째 스티커를 90도 회전

    int arr[11][11] = {0, };

    int r = num[n].first;
    int c = num[n].second;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++) {
            arr[j][r-i-1] = sticker[n][i][j];
        }

    for(int i = 0; i < 11; i++)
        for(int j = 0; j < 11; j++) {
            if(i<c&&j<r) sticker[n][i][j] = arr[i][j];
            else sticker[n][i][j] = 0;
        }

    num[n].first = c;
    num[n].second = r;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M >> K;

    for(int i = 0; i < K; i++) {
        int r,c; cin >> r >> c;
        num[i].first = r;
        num[i].second = c;
        for(int j = 0; j < r; j++)
            for(int k = 0; k < c; k++) {
                cin >> sticker[i][j][k];
            }
    }


    for(int i = 0; i < K; i++) { //스티커를 붙여봄
        bool flag = false;
        int cnt = 0;

        while(!flag && cnt < 4) {
            if(cnt != 0)
                rotatefunc(i);

            for(int j = 0; j < N; j++) {
                for(int k = 0; k < M; k++){
                    if(attach(i, j, k)) {
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }
            cnt++;
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(notebook[i][j] == 1) ans++;
        }
    }

    cout<<ans;
    return 0;
}