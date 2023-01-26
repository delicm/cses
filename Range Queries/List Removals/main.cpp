#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> tree;
vector <int> a;
vector <bool> seen;

void skip(int k, int u)
{
    while(k <= n)
    {
        tree[k] += u;
        k += k & -k;
    }
}

int skipped(int k)
{
    int s = 0;
    while(k >= 1)
    {
        s += tree[k];
        k -= k & -k;
    }
    return s;
}

int posAtK(int k)
{
    return k - skipped(k);
}

int findpos(int p)
{
    int a = 1, b = n+1;
    while(true)
    {
        int c = (a+b)/2;
        int pp = posAtK(c);
        if(seen[c])
        {
            if(pp >= p)
            {
                b = c; continue;
            }
            else
            {
                a = c;
                continue;
            }
        }
        else
        {
            if(pp == p) return c;
            else if(pp > p) b = c;
            else a = c;
        }
    }
    return 0;
}

void init()
{
    cin >> n;
    tree.resize(n+1, 0);
    a.resize(n+1, 0);
    seen.resize(n+1, false);

    for(int i = 1; i <= n; i++)
        cin >> a[i];

}

int main()
{
    init();
    for(int i = 0; i < n; i++)
    {
        int p; cin >> p;
        int k = findpos(p);
        cout << a[k] << endl;
        seen[k] = 1;
        skip(k, 1);
    }

    return 0;
}
