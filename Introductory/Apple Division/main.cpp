#include <iostream>
#include <cmath>

using namespace std;

int n;
long long m = 20*pow(10,9)+1;

void diff(int x[], int ind[], int check)
{
    if(check == n)
    {
        long long sum = 0;
        for(int i = 0; i<n; i++)
        {
            sum = sum + x[i]*ind[i];
        }
        m= min(m, abs(sum));
        return;
    }
    ind[check]=1;
    diff(x, ind, check+1);
    ind[check]=-1;
    diff(x, ind, check+1);

}

int main()
{
    cin >>n;
    int x[n];
    int ind[n];
    for(int i = 0; i< n; i++)
    {
        cin >> x[i];
        ind[i] =1;
    }
    diff(x, ind, 0);
    cout << m;
    return 0;
}
