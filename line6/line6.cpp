/*
문제 설명:

다양한 기업과 많은 지원자들이 참여한 대규모 공개 채용 이벤트가 진행되었습니다.
마침내 엄청난 경쟁을 뚫고 올라온 N명의 지원자들이 M개의 기업에 입사할 수 있는 기회를 얻었습니다.
이벤트 진행자는 설문을 통해 각 기업으로부터 지원자 선호 순위와 채용 인원수를 수집했고,
각 지원자로부터 기업 선호 순위와 입사를 희망하는 기업 수를 수집했습니다.
이 정보를 이용해 기업과 지원자들을 매칭 하려고 합니다.

아래 표는 2개는 각각 기업과 지원자의 설문 조사 내용을 나타냅니다. 기업의 이름은 알파벳 대문자로,
지원자의 이름은 알파벳 소문자로 나타냅니다.

첫 번째 표는 각 기업이 선호하는 지원자의 순위와 채용하고자 하는 인원수를 나타냅니다.
 > 의 오른쪽에 있을수록 선호도가 낮음을 의미합니다. 

 기업   지원자에 대한 선호도        채용 인원 수
 A      f > a > b > d > e > c       2
 B      c > e > b > d > f > a       2
 C      e > c > f > a > d > b       2

 두 번째 표는 각 지원자가 선호하는 기업의 순위와 입사하고자 하는 기업의 수를 나타냅니다.
 어떤 지원자의 입사 희망 기업 수가 1일 경우, 선호도 상위 1위 기업에만 입사 할 의지가 
 있음을 나타냅니다. 

 지원자     기업에 대한 선호도      입사 희망 기업 수
 a          B > A > C               1
 b          B > A > C               3
 c          B > C > A               2
 d          A > B > C               3
 e          B > C > A               3
 f          A > B > C               2

 다음 과정을 따라 가업과 지원자를 매칭 합니다.

 1단계, 지원자는 거절당하지 않았던 기업 중에서 자신의 선호도가 가장 높은 기업 

 2단계, 기업은 채용 인원수를 넘지 않는 한도 내에서 선호도가 높은 순서대로 

 3단계, 거절당한 지원자들 중에서 다른 기업에 지원할 지원자가 있다면 1단계부

 아래 그림은 기업과 지원자를 매칭하는 과정입니다. 총 4라운드를 거치며, 밑줄은 기업이
 잠정 선택한 지원자를 나타냅니다. 화살표는 거절당한 지원자가 다음 라운드에 지언하는 기업을
 가리킵니다. 

입력
companies                   applicants              result
["A fabdec 2",             ["a BAC 1", ""] 
"B cebdfa 2",
"C ecfadb 2"]
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>


using namespace std;

map<string, char> lineGo;

vector <string> solution(vector<string> companies, vector<string> applicants){
    vector<string> answer;

    for(string st : companies){
        
        answer.push_back(st.front());
    }

    return answer;
}

int main(){

    vector<string> companies;
    vector<string> applicants;

    companies.push_back("A fabdec 2");
    companies.push_back("B cebdfa 2");
    companies.push_back("C ecfadb 2");

    applicants.push_back("a BAC 1");
    applicants.push_back("b BAC 3");
    applicants.push_back("c BCA 2");
    applicants.push_back("d ABC 3");
    applicants.push_back("e BCA 3");
    applicants.push_back("f ABC 2");

    // for(auto i : companies){
    //     cout<<i<<endl;
    // }

    for(auto i : solution(companies, applicants)){
        cout<<i<<endl;
    }
    // A_bf , B_ce , C_d
    return 0;
}