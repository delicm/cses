#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

#define int long long int

int m[19]; //#things of exactly k digits starting with a specific digit --- powers of 9
int M[19]; //total #things below 10^k

void init()
{
    m[0] = 0; m[1] = 1;

    for(int i = 2; i <= 18; i++)
        m[i] = 9*m[i-1];

    //####################

    M[0] = 0;
    for(int i = 1; i < 19; i++)
    {
        M[i] = 0;
        M[i] += 9*m[i];
        M[i] += M[i-1];
    }

}

stack <int> decompose(int a)
{
    stack <int> v;
    while(a)
    {
        v.push(a%10);
        a = a/10;
    }
    return v;
}

int cnt(stack <int> digits, int f) //#stuff smaller then digits not starting with f
{
    int d = digits.size();
    int s = 0;

    for(int i = 0; i < digits.top(); i++)
        if(i != f) s += m[d];

    if(d == 1)
    {
        if(digits.top() != f) s++;
        return s;
    }

    int newf = digits.top();
    digits.pop();
    s += cnt(digits, newf);
    return s;
}

int solve(int a)
{
    if(a == -1 || a == 0) return 0;
    stack <int> s = decompose(a);
    int d = s.size();
    return cnt(s, 0)+M[d-1];
}

int32_t main()
{
    init();
    int a, b;
    cin >> a >> b;

    /*for(int i = 0; i < 5; i++)
    {
        cout << m[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < 19; i++)
    {
        cout << M[i] << endl;
    }*/

    cout << solve(b)-solve(a-1);

    return 0;
}
