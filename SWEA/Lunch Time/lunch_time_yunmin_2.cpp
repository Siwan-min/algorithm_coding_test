#include <stdio.h>
#include <algorithm>

using namespace std;

/**
[제약 사항]
1. 시간제한 : 최대 50개 테스트 케이스를 모두 통과하는데, C/C++/Java 모두 3초
2. 방의 한 변의 길이 N은 4 이상 10 이하의 정수이다. (4 ≤ N ≤ 10)
3. 사람의 수는 1 이상 10 이하의 정수이다. (1 ≤ 사람의 수 ≤ 10)
4. 계단의 입구는 반드시 2개이며, 서로 위치가 겹치지 않는다.
5. 계단의 길이는 2 이상 10 이하의 정수이다. (2 ≤ 계단의 길이 ≤ 10)
6. 초기에 입력으로 주어지는 사람의 위치와 계단 입구의 위치는 서로 겹치지 않는다.
**/

const int N = 10;
const int MAX_DIST = 2*N;
const int MAX_TIME = MAX_DIST + N*N; //최대이동거리 + 모든사람이 같은 계단을 이용할 때, 계단길이*사람수

struct Coord {
    int y, x;
    Coord() {}
    Coord(int y, int x) : y(y), x(x) {}     
} P[N], S[2];
int p_size, s_size;
int answer;
int map[N][N];

//visit[x]=y: Px가 Sy로 방문
int visit[N];

//사람 P와 계단 S 사이의 거리를 구하는 함수
int get_dist(int p_idx, int s_idx) {
    int dy = abs(P[p_idx].y - S[s_idx].y);
    int dx = abs(P[p_idx].x - S[s_idx].x);
    return dy + dx;
}

//s_idx번째 계단을 방문하는 모든 P에 대해
//모든 P가 계단을 내려오는 시간을 계산하여 반환함
int get_time(int s_idx) {
    int result_time = 0;
    
    //arrival[d]: d만큼 이동했을 때 도착하는 사람의 수
    int arrival[MAX_DIST] = { 0, };

    //cur_s[t]: 시간 t일 때 계단을 내려가는 사람의 수 
    int cur_s[MAX_TIME] = { 0, };

    for (int p_idx = 0; p_idx < p_size; p_idx++) {
        if (visit[p_idx] == s_idx) {
            //1분 후부터 계단을 내려가므로 +1, 사람수 증가를 위해 ++
            arrival[get_dist(p_idx, s_idx)+1]++;
        }
    }

    //먼저 도착한 사람에 대해서
    //계단을 실제로 내려보냄
    for (int dist = 1; dist < MAX_DIST; dist++) {        
        while (arrival[dist] > 0) {

            int s_len = map[S[s_idx].y][S[s_idx].x]; //계단 길이
            //도착한 시간(=거리)부터 시작해서 계단 인원이 충분한지 확인하고 이동시간을 증가함
            for (int time = dist; time < MAX_TIME; time++) {
                if (cur_s[time] < 3) {
                    cur_s[time]++;
                    s_len--;
                    
                    if (s_len == 0) { //계단 길이만큼 내려옴
                        result_time = max(result_time, time+1);
                        break;
                    }
                }    
            }

            //같은 거리의 사람들의 이동을 전부 처리함
            arrival[dist]--;
        }
    }
    return result_time;
}

//각각의 사람 P가 어느 계단 S를 방문할지 결정하고
//각 계단에 필요한 이동시간을 계산하고 정답을 갱신하는 함수
//방문 결과는 visit[] 에 저장됨
void visit_PS(int p_idx) {

    if (p_idx == p_size) {
        int s1_time = get_time(0);
        int s2_time = get_time(1);
        int total_time = (s1_time >= s2_time)? s1_time : s2_time;
        answer = min(answer, total_time);
        return;
    }
    
    visit[p_idx] = 0;
    visit_PS(p_idx+1);
    visit[p_idx] = 1;
    visit_PS(p_idx+1);
}

int main() {
    int test_case;
    scanf("%d", &test_case);    
    for (int tc = 1; tc <= test_case; tc++) {

        answer = 1e9;
        p_size = s_size = 0;

        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                scanf("%d", &map[i][j]);
                
                //사람(==1)이면, P에 좌표 저장
                if (map[i][j] == 1) P[p_size++] = Coord(i, j);
                //계단(>1)이면, S에 좌표 저장
                if (map[i][j] > 1) S[s_size++] = Coord(i, j);

            }
        }
        
        visit_PS(0);
        printf("#%d %d\n", tc, answer);
    }
}