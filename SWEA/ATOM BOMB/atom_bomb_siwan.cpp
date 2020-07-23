#include <iostream>
#include <cstring>
#include <queue>
#define MAX 2005
using namespace std;
 
int T, n, total;
int result, Qs;
int Xmin = 2001, Xmax, Ymin = 2001, Ymax;
 
struct info {
  int count, idx;
};
 
struct p {
 
    int y;
    int x;
    int dir;
    int e;
 
};
 
info Atom[MAX][MAX];
 
const int dy[4] = { 1, -1, 0, 0 };
const int dx[4] = { 0, 0, -1, 1 };
 
p Atominfo[1001];
 
queue <int> _sum;
 
int getResult() {
 
    total = n;
 
    while (total) {
 
  for(int i = 0; i<n; i++){
     
        int curY = Atominfo[i].y;
        int curX = Atominfo[i].x;
        int curD = Atominfo[i].dir;
        int curE = Atominfo[i].e;
         
      if(curE == 0) continue;
         
        int ny = curY + dy[curD];
        int nx = curX + dx[curD];
 
 
        if (ny > Ymax || ny < Ymin || nx > Xmax || nx < Xmin) { 
          total--;
          Atom[curY][curX].count = 0;
          Atominfo[i].e = 0;
          continue; 
        } // 범위 밖으로 벗어나면 패스 
 
            //0.5초 충돌
            if(Atom[ny][nx].count && Atom[ny][nx].idx > i){
            if ((curD == 0 && Atominfo[Atom[ny][nx].idx].dir == 1) ||
                (curD == 1 && Atominfo[Atom[ny][nx].idx].dir == 0) ||
                (curD == 2 && Atominfo[Atom[ny][nx].idx].dir == 3) ||
                (curD == 3 && Atominfo[Atom[ny][nx].idx].dir == 2) && Atominfo[Atom[ny][nx].idx].e != 0) {
                 
              result =result + curE + Atominfo[Atom[ny][nx].idx].e;
          total -= 2;
          Atom[Atominfo[i].y][Atominfo[i].x].count--;
          Atom[ny][nx].count--;
                Atominfo[Atom[ny][nx].idx].e = 0;
                Atominfo[i].e = 0;
                continue;
            }
      }
          Atom[curY][curX].count--;
          Atominfo[i].y = ny;
          Atominfo[i].x = nx;
          Atom[ny][nx].count++;
          Atom[ny][nx].idx = i;
    }
     
    for(int i = 0; i < n; i++){
      if(Atominfo[i].e == 0) continue;
      if(Atom[Atominfo[i].y][Atominfo[i].x].count > 1)
      _sum.push(i);
    }
     
    while(!_sum.empty()){
          result += Atominfo[_sum.front()].e;
          Atom[Atominfo[_sum.front()].y][Atominfo[_sum.front()].x].count = 0;
          Atominfo[_sum.front()].e = 0;
          total--;
          _sum.pop();
        }
    }
//  cout<<total<<" ";
    return result;
}
 
int main() {
 
    cin >> T;
 
    for (int tc = 1; tc <= T; tc++) {
        cin >> n;
 
        for (int i = 0; i < n; i++) {
            int x, y, d, k;
            cin >> x >> y >> d >> k;
             
            int xpoint = x + 1000;
            int ypoint = y + 1000;
            if (xpoint < Xmin) Xmin = xpoint;
            if (xpoint > Xmax) Xmax = xpoint;
            if (ypoint < Ymin) Ymin = ypoint;
            if (ypoint > Ymax) Ymax = ypoint;
 
            Atom[ypoint][xpoint].count++;
            Atom[ypoint][xpoint].idx = i;
            //moved[ypoint][xpoint] = true;
            Atominfo[i].y = ypoint;
            Atominfo[i].x = xpoint;
            Atominfo[i].dir = d;
            Atominfo[i].e = k;
 
        }
     
        cout << "#" << tc << " " << getResult() << endl;
 
        memset(Atominfo, 0, sizeof(Atominfo));
        memset(Atom, 0, sizeof(Atom));
        result = 0;
        Xmin = 2001, Xmax = 0, Ymin = 2001, Ymax = 0;
    }
    return 0;
}
