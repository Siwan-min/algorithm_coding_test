#include <iostream>
using namespace std;

// 2진수의 자리 수 하나를 구하는 재귀 함수
void Convert2Bin(int dec){

    // 10진수가 0보다 작거나 같으면 종료한다.
    if (dec <= 0)
        return;

    // 인자를 2로 나눈 값을 인자로 다시 호출한다.
    Convert2Bin(dec / 2);

    // 인자를 2로 나눈 나머지를 출력한다.
    cout << dec % 2; 
}


int main(){
    int n;
    cin>>n;
    Convert2Bin(n);

    cout << endl;

    return 0;
}

