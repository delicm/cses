#include <iostream>
#include <algorithm>

using namespace std;

int p1, p2, p3;

bool check2(int pf, int k, pair <int, int> a[])
{
    int l=0, r=pf-1;
    while(l<r)
    {
        if(a[l].first+a[r].first > k) r--;
        else if(a[l].first+a[r].first < k) l++;
        else
        {
            p1 = a[l].second;
            p2 = a[r].second;
            p3 = a[pf].second;
            return 1;
        }
    }
    return 0;
}

bool check3(int pf, int k, pair <int, int> a[])
{
    for(int i = pf; i >= 2; i--)
    {
        if(check2(i, k-a[i].first, a)) return 1;
    }
    return 0;
}

int main()
{
    int n, x;
    cin >> n >> x;
    pair <int, int> a[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }

    sort(a,a+n);

    if(check3(n-1, x, a)==0) {cout << "IMPOSSIBLE"; return 0;}
    cout << p1+1 << " " << p2+1 << " " << p3+1;

    return 0;
}
