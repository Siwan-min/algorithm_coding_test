/*
문제 파악
- 맵의 크기와 맵이 입력으로 주어진다. 맵은 정수형 숫자로 이루어져 있다.
- 도형 5개가 주어진다. 도형은 회전, 대칭이 가능하다
- 테트로미노 하나를 적절히 놓아서 테트로미노가 놓은 보드의 값의 최대를 출력하는 문제
---------------------------------------------------------------------------------
문제 해결 방안:
- 블록을 회전 또는 대칭 할 수 있는 모든 경우를 미리 만들어 놓는다.
- 500 x 500 보드판에 그대로 놓고 한 칸씩 올겨 가면서 비교.


*/

#include <iostream>
using namespace std;
int n, m;
int map[503][503];
//왼쪽 위에 도형을 붙여 넣음 : 기준점을 생성
const char block[19][4][5] = {
    {
        "1111",
        "0000",
        "0000",
        "0000",
    },
    {
        "1000",
        "1000",
        "1000",
        "1000",
    },
    {
        "1100",
        "1100",
        "0000",
        "0000",
    },
    {
        "1110",
        "1000",
        "0000",
        "0000",
    },
    {
        "1100",
        "0100",
        "0100",
        "0000",
    },
    {
        "1000",
        "1000",
        "1100",
        "0000",
    },
    {
        "0010",
        "1110",
        "0000",
        "0000",
    },
     {
        "0100",
        "0100",
        "1100",
        "0000",
    },
     {
        "1000",
        "1110",
        "0000",
        "0000",
    },
     {
        "1100",
        "1000",
        "1000",
        "0000",
    },
     {
        "1110",
        "0010",
        "0000",
        "0000",
    },
     {
        "1000",
        "1100",
        "0100",
        "0000",
    },
    {
        "0110",
        "1100",
        "0000",
        "0000",
    },
    {
        "0100",
        "1100",
        "1000",
        "0000",
    },
    {
        "1100",
        "0110",
        "0000",
        "0000",
    },
    {
        "1110",
        "0100",
        "0000",
        "0000",
    },
    {
        "0100",
        "1100",
        "0100",
        "0000",
    },
    {
        "0100",
        "1110",
        "0000",
        "0000",
    },
    {
        "1000",
        "1100",
        "1000",
        "0000",
    },
};
int get_count(int sy, int sx, int k){
    int ret = 0;
    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 4; x++){
            ret += (block[k][y][x] - '0') * map[sy + y][sx + x];
        }
    }
    return ret;
}
int main(){
    cin>>n>>m;
    //맵 정보를 받는다.
    for(int y = 0; y < n; y++){
        for(int x = 0; x <m; x++){
            cin>>map[y][x];
        }
    }
    //입력 받은 맵에서 아래로 세 칸 매우 작은 값을 추가해 준다.
    for(int y = n; y <n + 3; y++){ 
        for (int x = 0; x < m + 3; x++){
            map[y][x] = -100000;
        }
    }
    //입력 받은 맵에서 오른쪽으로 세 칸 매우 작은 값을 추가해 준다. 
    for(int y = 0; y < n + 3; y++){
        for (int x= m; x < m + 3; x++){
            map[y][x] = -100000;
        }
    }
    int ret = 0;
    for (int y = 0; y < n; y++){
        for (int x = 0; x < m; x++){
            for (int k = 0; k < 19; k++){ //도형 19개 
                int candi = get_count(y, x, k); //시작점에 y, x 좌표를 넣어주고 어떤 블록을 체크 할 건지 넣어줌
                //블록이 그 위치에 있을 때 얻을 수 있는 candi 값을 넣어줌
                if (ret < candi){
                    ret = candi;
                }
            }
        }
    }


    cout<<ret<<endl;
    return 0;
}