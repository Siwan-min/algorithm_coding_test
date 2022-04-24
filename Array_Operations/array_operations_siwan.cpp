/*
문제 파악: 
3 x 3 배열이 있다.
1초가 지날때마다 배열에 연산 적용.
R 연산: 배열 A의 모든 행에 대해서 정렬을 수행한다. (행의 개수 >= 열의 개수)
C 연산: 배열 A의 모든 열에 대해서 정렬을 수행한다. (행의 개수 < 열의 개수)
 - 각각의 수가 몇 번 나왔는지
 - 수의 등장 횟수가 커지는 순으로
 - 수가 커지는 순으로 
 - 정렬 결과 다시 입력 (수, 등장 횟수 넣은다)
초기 : [3, 1 ,1]
3: 1번 
1: 2번  >> [3, 1, 1, 2]
[3, 1, 1, 2]
3: 1번
1: 2번
1: 1번 >> [2, 1, 3, 1, 1, 2]

가장 큰 행(열)을 기준으로 모든 행의 크기가 변한다. 
행 또는 열의 크키가 100을 넘어가는 경우 : 처음 100개를 제외한 나머지는 버린다.


*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int r, c, k;
int pre_R, pre_C;
int cur_R, cur_C;
int map[103][103];

void Row_update(int sy){
    int num[101] = {0, };
    for(int x = 1; x <= pre_C; x++){
        num[map[sy][x]]++;
    }
    int size = 0;
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j<= 100; j++){
            if(num[j] == i){
            map[sy][++size] = j;
            map[sy][++size] = i;
            }
            if(size == 100) break;
        }
        if(size == 100) break;
    }
    for(int i = size + 1; i <= pre_C; i++){
        map[sy][i] = 0;
    }
    if(cur_C < size){
        cur_C = size;
    }
}

void Col_update(int sx){
    int num[101] = {0, };
    for(int y = 1; y <= pre_R; y++){
        num[map[y][sx]]++;
    }
    int size = 0;
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j<= 100; j++){
            if(num[j] == i){
                map[++size][sx] = j;
                map[++size][sx] = i;
            }
            if(size == 100) break;
        }
        if(size == 100) break;
    }
    for(int i = size + 1; i <= pre_R; i++){
        map[i][sx] = 0;
    }
    if(cur_R < size){
        cur_R = size;
    }
}

int main(){
    cin>>r>>c>>k;
    for(int i = 1 ; i <= 3; i++){
        for(int j = 1; j<= 3; j++){
            cin>>map[i][j];
        }
    }
    int t = 0;
    pre_R = 3, pre_C = 3;
    cur_R = 3, cur_C = 3;
    if(map[r][c] == k){
        cout<<"0"<<endl;
        return 0;
    }
    while(t < 100){
        t++;
        if(cur_R >= cur_C){
            pre_C = cur_C;
            cur_C = 0;
            for(int y = 1; y <= cur_R; y++) Row_update(y);
        }
        else{
            pre_R = cur_R;
            cur_R = 0;
            for(int x=1; x <= cur_C; x++) Col_update(x);
        }

        if(map[r][c] == k){
            cout<<t<<endl;
            return 0;
        }  
    }

    if( t >= 100 ){
     cout<<"-1"<<endl;   
    }

    return 0;
}