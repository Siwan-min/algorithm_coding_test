/*
문제: 백분 16235번 나무 재테크

문제 파악: 
N x N의 땅이 있다. 각 칸은 (r, c)로 표현
M개의 나무가 있다. 
봄: 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가.
1 x 1 크기의 칸에 있는 양분만 먹을 수 있다.
하나의 칸에 여러 개의 나무가 있을 수 있다. >> 나이가 어린 나무부터 양분을 먹는다.
양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 죽음
여름: 봄에 죽은 나무가 양분으로 변한다. 각 죽은 나무마다 나이를 2로 나눈 값이 
나무가 있던 칸에 양분으로 추가된다.  
가을: 나무 번식 >> 나이가 5배수 >> 주변 8칸
겨울: S2D2가 땅 양분 추가. A[r][c] 

결과: K년이 지난 후 살아있는 나무의 개수를 구하여라
----------------------------------------------------------------------

입력 :
 N, M, K
맵 정보 가중치 (N x N)
나무 정보 (x, y, 나이)

-----------------------------------------------------------------
문제 해결 방안:
(1) K 년 반복문
(2) for ( 0 ~ 4) 봄, 여름, 가을, 겨울
    -봄: 양분 먹음
    -여름: 양분 추가 (죽은거 / 2) 
    -가을: 8방향 나무 번식 ( 나이 5배수 되면)
    -겨울: 땅 양분 추가 A[r][c]


*/

#include <stdio.h>
#include <algorithm>

using namespace std;

struct TREE {
    int y, x, age;
};

bool cmp(TREE& a, TREE& b){
    return (a.age < b.age);
}

struct QUEUE {
    int f, b;
    TREE tree[684000];

    QUEUE() {
        init();
    }

    void init(){
        f = 0, b = 0;
    }

    bool isempty(){
        return (f == b);
    }

    void push(TREE val){
        tree[b++] = val;
    }
    void pop() {
        f++;
    }

    TREE front() {
        return tree[f];
    }

    int size(){
        return (b - f);
    }
};

int n, m, k;
QUEUE tree[2];
QUEUE new_tree;
QUEUE dead_tree, birth_of_child_tree;
TREE init_tree[100];

int map[10][10];
int add[10][10];

int main(){

    scanf("%d %d %d", &n, &m, &k);

    for(int y = 0; y < n; y++){
        for(int x=0; x < n; x++){
            scanf("%d", &add[y][x]);
            map[y][x] = 5;
        }
    }

    for (int i = 0; i < m; i++){
        scanf("%d %d %d", &init_tree[i].y, &init_tree[i].x, &init_tree[i].age);
        init_tree[i].y--, init_tree[i].x--;
    }

    sort(init_tree, init_tree + m, cmp);

    int cur = 0, next = 0;
    for(int i = 0; i < m; i++){
        tree[cur].push(init_tree[i]);
    }
    
    
    for(int i = 0 ; i < k; i++){

        next = (cur + 1) % 2;
        dead_tree.init();
        birth_of_child_tree.init();
        tree[next].init();

        while(!new_tree.isempty()){
            TREE cur_tree = new_tree.front(); new_tree.pop();

            if(map[cur_tree.y][cur_tree.x] >= cur_tree.age){
                map[cur_tree.y][cur_tree.x] -= cur_tree.age;

                cur_tree.age++;
                tree[next].push(cur_tree);
            }
            else {
                dead_tree.push(cur_tree);
            }
        }

        while(!tree[cur].isempty()){
            TREE cur_tree = tree[cur].front(); tree[cur].pop();

            if(map[cur_tree.y][cur_tree.x] >= cur_tree.age){
                map[cur_tree.y][cur_tree.x] -= cur_tree.age;

                cur_tree.age++;
                tree[next].push(cur_tree);

                if((cur_tree.age % 5) == 0){
                    birth_of_child_tree.push(cur_tree);
                } 
            }
            else {
                dead_tree.push(cur_tree);
            }
        }

        while(!dead_tree.isempty()){
            TREE cur_tree = dead_tree.front(); dead_tree.pop();
            map[cur_tree.y][cur_tree.x] += (cur_tree.age / 2);
        }

        const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        new_tree.init();
        while(!birth_of_child_tree.isempty()){
            TREE cur_tree = birth_of_child_tree.front(); birth_of_child_tree.pop();
            for(int dir = 0; dir<8; dir++){
                TREE next_tree;
                next_tree.y = cur_tree.y + dy[dir];
                next_tree.x = cur_tree.x + dx[dir];
                next_tree.age = 1;
                if(next_tree.y < 0 || next_tree.y >= n || next_tree.x < 0 || next_tree.x >= n) continue;

                new_tree.push(next_tree);
            }
        }

        for(int y = 0; y < n; y++){
            for(int x = 0; x < n; x++){
                map[y][x] += add[y][x];
            }
        }

        cur = next;

    }

    printf("%d\n", tree[next].size() + new_tree.size());

    return 0;
}