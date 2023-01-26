#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    long long x[max(7, n+1)];
    x[0] = 0;
    x[1] = 1;
    x[2] = 2;
    x[3] = 4;
    x[4] = 8;
    x[5] = 16;
    x[6] = 32;

    for(int i = 7; i <= n; i++)
    {
        x[i] = 0;
        for(int j = 1; j <= 6; j++)
        {
            x[i] = (x[i]+x[i-j])%1000000007;
        }
    }

    cout << x[n];

    return 0;
}
