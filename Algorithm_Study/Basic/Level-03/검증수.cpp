#include <iostream>
using namespace std;

int main(){
    int ans;
    for(int i = 0; i < 5; i++){
        int n;
        cin>>n;
        ans+=n*n;
    }
    cout<<ans%10;
    return 0;
}