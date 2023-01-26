#include <iostream>
#include <map>

using namespace std;

int n;

int main()
{
    long long x, score = 0, t = 0;
    cin >> n >> x;
    int a[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];

    map <long long, long long> m;

    for(int i = 0; i < n; i++)
    {
        t+=a[i];
        score += m[t-x];
        if(t == x) score++;
        m[t]++;

    }

    cout << score;

    return 0;
}
