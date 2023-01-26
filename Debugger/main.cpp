#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector < pair <int, int> > v(2);
    pair <int, int> p;

    while(true)
    {
        cin >> v[0].first >> v[0].second;
        cin >> v[1].first >> v[1].second;
        cin >> p.first >> p.second;

        auto k = lower_bound(v.begin(), v.end(), p);
        cout << (*k).first << " " << (*k).second << endl;
    }
    return 0;
}
