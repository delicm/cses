#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<pair<long long, long long>> v(n+1);
    for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    v[n] = v[0];

    long long ans = 0;
    for(int i = 0; i < n; i++) ans += (v[i].first*v[i+1].second-v[i].second*v[i+1].first);

    cout << abs(ans);

    return 0;
}
