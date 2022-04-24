#include <stdio.h>
#include <queue>
using namespace std;

int m, n;
int y1, y2, x1, x2, dir1, dir2;
int map[110][110];
int east[110][110], west[110][110], north[110][110], south[110][110];
bool checkE[110][110], checkW[110][110], checkN[110][110], checkS[110][110];

struct p {
  int y;
  int x;
  int dir;
};

p make(int y, int x, int dir) {
  p tmp;
  
  tmp.y = y;
  tmp.x = x;
  tmp.dir = dir;
  
  return tmp;
}

queue <p> q;

void bfs(int y, int x, int dir) {
  
  if (dir == 1) checkE[y][x] = true;
  if (dir == 2) checkW[y][x] = true;
  if (dir == 3) checkS[y][x] = true;
  if (dir == 4) checkN[y][x] = true;
  q.push(make(y, x, dir));
  
  while (!q.empty()) {
    
    p front = q.front();
    q.pop();
    
    int cy = front.y;
    int cx = front.x;
    int cd = front.dir;
    
    if (cd == 1) { //동쪽
      if (!checkN[cy][cx]) { //북쪽방향
        checkN[cy][cx] = true;
        north[cy][cx] = east[cy][cx] + 1;
        q.push(make(cy, cx, 4));
      }
      if (!checkS[cy][cx]) { //남쪽방향
        checkS[cy][cx] = true;
        south[cy][cx] = east[cy][cx] + 1;
        q.push(make(cy, cx, 3));
      }
      
      for (int i = 1; i <= 3; i++) { //동쪽으로 이동
        if (cx + i <= n) {
          if (map[cy][cx + i] == 1) break;
          if (map[cy][cx + i] == 0 && !checkE[cy][cx + i]) {
            checkE[cy][cx + i] = true;
            east[cy][cx + i] = east[cy][cx] + 1;
            q.push(make(cy, cx + i, 1));
          }
        }
      }
    }
    
    if (cd == 2) { //서쪽
      if (!checkN[cy][cx]) { //북쪽방향
        checkN[cy][cx] = true;
        north[cy][cx] = west[cy][cx] + 1;
        q.push(make(cy, cx, 4));
      }
      if (!checkS[cy][cx]) { //남쪽방향
        checkS[cy][cx] = true;
        south[cy][cx] = west[cy][cx] + 1;
        q.push(make(cy, cx, 3));
      }
      
      for (int i = 1; i <= 3; i++) { //서쪽으로 이동
        if (cx - i >= 1) {
          if (map[cy][cx - i] == 1) break;
          if (map[cy][cx - i] == 0 && !checkW[cy][cx - i]) {
            checkW[cy][cx - i] = true;
            west[cy][cx - i] = west[cy][cx] + 1;
            q.push(make(cy, cx - i, 2));
          }
        }
      }
    }
    
    if (cd == 3) { //남쪽
      if (!checkE[cy][cx]) { //동쪽방향
        checkE[cy][cx] = true;
        east[cy][cx] = south[cy][cx] + 1;
        q.push(make(cy, cx, 1));
      }
      if (!checkW[cy][cx]) { //서쪽방향
        checkW[cy][cx] = true;
        west[cy][cx] = south[cy][cx] + 1;
        q.push(make(cy, cx, 2));
      }
      
      for (int i = 1; i <= 3; i++) { //남쪽으로 이동
        if (cy + i <= m) {
          if (map[cy + i][cx] == 1) break;
          if (map[cy + i][cx] == 0 && !checkS[cy + i][cx]) {
            checkS[cy + i][cx] = true;
            south[cy + i][cx] = south[cy][cx] + 1;
            q.push(make(cy + i, cx, 3));
          }
        }
      }
    }
    
    if (cd == 4) { //북쪽
      if (!checkE[cy][cx]) { //동쪽방향
        checkE[cy][cx] = true;
        east[cy][cx] = north[cy][cx] + 1;
        q.push(make(cy, cx, 1));
      }
      if (!checkW[cy][cx]) { //서쪽방향
        checkW[cy][cx] = true;
        west[cy][cx] = north[cy][cx] + 1;
        q.push(make(cy, cx, 2));
      }
      
       for (int i = 1; i <= 3; i++) { //북쪽으로 이동
        if (cy - i >= 1) {
          if (map[cy - i][cx] == 1) break;
          if (map[cy - i][cx] == 0 && !checkN[cy - i][cx]) {
            checkN[cy - i][cx] = true;
            north[cy - i][cx] = north[cy][cx] + 1;
            q.push(make(cy - i, cx, 4));
          }
        }
      }
    }
  }
}

int main() {
  scanf("%d %d", &m, &n);
  
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &map[i][j]);
    }
  }
  
  scanf("%d %d %d", &y1, &x1, &dir1);
  scanf("%d %d %d", &y2, &x2, &dir2);
  
  bfs(y1, x1, dir1);
  
  if (dir2 == 1) printf("%d", east[y2][x2]);
  if (dir2 == 2) printf("%d", west[y2][x2]);
  if (dir2 == 3) printf("%d", south[y2][x2]);
  if (dir2 == 4) printf("%d", north[y2][x2]);

  return 0;
}