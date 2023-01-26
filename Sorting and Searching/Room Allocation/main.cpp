#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int n, a, l; cin >> n;
    pair < int, pair <bool, int>> x[2*n];
    set <int> s;
    int y[n];

    for(int i = 0; i < n; i++)
    {
        cin >> a >> l;
        x[2*i] = make_pair(a, make_pair(0, i));
        x[2*i+1]= make_pair(l, make_pair(1, i));
    }

    sort(x, x+2*n);

    int m = 1;
    s.insert(1);

    /*for(int i =0; i<2*n; i++)
    {
        cout << x[i].first << " " << x[i].second.first << " " << x[i].second.second << endl;
    }
*/
    for(int i = 0; i < 2*n; i++)
    {
        if(x[i].second.first) s.insert(y[x[i].second.second]);
        else
        {
            if(s.size()==0)
            {
                m++;
                y[x[i].second.second]=m;
            }
            else
            {
                y[x[i].second.second] = *s.begin();
                s.erase(s.begin());
            }
        }
    }

    cout << m << endl;

    for(int i = 0; i < n; i++)
    {
        cout << y[i] << " ";
    }

    return 0;
}
