#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int n; cin >> n;
    long long s = 0, m= -1;
    while(n--)
    {
        long long x; cin >> x;
        s+=x;
        m=max(m,x);
    }

    if(m > s-m) cout << 2*m;
    else cout << s;

    return 0;
}
