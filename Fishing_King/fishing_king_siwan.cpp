#include <iostream>

//using namespace std;

struct info {
	int s; //속력
	int d; //이동 방향
	int z; //크기
};


int r, c, m;
info map[2][105][105];
/* 
1 상 
2 하 
3 우 
4 좌 
*/

int fish(int cur, int idx) {
	int size = 0;
	for (int i = 0; i < r; i++) {
		if (map[cur][i][idx].z) {
			size += map[cur][i][idx].z;
			map[cur][i][idx].z = 0;
			map[cur][i][idx].s = 0;
			map[cur][i][idx].d = 0;
			break;
		}
	}
	return size;
}
void move(int cur) {
	int next = (cur + 1) % 2;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			map[next][i][j].s = 0;
			map[next][i][j].d = 0;
			map[next][i][j].z = 0;
		}
	}
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[cur][i][j].z != 0) {
                // (변의 길이 -1) * 2 가 한 사이클 
				if (map[cur][i][j].d == 1){

					int yy = (((r - 1) * 2) - i) + map[cur][i][j].s;
					yy = (yy % ((r - 1) * 2));
					int nd = 2; // 방향은 반대 
					if (yy >= (r - 1)) {
						yy = ((r - 1) * 2) - yy;
						nd = 1;
					}
                    if(map[next][yy][j].z < map[cur][i][j].z){
                        map[next][yy][j].z = map[cur][i][j].z;
                        map[next][yy][j].s = map[cur][i][j].s;
                        map[next][yy][j].d = nd;
                    }
                    
				}
				else if (map[cur][i][j].d == 2) {
                    int yy = i + map[cur][i][j].s;
					yy = (yy % ((r - 1) * 2));
					int nd = 2; // 방향은 반대 
					if (yy >= (r - 1)) {
						yy = ((r - 1) * 2) - yy;
						nd = 1;
					}
                    if(map[next][yy][j].z < map[cur][i][j].z){
                        map[next][yy][j].z = map[cur][i][j].z;
                        map[next][yy][j].s = map[cur][i][j].s;
                        map[next][yy][j].d = nd;
                    }
				}
				else if (map[cur][i][j].d == 3) {
				    int xx = j + map[cur][i][j].s;
					xx = (xx % ((c - 1) * 2));
					int nd = 3; // 방향은 반대 
					if (xx >= (c - 1)) {
						xx = ((c - 1) * 2) - xx;
						nd = 4;
					}
                    if(map[next][i][xx].z < map[cur][i][j].z){
                        map[next][i][xx].z = map[cur][i][j].z;
                        map[next][i][xx].s = map[cur][i][j].s;
                        map[next][i][xx].d = nd;
                    }
				}
				else if (map[cur][i][j].d == 4) {
                    int xx = (((c - 1) * 2) - j) + map[cur][i][j].s;
					xx = (xx % ((c - 1) * 2));
					int nd = 3; // 방향은 반대 
					if (xx >= (c - 1)) {
						xx = ((c - 1) * 2) - xx;
						nd = 4;
					}
                    if(map[next][i][xx].z < map[cur][i][j].z){
                        map[next][i][xx].z = map[cur][i][j].z;
                        map[next][i][xx].s = map[cur][i][j].s;
                        map[next][i][xx].d = nd;
                    }
				}
			}
		}
	}
}

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
  	std::cout.tie(NULL);
	int cur = 0;
	std::cin >> r >> c >> m;

	for (int i = 0; i < m; i++) {
		int y, x , s, d, z;
		std::cin >> y >> x >>s>>d>>z;
		y--, x--;
		map[0][y][x].s = s;
		map[0][y][x].d = d;
		map[0][y][x].z = z;
	}
 //   cout<<endl;
	int result = 0;
	for (int i = 0; i < c; i++) {
		result += fish(cur, i);
        // cout<<"fish: "<<i<<endl;
        // for(int y = 0 ; y < r; y++) {
        //     for(int x = 0; x< c; x++){
        //         cout<<map[cur][y][x].z<<" ";        
        //     }cout<<endl;
        // }

		move(cur);
        // cout<<"move: "<<i<<endl;
        // for(int y = 0 ; y < r; y++) {
        //     for(int x = 0; x< c; x++){
        //         cout<<map[cur][y][x].z<<" ";        
        //     }cout<<endl;
        // }
		cur = (cur + 1) % 2;
        
	}
    std::cout<<result<<std::endl;
	return 0;
}