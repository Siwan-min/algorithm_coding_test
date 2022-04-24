#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;


int main(){
     int idx=0;
     vector<string> lotto;

    while(!cin.eof()){
      string num;
      cin>>num;
      lotto.push_back(num);
    }

    for(int i = 0; i < lotto.size(); i++){
        cout<<lotto[i]<<endl;
    }

    return 0;
}