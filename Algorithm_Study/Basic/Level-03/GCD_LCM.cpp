#include <iostream>

using namespace std;

int main(){
    int a, b;
    int A, B;
    cin>>a>>b;

    A=a;
    B=b;
    
    while(1){
        int c = a % b;
        if( c == 0) break;
        a = b;
        b = c;
    }

    int GCD = b;
    int LCM = GCD * (A/GCD) * (B/GCD);
    cout<<GCD<<"\n"<<LCM;
    return 0;
}