#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int y[200001];
int x[200001];

void check(int a, int b)
{
    if(b == -1)
    {
        y[a]=-1;
        return;
    }
    if(x[a] > x[b])
    {
        y[a]=b;
        return;
    }
    check(a, y[b]);
    return;

}

int main()
{
    int n; cin >> n;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }

    y[0] = -1;

    for(int i = 1; i < n; i++)
    {
        check(i, i-1);
    }

    for(int i = 0; i < n; i++)
    {
        cout << y[i] + 1 << " ";
    }

    return 0;
}
