#include <iostream>
#include <cmath>
#define N 1000000
using namespace std;

int n;
int a[N+1];
int d[N+1];

void solve()
{
    for(int i = 0; i <= N; i++) d[i] = 0;
    for(int j = 0; j < n; j++){
        int x = a[j];
        int s = (int) sqrt(x);
        for(int i = 1; i <= s; i++){
            if(x%i == 0){
                d[i]++;
                if(x/i != i) d[x/i]++;
            }
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    solve();
    for(int i = N; i >= 1; i--){
        if(d[i] >= 2){
            cout << i;
            break;
        }
    }

    return 0;
}
