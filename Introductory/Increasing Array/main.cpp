#include <iostream>

using namespace std;

int main()
{
    long long int n, counter = 0;
    cin >>n;
    long long int a[n];

    cin >> a[0];
    for(int i = 1; i<n; i++)
    {
        scanf("%ld", &a[i]);
        if(a[i] < a[i-1])
        {
            counter += a[i-1]-a[i];
            a[i]=a[i-1];
        }
    }
    cout << counter;
    return 0;
}
