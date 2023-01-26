#include <iostream>
#include <cmath>
#include <tuple>

#define int long long int

using namespace std;

int w[19];

void init()
{
    w[0] = 0;
    for(int i = 1; i < 19; i++)
        w[i] = w[i-1] + 9*pow(10, i-1)*i;
}

int solve(int q)
{
    int d = 0;
    int N = 0;
    for(int i = 0; i < 19; i++)
    {
        if(w[i] <= q)
        {
            d = i;
            N = pow(10, d)-1;
        }
        else
            break;
    }
    q -= w[d];
    N += q/d;
    int r = q%d;

    if(r == 0) return N % 10;
    N++;
    int s = N/pow(10, d-r);
    return s%10;
}

int32_t main()
{
    int n; cin >> n;
    init();

    while(n--)
    {
        int q; cin >> q;
        cout << solve(q) << endl;
    }

    return 0;
}
