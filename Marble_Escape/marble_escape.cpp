#include <iostream>
#include <queue>
#include <algorithm>

struct INFO {
    int ry, rx, by, bx, count;
};

INFO start;
char map[10][11];

using namespace std;

int bfs(){
    const int dy[] = {-1, 1, 0, 0};
    const int dx[] = {0, 0, -1, 1};


    int visited[10][10][10][10] = {0, };
    queue<INFO> q;
    q.push(start);
    visited[start.ry][start.rx][start.by][start.bx] = 1;

    int ret = -1;

    while(!q.empty()){
        INFO cur = q.front(); q.pop();
        if(cur.count > 10) break;

        if(map[cur.ry][cur.rx] == '0' && map[cur.by][cur.bx] != '0') {
            ret = cur.count;
            break;
        }

        for(int dir = 0; dir < 4; dir++) {
            int next_ry=cur.ry;
            int next_rx=cur.rx;
            int next_by=cur.by;
            int next_bx=cur.bx;

            while(1) {
                if(map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O') {
                    next_ry += dy[dir], next_rx += dx[dir];
                }
                else{
                    if (map[next_ry][next_rx] == '#') {
                        next_ry -= dy[dir], next_rx -= dx[dir];
                    }
                    break;
                }
            }
            while(1) {
                if(map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O') {
                    next_by += dy[dir], next_bx += dx[dir];
                }
                else{
                    if (map[next_by][next_bx] == '#') {
                        next_by -= dy[dir], next_bx -= dx[dir];
                    }
                    break;
                }
            }

            if(next_ry == next_by && next_rx == next_bx) {
                if(map[next_ry][next_rx ] != 'O') {
                    int red_dist = abs(next_ry - cur.ry) + abs(next_rx - cur.rx);
                    int blue_dist = abs(next_by - cur.by) + abs(next_bx - cur.bx);

                    if (red_dist > blue_dist) {
                        next_ry -= dy[dir], next_bx -= dx[dir];
                    }
                    else {
                        next_by -= dy[dir], next_bx -= dx[dir];
                    }
                }
            }

            if(visited[next_ry][next_rx][next_by][next_bx] == 0) {
                visited[next_ry][next_rx][next_by][next_bx] = 1;
                INFO next;
                next.ry = next_ry;
                next.rx = next_rx;
                next.by = next_by;
                next.bx = next_bx;
                next.count = cur.count + 1;
                q.push(next);
            }
        }
    }    
    return ret;
}

int main(){

    int n, m;

    cin>>n>>m;

    for(int i = 0; i <n; i++){
        for(int j = 0; j<m; j++) {
            cin>>map[i][j];

            if(map[i][j] == 'R') {
                start.ry = i, start.rx = j;
            }

            if(map[i][j] == 'B') {
                start.by = i, start.bx = j;
            }
        }
    }

    start.count = 0;

    int ret = bfs();
    cout<<ret<<endl;
    
    return 0;
}


// #include <iostream>
// #include <queue>
// #include <cstring>
// #include <cstdlib>
// using namespace std;

// struct p {
//     int y;
//     int x;
//     int dir;
// };
// int n, m;

// char map[13][13];
// int cost[13][13];
// queue <p> Red;
// queue <p> Blue;
// int Rmove[4][1000];
// int Bmove[4][1000];

// int dy[4] = {-1, 1, 0, 0};
// int dx[4] = {0, 0, -1, 1};

// int Ry, Rx;
// int By, Bx;
// int endY, endX;
// int Rdist, Bdist;
// bool check1[13][13];
// bool check2[13][13];
// bool wall[13][13];

// int Rresult = 987987987;
// int Bresult = 987987987;

// int Ridx;
// int Bidx;

// void Red_result(){
//     //int dir = 0;
    
//     //int Rresult = 987987987;
//     for(int dir = 0; dir < 4; dir++){
//         Red.push({Ry, Rx, dir});
//         check1[Ry][Rx] = true;
//         cost[Ry][Rx] = 1;
//         int t = 0;
//         while (!Red.empty())
//         {
//             p front = Red.front();
//             Red.pop();
//             int curY = front.y;
//             int curX = front.x;
//             int curD = front.dir;

//             for(int i = 0; i<4; i++){
//                 int yy = curY + dy[i];
//                 int xx = curX + dx[i];

//                 if(yy >= 0 && yy < n && xx >=0 && xx < m && !check1[yy][xx] && !wall[yy][xx]){
//                     check1[yy][xx] = true;
//                     if(curD == i){
//                         cost[yy][xx] = cost[curY][curX];
//                     }
//                     else{
//                         cost[yy][xx] = cost[curY][curX] + 1;
//                     }
//                     t++;
//                     Rmove[dir][t] = cost[yy][xx];
//                     Red.push({yy, xx, i});
//                 }
//             }
//             if(check1[endY][endX]==true){
//                 if(cost[endY][endX] < Rresult)
//                     Rresult = cost[endY][endX];
//                     Ridx= dir;
//                     Rdist = t;
//             }
//         }
//     //  for(int i = 0; i<n; i++){
//     //     for(int j = 0 ; j<m; j++){
//     //         cout<<cost[i][j]<<" ";
//     //     }
//     //     cout<<endl;
//     //  }
//         memset(cost, 0, sizeof(cost));
//         memset(check1, 0, sizeof(check1));
//     }
//    // cout<<Rresult<<endl;
// }

