#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long int

int32_t main()
{
    int t; cin >> t;
    vector <pair <int, int>> s;
    vector <int> sol;
    sol.resize(t);

    for(int i = 0; i < t; i++)
    {
        int k; cin >> k;
        s.push_back({k, i});
    }

    sort(s.begin(), s.end());

    int n = 1000005;
    int mod = 1000000007;

    int x = 1, y = 1, cnt = 0;

    while(1 == s[cnt].first)
    {
        sol[s[cnt].second] = (x+y)%mod;
        cnt++;
    }

    for(int i = 2; i < n; i++)
    {
        int temp = x;
        x = (2*x+y)%mod;
        y = (4*y+temp)%mod;
        while(i == s[cnt].first)
        {
            sol[s[cnt].second] = (x+y)%mod;
            cnt++;
        }
    }

    for(int i = 0; i < t; i++) cout << sol[i] << endl;

    return 0;
}
