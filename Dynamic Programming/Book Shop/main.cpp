#include <iostream>

using namespace std;

int main()
{
    int n, x; cin >> n >> x;

    pair <int, int> b[n];

    for(int i = 0; i < n; i++)
    {
        cin >> b[i].first;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i].second;
    }

    long long s[x+1];

    for(int i = 0; i <=x; i++)
    {
        s[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = x; j >= 0; j--)
        {
            if(j >= b[i].first) s[j] = max(s[j], s[j-b[i].first]+b[i].second);
        }


        /*for(int i = 0; i <=x; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;*/
    }

    cout << s[x];

    return 0;
}
