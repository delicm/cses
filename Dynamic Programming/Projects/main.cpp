#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, temp = 0; cin >> n;

    vector <long long> a(n);
    vector <long long> p(n);
    vector <pair <long long, int> > s;
    map <long long, long long> m;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> temp >> p[i];
        s.push_back(make_pair(temp, i));
    }

    s.push_back(make_pair(0, n));
    sort(s.begin(), s.end());
    m[0] = 0;

    for(int i = 0; i <= n; i++)
    {
        m[s[i].first] = 0;
    }

    for(int i = 1; i <= n; i++)
    {
        auto k = lower_bound(s.begin(), s.end(), make_pair(a[s[i].second], 0));
        k--;
        m[s[i].first] = max(m[s[i-1].first], m[(*k).first]+p[s[i].second]);
    }

    cout << m[s[n].first];

    return 0;
}
