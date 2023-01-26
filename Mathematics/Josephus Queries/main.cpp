#include <iostream>

using namespace std;

int solve(int n, int k)
{
    if(k == 0) return 0;
    if(2*k <= n) return 2*k;
    if(n%2 == 0){
        n /= 2;
        return 2*solve(n, k-n)-1;
    }
    if(n%2 == 1){
        n /= 2;
        return 2*solve(n, k-n-1)+1;
    }
}

int main()
{
    int q; cin >> q;
    while(q--){
        int n, k; cin >> n >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}
