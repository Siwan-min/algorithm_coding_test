#include <iostream>

using namespace std;

int n, B, C; 
long long cnt;
int arr[1000005];

int main(){

    cin>>n;
    for(int i = 0 ; i < n; i++) cin>>arr[i];
    cin>>B>>C;

    for(int i = 0; i < n; i++){
        arr[i] = arr[i] - B;
        cnt++;
        if(arr[i] > 0){
            int candi = arr[i] / C;
            if(arr[i] % C != 0) candi++;

            cnt += candi;
        }
         
    }
    cout<<cnt;
    
    return 0;
}