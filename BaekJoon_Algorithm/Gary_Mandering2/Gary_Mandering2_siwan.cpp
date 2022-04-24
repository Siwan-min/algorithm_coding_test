#include <iostream>

#define MAX 20
// using namespace std;
int n, sum; 
int map[MAX][MAX];
int ans = 987987987;
int arr[5];

void getSection(int y, int x, int d1, int d2){

    for(int i = 0; i < 5; i++) arr[i] = 0;

    int k =0;

    for(int i = 0; i < y + d1; i++){
        if(i >= y) k++;
        for(int j = 0; j <= x -k; j++)
            arr[0] += map[i][j];
    }

    k = 1;
    for(int i = 0; i <= y + d2; i++){
        if(i > y) k++;
        for(int j = x +k; j < n; j++)
            arr[1] += map[i][j];
    }

    k = 0;
    for(int i = y + d1; i <n; i++){
        for(int j =0; j < x - d1 + k; j++)
            arr[2] += map[i][j];
        if(i < y + d1 + d2) k++;
    }

   k = 0;
   for(int i = y + d2 + 1; i <n; i++){
       for(int j = x + d2 - k; j <n; j++)
            arr[3] += map[i][j];
       if(i <= y +d1 + d2) k++;
   }

   arr[4] = sum - (arr[0] + arr[1] + arr[2] + arr[3]);
   int min = 987987987; int max = 0;

   for(int i = 0; i < 5; i++){
       if(arr[i] > max) max = arr[i];
       if(arr[i] < min) min = arr[i];
   }
   if(ans > max - min) ans = max - min;
}

void getArea(){

    for(int y = 0; y < n-2; y++){ // y 시작점
        for(int x = 1; x < n-1; x++){ // x 시작점
            for(int d1 = 1; y+d1 < n-1 && x-d1 >=0 ;d1++){
                for(int d2 = 1; y+d1+d2 < n && x + d2 - d1 < n-1; d2++ ){
                    getSection(y, x, d1, d2);
                }
            }
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
    std::cin>>n;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
           std::cin>>map[i][j];
            sum += map[i][j];
        }
    }

   getArea();
    std::cout << ans <<std::endl;

    return 0;
}

// #include <stdio.h>
// #define MIN(a, b) (((a) < (b)) ? (a) : (b))
// #define MAX(a, b) (((a) > (b)) ? (a) : (b))

// int n, sum = 0;
// int map[21][21] = {0, };

// int main(){

//     scanf("%d", &n);
//     for( int x = 1; x <=n; ++x){
//         for(int y = 1; y <= n; ++y){
//             scanf("%d", &map[x][y]);
//             sum += map[x][y];
//         }
//     }
//     int ret = 0x7fffffff;
//    // int count = 0;
//     for(int x = 1; x <=n; ++x){
//         for(int y = 1; y <=n; ++y){
//             for(int d1 = 1; d1 <=n; ++d1){
//                 for(int d2 = 1; d2 <=n; ++d2){
//                     if(x + d1 + d2 <=n; ++d2) continue;
//                     if(1 > y - d1) continue;
//                     if(y + d2 > n) continue;
//                    // ++count;
//                     ret = MIN(ret, solve(x, y, d1, d2));
//                 }
//             }
//         }
//     }
//     printf("%d", ret);
//  //   printf("%d\n", count);
//     return 0;
// }