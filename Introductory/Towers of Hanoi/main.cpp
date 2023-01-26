#include <iostream>

using namespace std;

int setc(int a, int b)
{
    if(a != 1 && b != 1) return 1;
    if(a != 2 && b != 2) return 2;
    if(a != 3 && b != 3) return 3;
}

void moveT(int a, int b, int k)
{
    int c = setc(a,b);

    if(k == 1)
    {
        cout << a << " " << b << endl;
        return;
    }
    if(k == 2)
    {
        cout << a << " " << c << endl;
        cout << a << " " << b << endl;
        cout << c << " " << b << endl;
        return;
    }

    moveT(a, b, k-2);
    cout << a << " " << c << endl;
    moveT(b, c, k-2);
    cout << a << " " << b << endl;
    moveT(c, a, k-2);
    cout << c << " " << b << endl;
    moveT(a, b, k-2);

    return;
}

int nosteps(int n)
{
    if(n % 2 == 0)
    {
        int s = 3;
        for(int i = 2; i < n; i+=2)
        {
            s = 4*s+3;
        }
        return s;
    }
    if(n % 2 == 1)
    {
        int s = 1;
        for(int i = 1; i < n; i+=2)
        {
            s = 4*s+3;
        }
        return s;
    }

}

int main()
{
    int n; cin >> n;

    cout << nosteps(n) << endl;
    moveT(1, 3, n);

    return 0;
}
