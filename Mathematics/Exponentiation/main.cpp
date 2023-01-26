#include <iostream>

using namespace std;
#define M 1000000007
#define int long long int

int exp(int a, int b)
{
    if(b == 0) return 1;
    int temp = exp(a, b/2);
    int sol = (temp*temp)%M;
    if(b%2) sol = (sol*a)%M;
    return sol;
}

int32_t main()
{
    int n; cin >> n;
    while(n--){
        int a, b; cin >> a >> b;
        cout << exp(a, b) << endl;
    }
    return 0;
}
