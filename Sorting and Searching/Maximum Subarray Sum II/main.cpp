#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n, a, b; cin >> n >> a >> b;
    long long x[n];

    cin >> x[0];
    for(int i = 1; i < n; i++)
    {
        cin >> x[i];
        x[i]+=x[i-1];
    }

    multiset <long long> s;
    long long m = -9e18;
    bool ind = 0;
    s.insert(0);

    m = max(m, x[a-1]);

    for(int i = a; i < n; i++)
    {
        s.insert(x[i-a]);

        if(i >= b && ind == 0)
        {
            s.erase(s.find(0));
            ind=1;
        }
        m = max(m, x[i]-*s.begin());
        if(i >= b)
        {
            s.erase(s.find(x[i-b]));
        }
    }


    cout << m;

    return 0;
}
