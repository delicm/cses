#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, x; cin >> n >> x;
    int c[n];
    for(int i = 0; i < n; i++) cin >> c[i];

    //sort(c, c+n);

    long long s[x+1];

    for(int i = 0; i <= x; i++)
    {
        s[i] = 0;
    }

    s[0] = 1;

    for(int i = 0; i<n; i++)
    {
        for(int j = 1; j <= x; j++)
        {
            if(j >= c[i]) s[j] = (s[j] + s[j-c[i]])%1000000007;
        }
    }

    cout << s[x];

    return 0;
}
