#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct POST{
    int y, x;
};

int n, m, type, ret;
vector<POST> house, shop, pick;


void dfs(int pos){
    if(pick.size() == m){
        int candi = 0;
        for(int i = 0; i < house.size(); i++){
            int min_dist = 10000000;
            for(int j = 0; j < pick.size(); j++){
                min_dist = min(min_dist, abs(house[i].y - pick[j].y) + abs(house[i].x - pick[j].x));
            }
            candi += min_dist;
        }
        if(ret > candi){
            ret = candi;

        }
        return ;
    }
    for(int i = pos; i < shop.size(); i++){
        pick.push_back(shop[i]);
        dfs(i+1);
        pick.pop_back();
    }
}
int main(){
    POST target;
    scanf("%d %d", &n, &m);
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            scanf("%d", &type);
            if(type == 1){
                target.y = y, target.x = x;
                house.push_back(target);
            }
            if(type == 2){
                target.y = y, target.x = x;
                shop.push_back(target);
            }
        }
    }
    ret = 0xfffffff;
    dfs(0);
    printf("%d\n", ret);
    return 0;
}