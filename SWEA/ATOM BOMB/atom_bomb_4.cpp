/*
 정답 코드
 kdk8361
 m/ 153340
 t/ 12
 l/ 2502
*/
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
using namespace std;
 
struct p {
    int x, y, w, c, i;
};
struct pp {
    int t, i, j;
};
typedef pair<int, int> pii;
 
int d[1001];
p a[4][1001];
int a2[1001], qidx;
pp q[12000002];
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t, n;
    cin >> t;
 
    register int i, j, k, l, x, y, w, c, idx[4], xdis, ydis, dist;
    for (int tc = 1; tc <= t; ++tc) {
        qidx = 0;
        cin >> n;
        idx[0] = idx[1] = idx[2] = idx[3] = 0;
        for (i = 0; i < n; ++i) {
            cin >> x >> y >> w >> c;
            a[w][idx[w]++] = { x,y,w,c,i };
            a2[i] = c;
            d[i] = -1;
        }
 
        for (i = 0; i < idx[0]; ++i) {
            int f = 0;
            for (j = 0; j < idx[1]; ++j) if ((dist = a[1][j].y - a[0][i].y) > 0 && a[0][i].x == a[1][j].x) {
                f = 1;
                q[qidx++] = { dist, a[0][i].i,a[1][j].i };
            }
            for (j = 0; j < idx[2]; ++j) if ((dist = a[2][j].y - a[0][i].y) == a[2][j].x - a[0][i].x && dist > 0) {
                f = 1;
                dist <<= 1;
                q[qidx++] = { dist, a[0][i].i,a[2][j].i };
            }
            for (j = 0; j < idx[3]; ++j) if ((dist = a[0][i].x - a[3][j].x) == a[3][j].y - a[0][i].y && dist > 0) {
                f = 1;
                dist <<= 1;
                q[qidx++] = { dist, a[0][i].i,a[3][j].i };
            }
            if (!f) n--;
        }
 
        for (i = 0; i < idx[1]; ++i) {
            int f = 0;
            for (j = 0; j < idx[2]; ++j) if ((dist = a[2][j].x - a[1][i].x) == a[1][i].y - a[2][j].y && dist > 0) {
                f = 1;
                dist <<= 1;
                q[qidx++] = { dist, a[1][i].i,a[2][j].i };
            }
            for (j = 0; j < idx[3]; ++j) if ((dist = a[1][i].x - a[3][j].x) == a[1][i].y - a[3][j].y && dist > 0) {
                f = 1;
                dist <<= 1;
                q[qidx++] = { dist, a[1][i].i,a[3][j].i };
            }
            if (!f) n--;
        }
 
        for (i = 0; i < idx[2]; ++i) {
            int f = 0;
            for (j = 0; j < idx[3]; ++j) if ((dist = a[2][i].x - a[3][j].x) > 0 && a[2][i].y == a[3][j].y) {
                f = 1;
                q[qidx++] = { dist, a[2][i].i,a[3][j].i };
            }
            if (!f) n--;
        }
 
        sort(q, q + qidx, [&](const pp &a, const pp &b) {
            return a.t < b.t;
        });
 
        int ans = 0;
        for (i = 0; n && i<qidx; ++i) {
            if (d[q[i].i] == q[i].t) {
                if (d[q[i].j] == -1) {
                    d[q[i].j] = q[i].t;
                    ans += a2[q[i].j];
                    n--;
                }
            }
            else if (d[q[i].i] == -1) {
                if (d[q[i].j] == -1) {
                    d[q[i].i] = d[q[i].j] = q[i].t;
                    ans += a2[q[i].i] + a2[q[i].j];
                    n -= 2;
                }
                else if (d[q[i].j] == q[i].t) {
                    d[q[i].i] = q[i].t;
                    n--;
                    ans += a2[q[i].i];
                }
            }
        }
         
        cout << "#" << tc << " " << ans << '\n';
    }
    return 0;
}
