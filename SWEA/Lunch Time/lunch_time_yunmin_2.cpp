#include <stdio.h>
#include <algorithm>

using namespace std;

/**
[���� ����]
1. �ð����� : �ִ� 50�� �׽�Ʈ ���̽��� ��� ����ϴµ�, C/C++/Java ��� 3��
2. ���� �� ���� ���� N�� 4 �̻� 10 ������ �����̴�. (4 �� N �� 10)
3. ����� ���� 1 �̻� 10 ������ �����̴�. (1 �� ����� �� �� 10)
4. ����� �Ա��� �ݵ�� 2���̸�, ���� ��ġ�� ��ġ�� �ʴ´�.
5. ����� ���̴� 2 �̻� 10 ������ �����̴�. (2 �� ����� ���� �� 10)
6. �ʱ⿡ �Է����� �־����� ����� ��ġ�� ��� �Ա��� ��ġ�� ���� ��ġ�� �ʴ´�.
**/

const int N = 10;
const int MAX_DIST = 2*N;
const int MAX_TIME = MAX_DIST + N*N; //�ִ��̵��Ÿ� + ������� ���� ����� �̿��� ��, ��ܱ���*�����

struct Coord {
    int y, x;
    Coord() {}
    Coord(int y, int x) : y(y), x(x) {}     
} P[N], S[2];
int p_size, s_size;
int answer;
int map[N][N];

//visit[x]=y: Px�� Sy�� �湮
int visit[N];

//��� P�� ��� S ������ �Ÿ��� ���ϴ� �Լ�
int get_dist(int p_idx, int s_idx) {
    int dy = abs(P[p_idx].y - S[s_idx].y);
    int dx = abs(P[p_idx].x - S[s_idx].x);
    return dy + dx;
}

//s_idx��° ����� �湮�ϴ� ��� P�� ����
//��� P�� ����� �������� �ð��� ����Ͽ� ��ȯ��
int get_time(int s_idx) {
    int result_time = 0;
    
    //arrival[d]: d��ŭ �̵����� �� �����ϴ� ����� ��
    int arrival[MAX_DIST] = { 0, };

    //cur_s[t]: �ð� t�� �� ����� �������� ����� �� 
    int cur_s[MAX_TIME] = { 0, };

    for (int p_idx = 0; p_idx < p_size; p_idx++) {
        if (visit[p_idx] == s_idx) {
            //1�� �ĺ��� ����� �������Ƿ� +1, ����� ������ ���� ++
            arrival[get_dist(p_idx, s_idx)+1]++;
        }
    }

    //���� ������ ����� ���ؼ�
    //����� ������ ��������
    for (int dist = 1; dist < MAX_DIST; dist++) {        
        while (arrival[dist] > 0) {

            int s_len = map[S[s_idx].y][S[s_idx].x]; //��� ����
            //������ �ð�(=�Ÿ�)���� �����ؼ� ��� �ο��� ������� Ȯ���ϰ� �̵��ð��� ������
            for (int time = dist; time < MAX_TIME; time++) {
                if (cur_s[time] < 3) {
                    cur_s[time]++;
                    s_len--;
                    
                    if (s_len == 0) { //��� ���̸�ŭ ������
                        result_time = max(result_time, time+1);
                        break;
                    }
                }    
            }

            //���� �Ÿ��� ������� �̵��� ���� ó����
            arrival[dist]--;
        }
    }
    return result_time;
}

//������ ��� P�� ��� ��� S�� �湮���� �����ϰ�
//�� ��ܿ� �ʿ��� �̵��ð��� ����ϰ� ������ �����ϴ� �Լ�
//�湮 ����� visit[] �� �����
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
                
                //���(==1)�̸�, P�� ��ǥ ����
                if (map[i][j] == 1) P[p_size++] = Coord(i, j);
                //���(>1)�̸�, S�� ��ǥ ����
                if (map[i][j] > 1) S[s_size++] = Coord(i, j);

            }
        }
        
        visit_PS(0);
        printf("#%d %d\n", tc, answer);
    }
}