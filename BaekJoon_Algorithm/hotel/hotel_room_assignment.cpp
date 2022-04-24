/*
문제 해결 방안:

Key point: 재귀 함수를 이용해서 푼다.

(1) 호텔 방이 비어 있다면, 그 호텔을 배정해주고
다음 방을 가리키도록 한다. 

(2) 비어있지 않다면, 그 호텔이 가리키는 방을 다시 확인한다. 
그 호텔이 가리키는 방이 비어있다면 그 방을 배정하고
 (1)을 반복한다. 
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<long, long> room_map;

long long findEmptyRoomN(long long num){
    
    // 기저 조건
    //호텔 방이 비어 있는 상태, 
    if (room_map[num] == 0){
        return num;
    }
    // 이미 배정이 된 상태라면 
    else {
        // 재귀 함수 호출 
        room_map[num] = findEmptyRoomN(room_map[num]);
        return room_map[num];
    }
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    // 원하는 방 번호를 받는다. 
    for( long long x : room_number){
        long long y = findEmptyRoomN(x);
        answer.push_back(y); //배정 받은 번호를 push_back
        room_map[y] = y + 1; //배정 된 방은 다음 방을 가리킨다. 
    }
    
    return answer;
}

int main(){
    long long k;
    
    vector<long long> room_number;
    room_number.push_back(1);
    room_number.push_back(3);
    room_number.push_back(4);
    room_number.push_back(1);
    room_number.push_back(3);
    room_number.push_back(1);

     
    for(auto answer : solution(k, room_number)){
       // long long answer = i;
        cout<<answer<<" ";
    }
    return 0;
}