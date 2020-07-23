#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

const int MAXN = 11;
const int MAXT = MAXN * 2 + MAXN*MAXN;

//위치를 나타내는 구조체
struct PT {
    int r, c;
    PT() {}
    PT(int r, int c) : r(r), c(c) {}     
} man[MAXN], stair[2];

//N: 방 한 변의 길이, M: 사람의 수,  S(=2): 계단의 수
int N, M, S;

//map: 입력으로 주어지는 방의 정보
int map[MAXN][MAXN];

//match[x]=y: x번째 사람이 y번째 계단을 타도록 결정된 상태
int match[MAXN];

int answer;

//man_index 인 사람과 stair_index 인 계단 사이의 거리
int dist(int man_index, int stair_index) {
    int dx = abs(man[man_index].r - stair[stair_index].r);
    int dy = abs(man[man_index].c - stair[stair_index].c);
    return dx + dy;
}

//각 사람이 어느 계단을 이용할 지 모두 정해졌을 때(=재귀 완료된 시점에)
//필요한 시간을 계산하는 함수
void update() {
    //모든 사람들이 계단을 내려가는데 필요한 최소 시간
    int total_min_time = 0;

    //두 계단은 서로 독립적이므로 각각에 대해서 계산한다.
    for (int stair_index = 0; stair_index < 2; stair_index++) {
        //참조 변수 now_stair 인데 PT 타입임.
        PT &now_stair = stair[stair_index];

        //arrival_time[t]: 시간 t일 때 계단에 도착하는 사람의 수
        int arrival_time[MAXN * 2] = { 0, };

        //모든 사람의 arrival_time을 계산함
        for (int man_index = 0; man_index < M; man_index++) {
            if (match[man_index] == stair_index) {
                //1분 후부터 계단을 내려가므로 +1, 사람수 증가를 위해 ++
                arrival_time[dist(man_index, stair_index)+1]++;
            }
        }

        //독립적인 각각의 계단을 내려가는 사람이 모두 작업을 마치기 위해 필요한 최소 시간
        int now_min_time = 0;

        //current_stair[t]: 시간 t일 때 계단을 내려가고 있는 사람의 수
        int current_stair[MAXT] = { 0, };

        //계단에 도착하는 시간 오름차순으로 각 사람이 계단을 내려가도록 시뮬레이션
        for (int time = 1; time <= 20; time++) {

            //time에 도착한 사람이 있다면
            while (arrival_time[time] > 0) {
                arrival_time[time]--;

                //해당 계단을 내려가는 데 필요한 시간
                int remain_time = map[now_stair.r][now_stair.c];

                //계단에 도착한 시점부터 사람 3명이
                //동시에 내려가고 있지 않을 때에 1칸씩 밑으로 내려 보낸다.
                for (int walk_time = time; walk_time < MAXT; walk_time++) {
                    if (current_stair[walk_time] < 3) {
                        
                        current_stair[walk_time]++;
                        remain_time--;

                        //계단을 다 내려갔으면 now_min_time 갱신
                        if (remain_time == 0) {
                            //종료 시간 계산 후 이동끝나는 최소시간 갱신
                            now_min_time = max(now_min_time, walk_time+1);
                            break;
                        }
                    }
                }
            }
        }

        //"전체 계단을 내려가는 데 필요한 최소 시간"
        // = (두 계단을 내려가는데 필요한 최소 시간) 중 최댓값
        total_min_time = max(total_min_time, now_min_time);
    }

    //현재 match 상태일 때 total_min_time 을 정답으로 갱신
    answer = min(answer, total_min_time);
}

void dfs(int man_index) {
    //모든 사람에 대해 각 사람이 사용할 계단을 다 정했다면
    if (man_index == M) {
        //해당 상태에서 필요한 시간을 계산하고 정답 갱신
        update();
        return;
    }

    //man_index번째 사람이 stair_index 번째 계단을 선택하고, 
    for (int stair_index = 0; stair_index < 2; stair_index++) {
        match[man_index] = stair_index;
        dfs(man_index + 1);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        
        scanf("%d", &N);
        M = S = 0;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                scanf("%d", &map[i][j]);

                //방의 (i, j)가 사람이면, 해당 위치를 man에 삽입
                if (map[i][j] == 1) man[M++] = PT(i, j);

                //방의 (i, j)가 계단이면, 해당 위치를 stair에 삽입
                if (map[i][j] >= 2) stair[S++] = PT(i, j);
            }
        }

        //답을 무한대로 초기화
        answer = 1e9;

        //깊이 우선 탐색 시작
        dfs(0);
        printf("#%d %d\n", tc, answer);
    }
}