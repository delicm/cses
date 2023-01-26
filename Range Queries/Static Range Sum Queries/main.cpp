#include <iostream>
#define int long long int

using namespace std;

int32_t main()
{
    int n, q;
    cin >> n >> q;

    int x[n+1];
    int s[n+1];
    x[0] = 0;
    s[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        cin >> x[i];
        s[i] = s[i-1]+x[i];
    }

    while(q--)
    {
        int a, b;
        cin >> a >> b;
        cout << s[b]-s[a-1] << endl;
    }

    return 0;
}
