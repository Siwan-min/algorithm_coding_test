#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct info{
    int y, x, d;
};

int n, k;
int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};

int _trunDir(int dir){
    if(dir == 1) return 2;
    if(dir == 2) return 1;
    if(dir == 3) return 4;
    if(dir == 4) return 3;
}

info horse[10];
int map[13][13]; 
vector <int> h[13][13]; // 말 위치

int moveHorse(int i){
    int yy = horse[i].y + dy[horse[i].d];
    int xx = horse[i].x + dx[horse[i].d];
    // 벽 or 파랑
    if( yy<=0 || yy > n || xx <=0 || xx > n || map[yy][xx] == 2){
        horse[i].d = _trunDir(horse[i].d);

        yy = horse[i].y + dy[horse[i].d];
        xx = horse[i].x + dx[horse[i].d];
        //반대 방향도 벽 or 파랑
        if(yy<=0 || yy > n || xx <=0 || xx > n || map[yy][xx] == 2){
            return 0;
        } 
    }
    vector<int> &cur = h[horse[i].y][horse[i].x];
    vector<int> &next = h[yy][xx];
    auto s = find(cur.begin(), cur.end(), i);
    //빨간 칸 뒤집기
    if(map[yy][xx] == 1){
        reverse(s, cur.end());
    }

    for(auto iter = s; iter != cur.end(); iter++){
        horse[*iter].y = yy;
        horse[*iter].x = xx;
        next.push_back(*iter);
    }

    cur.erase(s, cur.end());
    return next.size();
}

int search(){

    int ans, i, y, x, stack_cnt;

    for(int ans = 1; ans <= 1000; ans++){
        for(i = 0; i < k; ++i){
            stack_cnt = moveHorse(i);
            if(stack_cnt >=4) return ans;
        }
    }
    return -1;
}
int main(){

    cin>>n>>k;
    
    for(int i = 1; i <=n; i++){
        for(int j = 1; j<=n; j++){
            cin>>map[i][j];
        }
    }

    for(int i = 0; i < k; i++){
        info& ho = horse[i];
        cin >> ho.y >> ho.x >> ho.d;
        h[ho.y][ho.x].push_back(i);
    }

    cout<<search();
    return 0;
}