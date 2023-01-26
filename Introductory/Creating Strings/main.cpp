#include <iostream>
#include <string>
#include <queue>

using namespace std;

queue <string> q;
int counter = 0;

void rec(int x[], string c, int length, int n)
{
    if(length==n)
    {
        q.push(c);
        counter++;
        return;
    }
    for(int i = 0; i < 128; i++)
    {
        if(x[i]!=0)
        {
            x[i]--;
            c.push_back(i);
            rec(x, c, length+1, n);
            c.erase(c.end()-1, c.end());
            x[i]++;
        }
    }
    return;
}

int main()
{
    string s, c="";
    int x[128];
    int t = 1, m=0;
    cin >> s;

    for(int i = 0;  i < 128; i++)
    {
        x[i]=0;
    }

    for(int i = 0;  i < s.size(); i++)
    {
        x[s[i]]++;
    }


    rec(x, c, 0, s.size());
    cout << counter << "\n";
    for(int i = 0; i<counter; i++)
    {
        cout << q.front() << "\n";
        q.pop();
    }
    return 0;
}
