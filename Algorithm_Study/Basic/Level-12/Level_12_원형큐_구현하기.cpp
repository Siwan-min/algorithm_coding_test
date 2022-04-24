#include <stdio.h>
#define MAX 105
int data[MAX];
int n, m, cnt, f, r;
int main()
{

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {

        int a, b;
        scanf("%d", &a);
        if (a == 1)
        {
            scanf("%d", &b);
            if (cnt >= n)
                printf("Overflow\n");
            else
            {
                data[r] = b;
                if (r == n - 1)
                    r = 0;
                else
                    r++;
                cnt++;
            }
        }
        else if (a == 2)
        {
            if (cnt == 0)
                printf("Underflow\n");
            else
            {
                data[f] = 0;
                if (f == n - 1)
                    f = 0;
                else
                    f++;
                cnt--;
            }
        }

        else
        {
            if (cnt <= 0)
                printf("NULL\n");
            else
                printf("%d\n", data[f]);
        }
    }

    return 0;
}