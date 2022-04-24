#include <iostream>

using namespace std;

int n, ans;
int arr[1001];
int dp[1001];

int main(){

    cin>>n;
    for(int i = 0; i < n; i++){
        cin>> arr[i];
    }

    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j ++)
            if(arr[i]>arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    cout<< ans << endl;

    return 0;
}