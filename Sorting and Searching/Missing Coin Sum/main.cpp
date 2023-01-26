#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long int

vector <int> c;

int32_t main()
{
    int n; cin >> n;

    c.resize(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    c.push_back(0);
    sort(c.begin(), c.end());
    int t = 0;

    for(int i = 1; i <= n; i++)
    {
        if(c[i] > t+1)
        {
            cout << t+1;
            return 0;
        }
        else t+=c[i];
    }

    cout << t+1;

    return 0;
}
