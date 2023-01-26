#include <bits/stdc++.h>

using namespace std;
#define int long long int

int n, N = 1, m;
vector <int> vals;
vector <int> ftree;
vector <int> mintree;
vector <int> maxtree;
vector <int> mergetree;

int sum(int k)
{
    if(k == 0) return 0;
    int s = 0;
    while(k >= 1)
    {
        s += ftree[k];
        k -= k & -k;
    }
    return s;
}

void updateF(int k, int u)
{
    int x = u - vals[k];
    int ktemp = k;
    while(k <= N)
    {
        ftree[k] += x;
        k += k & -k;
    }
    vals[ktemp] = u;
}

void updateMinMax(int k)
{
    k += N;
    int s = sum(k-N);
    mintree[k] = s;
    maxtree[k] = s+vals[k-N+1];
    k /= 2;

    while(k >= 1)
    {
        mintree[k] = min(mintree[2*k], mintree[2*k+1]);
        maxtree[k] = max(maxtree[2*k], maxtree[2*k+1]);
        k /= 2;
    }

}

void updateMerge(int k)
{
    k += N;
    mergetree[k] = vals[k-N+1]; k /= 2;
    while(k >= 1)
    {
        mergetree[k] = max(maxtree[2*k+1]-mintree[2*k], max(mergetree[2*k+1], mergetree[2*k]));
        k /= 2;
    }
}

void update(int k, int u)
{
    updateF(k+1, u);
    updateMinMax(k);
    updateMerge(k);
}

void init()
{
    cin >> n >> m;
    while(n > N) N *= 2;
    vals.resize(N+1, 0);
    ftree.resize(N+1, 0);
    mintree.resize(2*N, INT_MAX);
    maxtree.resize(2*N, INT_MIN);
    mergetree.resize(2*N, INT_MIN);

    for(int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        updateF(i, x);
    }

    for(int i = N; i < 2*N; i++)
    {
        mintree[i] = sum(i-N);
        maxtree[i] = sum(i-N+1);
        mergetree[i] = vals[i-N+1];
    }

    for(int i = 0; i < N; i++)
        updateMinMax(i);
    for(int i = 0; i < N; i++)
        updateMerge(i);
}

int32_t main()
{
    init();
    cout << sum(N-1) << endl;
     for(int i = 1; i < 2*N; i++)
        {
            cout << mintree[i] << " ";
        }
        cout << endl;

    while(m--)
    {

        int a, b; cin >> a >> b;
        update(a-1, b);
        cout << sum(N-1) << endl;

        for(int i = 1; i < 2*N; i++)
        {
            cout << mintree[i] << " ";
        }
        cout << endl;

        cout << mergetree[1] << endl;
    }
    return 0;
}
