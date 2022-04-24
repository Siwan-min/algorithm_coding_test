/*
 정답 코드를 기반으로 수정함
 dddbbb
 m/ 75224
 t/ 1318
 l/ 1383
*/
#include <cstring>
#include <iostream>
using namespace std;
 
int N;
int ans;
int num;
int atom[1000][4];
int dir[4][2] = { {0,1}, {0,-1}, {-1,0}, {1,0} };
int map[4001][4001];
 
void sol() {

    //1회, 2회 진행
    while (1) {
 
        //step1. 모든 원자를 한 칸씩 이동시킨다
        for (int i = 0; i < N; ++i) {

           if (!atom[i][3])
                continue;

            int x = atom[i][0];
            int y = atom[i][1];
            int d = atom[i][2];

            --map[x][y];

            x += dir[d][0], y += dir[d][1];

            if (x <= -1 || x >= 4001 || y <= -1 || y >= 4001) {
                atom[i][3] = 0;
                --num;
                continue;
            }

            atom[i][0] = x, atom[i][1] = y;
            ++map[x][y];

        }

        //step2. 모든 원자가 부딪혔는지 검사한다
        for (int i = 0; i < N; ++i) {
            
            if (!atom[i][3]) 
                continue;

            int x = atom[i][0];
            int y = atom[i][1];
            int e = atom[i][3];
 
            if (map[x][y] >= 2) {

                for (int j = i; j < N; ++j) {
                    if (!atom[j][3]) 
                        continue;

                    if (atom[j][0] == x && atom[j][1] == y) {
                        --num;
                        --map[x][y];
                        ans += atom[j][3];
                        atom[j][3] = 0;
                    }

                }
                
            }

        }

        if (num <= 1) return;
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
 
    int T;
    cin >> T;
    int x, y, d, e;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        num = N;
        for (int i = 0; i < N; ++i) {
            cin >> x >> y >> atom[i][2] >> atom[i][3];
            atom[i][0] = (x + 1000) * 2;
            atom[i][1] = (y + 1000) * 2;
            map[atom[i][0]][atom[i][1]] = 1;
        }
        sol();
        cout << "#" << t << " " << ans << '\n';
        ans = 0;
        memset(map, 0, sizeof(map));
    }
    return 0;
}
