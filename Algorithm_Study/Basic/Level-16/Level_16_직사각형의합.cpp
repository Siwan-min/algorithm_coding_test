#include <iostream>
#include <vector>
using namespace std;

int map[1002][1002];

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int N, M, Q;
   cin >> N >> M >> Q;
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         int num; cin >> num;
         map[i + 1][j + 1] = map[i + 1][j] + map[i][j + 1] - map[i][j] + num;
      }
   }

   for (int i = 0; i < Q; i++) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      cout << map[x2 + 1][y2 + 1] - map[x1][y2 + 1] - map[x2 + 1][y1] + map[x1][y1] << '\n';
   }

   return 0;
}