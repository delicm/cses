#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
    string s;
    deque <char> d;
    int odd = 0, n;
    char od;
    int x[27];
    cin >>s;
    n=s.size();
    for(int i = 0; i <27; i++)
    {
        x[i]=0;
    }
    for(int i = 0; i <s.size(); i++)
    {
        x[s[i]-65]++;
    }
    for(int i = 0; i <27; i++)
    {
        if(x[i]%2==0)
        {
            for(int j = 0; j <x[i]/2; j++)
            {
                d.push_back(i+65);
                d.push_front(i+65);
            }
        }
        else
        {
            odd++;
            od = i+65;
            for(int j = 0; j <x[i]/2; j++)
            {
                d.push_back(i+65);
                d.push_front(i+65);
            }

        }
    }

    if(n%2==1)
    {
        if(odd>1){
            cout << "NO SOLUTION";
            return 0;
        }

        for(int i = 0; i<n/2; i++)
        {
            cout << d[i];
        }
        cout << od;
        for(int i = n/2; i<n-1; i++)
        {
            cout << d[i];
        }
        return 0;

    }

    if(odd != 0)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    for(int i = 0; i<n; i++)
        {
            cout << d[i];
        }

    return 0;
}
