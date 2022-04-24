#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 노드 정의
typedef struct Node {
	char data[100];
	struct Node* next;
} Node;

// 스택 정의(top)
typedef struct Stack {
	Node* top;
} Stack;

// push 함수 정의
void push(Stack* stack, char *data) {
	Node* node = (Node*)malloc(sizeof(Node)); // 메모리 동적할당
	strcpy(node->data, data);          // 노드의 데이터에 문자열 복사
	node->next = stack->top;           // 노드의 다음을 현 스택의 탑을 가리킴
	stack->top = node;                 // 현 스택의 탑을 추가하는 노드로 변경
}

char* getTop(Stack* stack) {
	Node* top = stack->top;
	return top->data;
}

char* pop(Stack* stack) {
	if (stack->top == NULL) {
		printf("Stack underflow");
		return NULL;
	}
	Node* node = stack->top;                          // 스택 최상단(top)을 임시 노드에 담음
	char* data = (char*)malloc(sizeof(char) * 100);   // data 메모리 동적 할당
	strcpy(data, node->data);                         // 임시 노드(top)의 데이터(문자열)를 data에 복사
	stack->top = node->next;                          // 임시 노드(top)의 다음 노드를 top으로 가리킴
	free(node);              // 최상단 노드 메모리 해제
	return data;
}

int getPriority(char* i) {
	if (!strcmp(i, "(")) return 0;
	if (!strcmp(i, "+") || !strcmp(i, "-")) return 1;
	if (!strcmp(i, "*") || !strcmp(i, "/")) return 2;
}

// 중위표기법을 후위표기법으로 변환하기 위한 stack
// 수식을 문자열로 받아들이기 위한 s      ex) 3 + 5 --> "3", "+", "5"
// 문자열의 개수를 알려주는 size          ex) 위의 경우 3개
char* transition(Stack* stack, char** s, int size) {
	char res[1000] = "";             // 후위표기법으로 바뀐 문자열이 담길 공간
	for (int i = 0; i < size; i++) {
		if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/")) {
			while (stack->top != NULL && getPriority(getTop(stack)) >= getPriority(s[i])) {
				strcat(res, pop(stack)); strcat(res, " ");
			}
			push(stack, s[i]);
		}
		else if (!strcmp(s[i], "(")) push(stack, s[i]);
		else if (!strcmp(s[i], ")")) {
			while (strcmp(getTop(stack), "(")) {
				strcat(res, pop(stack)); strcat(res, " ");
			}
			pop(stack);
		}
		else { strcat(res, s[i]); strcat(res, " "); }
	}
	while (stack->top != NULL) {
		strcat(res, pop(stack)); strcat(res, " ");
	}
	return res;
}

// 3 5 + ==> "3", "5", "+"
void calculate(Stack* stack, char** s, int size) {
	int x, y, z;
	for (int i = 0; i < size; i++) {
		if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/")) {
			x = atoi(pop(stack));
			y = atoi(pop(stack));              // 스택에서 두 수를 뽑아 연산, y가 먼저 들어간 원소
			if (!strcmp(s[i], "+")) z = y + x;
			if (!strcmp(s[i], "-")) z = y - x;
			if (!strcmp(s[i], "*")) z = y * x;
			if (!strcmp(s[i], "/")) z = y / x;
			char buffer[100];
			sprintf(buffer, "%d", z);          // 계산 결과를 문자열로 다시 변환
			push(stack, buffer);               // 연산 결과를 다시 스택에 넣음
		}
		else {
			push(stack, s[i]);
		}
	}
	printf("%s\n", pop(stack));               // 마지막 결과값 출력
}

int main(void) {
	Stack stack;
	stack.top = NULL;
	char a[100] = "( ( 3 + 4 ) * 5 ) - 5 * 7 * 5 - 5 * 10";
	int size = 1;
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == ' ') size++; // 공백을 만날 때 마다 size 1씩 추가, 즉 문자열의 개수 세기
	}

	char* ptr = strtok(a, " "); // 공백을 기준으로 문자열을 하나의 토큰으로 변환
	char** input = (char**)malloc(sizeof(char*) * size);
	for (int i = 0; i < size; i++) {
		input[i] = (char*)malloc(sizeof(char) * 100);
	}

	for (int i = 0; i < size; i++) {
		strcpy(input[i], ptr);
		ptr = strtok(NULL, " ");
	}                           // 여기까지 각각의 문자들이 input에 문자열 형태로 변환

	char b[1000] = "";
	strcpy(b, transition(&stack, input, size));  // 후위 표기법으로 변환
	printf("후위 표기법 : %s\n", b);

	size = 1;
	for (int i = 0; i < strlen(b) - 1; i++) { // 후위 표기법의 마지막은 항상 공백이 있어 제거(-1)
		if (b[i] == ' ') size++;
	}

	char* ptr2 = strtok(b, " ");
	for (int i = 0; i < size; i++) {
		strcpy(input[i], ptr2);
		ptr2 = strtok(NULL, " ");
	}
	calculate(&stack, input, size);
//	system("pause");
	return 0;
}