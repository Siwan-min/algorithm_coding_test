#include <stdio.h>
#include <stack>
using namespace std;

int sum, tmp = 1;
char data[33];
stack<char> myStack;

int main() {
    scanf("%s", data + 1);

    for (int i = 1; data[i]; i++) {
        switch (data[i]) {
        case '(':
            tmp *= 2, myStack.push('('); break;
        case '[':
            tmp *= 3, myStack.push('['); break;
        case ')':
            if (data[i - 1] == '(') sum += tmp;
            if (myStack.empty()) return !printf("0");
            if (myStack.top() == '(') myStack.pop();
            tmp /= 2; break;
        case ']':
            if (data[i - 1] == '[') sum += tmp;
            if (myStack.empty()) return !printf("0");
            if (myStack.top() == '[') myStack.pop();
            tmp /= 3;
        }
    }


    printf("%d", myStack.empty() ? sum : 0);

    return 0;
}