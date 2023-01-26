#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    int n, x;
    deque <int> v;
    cin >> n >> x;


    for(int i = 0; i < n; i++)
    {
        int weigh;
        cin >> weigh;
        if(weigh <= x) v.push_back(weigh);
    }
    int g = 0;
    sort(v.begin(), v.end());
    while(v.size() > 1)
    {
        if(v[v.size()-1] + v[0] <=x)
        {
            g++;
            v.pop_back();
            v.pop_front();
        }
        else
        {
            g++;
            v.pop_back();
        }
    }
    if(v.size()==1) g++;

    cout << g;


    return 0;
}
