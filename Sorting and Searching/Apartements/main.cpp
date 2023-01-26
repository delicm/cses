#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    int x[n];
    int a[m];

    for(int i = 0 ;i < n; i++)
    {
        cin >> x[i];
    }
    for(int i = 0 ;i < m; i++)
    {
        cin >> a[i];
    }

    sort(x,x+n);
    sort(a,a+m);

    int temp = 0, c = 0;

    for(int i = 0; i < n; i++)
    {
        auto j = lower_bound(a+temp, a+m, x[i]-k);
        //cout << *j << endl;
        int l = distance(a+temp, j);
        l+=temp;
        if(l < m && a[l] <= x[i]+k)
        {
            //cout << l << endl;
            temp = l+1;
            c++;
        }
    }

    cout << c;

    return 0;
}
