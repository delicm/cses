#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;

    pair <int, bool> x[2*n];

    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        x[2*i] = make_pair(a, 0);
        x[2*i+1] = make_pair(b, 1);
    }

    sort(x, x+2*n);

    int m=0, t=0;

    for(int i = 0; i < 2*n; i++)
    {
        if(x[i].second == 0)
        {
            t++;
            m=max(m,t);
        }
        else
        {
            t--;
        }
    }

    cout << m;

    return 0;
}
