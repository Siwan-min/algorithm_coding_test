/*
합병정렬: 배열을 절반으로 나누어 각각을 정렬한 수 합친다. 
 
시간 복잡도: nlog(n)
*/
 
#include <stdio.h>
 
void merging(int arr[], int s1, int e1, int s2, int e2){
    // arr의 s1 ~ e1이 왼쪽 절반, s2 ~ e2가 오른쪽 절반일 때,
    // 이 둘을 합쳐서 arr의 s1 ~ e2를 정렬된 결과로 만드는 함수
 
    // 1 2 4 8        3 4 6 7
    // temp 배열에 정렬된 값을 넣어준다. 
 
    int p, q; // p와 q의 현재 최솟값을 가리키는 변수들
    int temp[100005]; // 합쳐진 결과를 저장하는 임시변수
    int temp_inx = 0;
 
    p = s1, q = s2;
 
    // 1 2 4 8  2 2 3 3
    // p                q
 
    while(p <= e1 && q <= e2){
 
        if(arr[p] <= arr[q]){
            temp[temp_inx++] = arr[p];
            p++;
        }
        else{
            temp[temp_inx++] = arr[q];
            q++;
        }
    }
 
    if(p > e1){
        for(int i = q; i <= e2; i++){
            temp[temp_inx++] = arr[i];
        }
    }
    else{
        for(int i = p; i <= e1; i++){
            temp[temp_inx++] = arr[i];
        }
    }
    // temp는 완성 되었으니
    // arr[s1 ~ e2] 까지에 temp의 값을 복사
    for(int i = s1; i <= e2; i++)
        arr[i] = temp[i-s1];
}
 
void mergeSort(int arr[], int start, int end){
    // arr의 start부터 end까지 합병정렬하는 함수
 
    if(start>=end) return ;
    else{
        /*
        1. 왼쪽 절반을 합병정렬
        2. 오른쪽 절반을 합병정렬
        3. 그 둘을 합친다. 
        */
        int mid = (start+end)/2;
 
 
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
 
        // arr(start ~ mid), arr[mid+1 ~ end]는 정렬이 이미 되어있음
 
        merging(arr, start, mid, mid+1, end);
    }
}
 
int main(){
 
    int n; 
    int numbers[100005];
 
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &numbers[i]);
    }
 
    mergeSort(numbers, 0, n-1);
 
    for(int i = 0; i < n; i++)
        printf("%d ", numbers[i]);
 
    return 0;
}
