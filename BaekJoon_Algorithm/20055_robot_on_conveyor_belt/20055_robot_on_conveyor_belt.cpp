#include <iostream>
#include <deque>

using namespace std;

int n, k, x;
int ans = 0;

struct INFO
{
    int value;
    bool robot;
};


deque<INFO> belt;

int find()
{
    int zeroCount = 0;
    for(int i = 0 ; i < belt.size(); i++)
    {
        if (belt[i].value == 0) zeroCount++;
    }

    return zeroCount;
}

void solve()
{

    while(1)
    {
        if(find() >= k) break;
        ans++;

        belt.push_front({belt.back().value, belt.back().robot});
        belt.pop_back();

        if(belt[n-1].robot) belt[n-1].robot = false;

        for(int i = n-2; i >= 0; i--)
        {
            if(!belt[i+1].robot && belt[i].robot && belt[i+1].value > 0 )
            {
                belt[i].robot = false;
                belt[i+1].value--;
                
                if(i == n-2) continue;

                belt[i+1].robot = true;
                
            }
        }

        if(belt[0].value > 0 && !belt[0].robot )
        {
            belt[0].value--;
            belt[0].robot = true;
        }
    }
}

int main()
{
    cin>>n>>k;

    for(int i = 0; i < 2*n; i++)
    {
        cin>>x;
        belt.push_back({x, false});
    }

    solve();

    cout << ans << endl;

    return 0;
}