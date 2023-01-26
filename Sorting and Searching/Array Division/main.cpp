#include <iostream>
#include <set>

using namespace std;

bool check(int n, int k, int s[], long long x)
{
    long long sum = 0;
    int sets = 1;
    for(int i = 0; i < n; i++)
    {
        if(s[i] > x) return 0;
        if(s[i]+sum <= x) sum+=s[i];
        else
        {
            sum = s[i];
            sets++;
        }
    }
    return sets <= k;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int s[n];
    long long d = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
        d+=s[i];
    }

    long long a = 0; long long b = d;
    while(a != b-1)
    {
        long long t = (a+b)/2;
        if(check(n, k, s, t)==1) b = t;
        else a = t;
    }

    cout << b;

    return 0;
}
