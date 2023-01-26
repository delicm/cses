#include <iostream>
#include <cmath>

using namespace std;

int n = 1;
bool a[16];
int S[200000];

void printa()
{
    for(int i = 0; i < n; i++) cout << a[i];
    cout << endl;
}

void init()
{
    int k = 1;
    S[0] = 0;
    S[1] = 0;

    while(k <= n)
    {
        int t = pow(2,k);
        S[t] = k;
        for(int i = t+1; i < 2*t; i++)
        {
            S[i] = S[2*t-i];
        }
        k++;
    }
}

void solve()
{
    printa();
    for(int i = 1; i < pow(2, n); i++)
    {
        a[S[i]] = !a[S[i]];
        printa();
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < 16; i++) a[i] = 0;
    init();
    solve();

    return 0;
}
