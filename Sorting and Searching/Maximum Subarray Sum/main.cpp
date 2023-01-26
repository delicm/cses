#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    long long x[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%lld", &x[i]);
    }

    long long y[n], m = x[0];
    y[0]=x[0];

    for(int i = 1; i < n; i++)
    {
        y[i]=max(x[i], x[i]+y[i-1]);
        m=max(m, y[i]);
    }
    cout << m;
    return 0;
}
