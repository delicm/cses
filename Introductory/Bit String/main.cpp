#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >>n;
    int c=1;
    for(int i = 0; i < n; i++)
    {
        c=(c*2)%1000000007;
    }
    cout << c;
    return 0;
}
