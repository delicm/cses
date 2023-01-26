#include <iostream>
#include <cmath>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

int main()
{
    int n, k; cin >> n >> k; int x[n]; int t = k/2 + k%2-1;
    for(int i = 0; i < n; i++) cin >> x[i];

    ordered_multiset s;

    for(int i = 0; i < k; i++)
    {
        s.insert(x[i]);
    }

    int p = (*s.find_by_order(t));
    long long d = 0;

    for(int i = 0; i < k; i++)
        d += abs(x[i]-p);

    cout << d << " ";

    int P = 0;

    for(int i = k; i < n; i++)
    {
        s.insert(x[i]);
        s.erase(s.find_by_order(s.order_of_key(x[i-k])));
        P = (*s.find_by_order(t));

        d += abs(P-x[i])-abs(p-x[i-k]);
        if(k%2 == 0) d+= p-P;
        p = P;
        cout << d << " ";
    }

    return 0;
}
