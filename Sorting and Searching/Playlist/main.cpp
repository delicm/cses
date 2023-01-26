#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >>n;
    pair <int, int> x[n];
    //int z[n];
    int y[n];
    //int w[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x[i].first);
        //z[i]=x[i].first;
        x[i].second = i;
    }

    sort(x, x+n);
    y[x[0].second] = 200001;
    for(int i = 1; i < n; i++)
    {
        if(x[i].first == x[i-1].first)
        {
            y[x[i].second] = x[i].second - x[i-1].second;
        }
        else
        {
            y[x[i].second] = 200001;
        }
    }

    /*for(int i = 0; i<n; i++)
    {
        cout << y[i] << " ";
    }*/

    int a = 1;
    int m = 1;

    for(int i = 1; i < n; i++)
    {
        a = min(a+1, y[i]);
        m=max(m, a);
    }

    cout << m;

    return 0;
}
