#include <iostream>
#include <string>

using namespace std;

int main()
{
    string x, y; cin >> x >> y;
    int a = x.size();
    int b = y.size();
    int t = 0;

    int s[a][b];

    int c1 = (y.find(x[0])+b+1)%(b+1);
    int c2 = (x.find(y[0])+a+1)%(a+1);

    for(int i = 0; i < c2; i++)
    {
        s[i][0] = i+1;
    }
    for(int i = c2; i < a; i++)
    {
        s[i][0] = i;
    }
    for(int i = 0; i < c1; i++)
    {
        s[0][i] = i+1;
    }
    for(int i = c1; i < b; i++)
    {
        s[0][i] = i;
    }

    for(int i = 1; i < a; i++)
    {
        for(int j = 1; j < b; j++)
        {
            t = 2147483647;
            if(x[i] == y[j]) t = s[i-1][j-1];
            else t = s[i-1][j-1]+1;
            t = min(t, s[i-1][j]+1);
            t = min(t, s[i][j-1]+1);
            s[i][j] = t;
        }
    }

    /*for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
        {
            cout << s[i][j] << " ";
        }
        cout<<endl;
    }*/

    cout << s[a-1][b-1];
    //cout << c1 << endl << c2;

    return 0;
}
