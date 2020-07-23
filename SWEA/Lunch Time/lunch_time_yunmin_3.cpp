#include <stdio.h>
#include <algorithm>

using namespace std;

const int N = 10;
const int MAX_DIST = 2*N;
const int MAX_TIME = MAX_DIST + N*N;

struct Coord {
    int y, x;
    Coord() {}
    Coord(int y, int x) : y(y), x(x) {}     
} P[N], S[2];
int p_size, s_size;
int answer;
int map[N][N];
int visit[N];

int get_dist(int p_idx, int s_idx) {
    int dy = abs(P[p_idx].y - S[s_idx].y);
    int dx = abs(P[p_idx].x - S[s_idx].x);
    return dy + dx;
}

int get_time(int s_idx) {
    int result_time = 0;
    int arrival[MAX_DIST] = { 0, };
    int cur_s[MAX_TIME] = { 0, };

    for (int p_idx = 0; p_idx < p_size; p_idx++) {
        if (visit[p_idx] == s_idx) {
            arrival[get_dist(p_idx, s_idx)+1]++;
        }
    }

    for (int dist = 1; dist < MAX_DIST; dist++) {        
        while (arrival[dist] > 0) {
            int s_len = map[S[s_idx].y][S[s_idx].x];
            for (int time = dist; time < MAX_TIME; time++) {
                if (cur_s[time] < 3) {
                    cur_s[time]++;
                    s_len--;
                    
                    if (s_len == 0) {
                        result_time = max(result_time, time+1);
                        break;
                    }
                }    
            }
            arrival[dist]--;
        }
    }
    return result_time;
}

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
                
                if (map[i][j] == 1) P[p_size++] = Coord(i, j);
                if (map[i][j] > 1) S[s_size++] = Coord(i, j);
            }
        }
        
        visit_PS(0);
        printf("#%d %d\n", tc, answer);
    }
}