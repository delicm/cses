#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector <int> v;
    int pow2[n+1][32];
    v.resize(n+1);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &v[i]);
        pow2[i][0] = v[i];
    }

    for(int i = 1; i <= 31; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            pow2[j][i] = pow2[pow2[j][i-1]][i-1];
        }
    }

    for(int i = 1; i <= q; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        for(int i = 0; i < 32; i++)
        {
            if(b&(1 << i))
            {
                a = pow2[a][i];
            }
        }
        cout << a <<endl;
    }

    return 0;
}
