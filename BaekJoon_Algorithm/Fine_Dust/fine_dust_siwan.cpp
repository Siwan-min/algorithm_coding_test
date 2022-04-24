#include <iostream>
#include <cstring>

using namespace std;

int R, C, T;
int A[50][50];
int hi, lo;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

//bool check[1005][1005];
int temp[50][50];

void spread(int y, int x)
{

    int cnt = 0;

    for (int i = 0; i < 4; i++)
    {
        int yy = y + dy[i];
        int xx = x + dx[i];

        if (yy < 0 || yy >= R || xx < 0 || xx >= C || A[yy][xx] == -1)
            continue; // 칸이 없거나 공기 청정기
        else
        {
            cnt++;
            temp[yy][xx] += A[y][x] / 5;
        }
    }

    A[y][x] = A[y][x] - A[y][x] / 5 * cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
	  cin.tie(NULL);
  	cout.tie(NULL);
    cin >> R >> C >> T;
    bool check_hi = false;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> A[i][j];
            //  if(A[i][j]) check[i][j]= true;
            if (A[i][j] == -1 && check_hi == false)
            {
                hi = i;
                lo = i + 1;
                check_hi = true;
            }
        }
    }
   //  T = 1;
    while (T > 0)
    {
        T--;
         // 확산
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (A[i][j] == 0 || A[i][j] == -1)
                    continue;
                spread(i, j);
            }
        }

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                A[i][j] += temp[i][j];
                temp[i][j] = 0;
              // cout<<A[i][j]<<" ";
            }//cout<<endl;
        }
        // memset(temp, 0, sizeof(temp));
        int hi_temp[50][50] = {0, };
        for (int i = 0; i <= hi; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (i > 0 && i < hi && j > 0 && j < C - 1) continue;
                if (A[i][j] == -1) continue;
                else
                {
                  //   cout << A[i][j] << " ";
                    if(i == 0) {
                      if(j == 0) {
                        if(A[i+1][j] == -1) A[i][j] = 0;
                        else{
                          hi_temp[i+1][j] = A[i][j];
                        }
                      }
                      else {
                        hi_temp[i][j-1] = A[i][j];
                      }
                    }
                    else if(i == hi){
                      if(j == C - 1){
                        hi_temp[i-1][j] = A[i][j];
                      }
                      else{
                        hi_temp[i][j+1] = A[i][j];
                      }
                    }
                    else if( i != 0 && i != hi){
                      if(j == 0){
                        if(A[i+1][j] == -1) A[i][j] = 0;
                        else{
                          hi_temp[i+1][j] = A[i][j];
                        }
                      }
                      else if(j == C-1){
                        hi_temp[i-1][j] = A[i][j];
                      }
                    }
                }
            }
        }
       
        for (int i = 0; i <= hi; i++)
        {
            for (int j = 0; j < C; j++)
            {
               if (i > 0 && i < hi && j > 0 && j < C - 1) continue;
                if (A[i][j] == -1) continue;
                A[i][j] = hi_temp[i][j];
                
                //cout<<hi_temp[i][j]<<" ";
            }//cout<<endl;
        } 
        int lo_temp[50][50];
          for(int i = lo; i < R; i++){
              for(int j = 0; j < C; j++){
                if (i > lo && i < R-1 && j > 0 && j < C - 1) continue;
                if (A[i][j] == -1) continue;
              // if(A[i][j] == 0) continue;
                else
                {
                //    cout << A[i][j] << " ";
                    if (i == lo)
                    {
                      if(j == C - 1){
                        lo_temp[i+1][j] = A[i][j];
                      }
                      else{
                        lo_temp[i][j+1] = A[i][j];
                      }
                    }
                    else if (i == R-1)
                    {
                        if(j == 0){
                          lo_temp[i-1][j] = A[i][j];
                        }
                        else{
                          lo_temp[i][j-1] = A[i][j];
                        }
                    }
                    else if(i != lo && i != R-1){
                      if(j == 0){
                        if(A[i-1][j]==-1) A[i][j] = 0;
                        else lo_temp[i-1][j] = A[i][j];
                      }
                      else if(j==C-1){
                        lo_temp[i+1][j] = A[i][j];
                      }
                    }
                }
              }
          }
        //  cout<<endl;
          for (int i = lo; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                  if (i > lo && i < R-1 && j > 0 && j < C - 1) continue;
                  if (A[i][j] == -1) continue;
                    A[i][j] = lo_temp[i][j];
                }//cout<<endl;
            } 
          // memset(hi_temp, 0, sizeof(hi_temp));
          // memset(lo_temp, 0, sizeof(lo_temp));
    }

    // cout<<endl;
    // for(int i = 0; i<R; i++){
    //     for(int j = 0; j<C; j++){
    //         cout<<A[i][j]<<" ";
    //     }cout<<endl;
    // }
    //결과
    int result = 0;
    for(int i = 0 ; i <R; i++){
        for(int j = 0 ;j < C; j++){
            if(A[i][j] == -1 || !A[i][j] ) continue;
            
            result += A[i][j];
        }
    }
   
     cout<<result<<endl;

    return 0;
}
/*
0 0 0 0 0 1 8 6 
0 0 1 0 3 0 5 5 
-1 0 2 1 1 0 4 6 
-1 0 5 2 0 0 2 12 
0 1 1 0 5 10 13 0 
0 1 9 4 3 5 12 8 
8 17 8 3 4 8 4 0 
*/

/*

0 0 0 0 2 7 6 5 
0 0 1 0 3 1 3 6 
-1 0 0 3 1 1 0 6 
-1 0 1 1 3 1 2 6 
1 1 3 1 3 6 9 0 
9 5 6 5 5 6 8 5 
10 9 4 5 6 7 1 7 

*/