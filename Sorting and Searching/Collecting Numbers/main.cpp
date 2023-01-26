#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n; cin >> n;
    set <int> a;

    int sol = 0;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if(!a.count(x-1)) sol++;
        a.insert(x);
    }

    cout << sol;

    return 0;
}
