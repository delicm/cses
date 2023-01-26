#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int m = 0;
    char temp = '0';
    int t = 0;
    cin >> s;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i]==temp)
        {
            t++;
        }
        else
        {
            temp = s[i];
            m = max(m, t);
            t=1;
        }
    }
    cout << max(m,t);
    return 0;
}
