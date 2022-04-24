#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool visited[304][304];
int arr[310][310];
int cost[310][310];

struct p{

    int y;
    int x;
};

queue <p> Queue;

int solution(vector<vector<int>> maze){
    int answer = 0;
    //맵 초기화 
    for(int i = 0 ; i < 310; i++){
        for(int j = 0; j < 310; j++){
            arr[i][j] = 1; 
        }
    }
    //맵 체크
    for(int i = 0; i < maze.size(); i++){
        for(int j = 0; j < maze[i].size(); j++){
            if(maze[i][j]) {
                visited[i+1][j+1] = true;
            }
        }
    }
    //맵 복사
    for(int i = 0; i < maze.size(); i++){
        for(int j = 0; j < maze[i].size(); j++){
            arr[i+1][j+1] = maze[i][j];
        }
    }
    //시작 자리 
    visited[1][1] = true;
    Queue.push({1, 1});

    int n = maze.size();

    while(!Queue.empty()){

        p front = Queue.front();
        Queue.pop();

        int curY = front.y;
        int curX = front.x;

        for(int i = 0; i < 4; i++){
            //왼손
            int ny = curY + dy[i];
            int nx = curX + dx[i];
            
            int i2 = i + 1;
            if( i2 >=4 ) i2 = 0;
            int yy = ny + dy[i2];
            int xx = nx + dy[i2];

            //범위
            bool flag = false; 
            if(visited[ny][nx] && !visited[yy][xx] && yy >= 1 && xx >= 1 && yy <= n && xx <= n){
                visited[curY][curX] = true;
                arr[yy][xx] = arr[curY][curX] + 1;
                Queue.push({yy, xx});
                flag = true;
            }

            

            
        }
    }




    // for(auto i = 0; i < maze.size(); i++){
    //     for(auto j = 0; j < maze[i].size(); j++){
    //         cout<<maze[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    

    return answer;
}
int main(){

    vector<vector<int>> maze(4, vector<int>(4, 0));
    /*
    0 1 0 1
    0 1 0 0
    0 0 0 0 
    1 0 1 0
    */
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int n;
            cin>>n;
            maze[i][j] = n;
        }
    }

    // for(auto i = 0; i < maze.size(); i++){
    //     for(auto j = 0; j < maze[i].size(); j++){
    //         cout<<maze[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<solution(maze);
  
    return 0;
}