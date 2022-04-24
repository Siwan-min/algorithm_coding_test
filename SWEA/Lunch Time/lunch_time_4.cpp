//����ҽ� 4
//��������
// #s 2383 ���� �Ļ� �ð�
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 100000000
using namespace std;
 
int n;
typedef struct xy {
    int x,y;
};
typedef struct info {
    int x, y, value;
};
typedef struct info2 {
    int now_time, origin_time;
};
 
int visit[11];//����� ���� 1�̻� 10������ ����
vector <xy> people;
info stair[2];
int people_size;
int ans;
 
int distance(xy a, xy b) {// �Ÿ��� ���ϴ� �Լ�
    return abs(a.x - b.x) + abs(a.y - b.y);
}
 
int simul() {//����� ���� �̵��ϴ� �ùķ��̼�
    //visit�� ���� � ������� ���� ������ ��Ȳ
    int in_stair[2][3];//�̵��ϴ� ����� �� ��Ȳ
    memset(in_stair, 0, sizeof(in_stair));
    priority_queue <int, vector<int>, greater<int> >pq[2];//��� ��Ȳ
 
    xy a, b;
    for (int i = 0; i < people_size; i++) {  
        int temp = visit[i];
        a = { people[i].x,people[i].y };
        b = { stair[temp].x,stair[temp].y};
        int x = distance(a, b);
        pq[temp].push(x+1);//- ��� �Ա��� �����ϸ�, 1�� �� �Ʒ�ĭ���� ���� �� �� �ִ�.
    }
    int ret = 0;
    for (int idx = 0; idx < 2; idx++) {
         
        //��� i�� �������� �ð�
        int TIME = 0;//�������� ���� �ð�
        int out_cnt = 0;
        int total_people = pq[idx].size();
        while (true) {
            //  - ����� �������� �ð��� ��� �Ա��� ������ �ĺ��� ����� ������ ������ �������� �ð��̴�.
             
            for (int i = 0; i < 3; i++) {
                if (in_stair[idx][i] != 0) {
                    in_stair[idx][i]--;
                    if (in_stair[idx][i] == 0)out_cnt++;
                }
 
            }
             
            //  - ��� ������ ���ÿ� �ִ� 3������� �ö� ���� �� �ִ�.
            for (int i = 0; i < 3; i++) {
                if (pq[idx].empty())break;
                int need_time = pq[idx].top();
                //  - �̹� ����� 3���� �������� �ִ� ���, �� �� �� ���� ����� ������ ������ ������ ��� �Ա����� ����ؾ� �Ѵ�.
                //-> no push
                if (in_stair[idx][i] == 0&&need_time<=TIME) {
                    pq[idx].pop();
                    //  - ��ܸ��� ���� K�� �־�����, ��ܿ� �ö� �� ������ �������µ� K ���� �ɸ���.
                    in_stair[idx][i] = stair[idx].value;
                }
            }
 
            if (total_people == out_cnt)break;
            TIME++;// ��� �ùķ��̼��� ������ �ð��� �帧 
        }
 
        ret = max(ret, TIME);
    }
    return ret;
     
}
 
void dfs(int num, int cnt) {
     
 
    //for (int i = 0; i < people_size; i++) {
    //  cout << visit[i] << " ";
    //}cout << endl;
    ans = min(ans, simul());
    if (cnt == people_size)return;
 
    for (int i = num; i < people_size; i++) {
        if (visit[i])continue;
        visit[i] = true;
        dfs(i, cnt + 1);
        visit[i] = false;
    }
}
 
void Input() {
    cin >> n;
    int idx = 0;
    int x;
    people.clear();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            if (x == 1)people.push_back({ i,j });
            else if (x > 1) {
                stair[idx++] = {i,j,x};
            }
        }
    }
    people_size = people.size();
    ans = INF;
}
 
int main() {
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++) {
        Input();
        dfs(0, 0);
        cout << "#" << t << " " << ans << endl;
    }
     
}