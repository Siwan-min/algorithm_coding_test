#include <stdio.h>
int main()
{
    int n, s = 0, k;
    int arr[1010];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &k);
        arr[k]++;
        if (k > s)
        {
            s = k;
        }
    }
    int m = 0;
    for (int i = 1; i <= s; i++)
    {
        if (s == 3 && arr[i] >= 2)
        {
            m++;
        }
        else if (s == 4 && arr[i] == 2)
        {
            m++;
        }
        else if (s == 5 && arr[i] == 2)
        {
            m++;
        }
    }
    if (s == 3 && m >= 3)
    {
        printf("YES");
    }
    else if (s == 4 && m >= 2)
    {
        printf("YES");
    }
    else if (s == 5 && m >= 1)
    {
        printf("YES");
    }
    else if (s > 5)
    {
        printf("YES");
    }
    else if (s < 3)
        printf("NO");
    else
    {
        printf("NO");
    }
    return 0;
}