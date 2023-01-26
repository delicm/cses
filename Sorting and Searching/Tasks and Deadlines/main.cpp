#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    long long d = 0;
    cin >> n;
    int x[n];
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        x[i]= a;
        d+=b;
    }

    sort(x, x+n);
    long long t = 0, m = 0;
    for(int i = 0; i < n; i++)
    {
        t+=x[i];
        m+=t;
    }

    cout << d - m;

    return 0;
}
