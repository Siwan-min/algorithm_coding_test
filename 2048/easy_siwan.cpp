/*
최대 20 by 20 의 2차원 공간에 상, 하, 좌, 우로 보드를 이동할 수 있고,
규칙에 따라 숫자가 이동, 또는 합산을 하게 됩니다.
최초 입력되는 보드에서 최대 5번만 이동하여 보드에서 가장 큰 값을 출력하는 문제.

2 4 5 2             4 8 8 2
2 4 0 0    >>       4 0 2 0
2 0 0 0    up       0 0 0 0
2 0 2 0             0 0 0 0
-----------------------------------------------------------------------------------
문제 해결 방안:
1회 움직임에서 선택할 수 있는 경우는 상, 하, 좌, 우 4가지 방법이 있다.
최대 5번만의 움직임만 생각하면 되기 때문에 >> 완전 탐색 시뮬레이션
 -> 4^5 = 1024 (움직임의 경우의 수)
 -> 1024 * 20 * 20 = 409600 (움직임의 발생 횟수 * 보드의 크기)

 각 방향으로 이동시 보드의 숫자 변화 처리 방법:
 (1) 한가지 방향만 구현
 (2) 보드를 90도 돌리는 함수를 구현하여 네 방향 탐색 
*/

#include <iostream>
using namespace std;
int n, ret; // 사이즈 n 

struct BOARD {
    int map[20][20];

    void rotate(){ // 회전 함수 
        int temp[20][20];

        for(int y = 0; y < n; ++y){
            for(int x = 0; x < n; ++x){
                temp[y][x] = map[n - x - 1][y]; //x, y 를 바꿔줌
            }
        }

        for(int y = 0; y < n; ++y){
            for(int x = 0; x  < n; ++x){
                map[y][x] = temp[y][x];
            }
        }
    }

    int get_max(){
        int ret = 0;
        for (int y = 0; y < n; ++y){
            for(int x= 0 ; x < n; ++x){
                if(ret < map[y][x]){
                    ret = map[y][x];
                }
            }
        }
        return ret;
    }

    void up() {
        int temp[20][20];
        for (int x = 0; x < n; ++x){ //가로방향을 다 돌면서 
            int flag = 0, target = -1;
            for (int y = 0; y < n; ++y){ //세로 방햐을 다 돌아줌
                if(map[y][x] == 0) continue; // 값이 없으면 무시 

                if(flag == 1 && map[y][x] == temp[target][x]){ //한 번값이 옮겨 졌었고 , 내가 지금 옮기는 값과
                    temp[target][x] *= 2, flag = 0;  //타겟팅 된 값이 같으면 업데이트
                }
                else{
                    temp[++target][x] = map[y][x], flag = 1;
                }
            }
            for(++target; target < n; ++target){
                temp[target][x] = 0;
            }
        }
        for(int y = 0; y < n; ++y){
            for(int x = 0; x  < n; ++x){
                map[y][x] = temp[y][x];
            }
        }
    }
};

void dfs(BOARD cur, int count){
    if(count == 5) {
        int candi = cur.get_max();
        if( ret < candi){
            ret = candi;
        }
        return ;
    }

    for (int dir = 0; dir < 4; ++dir){
        BOARD next = cur;
        next.up();
        dfs(next, count + 1);
        cur.rotate();
    }
}
int main(){
    BOARD board;
    cin>>n;
    for(int y = 0; y < n; ++y){
        for (int x = 0; x < n; ++x){
            cin>>board.map[y][x];
        }
    }
    ret = 0;

    dfs(board, 0);
    cout<<ret<<endl;
    return 0;
}