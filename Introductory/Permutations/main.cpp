#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if(n==1)
    {
        cout << 1;
    }
    else if(n<=3)
    {
        cout << "NO SOLUTION";
    }
    else
    {

    for(int i = 1 ; 2*i<= n; i++)
    {
        cout << 2*i << " ";
    }
    for(int i = 0; 2*i+1<=n; i++)
    {
        cout << 2*i+1 << " ";
    }

    }
    return 0;
}
