#include <iostream>

using namespace std;

int main()
{
    int n, x; cin >> n >> x;
    int w[n];
    for(int i = 0; i < n; i++) cin >> w[i];

    pair <int, int> opt[(1<<n)];
    opt[0] = {1, 0};

    for(int s = 1; s < (1<<n); s++)
    {
        opt[s] = {n+1, 0};
        for(int i = 0; i < n; i++)
        {
            if(s&(1<<i))
            {
                auto prev = opt[s^(1<<i)];
                pair <int, int> temp;
                if(prev.second + w[i] <= x) temp = {prev.first, prev.second+w[i]};
                else temp = {prev.first+1, w[i]};
                opt[s] = min(opt[s], temp);
            }
        }
    }

    cout << opt[(1<<n)-1].first;

    return 0;
}
