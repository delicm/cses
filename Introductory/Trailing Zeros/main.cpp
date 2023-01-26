#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, m, deg=0, r = 0;
    cin >>n;
    m =n;
    while(m >= pow(5, deg))
    {
        deg++;
    }

    for(int i = 1; i<deg; i++)
    {
        r += n/pow(5,i);
    }
    cout << r;

    return 0;
}
