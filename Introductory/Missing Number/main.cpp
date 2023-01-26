#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    a[0]=0;
    bool f=true;

    for(int i = 1; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    sort(a, a+n);
    for(int i = 1; i<n; i++)
    {
        if(a[i]!=i)
        {
            cout << i;
            f=false;
            break;
        }
    }
    if(f)
    {
        cout << n;
    }
    return 0;
}
