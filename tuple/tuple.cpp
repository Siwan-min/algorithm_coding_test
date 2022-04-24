// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// bool cmp(vector<int>& a, vector <int>& b){
// 	return a.size() > b.size(); // > 내림차순 , < 오름차순
//     // 왼쪽이 크면 왼쪽이 계속 크게 , 오른쪽이 크면 오른쪽이 계속 크게
// }


// vector<int> solution(string s) {
//     vector<int> answer;
//     vector <vector<int>> v(1000);
//     string data = "";
//     int idx = 0;
//     bool flag = false;
//     for(int i = 0; i < s.size(); i++){
//       //  if(s[i] == '{' || s[i] == '}' || s[i] == ','|| s[i] == ' ') continue;
//         if(s[i] == '{') flag = true;
//         if( flag == true ){
//             if(s[i] >= '0' && s[i] <= '9'){
//                 data += s[i]; //1
//             }
//             else{ // 숫자가 아니다. ',' 또는 '}'  나왔을 때 
//              if(data.size() != 0) { //데이터를 받은 상태
//                   for(int j = 0; j <=idx; j++){
//                      //if(v[j].empty()) continue;
//                      if(  v[j].empty() || v[j].front() == atoi(data.c_str()) ){
//                         if(v[j].empty()) idx++;
//                         v[j].push_back(atoi(data.c_str()));
//                         data = "";
//                         break;
//                       }
//                   }
//               }
//             }
//             if(s[i] == '}') flag = false;
//         }
//     }
   
    
//     //sort(v, v+idx+n, greater<int>)
//    sort(v.begin(), v.begin() + idx+1, cmp); 
    
//     for(int i = 0; i<idx; i++) {
//         if(v[i].empty()) break;
//         answer.push_back(v[i].front());
//     }
//     return answer;
// }

// #include <iostream>
// #include <string>
// #include <algorithm>
// #include <vector>

// using namespace std;

// struct p{
//     int first;
//     int second;
// };

// vector<int> solution(string s) {
//     vector<int> answer;
//     int st[101010] = {};
//     string data = "";
//     bool flag = false;
    
//     for(int i = 0; i < s.size(); i++){
 
//         if(s[i] >= '0' && s[i] <= '9'){
//             data += s[i];
//         }
//         else{
//             if(data.length() != 0){
//                 int num = atoi(data.c_str()); // 정수형으로 변환 
//                 st[num]++; // 인덱스의 갯수를 ++ 해준다
//                 data = ""; // 데이터 초기화 
            
//             }
//         }
//     }
//     vector<pair<int, int>> v;
//     for(auto i = 0; i < 101010; i++){ 
//         //st[i]가 0이 아니라면 그 데이터와 인덱스를 push_back
//         if(st[i]) v.push_back({st[i], i});
//     }
//     // 내림차순 정렬
//     sort(v.begin(), v.end(), greater<pair<int, int>>());
//   //  reverse(v.begin(), v.end());
//     for(auto it: v) answer.push_back(it.second);
//     return answer;
// }

// int main(){
    
//     string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
//    // cin>>s;
//     vector<int> t = solution(s);
//     for(int i = 0; i < t.size(); i++){
//         cout<<t[i]<<" ";
//     }
//    // {{2},{2,1},{2,1,3},{2,1,3,4}}
//     return 0;
// }


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct p {
    int y;
    int x;
};

p curLeft;
p curRight;

p keypad[13];

void nextLocation(char usedHand, int num ){

    if (usedHand == 'R'){
        curRight.y = keypad[num].y;
        curRight.x = keypad[num].x;
    }
    else {
        curLeft.y = keypad[num].y;
        curLeft.x = keypad[num].x;
    }
}
string solution(vector<int> numbers, string hand) {
    string answer = "";

    int num = 1; 
        for(int i = 0; i < 4; i ++){
            for(int j = 0; j < 3; j++){
                keypad[num].y = i;
                keypad[num].x = j;
                num++;
            }
        }
    
    // 초기 위치 설정
    curLeft.y = 3;
    curLeft.x = 0;
    curRight.y = 3;
    curRight.x = 2;
    
    for(int i = 0; i < numbers.size(); i++){
        
        if (numbers[i] == 0) numbers[i] = 11;
        
        if(numbers[i] == 1 ||
           numbers[i] == 4 ||
           numbers[i] == 7
          ){
            answer += 'L';
            nextLocation('L', numbers[i]);
        }
        else if(numbers[i] == 3 ||
               numbers[i] == 6 ||
               numbers[i] == 9
               ){
            answer += 'R';
            nextLocation('R', numbers[i]);
        }

        else{
            
            int numY = keypad[numbers[i]].y;
            int numX = keypad[numbers[i]].x;
           
            int LeftDist = abs(curLeft.y - numY) + abs(curLeft.x - numX);
            int RightDist = abs(curRight.y - numY) + abs(curRight.x - numX);
            
            if( LeftDist < RightDist ){ 
                answer += 'L';
                nextLocation('L', numbers[i]);
                }
            else if (LeftDist > RightDist) {
                answer += 'R';
                nextLocation('R', numbers[i]);
                }
            else {
                if (hand == "right") {
                    answer += 'R';
                    nextLocation('R', numbers[i]);
                    }
                else {
                    answer += 'L';
                    nextLocation('L', numbers[i]);
                }
            }
        }
    }
    return answer;
}

int main(){

    string hand = "right";
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);
    numbers.push_back(8);
    numbers.push_back(2);
    numbers.push_back(1);
    numbers.push_back(4);
    numbers.push_back(5);
    numbers.push_back(9);
    numbers.push_back(5);

    cout<< "LRLLLRLLRRL"<<endl;
    cout<< solution(numbers, hand);

  // answer LRLLLRLLRRL

    return 0;
}