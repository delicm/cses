#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;
    int x[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }

    sort(x, x+n);

    long long k = x[n/2], m = 0;

    for(int i = 0; i < n; i++)
    {
        m = m+abs(x[i]-k);
    }
    cout << m;
    return 0;
}
