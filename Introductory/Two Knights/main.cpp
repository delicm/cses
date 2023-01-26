#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    long long comp = 0;
    cin >> n;

    if(n==1)
    {
        cout << 0;
        return 0;
    }
    else if(n==2)
    {
        cout << 0 << "\n" << 6;
        return 0;
    }

    cout << 0 << "\n" << 6 << "\n" << 28 << "\n";
    for(int i = 4; i <=n; i++)
    {
        long long t = i;
        t = t*t*t*t;
        comp = (t-i*i)/2-(4*i*i-12*i+8);
        cout << comp << "\n";
    }

    return 0;
}
