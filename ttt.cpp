// #include <iostream>
// using namespace std;

// int recursiveSum(int n){
//     if(n == 1) return 1;
//     return n - recursiveSum(n-1);
// }
// int main(){
//     int n;
//     cin>>n;

//     cout<<recursiveSum(n)<<endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
bool used[10];
int ret = 0;
set<string> S;

// 비교하는 함수
bool Compare(string a, string b){

    //길이가 틀리다면 다른 문자! 
    if(a.length() != b.length())  
        return false;

    // *이 아니고 서로 문자가 다르면 다른 문자!
    for(int i =0; i <a.length(); i++)
        if(a[i] != b[i] && b[i] != '*') 
            return false;
    return true;
}

void getResult(int idx, vector<string> user_id, vector<string> banned_id){
    if(idx == banned_id.size()){ // 기저조건
        string tmp;
        for(int i =0; i < user_id.size(); i++) 
            if(used[i]) tmp+= i+'0'; //인덱스 값을 문자열로 넣는다.

        // 사용 된 문자라면 함수를 종료한다.
        if(S.find(tmp) != S.end())  
            return; 
        
        // set에 tmp를 추가한다.
        S.insert(tmp);
        ret++;
        return;
    }
    for(int i = 0; i <user_id.size(); i++){
        //현재 사용 된 문자가 아니고 서로 같은 문자라면
        if(!used[i] && Compare(user_id[i], banned_id[idx])){
            used[i] = true;
            getResult(idx+1, user_id, banned_id);
            used[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    getResult(0, user_id, banned_id);
    return ret;
}

int main(){
    vector<string> user_id;
    vector<string> banned_id;

    user_id.push_back("frodo");
    user_id.push_back("fradi");
    user_id.push_back("crodo");
    user_id.push_back("abc123");
    user_id.push_back("frodoc");

    banned_id.push_back("*rodo");
    banned_id.push_back("*rodo");
    banned_id.push_back("******");

    cout<<solution(user_id, banned_id)<<endl;
  //  cout<<S.size()<<endl;
}