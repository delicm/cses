#include <iostream>

using namespace std;

long long table(long x, long y)
{
    if(x >= y)
    {
        if(x%2 == 0)
        {
            return (x-1)*(x-1)+y;
        }
        else
        {
            return (x-1)*(x-1)+x+x-y;
        }
    }
    else
    {
        if(y%2 == 0)
        {
            return (y-1)*(y-1)+y+y-x;
        }
        else
        {

            return (y-1)*(y-1)+x;
        }
    }
}

int main()
{
    long long n, x, y;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        scanf("%ld %ld", &x, &y);
        cout << table(y,x) << "\n";
    }


    return 0;
}
