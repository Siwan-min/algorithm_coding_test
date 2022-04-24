// C++ program to decode a string recursively 
// encoded as count followed substring 


/*
문제: 압축된 문자열을 압축해제 하여 값을 반환

문제 해결 방안:
1. 반복 횟수를 만들 인티저 스택을 만든다
	- 숫자가 나오면 스택에 푸쉬한다.  
2. 문자열을 받을 스택을 만든다. 
3. 닫는 괄호가 나오면, 
	-여는 괄호가 나올 때 까지 캐릭터 스택으로부터
	 문자를 팝 하면서 임시 스트링에 담는다.
	- 인티저 스택에 있는 숫자 만큼, 임시스트링 배열을 반복한다. 
4. 여는 괄호가 나오면 팝한다. 
5. 캐릭터 스택으로 다시 answer에 있는 문자를 다시 푸쉬한다. 
6. 문자는 그냥 푸쉬 ! 


*/
#include <iostream>
#include <cstdio>
#include <stack> 
using namespace std; 

string solution(string compressed) 
{ 
	stack<int> integerstack; 
	stack<char> stringstack; 
	string temp = "", answer = ""; 

	// 문자열 탐색
	for (int i = 0; i < compressed.length(); i++) 
	{ 
		int count = 0; 

		// 만약 숫자면 인트형 숫자로 변환
		// 푸쉬백 인티저스택 
		if (compressed[i] >= '0' && compressed[i] <='9') 
		{ 
			while (compressed[i] >= '0' && compressed[i] <= '9') 
			{ 
				count = count * 10 + compressed[i] - '0'; 
				i++; 
			} 

			i--; 
			integerstack.push(count); 
		} 
		// 만약 여는 괄호 나오면 문자열 스택에 푸쉬! 
		else if (compressed[i] == '(') 
		{ 
			if (compressed[i-1] >= '0' && compressed[i-1] <= '9') 
				stringstack.push(compressed[i]); 

			else
			{ 
				stringstack.push(compressed[i]); 
				integerstack.push(1); 
			} 
		} 
		// 만약 닫는 괄호 나오면, 여는 괄호 나올때 까지 팝 
		// 여는 괄호 나올때 까지 팝한다!  
		else if (compressed[i] == ')') 
		{ 
			temp = ""; 
			count = 0; 

			if (! integerstack.empty()) 
			{ 
				count = integerstack.top(); 
				integerstack.pop(); 
			} 

			while (! stringstack.empty() && stringstack.top()!='(' ) 
			{ 
				temp = stringstack.top() + temp; 
				stringstack.pop(); 
			} 

			if (! stringstack.empty() && stringstack.top() == '(') 
				stringstack.pop(); 

			//팝 된 문자열열을 반복! 카운트만큼! 
			for (int j = 0; j < count; j++) 
				answer = answer + temp; 

			// 캐릭터스택으로 푸쉬!!
			for (int j = 0; j < answer.length(); j++) 
				stringstack.push(answer[j]); 

			answer = ""; 
		} 

		else
			stringstack.push(compressed[i]); 
	} 

	// 모든 데이터를 팝하고, 문자열을 만들어 리턴 
	while (! stringstack.empty()) 
	{ 
		answer = stringstack.top() + answer; 
		stringstack.pop(); 
	} 

	return answer; 
} 
 
int main() 
{ 
	string compressed = "";
	cin>>compressed;
	cout << solution(compressed) << endl; 
	return 0; 
} 
