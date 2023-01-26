#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int findd(vector < pair <int, int> > x, int k, int a1, int b1)
{
    int a = a1, b = b1;
    while(a<=b)
    {
        int o = (a+b)/2;
        if(x[o].first == k)
        {
            return x[0].second;
        }
        if(x[o].first < k) a=o+1;
        else b=o-1;
    }
    return -1;

}

int main()
{
    int n, t;
    cin >> n >> t;
    vector < pair <int, int> > x(n);
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        x[i] = make_pair(temp, i);
    }

    sort(x.begin(), x.end());

    int a = 0, b = n-1;
    bool ind = true;
    while(a < b)
    {
        if(x[a].first+x[b].first == t)
        {
            cout << x[a].second + 1 << " " << x[b].second + 1;
            ind = false;
            break;
        }
        if(x[a].first+x[b].first > t)
        {
            b--;
        }
        else
        {
            a++;
        }
    }
    if(ind) cout << "IMPOSSIBLE";
    return 0;
}
