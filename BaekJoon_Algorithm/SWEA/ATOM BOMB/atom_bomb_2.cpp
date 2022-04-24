/*
 모범 답안

 1) 1초마다 원자들을 각자 고유의 방향대로 이동한다.
 2) 이동한 지점에 위치하고 있는 원자들의 개수를 저장한다.
 3) 해당 위치에 원자들의 개수가 2개 이상이면
    충돌을 하는 것이므로 원자를 제거하고, 에너지를 저장한다.
 4) 충돌 가능한 원자가 하나도 남아있지 않다면
    해당 테스트 케이스를 종료한다.
*/

#include <stdio.h>
using namespace std;

int atom[1000][4]; // 원자 정보(0:x, 1:y, 2:방향, 3:에너지)
int visit[4005][4005];
bool collision[4005][4005];
int nRest;

// 마지막 값을 삭제하는 원자의 자리로 옮긴다.
//충돌한 원자는 어차피 더이상 사용하지 않으므로 그냥 무시한다.
void RemoveAtom(int n, int* pnSize) 
{
    int nLastIndex = nRest - 1;
    // int nLastIndex = (*pnSize) - 1;
    atom[n][0] = atom[nLastIndex][0];
    atom[n][1] = atom[nLastIndex][1];
    atom[n][2] = atom[nLastIndex][2];
    atom[n][3] = atom[nLastIndex][3];
    //(*pnSize)--; // 원자 수를 1개 줄임
    nRest--;
}

int solution(int N)
{
    nRest = N;
    int ans = 0;

    // 시간속을 2 배로 늘리기 위해 좌표계도 2 배로 늘림
    for (int j = 0; j < nRest; ++j)
    {
        atom[j][0] = atom[j][0] * 2;
        atom[j][1] = atom[j][1] * 2;
        visit[atom[j][0]][atom[j][1]]++;
    }

    //nMaxLoop: -1000 부터 1000 까지 2000 개의 숫자범위를 두 배로 늘리고 0을 포함 한 사이즈
    int nMaxLoop = 4001; // 최악의 경우는 0 에서 4000 까지 원자가 움직이는 경우이다.
    for (int i = 0; i < nMaxLoop; ++i)
    {
        // 원자 이동
        for (int j = 0; j < nRest; ++j)
        {
            int & x = atom[j][0]; //reference 변수로 저장
            int & y = atom[j][1];
            int d = atom[j][2];
            visit[x][y]--;
            if (d == 0) y++; // up
            else if (d == 1) y--; // down
            else if (d == 2) x--; // left
            else if (d == 3) x++; // right

            if (atom[j][0] < 0 || atom[j][0] > 4000 ||
            atom[j][1] < 0 || atom[j][1] > 4000) { // 원자가 판을 벗어나는 경우
                RemoveAtom(j, &nRest); // 벗어나는 원자 제거
                j--; // 마지막 원자를 덮어씌우기에 다시 한 번 for 루프를 돌아야한다
            }
            else {
                visit[x][y]++;
                if (visit[x][y] >= 2) collision[x][y] = true;
            }
        }
        // 원자 충돌 체크
        for (int j = 0; j < nRest; ++j)
        {
            int x = atom[j][0]; int y = atom[j][1];
            if (collision[x][y] == true) {
                if (visit[x][y] == 1) collision[x][y] = false;
                visit[x][y]--;
                ans += atom[j][3];
                //충돌되었으므로 해당 원자 삭제
                RemoveAtom(j, &nRest);
                j--;
            }
        }

        if (nRest == 0) break; //남은 원자가 없으면 종료
    }
    return ans;
}

int main() 
{
    int T, test_case, N;
    
    scanf("%d\n", &T);

    for (test_case = 1; test_case <= T; test_case++)
    {
        N = 0;
        scanf("%d\n", &N);
        for (int i = 0; i < N; ++i)
        {
            scanf("%d %d %d %d", &atom[i][0], &atom[i][1],
                &atom[i][2], &atom[i][3]);
            atom[i][0] += 1000;
            // 좌표를 음이 아닌 정수로 만들어주기 위해 1000 을 더해준다
            atom[i][1] += 1000;
        }

        int nRes = solution(N);
        printf("#%d %d\n", test_case, nRes);
    }
}