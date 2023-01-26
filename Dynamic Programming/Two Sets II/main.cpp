#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n; cin >> n;
    int m = n*(n+1)/2;

    int s[m+1];
    int temp[m+1];

    for(int i = 0; i <= m; i++)
    {
        s[i] = 0;
    }

    s[1] = 1;

    for(int i = 1; i < n; i++)
    {
        for(int i = 0; i <= m; i++)
        {
            temp[i] = 0;
        }
        for(int j = 0; j <= m; j++)
        {
            temp[j+i+1] = (temp[j+i+1]+s[j])%1000000007;
            temp[abs(i+1-j)] = (temp[abs(i+1-j)]+s[j])%1000000007;
        }
        for(int i = 0; i <= m; i++)
        {
            s[i] = temp[i];
        }
    }

    /*for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << s[0];

    return 0;
}
