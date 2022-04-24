/*
나중에 자세히 쓸게
*/

#include <iostream>
#define Dsize 14
#define Wsize 21
//using namespace std;

int arr[Dsize][Wsize];
int temp[Dsize][Wsize];

int T, D, W, K, result;
bool flag = false;

bool Test(){
    for (int j = 0; j < W; j++){
        int now = temp[0][j], cnt = 1;
        for(int i = 1; i < D; i++){
            if(temp[i][j] == now)
                cnt++;
            else {
                now = temp[i][j];
                cnt = 1;
            }
            if ( cnt == K) break; //똑같은 k개가 되면 바로 다음 열 감사.
        }
        if( cnt < K) return false; //k개가 안되면 false return
    }
    return true;
}

void fill(int x, int y){ //약품 투입
    for (int i = 0; i < W; i++)
        temp[x][i] = y;
    return ;
}

void rollback(int x){ //임시배열 되돌리기
    for (int i = 0; i < W; i++)
        temp[x][i] = arr[x][i];
    return;
}

void getResult(int x, int cnt, int now){ // 매개변수 : 현재 바꾼 갯수, 최대 바꿀 갯수, 바꿔줄 인덱스
    if(flag) return;
    if(x == cnt){
        // for(int i = 0; i<D; i++){
        //     for(int j = 0; j < W; j++)
        //         cout << temp[i][j] <<" ";
        //     cout << endl; 
        // }
        // cout << "cnt : " << cnt <<" ";
        // if(Test())
        //     cout << "True" << '\n' <<endl;
        // else
        //     cout << "F" << '\n' << endl;
        
        if(Test()) result = cnt, flag = true;
        return;
    }

    for (int i = now; i < D; i++){
        fill(i, 0); //1번째 행에 0번 약품 투입
        getResult(x + 1, cnt, i + 1);
        fill(i, 1); // i 번째 행에 1번 약품 투입
        getResult(x + 1, cnt, i + 1);
        rollback(i); // 배열 되돌리기
    }
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cin>>T;
    for(int tc = 1; tc<=T; tc++){
       
        std::cin>>D>>W>>K;

        for(int i = 0; i < D; i++){
            for(int j = 0; j < W; j++){
                std::cin>>arr[i][j];
                temp[i][j] = arr[i][j];
            }
        }
        //std::cout<<"\n";
        flag = false, result = 0;
        for (int i = 0; i < D; i++){ //D-1 개까지 바꿀 수 있다
            if (flag ) break;
            getResult(0, i, 0); // 바꾸는 개수 i 
        }
        std::cout<<"#"<<tc<<" "<<result<<"\n";
    }
    return 0;
}