// void Blue_result(){
//     //int Bresult = 987987987;
//     for(int dir = 0; dir < 4; dir++){
//         Blue.push({By, Bx, dir});
//         check2[By][Bx] = true;
//         cost[By][Bx] = 1;
//         int t = 0;
//         while (!Blue.empty())
//         {
//             p front = Blue.front();
//             Blue.pop();
//             int curY = front.y;
//             int curX = front.x;
//             int curD = front.dir;

//             for(int i = 0; i<4; i++){
//                 int yy = curY + dy[i];
//                 int xx = curX + dx[i];
//                 if(wall[yy][xx]) continue;
//                 if(!wall[yy][xx] && yy >= 0 && yy < n && xx >=0 && xx < m && !check2[yy][xx]){
//                     check2[yy][xx] = true;
//                     if(curD == i){
//                         cost[yy][xx] = cost[curY][curX];
//                     }
//                     else{
//                         cost[yy][xx] = cost[curY][curX] + 1;
//                     }
//                     t++;
//                     Bmove[dir][t] = cost[yy][xx];
//                     Blue.push({yy, xx, i});
//                 }
//             }
//             if(check2[endY][endX]==true){
//                 if(cost[endY][endX] < Bresult)
//                     Bresult = cost[endY][endX];
//                     Bidx= dir;
//                     Bdist = t;
//             }
//         }
//         // for(int i = 0; i < n; i++){
//         //     for(int j = 0 ; j<m; j++){
//         //         cout<<cost[i][j]<<" ";
//         //     }
//         //     cout<<endl;
//         // }cout<<endl;
//         memset(cost, 0, sizeof(cost));
//         memset(check2, 0, sizeof(check2));
//     }
//    //cout<<Bresult<<endl;
// }

// int main(){

//     cin>>n>>m;

//     for(int i = 0; i<n; i++){
//         for(int j = 0; j<m; j++){
//             cin>>map[i][j];
//             if(map[i][j] == 'R'){
//                 Ry = i; 
//                 Rx = j;
//             }
//             if(map[i][j] == 'B'){
//                 By = i;
//                 Bx = j;
//             }
//             if(map[i][j] == '#'){
//                 wall[i][j] = true;
//                 //check1[i][j] = true;
//             }
//             if(map[i][j] == 'O'){
//                 endY = i;
//                 endX = j;
//             }
//         }
//     }

//     Red_result();
//     Blue_result();
//     cout<<Rresult<<endl;
//     cout<<Bresult<<endl; 

//     cout<<Rmove[Ridx][Rdist]<<endl;
//     cout<<Bmove[Bidx][Bdist]<<endl;
//    // for(int i = 0; i<4; i++){
//         for(int j = 0 ; j<16; j++){
//             cout<<Rmove[Ridx][j]<<" ";
//             //cout<<wall[i][j]<<" ";
//         }
//         cout<<endl;
//         for(int j = 0 ; j<15; j++){
//             cout<<Bmove[Bidx][j]<<" ";
//             //cout<<wall[i][j]<<" ";
//         }
//         cout<<endl;
//     //}
    

//     return 0;
// }

// #include <iostream>

// using namespace std;

// struct INFO
// {
//     int rx, ry, bx, by, d, cnt;
// };

// char map[10][10];

// int dx[4] = {0, 0, 1, -1};
// int dy[4] = {1, -1, 0, 0};

// int main () {
//     int N, M;
//    // cout << (1<<11) << endl;
//     cin>>N>>M;
//     int rx, ry, bx, by;
//     for (int i = 0; i < N; i++){
//         for (int j = 0; j < M; j++){
//             cin>>map[i][j];
//             if (map[i][j] == 'R') {
//                 rx = i, ry = j, map[i][j] = '.';
//             }
//             else if(map[i][j] == 'B') {
//                 bx = i, by = j, map[i][j] = '.';
//             }
//         }
//     }
    
//     int idx = 0, now = 0;
//     INFO info[1 << 11];
//     info[idx++] = { rx, ry, bx, by, -1, 1};

//     while(now < idx) {
//         rx = info[now].rx;
//         ry = info[now].ry;
//         bx = info[now].bx;
//         by = info[now].by;
        
//         int d = info[now].d;
//         int cnt = info[now++].cnt;

//         if (cnt > 10) break;

//         for (int i = 0; i < 4; i++) {
//            // cout<<"t"<<endl;
//             if (d == i || d == (i ^ 1)) continue; // 같은 방향과 반대 방향은 Continue
//             int nrx = rx, nry = ry, nbx = bx, nby = by, rcnt = 0, bcnt = 0;
//             while(map[nrx][nry] == '.')
//                 nrx += dx[i], nry += dy[i], rcnt++;
//             while (map[nbx][nby] == '.')
//                 nbx += dx[i], nby += dy[i], bcnt++;
            

//             if(map[nbx][nby] == 'O') continue;
//             if(map[nrx][nry] == 'O') {
//                 cout << cnt;
//                 return 0;
//             }

//             nrx -= dx[i]; nry -= dy[i];
//             nby -= dx[i]; nby -= dy[i];

//             if (nrx == nbx && nry == nby) { // 같은 위치일 경우 더 많이 움직인 구슬을 옆으로 한 칸 옮긴다. 
//                 if(rcnt > bcnt)
//                     nrx -= dx[i], nry -= dy[i];
//                 else
//                     nbx -= dx[i], nby -= dy[i];
//             }
//             if(rx == nrx && ry == nry && bx == nbx && by == nby) continue; // ????
//             info[idx++] = { nrx, nry,nbx, nby, i, cnt+1};
//         }
//     }
//     cout<<"-1";
//     return 0;
// }
