#include <bits/stdc++.h>

using namespace std;
#define int long long int

int n, N = 1, m;
vector <tuple<int, int, int, int>> tree;

bool ifLeft(int p)
{
    while(p > 1)
    {
        if(p % 2 == 1) return false;
        else p /= 2;
    }
    return true;
}

bool ifRight(int p)
{
    return ifLeft(p+1);
}

void update(int k, int x)
{
    k += N;
    tree[k] = make_tuple(x, x, k, k); k /= 2;
    int p = 1;
    while(k >= 1)
    {
        int left1 = get<0>(tree[2*k]), left2 = get<0>(tree[2*k+1]), right1 = get<1>(tree[2*k]), right2 = get<1>(tree[2*k+1]);
        if(left1 <= left2 + p)
        {
            get<0>(tree[k]) = left1;
            get<2>(tree[k]) = get<2>(tree[2*k]);
        }
        else
        {
            get<0>(tree[k]) = left2+p;
            get<2>(tree[k]) = get<2>(tree[2*k+1]);
        }

        if(right1 + p <= right2)
        {
            get<1>(tree[k]) = right1+p;
            get<3>(tree[k]) = get<3>(tree[2*k]);
        }
        else
        {
            get<1>(tree[k]) = right2;
            get<3>(tree[k]) = get<3>(tree[2*k+1]);
        }
        k /= 2; p *= 2;
    }
}

int findMin(int k)
{
    k += N; k--;
    int minn = get<0>(tree[k]);

    int p = k-1;
    while(!ifLeft(p))
    {
        if(p % 2 == 1) p /= 2;
        else
        {
            int newpos = get<3>(tree[p]);
            minn = min(get<1>(tree[newpos])+abs(newpos-k), minn);
            p--;
        }
    }

    if(p != 1)
    {
        int newposFinalLeft = get<3>(tree[p]);
        minn = min(get<1>(tree[newposFinalLeft])+abs(newposFinalLeft-k), minn);
    }

    p = k+1;
    while(!ifRight(p))
    {
        if(p % 2 == 0) p /= 2;
        else
        {
            int newpos = get<2>(tree[p]);
            minn = min(get<0>(tree[newpos])+abs(newpos-k), minn);
            p++;
        }
    }

    if(p != 1)
    {
        int newposFinalRight = get<2>(tree[p]);
        minn = min(get<0>(tree[newposFinalRight])+abs(newposFinalRight-k), minn);
    }

    return minn;
}

int inithelp(int k, bool b)
{
    if(b)
    {
        while(k < N) k *= 2;
        return k;
    }
    else
    {
        while(k < N) k = 2*k+1;
        return k;
    }
}

void init()
{
    cin >> n >> m;
    while(n > N) N *= 2;
    tree.resize(2*N);
    tree[0] = make_tuple(INT_MAX, INT_MAX, N, N);
    for(int i = 1; i < 2*N; i++)
        tree[i] = make_tuple(INT_MAX, INT_MAX, inithelp(i, 1), inithelp(i, 0));

    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        update(i, x);
    }

}

void querie()
{
    int q; cin >> q;
    if(q == 1)
    {
        int k, x; cin >> k >> x;
        update(k-1, x);
    }
    else
    {
        int k; cin >> k;
        cout << findMin(k) << endl;
    }
}

int32_t main()
{
    init();
    while(m--)
        querie();
    return 0;
}
