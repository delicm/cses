#include <iostream>

using namespace std;

void simulate()
{
    int n; cin >> n;
    int sol = 0;
    while(n--){
        int x; cin >> x;
        sol ^= x;
    }
    if(sol == 0) cout << "second" << endl;
    else cout << "first" << endl;
}

int main()
{
    int t; cin >> t;
    while(t--) simulate();
    return 0;
}
