#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n;
    vector <int> d;

    for(int i = 0; i < n; i++)
    {
        cin >> x;
        auto j = lower_bound(d.begin(), d.end(), x);
        if(j == d.end())
        {
            d.push_back(x);
        }
        else
        {
            *j = x;
        }

    }

    cout << d.size();

    return 0;
}
