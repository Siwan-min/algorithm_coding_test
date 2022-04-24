#include <stdio.h>
 
int main(void){
    int N;
    int Dp[1010] = {};
    int A[1010] = {};
    int max = 0;
    scanf("%d", &N);
 
    for (int i = 1; i <= N; i++)
        scanf("%d", &A[i]);
 
    for (int i = 1; i <= N; i++)
    {
        int maxDp = 0;
        for (int j = 0; j < i; j++){
            if (A[i]>A[j]){
                if (maxDp < Dp[j])
                    maxDp = Dp[j];
            }
        }
        Dp[i] = maxDp + A[i];
        if (max < Dp[i])
            max = Dp[i];
    }
 
    printf("%d\n", max);
 
}

