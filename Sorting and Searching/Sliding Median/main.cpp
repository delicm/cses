#include <iostream>
#include <set>
#include <queue>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

int main()
{
    int n, k; cin >> n >> k; long long x[n]; int t=k%2 - 1;
    for(int i = 0; i < n; i++) cin >> x[i];

    ordered_multiset s;

    for(int i = 0; i < k; i++)
    {
        s.insert(x[i]);
    }

    cout << *s.find_by_order(k/2+t) << " ";

    for(int i = k; i < n; i++)
    {
        s.insert(x[i]);
        s.erase(s.find_by_order(s.order_of_key(x[i-k])));

        cout << (*s.find_by_order(k/2+t)) << " ";
    }

    return 0;
}
