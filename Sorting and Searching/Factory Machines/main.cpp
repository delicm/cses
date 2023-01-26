#include <iostream>

using namespace std;

bool check(unsigned long long t, int n, int x[], unsigned long long k)
{
    unsigned long long m = 0;
    for(int i = 0; i < n; i++)
    {
        m += k/x[i];
    }
    return m >= t;
}

int main()
{
    int n;
    unsigned long long t;
    cin >> n >> t;
    int x[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }

    unsigned long long a = 0, b = x[0]*t;

    while(a!=b-1)
    {
        unsigned long long k = (a+b)/2;
        if(check(t, n, x, k) == false)
        {
            a = k;
        }
        else
        {
            b = k;
        }
    }

    cout << b;

    return 0;
}
