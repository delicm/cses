#include <bits/stdc++.h>

using namespace std;

int n, N = 1, m;
vector <int> stree;

void supdate(int k, int u)
{
    k += N;
    stree[k] = u; k /= 2;
    while(k >= 1)
    {
        stree[k] = stree[2*k]+stree[2*k+1];
        k /= 2;
    }
}

void init()
{
    cin >> n >> m;
    while(N < n) N *= 2;
    stree.resize(2*N, 0);

    for(int i = 0; i < n; i++)
    {
        int k; cin >> k;
        supdate(i, )
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
