#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >>n;

    if(n%4==0)
    {
        cout << "YES" << "\n" << n/2 << "\n";
        for(int i = 1; i<=n/4; i++)
        {
            cout << i << " " << n-i+1 << " ";
        }
        cout << "\n" << n/2 << "\n";
        for(int i = n/4+1; i<=n/4*3; i++)
        {
            cout << i << " ";
        }
        return 0;
    }
    if(n%4 ==3)
    {
        cout << "YES" << "\n" << (n+1)/2 << "\n";
        for(int i =1; i <= (n+1)/4; i++)
        {
            cout << i << " " << n-i << " ";
        }
        cout << "\n" << (n-1)/2 << "\n";
        for(int i = (n+1)/4+1; i<=n-(n+1)/4-1; i++)
        {
            cout << i << " ";
        }
        cout << n;
        return 0;
    }
    cout << "NO";
    return 0;
}
