#include <iostream>
#include <algorithm>

using namespace std;

bool comp(pair <int, int> x, pair <int, int> y)
{
    if(x.second == y.second) return x.first>y.first;
    return x.second < y.second;
}

int main()
{
    int n;
    cin >> n;

    pair <int, int> x[n];

    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        x[i] = make_pair(a,b);
    }

    sort(x, x+n, comp);

    int m=1, t=x[0].second;

    for(int i = 1; i < n; i++)
    {
        if(x[i].first >= t)
        {
            m++;
            t=x[i].second;
        }
    }

    cout << m;

    return 0;
}
