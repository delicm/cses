#include <iostream>
#include <cmath>
#define int long long int

using namespace std;
int a[1000001];

void init()
{
    for(int i = 0; i <= 1000000; i++) a[i] = i;
    for(int i = 2; i <= 1000000; i+=2) a[i] = 2;

    for(int i = 3; i <= 1000000; i+=2){
        if(a[i] == i){
            for(int j = 2*i; j <= 1000000; j+=i){
                if(a[j] < i) continue;
                a[j] = i;
            }
        }
    }
}

int vp(int k, int p)
{
    int sol = 0;
    while(true){
        int temp = (int) k/pow(p, sol);
        if(k != temp*pow(p, sol)) return sol-1;
        sol++;
    }
}

int factor(int k)
{
    if(k == 1) return 1;
    int p = a[k];
    int v = vp(k, p);
    return (v+1)*factor(k/pow(p, v));
}

int32_t main()
{
    int n; cin >> n;
    init();

    while(n--){
        int k; cin >> k;
        cout << factor(k) << endl;
    }

    return 0;
}
