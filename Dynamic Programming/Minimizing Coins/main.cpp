#include <iostream>

using namespace std;

int main()
{
    int n, x; cin >> n >> x;
    int c[n];
    for(int i = 0; i < n; i++) cin >> c[i];

    long long m[x+1];
    m[0] = 0;

    for(int i = 1; i <=x; i++)
    {
        m[i] = 1000001;
        for(int j = 0; j < n; j++)
        {
            if(i >= c[j])
            {
                m[i] = min(m[i], 1+m[i-c[j]]);
            }
        }
    }
    if(m[x]==1000001)
    {
        cout << -1;
        return 0;
    }
    cout << m[x];

    return 0;
}
