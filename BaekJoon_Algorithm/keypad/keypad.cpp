/*
문제 해결 방안:
0 ~ 9 까지 각 숫자의 Y값과 X 값을 배열에 받는다. 
만약 눌러야 하는 숫자가 
    >> 1 4 7 이면 문자열에 'L' 을 추가 해준다.
    >> 3 6 9 이면 문자열에 'R' 을 추가 해준다. 

그게 아니면 눌러야 하는 숫자의 위치가 
    >> 왼손과 가까우면 'L'
    >> 오른손과 가까우면 'R'

    만약 거리가 같다면 주로 사용하는 손을 더해준다. 

사용한 손의 위치를 바꿔준다. 
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct p {
    int y;
    int x;
};

p curLeft, curRight;
p keypad[13];

//현재 손 위치 변경 
void nextLocation(char usedHand, int num ){

    // 오른손으로 버튼을 눌렀다면,
    if (usedHand == 'R'){
        curRight.y = keypad[num].y;
        curRight.x = keypad[num].x;
    }
    else { //왼손으로 버튼을 눌렀다면 
        curLeft.y = keypad[num].y;
        curLeft.x = keypad[num].x;
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int num = 1; 
    //각 숫자가 같는 위치의 좌표값을 구조체 배열에 받는다. 
    for(int i = 0; i < 4; i ++){
        for(int j = 0; j < 3; j++){
            keypad[num].y = i;
            keypad[num].x = j;
            num++;
        }
    }
    
    // 초기 위치 설정
    curLeft.y = 3, curLeft.x = 0;
    curRight.y = 3, curRight.x = 2;
    
    for(int i = 0; i < numbers.size(); i++){
        
        if (numbers[i] == 0) numbers[i] = 11;
        //왼손 사용의 경우
        if(numbers[i] == 1 ||
           numbers[i] == 4 ||
           numbers[i] == 7
          ){
            answer += 'L';
            nextLocation('L', numbers[i]);
        }
        // 오른손 사용의 경우 
        else if(numbers[i] == 3 ||
               numbers[i] == 6 ||
               numbers[i] == 9
               ){
            answer += 'R';
            nextLocation('R', numbers[i]);
        }
        // 키패드 가운데 라인의 경우
        else{
            //눌러야 할 번호의 좌표를 구한다.
            int numY = keypad[numbers[i]].y;
            int numX = keypad[numbers[i]].x;
           
           // 눌러야 할 버튼을 기준으로 왼손과 오른손의 거리를 구한다.
            int LeftDist = abs(curLeft.y - numY) + abs(curLeft.x - numX);
            int RightDist = abs(curRight.y - numY) + abs(curRight.x - numX);
            // 왼손이 더 가깝다면
            if( LeftDist < RightDist ){ 
                answer += 'L';
                nextLocation('L', numbers[i]);
                }
             //오른손이 더 가깝다면   
            else if (LeftDist > RightDist) {
                answer += 'R';
                nextLocation('R', numbers[i]);
                }

            //거리가 똑같을 경우    
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

// int main(){

//     string hand = "right";
//     vector<int> numbers;
//     numbers.push_back(1);
//     numbers.push_back(3);
//     numbers.push_back(4);
//     numbers.push_back(5);
//     numbers.push_back(8);
//     numbers.push_back(2);
//     numbers.push_back(1);
//     numbers.push_back(4);
//     numbers.push_back(5);
//     numbers.push_back(9);
//     numbers.push_back(5);

//  //   cout<< "LRLLLRLLRRL"<<endl;
//     cout<< solution(numbers, hand);

//   // answer LRLLLRLLRRL

//     return 0;
// }