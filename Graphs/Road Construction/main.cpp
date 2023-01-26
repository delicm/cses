#include <iostream>

using namespace std;

int component = 0;
int biggest = 1;
int link[100001];
int no[100001];

int rep(int x)
{
    while(x!=link[x]) x= link[x];
    return x;
}

bool same(int x, int y)
{
    return rep(x) == rep(y);
}

int main()
{
    int n, m;
    cin >> n >> m;
    component = n;

    for(int i = 1; i <= n; i++) link[i] = i;
    for(int i = 1; i <= n; i++) no[i] = 1;

    while(m--)
    {
        int x, y;
        cin >> x >> y;

        if(same(x, y)) cout << component << " " << biggest << endl;
        else
        {
            x = rep(x);
            y = rep(y);

            if(no[x] < no[y]) swap(x, y);
            no[x] += no[y];
            link[y] = x;

            biggest = max(biggest, no[x]);
            component--;
            cout << component << " " << biggest << endl;
        }
    }

    return 0;
}
