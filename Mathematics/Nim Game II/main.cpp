#include <iostream>

using namespace std;

void simulate()
{
    int n; cin >> n;
    long long sol = 0;
    while(n--){
        long long x; cin >> x;
        sol = (sol+x)%4;
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
