/*
알고리즘 구현 문제
큰 자릿수 뺄셈
 
인트형 범위를 초과하는 큰 숫자는 연산이 불가능하다. 
문제 해결 방안:
 
1. 임시 배열에 숫자를 문자열로 받는다. 
2. first[] 배열에 앞 부분이 아니라 뒷 부분이 채워지게 받는다. 
    -> 000123245
3. second[] 배열도 똑같은 방법을 수행한다.
4. first배열과 second 배열의 길이를 비교하여 대소를 비교한다.
    - 첫 번째가 크면 양수, 두 번째가 크면 음수라는 것을 표현하기 위해 
        compare 변수를 만들고, 양수면 0, 음수면 1, 같으면 -1 을 설정한다. 
 
5. 큰 것을 big[]배열에 작은 것을 small[] 배열에 넣는다. 
6. 뒷 자리부터 뺄셈을 진행 
    - big[inx]의 숫자가 small[inx]의 숫자보다 작으면 big[inx-1]를 1 빼고
    big[inx]를 10 더해준다.
    - 뺀 결과를 result[] 배열에 저장한다.
7. 음수, 양수 여부를 확인 한 뒤 결과 값을 출력한다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
 
int main() {
    freopen("input.txt", "r", stdin);
    
    char temp[105];
    int big[105] = { 0, }, small[105] = { 0, };
    int first[105] = { 0, }, second[105] = { 0, };
    int firstLen, secondLen;
    int bigLen, smallLen;
    int result[105] = { 0, };
 
    scanf("%s", temp);
    firstLen = strlen(temp);
 
    for (int i = 0; i < firstLen; i++)
        first[104 - firstLen + i + 1] = temp[i] - '0';
 
    scanf("%s", temp);
    secondLen = strlen(temp);
    for (int i = 0; i < secondLen; i++)
        second[104 - secondLen + i + 1] = temp[i] - '0'; //문자열을 정수형으로 받음
 
    int compare = -1; // 출력 시 음수, 양수 여부를 가리기 위해 
    if (firstLen > secondLen) compare = 0;
    else if (firstLen < secondLen) compare = 1;
    else {
        for (int i = 0; i < 105; i++) {
            if (first[i] > second[i]) {
                compare = 0;
                break;
            }
            else if (first[i] < second[i]) {
                compare = 1;
                break;
            }
        }
    }
 
    for (int i = 0; i < 105; i++) {
        if (compare == 0) { // 양수
            big[i] = first[i];
            small[i] = second[i];
        }
        else if (compare == 1) { //음수
            big[i] = second[i];
            small[i] = first[i];
        }
        else { //같으면 0을 출력하고 종료한다. 
            printf("0\n");
            return 0;
        }
    }
 
    // 뒷 자리부터 계산을 한다. 
    for (int i = 104; i >= 0; i--) {
        if (big[i] >= small[i]) result[i] = big[i] - small[i];
        else {
            big[i - 1]--;
            big[i] += 10;
 
            result[i] = big[i] - small[i];
        }
    }
 
    if (compare == 1) printf("-");
 
    for (int i = 0; i < 105; i++) {
        if (result[i] != 0) { // 0이 아닌 순간부터 출력!
            for (int j = i; j < 105; j++) printf("%d", result[j]);
 
            printf("\n");
            return 0;
        }
    }
}
