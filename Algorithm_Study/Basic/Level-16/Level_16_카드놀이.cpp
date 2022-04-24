#include <iostream>

using namespace std;

const int MAX = 100005;
int n;
int arr[MAX] = {
    0,
};
int t[MAX] = {
    0,
};

int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (n > 3)
    {
        t[0] = arr[0];
        t[1] = arr[0] + arr[1];

        if (arr[0] > arr[1])
        {
            t[2] = arr[0] + arr[2];
        }
        else
        {
            t[2] = arr[1] + arr[2];
        }
    }

    int a = 0, b = 0, c = 0;
    int max;
    for (int i = 3; i < n; i++)
    {
        a = t[i - 1];
        b = t[i - 2] + arr[i];
        c = t[i - 3] + arr[i - 1] + arr[i];

        if (a >= b && a >= c)
        {
            max = a;
        }
        else if (b >= a && b >= c)
        {
            max = b;
        }
        else
        {
            max = c;
        }

        t[i] = max;
    }

    cout << t[n - 1];

    return 0;
}
