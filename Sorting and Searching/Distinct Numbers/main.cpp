#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int x[n];
    for(int i = 0; i <n; i++)
    {
        cin >> x[i];
    }

    sort(x, x+n);
    int t = 1, temp = x[0];
    for(int i = 1; i < n; i++)
    {
        if(x[i]!=x[i-1])
        {
            temp=x[i];
            t++;
        }
    }

    cout<<t;
    return 0;
}
