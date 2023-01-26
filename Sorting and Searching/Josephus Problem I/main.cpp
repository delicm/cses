#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main()
{
    int n, k; cin >> n;

    k = 1;
    ordered_set s;
    for(int i = 1; i <= n; i++) s.insert(i);

    int last_pos = 0;
    for(int i = 1; i <= n; i++)
    {
        last_pos = (last_pos + k)%(n+1-i);
        cout << *s.find_by_order(last_pos) << " ";
        s.erase(*s.find_by_order(last_pos));
    }

    return 0;
}
