#include <iostream>

using namespace std;

int main()
{
    int n, x; cin >> n >> x;
    int c[n];
    for(int i = 0; i < n; i++) cin >> c[i];

    long long s[x+1];
    s[0]=1;

    for(int i = 1; i <= x; i++)
    {
        s[i]=0;
        for(int j = 0; j < n; j++)
        {
            if(i >= c[j])
            {
                s[i] += s[i-c[j]];
                s[i] %= 1000000007;
            }
        }
    }

    /*for(int i = 0; i < x; i++)
    {
        cout << s[i] << " ";
    }*/

    cout << s[x];

    return 0;
}
