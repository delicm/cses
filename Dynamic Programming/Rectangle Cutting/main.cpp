#include <iostream>

using namespace std;

long long s[501][501];

long long find_(int a, int b)
{
    long long ans = 9223372036854775807;
    for(int i = 1; i <= a/2; i++)
    {
        ans = min(ans, s[i][b] + s[a-i][b] + 1);
    }
    for(int i = 1; i <= b/2; i++)
    {
        ans = min(ans, s[a][i] + s[a][b-i]+1);
    }
    return ans;
}

int main()
{
    int a, b; cin >> a >> b;

    for(int i = 1; i <= min(a, b); i++)
    {
        s[i][i] = 0;
    }

    for(int i = 0; i <= 500; i++)
    {
        for(int j = 0; j <= 500; j++)
        {
            s[i][j] = 0;
        }
    }

    for(int i = 1; i <= 500; i++)
    {
        for(int j = 1; j < i; j++)
        {
            s[i][j] = find_(i, j);
            s[j][i] = s[i][j];
        }
    }

    cout << s[a][b] << endl;

    /*for(int i = 1; i <= a; i++)
    {
        for(int j = 1; j <= b; j++)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }/*/

    return 0;
}
